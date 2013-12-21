/*
** my_cd.c for minishell in /home/sebastien/travaux/minishell
**
** Made by Sebastien Chapuis
** Login   <sebastien@epitech.net>
**
** Started on  Sat Dec 21 16:17:57 2013 Sebastien Chapuis
** Last update Sat Dec 21 17:50:11 2013 Sebastien Chapuis
*/

#include <unistd.h>
#include <stdlib.h>
#include <dirent.h>
#include "minishell.h"

char	*search_in_env(char **env, char *var)
{
  int	i;
  char	*path_home;

  i = 0;
  path_home = NULL;
  if (env == NULL || env[0] == NULL)
    return (NULL);
  while (env && env[i] && my_strncmp(var, env[i], 4) != 0)
    i = i + 1;
  if (env[i])
    path_home = right_egale(env[i]);
  return (path_home);
}

static int	save_path(char *path, char **env)
{
  char		*pwd;

  if (env && env[0] && (pwd = search_in_env(env, "PWD=")) == NULL)
    return (-1);
  my_setenv(&env, "OLDPWD", pwd);
  my_setenv(&env, "PWD", path);
}

int	my_cd(char *path, char **env)
{
  int	is_change;

  is_change = 0;
  if (path == NULL && ++is_change)
    path = search_in_env(env, "HOME=");
  if (path && path[0] == '-' && path[1] == '\0' && ++is_change)
    path = search_in_env(env, "OLDPWD=");
  if (access(path, F_OK) == -1)
  {
    my_putstr_error("error: Folder doesn't exist\n");
    return (0);
  }
  else if (access(path, X_OK) == -1)
  {
    my_putstr_error("error: Folder can't be access, check your rights on it\n");
    return (0);
  }
  if (path)
  {
    if ((save_path(path, env)) == -1)
      return (-1);
    chdir(path);
  }
  (is_change == 1) ? (free(path)) : (0);
  return (0);
}
