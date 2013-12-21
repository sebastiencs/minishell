/*
** my_strdup.c for strdup in /home/chapui_s/rendu/Piscine-C-Jour_08/ex_01
**
** Made by chapui_s
** Login   <chapui_s@epitech.net>
**
** Started on  Wed Oct  9 09:16:45 2013 chapui_s
** Last update Thu Dec 12 18:35:01 2013 chapui_s
*/

#include <stdlib.h>

static char	*dup_it(char *str, char *str2)
{
  int		i;
  int		j;

  i = 0;
  j = 0;
  while (str[i])
  {
    if (str[i] != ':')
      str2[j++] = str[i];
    else
    {
      str2[j++] = '/';
      str2[j++] = ' ';
    }
    i = i + 1;
  }
  str2[j] = '/';
  str2[j + 1] = 0;
  return (str2);
}

char	*my_strdup(char *str)
{
  int	size;
  char	*str2;
  int	nb_two_points;
  int	i;
  int	j;

  i = 0;
  j = 0;
  size = 0;
  nb_two_points = 0;
  while (str[size])
    if (str[size++] == ':')
      nb_two_points = nb_two_points + 1;
  str2 = (char*)malloc(sizeof(char) * (size + 2 + nb_two_points));
  str2 = dup_it(str, str2);
  return (str2);
}
