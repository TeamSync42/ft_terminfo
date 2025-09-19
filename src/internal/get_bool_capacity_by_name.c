/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_bool_capacity_by_name.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 16:51:36 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/09/19 17:11:04 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_terminfo_internal.h"
#include "core/string/ft_string.h"

typedef struct s_cap_hash_entry {
	const char	*id;
	int32_t		index;
	int32_t		padding;
}	t_cap_hash_entry;

static const t_cap_hash_entry	g_bool_caps_table[] = {
{NULL, -1, 0}
};

static size_t					g_bool_caps_count = sizeof(g_bool_caps_table) / sizeof(t_cap_hash_entry) - 1;

int32_t	get_bool_capacity_by_name(const char *id)
{
	size_t	i;

	i = 0;
	while (i < g_bool_caps_count)
	{
		if (ft_strcmp(g_bool_caps_table[i].id, id) == 0)
			return (g_bool_caps_table[i].index);
		i++;
	}
	return (-1);
}
