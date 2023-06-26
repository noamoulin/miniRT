/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noa <noa@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 17:47:46 by noa               #+#    #+#             */
/*   Updated: 2023/06/26 18:05:44 by noa              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include <stdint.h>
# include <stdbool.h>
# include "objects.h"

typedef struct s_scene
{
	t_cylinder	*cylinders;
	t_sphere	*spheres;
	t_plane		*planes;
	char		*scene_file;
}	t_scene;

bool	init_scene(const t_scene *scene);
void	destroy_scene(const t_scene *scene);

#endif
