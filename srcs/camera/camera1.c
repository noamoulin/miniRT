/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noa <noa@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 20:45:25 by noa               #+#    #+#             */
/*   Updated: 2023/06/27 00:11:12 by noa              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"

/* mise a jour des rayons obligatoire ? pas sur.. et pourrait meme empieter 
sur les performances */

void	rotate_camera_z(t_camera *camera, const double gamma)
{
	rotate_z(&camera->look_at, gamma);
	rotate_z(&camera->up, gamma);
	rotate_z(&camera->right, gamma);
	update_rays_dirs(camera);
}

void	rotate_camera_y(t_camera *camera, const double beta)
{
	rotate_y(&camera->look_at, beta);
	rotate_y(&camera->up, beta);
	rotate_y(&camera->right, beta);
	update_rays_dirs(camera);
}

void	rotate_camera_x(t_camera *camera, const double alpha)
{
	rotate_x(&camera->look_at, alpha);
	rotate_x(&camera->up, alpha);
	rotate_x(&camera->right, alpha);
	update_rays_dirs(camera);
}
