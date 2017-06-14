/*
** main.c for allum1 in /home/ducret_t/rendu/CPE/CPE_2015_Allum1/srcs
** 
** Made by ducret_t
** Login   <ducret_t@epitech.net>
** 
** Started on  Wed Feb 10 21:49:37 2016 ducret_t
** Last update Sun Feb 21 20:21:25 2016 ducret_t
*/

#include "allum1.h"

int	game_loop(t_var *var, t_play *play)
{
  if ((player_turn(var, play)) == -1)
    return (2);
  disp_tab(var);
  if ((check_loose(var)) == 2)
    var->loose = 1;
  if (var->loose != 1)
    {
      a_i(var);
      disp_tab(var);
      if ((check_loose(var)) == 2)
	var->loose = 2;
    }
  return (0);
}

void	disp_finish(t_var *var)
{
  if (var->loose == 1)
    my_putstr(1, "You lost, too bad..\n");
  else
    my_putstr(1, "I lost.. snif.. but I'll get you next time!!\n");
}

int		main()
{
  t_var		var;
  t_play	play;

  var.loose = 0;
  var.max_cols = DEFAULTCOL;
  var.max_lines = DEFAULTLINE;
  if ((var.board = malloc(sizeof(t_line) * var.max_lines)) == NULL)
    return (2);
  gest_board(&var);
  while (var.loose != 1 && var.loose != 2)
    {
      if (game_loop(&var, &play) == 2)
	{
	  free(var.board);
	  return (2);
	}
    }
  disp_finish(&var);
  free(var.board);
  return (0);
}
