/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   space.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noa <noa@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 21:56:45 by noa               #+#    #+#             */
/*   Updated: 2023/06/26 18:05:22 by noa              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPACE_H
# define SPACE_H

# include "vec3f.h"
# include <math.h>

t_vec3f	two_points_vec3f(const t_vec3f a, const t_vec3f b);
t_vec3f	normalized(const t_vec3f u);
t_vec3f	rotated_x(const t_vec3f u, const double alpha);
t_vec3f	rotated_y(const t_vec3f u, const double beta);
t_vec3f	rotated_z(const t_vec3f u, const double gamma);
double	magnitude(const t_vec3f u);
double	magnitude2(const t_vec3f u);
void	rotate_x(t_vec3f *u, const double alpha);
void	rotate_y(t_vec3f *u, const double beta);
void	rotate_z(t_vec3f *u, const double gamma);
void	normalize(t_vec3f *u);

#endif
