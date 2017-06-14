##
## Makefile for Allum1 in /home/ducret_t/rendu/CPE/CPE_2015_Allum1
## 
## Made by ducret_t
## Login   <ducret_t@epitech.net>
## 
## Started on  Wed Feb 10 21:41:14 2016 ducret_t
## Last update Mon Mar  7 22:07:30 2016 ducret_t
##

CC	=	gcc

RM	=	rm -rf

SRCS	=	srcs/main.c \
		srcs/gest_board.c \
		srcs/check_loose.c \
		srcs/ai_files/a_i.c \
		srcs/ai_files/ai_flag1.c \
		srcs/ai_files/ai_flag2.c \
		srcs/ai_files/ai_flag3.c \
		srcs/ai_files/ai_flag4.c \
		srcs/player_file/player.c \
		srcs/utils/utils.c \
		srcs/utils/my_put_nbr.c \
		srcs/utils/my_getnbr.c \
		srcs/utils/get_next_line.c

OBJS	=	$(SRCS:.c=.o)

NAME	=	allum1

CFLAGS	+=	-W -Wall -Wextra
CFLAGS	+=	-ansi -pedantic
##CFLAGS	+=	-g -g3 -ggdb
CFLAGS	+=	-I./include

all	:	$(NAME)

$(NAME)	:	$(OBJS)
		$(CC) -o $(NAME) $(OBJS)

clean	:
		$(RM) $(OBJS)

fclean	:	clean
		$(RM) $(NAME)

re	:	fclean all

.PHONY	:	all clean fclean re

coffee:
	@echo -e "                      \033[37m\033[5m(\033[0m"
	@echo -e "                       \033[37m\033[5m)\033[0m     \033[37m\033[5m(\033[0m"
	@echo -e "                ___...\033[37m\033[5m(\033[0m ------\033[37m\033[5m)\033[0m......___"
	@echo -e "            .-\"\"       \033[37m\033[5m)\033[0m    \033[37m\033[5m(\033[0m          \"\"-."
	@echo -e "      .-'\`\`'|-_              \033[37m\033[5m)\033[0m         _.-|"
	@echo "     /  .--.|   \`\"\"---...........---\"\"\`   |"
	@echo "    /  /    |                             |"
	@echo "    |  |    |                             |"
	@echo "     \\  \\   |                             |"
	@echo "      \`\\ \`\\ |                             |"
	@echo -e "        \`\\ \`|       \033[35mBONJOUR LE SWAG\033[0m       |"
	@echo "        _/ /\\                             /"
	@echo "       (__/  \\                           /"
	@echo "    _..---\"\"\` \\                         /\`\"\"---.._"
	@echo " .-'           \\                       /          '-."
	@echo ":               \`-.__             __.-'              :"
	@echo ":                  ) \"\"---...---\"\" (                 :"
	@echo " '._               \`\"--...___...--\"\`              _.'"
	@echo "   \\\"\"--..__                              __..--\"\"/"
	@echo "    '._     \"\"\"----.....______.....----\"\"\"     _.'"
	@echo "      \`\"\"--..,,_____            _____,,..--\"\"\`"
	@echo "                    \`\"\"\"----\"\"\"\`"
