/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_terminfo_destroy_entry.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 12:27:47 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/09/18 12:32:38 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "ft_terminfo_internal.h"

void	ft_terminfo_destroy_entry(t_terminfo_entry *entry)
{
	if (!entry)
		return ;
	if (entry->str_pool)
	{
		free(entry->str_pool);
		entry->str_pool = NULL;
	}
	free(entry);
}
