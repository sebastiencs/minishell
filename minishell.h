/*
** minishell.h for minishell in /home/chapui_s/travaux/minishell
**
** Made by chapui_s
** Login   <chapui_s@epitech.net>
**
** Started on  Tue Dec 10 16:17:05 2013 chapui_s
** Last update Sun Jan  5 13:26:51 2014 Sebastien Chapuis
*/

typedef struct	s_read
{
  char		c;
  struct s_read	*next;
}		t_read;

typedef struct	s_cmd
{
  char		*filename;
  char		*cmd_path;
  char		**args;
}		t_cmd;

typedef struct	s_env
{
  int		i;
  int		zero;
  int		u;
}		t_env;

int		push_read(t_read **list, char c, char **env);
char		*list_to_str(t_read *list_read);
t_cmd		*str_to_cmd(char *str, char **environ);
char		**my_str_to_wordtab(char *str);
int		exec_cmd(char **environ, t_read *list_read, t_cmd *cmd,
			 char *str);
void		free_list(t_read *list_read, t_cmd *cmd, char *str);
char		*find_cmd(char *str, char ** environ, int i, char *tmp);
int		my_strncmp(char *s1, char *s2, int n);
char		*my_strdup(char *str);
char		*str_cat(char *s1, char *s2);
unsigned int	my_strlen(char *str);
void		my_putstr(char *str);
int		my_setenv(char ***env, char *variable, char *value);
int		my_unsetenv(char ***env, char *variable);
int		my_strcmp(char *s1, char *s2);
char		*my_strchr(char *s, int c);
int		cmd_null(t_cmd *cmd, char *str);
void		get_first_sigint(int sig);
void		get_sigint(int sig);
int		is_only_spaces(char *str);
int		my_env(char **env, t_cmd *cmd);
void		usage_env(void);
int		exec_env_null(t_cmd *cmd, int j);
int		exec_it(t_cmd *cmd, char **environ, t_read *list_read, char *str);
char		*left_egale(char *str);
char		*right_egale(char *str);
int		my_atoi(char *str);
int		my_exit(char *str);
int		my_cd(char *path, char **env);
char		*search_in_env(char **env, char *var);
int		my_putstr_error(char *str);
void		prompt(char **env);
