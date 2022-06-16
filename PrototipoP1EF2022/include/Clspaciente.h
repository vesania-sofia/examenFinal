#ifndef CLSPACIENTE_H
#define CLSPACIENTE_H

#include<conio.h>
#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
#include<cstdlib>

using namespace std;


class Clspaciente
{
    public:
        Clspaciente(int=0, string="", string="", string="", string="", string="", string="", string="");


        mmenuPacientes();


        mcrearPacientes();

        //Metodos del CRUD de empleados
        int mobtenerIndicadorPac( const char * const );

        void mnuevoPciente(fstream &archivoPacientes);

        void mconsultarRegistroPacientes(fstream &archivoPacientes);

        void mostrarLineaPaciente( const Clspaciente &registroP );

        void mmodificarRegistroPacientes( fstream &archivoPacientes );

        void mmostrarLineaRegistroPacientes( ostream &salida, const Clspaciente &registroP );

        void mimprimirRegistroPacientes(fstream &archivoPacientes);

        void meliminarRegistroPacientes(fstream &archivoPacientes);

        void mbuscarPacientes(fstream &archivoPacientes);
        virtual ~Clspaciente();


        void mestablecerIDpac( int ) ;
        int mobtenerIDpac() const;


        void mestablecerNombrePac( string );
        string mobtenerNombrePac() const;


        void mestablecerApellidosPac( string );
        string mobtenerApellidos() const;


        void mestablecerFechaNac( string );
        string mobtenerFechaNac() const;


        void mestablecerGenero( string ) ;
        string mobtenerGenero() const;


        void mestablecerDireccion( string );
        string mobtenerDireccion() const;


        void mestablecerTelefono( string ) ;
        string mobtenerTelefono() const;


        void mestablecerEstado( string ) ;
        string mobtenerEstado() const;



    protected:

    private:
        int m_iIDPaciente;
        char m_snombrePaciente[20];
        char m_sapellidosPaciente[20];
        char m_sFechaNacPaciente[20];
        char m_sGeneroPaciente[20];
        char m_sdireccionPaciente[20];
        char m_stelefonoPaciente[20];
        char m_sEstadoPaciente[20];


};

#endif // CLSPACIENTE_H
