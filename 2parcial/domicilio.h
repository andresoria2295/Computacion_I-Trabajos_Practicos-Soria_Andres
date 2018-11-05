#ifndef DOMICILIO_H
#define DOMICILIO_H
#include <string>
#include <iostream>
#include <map>
#include <sstream>

using namespace std;

class Domicilio
{
    public:
        Domicilio();
        Domicilio(string,long);

        void setNumero(long);
        long  getNumero();
        void setCalle(string);
        string getCalle();


        void inicio();
        void agregar();
        void listar();
        void prueba();
        void eliminar(string);
        void recibir(string,string,string,string);
        void modificar(string,string,string,string);

    protected:

    private:
        long  numero;
        string calle;
};
#endif // DOMICILIO_H
