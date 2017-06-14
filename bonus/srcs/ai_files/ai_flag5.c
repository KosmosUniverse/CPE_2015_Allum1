/*
** ai_flag5.c for allum1 in /home/ducret_t/rendu/CPE/bonus
** 
** Made by ducret_t
** Login   <ducret_t@epitech.net>
** 
** Started on  Fri Feb 26 21:53:42 2016 ducret_t
** Last update Fri Feb 26 22:40:03 2016 ducret_t
*/

#include "allum1.h"

void	gest_ai_turn(t_var *var, t_ai_play **tmp, t_ai_play *ai_play)
{
  var->board[tmp[0]->line].matches -= tmp[0]->matches;
  var->board[tmp[0]->line].spaces2 += tmp[0]->matches;
  ai_play->line = tmp[0]->line;
  ai_play->matches = tmp[0]->matches;
}

void		flag_l5(t_var *var, t_ai_play *ai_play)
{
  t_ai_play	*tmp;
  int		rest;
  int		i;

  i = 0;
  rest = 0;
  rest = check_rest(var, rest);
  if ((tmp = malloc(sizeof(t_ai_play) * rest)) == NULL)
    return ;
  var->x = 1;
  while (i < rest)
    {
      find_line(var, &tmp[i]);
      i = i + 1;
    }
  gest_ai_turn(var, &tmp, ai_play);
  free(tmp);
}
