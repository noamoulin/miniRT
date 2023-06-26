/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noa <noa@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 03:48:00 by noa               #+#    #+#             */
/*   Updated: 2023/06/26 06:27:21 by noa              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include "unistd.h"

bool	init_render(t_render *render, const uint32_t width,
			const uint32_t height, char *title)
{
	render->height = height;
	render->width = width;
	render->mlx = mlx_init();
	if (!render->mlx)
		return (false);
	render->win = mlx_new_window(render->mlx, height, width, title);
	if (!render->win)
		return (mlx_destroy_display(render->mlx), free(render->mlx), false);
	render->image.img = mlx_new_image(render->mlx, width, height);
	if (!render->image.img)
		return (mlx_destroy_window(render->mlx, render->win),
			mlx_destroy_display(render->mlx), free(render->mlx), false);
	render->image.data = mlx_get_data_addr(render->image.img,
			&render->image.pixels_bits, &render->image.line_bytes,
			&render->image.endian);
	if (!render->image.data)
		return (destroy_render(render), free(render->mlx), false);
	return (true);
}

void	destroy_render(const t_render *render)
{
	mlx_destroy_image(render->mlx, render->image.img);
	mlx_destroy_window(render->mlx, render->win);
	mlx_destroy_display(render->mlx);
	free(render->mlx);
}

void	set_mlx_image_pixel(t_image *image, const uint32_t x, const uint32_t y,
			const uint32_t color)
{
	char	*dst;

	dst = image->data + (y * image->line_bytes + x * (image->pixels_bits / 8));
	*(uint32_t *)dst = color;
}

uint32_t	rgb_to_color(uint32_t r, uint32_t g, uint32_t b)
{
	return (r << 16 | g << 8 | b);
}

void	clear_image(t_render *render, uint32_t color)
{
	uint32_t	j;
	uint32_t	i;

	j = 0;
	while (j < render->height)
	{
		i = 0;
		while (i < render->width)
		{
			set_mlx_image_pixel(&render->image, i, j, color);
			i++;
		}
		j++;
	}
}
