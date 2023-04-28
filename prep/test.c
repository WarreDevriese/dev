#include <mlx.h>

typedef struct	s_data
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

int		close_win_esc(int keycode, t_data *img)
{
	if (keycode == 65307)
	{
		mlx_destroy_window(img->mlx, img->win);
		return (0);
	}
	return(0);		
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int		main(void)
{
	t_data	img;

	img.mlx = mlx_init();
	img.win = mlx_new_window(img.mlx, 1920, 1080, "Hello world!");
	img.img = mlx_new_image(img.mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	int x = 0;
	while (x < 1920)
	{
		int	y = 0;
		while (y < 1080)
		{
			int red = (float)x / 1920 * 255;
			int green = 0;
			int blue = (1.0 - (float)x / 1920) * 255;
			int color = 0;
			color = (color | red) << 8;
			color = (color | green) << 8;
			color = (color | blue);
			my_mlx_pixel_put(&img, x, y, color);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(img.mlx, img.win, img.img, 0, 0);
	mlx_hook(img.win, 2, 1L<<0, close_win_esc, &img);
	mlx_loop(img.mlx);
}
