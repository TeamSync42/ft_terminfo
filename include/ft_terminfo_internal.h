/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_terminfo_internal.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 11:54:31 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/09/20 00:44:08 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TERMINFO_INTERNAL_H
# define FT_TERMINFO_INTERNAL_H

# include <stddef.h>
# include "terminfo_types.h"

typedef enum e_cap_type {
	CAP_TYPE_BOOL,
	CAP_TYPE_NUM,
	CAP_TYPE_STR
}	t_cap_type;

typedef struct s_cap_hash_entry {
	const char	*id;
	int32_t		index;
	int32_t		padding;
}	t_cap_hash_entry;

extern const t_cap_hash_entry	g_bool_caps_table[];
extern const t_cap_hash_entry	g_num_caps_table[];
extern const t_cap_hash_entry	g_str_caps_table[];
extern const int32_t			g_bool_caps_count;
extern const int32_t			g_num_caps_count;
extern const int32_t			g_str_caps_count;

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
int32_t				ft_find_capability_index(const char *id, int32_t type);

#endif // FT_TERMINFO_INTERNAL_H
