/*
** ai_flags.c for allum1 in /home/ducret_t/rendu/CPE/CPE_2015_Allum1/srcs
** 
** Made by ducret_t
** Login   <ducret_t@epitech.net>
** 
** Started on  Sun Feb 14 16:56:22 2016 ducret_t
** Last update Sun Feb 21 22:14:51 2016 ducret_t
*/

#include "allum1.h"

void		flag_l1(t_var *var, t_ai_play *ai_play)
{
  t_ai_play	tmp;

  var->x = 1;
  find_line(var, &tmp);
  if (tmp.matches > 1)
    {
      var->board[tmp.line].matches -= tmp.matches - 1;
      var->board[tmp.line].spaces2 += tmp.matches - 1;
    }
  else
    {
      var->board[tmp.line].matches = 0;
      var->board[tmp.line].spaces2 += 1;
    }
  ai_play->line = tmp.line;
  ai_play->matches = tmp.matches;
}
