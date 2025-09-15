#include<stdio.h>
#include<string.h>
#include <stdbool.h>


struct empleado{
char nombre[50];	
int contrasenia;
char apellido[50];
int sueldo;
int sueldoreal;
int horas_trabajadas;
char rol[50];
int DNI;
};


struct producto{
int id_producto,stock;	
char nombre[50];
int precio;
char categoria[20];	
};


struct pedido{
int numero_pedido;
int idproducto;
int cantidad;
int realizado;
int marcado;
int pagado;
int envio;
int precio;
};

struct clientes
{
int id_cliente;
char nombre[50];
char apellido[50];
char direccion[60];
int idpedido;
int n_fiscal;	
};



struct ventas{
int monto;
int id_ventas;
int idpedido;
int venta_hecha;
int dia;
char mes[20];
int anio;
int id_cliente;	
};

int main()
{
struct empleado emp[50];
struct producto prc[50];
struct pedido ped[50];
struct ventas ven[50];
struct clientes clt[50];
int valorcorrecto=0;
int pasohecho=0, opcion, intento=0,pasohecho2=0, pasohecho3=0,pasohecho4=0,pasohecho5=0;
int empleadocreado=0,contrasenia_ingresada=0;
int opcionempleados,opcionproductos,opcionpedidos,opcionventas;
bool salir=false,saliremp=false,salirpro=false,salirped=false,salirven=false;
char nombre_ingresado[50],apellido_ingresado[50];
int exitoso=0;
int usuariocreado=0,pedidocreado=0,productocreado=0,ventacreada=0,clientecreado=0;;
int encontrado=0,precio=0,idbuscar=0,cantidadproducto=0,total=0,suma=0,pago=0,vuelto=0;
int i=0,j=0,x=0,y=0,g=0,h=0,k=0;
int horamaxima=40,promediosueldos=0,mayorsueldo=-1,promediototalsueldos=0, buscarpedido=0;
char nombremayorsueldo[50],apellidomayorsueldo[50];
char pagoexitoso=false;
int pedidos_pendientes=0, enviopedido;
int pagorecaudado=0, sumaventa=0,promedioventa=0;
char rolactual[50];
int encontrado0=0;
do
{
	
if(usuariocreado==1)
{
do
{
printf("Una vez cargado el usuario, tendra que ingresar los siguientes datos:\n");	
printf("\nNOMBRE:");
scanf("%s",nombre_ingresado);
printf("\nAPELLIDO:");
scanf("%s",apellido_ingresado);
printf("\nCONTRASENIA:");
valorcorrecto=0;
do

{

if(scanf("%d",&contrasenia_ingresada) != 1)

{

printf("ERROR: ingrese un numero\n");

fflush(stdin);

}

else

{

valorcorrecto=1;



}

}

while(valorcorrecto==0);
for(i=0;i<empleadocreado;i++)
{
if(strcmp(nombre_ingresado,emp[i].nombre) != 0 || strcmp(apellido_ingresado,emp[i].apellido) != 0 
|| contrasenia_ingresada != emp[i].contrasenia)
{
intento++;
}
else if(strcmp(nombre_ingresado,emp[i].nombre) == 0 && strcmp(apellido_ingresado,emp[i].apellido) == 0 
&& contrasenia_ingresada == emp[i].contrasenia)
{
exitoso=1;
strcpy(rolactual,emp[i].rol);
break;
}
}
if(intento>0)
{
printf("ERROR, intento[%d]\n",intento);	
}
if(exitoso==1)
{
break;	
}
}
while(intento<3);
}

if(intento==3)
{
printf("CONTRASEÑA INCORRECTA\n");
printf("ACCESO RESTRINGIDO\n");
break;
}

else
{
if(exitoso==1)
{
printf("SESION INICIADA\n");
printf("HOLA, %s %s\n",nombre_ingresado,apellido_ingresado);
usuariocreado=0;
}
if(pasohecho==0)
{	
printf("¡Hola!\n");
printf("¡Primero ingrese un empleado!\n");	
}

printf("====================\n");
printf("       MENU       \n");
printf("====================\n");
printf("[1]     SALIR     ||\n");
if(pasohecho==0)
{
printf("[2]==>EMPLEADOS<==||\n");
}
else if(strcmp(rolactual, "gerente")==0)
{
printf("[2]   EMPLEADOS   ||\n");
}
if(pasohecho==1 && pasohecho2==0)
{
printf("[3]==>PRODUCTOS<==||\n");
}
else
{
printf("[3]   PRODUCTOS   ||\n");
}
if(pasohecho2==1 && pasohecho3==0 && pasohecho5==0)
{
printf("[4] ==>PEDIDOS<== ||\n");	
}
else
{
printf("[4]   PEDIDOS     ||\n");
}
if(pasohecho3==1 && pasohecho4==0)
{
printf("[5]  ==>VENTAS<== ||\n");
}
else
{
printf("[5]   VENTAS      ||\n");
}
printf("[6]   PASOS       ||\n");
printf("====================\n");
printf("\nOPCION:");
valorcorrecto=0;
do

{

if(scanf("%d",&opcion) != 1)

{

printf("ERROR: ingrese un numero\n");

fflush(stdin);

}

else

{

valorcorrecto=1;


}

}

while(valorcorrecto==0);



switch(opcion)
{
case 1:
	{
	printf("Ha elegido salir...\n");
	salir=true;	
	break;	
	}
case 2:
do
{
printf("============================\n");
printf("     MENU DE EMPLEADOS\n");
printf("============================\n");
printf("[1]       VOLVER           ||\n");
if(pasohecho==0)
{
printf("[2]==>REGISTRAR EMPLEADO<==||\n");
}
else if(pasohecho==1)
{
printf("[2]  REGISTRAR EMPLEADO   ||\n");		
}
printf("[3]    LISTA DE EMPLEADOS  ||\n");
printf("[4]   PROMEDIO DE SUELDOS  ||\n");
printf("[5]    ¿QUIEN GANA MAS?    ||\n");
printf("============================\n");
printf("\nOPCION:");
valorcorrecto=0;
do

{

if(scanf("%d",&opcionempleados) != 1)

{

printf("ERROR: ingrese un numero\n");

fflush(stdin);

}

else

{

valorcorrecto=1;


}

}

while(valorcorrecto==0);




switch(opcionempleados)
{
case 1: 
	{
    saliremp=true;
    break;
	}
case 2:
	{
	if(empleadocreado==50)
	{
	printf("No se puede ingresar mas empleados\n");	
	}
	else
	{
	printf("Ahora, vamos a crear un empleado:\n");
	printf("NOMBRE:");
	scanf("%s",emp[i].nombre);
	printf("\nAPELLIDO:");
	scanf("%s",emp[i].apellido);
	printf("\nDNI:");
	scanf("%d",&emp[i].DNI);
	if(pasohecho==0)
	{
	do
	{
	printf("\nROL (gerente):");
	scanf("%s",&emp[i].rol);
	if(strcmp(emp[i].rol,"gerente")!=0)
	{
	printf("Tiene que ingresar un gerente primero\n");
	}
	else if(strcmp(emp[i].rol,"gerente")==0)
	{
	encontrado0=1;	
	}
	}
	while(encontrado0==0);
	}
	else
	{
	printf("\nROL (gerente, vendedor, almacenista):");
	scanf("%s",&emp[i].rol);	
	}
	printf("\nCONTRASENIA:");
	
	valorcorrecto=0;
do

{

if(scanf("%d",&emp[i].contrasenia) != 1)

{

printf("ERROR: ingrese numeros\n");

fflush(stdin);

}

else

{
valorcorrecto=1;
}

}
while(valorcorrecto==0);
	printf("\nSUELDO SEMANAL:");
	valorcorrecto=0;
do

{
if(scanf("%d",&emp[g].sueldo) != 1)

{

printf("ERROR: ingrese un numero\n");

fflush(stdin);

}

else

{

valorcorrecto=1;


}

}

while(valorcorrecto==0);
valorcorrecto=0;
	do
	{
	printf("\nHORAS TRABAJADAS(maximo %dhr):",horamaxima);
	valorcorrecto=0;
do

{

if(scanf("%d",&emp[g].horas_trabajadas) != 1)

{

printf("ERROR: ingrese un numero\n");

fflush(stdin);

}

else

{

valorcorrecto=1;

}

}

while(valorcorrecto==0);
	}
	while(emp[i].horas_trabajadas>horamaxima);
	emp[i].sueldoreal=(emp[i].sueldo/horamaxima)*emp[i].horas_trabajadas;
	pasohecho=1;
	empleadocreado++;
	promediosueldos+=emp[i].sueldoreal;
	i++;
	printf("======== USUARIO CARGADO EXITOSAMENTE =======\n");
	usuariocreado=1;	
	}
	break;
	}
case 3:
	{
	if(pasohecho==0)
	{
	printf("¡Primero tiene que crear un empleado!\n");	
	}
	else
	{
	printf("Ahora se mostraran a continuacion los empleados disponibles:\n");
	for(i=0;i<empleadocreado;i++)
	{
	printf("======== EMPLEADO [%d] ========\n",i+1);
	printf("NOMBRE: [%s]\n",emp[i].nombre);
	printf("APELLIDO: [%s]\n",emp[i].apellido);
	printf("DNI: [%d]\n",emp[i].DNI);
	printf("CONTRASENIA: [%d]\n",emp[i].contrasenia);
	printf("HORAS TRABAJADAS: [%d]\n",emp[i].horas_trabajadas);
	printf("SUELDO (En base a horas): [%d]\n",emp[i].sueldoreal);
	printf("==============================\n");
	}	
	}	
	break;
	}
case 4:
	{
	if(pasohecho==0)
	{
	printf("¡Primero tiene que crear un empleado!\n");	
	}
	if(pasohecho2==1)
	{
	printf("¡Primero tiene que registrar un producto\n");	
	}
	else
	{
	}
	promediototalsueldos=promediosueldos/empleadocreado;	
	printf("========== PROMEDIO DE SUELDOS ==========\n");
	printf("El promedio de todos los sueldos es:[$ %d]\n",promediototalsueldos);	
	printf("=========================================\n");		
	break;
	}
case 5:
	{
	if(pasohecho==0)
	{
	printf("¡Primero tiene que crear un empleado!\n");	
	}
	else
	{
	mayorsueldo=emp[0].sueldoreal;
	strcpy(nombremayorsueldo, emp[0].nombre);
	strcpy(apellidomayorsueldo, emp[0].apellido);
	for(i=0;i<empleadocreado;i++)
	{
	if(emp[i].sueldoreal>mayorsueldo)
	{
	mayorsueldo=emp[i].sueldoreal;
	strcpy(nombremayorsueldo,emp[i].nombre);
	strcpy(apellidomayorsueldo,emp[i].apellido);		
	}	
	}
	printf("========= MAYOR SUELDO =========\n");
	printf("El empleado llamado: [%s] [%s]\n",nombremayorsueldo,apellidomayorsueldo);
	printf("Con el sueldo de:[$%d]\n",mayorsueldo);
	printf("================================\n");	
	}		
	break;	
	}
}
}
while(saliremp==false);
break;

case 3:
{
if(pasohecho==0)
{
printf("¡Primero tiene que ingresar un empleado!\n");	
}
	else
	{
	total = 0;
	do
	{
printf("=========================\n");
printf("    MENU DE PRODUCTOS\n");
printf("=========================\n");
printf("[1]       VOLVER       ||\n");
if(pasohecho2==0)
{
printf("[2]==>CREAR PRODUCTO<==||\n");
}
else if(strcmp(rolactual, "gerente")==0 || strcmp(rolactual, "almacenista")==0)
{
printf("[2]   CREAR PRODUCTO   ||\n");
}
printf("[3]  AGREGAR PRODUCTO  ||\n");

if(strcmp(rolactual, "gerente")==0 || strcmp(rolactual, "almacenista")==0)
{
printf("[4]    INVENTARIO      ||\n");
}
printf("[5]  	 TOTAL         ||\n");
if(strcmp(rolactual, "gerente")==0 || strcmp(rolactual, "almacenista")==0)
{
printf("[6]    RECAUDADO       ||\n");
}
printf("=========================\n");
printf("\nOPCION: ");
valorcorrecto=0;
do

{

if(scanf("%d",&opcionproductos) != 1)

{

printf("ERROR: ingrese un numero\n");

fflush(stdin);

}

else

{

valorcorrecto=1;


}

}

while(valorcorrecto==0);

switch(opcionproductos)
{
	case 1:
salirpro=true;
	break;	

	case 2:
if(pasohecho==1)
{
printf("Bien, vamos a crear un producto\n");
}
else
{	
}
printf("A continuacion tendra que ingresar los siguientes datos:\n");	
printf("\nID:");
valorcorrecto=0;
do

{

if(scanf("%d",&prc[x].id_producto) != 1)

{

printf("ERROR: ingrese un numero\n");

fflush(stdin);

}

else

{

valorcorrecto=1;


}

}

while(valorcorrecto==0);
printf("\nNOMBRE:");
getchar();
fgets(prc[x].nombre, sizeof(prc[x].nombre), stdin);
prc[productocreado].nombre[strcspn(prc[productocreado].nombre, "\n")] = '\0';
printf("\nCATEGORIA:");
scanf("%s",&prc[x].categoria);
printf("\nSTOCK:");
valorcorrecto=0;
do
{

if(scanf("%d",&prc[x].stock) != 1)

{

printf("ERROR: ingrese un numero\n");

fflush(stdin);

}

else

{

valorcorrecto=1;

}

}

while(valorcorrecto==0);
printf("\nPRECIO:");
valorcorrecto=0;
do

{

if(scanf("%d",&prc[x].precio) != 1)

{

printf("ERROR: ingrese un numero\n");

fflush(stdin);

}

else

{

valorcorrecto=1;

}

}

while(valorcorrecto==0);
productocreado++;
x++;
pasohecho2=1;
	break;	

	case 3:
if(pasohecho2==0)
{
printf("¡Primero, tiene que ingresar un producto!\n");	
}
else
{
printf("Ha elegido agregar un producto:\n");
printf("Escriba los siguientes datos:\n");
valorcorrecto=0;
do
{
printf("\nID DEL PRODUCTO:");
do

{

if(scanf("%d",&idbuscar) != 1)

{

printf("ERROR: ingrese un numero\n");

fflush(stdin);

}

else

{

valorcorrecto=1;

}

}

while(valorcorrecto==0);

for(x=0;x<productocreado;x++)
{
if(idbuscar==prc[x].id_producto)
{
	if(prc[x].stock==0)
	{
	printf("No se encuentra stock de ese producto\n");
	break;
	}
		else
		{
		printf("El producto se ha encontrado\n");
		printf("======== (PRODUCTO) ========\n");
		printf("NOMBRE: [%s]\n",prc[x].nombre);
		printf("PRECIO: [$%d]\n",prc[x].precio);
		printf("STOCK: [%d]\n",prc[x].stock);
		printf("ID: [%d]\n",prc[x].id_producto);
		printf("============================\n");
		printf("¿Cuantas unidades desea?\n");
			do
			{
			printf("\nUNIDADES:");
			valorcorrecto=0;
				do
				{
					if(scanf("%d",&cantidadproducto) != 1)
					{
					printf("ERROR: ingrese un numero\n");
					fflush(stdin);
					}	
					else
					{
					valorcorrecto=1;
					}
				}
				while(valorcorrecto==0);
			}
			while(cantidadproducto>prc[x].stock);
		prc[x].stock-=cantidadproducto;
		suma=prc[x].precio*cantidadproducto;
		total+=suma;
		pagoexitoso=false;
		break;
		}
}
}
}
while(idbuscar!=prc[x].id_producto);
}
break;	

case 4:
if(pasohecho2==0)
{
printf("¡Primero, tiene que ingresar un producto!\n");	
}
else
{
	struct producto aux;

for(x=0;x<productocreado;x++)
{
for(h=0;h<productocreado;h++)    
{
if(strcmp(prc[x].categoria,prc[h].categoria) > 0)
{
aux = prc[x];
prc[x] = prc[h];
prc[h] = aux;
}
}    
}
	char categoriaactual[50]="";
	
	printf("A continuacion se mostraran los productos disponibles:\n");
		for(x=0;x<productocreado;x++)
		{
		if(strcmp(categoriaactual,prc[x].categoria) != 0)
		{
		strcpy(categoriaactual,prc[x].categoria);
		printf("====== (%s) ======\n",categoriaactual);	
		}
		printf("===== PRODUCTO [%d] ====\n",x+1);	
		printf("NOMBRE: [%s]\n",prc[x].nombre);
		printf("PRECIO: [$%d]\n",prc[x].precio);
		printf("STOCK: [%d]\n",prc[x].stock);
		printf("========================\n");
		}
}
	break;	

	case 5:
if(pasohecho2==0)
{
printf("¡Primero, tiene que ingresar un producto!\n");	
}
else
{
printf("A continuacion se mostrará el total:\n");
printf("======= (TOTAL) =======\n");
printf("TOTAL:[$%d]\n",total);
printf("=======================\n");
printf("Cuanto desea pagar:\n");
valorcorrecto=0;
	do
	{
	printf("\nPAGO:");
	do

{

if(scanf("%d",&pago) != 1)

{

printf("ERROR: ingrese un numero\n");

fflush(stdin);

}

else

{

valorcorrecto=1;

}

}

while(valorcorrecto==0);
	vuelto=pago-total;
		if(vuelto<0)
		{
		printf("El pago es menor al producto\n");
		printf("Falta:[%d]\n",vuelto);		
		}
			else if(vuelto==0)
			{
			printf("No hay vuelto\n");
			printf("=== PRODUCTOS ENTREGADOS EXITOSAMENTE ===\n");	
			pagoexitoso=true;
			pagorecaudado+=pago;	
			}
				else if(vuelto>0)
				{
				printf("El vuelto es: [%d]\n",vuelto);
				printf("=== PRODUCTOS ENTREGADOS EXITOSAMENTE ===\n");
				pagoexitoso=true;
				pagorecaudado+=pago;	
				}
	}	
	while(pagoexitoso==false);
}
	break;
	
	case 6:
	if(pasohecho2==0)
	{
	printf("¡Primero, tiene que ingresar un producto!\n");	
	}
	else
	{
	printf("El total recaudado es:\n");
	printf("=== (RECAUDACION) ===\n");
	printf("RECAUDADO: [%d]\n",pagorecaudado);
	printf("=====================\n");
	break;		
}
	}
}
	while(salirpro==false);
	}
break;
	}	

case 4:
	{	
if(pasohecho==0)
{
printf("¡Primero tiene que ingresar un empleado!\n");
break;	
}
if(pasohecho==1 && pasohecho2==0)
{
printf("¡Primero tiene que crear un producto!\n");
break;	
}

do
{
printf("===========================\n");
printf("     MENU DE PEDIDOS\n");
printf("===========================\n");
printf("[1]        VOLVER         ||\n");
if(pasohecho3==0)
{
printf("[2] ==>CREAR UN PEDIDO<== ||\n");	
}
else if(strcmp(rolactual, "gerente")==0 || strcmp(rolactual, "almacenista")==0)
{
printf("[2]   CREAR UN PEDIDO     ||\n");
}
else if(strcmp(rolactual, "gerente")==0 || strcmp(rolactual, "almacenista")==0)
{
printf("[3]    MARCAR PEDIDO      ||\n");
}
else if(strcmp(rolactual, "gerente")==0 || strcmp(rolactual, "almacenista")==0)
{
printf("[4] PEDIDOS PENDIENTES    ||\n");
}
if(pasohecho3==1 && pasohecho5==0)
{
printf("[5]==>REGISTRAR CLIENTE<==||\n");	
}
else if(strcmp(rolactual, "gerente")==0 || strcmp(rolactual, "vendedor")==0)
{
printf("[5]   REGISTRAR CLIENTE   ||\n");
}
printf("===========================\n");
printf("\nOPCION:");
valorcorrecto=0;
do

{

if(scanf("%d",&opcionpedidos) != 1)
{
printf("ERROR: ingrese un numero\n");
fflush(stdin);
}

else

{

valorcorrecto=1;


}

}

while(valorcorrecto==0);
switch(opcionpedidos)
{
case 1:
salirped=true;
break;

case 2:
if(pasohecho2==1)
{
printf("Bien, vamos a crear un pedido\n");
}
else
{	
}
printf("A continuacion tendra que ingresar los siguientes datos:\n");
printf("\nID PEDIDO:");
valorcorrecto=0;
do

{

if(scanf("%d",&ped[j].numero_pedido) != 1)

{

printf("ERROR: ingrese un numero\n");

fflush(stdin);

}

else

{

valorcorrecto=1;

}

}

while(valorcorrecto==0);
		do
		{
		printf("\nID DEL PRODUCTO:");
		valorcorrecto=0;
			do

			{
				if(scanf("%d",&ped[j].idproducto) != 1)
				{
				printf("ERROR: ingrese un numero\n");
				fflush(stdin);
				}
				else
				{
				valorcorrecto=1;
				}
			}
			while(valorcorrecto==0);
		printf("¿El pedido tiene envio?\n");
		printf("[1] SI\n");
		printf("[2] NO\n");
		printf("\nOPCION:");
		valorcorrecto=0;
			{
				if(scanf("%d",&enviopedido) != 1)
				{
				printf("ERROR: ingrese un numero\n");
				fflush(stdin);
				}
				else
				{
				valorcorrecto=1;
				}
			}
			while(valorcorrecto==0);
		switch(enviopedido)
		{	
		case 1:
		ped[j].envio=1;
		break;
		case 2:
		ped[j].envio=0;
		break;	
		}
		
			for(x=0;x<productocreado;x++)
			{
				if(ped[j].idproducto==prc[x].id_producto)
				{
					if(prc[x].stock==0)
					{
					printf("El producto ingresado, no tiene stock, ingrese otro producto:\n");
					break;
					}
						else
						{		
				encontrado=1;
					do
					{	
					printf("\nCANTIDAD DEL PRODUCTO:");
					valorcorrecto=0;
						do

						{

							if(scanf("%d",&ped[j].cantidad) != 1)

							{

							printf("ERROR: ingrese un numero\n");
							fflush(stdin);

							}

							else
							{
						valorcorrecto=1;
							}

						}

						while(valorcorrecto==0);
					}
					while(ped[j].cantidad > prc[x].stock);
			
						if(encontrado==1)
						{		
						prc[x].stock-=ped[j].cantidad;	
						precio=prc[x].precio;
						}	
				}	}
			}
		}	
		while(encontrado==0);
	ped[j].precio=precio*ped[j].cantidad;
	pedidocreado++;
	pasohecho3=1;
	ped[j].realizado=0;
	j++;
break;	

case 3:
encontrado=0;
if(pasohecho3==0)
{
printf("¡Primero, tiene que ingresar un pedido!\n");	
}
else
{
printf("Ha elegido marcar un pedido:\n");
printf("Ingrese el siguiente dato:\n");
do
{
printf("\nID PEDIDO:");
valorcorrecto=0;
do

{

if(scanf("%d",&buscarpedido) != 1)

{

printf("ERROR: ingrese un numero\n");

fflush(stdin);

}

else

{

valorcorrecto=1;

}

}

while(valorcorrecto==0);
	for(j=0;j<pedidocreado;j++)
	{
		if(buscarpedido==ped[j].numero_pedido)
		{
			if(ped[j].pagado==1)
			{
			printf("====== PEDIDO MARCADO EXITOSAMENTE ======\n");
			ped[j].marcado=1;
			encontrado=1;
			break;	
			}
				else if(ped[j].pagado==0)
				{
				printf("El pedido no esta pagado aún\n");
				break;	
				}	
		}	
	}
}
while(encontrado==0);
}
break;	

case 4:
if(pasohecho3==0)
{
printf("¡Primero, tiene que ingresar un pedido!\n");	
}
else
{
pedidos_pendientes=0;

	
printf("A continuacion se mostraran los pedidos pendientes\n");

	for(j=0;j<pedidocreado;j++)
	{
		if(ped[j].marcado==0)
		{
		pedidos_pendientes++;
		printf("========= (PEDIDO [%d]) ========\n",j+1);
		printf("NUMERO DE PEDIDO: [%d]\n",ped[j].numero_pedido);
		printf("ID DE PRODUCTO: [%d]\n",ped[j].idproducto);
		printf("CANTIDAD DEL PRODUCTO: [%d]\n",ped[j].cantidad);
		printf("ENVIO: [%d]\n",ped[j].envio);
		printf("================================\n");
		}
	}
		if(pedidos_pendientes==0)
		{
		printf("¡No hay pedidos pendientes!\n");	
		}
}
break;	

case 5:
encontrado=0;
valorcorrecto=0;
if(pasohecho3==0)
{
printf("¡Primero, tiene que ingresar un pedido!\n");	
}
else
{
printf("Bien, vamos a crear un cliente\n");
printf("A continuacion tendra que ingresar los siguientes datos del cliente:\n");
printf("\nID CLIENTE:");
scanf("%d",&clt[k].id_cliente);
printf("\nNOMBRE:");
scanf("%s",&clt[k].nombre);
printf("\nAPELLIDO:");
scanf("%s",&clt[k].apellido);
printf("\nDIRECCION:");
scanf("%s",&clt[k].direccion);
printf("\nNUMERO FISCAL:");
scanf("%d",&clt[k].n_fiscal);
	do
	{
	printf("\nID PEDIDO:");
	do

{

if(scanf("%d",&clt[k].idpedido) != 1)

{

printf("ERROR: ingrese un numero\n");

fflush(stdin);

}

else

{

valorcorrecto=1;


}

}

while(valorcorrecto==0);
		for(j=0;j<pedidocreado;j++)
		{
			if(clt[k].idpedido==ped[j].numero_pedido)
			{
				if(ped[j].marcado==1)
				{
				printf("El pedido ya se encuentra marcado\n");
				break;	
				}
				else
				{	
				encontrado=1;
				}
			}
			else
			{
			printf("El numero del pedido no se encuentra\n");
			}	
		}
	}
	while(encontrado==0);
	k++;
	clientecreado++;
}
break;	
}
}
while(salirped==false);
break;	
	}

case 5:
{	
if(pasohecho==0)
{
printf("¡Primero tiene que ingresar un empleado!\n");	
break;	
}
if(pasohecho==1 && pasohecho2==0)
{
printf("¡Primero tiene que crear un producto!\n");	
break;	
}
if(pasohecho2==1 && pasohecho3==0)
{
printf("¡Primero tiene que crear un pedido!\n");
break;	
}
do
{
printf("==========================\n");
printf("     MENU DE VENTAS\n");
printf("==========================\n");
printf("[1]       VOLVER        ||\n");
if(pasohecho4==0)
{
printf("[2]  ==>CREAR VENTA<==  ||\n");	
}
else if(strcmp(rolactual, "gerente")==0 || strcmp(rolactual, "vendedor")==0)
{
printf("[2]     CREAR VENTA     ||\n");
}
else if(strcmp(rolactual, "gerente")==0 || strcmp(rolactual, "vendedor")==0)
{
printf("[3]  VENTAS DISPONIBLES ||\n");
}
else if(strcmp(rolactual, "gerente")==0)
{
printf("[4]      PROMEDIO       ||\n");
}
printf("==========================\n");
printf("\nOPCION:");
valorcorrecto=0;
do

{

if(scanf("%d",&opcionventas) != 1)

{

printf("ERROR: ingrese un numero\n");

fflush(stdin);

}

else

{

valorcorrecto=1;


}

}

while(valorcorrecto==0);

switch(opcionventas)
{
case 1:
salirven=true;
break;	

case 2:

if(pasohecho3==1)
{
printf("Bien, vamos a crear una venta\n");
}
else
{	
}
encontrado=0;
pagoexitoso=false;
printf("A continuacion, ingrese los siguientes datos:\n");
printf("\nID DE VENTA:");
valorcorrecto=0;
do

{

if(scanf("%d",&ven[g].id_ventas) != 1)

{

printf("ERROR: ingrese un numero\n");

fflush(stdin);

}

else

{

valorcorrecto=1;

}

}
while(valorcorrecto==0);
encontrado=0;
do
{
printf("\nID DEL CLIENTE:");
valorcorrecto=0;
do

{

if(scanf("%d",&ven[g].id_cliente) != 1)

{

printf("ERROR: ingrese un numero\n");

fflush(stdin);

}

else

{

valorcorrecto=1;

}

}
while(valorcorrecto==0);

for(k=0;k<clientecreado;k++)
{
if(ven[g].id_cliente==clt[k].id_cliente)
{
printf("El cliente se encontró\n");	
encontrado=1;
}
else
{
printf("El cliente no se encontró\n");	
}	
}
}
while(encontrado==0);


	do
	{
	printf("\nID DEL PEDIDO:");
	valorcorrecto=0;
	do

	{

		if(scanf("%d",&ven[g].idpedido) != 1)

		{

		printf("ERROR: ingrese un numero\n");

		fflush(stdin);

		}

		else

		{

		valorcorrecto=1;

		}

	}

	while(valorcorrecto==0);
	encontrado=0;
		for(j=0;j<pedidocreado;j++)
		{
			if(ven[g].idpedido==ped[j].numero_pedido)
			{
				if(ped[j].marcado==1)
				{
				printf("El pedido ya esta marcado\n");	
				break;
				}
				else
				{	
				printf("==== PEDIDO ENCONTRADO ====\n");
				encontrado=1;
				ped[j].pagado=1;
				ven[g].monto=ped[j].precio;
				}
									
			}	
		}
	}
	while(encontrado==0);
	printf("MONTO: [%d]\n", ven[g].monto);
	printf("¿Cuanto va a pagar?\n");
	do
	{
	printf("\nPAGO:");
	scanf("%d",&pago);
		do
		{
			if(scanf("%d",&pago) != 1)
			{
			printf("ERROR: ingrese un numero\n");
			fflush(stdin);
			}
			else
			{
			valorcorrecto=1;
			}
		}
		while(valorcorrecto==0);
	vuelto=pago-ven[g].monto;
		if(vuelto<0)
		{
		printf("El pago es menor al producto\n");
		printf("Falta:[%d]\n",vuelto);		
		}
			else if(vuelto==0)
			{
			printf("No hay vuelto\n");
			printf("=== PRODUCTOS ENTREGADOS EXITOSAMENTE ===\n");	
			pagoexitoso=true;
			pagorecaudado+=ven[g].monto;	
			}
				else if(vuelto>0)
				{
				printf("El vuelto es: [%d]\n",vuelto);
				printf("=== PRODUCTOS ENTREGADOS EXITOSAMENTE ===\n");
				pagoexitoso=true;
				pagorecaudado+=ven[g].monto;	
				}
			
		}	
		while(pagoexitoso==false);
	printf("======== (FECHA) ========\n");
	printf("\nANIO:");
	valorcorrecto=0;
	do

{

if(scanf("%d",&ven[g].anio) != 1)

{

printf("ERROR: ingrese un numero\n");

fflush(stdin);

}

else

{

valorcorrecto=1;


}

}

while(valorcorrecto==0);
	printf("\nMES:");
	scanf("%s",&ven[g].mes);
	printf("\nDIA:");
	valorcorrecto=0;
	do

{

if(scanf("%d",&ven[g].dia) != 1)

{

printf("ERROR: ingrese un numero\n");

fflush(stdin);

}

else

{

valorcorrecto=1;


}

}

while(valorcorrecto==0);
	ven[g].venta_hecha=1;
	sumaventa+=ven[g].monto;
	g++;
	ventacreada++;
	pasohecho4=1;

break;

case 3:
	
	if(pasohecho4==0)
{
printf("¡Primero, tiene que ingresar una venta!\n");	
}
else
{
	printf("A continuacion se mostraran las ventas disponibles:\n");
	for(g=0;g<ventacreada;g++)
	{
	printf("======== (VENTA %d) ========\n",g+1);
	printf("ID DE VENTA: [%d]\n",ven[g].id_ventas);
	printf("ID DE PEDIDO: [%d]\n",ven[g].idpedido);
	printf("MONTO: [%d]\n",ven[g].monto);
	printf("FECHA:[%d] [%s] [%d]\n",ven[g].dia,ven[g].mes,ven[g].anio);
	printf("ID DE CLIENTE: [%d]\n",ven[g].id_cliente);
	printf("============================\n");
	}
}
break;

case 4:

if(pasohecho4==0)
{
printf("¡Primero, tiene que ingresar una venta!\n");	
}
else
{
promedioventa=sumaventa/ventacreada;
printf("Ha elegido el promedio de las ventas:\n");
printf("===== (PROMEDIO) =====\n");
printf("PROMEDIO: [%d]\n",promedioventa);
printf("======================\n");
break;
}
}
}
while(salirven==false);
}
break;
case 6:
	{	
	printf("=========== (pasos) ===========\n");
	if(pasohecho==0)
	{
	printf("[] ENTRAR A EMPLEADOS Y REGISTRAR UNO (GERENTE)\n");
	}
	else if(pasohecho==1)
	{
	printf("[X] ENTRAR A EMPLEADOS Y REGISTRAR UNO (GERENTE)\n");	
	}
	if(pasohecho2==0)
	{
	printf("[] ENTRAR A PRODUCTOS Y REGISTRAR UNO\n");	
	}
	else if(pasohecho2==1)
	{
	printf("[X] ENTRAR A PRODUCTOS Y REGISTRAR UNO\n");	
	}
	if(pasohecho3==0)
	{
	printf("[] ENTRAR A PEDIDOS Y CREAR UNO\n");	
	}
	else if(pasohecho3==1)
	{
	printf("[X] ENTRAR A PEDIDOS Y CREAR UNO\n");	
	}
	if(pasohecho5==0)
	{
	printf("[] ENTRAR A PEDIDOS Y REGISTRAR UN CLIENTE\n");	
	}
	if(pasohecho5==1)
	{
	printf("[X] ENTRAR A PEDIDOS Y REGISTRAR UN CLIENTE\n");		
	}
	if(pasohecho4==0)
	{
	printf("[] ENTRAR A VENTAS Y CREAR UNO\n");	
	}
	else if(pasohecho4==1)
	{
	printf("[X] ENTRAR A VENTAS Y CREAR UNO\n");	
	}
	if(pasohecho4==1)
	{
	printf("¡FELICIDADES! Ya podes usar todo el programa\n");	
	}
break;	
	}	
default:
printf("¡ERROR!, Ingrese una de las opciones dadas.\n");
break;	
}
}
}
while(salir==false);
return 0;	
}
