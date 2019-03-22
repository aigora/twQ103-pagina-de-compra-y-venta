#include <stdio.h>

void main(){
	
	int opcion, i;
	char nombre[50];
	char pass1[50];
	char pass2[50];
	
	
	
	printf("----------------------------------------------------------------\n\n");
	printf("                         PUZZLES\n\n");
	printf("----------------------------------------------------------------\n\n");
	
printf("       Bnienvenido a puzzles\n\n ¡Somos una pagina de compra-ventas en la que puede confiar!\n\n");

printf("Porfavor escoja una opcion para continuar\n\n");

printf("  1-Crear nuevo usuario\n  2-Entrar con mi usuario\n  3-Comprar\n  4-Vender\n  5-Cerrar sesion\n\n");
scanf("%d",&opcion);

switch(opcion)
    {
	case 1: {
		system("cls");
		
	printf("Introduce tu usuario:\n");
  				scanf("%s", nombre);
  				printf("Introduce tu password (Maximo 10 caracteres):\n");
  				 for(i=0; i<10;i++){	
     				   pass1[i]=getch();
        				printf("*");
        					if(pass1[i]=='\r')
            					break;
							if(i==9){
								printf("\nEstas al limite de la contraseña, no puedes introducir mas caracteres.\n\n");
								break;
									}
         						}
         					
         		do{
				printf("\nIntroduce otra vez tu password (Maximo 10 caracteres):\n");
  				 for(i=0; i<10;i++){	
     				   pass2[i]=getch();
        				printf("*");
        					if(pass2[i]=='\r')
            				break;
         			}
         					printf("\n");
         			}
         		while(strcmp(pass1,pass2)!=0);
         		printf("Password correcta\n");
	     
		
		break;
	}
	
	case 2: {
		printf("Introduzca su usuario");
		
		break;
	}
	
	case 3: {
		break;
	}
	
	case 4: {
		break;
	}
	
	case 5: { 
	system("cls");
	printf(" GRACIAS POR SU VISITA\n\n LE ESPERAMOS PRONTO DE VUELTA");
		break;
	}
	
		
}


}


