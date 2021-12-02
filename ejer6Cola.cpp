#include<conio.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

//Paz Exequiel 1k5 legajo 53382

/*En una empresa de servicios de telefonía celular se registra la información de los clientes a ser
atendidos en una estructura de cola, de cada uno de los N clientes se ingresa la siguiente
información:
? Número de atención.
? Número de celular.
? Tipo de reclamo: (F: Facturación, C:Compra, T:Técnico)

SE PIDE:

a) Ingresar los datos en la cola dinámica.
b) Mostrar los datos del próximo cliente a atender y borrarlo de la cola.
c) Indicar el porcentaje de clientes que fueron por problemas técnicos.*/


struct registro
{
	int numeroAtencion;
	char numeroCelular[11];
	char tipoReclamo;
};

struct nodo
{
	registro info;
	nodo *sig;
};

void inicializarcola(nodo *&frente,nodo *&fondo);

void insertar(nodo *&frente, nodo *&fondo,registro clientes);

void VaciarCola(nodo *&frente, nodo *&fondo);

main()
{
	nodo *frente,*fondo,*p;
	registro clientes;
	int n,numero=0,celular;
	
	inicializarcola(frente,fondo);
	printf("\nIngrese la cantidad de clientes: ");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		numero=numero+1;
		printf("\nIngrese el numero de telefono: ");
		scanf("%s",&clientes.numeroCelular);
		do
		{
			printf("Ingrese el Tipo de reclamo: (F: Facturacion, C:Compra, T:Tecnico): ");
			_flushall();
			clientes.tipoReclamo=getch();
			if(clientes.tipoReclamo<='z' && clientes.tipoReclamo>='a')clientes.tipoReclamo=clientes.tipoReclamo-'a'+'A';
			if(clientes.tipoReclamo!='F' && clientes.tipoReclamo!='C' && clientes.tipoReclamo!='T')
			printf("\nError la opcion no es valida\n\n");
		}while(clientes.tipoReclamo!='F' && clientes.tipoReclamo!='C' && clientes.tipoReclamo!='T');
		clientes.numeroAtencion=numero;
		printf("\nNumero de atencion: %d",clientes.numeroAtencion=numero);		
		insertar(frente,fondo,clientes);
	}
	system("cls");
	printf("\n");
	VaciarCola(frente, fondo);
	getch();
}

void inicializarcola(nodo *&frente,nodo *&fondo)
{
     frente=NULL;
     fondo=NULL;
}

void insertar(nodo *&frente, nodo *&fondo,registro clientes)
{
    nodo *p;
    
    p=new nodo;
     
    if (p!=NULL)
	{
		p->info.numeroAtencion=clientes.numeroAtencion;
		strcpy(p->info.numeroCelular,clientes.numeroCelular);
		p->info.tipoReclamo=clientes.tipoReclamo;
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

void VaciarCola(nodo *&frente, nodo *&fondo)
{
	nodo *p;
	p = frente;		
	frente = frente->sig;
	printf("Numero de atencion: %d\n",p->info.numeroAtencion);
	printf("numero de telefono: %s\n",p->info.numeroCelular);
	if (p->info.tipoReclamo=='F')printf("Tipo de reclamo: Facturacion\n");
	if (p->info.tipoReclamo=='C')printf("Tipo de reclamo: Compra\n");
	if (p->info.tipoReclamo=='T')printf("Tipo de reclamo: Tecnico\n");
	delete p;
	while(frente != NULL)
	{
		p = frente;		
		frente = frente->sig;
		printf("\n");         
		printf("\nSiguiente cliente: \n");
		printf("Numero de atencion: %d\n",p->info.numeroAtencion);
		printf("numero de telefono: %s\n",p->info.numeroCelular);
		if (p->info.tipoReclamo=='F')printf("Tipo de reclamo: Facturacion\n");
		if (p->info.tipoReclamo=='C')printf("Tipo de reclamo: Compra\n");
		if (p->info.tipoReclamo=='T')printf("Tipo de reclamo: Tecnico\n"); 
		getch();
		delete p;
	}
	
	frente = NULL;
	fondo = NULL;	
	if(frente==NULL)printf("\nCola vacia!\n");
	
}

