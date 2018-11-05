#include "organizacion.h"
#include <iostream>
#include "myconnection.h"

using namespace std;
Organizacion::Organizacion()
{
    nombre="";

}

Organizacion::Organizacion(string nombre)
{
    this->setNombre(nombre);
}


void Organizacion::agregar()
{
    string stringSQL;
    stringstream values;
    values << this->getNombre();
    stringSQL = "INSERT INTO organizacion (nombre) VALUES ('"+values.str()+"');";
    MyConnection::instance()->execute(stringSQL);
    this->inicio();
}

void Organizacion::inicio(){
    cout<<"<html><head>"<<endl;
    cout<<"<link href='http://localhost/bootstrap.css' rel='stylesheet'>"<<endl;
    cout << "</head>" <<endl;
    cout << "<body>   <div class='container'>"<<endl;
    //  this->listar();
    cout << "</table>" << endl;
    cout<<"<div class='centrar'><h2>Agregar Organizacion</h2></div>"<<endl;
    cout<<"<form class='form-signin'  method='post'>"<<endl;
    cout<<"<label for='organizacion' class='sr-only'>Organizacion</label>"<<endl;
    cout<<"<input type='text' id='organizacion' name='organizacion' class='form-control' placeholder='organizacion' required autofocus>"<<endl;
    cout<<"<br>"<<endl;
    cout<<"<br>"<<endl;
    cout<<"<button class='btn btn-lg btn-primary btn-block' name='crear2' type='submit'>Enviar</button>"<<endl;
    cout << "<a href='2Parcial'" << endl;
    cout << ">Volver</a>"<<endl;
    cout<<"</form>"<<endl;
    cout<<"</div></body></html>"<<endl;

}
void Organizacion::listar()
{

}

void Organizacion::eliminar(int x){

}

void Organizacion::setNombre(string nombre)
{
    this->nombre = nombre;
}

string Organizacion::getNombre()
{
    return this->nombre;
}
