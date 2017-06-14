/*
** check_error.c for allum1 in /home/ducret_t/rendu/CPE/bonus
** 
** Made by ducret_t
** Login   <ducret_t@epitech.net>
** 
** Started on  Fri Feb 26 19:44:41 2016 ducret_t
** Last update Fri Feb 26 19:53:24 2016 ducret_t
*/

#include "allum1.h"

int	check_line(int line, t_var *var)
{
  char	*get;

  if ((get = get_next_line(0)) == NULL)
    return (-2);
  line = my_getnbr(get);
  if (line == -1)
    {
      free(get);
      return (-1);
    }
  else if (line == 0 || line >= var->max_lines || var->board[line].bool == 1)
    {
      free(get);
      my_putstr(1, "Error: this line is out of range\n");
      return (-1);
    }
  else if (var->board[line].matches == 0)
    {
      free(get);
      my_putstr(1, "Error: this line is empty\n");
      return (-1);
    }
  free(get);
  return (line);
}

int	check_matches(int match, t_var *var, t_play *play)
{
  char	*get;

  if ((get = get_next_line(0)) == NULL)
    return (-2);
  match = my_getnbr(get);
  if (match == -1)
    {
      free(get);
      return (-1);
    }
  else if (match == 0 || match > var->board[play->line].matches)
    {
      free(get);
      if (match == 0)
	my_putstr(1, "Error: you have to remove at least one match\n");
      else
	my_putstr(1, "Error: not enough matches on this line\n");
      return (-1);
    }
  return (match);
}

int	gest_line(int l_check, t_var *var, t_play *play)
{
  int	line;

  while (l_check != 1)
    {
      my_putstr(1, "Line: ");
      line = check_line(line, var);
      if (line != -1 && line != -2)
	{
	  play->line = line;
	  l_check = 1;
	}
      else if (line == -2)
	return (-2);
    }
  return (l_check);
}
