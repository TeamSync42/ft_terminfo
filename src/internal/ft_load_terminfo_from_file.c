/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_terminfo_from_file.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 17:28:05 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/09/18 19:47:29 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>

#include "ft_terminfo_internal.h"
#include "io/ft_io.h"
#include "io/ft_printf.h"

#define FT_TERMINFO_PATHSIZE 1024

static void	*alloc_and_read(t_ft_file *fp, const struct stat *st, size_t *size)
{
	void	*buffer;

	buffer = malloc((size_t)st->st_size);
	if (buffer == NULL)
		return (NULL);
	if (ft_fread(buffer, 1, (size_t)st->st_size, fp) != (size_t)st->st_size)
	{
		free(buffer);
		return (NULL);
	}
	*size = (size_t)st->st_size;
	return (buffer);
}

static void	*load_file_to_buffer(const char *filepath, size_t *size)
{
	t_ft_file	*fp;
	struct stat	st;
	void		*buffer;

	fp = ft_fopen(filepath, "rb");
	if (fp == NULL)
		return (NULL);
	if (stat(filepath, &st) != 0)
	{
		ft_fclose(fp);
		return (NULL);
	}
	buffer = alloc_and_read(fp, &st, size);
	ft_fclose(fp);
	return (buffer);
}

t_terminfo_entry	*ft_load_terminfo_from_file(const char *term_name)
{
	char				filepath[FT_TERMINFO_PATHSIZE];
	size_t				size;
	void				*buffer;
	t_terminfo_entry	*entry;

	if (!term_name)
		return (NULL);
	ft_snprintf(filepath, sizeof(filepath),
		"/usr/share/terminfo/%c/%s", term_name[0], term_name);
	buffer = load_file_to_buffer(filepath, &size);
	if (!buffer)
		return (NULL);
	entry = ft_parse_terminfo(buffer);
	free(buffer);
	return (entry);
}
