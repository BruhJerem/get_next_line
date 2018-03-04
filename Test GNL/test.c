/*
** test.c for gnl in /home/jeremie/delivery/CPE/CPE_2016_getnextline
** 
** Made by jeremie bruhwiler
** Login   <jeremie@epitech.net>
** 
** Started on  Fri Jan 13 08:29:48 2017 jeremie bruhwiler
** Last update Mon Jan 16 09:08:55 2017 jeremie bruhwiler
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdio.h>
#include "../get_next_line.h"
#include "my.h"

int	fs_open_file(char *filepath)
{
  int	fd;

  if ((fd = open(filepath, O_RDONLY)) == -1)
    {
      my_putstr("File doesn't exist\n");
      return (-1);
    }
  return (fd);
}

int	main(int ar, char **av)
{
  char	*su;
  int	fd;

  if ((fd = fs_open_file(av[1])) == -1 || ar != 2)
    return (1);
  while ((su = get_next_line(-2)))
    {
    my_putstr("-------\n");
    my_putstr(su);
    my_putchar('\n');
    free(su);
    }
  printf("%s\n", get_next_line(fd));
  printf("%s\n", get_next_line(fd));
  printf("%s\n", get_next_line(fd));
  printf("%s\n", get_next_line(fd));
  printf("%s\n", get_next_line(fd));
  //printf("%s\n", get_next_line(fd));
  //printf("%s\n", get_next_line(fd));
  return (0);
}
