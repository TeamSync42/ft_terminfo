/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_terminfo_internal.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 11:54:31 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/09/19 16:51:22 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TERMINFO_INTERNAL_H
# define FT_TERMINFO_INTERNAL_H

# include <stddef.h>
# include "terminfo_types.h"

t_terminfo_session	*ft_terminfo_init(void);
void				ft_terminfo_destroy(t_terminfo_session *session);
void				ft_terminfo_destroy_entry(t_terminfo_entry *entry);

t_terminfo_entry	*ft_get_terminfo_entry(t_terminfo_session *session,
						const char *term_name);
int32_t				ft_cache_add(t_terminfo_session *session,
						const char *term_name, t_terminfo_entry *entry);

int32_t				hash_termname(const char *s, size_t size);

t_terminfo_entry	*ft_load_terminfo_from_file(const char *term_name);
t_terminfo_entry	*ft_parse_terminfo(void *file_buffer);
int32_t				get_bool_capacity_by_name(const char *id);

#endif // FT_TERMINFO_INTERNAL_H
