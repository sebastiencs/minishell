/*
** exec_cmd.c for minishell in /home/chapui_s/travaux/minishell
**
** Made by chapui_s
** Login   <chapui_s@epitech.net>
**
** Started on  Tue Dec 10 19:58:57 2013 chapui_s
** Last update Sun Jan  5 15:55:18 2014 Sebastien Chapuis
*/

#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include "minishell.h"

static int	is_builtin(t_cmd *cmd)
{
  if (my_strcmp(cmd->filename, "setenv") == 0
      || my_strcmp(cmd->filename, "cd") == 0
      || my_strcmp(cmd->filename, "unsetenv") == 0
      || my_strcmp(cmd->filename, "exit") == 0
      || my_strcmp(cmd->filename, "env") == 0)
    return (1);
  return (0);
}

static int	do_builtin(t_cmd *cmd, char **environ)
{
  if (my_setenv(&environ, "_", cmd->filename) == -1)
    return (-1);
  if (my_strcmp(cmd->filename, "setenv") == 0)
    return (my_setenv(&environ, cmd->args[1], cmd->args[2]));
  else if (my_strcmp(cmd->filename, "unsetenv") == 0)
    return (my_unsetenv(&environ, cmd->args[1]));
  else if (my_strcmp(cmd->filename, "env") == 0)
    return (my_env(environ, cmd));
  else if (my_strcmp(cmd->filename, "cd") == 0)
    return (my_cd(cmd->args[1], environ));
  else if (my_strcmp(cmd->filename, "exit") == 0)
    return (my_exit(cmd->args[1]));
  return (0);
}

static void	wait_child(void)
{
  int		status;

  signal(SIGINT, get_sigint);
  wait(&status);
  if (WIFSIGNALED(status))
  {
    if (WTERMSIG(status) == 11)
      my_putstr_error("Segfault !\n");
    else if (WTERMSIG(status) == 8)
      my_putstr_error("Arithmetic error !\n");
    else
      my_putstr_error("Killed\n");
  }
  else if (WIFSTOPPED(status))
    my_putstr_error("Stopped\n");
}

int		exec_it(t_cmd *cmd, char **environ, t_read *list_read,
			char *str)
{
  int		status;
  pid_t		pid;

  if (cmd->cmd_path == NULL)
    return (cmd_null(cmd, str));
  if ((pid = fork()) == 0)
  {
    if (execve(cmd->cmd_path, cmd->args, environ) == -1)
    {
      my_putstr_error("error -> could not execute the command\n");
      return (-1);
    }
  }
  else if (pid != -1)
    wait_child();
  else
    return (-2);
  if (my_setenv(&environ, "_", cmd->cmd_path) == -1)
    return (-2);
  free_list(list_read, cmd, str);
  return (0);
}

int	exec_cmd(char **environ, t_read *list_read, t_cmd *cmd, char *str)
{
  int	ret_exit;
  char	c_read;

  c_read = 0;
  prompt(environ);
  signal(SIGINT, get_first_sigint);
  while (read(0, &c_read, 1) > 0 && c_read != '\n')
    if ((push_read(&list_read, c_read, environ)) == -1)
      return (0);
  if (c_read == 0)
    return (write(1, "\n", 1) - 1);
  if ((str = list_to_str(list_read)) == NULL)
    return (-1);
  if ((cmd = str_to_cmd(str, environ)) == NULL)
    return (-1);
  if (is_builtin(cmd) == 1)
  {
    if ((ret_exit = do_builtin(cmd, environ)) != 0)
      return ((ret_exit == -3) ? (0) : (ret_exit));
  }
  else if (is_builtin(cmd) != 1)
    if ((exec_it(cmd, environ, list_read, str)) == -2)
      return (-2);
  return (1);
}
