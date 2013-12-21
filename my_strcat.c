/*
** my_strcat.c for minishell in /home/chapui_s/travaux/minishell
**
** Made by chapui_s
** Login   <chapui_s@epitech.net>
**
** Started on  Wed Dec 11 16:49:10 2013 chapui_s
** Last update Wed Dec 11 16:52:01 2013 chapui_s
*/

#include <stdlib.h>

char	*str_cat(char *s1, char *s2)
{
  char	*dest;
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (s1[i])
    i = i + 1;
  while (s2[j])
    j = j + 1;
  if ((dest = (char*)malloc(sizeof(char) * (i + j + 2))) == NULL)
    return (NULL);
  i = 0;
  j = 0;
  while (s1[i])
    dest[i] = s1[i++];
  if (dest[i - 1] != '/')
    dest[i++] = '/';
  while (s2[j])
    dest[i + j] = s2[j++];
  dest[i + j] = 0;
  return (dest);
}
