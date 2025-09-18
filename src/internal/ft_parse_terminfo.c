/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_terminfo.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 12:44:11 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/09/18 12:59:00 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_terminfo_internal.h"
#include "core/memory/ft_memory.h"

typedef struct s_terminfo_header {
	int16_t	magic;
	int16_t	name_size;
	int16_t	bool_count;
	int16_t	num_count;
	int16_t	str_count;
	int16_t	str_size;
}	t_terminfo_header;

t_terminfo_entry	*ft_parse_terminfo(void *file_buffer)
{
	t_terminfo_header	*hdr;
	t_terminfo_entry	*etr;
	char				*ptr;

	if (!file_buffer)
		return (NULL);
	hdr = (t_terminfo_header *)file_buffer;
	if (hdr->magic != 0x010c && hdr->magic != 0x10d)
		return (NULL);
	etr = malloc(sizeof(t_terminfo_entry));
	if (!etr)
		return (NULL);
	ptr = (char *)file_buffer;
	ptr += sizeof(t_terminfo_header) + hdr->name_size + (hdr->name_size % 2);
	ft_memcpy(etr->bools, ptr, (size_t)(hdr->bool_count + 7) / 8);
	ptr += (hdr->bool_count + 7) / 8;
	if ((hdr->bool_count + hdr->name_size) % 2 != 0)
		ptr++;
	ft_memcpy(etr->nums, ptr, (size_t)hdr->num_count * sizeof(int16_t));
	ptr += hdr->num_count * sizeof(int16_t);
	ft_memcpy(etr->str_offsets, ptr, (size_t)hdr->str_count * sizeof(int16_t));
	ptr += hdr->str_count * sizeof(int16_t);
	ft_memcpy(etr->str_pool, ptr, (size_t)hdr->str_size);
	return (etr);
}
