/*
** my_putstr.c for my_putstr in /home/jeremie/delivery/CPool_Day04
** 
** Made by jeremie bruhwiler
** Login   <jeremie@epitech.net>
** 
** Started on  Thu Oct  6 15:29:38 2016 jeremie bruhwiler
** Last update Mon Jan  2 17:37:21 2017 jeremie bruhwiler
*/

#include "my.h"

void	my_putchar(char c);

int	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      my_putchar(str[i]);
      i = i + 1;
    }
  return (1);
}
