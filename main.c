
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


// Crea dos macros con el tamaño horizontal y vertical del mundo

#define TAMX 10
#define TAMY 10

void world_init (bool m[TAMX+2][TAMY+2]);
void world_prin (bool m[TAMX+2][TAMY+2]);
bool world_get_cell(bool m[TAMX+2][TAMY+2],int x,int y);
int  world_count_neighbors(bool m[TAMX+2][TAMY+2],int x,int y);
void world_step (bool m[TAMX+2][TAMY+2],bool n[TAMX+2][TAMY+2]);
void world_copy (bool m[TAMX+2][TAMY+2], bool n[TAMX+2][TAMY+2]);

int main()
{
	
	// Declara dos mundos
    bool world_a[TAMX+2][TAMY+2]; 
    bool world_b[TAMX+2][TAMY+2];
	
    // inicializa el mundo_a
    world_init ( world_a);
    world_init ( world_b);
    
    int i=0;
    do {
		 printf("\033cIteration %d\n", i++);
		 
		 //imprimir mundo_a
         world_prin ( world_a);
	     
	     // Recorrer el mundo célula por célula 
	     world_step ( world_a,world_b );
	     
	   } while  (getchar() != 'q');  
	            
	   return EXIT_SUCCESS ;
}

void world_step (bool world_a[TAMX+2][TAMY+2],bool world_b[TAMX+2][TAMY+2])
{
	// Recorrer el mundo célula por célula 
	 
	 bool std_cel ;
	 for (int i=1; i<=TAMX; i++) 
            for (int j=1; j<=TAMY; j++)
               {
				// pedir imprimir estado de la celula 
	            std_cel = world_get_cell(world_a, i,j); 
		            
		        // contar las celulas vecinas vivas
	            int cont=0;
	            cont = world_count_neighbors(world_a,i,j);
	             
	            //celula nace con con tres vecinas vivas
	            if ((std_cel == false) && (cont == 3)) world_b[i][j] = true; 
	            else 
	            // celula viva con 2 o 3 vecinas vivas sigue viva
	            if ((std_cel == true) && ((cont == 2)||(cont == 3))) world_b[i][j] = true;
	            else world_b[i][j] = false; 
	           }
			 // Copiar el mundo auxiliar sobre el mundo principal
	         world_copy (world_a, world_b);    
}

//Definicin funcion inicializar mundo
void world_init (bool w[TAMX+2][TAMY+2])
	  {
	  for (int i=0; i<TAMX+2; i++)     // inizializar a false
	   for (int j=0; j<TAMY+2; j++)
		  w[i][j] = false ; 
		  
	  w[1][2] = true ;              // inicializar glade
	  w[2][3] = true ;
	  w[3][1] = true ;
	  w[3][2] = true ;
	  w[3][3] = true ; 
	  }    

//Definicion funcion imprimir mundo	  
void world_prin (bool w[TAMX+2][TAMY+2])
{
	for (int i=1; i<=TAMX; i++){
	    for (int j=1; j<=TAMY; j++) {
	    
		  if (w[i][j] == true) printf(" #");
	      else printf(" .");       }    
	  printf("\n");             }  
	   printf("\n");  
} 
 
 //devuelve el estado de la posicion indicada    
bool world_get_cell(bool w[TAMX+2][TAMY+2], int x, int y)
 {
	 bool std = w[x][y];
	 return std;
 }
	 
//imprime el numero de celulas vecinas vivas
int  world_count_neighbors (bool w[TAMX+2][TAMY+2],int x,int y)
 {  
	int cont = 0;
    if(world_get_cell (w, x-1, y-1)) cont++;
    if(world_get_cell (w, x-1,  y )) cont++;
	if(world_get_cell (w, x-1, y+1)) cont++;
	
	if(world_get_cell (w, x,   y-1)) cont++;
	if(world_get_cell (w, x,   y+1)) cont++;
	
	if(world_get_cell (w, x+1, y-1)) cont++;
	if(world_get_cell (w, x+1,  y )) cont++;
	if(world_get_cell (w, x+1, y+1)) cont++;
	
	return cont;
}

void world_copy(bool world_a[TAMX+2][TAMY+2], bool world_b[TAMX+2][TAMY+2])
{
	// copia el mundo segundo mundo sobre el primero
	for (int i=0; i<TAMX+2; i++)
	  for (int j=0; j<TAMY+2; j++) 
	   
			world_a[i][j] = world_b[i][j] ;
} 


