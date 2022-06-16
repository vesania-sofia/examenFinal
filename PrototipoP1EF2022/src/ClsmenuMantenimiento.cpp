#include "ClsmenuMantenimiento.h"
//Clases auxiliares
#include "Clsempleados.h"
//#include "Clspaciente.h"
//#include "Clsexamen.h"

#include<conio.h>
#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
#include<cstdlib>
#include<cstring>
#include<ctime>

using namespace std;

//ClsmenuMantenimiento::ClsmenuMantenimiento()
//{

//}
ClsmenuMantenimientos::mmenuMantimientos()
{
    string accion="";
    //tiempo
    time_t t;
    t = time(NULL);
    struct tm *fecha;
    fecha = localtime(&t);

    string codigo;
    fstream abrir;
    int found=0;
    abrir.open("Usuario.txt", ios::in);
    if (!abrir)
    {
        cerr << "Archivo Usuario no Encontrado" << endl;
        exit ( 3 );
    }
    else
    {
        abrir>>codigo;
    }

    ofstream bitacora("Bitacora.txt", ios::app | ios::out);
    if (!bitacora)
    {
        cerr << "No se pudo abrir el archivo." << endl;
        cout <<  "Archivo creado satisfactoriamente, pruebe de nuevo";
        exit ( 3 );
    }

    int choice2;
    do
    {
        system("cls");
        //Menu segundo nivel
        cout<<"-------------------------------"<<endl;
        cout<<" |   SISTEMA DE MANTENIMIENTO |"<<endl;
        cout<<"-------------------------------"<<endl;
        cout<<"1. CRUD empleados"<<endl;
        cout<<"2. CRUD pacientes"<<endl;
        cout<<"3. CRUD examen"<<endl;
        cout<<"0. Volver al menu principal"<<endl;
        cout<<"-------------------------------"<<endl;
        cout<<"Opcion a escoger:[1/2/3/0]"<<endl;
        cout<<"-------------------------------"<<endl;
        cout<<"Ingresa tu Opcion: ";
        cin>>choice2;
        switch(choice2)
        {
        case 1:
            {
                accion = "Ingreso a CRUD Empleados";

                bitacora<<left<<setw(9)<< "Usuario:" <<left<<setw(10)<< codigo <<left<<setw(8)<< "Accion:" <<left<<setw(30)<< accion
                <<left<<setw(5)<< "Dia:" <<left<<setw(5)<< fecha->tm_mday <<left<<setw(5)<< "Mes:" <<left<<setw(5)<< fecha->tm_mon+1
                <<left<<setw(5)<< "Año:" <<left<<setw(6)<< fecha->tm_year+1900 <<left<<setw(6)<< "Hora:" <<left<<setw(5)<< fecha->tm_hour
                <<left<<setw(8)<< "Minuto:" <<left<<setw(5)<< fecha->tm_min <<left<<setw(9)<< "Segundo:" <<left<<setw(5)<< fecha->tm_sec << endl;
                /*bitacora.close();*/

                Clsempleados empleado;
                empleado.mmenuEmpleados();

            }
            break;
        case 2:
            {
                /*accion = "Ingreso a CRUD Pacientes";

                bitacora<<left<<setw(9)<< "Usuario:" <<left<<setw(10)<< codigo <<left<<setw(8)<< "Accion:" <<left<<setw(30)<< accion
                <<left<<setw(5)<< "Dia:" <<left<<setw(5)<< fecha->tm_mday <<left<<setw(5)<< "Mes:" <<left<<setw(5)<< fecha->tm_mon+1
                <<left<<setw(5)<< "Año:" <<left<<setw(6)<< fecha->tm_year+1900 <<left<<setw(6)<< "Hora:" <<left<<setw(5)<< fecha->tm_hour
                <<left<<setw(8)<< "Minuto:" <<left<<setw(5)<< fecha->tm_min <<left<<setw(9)<< "Segundo:" <<left<<setw(5)<< fecha->tm_sec << endl;
                /*bitacora.close();*/

              /*  Clspaciente paciente;
                paciente.mmenuPaciente();*/
            }
            break;
        case 3:
            {
                accion = "Ingreso a CRUD Examen";

                bitacora<<left<<setw(9)<< "Usuario:" <<left<<setw(10)<< codigo <<left<<setw(8)<< "Accion:" <<left<<setw(30)<< accion
                <<left<<setw(5)<< "Dia:" <<left<<setw(5)<< fecha->tm_mday <<left<<setw(5)<< "Mes:" <<left<<setw(5)<< fecha->tm_mon+1
                <<left<<setw(5)<< "Año:" <<left<<setw(6)<< fecha->tm_year+1900 <<left<<setw(6)<< "Hora:" <<left<<setw(5)<< fecha->tm_hour
                <<left<<setw(8)<< "Minuto:" <<left<<setw(5)<< fecha->tm_min <<left<<setw(9)<< "Segundo:" <<left<<setw(5)<< fecha->tm_sec << endl;
                /*bitacora.close();*/

                ClsPuestos puesto;
                puesto.mmenuPuestos();
            }
            break;
        case 0:
            {
                accion = "Salio de Mantenimiento";

                bitacora<<left<<setw(9)<< "Usuario:" <<left<<setw(10)<< codigo <<left<<setw(8)<< "Accion:" <<left<<setw(30)<< accion
                <<left<<setw(5)<< "Dia:" <<left<<setw(5)<< fecha->tm_mday <<left<<setw(5)<< "Mes:" <<left<<setw(5)<< fecha->tm_mon+1
                <<left<<setw(5)<< "Año:" <<left<<setw(6)<< fecha->tm_year+1900 <<left<<setw(6)<< "Hora:" <<left<<setw(5)<< fecha->tm_hour
                <<left<<setw(8)<< "Minuto:" <<left<<setw(5)<< fecha->tm_min <<left<<setw(9)<< "Segundo:" <<left<<setw(5)<< fecha->tm_sec << endl;
                bitacora.close();
            }
            break;
        default:
            cout<<"numero ingresado no válido, intente de nuevo.";
            getch();
            break;
        }
    }while(choice2!=0);
}

