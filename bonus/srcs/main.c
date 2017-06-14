/*
** main.c for allum1 in /home/ducret_t/rendu/CPE/CPE_2015_Allum1/srcs
** 
** Made by ducret_t
** Login   <ducret_t@epitech.net>
** 
** Started on  Wed Feb 10 21:49:37 2016 ducret_t
** Last update Fri Feb 26 21:46:09 2016 ducret_t
*/

#include "allum1.h"

void	disp_finish(t_var *var)
{
  if (var->party_mod == 1)
    {
      if (var->loose == 1)
	my_putstr(1, "You lost, too bad..\n");
      else
	my_putstr(1, "I lost.. snif.. but I'll get you next time!!\n");
    }
  else if (var->party_mod == 2)
    {
      if (var->loose == 1)
	my_putstr(1, "Player 1 : You lost and your sentence is definitive !\n");
      else
	my_putstr(1, "Player 2 : You lost and your sentence is definitive !\n");
    }
}

int	parse_mod(char *str)
{
  if (my_strlen(str) != 5 && my_strlen(str) != 4)
    {
      my_putstr(2, BAD_OPTION);
      return (-1);
    }
  else if (!(str[0] == '-' && str[1] == 'j' && str[2] == 'c' && str[3] == 'j'))
    {
      my_putstr(2, BAD_OPTION);
      return (-1);
    }
  return (2);
}

int		main(int ac, char **av)
{
  t_var		var;

  if (ac > 3)
    {
      my_putstr(2, BAD_ARGS);
      return (2);
    }
  var.loose = 0;
  if ((set_vals(&var, ac, av)) == -1)
    return (2);
  else if ((var.board = malloc(sizeof(t_line) * var.max_lines)) == NULL)
    return (2);
  gest_board(&var);
  game_loop(&var);
  disp_finish(&var);
  free(var.board);
  return (0);
}
