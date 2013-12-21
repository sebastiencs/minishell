/*
** main.c for minishell in /home/chapui_s/travaux/minishell
**
** Made by chapui_s
** Login   <chapui_s@epitech.net>
**
** Started on  Tue Dec 10 15:55:30 2013 chapui_s
** Last update Sat Dec 21 17:49:50 2013 Sebastien Chapuis
*/

#include <stdio.h>
#include <unistd.h>
#include "minishell.h"

int	main(int argc, char **argv, char **environ)
{
  int	res_exec;

  res_exec = 1;

  while (res_exec == 1)
  {
    res_exec = exec_cmd(environ, NULL, NULL, NULL);
    if (res_exec == -1)
    {
      my_putstr_error("Could not alloc\n");
      return (-1);
    }
    else if (res_exec == -2)
    {
      my_putstr_error("Could not fork\n");
      return(-1);
    }
  }
  return (res_exec);
}
