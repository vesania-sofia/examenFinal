#ifndef CLSEMPLEADOS_H
#define CLSEMPLEADOS_H

//Librerias
#include<conio.h>
#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
#include<cstdlib>

using namespace std;

class Clsempleados
{
    public:
        //Constructor clase
        Clsempleados(int=0, string = "", string = "", string = "", string = "", string = "", string = "");


        mmenuEmpleados();


        mcrearEmpleados();

        //Metodos del CRUD de empleados
        int mobtenerIndicador( const char * const );

        void mnuevoEmpleado(fstream &archivoEmpleados);

        void mconsultarRegistroEmpleados(fstream &archivoEmpleados);

        void mostrarLineaEmpleado( const Clsempleados &registro );

        void mmodificarRegistroEmpleados( fstream &archivoEmpleados );

        void mmostrarLineaRegistroEmpleados( ostream &salida, const Clsempleados &registro );

        void mimprimirRegistroEmpleados(fstream &archivoEmpleado);

        void meliminarRegistroEmpleados(fstream &archivoEmpleados);

        void mbuscarEmpleados(fstream &archivoEmpleados);


        void mestablecerid( int ) ;
        int mobtenerid() const;


        void mestablecerNombre( string );
        string mobtenerNombre() const;


        void mestablecerApellidos( string );
        string mobtenerApellidos() const;


        void mestablecerTelefono( string ) ;
        string mobtenerTelefono() const;


        void mestablecerDPI( string ) ;
        string mobtenerDPI() const;


        void mestablecerDireccion( string );
        string mobtenerDireccion() const;


        void mestablecerFechaNac( string );
        string mobtenerFechaNac() const;


        //Destructor de la clase empleado
        virtual ~Clsempleados();

    protected:

    private:
        int m_iidEmpleado;
        char m_snombreEmpleado[20];
        char m_sapellidosEmpleado[20];
        char m_stelefonoEmpleado[20];
        char m_sDPIEmpleado[20];
        char m_sdireccion[20];
        char m_sFechaNac[20];

};

#endif // CLSEMPLEADOS_H
