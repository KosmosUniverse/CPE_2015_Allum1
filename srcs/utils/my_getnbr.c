/*
** my_getnbr.c for my_getnbr in /home/ducret_t/rendu/Piscine_C_J07/lib/my/files.c
** 
** Made by thomas ducret
** Login   <ducret_t@epitech.net>
** 
** Started on  Wed Oct  7 21:53:35 2015 thomas ducret
** Last update Sat Feb 20 23:54:28 2016 ducret_t
*/

#include "allum1.h"

int	multiplication(char *str)
{
  int	counti;
  int	countj;

  counti = 0;
  countj = 0;
  while (str[counti] > '9' || str[counti] < '0')
    {
      if (str[counti] == '-')
	countj = countj + 1;
      counti = counti + 1;
    }
  if (countj % 2 != 0)
    return (1);
  else
    return (0);
}

int	count_number(char str)
{
  if (str >= '0' && str <= '9')
    return (1);
  else
    return (0);
}

int	verif_str(char *str)
{
  int	i;

  i = 0;
  if (str == NULL || str[0] == '\0' || str[0] == '\n')
    {
      my_putstr(1, "Error: invalid input (positive number expected)\n");
      return (-1);
    }
  while (str[i])
    {
      if (!(str[i] >= 48 && str[i] <= 57))
	{
	  my_putstr(1, "Error: invalid input (positive number expected)\n");
	  return (-1);
	}
      i = i + 1;
    }
  return (0);
}

int	my_getnbr(char *str)
{
  int	nb;
  int	countii;

  if ((verif_str(str)) == -1)
    return (-1);
  countii = 0;
  nb = 0;
  while (count_number(str[countii]) == 0)
    countii = countii + 1;
  while (count_number(str[countii]) == 1)
    {
      nb = (nb * 10) + (str[countii] - 48);
      countii = countii + 1;
    }
  if (nb > 2147483646 || nb < -2147483647)
    return (0);
  else if ((multiplication(str)) == 1)
    my_putchar('-');
  return (nb);
}
