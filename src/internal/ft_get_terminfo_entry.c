/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_terminfo_entry.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 12:36:43 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/09/18 18:51:54 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_terminfo_internal.h"
#include "core/string/ft_string.h"

t_terminfo_entry	*ft_get_terminfo_entry(t_terminfo_session *session,
											const char *term_name)
{
	int32_t				idx;
	t_terminfo_entry	*entry;

	if (!session || !term_name)
		return (NULL);
	idx = hash_termname(term_name, ft_strlen(term_name));
	entry = session->cache[idx];
	if (entry)
		return (entry);
	entry = ft_load_terminfo_from_file(term_name);
	if (entry)
		ft_cache_add(session, term_name, entry);
	return (entry);
}
