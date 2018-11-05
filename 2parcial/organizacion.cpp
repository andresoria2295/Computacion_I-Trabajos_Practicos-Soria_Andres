#include "organizacion.h"
#include <iostream>
#include "myconnection.h"

using namespace std;
Organizacion::Organizacion()
{
    nombre="";
    id=0;

}

Organizacion::Organizacion(string nombre,int id)
{
    this->setNombre(nombre);
    this->setid(id);
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

    cout<<"<div class='centrar'><h2>Organizaciones Registradas</h2></div>"<<endl;
    cout << "<table class='table table-hover table-bordered  table-striped' cellpadding='0' cellspacing='0'>" << endl;
    cout << "<thead><tr>" << endl;
    cout << "<th >Nombre de organizacion</th>"<< endl;
    cout << "<th >Cantidad de empleados</th>"<< endl;
    cout << "<th >Orden alfabetico de organizaciones</th>"<< endl;
    cout << "</tr></thead>" << endl;
    cout << "<tbody><tr>" << endl;
    this->listar();
    cout << "</tr>" << endl;
    cout << "</tr></tbody>" << endl;
    cout << "</table>" << endl;
    cout<<"<div class='centrar'><h2>Insertar Organizacion</h2></div>"<<endl;
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
  MyConnection myconnection;
  myconnection.connect();

  sql::ResultSet* organizaciones_personas = myconnection.query("SELECT organizacion.id as id_organizacion, organizacion.nombre as nombre_organizacion FROM computacion.organizacion INNER JOIN persona ON organizacion.id = persona.idorganizacion");
  while (organizaciones_personas->next()) {
      cout << "<tr>" << endl;
      cout << "<td>" << endl;
      cout << organizaciones_personas->getString("nombre_organizacion") << endl;
      cout << "</td>" << endl;
      cout << "<td>" << endl;
      cout << "<a href='2Parcial?eliminar=" + organizaciones_personas->getString("nombre_organizacion") + "'" << endl;
      cout << ">Eliminar</a>"<<endl;
      cout << "</td>" << endl;
      cout << "<td>" << endl;
      cout << "<a href='2Parcial?ide=" +organizaciones_personas->getString("id_organizacion") + "&doc=" + organizaciones_personas->getString("nombre_organizacion") +"'" << endl;
      cout << ">Modificar</a>"<<endl;
      cout << "</td>" << endl;
  }

  //probando orden alfabético
  sql::ResultSet* personas = myconnection.query("SELECT * FROM computacion.organizacion ORDER BY nombre ASC;");
    cout << "<br>" << endl;
    cout << "<br>" << endl;
    cout << "<br>" << endl;
    
    while (personas->next()) {
        cout << "<td>" << personas->getString("id") << "</td>" << endl;
        cout << "<td>" << personas->getString("nombre") << "<td>" << endl;
        cout << "<a class='btn btn-danger' style='width: 100px' href='2Parcial?eliminar=" + personas->getString("id") + "'" << endl;
        cout << ">Orden Alfabetico</a></td>" << endl;
        cout << "<td><form action='' method='get'><input type='text' class='form-control' style='width: 120px' name='modificado'><button class='btn btn-primary' type='submit' name='id2' value='" + personas->getString("id") + "'>enviar</button></form></td></tr>" << endl;
    }
}

void Organizacion::eliminar(string y){
    string stringSQL;
    stringSQL = "DELETE FROM organizacion WHERE nombre='"+y+"'";
    MyConnection::instance()->execute(stringSQL);
}

void Organizacion::setNombre(string nombre)
{
    this->nombre = nombre;
}

string Organizacion::getNombre()
{
    return this->nombre;
}

void Organizacion::setid(int id)
{
  this->id=id;
}
int Organizacion::getid()
{
  return this->id;
}
