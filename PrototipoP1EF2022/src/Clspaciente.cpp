#include<ctime>
#include<string.h>

#include "ClsmenuMantenimiento.h"
#include "Clspaciente.h"

using namespace std;


Clspaciente::Clspaciente(int iIDPaciente, string snombrePaciente, string sapellidosPaciente, string sFechaNacPaciente, string sGeneroPaciente, string sdireccionPaciente, string stelefonoPaciente, string sEstadoPaciente)
{
    //ctor
    mestablecerIDpac(iIDPaciente);
    mestablecerNombrePac(snombrePaciente);
    mestablecerApellidosPac(sapellidosPaciente);
    mestablecerFechaNac(sFechaNacPaciente);
    mestablecerGenero(sGeneroPaciente);
    mestablecerDireccion(sdireccionPaciente);
    mestablecerTelefono(stelefonoPaciente);
    mestablecerEstado(sEstadoPaciente);
}

int Clspaciente::mobtenerIDpac() const
{
    return m_iIDPaciente;
}

void Clsempleados::mestablecerid (int iIDpaciente)
{
    m_iIDPaciente = iIDpaciente;
}

string Clspaciente::mobtenerNombrePac() const
{
    return m_snombrePaciente;
}

void Clsempleados::mestablecerNombrePac( string snombrePaciente )
{

   const char *svalorNombrePac = snombrePaciente.data();
   int ilongitud = strlen( svalorNombrePac );
   ilongitud = ( ilongitud < 20 ? ilongitud : 19 );
   strncpy( m_snombrePaciente, svalorNombrePac, ilongitud );


   m_snombrePaciente[ ilongitud ] = '\0';

}

string Clspaciente::mobtenerApellidosPac() const
{
    return m_sapellidosPaciente;
}

void Clsempleados::mestablecerApellidosPac( string sapellidosPaciente )
{

   const char *svalorApellidoPac = sapellidosPaciente.data();
   int ilongitud = strlen( svalorApellidoPac );
   ilongitud = ( ilongitud < 20 ? ilongitud : 19 );
   strncpy( m_sapellidosPaciente, svalorApellidoPac, ilongitud );


   m_sapellidosPaciente[ ilongitud ] = '\0';
}

string Clspaciente::mobtenerFechaNac() const
{
    return m_sFechaNacPaciente;
}

void Clsempleados::mestablecerFechaNac( string sFechaNacPaciente )
{

   const char *svalorFechaPac = sFechaNacPaciente.data();
   int ilongitud = strlen( svalorFechaPac );
   ilongitud = ( ilongitud < 20 ? ilongitud : 19 );
   strncpy( m_sFechaNacPaciente, svalorFechaPac, ilongitud );


   m_sFechaNacPaciente[ ilongitud ] = '\0';

}
Clspaciente::~Clspaciente()
{
    //dtor
}
