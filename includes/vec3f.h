/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3f.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noa <noa@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 16:34:21 by noa               #+#    #+#             */
/*   Updated: 2023/06/26 21:05:31 by noa              ###   ########.fr       */
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
t_vec3f	two_points_vec3f(const t_vec3f a, const t_vec3f b);
t_vec3f	normalized(const t_vec3f u);
t_vec3f	rotated_x(const t_vec3f u, const double alpha);
t_vec3f	rotated_y(const t_vec3f u, const double beta);
t_vec3f	rotated_z(const t_vec3f u, const double gamma);
t_vec3f	cross_product(const t_vec3f u, const t_vec3f v);
double	magnitude(const t_vec3f u);
double	magnitude2(const t_vec3f u);
double	dot_product(const t_vec3f u, const t_vec3f v);
void	rotate_x(t_vec3f *u, const double alpha);
void	rotate_y(t_vec3f *u, const double beta);
void	rotate_z(t_vec3f *u, const double gamma);
void	normalize(t_vec3f *u);

#endif
