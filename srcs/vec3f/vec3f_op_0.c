/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3f_op_0.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noa <noa@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 15:59:57 by noa               #+#    #+#             */
/*   Updated: 2023/06/26 17:55:39 by noa              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec3f.h"

t_vec3f	vec3f(const double x, const double y, const double z)
{
	t_vec3f	vec;

	vec.x = x;
	vec.y = y;
	vec.z = z;
	return (vec);
}

t_vec3f	vec3f_sum(const t_vec3f u, const t_vec3f v)
{
	return (vec3f(u.x + v.x, u.y + v.y, u.z + v.z));
}

t_vec3f	vec3f_difference(const t_vec3f u, const t_vec3f v)
{
	return (vec3f(u.x - v.x, u.y - v.y, u.z - v.z));
}

t_vec3f	linear_combination(const t_vec3f u, const t_vec3f v,
			const double alpha, const double beta)
{
	return (vec3f(alpha * u.x + beta * v.x, alpha * u.y + beta
			* v.y, alpha * u.z + beta * v.z));
}

t_vec3f	multiplied_vec3f(const t_vec3f u, const double x)
{
	return (vec3f(u.x * x, u.y * x, u.z * x));
}
