/*
** ai_flag2.c for allum1 in /home/ducret_t/rendu/CPE/CPE_2015_Allum1/srcs
** 
** Made by ducret_t
** Login   <ducret_t@epitech.net>
** 
** Started on  Sun Feb 14 17:53:40 2016 ducret_t
** Last update Sun Feb 21 22:14:50 2016 ducret_t
*/

#include "allum1.h"

void	gest_more(t_var *var, t_ai_play *tmp, t_ai_play *tmp2)
{
  if (tmp->matches == 2 && tmp2->matches == 2)
    {
      var->board[tmp->line].matches -= 2;
      var->board[tmp->line].spaces2 += 2;
    }
  else if (tmp->matches == 2)
    {
      var->board[tmp2->line].matches -= (tmp2->matches - 2);
      var->board[tmp2->line].spaces2 += (tmp2->matches - 2);
      tmp->line = tmp2->line;
      tmp->matches = tmp2->matches;
    }
  else
    {
      var->board[tmp->line].matches -= (tmp->matches - 2);
      var->board[tmp->line].spaces2 += (tmp->matches - 2);
    }
}

void		flag_l2(t_var *var, t_ai_play *ai_play)
{
  t_ai_play	tmp;
  t_ai_play	tmp2;

  var->x = 1;
  find_line(var, &tmp);
  find_line(var, &tmp2);
  if (tmp.matches == 1)
    {
      var->board[tmp2.line].matches -= tmp2.matches;
      var->board[tmp2.line].spaces2 += tmp2.matches;
    }
  else if (tmp2.matches == 1)
    {
      var->board[tmp.line].matches -= tmp.matches;
      var->board[tmp.line].spaces2 += tmp.matches;
    }
  else
    gest_more(var, &tmp, &tmp2);
  ai_play->line = tmp.line;
  ai_play->matches = tmp.matches;
}
