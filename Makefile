# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: noa <noa@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/26 18:30:35 by noa               #+#    #+#              #
#    Updated: 2023/06/27 01:33:05 by noa              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

######################## SOURCES ########################

SRCS_DIR = ./srcs
VEC3F_DIR = vec3f
CAMERA_DIR = camera
RENDER_DIR = render
OBJECTS_DIR = objects
SCENE_DIR = scene
UTILS_DIR = utils
MAIN_DIR = .

CAMERA_CFILES = camera camera1
VEC3F_CFILES = vec3f_op_0 vec3f_op_1 vec3f_rotations1 vec3f_rotations0 vec3f_space0 vec3f_space1
RENDER_CFILES = render
SCENE_CFILES = scene
OBJECTS_CFILES = intersections
UTILS_CFILES = get_next_line get_next_line_utils
MAIN_CFILES = main

CAMERA_SRCS = $(addprefix $(SRCS_DIR)/$(CAMERA_DIR)/, $(CAMERA_CFILES))
VEC3F_SRCS = $(addprefix $(SRCS_DIR)/$(VEC3F_DIR)/, $(VEC3F_CFILES))
RENDER_SRCS = $(addprefix $(SRCS_DIR)/$(RENDER_DIR)/, $(RENDER_CFILES))
MAIN_SRCS = $(addprefix $(SRCS_DIR)/$(MAIN_DIR)/, $(MAIN_CFILES))
UTILS_SRCS = $(addprefix $(SRCS_DIR)/$(UTILS_DIR)/, $(UTILS_CFILES))
SCENE_SRCS = $(addprefix $(SRCS_DIR)/$(SCENE_DIR)/, $(SCENE_CFILES))
OBJECTS_SRS = $(addprefix $(SRCS_DIR)/$(OBJECTS_DIR_DIR)/, $(OBJECTS_CFILES))
SRCS = $(CAMERA_SRCS) $(VEC3F_SRCS) $(RENDER_SRCS) $(MAIN_SRCS)

######################## SECRUOS ########################

######################## OBJETS ########################

OBJS = $(addsuffix .o, $(SRCS))

######################## STEJBO ########################

######################## COMPILATION ########################

CC = clang
CFLAGS = -Wall -Wextra -Werror -fsanitize=address

MLINKS = -L./libs/minilibx-linux -lmlx
LINKS = $(MLINKS) -lm -lXext -lX11

MLX_INC = ./libs/minilibx-linux/
SRCS_INC = ./includes/
INCS = -I$(SRCS_INC) -I$(MLX_INC)

BIN_DIR = .
BUILD_DIR = ./build

NAME = $(BIN_DIR)/miniRT

######################## NOITALIPMOC ########################

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LINKS)

%.o : %.c
	$(CC) -c $(CFLAGS) $(INCS) -c $< -o $@

all : $(NAME)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

clear : re
	@clear

run : clear
	@./$(NAME)