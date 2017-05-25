/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oukrifa <oukrifa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 02:17:53 by oukrifa           #+#    #+#             */
/*   Updated: 2017/05/25 02:23:45 by oukrifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

typedef struct s_mlx
{
	void *mlx;
	void *win;
} t_mlx;

int my_key_funct(int keycode, void *param)
{
	printf("key event %d\n", keycode);
	//mlx_pixel_put((void *)param->mlx, (void *)param->mlx, 1 , 1, 0x00FF00FF);
	if (keycode == 53)
		exit(1);
	return (1);
}

int mouse_hook(int button, int x, int y, void *param)
{
	printf("Mouse : x = %d, y = %d, button = %d.\n", x, y, button);
	return (1);
}

int expose_hook(void *param)
{
	printf("expose changes\n");
	return (1);
}

void fill_pixel(char *img_str, int x, int y, int color, int size_line)
{
	int i = 0;
	int j = 0;
	char *tmp = img_str;

	tmp = tmp + x * 4 + y * size_line;
	int mask = color;
	*tmp = mask;
	*(tmp + 1) = mask >> 8;
	*(tmp + 2) = mask >> 16;
}

int main(int ac, char **av)
{
	t_mlx main;
	int x;
	int y;
	void *image;
	char *s;
	int endian;
	int bpp;
	int s_l;
	t_file file;
	t_point *point;

	if (ac != 2)
		return (0);
	main.mlx = mlx_init();
	main.win = mlx_new_window(main.mlx, 400, 400, "Test 42.");
	image = mlx_new_image(main.mlx, 400, 400);
	s = mlx_get_data_addr(image, &bpp, &(s_l), &endian);
	unsigned int color = mlx_get_color_value(main.mlx, 0x00FFFF);
	printf("color value : %u\n", color);
	point = ft_parsing(av[1], &file);
	int i = 0;
	int j = 0;
	int k = 0;
	while (i < file.col * file.line)
	{
		if (j == file.col)
		{
			k += 20;
			j = 0;
		}
		fill_pixel(s, point[i].x + 20 + 20 * j, point[i].y + 20 + k, color, s_l);
		i++;
		j++;
	}
	//mlx_pixel_put(main.mlx, main.win, x, y, 0x00FF0000);
	mlx_put_image_to_window(main.mlx, main.win, image, 0, 0);
	//mlx_string_put(main.mlx, main.win, 100, 100, 0x00FF00FF, "FUCK HER");
	mlx_expose_hook(main.win, expose_hook, &main);
	mlx_mouse_hook(main.win, mouse_hook, &main);
	mlx_key_hook(main.win, my_key_funct, &main);
	mlx_loop(main.mlx);
	return (0);
}
