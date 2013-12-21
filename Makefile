##
## Makefile for minishell in /home/sebastien/travaux/minishell
## 
## Made by Sebastien Chapuis
## Login   <sebastien@epitech.net>
## 
## Started on  Wed Dec 18 17:17:54 2013 Sebastien Chapuis
## Last update Sat Dec 21 16:19:15 2013 Sebastien Chapuis
##

SRC	= main.c \
	  my_setenv.c \
	  my_unsetenv.c \
	  exec_cmd.c \
	  find_cmd.c \
	  free_cmd.c \
	  get_commande.c \
	  list_read.c \
	  my_atoi.c \
	  my_strcat.c \
	  my_env.c \
	  my_env_exec.c \
	  my_strdup.c \
	  my_strncmp.c \
	  my_strchr.c \
	  my_strcmp.c \
	  my_cd.c \
	  my_str_to_wordtab.c \
	  utils.c \
	  utils2.c \
	  signal.c

NAME	= mysh

CFLAGS	= -ggdb

OBJ	= $(SRC:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
	@echo -e "\033[32m[build]" | tr -d '\n'
	gcc $(OBJ) -o $(NAME) -ggdb
	@echo -e "\033[0m" | tr -d '\n'

clean:
	@echo -e "\033[31m[clean] " | tr -d '\n'
	rm -f $(OBJ)
	@echo -e "\033[0m" | tr -d '\n'

fclean:	clean
	@echo -e "\033[31m[fclean] " | tr -d '\n'
	rm -f $(NAME)
	@echo -e "\033[0m" | tr -d '\n'

re:	fclean all
