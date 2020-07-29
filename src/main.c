/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wanton <wanton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 15:28:41 by wanton            #+#    #+#             */
/*   Updated: 2020/07/29 15:18:21 by wanton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/*
**Read first line and check symbol which we will play
**
** 'O' is default for init_functions()
*/

void	read_start(t_map *map, FILE *fp)
{
	char *line;

	get_next_line(0, &line);
	if ((ft_strstr(line, "p2")))
		map->player = 'X';
	write_trace(fp, line);
	free(line);
}

/*
**Read map size and set parameters n and m for t_map
 *
** m - rows
** n - columns
*/

void	read_map_size(t_map *map, FILE *fp)
{
	char	**buff;
	char	*line;
	char	*size1;
	char	*size2;

	get_next_line(0, &line);
	buff = ft_strsplit(line, ' ');
	size1 = ft_strdup(buff[1]);
	size2 = ft_strdup(buff[2]);
	map->m = ft_atoi(size1);
	map->n = ft_atoi(size2);
	
	// traces
	free_buff(buff);
	write_trace(fp, line);
	free(line);
	write_trace(fp, size1);
	free(size1);
	write_trace(fp, size2);
	free(size2);
}

int		main(void) 
{
	FILE	*fp;
	char	*str;
	t_map	*map;

	if (!(map = init_map()))
		return (0);
	fp = open_file();
	str = ft_strdup("Player number:");
	write_trace(fp, str);
	free(str);
	read_start(map, fp);
	
	str = ft_strdup("Map size:");
	write_trace(fp, str);
	free(str);
	read_map_size(map, fp);
	
	read_map(map, fp);
	
	close_file(fp);
	ft_putstr("1 1\n");
	ft_putstr("1 1\n");
	return (0);
}

