#include<conio.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

//Paz Exequiel 1k5 legajo 53382

/*Un médico registra la información de sus pacientes en una estructura dinámica de pila, que
posee los siguientes campos:
? Nombre
? Teléfono
? Edad
a) Ingresar la información de N pacientes.
b) Indicar los datos del paciente con mayor edad.*/

struct registro
{
	char telefono[20],nombre[50];
	int edad;
};

struct nodo
{
	registro info;
	nodo *sig;
};

void inicializar(nodo *&frente);

void insertar(nodo *&frente, registro pacientes);

void listar(nodo *&frente);

void mayor(nodo *&frente);

main()
{
	nodo *frente,*p;
	registro pacientes;
	char salir;
	
	inicializar(frente);
	
	do
	{
		printf("\nIngrese Nombre del paciente: ");
		_flushall();
		gets(pacientes.nombre);
		printf("\nEdad: ");
		scanf("%d",&pacientes.edad);
		printf("\nTelefono: ");
		scanf("%s",&pacientes.telefono);
		insertar(frente,pacientes);
		printf("\n\nIngresar otro paciente? S/N");
		printf("\nOpcion: ");
		salir=getch();
		if(salir<='z' && salir >='a')salir=salir-'a'+'A';
		system("cls");
	}while(salir=='S');
	
	printf("\nDatos de los pacientes: \n");
	listar(frente);
	mayor(frente);	
	
}

void inicializar(nodo *&frente)
{
     frente=NULL;
}

void insertar(nodo *&frente, registro pacientes)
{
     nodo *p;
     
     p=new nodo;
     
     if (p!=NULL)
     {
           p->info=pacientes;
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
          printf("Nombre: %s\n",p->info.nombre);
          printf("Edad: %d\n",p->info.edad);
          printf("Telefono: %s\n",p->info.telefono);
          printf("\n");
          p=p->sig;
    }
    getch();
}

void mayor(nodo *&frente)
{
	nodo *p;
	registro aux;
	int may=0;
	
	p=frente;
    while (p!=NULL)
    {
		if(p->info.edad>may)
        {
        	may=p->info.edad; 
			strcpy(aux.nombre,p->info.nombre);
			aux.edad= p->info.edad;
			strcpy(aux.telefono,p->info.telefono);
		}
          p=p->sig;
    }
    printf("\nLos datos del Paciente con mayor edad son: \n");
    printf("Nombre: %s\n",aux.nombre);
    printf("Edad: %d\n",aux.edad);
    printf("Telefono: %s\n",aux.telefono);
    printf("\n");
    getch();
}
