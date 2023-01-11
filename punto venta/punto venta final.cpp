#include <iostream>
#include <string>
#include <stdlib.h>
#include <fstream>

using namespace std;


string inventario[10][5];
string clientes[5][4];
string MOV_TV_CLI[100][4]; 
string reg_tot_ven[5][3];
float totven=0;
int idprod_ingres[100][2];

ofstream archivo;	


int mov=0;
float totLV=0;
int lug_vac=8;int lug_vac2=4;
int loop=0;int loop2=0; //ciclo para verificar los espacios
int p,np,opc2,x;
int i=2,opc;;                                    
float totalCl[5];

int main()
{	

	// Clientes pre-registrados
	clientes[0][0]="0";clientes[0][1]="Erick";clientes[0][2]="2000";clientes[0][3]="100";
	clientes[1][0]="1";clientes[1][1]="carlos";clientes[1][2]="2000";clientes[1][3]="310";

	

	//Contenido del inventario
	inventario[0][0]="0";inventario[0][1]="Leño dulce";inventario[0][2]="15";inventario[0][3]="30";inventario[0][4]="10";
	inventario[1][0]="1";inventario[1][1]="coca cola 600ml";inventario[1][2]="15";inventario[1][3]="20";inventario[1][4]="5";
	inventario[2][0]="2";inventario[2][1]="Paketaxo";inventario[2][2]="20";inventario[2][3]="8";inventario[2][4]="4";
	inventario[3][0]="6";inventario[3][1]="Tonayan 1 lt.";inventario[3][2]="50";inventario[3][3]="12";inventario[3][4]="4";
	inventario[4][0]="7";inventario[4][1]="Agua bonafont 1lt ";inventario[4][2]="20";inventario[4][3]="20";inventario[4][4]="5";
	inventario[5][0]="8";inventario[5][1]="Galletas principe";inventario[5][2]="18";inventario[5][3]="18";inventario[5][4]="6";
	
	//registro de las ventas
	reg_tot_ven[0][2]="0";
	reg_tot_ven[1][2]="0";
	reg_tot_ven[2][2]="0";
	reg_tot_ven[3][2]="0";
	reg_tot_ven[4][2]="0";
	do
	{
		system("CLS");
		cout<<"CONASUPO :D\n";
		cout<<"[1] Venta\n";
		cout<<"[2] inventario\n";
		cout<<"[3] registro de clientess\n";
		cout<<"[4] registro de ventas\n";
		cout<<"[5] Totalizacion\n";
		cout<<"[7] Exit\n";
		cin>>opc;
		switch(opc)
		{
			case 1:
				{	archivo.open("Totalizacion de ventas e individuales.txt",ios::app);
					system("CLS");
					mov++;
					string op="";
					float tempp;
					string id; id=" ";
					int IDd;
					string npL;
					tempp=0;
					do
					{
				cout<<"VENTA\n";
						for (loop=0;loop<=lug_vac;loop++)
						{
							if(inventario[loop][1]==" ")
							{
								cout<<"\n";
							}
							else
							cout<<"["<<loop<<"]  "<<"$"<<inventario[loop][2]<<" "<<inventario[loop][1]<<"\n";
						}
						cout<<"eleccion de inventario: ";	
						cin>>p;
						
					
						cout<<"cantidad de "<<inventario[p][1]<<" que quiere: ";
						cin>>np;
						if (np<0){
							cout<<"Error, Ingrese un valor mayor a 0\n";
						}
						else{
					
					
						int l;
						l=stoi(inventario[p][3]);
						while(np>l)
						{
							cout<<"ingrese una cantidad menor";
							cin>>np;
						}
						npL=to_string(np);
						tempp=stof(inventario[p][2]);
						tempp*=np;
						cout<<"total: "<<tempp<<"\n";
						totLV=totLV+tempp;
							}		
																	 
						do
						{
							if (id==" ")
							{
								cout<<"id del cliente: ";
								cin>>id;
								IDd=stoi(id);
								if(IDd>i or IDd<0)
								{
									cout<<"Ingrese una respuesta valida\n";
									x=1;
								}							
								else 
									x=0;
							}
							else 
								x=0;	
						}
						while(x==1);
						// Inventario y stock en la matriz
							int st=stoi(inventario[p][3]);
							st=st-np;
							inventario[p][3]=to_string(st);
						// venta individual
							string temppL=to_string(tempp);
							string movL;
							movL=to_string(mov);				
                            	MOV_TV_CLI[mov][1]=movL;
                                	MOV_TV_CLI[mov][2].append(inventario[p][1]);
	                            MOV_TV_CLI[mov][2].append("     $");
	                             MOV_TV_CLI[mov][2].append(temppL);
	                            MOV_TV_CLI[mov][2].append("\n");
						//registro totalizacion
						if (reg_tot_ven[IDd][0]!=id)
					{
								
							reg_tot_ven[IDd][0]=id;
						}
						reg_tot_ven[IDd][1].append(npL);
						reg_tot_ven[IDd][1].append(inventario[p][1]);
						reg_tot_ven[IDd][1].append(temppL);
						reg_tot_ven[IDd][1].append("\n");
					cout<<"quiere otro comprar otro producto? [si] || [no]\n";
					cin>>op;

					}
				while(op=="si");
					cout<<"el total de toda su venta es de: "<<totLV;

					string totLVL;
					totLVL=to_string(totLV);
					MOV_TV_CLI[mov][0]=id;
					MOV_TV_CLI[mov][3]=totLVL;
					archivo<<"Total de ventas individuales\n"<<totLVL;
	
				float tempreg_tot_ven=stof(reg_tot_ven[IDd][2]);
					tempreg_tot_ven=tempreg_tot_ven+totLV;
					reg_tot_ven[IDd][2]=to_string(tempreg_tot_ven);
					totven=totven+totLV;
					archivo<<"Totalizacion de ventas:\n"<<totven;
					
					system("PAUSE");
					archivo.close();
				}
				break;
			case 2:
				{	
				int id;
			    int op;
					cout<<"inventario\n";
					cout<<"[1]Buscar inventarios\n";
					cout<<"[2]Mostrar inventario\n";
					cout<<"[3]Agregar\n";
					cout<<"[4]borrar\n";
					cout<<"[5]SALIR\n";
					 cin>>op;
				do
					{
				switch (op)
					{
					case 1:
						{
							archivo.open("inventario total.txt",ios::app);
							cout<<"ID del inventario: ";
								cin>>id;
								archivo<<id<<endl;
						int IDd=0;
							for (IDd=0;IDd<=4;IDd++)
							{
							if(IDd==0)
								{
									cout<<"ID:";
									
									}
							else if(IDd==2)
								{
										cout<<"$";
								}
							else if(IDd==3)
								{
										cout<<"stock en existencia ";
								}
							else if(IDd==4)
									{
									cout<<"stock minimo ";
									}
								cout<<inventario[id][IDd]<<"  ";
								archivo<<inventario[id][IDd]<<endl;		
							}	
								system("PAUSE");
								archivo.close();
							}
							break;
				case 2:
					{
						archivo.open("inventario total.txt",ios::app);
				for (loop=0;loop<=lug_vac;loop++)
			    {
					for(loop2=0;loop2<=lug_vac2-1;loop2++)
					{
					if(loop2==0)
								{
					cout<<"ID:";
								}
					else if(loop2==2)
					{
					cout<<"$";
							}
					else if(loop2==3)
							{
					cout<<"Disponibles:";
									}
					cout<<inventario[loop][loop2]<<" ";
					archivo<<inventario[loop][loop2]<<" \n ";
						}		
						cout<<"\n";
								}
		         	system("PAUSE");
					archivo.close();
							}
			break;
				case 3:
		{
			int x;
			cout<<"agregue una descripcion para el inventario: ";
								
			for (loop=0;loop<=lug_vac;loop++)
				{
			if(inventario[loop][1]==" ")
				{
			cin>>inventario[loop][1];
			inventario[loop][0]=loop;
				cout<<"precio venta : ";
					cin>>inventario[loop][2];
				cout<<"No.articulos en stock: ";
					cin>>inventario[loop][3];
				cout<<"cantidad minima: ";
					cin>>inventario[loop][4]; 
					loop+=10;//Cierre del looplo
						x=1;
						}
					else
					{
					x=0;
						}
					}
					if(x==0)
								{
									//lug_vac++ es para ir un lugar libre despues del ultimo inventario
									lug_vac++;
									cin>>inventario[lug_vac][1];
									inventario[lug_vac][0]=lug_vac;
									cout<<"precio venta: ";
									cin>>inventario[lug_vac][2];
									cout<<"cantidad de stock: ";
									cin>>inventario[lug_vac][3];
									cout<<"cantidad minima de stock: ";
									cin>>inventario[lug_vac][4]; 
								}	
							}
							break;
						case 4:
							{archivo.open("productos eliminados.txt",ios::app);
							int x;
								cout<<"Escriba id del producto a eliminar: ";
								cin>>x;
								inventario[x][1]=" ";
								inventario[x][2]=" ";
								inventario[x][3]=" ";
								inventario[x][4]=" ";
								cout<< x<<" ha sido eliminado del inventario\n";
								cout<<inventario[x][1]<<inventario[x][2]<<inventario[x][3]<<inventario[x][4]<<"\n";
								archivo<<inventario[x][1]<<inventario[x][2]<<inventario[x][3]<<inventario[x][4]<<"\n";
								archivo<< x<<" ha sido eliminado del inventario\n";
								system("PAUSE");
								archivo.close();
							}
							break;
						case 5:
							{
								op=6; 
							}
							break;
						default:
							{
								cout<<"ingresar una opcion valida";
								system("PAUSE");
								system("CLS");
							}
					}
				}
			while(op<1 or op>6);
			}
			break;
			case 3:
				{
			int op=0;
				string id;
			int IDd;
			do
					{
						system("CLS");
						cout<<"clientes\n";
						cout<<"[1] Buscar clientes\n";
						cout<<"[2] Muestra de clientes\n";
						cout<<"[3] Aniadir clientes\n";
						cout<<"[4] Abono cliente \n";
						cout<<"[5] Eliminar\n";
						cout<<"[6] Exit\n";  
						cin>>op;
						switch(op)
						{
							case 1:
								{
					cout<<"ingresar ID cliente a buscar: ";
					cin>>id;
					IDd=stoi(id);
					for (loop=0;loop<=3;loop++)
						{	
					if (loop==0)
					{
				cout<<"ID: ";
							}
				else if (loop==1)	{
				cout<<"Nombre del cliente: ";
						}
				else if(loop==2)
						{
				cout<<"Credito maximo del cliente: ";
										}
			else if (loop==3)	{
			cout<<"total de credito utilizado por el cliente: ";
								}
			cout<<clientes[IDd][loop]<<"  ";
									}
			system("PAUSE");
								}
			break;
					case 2:
				archivo.open("clientes.txt",ios::app);
				{
				for (loop=0;loop<=i;loop++)
					{
				for(loop2=0;loop2<=3;loop2++)	{
					if(loop2==0){
					cout<<"ID del cliente:";
										}
			else if(loop2==1)
					{
				 	cout<<"Nombre del cliente:: ";
									}
					else if(loop2==2)
						{
					cout<<"Credito maximo del cliente: ";
							}
						else if(loop2==3)	{
						cout<<"Total de credito utilizado por el cliente: ";
							}
							cout<<clientes[loop][loop2]<<"  ";
						archivo<<clientes[loop][loop2]<<"  ";
												}
						cout<<"\n";
								}
						system("PAUSE");
					archivo.close();
								}
								break;
					case 3:
						{
					archivo.open("clientes agregados.txt",ios::app);
								int x;
							cout<<"agregar nombre del cliente: ";
								for (loop=0;loop<=i;loop++)
								{
								if(clientes[loop][1]==" ")
										{
		cin>>clientes[loop][1];
			string loopL=to_string(loop);
				clientes[loop][0]=loopL;
					cout<<"credito maximo del cliente: ";
						cin>>clientes[loop][2];
							archivo<<"clientes"<<clientes[loop][1]<<endl;
					archivo<<"credito maximo del cliente: "<<clientes[loop][2];;
							clientes[loop][3]="0";
							loop+=10;
						x=1;
							}
				else	{
			      	x=0;
						}
						}
						if(x==0)	{
		                     	i++;
					cin>>clientes[i][1];
					string iL=to_string(i);
					clientes[i][0]=iL;
					cout<<"credito maximo del nuevo cliente: ";
						cin>>clientes[i][2];
						clientes[i][3]="0";
						archivo.close();
									}	
								}
								break;
					case 4:
								
						{				
			int temp;
				cout<<"ingresar ID del usuario a abonar ";
				cin>>id;
				IDd=stoi(id);
				if (IDd>=0 and IDd<=i)
						{
			cout<<"credito pendiente: "<<clientes[IDd][3]<<"\n";
				cout<<"Cantidad a abonar: ";
			 cin>>temp;
				float tempc=stof(clientes[IDd][3]);
					tempc-=temp;
					clientes[IDd][3]=to_string(tempc);
					}
					else 
					{
					cout<<"Usuario incorrecto, intente nuevamente ";
						system("PAUSE");
						}
					system("PAUSE");
							}
					break;
				case 5:
						{
						int x;
						cout<<"Ingrese el ID del cliente a eliminar\n: ";
					 cin>>x;
						clientes[x][1]=" ";
						clientes[x][2]=" ";
					clientes[x][3]=" ";
						cout<<x<<" ha sido eliminado de la lista de clientes\n";
							cout<<clientes[x][1]<<clientes[x][2]<<clientes[x][3]<<"\n";
						system("PAUSE");
							}
							
								break;
							case 6:
				{
				
						}
								break;
							default:
								{
									cout<<"Ingrese una opcion valida\n";
									cout<<"presione cualquier tecla para volver a intentar\n";
									system("PAUSE");
									system("CLS");
								}
						}
					}
					while(op!=6);
				}
				break;
			case 4:
				{
					int op,x,IDd=0;
					system("CLS");
					cout<<"Venta individual\n";
					cout<<"[1] Buscar venta[1]\n";
					cout<<"[2] Mostrar venta\n";
					cout<<"[3] Exit\n";
					cin>>op;
					do
					{
					
					switch(op)
					{
						case 1:
							{
								cout<<"numero de venta a buscar: ";
								cin>>x;
								for (IDd=0;IDd<=3;IDd++)
								{
									cout<<MOV_TV_CLI[x][IDd]<<"\n";
								}
								system("PAUSE");
							}
							break;
						case 2:
							{
								for(x=0;x<=mov;x++)
								{
									for(IDd=0;IDd<=3;IDd++)
									{
										cout<<MOV_TV_CLI[x][IDd]<<"\n";	
									}
								}
								system("PAUSE");
							}
							break;
						default:
							{
								cout<<"eliga una opcion valida";
								system("PAUSE");
							}
							break;
					}
					cout<<"ingrese nuevamente una opcion:\n";
					cin>>op;
					}
					   while(op!=3);
				}
				break;
			case 5:
				{
					int op,x,IDd;
					float k;
					cout<<"Registro de totalizacion de ventas:\n\n";
					for(x=0;x<=i;x++)
					{
						for(IDd=0;IDd<=2;IDd++)
						{
							k=stof(reg_tot_ven[x][2]);
							if (k>=1)
							{
								cout<<"Cantidad de prodcutos totales vendidos:\n";
							cout<<reg_tot_ven[x][IDd]<<"\n";
							system("PAUSE");
							}
							else 
							{
								
							}
						}
					}
					
				}
				break;
			case 6:
				{
					cout<<"Totalizacion\n";
					cout<<"Totalizacion de ventas: ";
					cout<<totven;
					system("PAUSE");
					
				}
				break;
			case 7:
				{
					int x;
					int temp1,temp2;
					cout<<"Inventario en stock\n";
					for(x=0;x<=lug_vac;x++)
					{
						cout<<"ID: "<<inventario[x][0]<<" "<<inventario[x][1]<<" stock actual: "<<inventario[x][3]<<" stock minimo: "<<inventario[x][4]<<"\n";
						temp1=stoi(inventario[x][3]);
						temp2=stoi(inventario[x][4]);
						if(temp1<=temp2)
						{
							cout<<"Baja cantidad de stock\n";
						}
					}
					
				}
				break;
			case 8:
				{
					
				}
				break;
			default:
				{
					cout<<"Ingrese nuevamente una opcion\n";
					
					system("CLS");
				}		
		}
	}
	while (opc=0 and opc<=7 or opc<=9 );
	
	return 0;
}
