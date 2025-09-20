/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tgetnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 11:48:38 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/09/20 00:45:48 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_terminfo.h"
#include "ft_terminfo_internal.h"

int32_t	ft_tgetnum(t_terminfo_session *session, const char *id)
{
	t_terminfo_entry	*entry;
	int32_t				cap_idx;

	if (!session || !session->current_terminfo)
		return (-1);
	entry = session->current_terminfo;
	cap_idx = ft_find_capability_index(id, CAP_TYPE_NUM);
	if (cap_idx == -1)
		return (-1);
	return (entry->nums[cap_idx]);
}
