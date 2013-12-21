/*
** free_cmd.c for minishell in /home/chapui_s/travaux/minishell
**
** Made by chapui_s
** Login   <chapui_s@epitech.net>
**
** Started on  Wed Dec 11 13:15:20 2013 chapui_s
** Last update Thu Dec 19 20:22:50 2013 Sebastien Chapuis
*/

#include <stdlib.h>
#include "minishell.h"

static void	free_read(t_read *list_read)
{
  t_read	*tmp;
  t_read	*tmp_next;

  tmp = list_read;
  while (tmp)
  {
    tmp_next = tmp->next;
    free(tmp);
    tmp = tmp_next;
  }
}

static void	free_cmd(t_cmd *cmd)
{
  int		i;

  i = 0;
  while (cmd && cmd->args && cmd->args[i])
  {
    free(cmd->args[i]);
    i = i + 1;
  }
  if (cmd != NULL)
  {
    free(cmd->args);
    free(cmd->filename);
    free(cmd);
  }
}

void		free_list(t_read *list_read, t_cmd *cmd, char *str)
{
  free_read(list_read);
  free_cmd(cmd);
  free(str);
}
