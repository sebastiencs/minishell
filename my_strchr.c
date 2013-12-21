/*
** my_strchr.c for minishell in /home/sebastien/travaux/minishell
**
** Made by Sebastien Chapuis
** Login   <sebastien@epitech.net>
**
** Started on  Wed Dec 18 19:37:21 2013 Sebastien Chapuis
** Last update Wed Dec 18 19:43:47 2013 Sebastien Chapuis
*/

#include <stdlib.h>

char	*my_strchr(char *s, int c)
{
  int	i;

  i = 0;
  while (s[i])
  {
    if (s[i] == c)
      return (s + i);
    i = i + 1;
  }
  return (NULL);
}
