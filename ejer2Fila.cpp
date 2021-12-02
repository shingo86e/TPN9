#include<conio.h>
#include<stdlib.h>
#include<stdio.h>

//Paz Exequiel 1k5 legajo 53382

/*Cree una estructura dinámica de lista, para almacenar la información de N empleados de una
fábrica de los cuales se debe guardar, la siguiente información:
? legajo
? apellido y nombre
? edad
a) Ingrese los datos de los empleados.
b) Borre la información de uno de ellos.
c) Muestre la información que quedó en la pila*/

struct registro
{
	int legajo,edad;
	char nomApe[50];
};

struct nodo
{
	registro info;
	nodo *sig;
};

void inicializar(nodo *&frente);

void insertar(nodo *&frente, registro empleados);
 
void recorrer(nodo *frente);

void eliminar(nodo *&frente);

main()
{
	int n;
	registro empleados;
	nodo *frente;
	
	inicializar(frente);
	
	printf("Ingrese la cantidad de empleados que desea guardar: ");
	scanf("%d",&n);
	
	for (int i=0;i<n;i++)
	 {
		 printf("\nIngrese Nombre y Apellido: ");
		 _flushall();
		 gets(empleados.nomApe);
		 printf("Legajo: ");
		 scanf("%d", &empleados.legajo);
		 printf("Edad: ");
		 scanf("%d", &empleados.edad);
		 insertar(frente,empleados);
		 system("cls");
	 }
	printf("\nLista de empleados: \n");
	recorrer(frente);
	printf("\nEliminar un empleado\n");
	eliminar(frente);
	printf("\nLista de empleados Nueva: \n");
	recorrer(frente);
	getch();
}

void inicializar(nodo *&frente)
{
 	frente=NULL;
}

void insertar(nodo *&frente, registro empleados)
{
	 nodo *act, *p, *ant;
	 p=new nodo; //le da una direccion de sistema ej FF2
	 act=frente;
	 ant=frente;
	 if (p!=NULL)
	 {
		p->info=empleados;//le asigna a p campo info el valor de x
		while ((act!=NULL) && (act->info.legajo < p->info.legajo)) //si act es NULL y act campo info es menor a p campo info
		{
			 ant=act;
			 act=act->sig;
		}
		if (act==ant)
		{
			 p->sig=frente;
			 frente=p; 
		}
		else
		{
			if (act!=NULL)
			{	
				p->sig=ant->sig;
			 	ant->sig=p;
			 	getchar();
			}
			 else
			{
				p->sig=NULL;
				ant->sig=p;
				getchar();
			}
			 
		}
	}
	else 
	{
		printf("Error fatal en el HEAP no se puede insertar un nodo");
		getch();
	}
 }
 
 void recorrer(nodo *frente)
{
	 nodo *p;
	 p=frente;
	 while (p != NULL)
	 {
		 printf("Legajo: %d\n",p->info.legajo);
		 printf("Nombre y Apellido: %s\n",p->info.nomApe);
		 printf("Edad: %d\n",p->info.edad);
		 p=p->sig;
		 printf("\n");
	 }
}

void eliminar(nodo *&frente)
{
	 int buscar;
	 nodo *act, *ant;

	 if (frente!=NULL)
	 {
		 printf("Introducir el Legajo a eliminar:\n");
		 scanf("%d", &buscar);
		 act=frente;
		 ant=frente;
		 while ((act!=NULL) && (act->info.legajo < buscar))
		 {
			 ant=act;
			 act=act->sig;
		 }
		 if ((act!=NULL) && (act->info.legajo == buscar))
		 {
			 if (ant!=act)
			 {
				 //elimina nodo del medio o el del final
				 ant->sig=act->sig;
			 }
			 else
			 { //elimina el primer nodo
			 	frente=act->sig;
			 }
			 delete(act);
			 printf("\nNodo eliminado\n");
		 }
		 else
		 printf("\nNo existe un nodo con ese numero\n\n"); 
	 }
	 else printf("LISTA VACIA");
 }
