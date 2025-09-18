/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_terminfo_destroy.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 12:27:55 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/09/18 12:35:25 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "ft_terminfo_internal.h"

void	ft_terminfo_destroy(t_terminfo_session *session)
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
