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
      ( m_inumeroPuesto - 1 ) * sizeof( Clsempleados ) );

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

/*void Clsempleados::mostrarLineaEmpleado( const Clsempleados &registro )
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
*/
Clsempleados::~Clsempleados()
{
    //dtor
}
