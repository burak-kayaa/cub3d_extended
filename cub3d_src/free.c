/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: burkaya <burkaya@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 17:23:49 by burkaya           #+#    #+#             */
/*   Updated: 2024/05/27 18:28:32 by burkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	ft_free_map(t_map *map)
{
	if (map->floor)
		ft_free_array(map->floor);
	if (map->ceiling)
		ft_free_array(map->ceiling);
	if (map->map)
		ft_free_array(map->map);
	if (map->flood_fill)
		ft_free_array(map->flood_fill);
	if (map->wall_textures)
		free(map->wall_textures);
	if (map->ceiling_str)
		free(map->ceiling_str);
	if (map->floor_str)
		free(map->floor_str);
	if (map->map_str)
		free(map->map_str);
	free(map);
}

void	ft_free_data(t_data *data)
{
	int	i;

	i = 1;
	if (data->map)
		ft_free_map(data->map);
	if (data->ray)
		free(data->ray);
	if (data->images)
	{
		while (data->images[i])
		{
			if (data->images[i]->img)
				mlx_destroy_image(data->mlx_ptr, data->images[i]->img);
			free(data->images[i]);
			i++;
		}
		free(data->images[0]);
		free(data->images);
	}
	if (data->win_ptr)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	free(data);
}

void	ft_error(char *str, t_data *data)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(str, 2);
	ft_putchar_fd('\n', 2);
	if (data)
		ft_free_data(data);
	exit(0);
}