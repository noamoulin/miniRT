/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noa <noa@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 18:58:17 by noa               #+#    #+#             */
/*   Updated: 2023/06/26 19:26:02 by noa              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"

bool	init_camera(t_camera *camera, const uint32_t width,
			const uint32_t height, const uint32_t horizontal_fov)
{
	camera->horizontal_fov = horizontal_fov;
	camera->image_width = width;
	camera->image_height = height;
	camera->pixels_number = width * height;
	camera->image_ratio = (double)width / (double)height;
	camera->h = 1 / tan(horizontal_fov / 2);
	camera->vertical_fov = 2 * atan(camera->image_ratio / camera->h);
	camera->rays_dir = malloc(sizeof(t_vec3f) * width * height);
	if (!camera->rays_dir)
		return (false);
	camera->look_at = vec3f(0, 0, 1);
	camera->right = vec3f(1, 0, 0);
	camera->up = vec3f(0, -1, 0);
	camera->position = vec3f(0, 0, 0);
	return (true);
}

void	set_camera_image(t_camera *camera, const t_image *image)
{
	camera->image = image;
}

void	update_ray_dir(t_camera *camera)
{
	uint32_t	rays_number;
	uint32_t	n;
	uint32_t	i;
	uint32_t	j;

	rays_number = camera->pixels_number;
	n = 0;
	i = 0;
	j = 0;
	while (n < rays_number)
	{
		
	}
}