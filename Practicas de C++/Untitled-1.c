//crear  perfecta un fichero de texto (Ejercicio.txt) y guarda su contenido en un archivo
#include <stdio.h> // Biblioteca estándar de entrada/salida. Si quieres usar printf y scanf
#include <stdlib.h>/* la librería stdlib.h es necesaria para que "system" funcione */
#include <windows.h> 
#include <conio.h>
/* conio.h   no es una librería estándar, sólo los compiladores de Borland pueden usarla.
 background(), clrscr(), gotoxy(a,b), getch(), textcolor(), cprintf() */
                    
           
    
 struct estructura_amigo {
	int cedula;
	char nombre[30];
	char apellido[30];
	char telefono[11];
	int edad;
}	personal;
      
  
int main()
{
 
   char opc;
         
       FILE *archivo;         
       int cedula ; 
	   int Bandera=0;        
       
       archivo = fopen("Ejercicio.txt","w");
       if (archivo == NULL){      //NULL   archivo NO  fue  abierto con éxito            
           printf("\n  Error de apertura del archivo. \n\n");
           	exit( 1 );
          
           }
       else {                   
            while (feof(archivo) == 0){	
            fflush(stdin); // vacia el bufer de teclado
	        printf("\n\250Desea ingresar datos continuar? (s/n): ");
	        scanf("%c",&opc); 
		  		if (opc == 's' || opc == 'S'){
		  			
		  			printf( "\n   CEDULA \t" );
				scanf( "%d",&cedula );		
				  	
		  		 system("cls");
			   
			   
				 fscanf(archivo,"%15d %30s %30s %11s %3d\n",&personal.cedula,personal.nombre,personal.apellido,personal.telefono,&personal.edad);
				// printf( "\n %d\t  %d",personal.cedula,cedula);
				 
				 if(cedula== personal.cedula) 
				 {
				  
				  printf( "\n\n El valor ya exite \t" );
				 			  
				   Bandera=0;
				 } 
				 else
				  {
				  
				  Bandera=1;
		          
				 }	
				 if (Bandera==1) { 
		  		personal.cedula= cedula;	
			     printf( "\n Cedula de Identidad : \t" );
			     printf( " %d",personal.cedula );
			     printf( "\n Nombre (30 letras maximo ): \t" );
		   		 scanf( "%s",personal.nombre );
    	    	 printf( "\n Apellido (30 letras maximo):\t " );
        	     scanf( "%s",personal.apellido );
            	 printf( "\n Telefono : \t " );
       		     scanf( "%s",personal.telefono);
		         printf( "\n Edad:\t" );
				 fflush(stdin); // vacia el bufer de teclado
		         scanf( "%i",&personal.edad);
		     
            
			   
			   
			   
				 fprintf(archivo,"%15d %30s %30s %11s %3d\n",personal.cedula,personal.nombre,personal.apellido,personal.telefono,personal.edad); 	   
			     	}         
           
       			}
				else if(opc == 'n' || opc == 'N'){
	  						fclose(archivo);
	 						 return(0);
				}
        
		  } 
          
    
  } 
		
			
 } 