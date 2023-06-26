/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3f.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noa <noa@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 16:34:21 by noa               #+#    #+#             */
/*   Updated: 2023/06/26 18:05:52 by noa              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC3F_H
# define VEC3F_H

# include <math.h>

typedef struct s_vec3f
{
	double	x;
	double	y;
	double	z;
}	t_vec3f;

t_vec3f	vec3f(const double x, const double y, const double z);
t_vec3f	vec3f_sum(const t_vec3f u, const t_vec3f v);
t_vec3f	vec3f_difference(const t_vec3f u, const t_vec3f v); /* u - v */
t_vec3f	linear_combination(const t_vec3f u, const t_vec3f v,
			const double alpha, const double beta);
t_vec3f	multiplied_vec3f(const t_vec3f u, const double x);
void	add_vec3f(t_vec3f *u, const t_vec3f v);
void	substract_vec3f(t_vec3f *u, const t_vec3f v); /* u -= v */
void	combine(t_vec3f *u, const t_vec3f v, const double alpha,
			const double beta);
void	multipy_vec3f(t_vec3f *u, const double x);

#endif
