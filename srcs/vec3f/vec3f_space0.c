/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3f_space0.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noa <noa@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 16:24:05 by noa               #+#    #+#             */
/*   Updated: 2023/06/26 20:41:09 by noa              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec3f.h"

t_vec3f	two_points_vec3f(const t_vec3f a, const t_vec3f b)
{
	return (vec3f(b.x - a.x, b.y - a.y, b.z - a.z));
}

t_vec3f	normalized(const t_vec3f u)
{
	return (multiplied_vec3f(u, 1 / magnitude(u)));
}

double	magnitude(const t_vec3f u)
{
	return (sqrt(pow(u.x, 2) + pow(u.y, 2) + pow(u.z, 2)));
}

double	magnitude2(const t_vec3f u)
{
	return (pow(u.x, 2) + pow(u.y, 2) + pow(u.z, 2));
}

void	normalize(t_vec3f *u)
{
	multipy_vec3f(u, 1 / magnitude(*u));
}
