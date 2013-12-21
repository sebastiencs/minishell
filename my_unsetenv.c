/*
** my_unsetenv.c for minishell in /home/sebastien/travaux/minishell
**
** Made by Sebastien Chapuis
** Login   <sebastien@epitech.net>
**
** Started on  Wed Dec 18 19:54:06 2013 Sebastien Chapuis
** Last update Sat Dec 21 18:38:59 2013 Sebastien Chapuis
*/

#include <stdlib.h>
#include "minishell.h"

int	my_unsetenv(char ***env, char *variable)
{
  int	i;
  char	**tmp_var;

  i = 0;
  tmp_var = *env;
  if (variable == NULL)
    return (my_putstr_error("usage: unsetenv VARIABLE\n"));
  if (variable == NULL || my_strlen(variable) == 0
      || my_strchr(variable, '=') != NULL)
  {
    my_putstr_error("error -> variable is NULL or there is '=' in name\n");
    return (0);
  }
  while (tmp_var && tmp_var[i]
	 && my_strncmp(variable, tmp_var[i], my_strlen(variable)) != 0)
    i = i + 1;
  if (tmp_var[i] == NULL)
    return (0);
  while (tmp_var[i])
  {
    tmp_var[i] = tmp_var[i + 1];
    i = i + 1;
  }
  return (0);
}
