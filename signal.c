/*
** signal.c for minishell in /home/sebastien/travaux/minishell
**
** Made by Sebastien Chapuis
** Login   <sebastien@epitech.net>
**
** Started on  Thu Dec 19 18:35:28 2013 Sebastien Chapuis
** Last update Sun Jan  5 14:05:16 2014 Sebastien Chapuis
*/

#include <unistd.h>

void	get_first_sigint(int sig)
{
  write(1, "\n$> ", 4);
}

void	get_sigint(int sig)
{
  write(1, "\r\n", 2);
}
