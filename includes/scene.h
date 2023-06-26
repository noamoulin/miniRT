/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noa <noa@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 17:47:46 by noa               #+#    #+#             */
/*   Updated: 2023/06/26 21:44:36 by noa              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include <stdint.h>
# include <stdbool.h>
# include <stdlib.h>
# include <fcntl.h>
# include "objects.h"
# include "get_next_line.h"

typedef struct s_scene
{
	t_cylinder	*cylinders;
	t_sphere	*spheres;
	t_plane		*planes;
	char		*scene_file;
}	t_scene;

bool	init_scene(t_scene *scene, char file);
void	destroy_scene(const t_scene *scene);
bool	get_objects_from_file(t_scene *scene);

#endif
