/*
** my_setenv.c for minishell in /home/chapui_s/travaux/minishell
**
** Made by chapui_s
** Login   <chapui_s@epitech.net>
**
** Started on  Thu Dec 12 19:41:56 2013 chapui_s
** Last update Sun Jan  5 15:45:53 2014 Sebastien Chapuis
*/

#include <stdlib.h>
#include "minishell.h"

static int	mod_env(char **str, char *value)
{
  int		i;
  int		j;
  char		*new_str;

  j = 0;
  i = 0;
  while (*str && str[0][i] != '=')
    i = i + 1;
  i = i + 1;
  if ((new_str = (char*)malloc(my_strlen(value) + i + 3)) == NULL)
    return (-1);
  i = 0;
  while (*str && str[0][i - 1] != '=')
    new_str[j++] = str[0][i++];
  i = 0;
  while (value[i])
    new_str[j + i] = value[i++];
  new_str[j + i] = 0;
  *str = new_str;
}

static char	**cp_env(char **env)
{
  char		**new_env;
  int		i;

  i = 0;
  while (env[i])
    i = i + 1;
  if ((new_env = (char**)malloc(sizeof(char*) * i + 2)) == NULL)
    return (NULL);
  new_env = env;
  return (new_env);
}

static int	push_env(char ***env, char *variable, char *value)
{
  char		**new_env;
  char		*new_var;
  int		i;
  int		j;

  i = 0;
  j = 0;
  if ((new_env = cp_env(*env)) == NULL)
    return (-1);
  if ((new_var = (char*)malloc(my_strlen(value) + my_strlen(variable) + 2))
      == NULL)
    return (-1);
  while (variable[i])
    new_var[i] = variable[i++];
  while (value[j])
    new_var[j + i] = value[j++];
  new_var[j + i] = 0;
  i = 0;
  while (new_env[i])
    i = i + 1;
  new_env[i++] = new_var;
  new_env[i] = NULL;
  return (0);
}

char	*add_egale(char *var)
{
  int	size;
  char	*new_var;
  int	i;

  size = my_strlen(var);
  if ((new_var = (char*)malloc(size + 2)) == NULL)
    return (NULL);
  i = 0;
  while (var[i])
  {
    new_var[i] = var[i];
    i = i + 1;
  }
  new_var[i++] = '=';
  new_var[i] = 0;
  return (new_var);
}

int	my_setenv(char ***env, char *variable, char *value)
{
  char	**tmp_var;
  int	i;

  i = 0;
  tmp_var = *env;
  if (variable == NULL || value == NULL)
    return (my_putstr_error("usage: setenv VARIABLE VALUE\n"));
  if (variable == NULL || my_strlen(variable) == 0
      || my_strchr(variable, '=') != NULL)
    return (my_putstr_error("error : variable NULL or '=' in name\n"));
  if ((variable = add_egale(variable)) == NULL)
    return (-1);
  while (tmp_var && tmp_var[i]
	 && my_strncmp(variable, tmp_var[i], my_strlen(variable)) != 0)
    i = i + 1;
  if (tmp_var == NULL || tmp_var[i] == NULL)
  {
    if ((push_env(env, variable, value)) == -1)
      return (-1);
  }
  else if ((mod_env(&tmp_var[i], value)) == -1)
    return (-1);
  return (0);
}
