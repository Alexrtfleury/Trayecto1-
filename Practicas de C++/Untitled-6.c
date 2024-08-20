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
                  
       
       archivo = fopen("Inventario IVSS.txt","w");
       if (archivo == NULL){ 
           printf("\n  Error de apertura del archivo. \n\n");
           	exit( 1 );
          
           }
       else {                   
            while (feof(archivo) == 0){	
            fflush(stdin);
	        printf("\n\250Desea ingresar datos continuar? (s/n): ");
	        scanf("%c",&opc); 
		  		if (opc == 's' || opc == 'S'){
			     printf( "\n Equipo : \t" );
			     scanf( "%s",&Equipo.Nombre );
			   	 printf( "\n Marca : \t" );
		   		 scanf( "%s",Equipo.Marca );
    	    	 printf( "\n Modelo :\t " );
        	     scanf( "%s",Equipo.Modelo );
            	 printf( "\n Serial : \t " );
       		     scanf( "%s",Equipo.Serial); 
       		     printf( "\n Caracteristicas : \t " );
       		     scanf( "%s",Equipo.Caracteristicas);                   
				 fflush(stdin);
		     	   
				 fprintf(archivo," %15s %30d %30s %11s %200s\n",Equipo.Nombre,Equipo.Modelo,Equipo.Marca,Equipo.Serial,Equipo.Caracteristicas); 	   
			       
			 printf( "\n Nombre =\t %s",Equipo.Nombre );
            printf( "\n Modelo = \t %s",Equipo.Modelo );
             printf( "\n Marca = \t %s",Equipo.Marca );
             printf( "\n Serial = \t %d",Equipo.Serial );
              printf( "\n Caracteristicas =\t %s",Equipo.Caracteristicas );         
       			}
				else if(opc == 'n' || opc == 'N'){
	  						fclose(archivo);
	 						 return(0);
				}
        
		  } 
          
    
  } 
		
			
 } 