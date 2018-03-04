/*
** my_putchar.c for my_putchar in /home/jeremie/delivery/CPool_Day03/tests
** 
** Made by jeremie bruhwiler
** Login   <jeremie@epitech.net>
** 
** Started on  Thu Oct  6 08:48:22 2016 jeremie bruhwiler
** Last update Tue Dec  6 12:55:01 2016 jeremie bruhwiler
*/

#include <unistd.h>
#include "my.h"

void	my_putchar(char c)
{
  write(1, &c, 1);
}
