#include<conio.h>
#include<stdlib.h>
#include<stdio.h>

//Paz Exequiel 1k5 legajo 53382

/*1) Dado un conjunto de N valores reales. Los cuáles serán guardado en una estructura dinámica de
lista.
a) Ingresar N valores reales en una estructura de lista.
b) Una vez ingresados los datos en la lista, ordene de menor a mayor la lista.
c) Ingresar un valor X, si dicho valor se encuentra en la lista elimínelo.
d) Liste los elementos que quedaron en la lista.*/

struct nodo
{
	float info;
	nodo *sig;
};

void inicializar(nodo *&frente);

void insertar(nodo *&frente, float x);

void recorrer(nodo *frente);

void eliminar(nodo *&frente);

main()
{
	int n;
	float x;
	nodo *frente;
	
	inicializar(frente);
		
	printf("Ingrese la cantidad de valores reales que desea guardar: ");
	scanf("%d",&n);
	
	for (int i=0;i<n;i++)
	 {
		 printf("Introducir numero:\n");
		 scanf("%f", &x);
		 insertar(frente,x);
	 }
	 printf("\nLista Ordenada: \n");
	 recorrer(frente);
	 eliminar(frente);
	 printf("\nLista Ordenada con Numero eliminado: \n");
	 recorrer(frente);
}

void inicializar(nodo *&frente)
{
 	frente=NULL;
}

void insertar(nodo *&frente, float x)
{
	 nodo *act, *p, *ant;
	 p=new nodo; //le da una direccion de sistema ej FF2
	 act=frente;
	 ant=frente;
	 if (p!=NULL)
	 {
		p->info=x;//le asigna a p campo info el valor de x
		while ((act!=NULL) && (act->info < p->info)) //si act es NULL y act campo info es menor a p campo info
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
		 printf("%.2f\n",p->info);
		 p=p->sig;
	 }
}
void eliminar(nodo *&frente)
{
	 float buscar;
	 nodo *act, *ant;

	 if (frente!=NULL)
	 {
		 printf("Introducir el numero a eliminar:\n");
		 scanf("%f", &buscar);
		 act=frente;
		 ant=frente;
		 while ((act!=NULL) && (act->info < buscar))
		 {
			 ant=act;
			 act=act->sig;
		 }
		 if ((act!=NULL) && (act->info == buscar))
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
