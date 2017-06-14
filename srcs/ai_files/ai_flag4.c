/*
** ai_flag4.c for allum1 in /home/ducret_t/rendu/CPE/CPE_2015_Allum1/srcs
** 
** Made by ducret_t
** Login   <ducret_t@epitech.net>
** 
** Started on  Sun Feb 14 18:55:49 2016 ducret_t
** Last update Sun Feb 21 22:15:15 2016 ducret_t
*/

#include "allum1.h"

int	gest_l(t_var *var, t_ai_play **tmp)
{
  if (tmp[0]->matches == 1 && tmp[1]->matches == 1 && tmp[2]->matches == 1)
    {
      var->board[tmp[3]->line].matches -= tmp[3]->matches;
      var->board[tmp[3]->line].spaces2 += tmp[3]->matches;
      tmp[0]->line = tmp[3]->line;
      tmp[0]->matches = tmp[3]->matches;
      return (1);
    }
  else if (tmp[0]->matches == 1 && tmp[1]->matches == 1 && tmp[3]->matches == 1)
    {
      var->board[tmp[2]->line].matches -= tmp[2]->matches;
      var->board[tmp[2]->line].spaces2 += tmp[2]->matches;
      tmp[0]->line = tmp[2]->line;
      tmp[0]->matches = tmp[2]->matches;
      return (1);
    }
  else if (tmp[0]->matches == 1 && tmp[2]->matches == 1 && tmp[3]->matches == 1)
    {
      var->board[tmp[1]->line].matches -= tmp[1]->matches;
      var->board[tmp[1]->line].spaces2 += tmp[1]->matches;
      tmp[0]->line = tmp[1]->line;
      tmp[0]->matches = tmp[1]->matches;
      return (1);
    }
  return (0);
}

void	check_zone(t_var *var, t_ai_play **tmp)
{
  if (tmp[0]->matches == 1 && tmp[1]->matches == 1 &&
      tmp[2]->matches == 1 && tmp[3]->matches == 1)
    {
      var->board[tmp[0]->line].matches -= 1;
      var->board[tmp[0]->line].spaces2 += 1;
    }
  else
    {
      if (gest_l(var, tmp) == 0)
	{
	  var->board[tmp[0]->line].matches -= tmp[0]->matches;
	  var->board[tmp[0]->line].spaces2 += tmp[0]->matches;
	}
    }
}

void		flag_l4(t_var *var, t_ai_play *ai_play)
{
  t_ai_play	*tmp;

  if ((tmp = malloc(sizeof(t_ai_play) * 4)) == NULL)
    return ;
  var->x = 1;
  find_line(var, &tmp[0]);
  find_line(var, &tmp[1]);
  find_line(var, &tmp[2]);
  find_line(var, &tmp[3]);
  check_zone(var, &tmp);
  ai_play->line = tmp[0].line;
  ai_play->matches = tmp[0].matches;
  free(tmp);
}
