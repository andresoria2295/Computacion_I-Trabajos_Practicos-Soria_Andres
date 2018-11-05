#include <iostream>
#include <string>
// Formularios html
#include "getpost.h"
#include <typeinfo>
#include "persona.h"
#include "myconnection.h"

using namespace std;

int main (int argc, char* const argv[]) {
  // Para formularios
  // map<string,string> Post;
  // initializePost(Post);

  MyConnection myconnection;
  myconnection.connect();
  sql::ResultSet* personas = myconnection.query("select persona.nombre as nombre, persona.apellido as apellido, persona.dni as dni from persona");

  cout<<"Content-type: text/html"<<endl<<endl;
  cout<<"<html>"<<endl;
  cout<<"<head>"<<endl;
  cout<<"<link href='http://localhost/cgi-bin/bootstrap-4.1.3-dist/css/bootstrap.min.css' rel='stylesheet' type='text/css' />"<<endl;
  cout<<"<link href='http://localhost/css/signin.css' rel='stylesheet'>"<<endl;
  cout<<"<link href='http://localhost/css/ejemplo.css' rel='stylesheet'>"<<endl;
  cout<<"</head>"<<endl;

  cout<<"<div class='centrar'>"<<endl;
  cout<<"<h1>Listado de Personas</h1>"<<endl;
  while (personas->next()) {
    cout << personas->getString("nombre") << ", " << personas->getString("apellido") << ", " << personas->getString("dni") << "<br>" << endl;
  }

  cout<<"</div>"<<endl;
  cout<<"<br>"<<endl;
  cout<<"<button type='submit' class='btn btn-outline-success my-2 my-sm-0'>Registrarse</button>"<<endl;
  cout<<"</body>"<<endl;
  cout<<"</html>"<<endl;


  return 0;
}
