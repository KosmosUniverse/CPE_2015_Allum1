/*
** utils.c for allum1 in /home/ducret_t/rendu/CPE/CPE_2015_Allum1
** 
** Made by ducret_t
** Login   <ducret_t@epitech.net>
** 
** Started on  Fri Feb 12 14:29:00 2016 ducret_t
** Last update Thu Feb 18 16:28:38 2016 ducret_t
*/

#include "allum1.h"

void	my_putchar(char c)
{
  write(1, &c, 1);
}

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    i = i + 1;
  return (i);
}

void	my_putstr(int output, char *str)
{
  write(output, str, my_strlen(str));
}
