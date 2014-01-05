/*
** prompt.c for minishell in /home/sebastien/travaux/minishell
**
** Made by Sebastien Chapuis
** Login   <sebastien@epitech.net>
**
** Started on  Sun Jan  5 13:20:53 2014 Sebastien Chapuis
** Last update Sun Jan  5 13:43:25 2014 Sebastien Chapuis
*/

#include <stdlib.h>
#include "minishell.h"

void	prompt(char **env)
{
  char	*user;
  char	*pwd;

  if ((user = search_in_env(env, "USER=")) == NULL)
  {
    write(1, "$> ", 3);
    return ;
  }
  my_putstr(user);
  my_putstr(" > ");
}
