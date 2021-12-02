#include<conio.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

//Paz Exequiel 1k5 legajo 53382

/*En un sistema se registra la información de los N programas en una estructura dinámica de pila
implementada dinámicamente,
? Nombre del programa
? Cantidad de líneas
a) Ingresar la información en la pila.
b) Borrar los datos de un programa.
c) Mostrar los datos.
d) Mostrar los datos de los programas registrados.*/

struct registro
{
	char programaNombre[50];
	char cantidadLineas[100];
};

struct nodo
{
	registro info;
	nodo *sig;
};

void inicializar(nodo *&frente);

void insertar(nodo *&frente, registro programas);

void listar(nodo *&frente);

void eliminar(nodo *&frente,nodo*&p);

main()
{
	nodo *frente,*p;
	registro programas;
	char salir;
	
	inicializar(frente);	
	do
	{
		printf("\nIngrese Nombre del programa: ");
		_flushall();
		gets(programas.programaNombre);
		printf("\nCantidad de lineas del programa: ");
		scanf("%s",&programas.cantidadLineas);
		insertar(frente,programas);
		printf("\n\nIngresar otro programa? S/N");
		printf("\nOpcion: ");
		salir=getch();
		if(salir<='z' && salir >='a')salir=salir-'a'+'A';
		system("cls");
	}while(salir=='S');
	
	printf("\nDatos de los programas: \n");
	listar(frente);
	eliminar(frente,p);
	listar(frente);
}

void inicializar(nodo *&frente)
{
     frente=NULL;
}

void insertar(nodo *&frente, registro programas)
{
     nodo *p;
     
     p=new nodo;
     
     if (p!=NULL)
     {
           strcpy(p->info.cantidadLineas,programas.cantidadLineas);
           strcpy(p->info.programaNombre,programas.programaNombre);
           p->sig=frente;
           frente=p;
     }  
     else
           printf("ERROR - PILA LLENA");
}

void listar(nodo *&frente)
{
	nodo *p;
	
	p=frente;
    while (p!=NULL)
    {
          printf("Programa: %s\n",p->info.programaNombre);
          printf("Cantidad de lineas: %s\n",p->info.cantidadLineas);
          printf("\n");
          p=p->sig;
    }
    getch();
}

void eliminar(nodo *&frente,nodo*&p)
{
	
	registro aux[50];
	char programa[50];
	int comparar,i=0,n;
	bool b=false;
	
	printf("\nIngrese el nombre del programa a borrar: ");
	_flushall();
	gets(programa);
	p=frente;
    while (p!=NULL)
    {
          comparar=strcmp(programa,p->info.programaNombre);
          if(comparar!=0)
          {
          	strcpy(aux[i].programaNombre,p->info.programaNombre);
          	strcpy(aux[i].cantidadLineas,p->info.cantidadLineas);
          	i++;
          	b=true;
          }
          else
          {
			printf("Programa: %s\n",p->info.programaNombre);
			printf("Cantidad de lineas: %s\n",p->info.cantidadLineas);
	        printf("\n");
          }
          p=p->sig;
    }
    if(b==true)
    {
    	delete frente;
    	n=i;
    	inicializar(frente);
    	for(i=0;i<n;i++)
    	{
    		insertar(frente,aux[i]);
    	}
    }
    
    getch();
}




