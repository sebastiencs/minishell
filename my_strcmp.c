/*
** my_strcmp.c for strcmp in /home/chapui_s/rendu/Piscine-C-Jour_06/ex_05
**
** Made by chapui_s
** Login   <chapui_s@epitech.net>
**
** Started on  Mon Oct  7 10:26:21 2013 chapui_s
** Last update Wed Dec 18 17:57:47 2013 Sebastien Chapuis
*/

int	my_strcmp(char *s1, char *s2)
{
  int	i;

  i = 0;
  while (s1[i] || s2[i])
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
