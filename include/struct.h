/*
** struct.h for allum1 in /home/ducret_t/rendu/CPE/CPE_2015_Allum1/include
** 
** Made by ducret_t
** Login   <ducret_t@epitech.net>
** 
** Started on  Sun Feb 14 22:28:27 2016 ducret_t
** Last update Tue Feb 16 19:32:00 2016 ducret_t
*/

#ifndef STRUCT_H_
# define STRUCT_H_

typedef struct	s_play
{
  int		line;
  int		matches;
}		t_play;

typedef struct	s_line
{
  char		bool;
  int		spaces;
  int		matches;
  int		spaces2;
}		t_line;

typedef struct	s_var
{
  t_line	*board;
  int		max_lines;
  int		max_cols;
  int		x;
  int		y;
  char		loose;
}		t_var;

typedef struct	s_ai_play
{
  int		line;
  int		matches;
}		t_ai_play;

typedef struct	s_ai_turn
{
  void		(*ptnflag)(t_var *var, t_ai_play *ai_play);
  int		key;
}		t_ai_turn;

#endif /* !STRUCT_H_ */
