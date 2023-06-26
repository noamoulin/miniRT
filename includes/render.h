/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noa <noa@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 22:13:54 by noa               #+#    #+#             */
/*   Updated: 2023/06/26 17:58:04 by noa              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include "mlx.h"
# include <stdbool.h>
# include <stdint.h>
# include <stdlib.h>

typedef struct s_image
{
	char	*data;
	void	*img;
	int		pixels_bits;
	int		line_bytes;
	int		endian;
}	t_image;

typedef struct s_render
{
	uint32_t	width;
	uint32_t	height;
	t_image		image;
	void		*mlx;
	void		*win;
	char		*title;
}	t_render;

uint32_t	rgb_to_color(uint32_t r, uint32_t g, uint32_t b);
bool		init_render(t_render *render, const uint32_t width,
				const uint32_t height, char *title);
void		destroy_render(const t_render *render);
void		set_mlx_image_pixel(t_image *image, const uint32_t x,
				const uint32_t y, const uint32_t color);
void		clear_image(t_render *render, uint32_t color);

#endif
