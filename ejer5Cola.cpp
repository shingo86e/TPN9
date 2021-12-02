#include<conio.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

//Paz Exequiel 1k5 legajo 53382

/*Dada la siguiente configuración de un registro:
? Código
? Importe
a) Inicializar una estructura de cola.
b) Ingresar n valores.
c) Borrar un valor.
d) Mostrar los datos de los artículos que quedan.*/

struct registro
{
	int codigo;
	float importe;
};

struct nodo
{
	registro info;
	nodo *sig;
};

void inicializarcola(nodo *&frente,nodo *&fondo);

void insertar(nodo *&frente, nodo *&fondo,registro articulos);

void listar(nodo *&frente);

void eliminar(nodo *&frente,nodo *&fondo);

main()
{
	nodo *frente,*fondo,*p;
	registro articulos;
	int n;
	
	inicializarcola(frente,fondo);
	printf("\nIngrese la cantidad de articulos: ");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		printf("Ingrese el codigo del articulo: ");
        scanf("%d",&articulos.codigo);
        printf("Ingrese el importe del articulo: ");
        scanf("%f",&articulos.importe);
        insertar(frente,fondo,articulos);
	}
	listar(frente);
	printf("\n");
	eliminar(frente,fondo);
	printf("\n");
	listar(frente);
}

void inicializarcola(nodo *&frente,nodo *&fondo)
{
     frente=NULL;
     fondo=NULL;
}

void insertar(nodo *&frente, nodo *&fondo,registro articulos)
{
     nodo *p;
     
     p=new nodo;
     
     if (p!=NULL)
     {
           p->info.codigo=articulos.codigo;
           p->info.importe=articulos.importe;
           p->sig=NULL;
           
		   if (frente==NULL)
                 frente=p;
           else
                 fondo->sig=p;
                 fondo=p;
     }  
     else
           printf("ERROR - COLA LLENA");
}

void listar(nodo *&frente)
{
	nodo *p;
		
	p=frente;
    while (p!=0)
    {
          printf("Codigo: %d\n",p->info.codigo);
          printf("Importe: %.2f\n",p->info.importe);
          printf("\n");
          p=p->sig;
    }
    getch();
}

void eliminar(nodo *&frente,nodo *&fondo)
{
	nodo *p;
	int codigo;
	registro aux[50];
	int i=0,n;
	bool b=false;
		
	p=frente;
	printf("\nIngrese el codigo de articulo que desea eliminar: ");
	scanf("%d",&codigo);
    while (p!=0)
    {
        if(codigo!=p->info.codigo)
        {
			aux[i].codigo=p->info.codigo;
          	aux[i].importe=p->info.importe;
          	i++;
          	b=true;
		}
          p=p->sig;
    }
    if(b==true)
    {
    	delete frente;
    	delete fondo;
    	n=i;
    	inicializarcola(frente,fondo);
    	for(i=0;i<n;i++)
    	{
    		insertar(frente,fondo,aux[i]);
    	}
    }
    getch();
}
