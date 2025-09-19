/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setupterm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 11:48:09 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/09/19 17:03:42 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_terminfo.h"
#include "ft_terminfo_internal.h"

t_terminfo_session	*ft_setupterm(const char *term, const int32_t fildes,
						int32_t *errret)
{
	t_terminfo_session	*session;
	t_terminfo_entry	*entry;

	(void)fildes;
	session = ft_terminfo_init();
	if (!session)
	{
		if (errret)
			*errret = -1;
		return (NULL);
	}
	session->get_bool_index = get_bool_capacity_by_name;
	entry = ft_get_terminfo_entry(session, term);
	if (!entry)
	{
		ft_terminfo_destroy(session);
		if (errret)
			*errret = -1;
		return (NULL);
	}
	session->current_terminfo = entry;
	if (errret)
		*errret = 0;
	return (session);
}
