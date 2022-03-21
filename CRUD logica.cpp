#include <iostream>
#include <stdio.h>  
#include <string.h> 
#include <conio.h>
using namespace std;

const char *nombre_archivo = "archivo.dat";

struct estudiante{
	int codigo;
	char nombre[50];
	char direccion[100];
	char apellido[50];
	int telefono;
	int eliminacion;
}Estudiante;

void crear();
void leer();
void actualizar();
void eliminar();

int main(){
	
	int op;
	
	do{
		system("cls");
		cout<<"1.Agregar estudiante"<<endl;
		cout<<"2.Actualizar estudiante datos de estudiante"<<endl;
		cout<<"3.Leer datos de estudiante"<<endl;
		cout<<"4.Eliminar estudiante"<<endl;
		cout<<"0.Salir"<<endl;
		cout<<"Ingrese la opcion que desea realizar: ";
		cin>>op;
		
		switch(op){
			case 1: crear(); break;
			case 2: actualizar(); break;
			case 3: leer(); break;
			case 4: eliminar(); break;
			case 0: break;
		}
	}while(op!=0);
	
	return 0;
	getch();
}

void actualizar(){
	system("cls");
	FILE* archivo = fopen(nombre_archivo,"r+b");
	int id;
	string nombre, apellido;
	cout<<"Ingrese el id para modificar: ";
	cin>>id;
	
	fseek(archivo,id *sizeof(struct estudiante),SEEK_SET);
	
		cout<<"Ingrese el codigo: ";
		cin>>Estudiante.codigo;
		cin.ignore();
		
		cout<<"Ingrese el nombre de estudiante: ";
		getline(cin,nombre);
		strcpy(Estudiante.nombre,nombre.c_str());
		
		cout<<"Ingrese el apellido de estudiante: ";
		getline(cin,apellido);
		strcpy(Estudiante.apellido,apellido.c_str());
		
		cout<<"Ingrese el numero de telefono: ";
		cin>>Estudiante.telefono;
		cin.ignore();
		
		cout<<"Ingrese el estado del estudiante: ";
		cin>>Estudiante.eliminacion;
		cin.ignore();
		getch();
		fwrite(&Estudiante,sizeof(struct estudiante),1,archivo);
		fclose(archivo);
}

void leer(){
	system("cls");
	FILE* archivo = fopen(nombre_archivo,"rb");
	
	if(!archivo){
		archivo = fopen(nombre_archivo,"w+b");
	}
	int id=0;
	
	fread(&Estudiante,sizeof(struct estudiante),1,archivo);
	
	do{
		if(Estudiante.eliminacion==1){
			fread(&Estudiante,sizeof(struct estudiante),1,archivo);
			id++;
		}else{
			cout<<"__________________________"<<endl;
			cout<<"id: "<<id<<endl;
			cout<<"Codigo: "<<Estudiante.codigo<<endl;
			cout<<"Nombres: "<<Estudiante.nombre<<endl;
			cout<<"Apellidos: "<<Estudiante.apellido<<endl;
			cout<<"Telefono: "<<Estudiante.telefono<<endl;
			cout<<"Estado: "<<Estudiante.eliminacion<<endl;
			fread(&Estudiante,sizeof(struct estudiante),1,archivo);
			id++;
		}
		
	}while(feof(archivo)==0);
	getch();
	fclose(archivo);
}

void crear(){
	system("cls");
	FILE* archivo = fopen(nombre_archivo,"ab");
	char continuar;
	string nombre, apellido;
	
	do{
		fflush(stdin);
		cout<<"Ingrese el codigo: ";
		cin>>Estudiante.codigo;
		cin.ignore();
		
		cout<<"Ingrese el nombre de estudiante: ";
		getline(cin,nombre);
		strcpy(Estudiante.nombre,nombre.c_str());
		
		cout<<"Ingrese el apellido de estudiante: ";
		getline(cin,apellido);
		strcpy(Estudiante.apellido,apellido.c_str());
		
		cout<<"Ingrese el numero de telefono: ";
		cin>>Estudiante.telefono;
		cin.ignore();
		
		Estudiante.eliminacion = 0;
		
		fwrite(&Estudiante,sizeof(struct estudiante),1,archivo);
		
		cout<<"Desea agregar otro esutidiante (s/n): ";
		cin>>continuar;
	}while(continuar=='s' or continuar=='S');
	getch();
	fclose(archivo);
}

void eliminar(){
	system("cls");
	FILE* archivo = fopen(nombre_archivo,"r+b");
	int id;
	cout<<"Ingrese el id que desea cambiar su estado: ";
	cin>>id;
	
	fseek(archivo,id *sizeof(struct estudiante),SEEK_SET);
		
		cout<<"1.Eliminado"<<endl;
		cout<<"0.Existente"<<endl;
		cout<<"Ingrese el estado del estudiante: ";
		cin>>Estudiante.eliminacion;
		cin.ignore();
		
		system("cls");
		if(Estudiante.eliminacion==1){
			cout<<"ELMINADO"<<endl;	
		}else if(Estudiante.eliminacion==0){
			cout<<"EXISTENTE"<<endl;
		}
		
		getch();
		fwrite(&Estudiante,sizeof(struct estudiante),1,archivo);
		fclose(archivo);
}
