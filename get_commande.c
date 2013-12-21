/*
** get_commande.c for minishell in /home/chapui_s/travaux/minishell
**
** Made by chapui_s
** Login   <chapui_s@epitech.net>
**
** Started on  Tue Dec 10 16:41:28 2013 chapui_s
** Last update Thu Dec 19 20:30:20 2013 Sebastien Chapuis
*/

#include <stdlib.h>
#include "minishell.h"

#include <stdio.h>

char		*list_to_str(t_read *list_read)
{
  char		*str;
  t_read	*tmp;
  int		i;

  i = 0;
  tmp = list_read;
  while (tmp && ++i)
    tmp = tmp->next;
  if ((str = (char*)malloc(sizeof(char) * (i + 1))) == NULL)
    return (NULL);
  i = 0;
  tmp = list_read;
  while (tmp)
  {
    str[i] = tmp->c;
    tmp = tmp->next;
    i = i + 1;
  }
  str[i] = 0;
  return (str);
}

t_cmd		*str_to_cmd(char *str, char **environ)
{
  t_cmd		*cmd;
  int		i;
  int		j;

  i = 0;
  j = 0;
  while (str[i] && str[i] == ' ')
    i = i + 1;
  while (str[i + j] && str[i + j++] != ' ');
  if ((cmd = (t_cmd*)malloc(sizeof(t_cmd))) == NULL)
    return (NULL);
  if ((cmd->filename = (char*)malloc(sizeof(char) * (j + 1))) == NULL)
    return (NULL);
  cmd->cmd_path = NULL;
  cmd->args = NULL;
  j = 0;
  while (str[i + j] && str[i + j] != ' ')
    cmd->filename[j] = str[i + j++];
  cmd->filename[j] = 0;
  cmd->args = my_str_to_wordtab(str + i);
  cmd->cmd_path = find_cmd(cmd->args[0], environ, 0, NULL);
  return (cmd);
}
