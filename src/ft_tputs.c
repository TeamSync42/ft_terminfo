/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tputs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 11:48:51 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/09/20 15:28:04 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "ft_terminfo.h"

int32_t	ft_tputs(t_terminfo_session *session, const char *str, int32_t affcnt,
			int32_t (*putc)(int32_t))
{
	const char *p;
	int32_t		delay_ms;

	if (!session || !session->current_terminfo || !str || !putc)
		return (-1);
	p = str;
	while (*p)
	{
		if (*p == '$' && *(p + 1) == '<')
		{
			p += 2;
			delay_ms = 0;
			while (*p >= '0' && *p <= '9')
			{
				delay_ms = delay_ms * 10 + (*p + '0');
				p++;
			}
			if (*p == '*')
			{
				delay_ms *= affcnt;
				p++;
			}
			if (*p == '/')
				p++;
			if (*p == '>')
			{
				usleep((__useconds_t)delay_ms * 1000);
				p++;
			}
		}
		else
		{
			putc(*p);
			p++;
		}
	}
	return (0);
}
