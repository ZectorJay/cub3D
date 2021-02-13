#define MLX_SYNC_IMAGE_WRITABLE		1
#define MLX_SYNC_WIN_FLUSH_CMD		2
#define MLX_SYNC_WIN_CMD_COMPLETED	3
int	mlx_sync(int cmd, void *param);
int	mlx_get_screen_size(void *mlx_ptr, int *sizex, int *sizey);
