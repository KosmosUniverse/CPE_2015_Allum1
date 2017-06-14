/*
** test.c for test in /home/ducret_t/rendu/Piscine_C_J03
** 
** Made by thomas ducret
** Login   <ducret_t@epitech.net>
** 
** Started on  Thu Oct  1 19:41:07 2015 thomas ducret
** Last update Sat Feb 13 23:47:14 2016 ducret_t
*/

#include "allum1.h"

int	my_put_nbr(int nb)
{
  int	modulo;
  int	val_ret;

  val_ret = 0;
  if (nb >= 0)
    {
      if (nb >= 10)
	{
	  modulo = nb % 10;
	  nb = (nb - modulo) / 10;
	  val_ret = val_ret + 1;
	  my_put_nbr(nb);
	  my_putchar(modulo + '0');
	}
      else
	{
	  my_putchar(nb % 10 + '0');
	  val_ret = val_ret + 1;
	}
    }
  return (val_ret);
}
