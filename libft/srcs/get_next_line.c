/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavui <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 20:37:54 by mavui             #+#    #+#             */
/*   Updated: 2018/08/21 21:02:49 by mavui            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_gnl	*ft_check_fd(const int fd, t_gnl **alst)
{
	t_gnl	*current;

	if (!alst)
		return (NULL);
	current = *alst;
	while (current)
	{
		if (current->fd == fd)
			return (current);
		current = current->next;
	}
	current = *alst;
	if (!((*alst) = (t_gnl*)malloc(sizeof(t_gnl))))
		return (NULL);
	if (!((*alst)->s = ft_strnew(0)))
		return (NULL);
	(*alst)->fd = fd;
	(*alst)->next = current;
	return (*alst);
}

char	*ft_read(t_gnl *file)
{
	char		*buf;
	char		*tofree;
	int			ret;

	if (!(buf = ft_strnew(BUFF_SIZE + 1)))
		return (NULL);
	while ((ret = read(file->fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		tofree = file->s;
		if (!(file->s = ft_strjoin(file->s, buf)))
		{
			ft_strdel(&tofree);
			return (NULL);
		}
		ft_strdel(&tofree);
		if (ft_strchr(file->s, '\n'))
			break ;
	}
	ft_strdel(&buf);
	return (file->s);
}

int		get_next_line(const int fd, char **line)
{
	char				*tmp;
	int					i;
	int					ret;
	static t_gnl		*files;
	t_gnl				*file;

	if (read(fd, NULL, 0) == -1 || line == NULL || BUFF_SIZE <= 0
		|| !(file = ft_check_fd(fd, &files)))
		return (-1);
	i = 0;
	if (!(tmp = ft_read(file)))
		return (-1);
	while (tmp[i] != '\0' && tmp[i] != '\n')
		i++;
	ret = *tmp || i > 0;
	if (!(*line = ft_strsub(tmp, 0, i)))
	{
		free(tmp);
		return (-1);
	}
	if (!(file->s = ft_strsub(tmp, (!tmp[i]) ? i : i + 1, ft_strlen(tmp))))
		return (-1);
	ft_strdel(&tmp);
	ret == 0 ? free(file->s) : 0;
	return (ret);
}
