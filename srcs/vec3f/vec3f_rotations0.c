/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3f_rotations0.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noa <noa@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 17:16:28 by noa               #+#    #+#             */
/*   Updated: 2023/06/26 20:41:49 by noa              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec3f.h"

void	rotate_x(t_vec3f *u, const double alpha)
{
	double	cos_alpha;
	double	sin_alpha;

	cos_alpha = cos(alpha);
	sin_alpha = sin(alpha);
	u->y = u->y * cos_alpha - u->z * sin_alpha;
	u->z = u->y * sin_alpha + u->z * cos_alpha;
}

void	rotate_y(t_vec3f *u, const double beta)
{
	double	cos_beta;
	double	sin_beta;

	cos_beta = cos(beta);
	sin_beta = sin(beta);
	u->x = u->x * cos_beta + u->z * sin_beta;
	u->z = -u->x * sin_beta + u->z * cos_beta;
}

void	rotate_z(t_vec3f *u, const double gamma)
{
	double	cos_gamma;
	double	sin_gamma;

	cos_gamma = cos(gamma);
	sin_gamma = sin(gamma);
	u->x = u->x * cos_gamma - u->y * sin_gamma;
	u->y = u->x * sin_gamma + u->y * cos_gamma;
}
