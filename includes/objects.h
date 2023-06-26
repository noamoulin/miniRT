/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noa <noa@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 20:55:29 by noa               #+#    #+#             */
/*   Updated: 2023/06/26 18:05:38 by noa              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECTS_H
# define OBJECTS_H

# include "vec3f.h"
# include "texture.h"

typedef struct s_plane
{
	t_texture	texture;
	t_vec3f		normal;
	t_vec3f		point;
}	t_plane;

typedef struct s_sphere
{
	t_texture	texture;
	t_vec3f		center;
	double		radius;
}	t_sphere;

typedef struct s_cylinder
{
	t_texture	texture;
	t_vec3f		axis;
	t_vec3f		center;
	double		radius;
	double		height;
}	t_cylinder;

#endif
