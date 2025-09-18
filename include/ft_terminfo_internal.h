/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_terminfo_internal.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 11:54:31 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/09/18 12:25:38 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TERMINFO_INTERNAL_H
# define FT_TERMINFO_INTERNAL_H

# include <stddef.h>
# include <stdint.h>

# define MAX_BOOLS_CAPS	512
# define MAX_NUMS_CAPS	512
# define MAX_STRS_CAPS	512

# define CAP_CUP_IDX	12
# define CAP_CLEAR_IDX	14

# define CACHE_SIZE		1024

typedef struct s_terminfo_entry {
	uint8_t	bools[(MAX_BOOLS_CAPS + 7) / 8];
	int16_t	nums[MAX_NUMS_CAPS];
	int16_t	str_offsets[MAX_STRS_CAPS];
	char	*str_pool;
}	t_terminfo_entry;

typedef struct s_terminfo_session {
	t_terminfo_entry	*current_terminfo;
	t_terminfo_entry	*cache[CACHE_SIZE];
}	t_terminfo_session;

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

#endif // FT_TERMINFO_INTERNAL_H
