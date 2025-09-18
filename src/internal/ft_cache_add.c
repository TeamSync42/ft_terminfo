/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cache_add.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 12:36:49 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/09/18 12:40:33 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_terminfo_internal.h"
#include "core/string/ft_string.h"

int32_t	ft_cache_add(t_terminfo_session *session, const char *term_name,
			t_terminfo_entry *entry)
{
	int32_t	idx;

	if (!session || !entry || !term_name)
		return (-1);
	idx = hash_termname(term_name, ft_strlen(term_name));
	if (session->cache[idx])
		ft_terminfo_destroy_entry(session->cache[idx]);
	session->cache[idx] = entry;
	return (0);
}
