# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mde-clee <mde-clee@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/15 10:54:31 by llapage           #+#    #+#              #
#    Updated: 2024/01/29 14:18:36 by mde-clee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= miniRT

#-------------------SOURCES PATH----------------------
SOURCES     = src/
HEADER_PWD  = ./includes/
LIBFT_PWD   = ./dep/libft/

#-------------------COMPILATION-----------------------
MACOS_CC	= cc
LINUX_CC	= clang

FLAGS	= -Wall -Werror -Wextra -O3
#FLAGS	= -Wall -Werror -Wextra -O3 -g
#FLAGS	= -Wall -Werror -Wextra -O3 -g -fsanitize=thread

MACOS_LINKER_FLAGS = -lmlx -framework OpenGL -framework AppKit
LINUX_LINKER_FLAGS = -lm -lbsd -lmlx -lXext -lX11

#-------------------SOURCES FILES----------------------
HEADERS     =   $(HEADER_PWD)miniRT.h

H_LIB       =   $(LIBFT_PWD)libft.h

SRCS        =	$(SOURCES)arprar/bn_add.c \
				$(SOURCES)arprar/bn_div.c \
				$(SOURCES)arprar/bn_mult.c \
				$(SOURCES)arprar/bn_new.c \
				$(SOURCES)arprar/bn_subt.c \
				$(SOURCES)arprar/bn_utils_1.c \
				$(SOURCES)arprar/bn_utils_2.c \
				$(SOURCES)arprar/bn_utils_3.c \
				$(SOURCES)arprar/bn_utils_4.c \
				$(SOURCES)color/color_1.c \
				$(SOURCES)color/color_2.c \
				$(SOURCES)color/color_3.c \
				$(SOURCES)color/color_4.c \
				$(SOURCES)controls/arrow_up.c \
				$(SOURCES)controls/arrow_down.c \
				$(SOURCES)controls/arrow_left.c \
				$(SOURCES)controls/arrow_right.c \
				$(SOURCES)controls/drop_object.c \
				$(SOURCES)controls/hooks.c \
				$(SOURCES)controls/press_key.c \
				$(SOURCES)controls/press_button.c \
				$(SOURCES)controls/move_mouse.c \
				$(SOURCES)controls/release_button.c \
				$(SOURCES)controls/escape.c \
				$(SOURCES)controls/enter.c \
				$(SOURCES)controls/tab.c \
				$(SOURCES)controls/left_click.c \
				$(SOURCES)controls/left_release.c \
				$(SOURCES)controls/mouse_move_display_info.c \
				$(SOURCES)controls/right_release.c \
				$(SOURCES)controls/scroll.c \
				$(SOURCES)controls/select_object.c \
				$(SOURCES)controls/set_move_strings.c \
				$(SOURCES)controls/show_move_strings.c \
				$(SOURCES)controls/unselect_object.c \
				$(SOURCES)controls/bool.c \
				$(SOURCES)core/execution.c \
				$(SOURCES)core/launch.c \
				$(SOURCES)core/loop.c \
				$(SOURCES)core/main.c \
				$(SOURCES)graphics/get.c \
				$(SOURCES)graphics/load.c \
				$(SOURCES)graphics/load_icons.c \
				$(SOURCES)graphics/load_menu_items.c \
				$(SOURCES)graphics/load_normal_maps.c \
				$(SOURCES)graphics/load_textures.c \
				$(SOURCES)graphics/new.c \
				$(SOURCES)graphics/parse.c \
				$(SOURCES)graphics/put_graphic.c \
				$(SOURCES)graphics/set.c \
				$(SOURCES)gui/gui.c \
				$(SOURCES)gui/gui_image.c \
				$(SOURCES)history/bool.c \
				$(SOURCES)history/pop.c \
				$(SOURCES)history/push.c \
				$(SOURCES)history/restore.c \
				$(SOURCES)history/revert.c \
				$(SOURCES)history/save.c \
				$(SOURCES)history/set.c \
				$(SOURCES)history/undo.c \
				$(SOURCES)image/bool.c \
				$(SOURCES)image/get.c \
				$(SOURCES)image/set_1.c \
				$(SOURCES)image/set_2.c \
				$(SOURCES)input/input.c \
				$(SOURCES)input/update_float.c \
				$(SOURCES)input/update_storage.c \
				$(SOURCES)input/cancel.c \
				$(SOURCES)input/confirm.c \
				$(SOURCES)input/init.c \
				$(SOURCES)input/link.c \
				$(SOURCES)input/strings.c \
				$(SOURCES)input/key_to_char.c \
				$(SOURCES)intersect/cone.c \
				$(SOURCES)intersect/cyl.c \
				$(SOURCES)intersect/cyl_calculation_1.c \
				$(SOURCES)intersect/cyl_calculation_2.c \
				$(SOURCES)intersect/cone_calculation.c \
				$(SOURCES)intersect/intersect.c \
				$(SOURCES)intersect/plane.c \
				$(SOURCES)intersect/sphere.c \
				$(SOURCES)intersect/bool.c \
				$(SOURCES)intersect/get_1.c \
				$(SOURCES)intersect/get_2.c \
				$(SOURCES)intersect/set.c \
				$(SOURCES)memory/memory_error.c \
				$(SOURCES)memory/memory_free_1.c \
				$(SOURCES)memory/memory_free_2.c \
				$(SOURCES)memory/memory_free_3.c \
				$(SOURCES)memory/memory_init.c \
				$(SOURCES)memory/memory_init_2.c \
				$(SOURCES)navigation/export.c \
				$(SOURCES)navigation/focus.c \
				$(SOURCES)navigation/nav_utils_1.c \
				$(SOURCES)navigation/nav_utils_2.c \
				$(SOURCES)navigation/press.c \
				$(SOURCES)navigation/put_color_label.c \
				$(SOURCES)navigation/put_color_label_get_addr.c \
				$(SOURCES)navigation/put_color_labels.c \
				$(SOURCES)navigation/reset_widgets.c \
				$(SOURCES)navigation/scroll.c \
				$(SOURCES)navigation/scroll_enum.c \
				$(SOURCES)navigation/scroll_fill.c \
				$(SOURCES)navigation/scroll_surface.c \
				$(SOURCES)navigation/select.c \
				$(SOURCES)navigation/select_undo.c \
				$(SOURCES)navigation/select_render.c \
				$(SOURCES)navigation/set_1.c \
				$(SOURCES)navigation/set_2.c \
				$(SOURCES)navigation/show_sub_menu.c \
				$(SOURCES)navigation/shut_down.c \
				$(SOURCES)navigation/start_input.c \
				$(SOURCES)navigation/widget_loop.c \
				$(SOURCES)navigation/switch_reflections.c \
				$(SOURCES)navigation/switch_anti_aliasing.c \
				$(SOURCES)nav_widget/bool_1.c \
				$(SOURCES)nav_widget/bool_2.c \
				$(SOURCES)nav_widget/bool_3.c \
				$(SOURCES)nav_widget/bool_4.c \
				$(SOURCES)nav_widget/bool_5.c \
				$(SOURCES)nav_widget/get.c \
				$(SOURCES)nav_widget/move_item_adjacent.c \
				$(SOURCES)nav_widget/move_items.c \
				$(SOURCES)nav_widget/nav_under_pointer.c \
				$(SOURCES)nav_widget/scroll_pane.c \
				$(SOURCES)nav_widget/scroll_pane_down.c \
				$(SOURCES)nav_widget/scroll_pane_up.c \
				$(SOURCES)nav_widget/set_1.c \
				$(SOURCES)nav_widget/set_2.c \
				$(SOURCES)nav_widget/set_3.c \
				$(SOURCES)nav_widget/set_4.c \
				$(SOURCES)nav_widget/set_5.c \
				$(SOURCES)nav_widget/set_6.c \
				$(SOURCES)nav_widget/set_graphics.c \
				$(SOURCES)nav_widget/set_position.c \
				$(SOURCES)nav_widget/setup/a_light.c \
				$(SOURCES)nav_widget/setup/camera.c \
				$(SOURCES)nav_widget/setup/cone.c \
				$(SOURCES)nav_widget/setup/cyl.c \
				$(SOURCES)nav_widget/setup/d_light.c \
				$(SOURCES)nav_widget/setup/functions.c \
				$(SOURCES)nav_widget/setup/graphs.c \
				$(SOURCES)nav_widget/setup/lights.c \
				$(SOURCES)nav_widget/setup/objects.c \
				$(SOURCES)nav_widget/setup/plane.c \
				$(SOURCES)nav_widget/setup/positions_1.c \
				$(SOURCES)nav_widget/setup/positions_2.c \
				$(SOURCES)nav_widget/setup/setup.c \
				$(SOURCES)nav_widget/setup/settings.c \
				$(SOURCES)nav_widget/setup/s_light.c \
				$(SOURCES)nav_widget/setup/sphere.c \
				$(SOURCES)nav_widget/setup/utils.c \
				$(SOURCES)nav_widget/set_visibility_1.c \
				$(SOURCES)nav_widget/set_visibility_2.c \
				$(SOURCES)nav_widget/set_visibility_3.c \
				$(SOURCES)nav_widget/set_visibility_4.c \
				$(SOURCES)nav_widget/set_visibility_5.c \
				$(SOURCES)parsing/parsing.c \
				$(SOURCES)parsing/cam.c \
				$(SOURCES)parsing/cone.c \
				$(SOURCES)parsing/cyl.c \
				$(SOURCES)parsing/light.c \
				$(SOURCES)parsing/plane.c \
				$(SOURCES)parsing/print_1.c \
				$(SOURCES)parsing/print_2.c \
				$(SOURCES)parsing/read.c \
				$(SOURCES)parsing/sphere.c \
				$(SOURCES)parsing/bool_1.c \
				$(SOURCES)parsing/bool_2.c \
				$(SOURCES)rendering/bool_1.c \
				$(SOURCES)rendering/bool_2.c \
				$(SOURCES)rendering/bool_3.c \
				$(SOURCES)rendering/bool_4.c \
				$(SOURCES)rendering/color_and_light.c \
				$(SOURCES)rendering/detail_trace.c \
				$(SOURCES)rendering/standard_trace.c \
				$(SOURCES)rendering/fill_hit_subsample_gaps.c \
				$(SOURCES)rendering/get_1.c \
				$(SOURCES)rendering/get_2.c \
				$(SOURCES)rendering/get_3.c \
				$(SOURCES)rendering/hit_normal.c \
				$(SOURCES)rendering/lights_intensity.c \
				$(SOURCES)rendering/modes.c \
				$(SOURCES)rendering/probe.c \
				$(SOURCES)rendering/put_color.c \
				$(SOURCES)rendering/put_color_main_image.c \
				$(SOURCES)rendering/put_color_object_images.c \
				$(SOURCES)rendering/reflection.c \
				$(SOURCES)rendering/render.c \
				$(SOURCES)rendering/render_utils.c \
				$(SOURCES)rendering/set_1.c \
				$(SOURCES)rendering/set_2.c \
				$(SOURCES)rendering/set_3.c \
				$(SOURCES)rendering/set_4.c \
				$(SOURCES)rendering/set_5.c \
				$(SOURCES)rendering/set_6.c \
				$(SOURCES)rendering/set_7.c \
				$(SOURCES)rendering/simple_trace.c \
				$(SOURCES)rendering/smooth_intersection_normal.c \
				$(SOURCES)rendering/splash.c \
				$(SOURCES)rendering/surface_color.c \
				$(SOURCES)rendering/surface_map.c \
				$(SOURCES)rendering/trace_and_put_pixel.c \
				$(SOURCES)rendering/trace.c \
				$(SOURCES)scene/set_cam_vars.c \
				$(SOURCES)scene/set_vars.c \
				$(SOURCES)scene/set_1.c \
				$(SOURCES)scene/set_2.c \
				$(SOURCES)scene/set_3.c \
				$(SOURCES)scene/set_4.c \
				$(SOURCES)scene/set_5.c \
				$(SOURCES)t_data/bool_1.c \
				$(SOURCES)t_data/bool_2.c \
				$(SOURCES)t_data/bool_3.c \
				$(SOURCES)t_data/bool_4.c \
				$(SOURCES)t_data/get_1.c \
				$(SOURCES)t_data/get_2.c \
				$(SOURCES)t_data/set_1.c \
				$(SOURCES)t_data/set_2.c \
				$(SOURCES)t_data/set_3.c \
				$(SOURCES)t_data/set_4.c \
				$(SOURCES)t_data/set_5.c \
				$(SOURCES)t_data/set_6.c \
				$(SOURCES)t_data/set_7.c \
				$(SOURCES)t_data/set_8.c \
				$(SOURCES)tiff/fields.c \
				$(SOURCES)tiff/file.c \
				$(SOURCES)tiff/get.c \
				$(SOURCES)tiff/new.c \
				$(SOURCES)tiff/out.c \
				$(SOURCES)tiff/params.c \
				$(SOURCES)tiff/tiff.c \
				$(SOURCES)tiff/to_hex.c \
				$(SOURCES)transform/matrices.c \
				$(SOURCES)transform/transform.c \
				$(SOURCES)transform/transform_camera_2.c \
				$(SOURCES)transform/transform_camera.c \
				$(SOURCES)transform/transform_rotate.c \
				$(SOURCES)transform/transform_scale.c \
				$(SOURCES)transform/transform_translation.c \
				$(SOURCES)transform/rotate_camera.c \
				$(SOURCES)transform/pan.c \
				$(SOURCES)transform/tilt.c \
				$(SOURCES)utils/ft_ftoa.c \
				$(SOURCES)vector/vector_arithmetic.c \
				$(SOURCES)vector/vector_ops_1.c \
				$(SOURCES)vector/vector_ops_2.c \
				$(SOURCES)vector/vector_ops_3.c \
				$(SOURCES)vector/vector_ops_4.c \
				$(SOURCES)vector/vector_ops_5.c \
				$(SOURCES)vector/vector_print.c \
				$(SOURCES)viewport/calculations_1.c \
				$(SOURCES)viewport/calculations_2.c \
				$(SOURCES)viewport/get.c \
				$(SOURCES)viewport/init.c \
				$(SOURCES)viewport/set.c \

SRC_LIBFT	=	$(LIBFT_PWD)free_s_arr.c \
				$(LIBFT_PWD)ft_atof.c \
				$(LIBFT_PWD)ft_atoi.c \
				$(LIBFT_PWD)ft_atoll.c \
				$(LIBFT_PWD)ft_bzero.c \
				$(LIBFT_PWD)ft_isdigit.c \
				$(LIBFT_PWD)ft_itoa.c \
				$(LIBFT_PWD)ft_lstadd_front.c \
				$(LIBFT_PWD)ft_lstclear.c \
				$(LIBFT_PWD)ft_lstnew.c \
				$(LIBFT_PWD)ft_max.c \
				$(LIBFT_PWD)ft_memcpy.c \
				$(LIBFT_PWD)ft_memrcpy.c \
				$(LIBFT_PWD)ft_min.c \
				$(LIBFT_PWD)ft_pow.c \
				$(LIBFT_PWD)ft_strdupchr.c \
				$(LIBFT_PWD)ft_pstrdup.c \
				$(LIBFT_PWD)ft_putnbr_base_fd.c \
				$(LIBFT_PWD)ft_split.c \
				$(LIBFT_PWD)ft_strcchr.c \
				$(LIBFT_PWD)ft_strchr.c \
				$(LIBFT_PWD)ft_strcmp.c \
				$(LIBFT_PWD)ft_strcncpy.c \
				$(LIBFT_PWD)ft_strdup.c \
				$(LIBFT_PWD)ft_strfjoin.c \
				$(LIBFT_PWD)ft_strjoin.c \
				$(LIBFT_PWD)ft_strlen.c \
				$(LIBFT_PWD)ft_strracat.c \
				$(LIBFT_PWD)ft_strstrlen.c \
				$(LIBFT_PWD)get_next_line.c \
				$(LIBFT_PWD)rd_float.c

#-------------------OBJECTS----------------------
OBJS        =   $(SRCS:.c=.o)
LIBFT_OBJ	=	$(SRC_LIBFT:.c=.o)

#-------------------HEADERS----------------------
I_HEADER    =   $(addprefix( -include, $(HEADERS)))
I_H_LIB     =   $(addprefix( -include, $(H_LIB)))

#-------------------COLORS-----------------------
RED         =   \x1b[31m
YELLOW      =   \x1b[33m
GREEN       =   \x1b[32m
NO_COLOR    =   \x1b[0m
BOLD        =   \x1b[1m
BOLD_OFF    =   \x1b[21m

#-------------------RULES-----------------------
%.o: %.c
			@$(ECHO)
			@$(CC) $(FLAGS) -Iincludes $(I_H_LIB) -c $< -o $@

$(NAME):    $(LIBFT_OBJ) $(OBJS)
			@$(ECHO)
			@$(MAKE) -sC ./dep/libft/
			@$(MACOS_CC) $(FLAGS) $(OBJS) $(LIBFT_OBJ) -o $(NAME) $(MACOS_LINKER_FLAGS)
			@echo "Success!"

linux:    $(LIBFT_OBJ) $(OBJS)
			@$(ECHO)
			@$(MAKE) -sC ./dep/libft/
			@$(LINUX_CC) $(FLAGS) $(OBJS) $(LIBFT_OBJ) -o $(NAME) $(LINUX_LINKER_FLAGS)
			@echo "~~~~~~~~~~~~~~~~"
			@echo "Compilation done"
			@echo "~~~~~~~~~~~~~~~~"

bonus:	$(NAME)

all:	$(NAME)

clean:
		@rm -rf $(OBJS)
		@make clean -sC ./dep/libft/
		@echo "cleaning $(NAME).. done"

fclean:	clean
		@make fclean -sC ./dep/libft/
		@rm -f $(NAME)
		@echo -ne "\rfcleaning $(NAME).. done"
re:	fclean all

.PHONY: all clean fclean bonus re
