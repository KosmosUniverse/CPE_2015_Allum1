/*
** ai_flag3.c for allum1 in /home/ducret_t/rendu/CPE/CPE_2015_Allum1/srcs
** 
** Made by ducret_t
** Login   <ducret_t@epitech.net>
** 
** Started on  Sun Feb 14 18:26:58 2016 ducret_t
** Last update Sun Feb 21 22:25:29 2016 ducret_t
*/

#include "allum1.h"

int	gest_2l(t_var *var, t_ai_play *tmp, t_ai_play *tmp2, t_ai_play *tmp3)
{
  if (tmp->matches == 1 && tmp2->matches == 1)
    {
      var->board[tmp3->line].matches -= (tmp3->matches - 1);
      var->board[tmp3->line].spaces2 += (tmp3->matches - 1);
      tmp->line = tmp3->line;
      tmp->matches = tmp3->matches;
      return (1);
    }
  else if (tmp->matches == 1 && tmp3->matches == 1)
    {
      var->board[tmp2->line].matches -= (tmp2->matches - 1);
      var->board[tmp2->line].spaces2 += (tmp2->matches - 1);
      tmp->line = tmp2->line;
      tmp->matches = tmp2->matches;
      return (1);
    }
  else if (tmp2->matches == 1 && tmp3->matches == 1)
    {
      var->board[tmp->line].matches -= (tmp->matches - 1);
      var->board[tmp->line].spaces2 += (tmp->matches - 1);
      return (1);
    }
  return (0);
}

int	gest_1l(t_var *var, t_ai_play *tmp, t_ai_play *tmp2, t_ai_play *tmp3)
{
  if (tmp->matches == 1)
    {
      var->board[tmp->line].matches -= 1;
      var->board[tmp->line].spaces2 += 1;
      return (1);
    }
  else if (tmp2->matches == 1)
    {
      var->board[tmp2->line].matches -= 1;
      var->board[tmp2->line].spaces2 += 1;
      tmp->line = tmp2->line;
      tmp->matches = 1;
      return (1);
    }
  else if (tmp3->matches == 1)
    {
      var->board[tmp3->line].matches -= 1;
      var->board[tmp3->line].spaces2 += 1;
      tmp->line = tmp3->line;
      tmp->matches = 1;
      return (1);
    }
  return (0);
}

void		flag_l3(t_var *var, t_ai_play *ai_play)
{
  t_ai_play	tmp;
  t_ai_play	tmp2;
  t_ai_play	tmp3;

  var->x = 1;
  find_line(var, &tmp);
  find_line(var, &tmp2);
  find_line(var, &tmp3);
  if (tmp.matches == 1 && tmp2.matches == 1 && tmp3.matches == 1)
    {
      var->board[tmp.line].matches -= 1;
      var->board[tmp.line].spaces2 += 1;
    }
  else if (gest_2l(var, &tmp, &tmp2, &tmp3) == 0)
    {
      if (gest_1l(var, &tmp, &tmp2, &tmp3) == 0)
	{
	  var->board[tmp.line].matches -= 1;
	  var->board[tmp.line].spaces2 += 1;
	  tmp.matches = 1;
	}
    }
  ai_play->line = tmp.line;
  ai_play->matches = tmp.matches;
}
