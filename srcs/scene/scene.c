/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noa <noa@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 21:20:28 by noa               #+#    #+#             */
/*   Updated: 2023/06/27 00:09:44 by noa              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

bool	init_scene(t_scene *scene, char file)
{
	scene->scene_file = file;
}

void	destroy_scene(const t_scene *scene)
{
	free(scene->cylinders);
	free(scene->planes);
	free(scene->spheres);
}

bool	get_objects_from_file(t_scene *scene)
{
	int	file;

	file = open(scene->scene_file, O_RDONLY);
	if (file < 0)
		return (false);
}
