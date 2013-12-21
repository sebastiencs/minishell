/*
** my_env_exec.c for minishell in /home/sebastien/travaux/minishell
**
** Made by Sebastien Chapuis
** Login   <sebastien@epitech.net>
**
** Started on  Sat Dec 21 13:18:59 2013 Sebastien Chapuis
** Last update Sat Dec 21 16:13:28 2013 Sebastien Chapuis
*/

#include <stdlib.h>
#include "minishell.h"

#include <stdio.h>

char	*cmd_to_str(t_cmd *cmd, int j)
{
  int	i;
  int	z;
  char	*str;
  int	size_str;

  size_str = 0;
  i = 0;
  z = 0;
  while (cmd && cmd->args[j + i])
  {
    size_str += my_strlen(cmd->args[j + i]) + 1;
    i = i + 1;
  }
  if ((str = (char*)malloc(size_str)) == NULL)
    return (NULL);
  while (cmd && cmd->args[j])
  {
    i = 0;
    while (cmd && cmd->args[j][i])
      str[z++] = cmd->args[j][i++];
    str[z++] = ' ';
    j = j + 1;
  }
  str[z] = 0;
  return (str);
}

int	exec_env_null(t_cmd *cmd, int j)
{
  t_cmd	*new_cmd;
  char	*str;
  int	i;

  i = 0;
  if (cmd->args[j] == NULL)
    return (0);
  if ((str = cmd_to_str(cmd, j)) == NULL)
    return (-1);
  if ((new_cmd = str_to_cmd(str, NULL)) == NULL)
    return (-1);
  if ((exec_it(new_cmd, NULL, NULL, str)) == -2)
    return (-2);
  return (0);
}

void	disp_env(char **env, t_env *options)
{
  int	i;

  i = 0;
  if (env == NULL)
    return ;
  while (env[i])
  {
    my_putstr(env[i]);
    if (options->zero == 0)
      write(1, "\n", 1);
    i = i + 1;
  }
}

int	exec_with_env(t_cmd *cmd, char **env, int j)
{
  t_cmd	*new_cmd;
  char	*str;
  int	i;

  i = 0;
  if (cmd->args[j] == NULL)
    return (0);
  if ((str = cmd_to_str(cmd, j)) == NULL)
    return (-1);
  if ((new_cmd = str_to_cmd(str, env)) == NULL)
    return (-1);
  if ((exec_it(new_cmd, env, NULL, str)) == -2)
    return (-2);
  return (0);
}

int	prepare_setenv(char ***env, char *str)
{
  char	*left;
  char	*right;

  if ((left = left_egale(str)) == NULL)
    return (-1);
  if ((right = right_egale(str)) == NULL)
    return (-1);
  if ((my_setenv(env, left, right)) == -1)
    return (-1);
  free(left);
  free(right);
  return (0);
}
