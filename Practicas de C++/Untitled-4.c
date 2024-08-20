#include <stdio.h>
#include <stdlib.h>                             
 struct estructura_IVSS {
	char Nombre[15];
	char Modelo[30];
	char Marca[30];
	char Serial[11];
	char Caracteristicas[200]; 
}	Equipo;
      
  
int main()
{
 
   char opc;
         
       FILE *archivo;         
                  
       
       archivo = fopen("Inventario IVSS.txt","r");
       if (archivo == NULL){ 
           printf("\n  Error de apertura del archivo. \n\n");
           	exit( 1 );
          
           }
       else {                   
			     printf( "\n Equipo : \t" );
			   	 printf( "\n Marca : \t" );
    	    	 printf( "\n Modelo :\t " );
            	 printf( "\n Serial : \t " );
       		     printf( "\n Caracteristicas : \t " );  
                  while (feof(archivo) == 0){
		     	   
				 fscanf(archivo," %15s %30d %30s %11s %200s\n",Equipo.Nombre,Equipo.Modelo,Equipo.Marca,Equipo.Serial,Equipo.Caracteristicas); 

                  printf( "\n% d",Equipo.Nombre  );
                   printf( "\n% d",Equipo.Modelo  );
                   printf( "\n% d",Equipo.Marca  );
                   printf( "\n% d",Equipo.Serial  );
                   printf( "\n% d",Equipo.Caracteristicas  );


       			}
				else if(opc == 'n' || opc == 'N'){
	  						fclose(archivo);
	 						 return(0);
				}
            }
}