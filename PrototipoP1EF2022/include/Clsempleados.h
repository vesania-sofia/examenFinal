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
        Clsempleados(int=0, string = "", string = "", int=0, int=0, string = "", string = "");

        //Menu de los empleados
        mmenuEmpleados();

        //Crear registro en blanco
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

        //Metodos atributo clase empelados
        void mestablecerid( int ) ;
        int mobtenerid() const;

        //Metodos atributo nombre del empleado
        void mestablecerNombre( string );
        string mobtenerNombre() const;

        //Metodos atributo apellidos del empleado
        void mestablecerApellidos( string );
        string mobtenerApellidos() const;

        //Metodos atributo edad del empleado
        void mestablecerTelefono( int ) ;
        int mobtenerTelefono() const;

        //Metodos atributo direccion del empleado
        void mestablecerDPI( int ) ;
        int mobtenerDPI() const;

        //Metodos atributo telefono del empleado
        void mestablecerDireccion( string );
        string mobtenerDireccion() const;

        //Metodos atributo correo del empleado
        void mestablecerFechaNac( string );
        string mobtenerFechaNac() const;


        //Destructor de la clase empleado
        virtual ~Clsempleados();

    protected:

    private:
        int m_iidEmpleado;
        char m_snombreEmpleado[10];
        char m_sapellidosEmpleado[20];
        int m_itelefonoEmpleado[10];
        int m_iDPIEmpleado[10];
        char m_sdireccion[20];
        char m_sFechaNac[20];

};

#endif // CLSEMPLEADOS_H
