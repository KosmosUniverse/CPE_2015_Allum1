/*
** allum1.h for allum1 in /home/ducret_t/rendu/CPE/CPE_2015_Allum1/srcs
** 
** Made by ducret_t
** Login   <ducret_t@epitech.net>
** 
** Started on  Wed Feb 10 21:50:40 2016 ducret_t
** Last update Fri Feb 26 22:15:07 2016 ducret_t
*/

#ifndef ALLUM1_H_
# define ALLUM1_H_

# include <unistd.h>
# include <stdlib.h>
# include "struct.h"

# define GNL_BUFF_SIZE 64
# define BAD_ARGS "Bad count arguments\n"
# define BAD_OPTION "Bad Option : only -jcj\n"
# define DEFAULTLINE 6
# define DEFAULTCOL 9

/*
** #####################################
** #----------------SRCS---------------#
** #####################################
*/

/*
** -------------------------------------
** ------------GEST_BOARD_C_------------
** -------------------------------------
*/

int	gest_board(t_var *var);
void	disp_tab(t_var *var);
void	init_tab(t_var *var);

/*
** -------------------------------------
** -----------CHECK_LOOSE_C_------------
** -------------------------------------
*/

int	check_loose(t_var *var);

/*
** -------------------------------------
** --------------MAIN_C_----------------
** -------------------------------------
*/

int	parse_mod(char *str);
void	disp_finish(t_var *var);
int	game_loop(t_var *var);

/*
** -------------------------------------
** ------------GEST_GAME_C_-------------
** -------------------------------------
*/

int	turns(t_var *var);
int	turnsjcj(t_var *var);
int	game_loop(t_var *var);
int	set_vals(t_var *var, int ac, char **av);

/*
** #####################################
** #---------SRCS/PLAYER_FILE----------#
** #####################################
*/

/*
** -------------------------------------
** --------------PLAYER_C_--------------
** -------------------------------------
*/

void	disp_res(t_play *play, t_var *var);
int	player_loop(t_var *var, t_play *play);
int	player_turn(t_var *var, int nb_player);

/*
** -------------------------------------
** ------------CECK_ERROR_C_------------
** -------------------------------------
*/

int	gest_line(int l_check, t_var *var, t_play *play);
int	check_line(int line, t_var *var);
int	check_matches(int match, t_var *var, t_play *play);

/*
** #####################################
** #-----------SRCS/AI_FILES-----------#
** #####################################
*/

/*
** -------------------------------------
** ----------------A_I_C_---------------
** -------------------------------------
*/

void	a_i(t_var *var);
int	check_rest(t_var *var, int rest);
void	find_line(t_var *var, t_ai_play *tmp);

/*
** -------------------------------------
** --------------FLAG_L1_C_-------------
** -------------------------------------
*/

void	flag_l1(t_var *var, t_ai_play *ai_play);

/*
** -------------------------------------
** --------------FLAG_L2_C_-------------
** -------------------------------------
*/

void	flag_l2(t_var *var, t_ai_play *ai_play);
void	gest_more(t_var *var, t_ai_play *tmp, t_ai_play *tmp2);

/*
** -------------------------------------
** --------------FLAG_L3_C_-------------
** -------------------------------------
*/

void	flag_l3(t_var *var, t_ai_play *ai_play);
int	gest_1l(t_var *var, t_ai_play *tmp, t_ai_play *tmp2, t_ai_play *tmp3);
int	gest_2l(t_var *var, t_ai_play *tmp, t_ai_play *tmp2, t_ai_play *tmp3);

/*
** -------------------------------------
** --------------FLAG_L4_C_-------------
** -------------------------------------
*/

int	gest_l(t_var *var, t_ai_play **tmp);
void	flag_l4(t_var *var, t_ai_play *ai_play);

/*
** -------------------------------------
** --------------FLAG_L5_C_-------------
** -------------------------------------
*/

void	flag_l5(t_var *var, t_ai_play *ai_play);
void	gest_ai_turn(t_var *var, t_ai_play **tmp, t_ai_play *ai_play);

/*
** #####################################
** #-------------SRCS/UTILS------------#
** #####################################
*/

/*
** -------------------------------------
** --------------UTILS_C_---------------
** -------------------------------------
*/

void	my_putchar(char c);
int	my_strlen(char *str);
void	my_putstr(int output, char *str);

/*
** -------------------------------------
** ------------MY_GETNBR_C_-------------
** -------------------------------------
*/

int	my_getnbr(char *str);
int	verif_str(char *str);
int	count_number(char str);
int	multiplication(char *str);

/*
** -------------------------------------
** ----------GET_NEXT_LINE_C_-----------
** -------------------------------------
*/

char	*get_next_line(const int fd);
char	*my_realloc(char *buffer, char *str);

/*
** -------------------------------------
** ------------MY_PUT_NBR_C_------------
** -------------------------------------
*/

int	my_put_nbr(int nb);

#endif /* !ALLUM1_H_ */
