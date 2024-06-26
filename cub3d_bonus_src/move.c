/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: burkaya <burkaya@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 16:57:12 by burkaya           #+#    #+#             */
/*   Updated: 2024/05/25 02:06:58 by burkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	key_left(t_data *data)
{
	double	old_dirx;
	double	old_planex;

	old_dirx = data->ray->dirx;
	data->ray->dirx = data->ray->dirx * cos(0.05) - data->ray->diry
		* sin(0.05);
	data->ray->diry = old_dirx * sin(0.05) + data->ray->diry
		* cos(0.05);
	old_planex = data->ray->planex;
	data->ray->planex = data->ray->planex * cos(0.05) - data->ray->planey
		* sin(0.05);
	data->ray->planey = old_planex * sin(0.05) + data->ray->planey
		* cos(0.05);
}

void	key_right(t_data *data)
{
	double	old_dirx;
	double	old_planex;

	old_dirx = data->ray->dirx;
	data->ray->dirx = data->ray->dirx * cos(-0.05) - data->ray->diry
		* sin(-0.05);
	data->ray->diry = old_dirx * sin(-0.05) + data->ray->diry
		* cos(-0.05);
	old_planex = data->ray->planex;
	data->ray->planex = data->ray->planex * cos(-0.05) - data->ray->planey
		* sin(-0.05);
	data->ray->planey = old_planex * sin(-0.05) + data->ray->planey
		* cos(-0.05);
}

void	ft_move(t_data *data)
{
	if (data->w_pressed)
		key_w(data);
	if (data->s_pressed)
		key_s(data);
	if (data->left_pressed || data->left_mouse_pressed)
		key_left(data);
	if (data->right_pressed || data->right_mouse_pressed)
		key_right(data);
	if (data->a_pressed)
		key_a(data);
	if (data->d_pressed)
		key_d(data);
}

int	ft_player_move(t_data *data)
{
	ft_move(data);
	mouse_hook(data);
	return (0);
}
