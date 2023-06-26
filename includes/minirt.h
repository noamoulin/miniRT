/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noa <noa@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 22:27:41 by noa               #+#    #+#             */
/*   Updated: 2023/06/26 18:05:18 by noa              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "scene.h"
# include "camera.h"
# include "render.h"
# include <stdbool.h>
# include <stdint.h>

typedef struct s_minirt
{
	t_camera	camera;
	t_render	render;
	t_scene		scene;
}	t_minirt;

bool	init_minirt(t_minirt *minirt, uint32_t width, uint32_t height,
			const char *scene_file);

#endif
