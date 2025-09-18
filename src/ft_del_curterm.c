/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del_curterm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 11:48:19 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/09/18 19:07:06 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "ft_terminfo.h"
#include "ft_terminfo_internal.h"

void	ft_del_curterm(t_terminfo_session *session)
{
	size_t	i;

	if (!session)
		return ;
	i = 0;
	while (i < CACHE_SIZE)
	{
		if (session->cache[i])
		{
			ft_terminfo_destroy_entry(session->cache[i]);
			session->cache[i] = NULL;
		}
		i++;
	}
	free(session);
}
