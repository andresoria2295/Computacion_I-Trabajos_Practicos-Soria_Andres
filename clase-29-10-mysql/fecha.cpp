
#include "fecha.h"
#include <iostream>

using namespace std;

Fecha::Fecha()
{
    dia=0;
    mes=0;
    anho=0;
}

Fecha::Fecha(int dia, int mes, int anho)
{
    this->setdia(dia);
    this->setmes(mes);
    this->setanho(anho);
}

void Fecha::ingresar()
{
    int x,y,z;
    cout << "Ingrese el dia: ";
    cin >> x;
    this->setdia(x);
    cout << "Ingrese el mes: ";
    cin >> y;
    this->setmes(y);
    cout << "Ingrese el anho: ";
    cin >> z;
    this->setanho(z);
}

void Fecha::mostrar()
{
    cout << "<BR>";
    cout << "Fecha de Nacimiento: " << this->getdia() << "/" << this->getmes() << "/" << this->getanho() << "" << endl;

}

void Fecha::setdia(int dia)
{
    this->dia = dia;
}

int Fecha::getdia()
{
    return this->dia;
}

void Fecha::setmes(int mes)
{
    this->mes = mes;
}

int Fecha::getmes()
{
    return this->mes;
}

void Fecha::setanho(int  anho)
{
    this->anho = anho;
}

int Fecha::getanho()
{
    return this->anho;
}
