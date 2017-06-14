/*
** gest_game.c for allum1 in /home/ducret_t/rendu/CPE/bonus
** 
** Made by ducret_t
** Login   <ducret_t@epitech.net>
** 
** Started on  Fri Feb 26 19:20:16 2016 ducret_t
** Last update Fri Feb 26 21:46:08 2016 ducret_t
*/

#include "allum1.h"

int	turns(t_var *var)
{
  if ((player_turn(var, 0)) == -1)
    return (2);
  disp_tab(var);
  if ((check_loose(var)) == 2)
    var->loose = 1;
  else if (var->loose != 1)
    {
      a_i(var);
      disp_tab(var);
      if ((check_loose(var)) == 2)
	var->loose = 2;
    }
  return (0);
}

int	turnsjcj(t_var *var)
{
  if ((player_turn(var, 1)) == -1)
    return (2);
  disp_tab(var);
  if ((check_loose(var)) == 2)
    var->loose = 1;
  else if (var->loose != 1)
    {
      if ((player_turn(var, 2)) == -1)
	return (2);
      disp_tab(var);
      if ((check_loose(var)) == 2)
	var->loose = 2;
    }
  return (0);
}

int	game_loop(t_var *var)
{
  while (var->loose != 1 && var->loose != 2)
    {
      if (var->party_mod == 1)
	{
	  if (turns(var) == 2)
	    {
	      free(var->board);
	      return (2);
	    }
	}
      else if (var->party_mod == 2)
	{
	  if (turnsjcj(var) == 2)
	    {
	      free(var->board);
	      return (2);
	    }
	}
    }
  return (0);
}

int	set_vals(t_var *var, int ac, char **av)
{
  if (ac == 1)
    {
      var->max_cols = DEFAULTCOL;
      var->max_lines = DEFAULTLINE;
      var->party_mod = 1;
    }
  if (ac == 2)
    {
      if ((var->max_lines = my_getnbr(av[1])) == -1)
	return (-1);
      var->max_cols = (var->max_lines * 2) + 1;
      var->max_lines += 2;
      var->party_mod = 1;
    }
  else if (ac == 3)
    {
      if ((var->max_lines = my_getnbr(av[1])) == -1)
	return (-1);
      var->max_cols = (var->max_lines * 2) + 1;
      var->max_lines += 2;
      if ((var->party_mod = parse_mod(av[2])) == -1)
	return (-1);
    }
  return (0);
}
