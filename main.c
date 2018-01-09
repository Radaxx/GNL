/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparabos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 12:50:07 by aparabos          #+#    #+#             */
/*   Updated: 2017/12/10 10:52:38 by aparabos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		main(int ac, char **av)
{
	char	*line;
	int		fd;

	(void)av;
	(void)ac;
	fd = 0;
	//if (!(fd = open(av[1], O_RDONLY)))
	//	return (0);
	ft_putstr("Valeur de retour: ");
	ft_putnbr(get_next_line(fd, &line));
	ft_putchar('\n');
	ft_putstr(line);
	ft_putchar('\n');
	free(line);

	return (0);
}
