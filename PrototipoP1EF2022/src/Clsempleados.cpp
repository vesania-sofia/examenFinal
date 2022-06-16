#include "Clsempleados.h"

#include<conio.h>
#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
#include<cstdlib>
#include<ctime>
#include<string.h>

#include "ClsmenuMantenimiento.h"

using namespace std;
Clsempleados::Clsempleados(int iidEmpleado, string snombreEmpleado, string sapellidosEmpleado, string stelefonoEmpleado, string sDPIEmpleado, string sdireccion, string sFechaNac)
{
    //ctor
    mestablecerid(iidEmpleado);
    mestablecerNombre(snombreEmpleado);
    mestablecerApellidos(sapellidosEmpleado);
    mestablecerTelefono(stelefonoEmpleado);
    mestablecerDPI(sDPIEmpleado);
    mestablecerDireccion(sdireccion);
    mestablecerFechaNac(sFechaNac);
}

int Clsempleados::mobtenerid() const
{
    return m_iidEmpleado;
}

void Clsempleados::mestablecerid (int iidEmpleado)
{
    m_iidEmpleado = iidEmpleado;
}

string Clsempleados::mobtenerNombre() const
{
    return m_snombreEmpleado;
}

void Clsempleados::mestablecerNombre( string snombreEmpleado )
{
   // copiar a lo más 20 caracteres de la cadena en nombree
   const char *svalorNombre = snombreEmpleado.data();
   int ilongitud = strlen( svalorNombre );
   ilongitud = ( ilongitud < 20 ? ilongitud : 19 );
   strncpy( m_snombreEmpleado, svalorNombre, ilongitud );

   // anexar caracter nulo al final del nombre
   m_snombreEmpleado[ ilongitud ] = '\0';

}

string Clsempleados::mobtenerApellidos() const
{
    return m_sapellidosEmpleado;
}

void Clsempleados::mestablecerApellidos( string sapellidosEmpleado )
{
   // copiar a lo más 20 caracteres de la cadena en nombree
   const char *svalorApellido = sapellidosEmpleado.data();
   int ilongitud = strlen( svalorApellido );
   ilongitud = ( ilongitud < 20 ? ilongitud : 19 );
   strncpy( m_sapellidosEmpleado, svalorApellido, ilongitud );

   // anexar caracter nulo al final del nombre
   m_sapellidosEmpleado[ ilongitud ] = '\0';

}

string Clsempleados::mobtenerTelefono() const
{
    return m_stelefonoEmpleado;
}

void Clsempleados::mestablecerTelefono( string stelefonoEmpleado )
{
   // copiar a lo más 20 caracteres de la cadena en nombree
   const char *svalortelefono = stelefonoEmpleado.data();
   int ilongitud = strlen( svalortelefono );
   ilongitud = ( ilongitud < 20 ? ilongitud : 19 );
   strncpy( m_stelefonoEmpleado, svalortelefono, ilongitud );

   // anexar caracter nulo al final del nombre
   m_stelefonoEmpleado[ ilongitud ] = '\0';

}

string Clsempleados::mobtenerDPI() const
{
    return m_sDPIEmpleado;
}

void Clsempleados::mestablecerDPI( string sDPIEmpleado )
{
   // copiar a lo más 20 caracteres de la cadena en nombree
   const char *svalorDPI = sDPIEmpleado.data();
   int ilongitud = strlen( svalorDPI );
   ilongitud = ( ilongitud < 20 ? ilongitud : 19 );
   strncpy( m_sDPIEmpleado, svalorDPI, ilongitud );

   // anexar caracter nulo al final del nombre
   m_sDPIEmpleado[ ilongitud ] = '\0';

}


string Clsempleados::mobtenerDireccion() const
{
    return m_sdireccion;
}

void Clsempleados::mestablecerDireccion( string sdireccion )
{
   // copiar a lo más 20 caracteres de la cadena en nombree
   const char *svalordireccion = sdireccion.data();
   int ilongitud = strlen( svalordireccion );
   ilongitud = ( ilongitud < 20 ? ilongitud : 19 );
   strncpy( m_sdireccion, svalordireccion, ilongitud );

   // anexar caracter nulo al final del nombre
   m_sdireccion[ ilongitud ] = '\0';

}

string Clsempleados::mobtenerFechaNac() const
{
    return m_sFechaNac;
}

void Clsempleados::mestablecerFechaNac( string sdireccion )
{

   const char *svalorFecha = sdireccion.data();
   int ilongitud = strlen( svalorFecha );
   ilongitud = ( ilongitud < 20 ? ilongitud : 19 );
   strncpy( m_sFechaNac, svalorFecha, ilongitud );

   m_sFechaNac[ ilongitud ] = '\0';

}

Clsempleados::mcrearEmpleados()
{
    ofstream archivoEmpleado("registrosempleado.dat", ios::out | ios::binary);
    if(!archivoEmpleado)
    {
        cerr<<"No se habrio el archivo"<<endl;
        exit(1);
    }
    Clsempleados empleadoEnBlanco;
    for(int i=0; i<100; i++)
    {
        archivoEmpleado.write(reinterpret_cast<const char * > (&empleadoEnBlanco), sizeof(Clsempleados));
    }
}
int Clsempleados::mobtenerIndicador(const char * const iindicador)
{
    int m_iidEmpleado;


   do {
      cout << iindicador << " (1 - 100): ";
      cin >> m_iidEmpleado;

   } while ( m_iidEmpleado < 1 || m_iidEmpleado > 100 );

   return m_iidEmpleado;
}


void Clsempleados::mnuevoEmpleado(fstream &archivoEmpleado)
{
   Clsempleados empleado;
   int m_iidEmpleado = mobtenerIndicador( "Escriba el numero del empleado" );

   // desplazar el apuntador de posición del archivo hasta el registro correcto en el archivo
   archivoEmpleado.seekg(
      ( m_iidEmpleado - 1 ) * sizeof( Clsempleados ) );

   // leer el registro del archivo
   archivoEmpleado.read( reinterpret_cast< char * >( &empleado ),
      sizeof( Clsempleados ) );

   // crear el registro, si éste no existe ya
   if ( empleado.mobtenerid() == 0 ) {

     char m_snombreEmpleado[ 20 ];

      // el usuario introduce el nombre
      cout << "Escriba el nombre del empleado: " << endl;
      cin >> setw( 20 ) >> m_snombreEmpleado;

     char m_sapellidosEmpleado[ 20 ];

      // el usuario introduce el nombre
      cout << "Escriba el apellido del empleado: " << endl;
      cin >> setw( 20 ) >> m_sapellidosEmpleado;

     char m_stelefonoEmpleado[ 20 ];

      // el usuario introduce el nombre
      cout << "Escriba el numero de telefono: " << endl;
      cin >> setw( 20 ) >> m_stelefonoEmpleado;


     char m_sDPIEmpleado[ 20 ];

      // el usuario introduce el nombre
      cout << "Escriba el numero de DPI: " << endl;
      cin >> setw( 20 ) >> m_sDPIEmpleado;

     char m_sdireccion[ 20 ];

      // el usuario introduce el nombre
      cout << "Escriba la dirreccion del empleado: " << endl;
      cin >> setw( 20 ) >> m_sdireccion;

     char m_sFechaNac[ 20 ];

      // el usuario introduce el nombre
      cout << "Escriba la fecha de nacimiento: " << endl;
      cin >> setw( 20 ) >> m_sFechaNac;

      empleado.mestablecerNombre(m_snombreEmpleado);
      empleado.mestablecerApellidos(m_sapellidosEmpleado);
      empleado.mestablecerTelefono(m_stelefonoEmpleado);
      empleado.mestablecerDPI(m_sDPIEmpleado);
      empleado.mestablecerDireccion(m_sdireccion);
      empleado.mestablecerFechaNac(m_sFechaNac);

      // desplazar el apuntador de posición de archivo hasta el registro correcto en el archivo
      archivoEmpleado.seekp( ( m_iidEmpleado - 1 ) *
         sizeof( Clsempleados ) );

      // insertar el registro en el archivo
      archivoEmpleado.write(
         reinterpret_cast< const char * >( &empleado ),
         sizeof( Clsempleados ) );

        cout << "empleado agregado con exito.";

   }

   // mostrar error si la cuenta ya existe
   else
   {
       cerr << "El numero  #" << m_iidEmpleado << " ya contiene informacion." << endl;
       getch();
   }
}

void Clsempleados::mostrarLineaEmpleado( const Clsempleados &registro )
{
       cout << left << setw( 10 ) << registro.mobtenerid()
          << setw( 20 ) << registro.mobtenerNombre().data()
          << setw( 20 ) << registro.mobtenerApellidos().data()
          << setw( 20 ) << registro.mobtenerTelefono().data()
          << setw( 20 ) << registro.mobtenerDPI().data()
          << setw( 20 ) << registro.mobtenerDireccion().data()
          << setw( 20 ) << registro.mobtenerFechaNac().data()
          << endl;
}


void Clsempleados::mconsultarRegistroEmpleados(fstream &archivoEmpleado)
{
   cout << left << setw( 10 ) << "ID" << setw( 20 )
       << "Nombre" << setw( 20 )
       << "Apellido" << setw( 20 )
       << "Telefono" << setw ( 20 )
       << "DPI" << setw ( 20 )
       << "Direccion" << setw ( 20 )
       << "Fecha de nacimiento"<< endl;

   // colocar el apuntador de posición de archivo al principio del archivo de registros
   archivoEmpleado.seekg( 0 );

   // leer el primer registro del archivo de registros
   Clsempleados empleado;
   archivoEmpleado.read( reinterpret_cast< char * >( &empleado),
      sizeof( Clsempleados ) );

   // copiar todos los registros del archivo de registros en el archivo de texto
   while ( !archivoEmpleado.eof() ) {

      // escribir un registro individual en el archivo de texto
      if ( empleado.mobtenerid() != 0 )
         mostrarLineaEmpleado(empleado);

      // leer siguiente registro del archivo de registros
      archivoEmpleado.read( reinterpret_cast< char * >( &empleado ),
         sizeof( Clsempleados ) );

   }
}

void Clsempleados::mmostrarLineaRegistroEmpleados( ostream &salida, const Clsempleados &registroempleado )
{
       salida << left << setw( 10 ) << registroempleado.mobtenerid()
          << setw( 20 ) << registroempleado.mobtenerNombre().data()
          << setw( 20 ) << registroempleado.mobtenerApellidos().data()
          << setw( 20 ) << registroempleado.mobtenerTelefono().data()
          << setw( 20 ) << registroempleado.mobtenerDPI().data()
          << setw( 20 ) << registroempleado.mobtenerDireccion().data()
          << setw( 20 ) << registroempleado.mobtenerFechaNac().data()
          << endl;

}

void Clsempleados::mmodificarRegistroEmpleados( fstream &archivoEmpleado )
{

   Clsempleados empleado;
   int m_iidEmpleado = mobtenerIndicador("Ingrese el numero del empleado");

   archivoEmpleado.seekg(
      ( m_iidEmpleado - 1 ) * sizeof( Clsempleados ) );

   // leer el primer registro del archivo
   archivoEmpleado.read( reinterpret_cast< char * >( &empleado ),
      sizeof( Clsempleados ) );

   // actualizar el registro
   if ( empleado.mobtenerid() != 0 ) {
      mmostrarLineaRegistroEmpleados( cout, empleado );

      cout << "\nEscriba el nombre del empelado: ";
      char m_snombreEmpleado [ 20 ];
      cin >> m_snombreEmpleado;

      cout << "\nEscriba el apellido del empleado: ";
      char m_sapellidosEmpleado [ 20 ];
      cin >> m_sapellidosEmpleado;

      cout << "\nEscriba el numero de telefono: ";
      char m_stelefonoEmpleado [ 20 ];
      cin >> m_stelefonoEmpleado;

      cout << "\nEscriba el numero de DPI: ";
      char m_sDPIEmpleado [ 20 ];
      cin >> m_sDPIEmpleado;

      cout << "\nEscriba la direccion: ";
      char m_sdireccion [ 20 ];
      cin >> m_sdireccion;

      cout << "\nEscriba la fecha de nacimiento: ";
      char m_sFechaNac [ 20 ];
      cin >> m_sFechaNac;

      empleado.mestablecerid(m_iidEmpleado);
      empleado.mestablecerNombre(m_snombreEmpleado);
      empleado.mestablecerApellidos(m_sapellidosEmpleado);
      empleado.mestablecerTelefono(m_stelefonoEmpleado);
      empleado.mestablecerDPI(m_sDPIEmpleado);
      empleado.mestablecerDireccion(m_sdireccion);
      empleado.mestablecerFechaNac(m_sFechaNac);
      mmostrarLineaRegistroEmpleados( cout, empleado );

      // desplazar el apuntador de posición de archivo hasta el registro correcto en el archivo
      archivoEmpleado.seekp(
         ( m_iidEmpleado - 1 ) * sizeof( Clsempleados ) );

      // escribir el registro actualizado sobre el registro anterior en el archivo
      archivoEmpleado.write(
         reinterpret_cast< const char * >( &empleado ),
         sizeof( Clsempleados ) );

        cout << "empleado modificado con éxito.";

   } // fin de instrucción if

   // mostrar error si la cuenta no existe
   else
      cerr << "El numero #" << m_iidEmpleado
         << " no tiene informacion." << endl;
}


void Clsempleados::mimprimirRegistroEmpleados (fstream &archivoEmpleado)
{
    Clsempleados empleado;
    ofstream imprimir("registrodeempleado.txt", ios::out);

   // salir del programa si ofstream no puede crear el archivo
   if ( !imprimir ) {
      cerr << "No se pudo crear el archivo." << endl;
      exit( 1 );

   } // fin de instrucción if

   imprimir << left << setw( 10 ) << "ID" << setw( 20 )
       << "Nombre" << setw( 20 )
       << "Apellido" << setw( 20 )
       << "Telefono" << setw( 20 )
       << "DPI" <<setw( 20 )
       << "Direccion" << setw( 20 )
       << "Fecha de nacimiento"<< endl;
   // colocar el apuntador de posición de archivo al principio del archivo de registros
   archivoEmpleado.seekg( 0 );

   // leer el primer registro del archivo de registros
   archivoEmpleado.read( reinterpret_cast< char * >( &empleado ),
      sizeof( Clsempleados ) );

   // copiar todos los registros del archivo de registros en el archivo de texto
   while ( !archivoEmpleado.eof() ) {

      // escribir un registro individual en el archivo de texto
      if ( empleado.mobtenerid() != 0 )
         mmostrarLineaRegistroEmpleados( imprimir, empleado );

      // leer siguiente registro del archivo de registros
      archivoEmpleado.read( reinterpret_cast< char * >( &empleado ),
         sizeof( Clsempleados ) );

   }
   cout << "archivo creado con éxito con el nombre de: regisrodeempleado";
}

void Clsempleados::meliminarRegistroEmpleados(fstream &archivoEmpleado)
{
    int iindicador= mobtenerIndicador( "Escriba el numero de empleado a eliminar" );

   // desplazar el apuntador de posición de archivo hasta el registro correcto en el archivo
   archivoEmpleado.seekg(
      ( iindicador - 1 ) * sizeof( Clsempleados ) );

   // leer el registro del archivo
   Clsempleados empleado;
   archivoEmpleado.read( reinterpret_cast< char * >( &empleado ),
      sizeof( Clsempleados ) );

   // eliminar el registro, si es que existe en el archivo
   if ( empleado.mobtenerid() != 0 ) {
      Clsempleados empleadoEnBlanco;

      // desplazar el apuntador de posición de archivo hasta el registro correcto en el archivo
      archivoEmpleado.seekp( ( iindicador - 1 ) *
         sizeof( Clsempleados ) );

      // reemplazar el registro existente con un registro en blanco
      archivoEmpleado.write(
         reinterpret_cast< const char * >( &empleadoEnBlanco ),
         sizeof( Clsempleados ) );

      cout << "Empleado numero #" << iindicador << " eliminado correctamente.\n";

   }

   // mostrar error si el registro no existe
   else
   {
       cerr << "Empleado numero #" << iindicador << " esta vacia.\n";
   }
   getch();
}

void Clsempleados::mbuscarEmpleados(fstream &archivoEmpleado)
{
    int iindicador = mobtenerIndicador( "Escriba el numero que desea buscar" );

   // desplazar el apuntador de posición de archivo hasta el registro correcto en el archivo
   archivoEmpleado.seekg(
      ( iindicador - 1 ) * sizeof( Clsempleados ) );

   // leer el primer registro del archivo
   Clsempleados empleado;
   archivoEmpleado.read( reinterpret_cast< char * >( &empleado ),
      sizeof( Clsempleados ) );
    //cout<<empleado.mobtenerClave();

   // actualizar el registro
   if ( empleado.mobtenerid() != 0 ) {
      mmostrarLineaRegistroEmpleados( cout, empleado );
   }

   // mostrar error si la cuenta no existe
   else
   {
       cerr << "El numero #" << iindicador
         << " no tiene informacion." << endl;
   }
   getch();
}


Clsempleados::mmenuEmpleados()
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

    int iseleccionMenuEmpleados;
    do
    {
        system("cls");
        // abrir el archivo en modo de lectura y escritura
        fstream archivoEmpleado("registrosempleado.dat", ios::in | ios::out | ios::binary);
        // salir del programa si fstream no puede abrir el archivo
        if ( !archivoEmpleado )
            {
                cerr << "No se pudo abrir el archivo." << endl;
                mcrearEmpleados();
                cout <<  "Archivo creado satisfactoriamente, pruebe de nuevo";
                exit ( 1 );

            }
        cout<<"-------------------------------"<<endl;
        cout<<"|   SISTEMA GESTION EMPLEADO  |"<<endl;
        cout<<"-------------------------------"<<endl;
        cout<<"1. Ingreso de Empleado"<<endl;
        cout<<"2. Despliegue de Empleado"<<endl;
        cout<<"3. Modifica Empleado"<<endl;
        cout<<"4. Imprimir Regisro de Empleado"<<endl;
        cout<<"5. Borra Empleado"<<endl;
        cout<<"6. Buscar Empleado"<<endl;
        cout<<"0. Volver al menu superior"<<endl;
        cout<<"-------------------------------"<<endl;
        cout<<"Opcion a escoger:[1/2/3/4/5/6/0]"<<endl;
        cout<<"------------------------------"<<endl;
        cout<<"Ingresa tu Opcion: ";
        cin>>iseleccionMenuEmpleados;
        switch(iseleccionMenuEmpleados)
        {
        case 1:
            {
                accion = "Ingreso a Agre. Empleado";

                bitacora<<left<<setw(9)<< "Usuario:" <<left<<setw(10)<< codigo <<left<<setw(8)<< "Accion:" <<left<<setw(30)<< accion
                <<left<<setw(5)<< "Dia:" <<left<<setw(5)<< fecha->tm_mday <<left<<setw(5)<< "Mes:" <<left<<setw(5)<< fecha->tm_mon+1
                <<left<<setw(5)<< "Año:" <<left<<setw(6)<< fecha->tm_year+1900 <<left<<setw(6)<< "Hora:" <<left<<setw(5)<< fecha->tm_hour
                <<left<<setw(8)<< "Minuto:" <<left<<setw(5)<< fecha->tm_min <<left<<setw(9)<< "Segundo:" <<left<<setw(5)<< fecha->tm_sec << endl;
                /*bitacora.close();*/

                system("cls");
                mnuevoEmpleado(archivoEmpleado);
                getch();
            }
            break;
        case 2:
            {
                accion = "Ingreso a Cons. Empleado";

                bitacora<<left<<setw(9)<< "Usuario:" <<left<<setw(10)<< codigo <<left<<setw(8)<< "Accion:" <<left<<setw(30)<< accion
                <<left<<setw(5)<< "Dia:" <<left<<setw(5)<< fecha->tm_mday <<left<<setw(5)<< "Mes:" <<left<<setw(5)<< fecha->tm_mon+1
                <<left<<setw(5)<< "Año:" <<left<<setw(6)<< fecha->tm_year+1900 <<left<<setw(6)<< "Hora:" <<left<<setw(5)<< fecha->tm_hour
                <<left<<setw(8)<< "Minuto:" <<left<<setw(5)<< fecha->tm_min <<left<<setw(9)<< "Segundo:" <<left<<setw(5)<< fecha->tm_sec << endl;
                /*bitacora.close();*/

                system("cls");
                mconsultarRegistroEmpleados(archivoEmpleado);
                cout << "Fin del archivo.";
                getch();
            }
            break;
        case 3:
            {
                accion = "Ingreso a Mod. Empleado";

                bitacora<<left<<setw(9)<< "Usuario:" <<left<<setw(10)<< codigo <<left<<setw(8)<< "Accion:" <<left<<setw(30)<< accion
                <<left<<setw(5)<< "Dia:" <<left<<setw(5)<< fecha->tm_mday <<left<<setw(5)<< "Mes:" <<left<<setw(5)<< fecha->tm_mon+1
                <<left<<setw(5)<< "Año:" <<left<<setw(6)<< fecha->tm_year+1900 <<left<<setw(6)<< "Hora:" <<left<<setw(5)<< fecha->tm_hour
                <<left<<setw(8)<< "Minuto:" <<left<<setw(5)<< fecha->tm_min <<left<<setw(9)<< "Segundo:" <<left<<setw(5)<< fecha->tm_sec << endl;
                /*bitacora.close();*/

                system("cls");
                mmodificarRegistroEmpleados(archivoEmpleado);
                getch();
            }
            break;
        case 4:
            {
                accion = "Ingreso a Impri. Empleado";

                bitacora<<left<<setw(9)<< "Usuario:" <<left<<setw(10)<< codigo <<left<<setw(8)<< "Accion:" <<left<<setw(30)<< accion
                <<left<<setw(5)<< "Dia:" <<left<<setw(5)<< fecha->tm_mday <<left<<setw(5)<< "Mes:" <<left<<setw(5)<< fecha->tm_mon+1
                <<left<<setw(5)<< "Año:" <<left<<setw(6)<< fecha->tm_year+1900 <<left<<setw(6)<< "Hora:" <<left<<setw(5)<< fecha->tm_hour
                <<left<<setw(8)<< "Minuto:" <<left<<setw(5)<< fecha->tm_min <<left<<setw(9)<< "Segundo:" <<left<<setw(5)<< fecha->tm_sec << endl;
                /*bitacora.close();*/

                system("cls");
                mimprimirRegistroEmpleados(archivoEmpleado);
                getch();
            }
            break;
        case 5:
            {
                accion = "Ingreso a Elim. Empleado";

                bitacora<<left<<setw(9)<< "Usuario:" <<left<<setw(10)<< codigo <<left<<setw(8)<< "Accion:" <<left<<setw(30)<< accion
                <<left<<setw(5)<< "Dia:" <<left<<setw(5)<< fecha->tm_mday <<left<<setw(5)<< "Mes:" <<left<<setw(5)<< fecha->tm_mon+1
                <<left<<setw(5)<< "Año:" <<left<<setw(6)<< fecha->tm_year+1900 <<left<<setw(6)<< "Hora:" <<left<<setw(5)<< fecha->tm_hour
                <<left<<setw(8)<< "Minuto:" <<left<<setw(5)<< fecha->tm_min <<left<<setw(9)<< "Segundo:" <<left<<setw(5)<< fecha->tm_sec << endl;
                /*bitacora.close();*/

                system("cls");
                meliminarRegistroEmpleados(archivoEmpleado);
            }
            break;
        case 6:
            {
                accion = "Ingreso a Bus. Empleado";

                bitacora<<left<<setw(9)<< "Usuario:" <<left<<setw(10)<< codigo <<left<<setw(8)<< "Accion:" <<left<<setw(30)<< accion
                <<left<<setw(5)<< "Dia:" <<left<<setw(5)<< fecha->tm_mday <<left<<setw(5)<< "Mes:" <<left<<setw(5)<< fecha->tm_mon+1
                <<left<<setw(5)<< "Año:" <<left<<setw(6)<< fecha->tm_year+1900 <<left<<setw(6)<< "Hora:" <<left<<setw(5)<< fecha->tm_hour
                <<left<<setw(8)<< "Minuto:" <<left<<setw(5)<< fecha->tm_min <<left<<setw(9)<< "Segundo:" <<left<<setw(5)<< fecha->tm_sec << endl;
                /*bitacora.close();*/

                system("cls");
                mbuscarEmpleados(archivoEmpleado);
            }
            break;
        case 0:
            {
                accion = "Salio de Gestion Empleado";

                bitacora<<left<<setw(9)<< "Usuario:" <<left<<setw(10)<< codigo <<left<<setw(8)<< "Accion:" <<left<<setw(30)<< accion
                <<left<<setw(5)<< "Dia:" <<left<<setw(5)<< fecha->tm_mday <<left<<setw(5)<< "Mes:" <<left<<setw(5)<< fecha->tm_mon+1
                <<left<<setw(5)<< "Año:" <<left<<setw(6)<< fecha->tm_year+1900 <<left<<setw(6)<< "Hora:" <<left<<setw(5)<< fecha->tm_hour
                <<left<<setw(8)<< "Minuto:" <<left<<setw(5)<< fecha->tm_min <<left<<setw(9)<< "Segundo:" <<left<<setw(5)<< fecha->tm_sec << endl;
                /*bitacora.close();*/
            }
            break;
        default:
            cout<<"Opción invalida, intenta de nuevo";
            getch();
            break;
        }
    }while(iseleccionMenuEmpleados!=0);
}


Clsempleados::~Clsempleados()
{
    //dtor
}
