/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_terminfo_init.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 12:18:49 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/09/18 12:21:00 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "ft_terminfo_internal.h"
#include "core/memory/ft_memory.h"

t_terminfo_session	*ft_terminfo_init(void)
{
	t_terminfo_session	*session;

	session = malloc(sizeof(t_terminfo_session));
	if (!session)
		return (NULL);
	session->current_terminfo = NULL;
	ft_memset(session->cache, 0, sizeof(session->cache));
	return (session);
}
