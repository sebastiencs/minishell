/*
** list_read.c for minishell in /home/chapui_s/travaux/minishell
**
** Made by chapui_s
** Login   <chapui_s@epitech.net>
**
** Started on  Tue Dec 10 16:22:33 2013 chapui_s
** Last update Sat Dec 21 17:53:21 2013 Sebastien Chapuis
*/

#include <stdlib.h>
#include "minishell.h"

static t_read	*create_read(char c)
{
  t_read	*new;

  new = NULL;
  if (new = (t_read*)malloc(sizeof(*new)))
  {
    new->c = c;
    new->next = NULL;
  }
  return (new);
}

int	trans_tild(t_read **list, char **env)
{
  char	*home;
  int	i;

  i = 0;
  home = search_in_env(env, "HOME=");
  if (home == NULL)
  {
    if ((push_read(list, '~', env)) == -1)
      return (-1);
    return (0);
  }
  while (home[i])
  {
    if ((push_read(list, home[i], env)) == -1)
      return (-1);
    i = i + 1;
  }
  return (0);
}

int		push_read(t_read **list, char c, char **env)
{
  t_read	*tmp;

  tmp = *list;
  if (c == 0)
    return (-1);
  else if (c == '~')
    return (trans_tild(list, env));
  (c == '\t') ? (c = ' ') : (0);
  if (*list)
  {
    while (tmp->next)
      tmp = tmp->next;
    if ((tmp->next = create_read(c)))
      return (0);
  }
  else
    if ((*list = create_read(c)))
      return (0);
  my_putstr_error("error -> could not alloc\n");
  return (-1);
}
