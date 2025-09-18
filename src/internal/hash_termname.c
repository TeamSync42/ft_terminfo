/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_termname.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 12:14:12 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/09/18 12:16:24 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_terminfo_internal.h"

#define FNV_PRIME_32	0x01000193
#define FNV_OFFSET_32	0x811c9dc5

int32_t	hash_termname(const char *s, const size_t size)
{
	uint32_t	hash;
	size_t		i;

	hash = FNV_OFFSET_32;
	i = 0;
	while (i < size)
	{
		hash ^= (uint8_t)s[i];
		hash *= FNV_PRIME_32;
		i++;
	}
	return ((int32_t)(hash % CACHE_SIZE));
}
