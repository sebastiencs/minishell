/*
** my_strncmp.c for strncmp in /home/chapui_s/rendu/Piscine-C-Jour_06/ex_06
**
** Made by chapui_s
** Login   <chapui_s@epitech.net>
**
** Started on  Mon Oct  7 10:51:35 2013 chapui_s
** Last update Sat Dec 21 16:50:36 2013 Sebastien Chapuis
*/

static int	check_n(char *s1, char *s2)
{
  int		size_s1;
  int		size_s2;

  size_s1 = 0;
  size_s2 = 0;
  while (s1[size_s1])
    size_s1 = size_s1 + 1;
  while (s2[size_s2])
    size_s2 = size_s2 + 1;
  if (size_s2 > size_s1)
    return (size_s2);
  return (size_s1);
}

int	my_strncmp(char *s1, char *s2, int n)
{
  int	i;

  i = 0;
  if (n < 0)
    n = check_n(s1, s2);
  while ((s1[i] || s2[i]) && i < n)
  {
    if (s1[i] == '\0' && s2[i] == '\0')
      return (0);
    if (s1[i] == '\0' || s2[i] == '\0')
      return (s1[i] - s2[i]);
    if (s1[i] != s2[i])
      return (s1[i] - s2[i]);
    i = i + 1;
  }
  return (0);
}
