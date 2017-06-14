/*
** a_i.c for allum1 in /home/ducret_t/rendu/CPE/CPE_2015_Allum1/srcs
** 
** Made by ducret_t
** Login   <ducret_t@epitech.net>
** 
** Started on  Sun Feb 14 15:46:13 2016 ducret_t
** Last update Mon Mar  7 22:05:26 2016 ducret_t
*/

#include "allum1.h"

t_ai_turn	*init(t_ai_turn *tab)
{
  tab[0].ptnflag = &flag_l1;
  tab[0].key = 1;
  tab[1].ptnflag = &flag_l2;
  tab[1].key = 2;
  tab[2].ptnflag = &flag_l3;
  tab[2].key = 3;
  tab[3].ptnflag = &flag_l4;
  tab[3].key = 4;
  tab[4].ptnflag = NULL;
  tab[4].key = -1;
  return (tab);
}

int	check_rest(t_var *var, int rest)
{
  var->y = 1;
  while (var->y < var->max_lines - 1)
    {
      if (var->board[var->y].matches >= 1)
	rest = rest + 1;
      var->y = var->y + 1;
    }
  return (rest);
}

void	find_line(t_var *var, t_ai_play *tmp)
{
  while (var->x < var->max_lines)
    {
      if (var->board[var->x].matches >= 1)
	{
	  tmp->line = var->x;
	  tmp->matches = var->board[var->x].matches;
	  var->x = var->x + 1;
	  return ;
	}
      var->x = var->x + 1;
    }
}

void		a_i(t_var *var)
{
  int		i;
  t_ai_play	ai_play;
  int		rest;
  t_ai_turn	*tab;

  i = 0;
  if ((tab = malloc(sizeof(t_ai_turn) * 5)) == NULL)
    return ;
  tab = init(tab);
  my_putstr(1, "\nAI's turn...\n");
  rest = 0;
  rest = check_rest(var, rest);
  while (tab[i].key != -1)
    {
      if (tab[i].key == rest)
	tab[i].ptnflag(var, &ai_play);
      i = i + 1;
    }
  my_putstr(1, "AI removed ");
  my_put_nbr(ai_play.matches);
  my_putstr(1, " match(es) from line ");
  my_put_nbr(ai_play.line);
  my_putchar('\n');
  free(tab);
}
