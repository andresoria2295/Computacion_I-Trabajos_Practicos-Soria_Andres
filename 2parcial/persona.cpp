#include "persona.h"
#include <iostream>
#include "myconnection.h"
#include "organizacion.h"
using namespace std;
Persona::Persona()
{
    dni=0;
    id=0;
    apellido="";
    nombre="";
}

Persona::Persona(long dni, int id, string apellido, string nombre)
{
    this->setDni(dni);
    this->setid(id);
    this->setApellido(apellido);
    this->setNombre(nombre);
}

void Persona::agregar()
{
    string stringSQL;
    stringstream values;
    values << this->getDni() << "','" << this->getNombre() << "','" << this->getApellido() << "','" << '1';
    stringSQL = "INSERT INTO persona (dni,nombre,apellido,idorganizacion) VALUES ('"+values.str()+"');";
    MyConnection::instance()->execute(stringSQL);
    this->inicio();
}

void Persona::inicio(){
    cout<<"<html><head>"<<endl;
    cout<<"<link href='http://localhost/bootstrap.css' rel='stylesheet'>"<<endl;
    cout << "</head>" <<endl;
    cout << "<body>   <div class='container'>"<<endl;
    cout<<"<div class='centrar'><h2>Personas Registradas</h2></div>"<<endl;
    cout << "<table class='table table-hover table-bordered  table-striped' cellpadding='0' cellspacing='0'>" << endl;
    cout << "<thead><tr>" << endl;
    cout << "<th >DNI</th>"<< endl;
    cout << "<th >Apellido</th>"<< endl;
    cout << "<th >Nombre</th>"<< endl;
    cout << "<th >Organizaci&oacute;n</th>"<< endl;
    cout << "<th >Domicilio</th>" << endl;
    cout << "</tr></thead>" << endl;
    cout << "<tbody><tr>" << endl;
    this->listar();
    cout << "</tr>" << endl;
    cout << "</tr></tbody>" << endl;
    cout << "</table>" << endl;
    cout<<"<div class='centrar'><h2>Insertar Persona</h2></div>"<<endl;
    cout<<"<form class='form-signin'  method='post'>"<<endl;
    cout<<"<label for='nombre' class='sr-only'>Nombre</label>"<<endl;
    cout<<"<input type='text' id='nombre' name='nombre' class='form-control' placeholder='Nombre' required autofocus>"<<endl;
    cout<<"<label for='apellido' class='sr-only'>Apellido</label>"<<endl;
    cout<<"<input type='text' id='apellido' name='apellido' class='form-control' placeholder='Apellido' required>"<<endl;
    cout<<"<label for='dni' class='sr-only'>Dni</label>"<<endl;
    cout<<"<input type='text' id='dni' name='dni' class='form-control' placeholder='Dni' required>"<<endl;
    cout<<"<br>"<<endl;
    cout<<"<br>"<<endl;
    cout<<"<button class='btn btn-lg btn-primary btn-block' name='crear' type='submit'>Enviar</button>"<<endl;
    cout << "<a href='2Parcial'" << endl;
    cout << ">Volver</a>"<<endl;
    cout<<"</form>"<<endl;
    cout<<"</div></body></html>"<<endl;

}
void Persona::listar()
{
    MyConnection myconnection;
    myconnection.connect();
    sql::ResultSet* personas_organizaciones = myconnection.query("SELECT persona.id as id_persona,persona.nombre as nombre_persona,persona.apellido as apellido_persona,persona.dni as dni_persona,organizacion.nombre  as organizacion_nombre FROM computacion.persona INNER JOIN organizacion ON persona.idorganizacion = organizacion.id");

    while (personas_organizaciones->next()) {
        cout << "<tr>" << endl;
        cout << "<td>" << endl;
        cout << personas_organizaciones->getString("dni_persona") << endl;
        cout << "</td>" << endl;
        cout << "<td>" << endl;
        cout << personas_organizaciones->getString("apellido_persona") << endl;
        cout << "</td>" << endl;
        cout << "<td>" << endl;
        cout << personas_organizaciones->getString("nombre_persona") << endl;
        cout << "</td>" << endl;
        cout << "<td>" << endl;
        cout << personas_organizaciones->getString("organizacion_nombre") << endl;
        cout << "</td>" << endl;
        cout << "<td>" << endl;
        cout << "La Plata 451" << endl;
        cout << "</td>" << endl;
        cout << "<td>" << endl;
        cout << "<a href='2Parcial?eliminar=" + personas_organizaciones->getString("dni_persona") + "'" << endl;
        cout << ">Eliminar</a>"<<endl;
        cout << "</td>" << endl;
        cout << "<td>" << endl;
        cout << "<a href='2Parcial?ide=" +personas_organizaciones->getString("id_persona") + "&doc=" + personas_organizaciones->getString("dni_persona") + "&name="+personas_organizaciones->getString("nombre_persona") + "&lastname="+personas_organizaciones->getString("apellido_persona")+"'" << endl;
        cout << ">Modificar</a>"<<endl;
        cout << "</td>" << endl;
    }
}

void Persona::recibir(string ide, string dni, string nombre,string apellido){
  cout<<"<html><head>"<<endl;
  cout << "</head>" <<endl;
  cout << "<body>   <div class='container'>"<<endl;
  cout<<"<form method='post'>"<<endl;
  cout<<"<label for='dni2' >Dni</label>"<<endl;
  cout << "<input type='text' name='dni2' id='dni2' value="+dni+" >" << endl;
  cout << "<input type='hidden' name='id2' id='id2' value="+ide+" >" << endl;
  cout<<"<label for='nombre2' >Nombre</label>"<<endl;
  cout << "<input type='text' name='nombre2' id='nombre2' value="+nombre+" >" << endl;
  cout<<"<label for='apellido2' >Apellido</label>"<<endl;
  cout << "<input type='text' name='apellido2' id='apellido2' value="+apellido+" >" << endl;
  cout <<"Organizacion: " << endl;
  cout << "<select name='org'>" << endl;

  MyConnection myconnection;
  myconnection.connect();
  //sql::ResultSet* personas_organizaciones = myconnection.query("SELECT persona.idorganizacion as idorganizacion_persona,organizacion.nombre  as organizacion_nombre FROM computacion.persona INNER JOIN organizacion ON persona.idorganizacion = organizacion.id");
  sql::ResultSet* organizaciones = myconnection.query("SELECT * FROM organizacion");
  while(organizaciones->next())
  {
    cout << "<option value="+organizaciones->getString("id")+">"+organizaciones->getString("nombre")+"</option>" << endl;
  }
  cout << "</select>" << endl;
  cout<<"<button name='buttonchange' type='submit'>Guardar y Volver</button>"<<endl;
  cout<<"</form>"<<endl;
  cout<<"</div></body></html>"<<endl;
}

void Persona::modificar(string i,string d, string n, string a, string o)
{
    string stringSQL;
    stringSQL = "UPDATE persona SET dni='"+d+"', nombre='"+n+"',apellido='"+a+"',idorganizacion='"+o+"' WHERE id='"+i+"'";
    MyConnection::instance()->execute(stringSQL);
}


void Persona::eliminar(string dni){
    //stringstream stringSQL;
    string stringSQL;
    //stringSQL <<"DELETE FROM persona WHERE dni = "<< dni <<";";
    stringSQL = "DELETE FROM persona WHERE dni='"+dni+"'";
    //MyConnection::instance()->execute(stringSQL.str());
    MyConnection::instance()->execute(stringSQL);
}

void Persona::setDni(long dni)
{
    this->dni = dni;
}

long Persona::getDni()
{
    return this->dni;
}

void Persona::setApellido(string apellido)
{
    this->apellido = apellido;
}

string Persona::getApellido()
{
    return this->apellido;
}

void Persona::setNombre(string  nombre)
{
    this->nombre = nombre;
}

string Persona::getNombre()
{
    return this->nombre;
}
void Persona::setid(int id){
  this->id=id;
}
int Persona::getid(){
  return this->id;
}
