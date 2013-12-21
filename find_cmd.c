/*
** find_cmd.c for minishell in /home/chapui_s/travaux/minishell
**
** Made by chapui_s
** Login   <chapui_s@epitech.net>
**
** Started on  Wed Dec 11 15:26:10 2013 chapui_s
** Last update Sat Dec 21 17:49:27 2013 Sebastien Chapuis
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include "minishell.h"

int	cmd_null(t_cmd *cmd, char *str)
{
  if (str && str[0] != '\0' && is_only_spaces(str) == 0)
  {
    my_putstr_error("Cannot find the command '");
    if (cmd && cmd->args)
      my_putstr_error(cmd->args[0]);
    my_putstr_error("'...\n");
  }
  return (-1);
}

static char	**path_to_wordtab(char *str)
{

  char		**paths;
  int		i;

  i = 0;
  while (i < 5)
    str[i++] = ' ';
  if ((paths = my_str_to_wordtab(str)) == NULL)
    return (NULL);
  free(str);
  return (paths);
}

static char	*free_paths(char **paths, int i)
{
  char		*good_paths;
  int		j;

  j = 0;
  if (paths == NULL || paths[i] == NULL)
    return (NULL);
  if ((good_paths = (char*)malloc(my_strlen(paths[i]) + 1)) == NULL)
    return (NULL);
  while (paths[i][j])
    good_paths[j] = paths[i][j++];
  good_paths[j] = 0;
  i = 0;
  while (paths[i])
  {
    if (paths[i] != NULL)
      free(paths[i]);
    i = i + 1;
  }
  free(paths[i]);
  free(paths);
  return (good_paths);
}

static char	*is_path_good(char *str)
{
  if (access(str, X_OK) == 0)
    return (str);
  return (NULL);
}

char		*find_cmd(char *str, char **environ, int i, char *tmp)
{
  char		**paths;

  if (str && str[0] != '.' && str[0] != '/' && environ)
  {
    while (environ[i] && my_strncmp("PATH=", environ[i], 5) != 0)
      i = i + 1;
    if (environ[i] == NULL)
      return (NULL);
    if ((paths = path_to_wordtab(my_strdup(environ[i]))) == NULL)
      return (NULL);
    i = 0;
    while (paths[i])
    {
      tmp = paths[i];
      if ((paths[i] = str_cat(paths[i], str)) == NULL)
	return (NULL);
      free(tmp);
      if (access(paths[i], X_OK) == 0)
	return (free_paths(paths, i));
      i = i + 1;
    }
  }
  else
    return (is_path_good(str));
}
