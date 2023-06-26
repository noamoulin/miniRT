/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3f_rotations1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noa <noa@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 17:18:13 by noa               #+#    #+#             */
/*   Updated: 2023/06/26 20:41:55 by noa              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec3f.h"

t_vec3f	rotated_x(const t_vec3f u, const double alpha)
{
	t_vec3f	result;
	double	cos_angle;
	double	sin_angle;

	cos_angle = cos(alpha);
	sin_angle = sin(alpha);
	result.x = u.x;
	result.y = u.y * cos_angle - u.z * sin_angle;
	result.z = u.y * sin_angle + u.z * cos_angle;
	return (result);
}

t_vec3f	rotated_y(const t_vec3f u, const double beta)
{
	t_vec3f	result;
	double	cos_angle;
	double	sin_angle;

	cos_angle = cos(beta);
	sin_angle = sin(beta);
	result.x = u.x * cos_angle + u.z * sin_angle;
	result.y = u.y;
	result.z = -u.x * sin_angle + u.z * cos_angle;
	return (result);
}

t_vec3f	rotated_z(const t_vec3f u, const double gamma)
{
	t_vec3f	result;
	double	cos_angle;
	double	sin_angle;

	cos_angle = cos(gamma);
	sin_angle = sin(gamma);
	result.x = u.x * cos_angle - u.y * sin_angle;
	result.y = u.x * sin_angle + u.y * cos_angle;
	result.z = u.z;
	return (result);
}
