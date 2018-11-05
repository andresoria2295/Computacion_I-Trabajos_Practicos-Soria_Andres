#include "persona.h"
#include <iostream>
#include "myconnection.h"
#include "organizacion.h"
#include "domicilio.h"

using namespace std;

Domicilio::Domicilio()
{
    calle="";
    numero=0;
}

Domicilio::Domicilio(string calle,long numero)
{
    this->setCalle(calle);
    this->setNumero(numero);
}

void Domicilio::agregar()
{
  string stringSQL;
  stringstream values;
  values << this->getCalle() << "','" << this->getNumero();
  stringSQL = "INSERT INTO domicilio (calle,numero) VALUES ('"+values.str()+"');";
  MyConnection::instance()->execute(stringSQL);
  this->inicio();
}

void Domicilio::inicio(){
    cout<<"<html><head>"<<endl;
    cout<<"<link href='http://localhost/bootstrap.css' rel='stylesheet'>"<<endl;
    cout << "</head>" <<endl;
    cout << "<body>   <div class='container'>"<<endl;
    //  this->listar();
    cout<<"<div class='centrar'><h2>Insertar Domicilio</h2></div>"<<endl;
    cout<<"<form  method='post'>"<<endl;
    cout<<"<label for='calle'>Calle</label>"<<endl;
    cout<<"<input type='text' id='calle' name='calle'>"<<endl;
    cout<<"<label for='numero'>Numero</label>"<<endl;
    cout<<"<input type='text' id='numero' name='numero'>"<<endl;
    cout<<"<br>"<<endl;
    cout<<"<br>"<<endl;
    cout<<"<button name='crear3' type='submit'>Enviar</button>"<<endl;
    cout << "<a href='2Parcial'" << endl;
    cout << ">Volver</a>"<<endl;
    cout<<"</form>"<<endl;
    cout<<"</div></body></html>"<<endl;

}

void Domicilio::setNumero(long numero)
{
    this->numero = numero;
}

long Domicilio::getNumero()
{
    return this->numero;
}

void Domicilio::setCalle(string calle)
{
    this->calle = calle;
}

string Domicilio::getCalle()
{
    return this->calle;
}
