/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noa <noa@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 18:58:17 by noa               #+#    #+#             */
/*   Updated: 2023/06/26 20:37:49 by noa              ###   ########.fr       */
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
	camera->rays_dirs = malloc(sizeof(t_vec3f) * width * height);
	if (!camera->rays_dirs)
		return (false);
	camera->look_at = vec3f(0, 0, 1);
	camera->right = vec3f(1, 0, 0);
	camera->up = vec3f(0, -1, 0);
	camera->position = vec3f(0, 0, 0);
	return (true);
}

void	set_camera_image(t_camera *camera, t_image *image)
{
	camera->image = image;
}

/* autre possibilité : initialiser tous les vecteurs a 
lookat * h et les combiner avec up et right (pas besoin 
de copie (faire des essais en passant tout par pointeurs aussi))

si ça ne fonctionne pas faire une fonction plus sure et moins efficace
pour les tests*/

void	update_rays_dirs(t_camera *camera)
{
	uint32_t	n;
	uint32_t	inc;
	t_vec3f		z;
	double		x;
	double		y;

	z = multiplied_vec3f(camera->look_at, camera->h);
	n = 0;
	x = -1;
	y = camera->image_ratio;
	while (n < camera->pixels_number)
	{
		camera->rays_dirs[n] = vec3f_sum(z,
				vec3f_sum(multiplied_vec3f(camera->right, x),
					multiplied_vec3f(camera->up, y)));
		inc = (camera->pixels_number % n == 0);
		x += 1 / camera->image_width;
		x *= inc;
		y += (inc * camera->image_ratio) / camera->image_height;
		++n;
	}
}

void	immerge_camera(t_camera *camera, t_scene *scene,
			const t_vec3f position, const t_vec3f orientation)
{
	camera->scene = scene;
	camera->position = position;
	camera->look_at = orientation;
	camera->right = cross_product(orientation, vec3f(0, 0, 1));
	camera->up = cross_product(camera->right, camera->look_at);
	update_rays_dirs(camera);
}

void	translate_camera(t_camera *camera, const t_vec3f translation)
{
	add_vec3f(&camera->position, translation);
}
