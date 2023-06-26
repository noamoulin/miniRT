/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3f_space1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noa <noa@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 20:19:30 by noa               #+#    #+#             */
/*   Updated: 2023/06/26 20:30:33 by noa              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "space.h"

t_vec3f	cross_product(const t_vec3f u, const t_vec3f v)
{
	t_vec3f	result;

	result.x = u.y * v.z - u.z * v.y;
	result.y = u.z * v.x - u.x * v.z;
	result.z = u.x * v.y - u.y * v.x;
	if (result.x == 0.0f && result.y == 0.0f && result.z == 0.0f)
	{
		result.x = u.y;
		result.y = -u.x;
		result.z = 0.0f;
	}
	return (result);
}
