/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noa <noa@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 17:19:10 by noa               #+#    #+#             */
/*   Updated: 2023/06/26 20:44:26 by noa              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

# include "vec3f.h"
# include "scene.h"
# include <math.h>
# include <stdlib.h>
# include <stdint.h>
# include <stdbool.h>
# include "render.h"

typedef struct s_camera
{
	uint32_t	pixels_number;
	uint32_t	horizontal_fov;
	uint32_t	vertical_fov;
	uint32_t	image_width;
	uint32_t	image_height;
	t_image		*image;
	t_vec3f		*rays_dirs;
	t_vec3f		position;
	t_vec3f		look_at;
	t_vec3f		up;
	t_vec3f		right;
	t_scene		*scene;
	double		image_ratio;
	double		h;
}	t_camera;

bool	init_camera(t_camera *camera, const uint32_t width,
			const uint32_t height, const uint32_t horizontal_fov);
void	immerge_camera(t_camera *camera, t_scene *scene,
			const t_vec3f position, const t_vec3f orientation);
void	set_camera_image(t_camera *camera, t_image *image);
void	update_rays_dirs(t_camera *camera);
void	translate_camera(t_camera *camera, const t_vec3f translation);
void	rotate_camera_z(t_camera *camera, const double gamma);
void	rotate_camera_y(t_camera *camera, const double beta);
void	rotate_camera_x(t_camera *camera, const double alpha);
void	take_image(t_camera *camera);

#endif
