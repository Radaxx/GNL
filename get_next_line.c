/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aparabos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 11:15:12 by aparabos          #+#    #+#             */
/*   Updated: 2017/12/07 15:07:08 by aparabos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int			get_next_line(const int fd, char **line)
{
	int				size;
	char			*tmp;
	char			buffer[BUFF_SIZE + 1];
	static char		*str = "";

	if (fd < 0 || line == NULL || !(str = !str ? ft_strnew(1) : str))
		return (-1);
	while (!ft_strchr(str, '\n') && (size = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		tmp = ft_strdup(str);
		buffer[size] = '\0';
		str = ft_strjoin(str, buffer);
	}
	if (size == -1)
		return (-1);
	if ((*line = (ft_strchr(str, '\n'))))
		*line = ft_strsub(str, 0, ft_strchr(str, '\n') - str);
	else
		*line = ft_strdup(str);
	if (ft_strchr(str, '\n'))
		str = ft_strsub(str, ft_strchr(str, '\n') - str + 1, ft_strlen(str));
	else
		ft_strdel(&str);
	return (!str && ft_strlen(*line) == 0 ? 0 : 1);
}
