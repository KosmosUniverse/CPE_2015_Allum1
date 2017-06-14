/*
** player.c for allum1 in /home/ducret_t/rendu/CPE/CPE_2015_Allum1
** 
** Made by ducret_t
** Login   <ducret_t@epitech.net>
** 
** Started on  Sat Feb 13 15:38:12 2016 ducret_t
** Last update Fri Feb 26 21:36:10 2016 ducret_t
*/

#include "allum1.h"

void	disp_res(t_play *play, t_var *var)
{
  my_putstr(1, "Player removed ");
  my_put_nbr(play->matches);
  my_putstr(1, " match(es) from line ");
  my_put_nbr(play->line);
  my_putchar('\n');
  var->board[play->line].matches -= play->matches;
  var->board[play->line].spaces2 += play->matches;
}

int	player_loop(t_var *var, t_play *play)
{
  int		match;
  char		l_check;
  char		m_check;

  m_check = 0;
  l_check = 0;
  while (m_check != 1)
    {
      if ((l_check = gest_line(l_check, var, play)) == -2)
	return (-1);
      my_putstr(1, "Matches: ");
      match = check_matches(match, var, play);
      if (match != -1 && match != -2)
	{
	  play->matches = match;
	  m_check = 1;
	}
      else if (match == -2)
	return (-1);
      else
	l_check = 0;
    }
  return (0);
}

int		player_turn(t_var *var, int nb_player)
{
  t_play	play;

  if (var->party_mod == 1)
    my_putstr(1, "\nYour turn:\n");
  else if (var->party_mod == 2)
    {
      if (nb_player == 1)
	my_putstr(1, "\nPlayer 1 turn:\n");
      else if (nb_player == 2)
	my_putstr(1, "\nPlayer 2 turn:\n");
    }
  player_loop(var, &play);
  disp_res(&play, var);
  return (0);
}
