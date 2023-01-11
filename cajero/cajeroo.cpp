# include <iostream>
# include <string>
#include <fstream>
using namespace std;



double User[3][3]; 
 ofstream archivo;
 int nip;
 int nip_user[3]={5885,7457,1234};

 int opcion;
 int din,cantact;
  double Tot;
 bool val = false;
 string moves[100][5];
 int M[3];
 
double temp=0;
int u;
int i=0,Usertransfer;

int main()
{
	
	for (int i=0;i<=1;i++)
	{
		M[i]=0;
	}
	nip_user[0] = 5885;
	User[0][2] = 10000;
	nip_user[1] = 7457;
	
	nip_user[2]	=1234;
	
	
	do
	{
		system("CLS");
		     
		     cout<<"Autor: Estrada Avalos Carlos Giovanny 2-03\n";
			cout<<"Cajero BBVA\n";
		
		cout<<"Nip: \n";
		cin>>nip;	
		if (nip == nip_user[0] or nip==nip_user[1] or nip==nip_user[2])         
			val = true;
		
		if (val == false)		   
			return 0;
		else{
			if (val==true)
	 		{
			do
			{
					cout<<"Cajero BBVA\n";
					
				
	   cout<<"(1) Depositar "<<endl;
	   cout<<"(2) Retirar "<<endl;
	   cout<<"(3) Consulta saldo"<<endl;
	   cout<<"(4) transferencia"<<endl;
	   cout<<"(5) Cambio de nip"<<endl;
	   cout<<"(6) Ultimos movimientos"<<endl;
	   cout<<"(7) Exit"<<endl;
		cout<<endl<<"Elija una opcion: ";
			cin>>opcion;
				    
				    switch (opcion)
			    	{
			    		
				        case 1:{
				        	
							
				        	archivo.open("deposito.txt",ios::app);
							cout<<"Ingrese la cantidad que desea depositar: ";
							cin>>din;
							if (din<=0){
								cout<<"Error, No puede registrar una cantidad menor a cero (no negativa)\n";
								
							}else{
							
							cout<<"cantidad depositada\n"<<din<<endl;
							archivo<<"cantidad depositada"<<din<<endl;
							cantact=User[u][2]+din;
							Tot=cantact;
							if (din<=0) 
								cout<<"Ingrese un valor valido a deposito que no sea mayor que 0 ";
							
							else
							{
						
							
						    cantact=User[u][2]+din;
						    Tot=cantact;
							
							Tot=User[u][2];
									cout<<"su saldo actual es: "<<" "<<cantact;
									
									Tot=cantact;
									archivo<<"su saldo actual es: "<<" "<<User[u][2];
								M[u]=M[u]+1;
								moves[u][M[u]].append(" deposito: ");
									string temp=to_string(din);
									moves[u][M[u]].append(temp);
								moves[u][M[u]].append("\n");
									system("PAUSE()");
									system("CLS");
									archivo.close();
							}
							}
							
						}break;
						case 2:
								archivo.open("Retiro.txt",ios::app);
							{
							cout<<"Cantidad a retirar: ";
							cin>>din;
							cout<<"Cantidad a retirar: "<<" "<<din<<endl;
							 archivo<<"Cantidad a retirar: "<<din<<endl;
							 cantact=User[u][2];
							
							Tot=User[u][2];
	//...................................................................................................................................................
							if (din<=0) 
								cout<<"Error de monto, Ingrese un monto valido\n";
							else
							{
							
								while (din>=Tot)
								{	
									cout<<"No cuenta con el fondo suficiente para retirar "<<" por favor ingrese un monto valido: \n";
									cin>>din;
									M[u]=M[u]+1;
									moves[u][M[u]].append(" Error en el retiro \n");
								
								}	
								Tot=Tot-din;
								User[u][2]=Tot;
								M[u]=M[u]+1;
								moves[u][M[u]].append(" retiro exitoso de \n");
								
								string temp2=to_string(din);
								moves[u][M[u]].append(temp2);
								moves[u][M[u]].append("\n");
								cout<<"su nuevo saldo es: "<<User[u][2]<<endl;
								system("PAUSE()");
								system("CLS");
								archivo.close();
							}
						}break;
				        case 3:{ 
				        	archivo.open("Saldo actual.txt",ios::app);
							if (Tot=0){
							
					        	cout<<"No cuenta con saldo suficiente "<<endl<<endl;
					        	}
					    	else{
						     cantact=User[u][2];
				                Tot=cantact;
					        	cout<<"Su saldo actual es : "<<Tot<<endl;
					        	
					        	archivo<<"Su saldo actual es : "<<User[u][2];
					        M[u]=M[u]+1;
							moves[u][M[u]].append(" Consulta \n");
							system("PAUSE()");
							}
							
							archivo.close();
						}break;
						
				        case 4:{
				        	archivo.open("transferencia.txt",ios::app);
				        	cout<<"Cantidad a transferir: ";
				            cin>>din;
				            cantact=cantact - din;
				                Tot=cantact;
				                
				            if(din <= 0){
				            	cout<<"Error, ingrese numeros mayores a cero (no negativo)\n";
				            
				            	
							}else{
						
				            Tot=User[u][2];
				            if (din > Tot){	
				                cin>>din;
				            } 
							else if (din <= 0)
								cout<<"Error!! ingrese un monto valido ";
								
							else {
				                cout<<"Nip del beneficiario: ";
				                cin>>nip;
				                
				                
				                
				                
				                cout<<"Transferencia exitosa \nSu nuevo saldo es:"<<cantact<<endl;
				                cout<<"Total de cantidad transferida"<<" "<<din<<endl;
				                cout<<"nip del beneficiario:"<<" "<<nip<<endl;
				                
				                 
				                 User[Usertransfer][2]=din+User[Usertransfer][2];
				                
				                archivo<<"transferencia :\n";
					        	archivo<<"Cantidad total : "<<Tot<<endl;
					        	archivo<<"cantidad transferida:"<<" "<<din;
					        	
					        	
				                M[u]=M[u]+1;
				                moves[u][M[u]].append("transferencia ");
				                string temp2=to_string(din);
				                moves[u][M[u]].append(temp2);
				                moves[u][M[u]].append("\n");
				            }
				            system("PAUSE()");
				            system("CLS");
				            archivo.close();
				            	}
				        }break;
				        case 5:{
				        	archivo.open("cambio nip.txt",ios::app);
				        	cout<<"Digite su nip: ";
							cin>>nip;
							if(nip_user[u]==nip)
							{
								cout<<"Digite el nuevo nip ";
								cin>>nip_user[u];
								archivo<<"nip actual:\n"<<nip_user[u]<<endl;
								archivo<<"nip reciente:\n"<<nip;
								
					        	
								M[u]=M[u]+1;
								moves[u][M[u]].append("El cambio de nip fue exitoso \n");
								
								system("PAUSE()");
							
							}
							else
							{
								cout<<"El nip ingresado es incorrecto, intente nuevamente";
								M[u]=M[u]+1;
								moves[u][M[u]].append("Un error ha ocurrido en el cambio del nip \n");
								archivo<<"nip actual:\n"<<moves[u][M[u]].append("Un error ha ocurrido en el cambio del nip \n")<<endl;
								system("PAUSE()");
								archivo.close();
							}
							system("CLS");
						}break;
				        case 6:{
				        	archivo.open("Movimientos registrados.txt",ios::app);
							cout<<"Ultimos movimientos del usuario: \n ";
							for (int i=0;i<=M[u];i++)
							{
								cout<<"movimiento "<<i<<" "<<endl;
								cout<<"\n"<<moves[u][i]<<"\n";
								archivo<<"movimiento "<<i<<" "<<endl;
								archivo<<"\n"<<moves[u][i]<<"\n";
								
							}
							system("PAUSE()");
							system("CLS");
							archivo.close();
						}break;	
				        default:
				        	
							cout<<endl<<"Cajero ATM BBVA AGRADECE SU PREFERENCIA\n"<<endl; 
							cout<<"Vuelva pronto\n";
					}	
				}
			while(opcion!=7);
			}
			else
			{
				
				cout<<"El nip ingresado es incorrecto\n ";
				cout<<"Ingrese nuevamente el nip:\n ";
				cin>>nip;
				
			}
		}
	}
	while(u<=1);
	system("PAUSE()");
	system("CLS");
return 0;
}
