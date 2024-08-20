#include <stdio.h>
#include <stdlib.h>   
                          
 struct estructura_amigo {
	int cedula;
	char nombre[30];
	char apellido[30];
	char telefono[11];
	int edad;
}	personal;
      
  
int main()
{
         
       FILE *archivo;         
                  
       
       archivo = fopen("Ejercicio.txt","r");
       if (archivo == NULL){          
           printf("\n  Error de apertura del archivo. \n\n");
           	exit( 1 );
          
           }
       else {    
		   
		    printf( "\n Cedula de Identidad : \t" );
			   	 printf( " Nombre (30 letras maximo ): \t" );
    	    	 printf( " Apellido (30 letras maximo):\t " );
            	 printf( " Telefono : \t " );
		         printf( " Edad:\t" );               
            while (feof(archivo) == 0){	
           
		 
			   
			   
				 fscanf(archivo,"%15d %30s %30s %11s %3d\n",&personal.cedula,personal.nombre,personal.apellido,personal.telefono,&personal.edad); 	   
			              
            printf( "\n Cedula de Identidad : \t" );
			   	 printf( "\n%d",personal.cedula  );
    	    	 printf( "\n%s",personal.apellido );
            	 printf( "\n%s",personal.nombre);
		         printf( "\n%d",personal.edad);
		         printf( "\n%s",personal.telefono);
       			
	  						
				}
        
		  } 
          
     
fclose(archivo);
	 						 return(0);		
			
 } 