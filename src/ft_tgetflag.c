/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tgetflag.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 11:48:31 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/09/20 11:11:28 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_terminfo.h"
#include "ft_terminfo_internal.h"

int32_t	ft_tgetflag(t_terminfo_session *session, const char *id)
{
	int32_t				idx;
	t_terminfo_entry	*entry;

	if (!session || !session->current_terminfo)
		return (0);
	idx = ft_find_capability_index(id, CAP_TYPE_BOOL);
	if (idx == -1)
		return (0);
	entry = session->current_terminfo;
	if (idx >= MAX_BOOLS_CAPS)
		return (0);
	if (entry->bools[idx >> 3] & (1 << idx % 8))
		return (1);
	return (0);
}
