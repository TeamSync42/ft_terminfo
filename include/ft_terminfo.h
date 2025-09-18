/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_terminfo.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 22:59:32 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/09/18 11:52:32 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TERMINFO_H
# define FT_TERMINFO_H

# include <stdint.h>

int32_t	ft_setupterm(const char *term, int32_t fildes, int32_t *errret);
int32_t	ft_del_curterm(void);

int32_t	ft_tgetflag(const char *id);
int32_t	ft_tgetnum(const char *id);
char	*ft_tgetstr(const char *id, char **area);
int32_t	ft_tputs(const char *str, int32_t affcnt, int32_t (*putc)(int32_t));

#endif // FT_TERMINFO_H
