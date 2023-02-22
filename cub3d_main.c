
#include "./cub3d.h"


int check_arguments(char **argv)
{
	//.cub으로 끝나는지 확인, error control : 오류 시 1 반환
	int		i;

	i = (int)ft_strlen(argv[1]);
	if (ft_strncmp(argv[1] + i - 4, ".cub", 4) != 0)
		return (-1);
	return (0);
}


int floor_casting(t_window *window)
{

	for(int y = 0; y < h; y++)
    {
      // rayDir for leftmost ray (x = 0) and rightmost ray (x = w)
      float rayDirX0 = dirX - planeX;
      float rayDirY0 = dirY - planeY;
      float rayDirX1 = dirX + planeX;
      float rayDirY1 = dirY + planeY;

      // Current y position compared to the center of the screen (the horizon)
      int p = y - screenHeight / 2;

      // Vertical position of the camera.
      float posZ = 0.5 * screenHeight;

      // Horizontal distance from the camera to the floor for the current row.
      // 0.5 is the z position exactly in the middle between floor and ceiling.
      float rowDistance = posZ / p;

      // calculate the real world step vector we have to add for each x (parallel to camera plane)
      // adding step by step avoids multiplications with a weight in the inner loop
      float floorStepX = rowDistance * (rayDirX1 - rayDirX0) / screenWidth;
      float floorStepY = rowDistance * (rayDirY1 - rayDirY0) / screenWidth;

      // real world coordinates of the leftmost column. This will be updated as we step to the right.
      float floorX = posX + rowDistance * rayDirX0;
      float floorY = posY + rowDistance * rayDirY0;

      for(int x = 0; x < screenWidth; ++x)
      {
        // the cell coord is simply got from the integer parts of floorX and floorY
        int cellX = (int)(floorX);
        int cellY = (int)(floorY);

        // get the texture coordinate from the fractional part
        int tx = (int)(texWidth * (floorX - cellX)) & (texWidth - 1);
        int ty = (int)(texHeight * (floorY - cellY)) & (texHeight - 1);

        floorX += floorStepX;
        floorY += floorStepY;

        // choose texture and draw the pixel
        int floorTexture = 3;
        int ceilingTexture = 6;
        Uint32 color;

        // floor
        color = texture[floorTexture][texWidth * ty + tx];
        color = (color >> 1) & 8355711; // make a bit darker
        buffer[y][x] = color;

        //ceiling (symmetrical, at screenHeight - y - 1 instead of y)
        color = texture[ceilingTexture][texWidth * ty + tx];
        color = (color >> 1) & 8355711; // make a bit darker
        buffer[screenHeight - y - 1][x] = color;
	
      }
    }
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
	window->W_img.count = 0;
	window->N_img.count = 0;
	window->S_img.count = 0;
	window->E_img.count = 0;
	window->exist_flag = 0;
	window->map_col = 0;
	window->map_row = 0;
	window->map = 0;
	window->queue = 0;
	window->queue_isempty = 1;
	window->visited = 0;
}

int main(int argc, char **argv)
{
	t_window	*window;

	if(argc != 2)	
		ft_put_error("Error\n");
	window = (t_window *)malloc(sizeof(t_window));
	if (!(window))
		ft_put_error("Error\n");
	if (check_arguments(argv))
		ft_put_error("Error\n");
	init_game(window);
	check_map(window, argv[1]);

	set_game(window);
	window->win = mlx_new_window(window->mlx, window->win_width,
						window->win_height, "CUB_3D");
	
	floor_casting(window);

		
	


	//TODO : libft 불러오기


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


		1.  WSAD 로 이동, 
		2.  방향키 오른쪽 왼쪽으로 회전
			-> cos, sin 사용되나? 
		3.	esc , red cross button

	
	*/
	
}
