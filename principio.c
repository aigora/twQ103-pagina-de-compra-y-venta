#include <stdio.h>
#include <string.h>

void main(){
	
	int opcion, op, i;
	char nombre[50];
	char pass1[50];
	char pass2[50];
	
	system("color 9");
	
	printf("----------------------------------------------------------------\n\n");
	printf("                         PUZZLES\n\n");
	printf("----------------------------------------------------------------\n\n");
	
printf("       Bienvenido a puzzles\n\n �Somos una pagina de compra-ventas en la que puede confiar!\n\n");

printf("Porfavor escoja una opcion para continuar\n\n");

printf("  1-Crear nuevo usuario\n  2-Entrar con mi usuario\n  3-Cerrar sesion\n\n");
scanf("%d",&opcion);

switch(opcion)
    {
	case 1: {
		system("cls");
		
	printf("Introduce tu usuario:\n");
  				scanf("%s", nombre);
  				printf("Introduce tu password (Maximo 10 caracteres):\n");
  				 for(i=0; i<10;i++)
				    {	
     				   pass1[i]=getch();
        				printf("*");
        					if(pass1[i]=='\r')
            					break;
							if(i==9)
							{
								printf("\nEstas al limite de la contrase�a, no puedes introducir mas caracteres.\n\n");
								break;
							}
         			}
         					
         		do{
				printf("\nIntroduce otra vez tu password (Maximo 10 caracteres):\n");
  				 for(i=0; i<10;i++)
				    {	
     				   pass2[i]=getch();
        				printf("*");
        					if(pass2[i]=='\r')
            				break;
         			}
         					printf("\n");
         			}
         		while(strcmp(pass1,pass2)!=0);
         		printf("Password correcta\n");
         		printf("Bienvenido a nuestra pagina\n");
	     
		
		break;
	}
	
	case 2: {
		system("cls");
		
		printf("Introduzca su usuario\n");
		scanf("%s", nombre);
  				printf("Introduce tu password (Maximo 10 caracteres):\n");
  				for(i=0; i<10;i++)
					{	
     				   pass1[i]=getch();
        				printf("*");
        					if(pass1[i]=='\r')
            					break;
							if(i==9)
							{
								printf("\nEstas al limite de la contrase�a, no puedes introducir mas caracteres.\n\n");
								break;
							}
         			}
        printf("\n");
        printf("Bienvenido %s\n", nombre); 	
		system("cls");		
		
		printf("Seleccione la opcion que desea realizar\n");
		printf("1. Comprar\n2. Vender\n");
		scanf("%d",&op);
		switch (op)
		{
			case 1:
			{
				system("cls");
				printf("Bienvenido a la seccion de compra. Eche un vistazo a nuestros productos\n");
			
				break;
			}
			case 2:
			{
				system("cls");
				printf("Bienvenido a la seccion de venta. Introduce aqui los productos que deseas vender");
				
				break;
			}
		}
		
		
		
		break;
		
		
	}
	
	case 3: { 
	system("cls");
	printf(" GRACIAS POR SU VISITA\n\n LE ESPERAMOS PRONTO DE VUELTA");
		break;
	}
	
		
}


}


