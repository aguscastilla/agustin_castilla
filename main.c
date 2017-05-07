#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Crea dos macros con el tamaño horizontal y vertical del mundo

#define TAMX 15
#define TAMY 15

void world_init (bool m[TAMX][TAMY]);
void world_print (bool m[TAMX][TAMY]);
void world_step ();
int  world_count_neighbors();
bool world_get_cell();
void world_copy ();

int main()
{
	int i = 0;
	//  Declara dos mundos
    bool world_a[TAMX][TAMY]; 
    bool world_b[TAMX][TAMY];

	// inicializa el mundo
    world_init(world_a);
	
    do {
		printf("\033cIteration %d\n", i++);
		// Imprime el mundo
    world_print (world_a);

		//  Itera
    
	} while (getchar() != 'q');

	return EXIT_SUCCESS;
}

void world_init(bool w[TAMX][TAMY])
{
	// Poner el mundo a false
    for (int i=0; i<TAMX; i++)  
	   for (int j=0; j<TAMY; j++)
		  w[i][j] = false ; 

	// Inicializar con el patrón del glider:
    w[0][1] = true ;             
	w[1][2] = true ;
	w[2][0] = true ;
	w[2][1] = true ;
	w[2][2] = true ; 
	 
}

void world_print(bool w[TAMX][TAMY])
{
	// Imprimir el mundo por consola. Sugerencia:
	for (int i=0; i<TAMX; i++)  {
	    for (int j=0; j<TAMY; j++) {
	    
		  if (w[i][j] == true) printf(" #");
	      else printf(" .");       }    
	  printf("\n");             }  
	   printf("\n");
}

void world_step(/* Recibo dos mundos */)
{
	/*
	 * TODO:
	 * - Recorrer el mundo célula por célula comprobando si nace, sobrevive
	 *   o muere.
	 *
	 * - No se puede cambiar el estado del mundo a la vez que se recorre:
	 *   Usar un mundo auxiliar para guardar el siguiente estado.
	 *
	 * - Copiar el mundo auxiliar sobre el mundo principal
	 */
}

int world_count_neighbors(/* Recibo un mundo y unas coordenadas */)
{
	// Devuelve el número de vecinos
}

bool world_get_cell(/* Recibo un mundo y unas coordenadas */)
{
	/*
	 * TODO: Devuelve el estado de la célula de posición indicada
	 * (¡cuidado con los límites del array!)
	 */
}

void world_copy(/* Recibo dos mundos */)
{
	// TODO: copia el mundo segundo mundo sobre el primero
}
