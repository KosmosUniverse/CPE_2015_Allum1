/*
** gest_tab.c for allum1 in /home/ducret_t/rendu/CPE/CPE_2015_Allum1
** 
** Made by ducret_t
** Login   <ducret_t@epitech.net>
** 
** Started on  Thu Feb 11 16:46:50 2016 ducret_t
** Last update Sun Feb 14 23:11:22 2016 ducret_t
*/

#include "allum1.h"

void	init_tab(t_var *var)
{
  int	match;
  int	spac;

  match = 1;
  spac = (var->max_cols / 2) - 1;
  var->y = 0;
  while (var->y < var->max_lines)
    {
      var->board[var->y].bool = 0;
      if (var->y == 0 || var->y == var->max_lines - 1)
	var->board[var->y].bool = 1;
      else
	{
	  var->board[var->y].matches = match;
	  var->board[var->y].spaces = spac;
	  var->board[var->y].spaces2 = spac;
	  spac = spac - 1;
	  match = match + 2;
	}
      var->y =  var->y + 1;
    }
}

void	loop(int cnt, char put, int max)
{
  while (cnt < max)
    {
      my_putchar(put);
      cnt = cnt + 1;
    }
}

void	disp_tab(t_var *var)
{
  var->y = 0;
  while (var->y < var->max_lines)
    {
      var->x = 0;
      if (var->board[var->y].bool == 1)
	loop(var->x, '*', var->max_cols);
      else
	{
	  my_putchar('*');
	  loop(var->x, ' ', var->board[var->y].spaces);
	  loop(var->x, '|', var->board[var->y].matches);
	  loop(var->x, ' ', var->board[var->y].spaces2);
	  my_putchar('*');
	}
      my_putchar('\n');
      var->y = var->y + 1;
    }
}

int	gest_board(t_var *var)
{
  init_tab(var);
  disp_tab(var);
  return (0);
}
