/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3f_op_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noa <noa@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 17:55:43 by noa               #+#    #+#             */
/*   Updated: 2023/06/26 17:55:53 by noa              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec3f.h"

void	add_vec3f(t_vec3f *u, const t_vec3f v)
{
	u->x += v.x;
	u->y += v.y;
	u->z += v.z;
}

void	substract_vec3f(t_vec3f *u, const t_vec3f v)
{
	u->x -= v.x;
	u->y -= v.y;
	u->z -= v.z;
}

void	combine(t_vec3f *u, const t_vec3f v, const double alpha,
			const double beta)
{
	u->x = alpha * u->x + beta * v.x;
	u->y = alpha * u->y + beta * v.y;
	u->z = alpha * u->z + beta * v.z;
}

void	multipy_vec3f(t_vec3f *u, const double x)
{
	u->x *= x;
	u->y *= x;
	u->z *= x;
}
