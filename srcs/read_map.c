/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhojoon <lhojoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 13:15:22 by lhojoon           #+#    #+#             */
/*   Updated: 2023/11/20 16:39:18 by lhojoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "maps.h"

static BOOL	verify_length(t_list *read_value)
{
	size_t	len;

	if (!read_value)
		return (FALSE);
	if (ft_lstsize(read_value) <= 3)
		return (FALSE);
	len = ft_strlen(read_value->content);
	if (len <= 3)
		return (FALSE);
	while (read_value != NULL)
	{
		if (len != ft_strlen(read_value->content))
		{
			return (FALSE);
		}
		read_value = read_value->next;
	}
	return (TRUE);
}

static void	*clear_and_close(int fd, t_list **lst)
{
	close(fd);
	ft_lstclear(lst, free);
	return (NULL);
}

/**
 * Function : 
 * Import map with get_next_line
 * Verify equality of line length
 * Verify minimum length, height (3, 3)
 * 
 * 
 * Return:
 * NULL When error (malloc safe)
 * t_list<char *> when success
*/
t_list	*read_map(char *filename)
{
	t_list	*read_value;
	int		fd;
	char	*s;
	t_list	*tmplst;

	fd = open(filename, O_RDONLY);
	s = get_next_line(fd);
	read_value = NULL;
	while (s)
	{
		tmplst = ft_lstnew(s);
		if (!tmplst)
			return (clear_and_close(fd, &read_value));
		ft_lstadd_back(&read_value, tmplst);
		s = get_next_line(fd);
	}
	if (verify_length(read_value) == FALSE)
		return (clear_and_close(fd, &read_value));
	close(fd);
	return (read_value);
}
