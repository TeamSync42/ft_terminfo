/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminfo_types.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 18:57:26 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/09/20 00:46:52 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TERMINFO_TYPES_H
# define TERMINFO_TYPES_H

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

#endif // TERMINFO_TYPES_H
