//Librerias
#include<conio.h>
#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
#include<cstdlib>
#include<ctime>
#include <string.h>

//clases
#include "ClsmenuMantenimiento.h"
#include "ClsMantenimiento.h"
#include "Clsempleados.h"
#include "Clspaciente.h"
//#include "Clsexamen.h"

#define ENTER 13
#define BACKSPACE 8

using namespace std;

typedef struct {
    char usuario[10],contrasenia[10];
} tlogin;

void pausa();

void continuar(){
    printf("Presione una tecla para continuar\n\n");
    getch();
}


void crear(){
    FILE *arch;
    arch=fopen("login.dat","wb");
    if (arch==NULL)
        exit(1);
    fclose(arch);
}

void cargar(){
    FILE *arch;
    arch=fopen("login.dat","ab");
    if (arch==NULL){
        void crear();
    }else{
        tlogin login;
        printf("Ingrese usuario: ");
        scanf("%s",&login.usuario);
        fflush(stdin);
        printf("Ingrese password: ");
        scanf("%s",&login.contrasenia);
        fwrite(&login, sizeof(tlogin), 1, arch);
        fclose(arch);
    }
}

void listado(){

    FILE *arch;
    arch=fopen("login.dat","rb");
    if (arch==NULL)
        exit(1);
    tlogin login;
    fread(&login, sizeof(tlogin), 1, arch);

    printf("%s %s\n", "USUARIO", "PASSW0RD");

    while(!feof(arch))
    {
        printf("%s %s\n", login.usuario, login.contrasenia);
        fread(&login, sizeof(tlogin), 1, arch);
    }
    fclose(arch);
}

void login(){

    //Bitacora
    string codigo="";
    string accion="";

    //tiempo
    time_t t;
    t = time(NULL);
    struct tm *fecha;
    fecha = localtime(&t);

    FILE *arch;
    arch=fopen("login.dat","rb");
    if (arch==NULL)
        exit(1);

    char pusuario[10],pcontrasenia[10];
    cout<<"Ingrese usuario: ";
    cin>>pusuario;

    cout<<"Ingrese password: ";
    //cin>>pcontrasenia;

    char caracter;
    caracter = getch();

     string   password = "";

        while (caracter != ENTER)
        {

            if (caracter != BACKSPACE)
            {
                password.push_back(caracter);
                cout << "*";
            }
            else
            {
                if (password.length() > 0)
                {
                    cout << "\b \b";
                    password = password.substr(0, password.length() - 1);
                }
            }

            caracter = getch();
        }

    strcpy(pcontrasenia, password.c_str());


    tlogin login;

    fread(&login, sizeof(tlogin), 1, arch);
    bool usuarioExiste = false;
    bool passwordCorrecto = false;

    while(!feof(arch)){

        if(strcmp(pusuario,login.usuario)==0){
            usuarioExiste = true;
        }

        if(strcmp(pcontrasenia,login.contrasenia)==0){
            passwordCorrecto = true;
        }
        fread(&login, sizeof(tlogin), 1, arch);

    }

    if (!usuarioExiste){
        cout<<endl<<endl<<"El usuario ingresado no existe";
    }
    if (!passwordCorrecto){
        cout<<endl<<endl<<"Password incorrecto";
    }

    if((usuarioExiste)&&(passwordCorrecto)){
        cout<<endl<<endl<<"Realizo login exitoso"<<endl;
        getch();
        int imenuPrincipal=0;

        //Bitacora
        codigo = pusuario;
        accion = "Ingreso al sistema";
        //escribirBitacora(codigo, accion);

        ofstream bitacora("Bitacora.txt", ios::app | ios::out);
        if (!bitacora)
        {
            cerr << "No se pudo abrir el archivo." << endl;
            cout <<  "Archivo creado satisfactoriamente, pruebe de nuevo";
            exit ( 3 );
        }

        bitacora<<left<<setw(9)<< "Usuario:" <<left<<setw(10)<< codigo <<left<<setw(8)<< "Accion:" <<left<<setw(30)<< accion
        <<left<<setw(5)<< "Dia:" <<left<<setw(5)<< fecha->tm_mday <<left<<setw(5)<< "Mes:" <<left<<setw(5)<< fecha->tm_mon+1
        <<left<<setw(5)<< "Año:" <<left<<setw(6)<< fecha->tm_year+1900 <<left<<setw(6)<< "Hora:" <<left<<setw(5)<< fecha->tm_hour
        <<left<<setw(8)<< "Minuto:" <<left<<setw(5)<< fecha->tm_min <<left<<setw(9)<< "Segundo:" <<left<<setw(5)<< fecha->tm_sec << endl;
        bitacora.close();

        //////////////////////////////////////////////////////////////////////
        ofstream usuario("Usuario.txt", ios::out);
        if (!usuario)
        {
            cerr << "No se pudo abrir el archivo." << endl;
            cout <<  "Archivo creado satisfactoriamente, pruebe de nuevo";
            exit ( 3 );
        }

        usuario<<left<<setw(10)<< codigo;
        usuario.close();
    //Menu principal
	do
    {
        system("cls");

        cout<<"---------------------------------------------"<<endl;
        cout<<"|----BIENVENIDO AL SISTEMA DE LA CLINICA----|"<<endl;
        cout<<"creadora Karla Sofia Gómez Tobar 9959-21-1896"<<endl;
        cout<<"---------------------------------------------"<<endl;
        cout<<"1. CATALOGO"<<endl;
        cout<<"2. PROCESO"<<endl;
        cout<<"3. INFORMES"<<endl;
        cout<<"0. EXIT"<<endl;
        cout<<"-------------------------------"<<endl;
        cout<<"OPCIONES A ESCOGER :     [1/2/3/0]"<<endl;
        cout<<"-------------------------------"<<endl;
        cout<<"INGRESA TU OPCION : ";
        cin>>imenuPrincipal;
        switch (imenuPrincipal)
        {
        case 1:
            {
                accion = "Ingreso a Mantenimiento";
                ofstream bitacora("Bitacora.txt", ios::app | ios::out);
                if (!bitacora)
                {
                    cerr << "No se pudo abrir el archivo." << endl;
                    cout <<  "Archivo creado satisfactoriamente, pruebe de nuevo";
                    exit ( 3 );
                }

                bitacora<<left<<setw(9)<< "Usuario:" <<left<<setw(10)<< codigo <<left<<setw(8)<< "Accion:" <<left<<setw(30)<< accion
                <<left<<setw(5)<< "Dia:" <<left<<setw(5)<< fecha->tm_mday <<left<<setw(5)<< "Mes:" <<left<<setw(5)<< fecha->tm_mon+1
                <<left<<setw(5)<< "Año:" <<left<<setw(6)<< fecha->tm_year+1900 <<left<<setw(6)<< "Hora:" <<left<<setw(5)<< fecha->tm_hour
                <<left<<setw(8)<< "Minuto:" <<left<<setw(5)<< fecha->tm_min <<left<<setw(9)<< "Segundo:" <<left<<setw(5)<< fecha->tm_sec << endl;
                bitacora.close();

                ClsMantenimiento Mantenimiento;
                Mantenimiento.mmenuMantenimientoT();
            }
            break;
        case 2:
            {

            }
            break;
        case 3:
            {

            }
            break;

        case 0:
            {
                accion = "Salio del Menu Principal";
                ofstream bitacora("Bitacora.txt", ios::app | ios::out);
                if (!bitacora)
                {
                    cerr << "No se pudo abrir el archivo." << endl;
                    cout <<  "Archivo creado satisfactoriamente, pruebe de nuevo";
                    exit ( 3 );
                }

                bitacora<<left<<setw(9)<< "Usuario:" <<left<<setw(10)<< codigo <<left<<setw(8)<< "Accion:" <<left<<setw(30)<< accion
                <<left<<setw(5)<< "Dia:" <<left<<setw(5)<< fecha->tm_mday <<left<<setw(5)<< "Mes:" <<left<<setw(5)<< fecha->tm_mon+1
                <<left<<setw(5)<< "Año:" <<left<<setw(6)<< fecha->tm_year+1900 <<left<<setw(6)<< "Hora:" <<left<<setw(5)<< fecha->tm_hour
                <<left<<setw(8)<< "Minuto:" <<left<<setw(5)<< fecha->tm_min <<left<<setw(9)<< "Segundo:" <<left<<setw(5)<< fecha->tm_sec << endl;
                bitacora.close();
            }
            break;
        default:
            cout<<"Valor ingresado no vádido, intente de nuevo";
            getch();
            break;
        }
     }while(imenuPrincipal!=0);
    }

    fclose(arch);

}


