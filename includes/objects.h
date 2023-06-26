/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noa <noa@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 20:55:29 by noa               #+#    #+#             */
/*   Updated: 2023/06/27 01:36:19 by noa              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECTS_H
# define OBJECTS_H

# include "vec3f.h"
# include "texture.h"
# include <math.h>
# include <stdbool.h>

typedef struct s_plane
{
	t_texture	texture;
	t_vec3f		normale;
	t_vec3f		point;
}	t_plane;

typedef struct s_sphere
{
	t_texture	texture;
	t_vec3f		center;
	double		radius;
}	t_sphere;

typedef struct s_cylinder
{
	t_texture	texture;
	t_vec3f		axis;
	t_vec3f		center;
	double		radius;
	double		height;
}	t_cylinder;

/* voir pour une structure impact {color, coords, normale + phong etc.} */

bool	intersects_plane(const t_vec3f ray_dir, const t_vec3f ray_origin,
			t_plane *plane, t_vec3f *impact);
bool	intersects_sphere(const t_vec3f ray_dir, const t_vec3f ray_origin,
			t_sphere *sphere, t_vec3f *impact);
bool	intersects_cylinder(const t_vec3f ray_dir, const t_vec3f ray_origin,
			t_cylinder *cynlinder, t_vec3f *impact);

#endif
