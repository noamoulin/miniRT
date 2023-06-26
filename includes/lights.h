/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lights.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noa <noa@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 21:31:07 by noa               #+#    #+#             */
/*   Updated: 2023/06/25 21:55:35 by noa              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHTS_H
# define LIGHTS_H

# include <stdint.h>
# include "vec3f.h"

typedef struct s_ambient_light
{
	uint32_t	color;
	double		ratio;
}	t_ambient_light;

typedef struct s_light
{
	uint32_t	color;
	t_vec3f		position;
	double		ratio;
}	t_light;

#endif
