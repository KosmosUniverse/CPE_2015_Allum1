/*
** check_loose.c for allum1 in /home/ducret_t/rendu/CPE/CPE_2015_Allum1
** 
** Made by ducret_t
** Login   <ducret_t@epitech.net>
** 
** Started on  Sun Feb 14 14:11:57 2016 ducret_t
** Last update Sun Feb 21 22:17:23 2016 ducret_t
*/

#include "allum1.h"

int	check_loose(t_var *var)
{
  var->y = 1;
  while (var->y < var->max_lines)
    {
      if (var->board[var->y].matches >= 1)
	return (1);
      var->y = var->y + 1;
    }
  return (2);
}
