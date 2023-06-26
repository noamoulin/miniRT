/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noa <noa@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 20:52:08 by noa               #+#    #+#             */
/*   Updated: 2023/06/27 01:26:06 by noa              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"

/* optimiser les calculs et les branchements conditionels */

bool	intersects_sphere(const t_vec3f ray_dir, const t_vec3f ray_origin,
			t_sphere *sphere, t_vec3f *impact)
{
	double	t[2];
	double	a;
	double	b;
	double	c;
	double	delta;

	a = pow(ray_dir.x, 2) + pow(ray_dir.y, 2) + pow(ray_dir.z, 2);
	b = 2 * (ray_dir.x * (ray_origin.x - sphere->center.x) + ray_dir.y
			* (ray_origin.y - sphere->center.y) + ray_dir.z
			* (ray_origin.z - sphere->center.z));
	c = pow(ray_origin.x + sphere->center.x, 2) + pow(ray_origin.y \
			+ sphere->center.y, 2) + pow(ray_origin.z + sphere->center.z, 2) \
				- pow(sphere->radius, 2);
	delta = pow(b, 2) - 4 * a * c;
	if (delta < 0)
		return (false);
	t[0] = (-b - sqrt(delta)) / (2 * a);
	t[1] = (-b + sqrt(delta)) / (2 * a);
	if (t[0] > 0)
		*impact = multiplied_vec3f(ray_dir, t[0]);
	else if (t[1] > 0)
		*impact = multiplied_vec3f(ray_dir, t[1]);
	else
		return (false);
	return (true);
}
