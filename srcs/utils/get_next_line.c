/*
** get_next_line.c for allum1 in /home/ducret_t/rendu/CPE/CPE_2015_Allum1
** 
** Made by ducret_t
** Login   <ducret_t@epitech.net>
** 
** Started on  Fri Feb 19 18:44:07 2016 ducret_t
** Last update Sun Feb 21 22:24:34 2016 ducret_t
*/

#include "allum1.h"

char	*my_realloc(char *buffer, char *str)
{
  char	*new_str;
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (str != NULL && str[i] != '\0')
    i = i + 1;
  while (buffer[j] != '\0' && buffer[j] != '\n')
    j = j + 1;
  if ((new_str = malloc(sizeof(char) * (i + j + 2))) == NULL)
    return (NULL);
  if (str != NULL)
    {
      i = 0;
      while (str[i] != '\0')
	{
	  new_str[i] = str[i];
	  i = i + 1;
	}
      free(str);
    }
  return (new_str);
}

char	*get_next_line(const int fd)
{
  char	buffer[2];
  int	idx;
  char	*str;
  int	read_value;

  idx = 0;
  buffer[0] = '\0';
  str = NULL;
  while (buffer[0] != '\n')
    {
      read_value = read(fd, buffer, 1);
      if (read_value == -1 || read_value == 0)
  	return (NULL);
      buffer[read_value] = '\0';
      if ((str = my_realloc(buffer, str)) == NULL)
  	return (NULL);
      str[idx] = buffer[0];
      idx = idx + 1;
      str[idx] = '\0';
    }
  if (str[idx - 1] == '\n')
    str[idx - 1] = '\0';
  return (str);
}
