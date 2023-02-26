
#include "../include/cub3d.h"

void init_game(t_window *window);

int main(int argc, char **argv)
{
	t_window	*window;

	if(argc != 2)	
		ft_put_error("Error : argument\n");
	window = (t_window *)malloc(sizeof(t_window));
	if (!(window))
		ft_put_error("Error : malloc\n");
	if (check_arguments(argv))//.cub로 끝나는 지 확인
		ft_put_error("Error : argument\n"); 
	init_game(window); //window 구조체의 값 초기화 
	if (save_map(window, argv[1])) //맵을 구조체에 저장, 맵이 유효한지 확인, 맵의 내용들 저장
		ft_put_error("Error: map error\n");
	if (check_map_shape(window))
		ft_put_error("Error\n map shape");
	
	printf("check map done\n");
	// set_game(window);
	// window->win = mlx_new_window(window->mlx, window->win_width,
						// window->win_height, "CUB_3D");
	// floor_casting(window);

	//world map free!

	/*
	t_map 의 구성요소
	double posX = 22, posY = 12;  //x and y start position
  	double dirX = -1, dirY = 0; //initial direction vector
  	double planeX = 0, planeY = 0.66; //the 2d raycaster version of camera plane

	t_img W,S,N,E

	1. 화면 생성
	2. 이미지 불러오기, 저장
	3. floor casting
	4. wall casting

	5. draw: 3,4에서 buffer에 저장한 걸 읽으면서 맞게 img를 그린다. 

	6. key hook :

	mlx_key_hook(window->win, &check_key, window);
	mlx_hook(window->win, X_BUTTON, 0, &x_button, window);
	mlx_loop(window->mlx);
	*/
	
}

int check_arguments(char **argv)
{
	//.cub으로 끝나는지 확인, error control : 오류 시 1 반환
	int		i;

	i = (int)ft_strlen(argv[1]);
	if (ft_strncmp(argv[1] + i - 4, ".cub", 4) != 0)
		return (-1);
	return (0);
}

void set_game(t_window *window)
{
	window->mlx = mlx_init();
	window->win = NULL;
	window->win_width = 640;
	window->win_height = 480;
	window->W_img.img = mlx_xpm_file_to_image(window->mlx,
			window->W_img.path, &window->W_img.width,
			&window->W_img.height);
	window->S_img.img = mlx_xpm_file_to_image(window->mlx,
			window->S_img.path, &window->S_img.width,
			&window->S_img.height);
	window->N_img.img = mlx_xpm_file_to_image(window->mlx,
			window->N_img.path, &window->N_img.width,
			&window->N_img.height);
	window->E_img.img = mlx_xpm_file_to_image(window->mlx,
			window->E_img.path, &window->E_img.width,
			&window->E_img.height);
}

void init_game(t_window *window)
{
	window->exist_flag = 1;
	window->pos_x = -1;
	window->pos_y = -1;
	window->map_col = 0;
	window->map_row = 0;
	window->direction = -1;
	window->map = 0;
	window->queue = 0;
	window->queue_isempty = 1;
	window->visited = 0;
	window->worldmap = 0;
	window->map_char = 0;
	window->floor.r = -1;
	window->floor.g = -1;
	window->floor.b = -1;
	window->ceiling.r = -1;
	window->ceiling.g = -1;
	window->ceiling.b = -1;
	window->character_count = 0;
}


