/*
** my_atoi.c for 102chiffrement in /home/chapui_s/travaux/102Chiffrement
**
** Made by chapui_s
** Login   <chapui_s@epitech.net>
**
** Started on  Thu Nov 28 19:44:31 2013 chapui_s
** Last update Thu Nov 28 19:44:56 2013 chapui_s
*/

int	my_atoi(char *str)
{
  int	i;
  int	negativ;
  int	number;

  i = 0;
  negativ = 0;
  number = 0;
  while ((str[i] == ' ') || (str[i] == '\t') || (str[i] == '\n')
	 || (str[i] == '\v') || (str[i] == '\f') || (str[i] == '\r'))
    i++;
  if (str[i] == 45)
    negativ = 1;
  if ((str[i] == 45) || (str[i] == 43))
    i++;
  while (str[i] >= 48 && str[i] <= 57)
  {
    number *= 10;
    number += ((int)str[i] - 48);
    i++;
  }
  if (negativ == 1)
    return (-number);
  else
    return (number);
}
