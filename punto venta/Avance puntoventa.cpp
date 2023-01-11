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
		cout<<"[6] cantidad de inventario\n";
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
		//					
						reg_tot_ven[IDd][1].append(inventario[p][1]);
			//				
						reg_tot_ven[IDd][1].append(temppL);
						reg_tot_ven[IDd][1].append("\n");
					cout<<"quiere otro comprar otro producto? [si] || [no]\n";
					cin>>op;

					}
				while(op=="si");
					cout<<"el total de toda su venta es de: "<<totLV;
										
					//idprod_ingresorte venta no totalizada(individual)
					string totLVL;
					totLVL=to_string(totLV);
					MOV_TV_CLI[mov][0]=id;
					MOV_TV_CLI[mov][3]=totLVL;
					archivo<<"Total de ventas individuales\n"<<totLVL;
					//idprod_ingresorte totalizacion
					
				float tempreg_tot_ven=stof(reg_tot_ven[IDd][2]);
					tempreg_tot_ven=tempreg_tot_ven+totLV;
					reg_tot_ven[IDd][2]=to_string(tempreg_tot_ven);
					//variable que almacena la totalizacion de ventas
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
					 break;
					 }
			         break;
						while (opc=0 and opc<=7 or opc<=9 );
	
	            return 0;
			}
			
		}
		
	}
