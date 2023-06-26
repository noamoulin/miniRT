/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noa <noa@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 03:47:55 by noa               #+#    #+#             */
/*   Updated: 2023/06/26 06:29:05 by noa              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "render.h"

int	main(void)
{
	t_render	render;

	if (!init_render(&render, 1000, 1000, "RTest"))
		return (-1);
	clear_image(&render, 0xFFFFFF);
	mlx_put_image_to_window(render.mlx, render.win, render.image.img, 0, 0);
	mlx_loop(render.mlx);
	destroy_render(&render);
	return (0);
}
