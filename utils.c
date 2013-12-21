/*
** utils.c for minishell in /home/chapui_s/travaux/minishell
**
** Made by chapui_s
** Login   <chapui_s@epitech.net>
**
** Started on  Thu Dec 12 15:54:49 2013 chapui_s
** Last update Sat Dec 21 18:36:38 2013 Sebastien Chapuis
*/

#include <unistd.h>

unsigned int	my_strlen(char *str)
{
  unsigned int	size;

  size = 0;
  if (str == NULL)
    return (0);
  while (str[size])
    size = size + 1;
  return (size);
}

void		my_putstr(char *str)
{
  unsigned int	i;

  i = 0;
  if (str == NULL)
    return ;
  while (str[i])
    write(1, &str[i++], 1);
}

int		my_putstr_error(char *str)
{
  unsigned int	i;

  i = 0;
  if (str == NULL)
    return ;
  while (str[i])
    write(2, &str[i++], 1);
  return (0);
}

int	is_only_spaces(char *str)
{
  int	i;

  i = 0;
  if (str == NULL)
    return (1);
  while (str[i])
  {
    if (str[i] != ' ')
      return (0);
    i = i + 1;
  }
  return (1);
}

void	usage_env(void)
{
  my_putstr("Usage: env [OPTION]... [-] [NAME=VALUE]... [COMMAND [ARG]...]\n\n");
  my_putstr("\t-i      start with an empty environment\n");
  my_putstr("\t-0      end each output line with 0 byte rather than newline\n");
  my_putstr("\t-u      remove variable from the environment\n");
  my_putstr("\t--help  display help\n");
  my_putstr("\nIf no COMMAND, print the resulting environment.\n");
}
