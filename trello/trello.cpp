#include<iostream>
#include<conio.h>
#include<string>
#include <stdlib.h>
#include<windows.h>

using namespace std;

void gotoxy(int x, int y){
	HANDLE hcon= GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X=x;
	dwPos.Y=y;
	SetConsoleCursorPosition(hcon,dwPos);
	
	
}

int main(){
	string tarea[5],nomtarea;
	int op,resp,opc;
	string nom,contra,i,j;
	string usuacontra[2][2];
	   usuacontra[0][0]="ramiro"; usuacontra[0][1]="ram123";
	   do{
	   
		
		gotoxy(40,1);cout<<"TRELLO :)";
	
	gotoxy(39,2);cout<<"Gestor de tareas ";
	gotoxy(38,3);cout<<"1- Iniciar sesion ";
	    gotoxy(38,4);cout<<"2- Registrarse ";
	    gotoxy(38,5);cout<<"3- Salir ";
	cin>>opc;
	
	switch(opc){
	system("cls");
		int opc1,resp;
	    do{
		
		
		
	    case 1:
	    	do{
			
	    	system("cls");
	    	int opp;
	    	
	    	gotoxy(39,3);cout<<"Ingrese su usuario\n";
	    	
	         gotoxy(39,4);cin>>nom;
	    	
	    		gotoxy(39,5);cout<<"Ingrese su contraseña\n";
	    		
	    	      gotoxy(39,6);cin>>contra;
	    	      
	    	      if (nom=="ramiro" and contra=="ram123"){
	    	      	cout<<"Ingrese opcion a realizar:";
	    	      	cout<<"1-Crear nueva tareas\n:";
	    	      	cout<<"2-Editar tareas:\n";
	    	      	cout<<"3-Ver tableros:\n";
	    	      	
	    	      	cin>>opp;
	    	      	
	    	      	
	    	      	switch(opp){
	    	      		case 1:
	    	      			system("cls");
	    	      			cout<<"Agrege el nombre de la nueva tarea:\n";
	    	      			cin>>tarea[5];
	    	      			
	    	      			break;
	    	      		case 2:
	    	      			break;
	    	      		case 3:
	    	      			system("cls");
	    	      			gotoxy(35,1);cout<<"Tareas pendientes:";
	    	      			gotoxy(45,1);cout<<"Tareas entregadas:";
	    	      			gotoxy(41,1);cout<<"-";
	    	      			gotoxy(41,2);cout<<"-";
	    	      			gotoxy(41,3);cout<<"-";
	    	      			gotoxy(41,4);cout<<"-";
	    	      			gotoxy(41,5);cout<<"-";
	    	      			gotoxy(41,6);cout<<"-";
	    	      			gotoxy(41,7);cout<<"-";
	    	      			gotoxy(41,8);cout<<"-";
	    	      			break;
	    	      			
	    	      		
					  }
	    	      	
	    	      	
				  } 
				  } while (resp==opc1);
	    	      
	    	
	    	
	    	
	    	break;
	    	
	    	case 2:
	    		system("cls");
	    		for( int i=0; i<1;i++){
			
	    	gotoxy(39,3);cout<<"Ingrese su usuario\n";
	    	
	         cin>>usuacontra[1][0];
	    	
	    		gotoxy(39,4);cout<<"Ingrese su contraseña\n";
	    		
	    	cin>>usuacontra[1][1];
	    	}
	    	break;
	    	
	    	
	    	case 3:
	    	break;
	    	cout<<"Desea realizar otra opcion: 1-si 2-no\n";
	    	cin>>resp;
	    	} while (resp==opc1 );
	
	    }
	} 	while (opc=0 and opc<=7 or opc<=9 );
	return 0;
}
