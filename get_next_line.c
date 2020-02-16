/*
** get_next_line.c for get_next_line in /home/jeremie/delivery/CPE/CPE_2016_getnextline
** 
** Made by jeremie
** Login   <jeremie@epitech.net>
** 
** Started on  Mon Jan  2 10:03:09 2017 jeremie 
** Last update Mon Jan 16 09:24:50 2017 jeremie 
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

/*
 * my_strlen
 */

int	my_count(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
      i++;
  return (i);
}

/*
 * dest = destination du copiage de la memoire
 * src = source du copiage de la memoire
 * n = nombre de bytes copier
 * size de memoire modifier
 */

void	my_memcpy(char *dest, char *src, int n)
{
  char	*csrc;
  char	*cdest;
  int	i;

  i = 0;
  csrc = (char *)src;
  cdest = (char *)dest;
  while (i < n)
    {
      cdest[i] = csrc[i];
      i++;
    }
}

/*
 * str = string a realocer
 * permet de realloc une string selon READ_SIZE
 * string realloc
 */

char		*r_ma(char *str)
{
  char		*stock;
  int		size;
  static int	i = 1;

  i++;
  size = READ_SIZE * i;
  stock = malloc(sizeof(*stock) * size);
  if (stock == NULL || size == 0)
    return (NULL);
  my_memcpy(stock, str, size);
  free(str);
  return (stock);
}

/*
 * fd = file descriptor
 * str = string a malloc
 * gerent les erreurs
 * string mallocer
 */

char	*beginn(int fd, char *str)
{
  str = malloc(sizeof(str) * READ_SIZE);
  if (fd <= -1 || str == NULL || READ_SIZE <= 0)
    return (NULL);
  return (str);
}

/*
 * file descriptor
 * len = compteur pour str
 * str = stockage du s
 * i = compteur du s
 * s = char a read
 * str == contient s
 */

char		*get_next_line(const int fd)
{
  int		len;
  char		*str;
  static int	i = 0;
  static char	s[READ_SIZE];

  str = beginn(fd, str);
  if (str == NULL)
    return (NULL);
  if ((s[i] == '\n' && s[i] == '\0') || (len = 0) != -1)
    while (s[i++] != '\n' && s[i++] != '\0')
      str[len++] = s[i++];
  while (s[i] != '\n')
    {
      if (s[i] == '\0')
	if (read(fd, s, READ_SIZE) == 0 || (str = r_ma(str)) == NULL || (i = 0))
	  return (NULL);
      if (s[i] == '\n')
	{
	  str[len] = '\0';
	  return (str);
	}
      str[len++] = s[i++];
    }
  str[len] = '\0';
  return (str);
}
