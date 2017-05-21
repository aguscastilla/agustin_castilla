#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define W_SIZE_X 20
#define W_SIZE_Y 15

void world_init(bool world_a[W_SIZE_X][W_SIZE_Y]);
void world_print(bool world_a[W_SIZE_X][W_SIZE_Y]);
bool world_get_cell(bool world_a[W_SIZE_X][W_SIZE_Y], int i, int j);
int  world_count_neighbors(bool world_a[W_SIZE_X][W_SIZE_Y], int i, int j);
void world_step(bool world_a[W_SIZE_X][W_SIZE_Y], bool world_b[W_SIZE_X][W_SIZE_Y]);
void world_copy(bool world_a[W_SIZE_X][W_SIZE_Y], bool world_b[W_SIZE_Y][W_SIZE_Y]);

int main()
{
	bool world_a[W_SIZE_X][W_SIZE_Y]; 
	bool world_b[W_SIZE_X][W_SIZE_Y]; 
	
	world_init(world_a);
	
	int i = 0;
	do {
	
	printf("\033cIteration %d\n", i++);
	
	world_print(world_a);
	
	world_step(world_a, world_b);
	
	} while (getchar() != 'q');       
	            
	return EXIT_SUCCESS ;
}

void world_init(bool world_a[W_SIZE_X][W_SIZE_Y])
{	
	// inizializar a false:
	for (int i = 0; i<W_SIZE_X; i++)     
		for (int j = 0; j<W_SIZE_Y; j++)
			world_a[i][j] = false ; 
	
	// inicializar glade:	  
	world_a[0][1] = true ;              
	world_a[1][2] = true ;
	world_a[2][0] = true ;
	world_a[2][1] = true ;
	world_a[2][2] = true ; 
}    
	  
void world_print(bool world_a[W_SIZE_X][W_SIZE_Y])
{	
	for (int i = 0; i<W_SIZE_X; i++)
	{
		for (int j = 0; j<W_SIZE_Y; j++) 
		{
			world_a[i][j] ? printf(" #") : printf(" .");
		}      
			printf("\n");             
	}  
			printf("\n"); 
}
 
//Se comprueba si las coordenadas pasadas esten fuera de limites
bool world_get_cell(bool world_a[W_SIZE_X][W_SIZE_Y], int i, int j)
{
	if ((i == -1 || j==-1) || (i == W_SIZE_X || j== W_SIZE_Y))
		return false;
	else 
		return world_a[i][j];
}						

void world_step(bool world_a[W_SIZE_X][W_SIZE_Y], bool world_b[W_SIZE_X][W_SIZE_Y])
{
	bool std_cell;
	int  neigh;
	for (int i = 0; i<W_SIZE_X; i++)
	{
		for (int j = 0; j<W_SIZE_Y; j++) 
		{
		std_cell = world_get_cell(world_a, i, j);  
		       
		neigh = world_count_neighbors(world_a, i, j); 
		
		if (std_cell == false && neigh == 3) world_b[i][j] = true; 
			else if ((std_cell == true && neigh == 2) || neigh == 3) world_b[i][j] = true;
				else world_b[i][j] = false; 
		}
	}
	world_copy(world_a, world_b);
}

void world_copy(bool world_a[W_SIZE_X][W_SIZE_Y], bool world_b[W_SIZE_X][W_SIZE_Y])
{
	for (int i = 0; i<W_SIZE_X; i++)
		for (int j = 0; j<W_SIZE_Y; j++) 
			world_a[i][j] = world_b[i][j];
} 

int world_count_neighbors(bool world_a[W_SIZE_X][W_SIZE_Y], int x, int y)
{	
	int count = 0;
	count += world_get_cell(world_a, x-1, y-1);
	count += world_get_cell(world_a, x-1, y  );
	count += world_get_cell(world_a, x-1, y+1);
	count += world_get_cell(world_a, x,   y-1);
	count += world_get_cell(world_a, x,   y+1);
	count += world_get_cell(world_a, x+1, y-1);
	count += world_get_cell(world_a, x+1, y  );
	count += world_get_cell(world_a, x+1, y+1);
	return count;
}
