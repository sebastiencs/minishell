/*
** utils2.c for minishell in /home/sebastien/travaux/minishell
**
** Made by Sebastien Chapuis
** Login   <sebastien@epitech.net>
**
** Started on  Sat Dec 21 13:50:50 2013 Sebastien Chapuis
** Last update Sat Dec 21 17:52:52 2013 Sebastien Chapuis
*/

#include <stdlib.h>

char	*left_egale(char *str)
{
  int	i;
  char	*new_str;
  int	size_str;

  i = 0;
  size_str = 0;
  while (str && str[size_str] && str[size_str] != '=')
    size_str = size_str + 1;
  if ((new_str = (char*)malloc(size_str +1)) == NULL)
    return (NULL);
  while (i < size_str)
  {
    new_str[i] = str[i];
    i = i + 1;
  }
  new_str[i] = 0;
  return (new_str);
}

char	*right_egale(char *str)
{
  int	i;
  char	*new_str;
  int	size_str;

  i = 0;
  size_str = 0;
  while (str && str[i] != '=')
    i = i + 1;
  i = i + 1;
  while (str[i + size_str])
    size_str = size_str + 1;
  if ((new_str = (char*)malloc(size_str + 1)) == NULL)
    return (NULL);
  size_str = 0;
  while (str[i + size_str])
  {
    new_str[size_str] = str[i + size_str];
    size_str = size_str + 1;
  }
  new_str[size_str] = 0;
  return (new_str);
}

int		my_exit(char *str)
{
  unsigned char	num_exit;
  int		i;

  i = 0;
  my_putstr("exit\n");
  if (str == NULL)
    return (-3);
  while (str && str[i])
  {
    if (!((str[i] >= '0' && str[i] <= '9')) && str[i] != '-')
    {
      my_putstr_error("exit: argument numeric necessary\n");
      return (255);
    }
    i = i + 1;
  }
  num_exit = (unsigned char)my_atoi(str);
  return (num_exit);
}
