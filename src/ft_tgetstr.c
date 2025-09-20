/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tgetstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 11:48:45 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/09/20 11:18:47 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_terminfo.h"
#include "ft_terminfo_internal.h"
#include "core/string/ft_string.h"

char	*ft_tgetstr(t_terminfo_session *session, const char *id, char **area)
{
	int32_t				idx;
	int32_t				offset;
	char				*str_res;
	t_terminfo_entry	*entry;

	if (!session || !session->current_terminfo || !id || !area)
		return (NULL);
	entry = session->current_terminfo;
	idx = ft_find_capability_index(id, CAP_TYPE_STR);
	if (idx == -1)
		return (NULL);
	offset = entry->str_offsets[idx];
	if (offset == -1)
		return (NULL);
	str_res = entry->str_pool + offset;
	ft_strcpy(*area, str_res);
	*area += ft_strlen(str_res) + 1;
	return (*area);
}
