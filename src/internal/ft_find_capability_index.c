/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_capability_index.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 16:51:36 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/09/20 07:12:28 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "ft_terminfo_internal.h"
#include "core/string/ft_string.h"

static bool	determine_type_and_count(const int32_t type,
				const t_cap_hash_entry **table, int32_t *count)
{
	if (type == CAP_TYPE_BOOL)
	{
		*table = g_bool_caps_table;
		*count = g_bool_caps_count;
	}
	else if (type == CAP_TYPE_NUM)
	{
		*table = g_num_caps_table;
		*count = g_num_caps_count;
	}
	else if (type == CAP_TYPE_STR)
	{
		*table = g_str_caps_table;
		*count = g_str_caps_count;
	}
	else
		return (-1);
	return (0);
}

int32_t	ft_find_capability_index(const char *id, const int32_t type)
{
	const t_cap_hash_entry	*table;
	int32_t					count;
	size_t					i;

	if (determine_type_and_count(type, &table, &count) != 0)
		return (-1);
	i = 0;
	while (i < (size_t)count)
	{
		if (ft_strcmp(table[i].id, id) == 0)
			return (table[i].index);
		i++;
	}
	return (-1);
}
