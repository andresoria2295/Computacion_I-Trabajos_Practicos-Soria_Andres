#include <iostream>
#include <string>
// Formularios html
#include "getpost.h"
#include <typeinfo>
#include "persona.h"
#include "organizacion.h"
#include "domicilio.h"
#include "myconnection.h"

using namespace std;

int main (int argc, char* const argv[]) {
  Persona persona;
  Organizacion organizacion;
  Domicilio domicilio;
  map<string,string> Post;
  initializePost(Post);
  map<string,string> Get;
  initializeGet(Get);



  cout<<"Content-type: text/html"<<endl<<endl;







  if (Get.find("eliminar")!=Get.end()){
      persona.eliminar(Get["eliminar"]);
  }

  if (Get.find("eliminar")!=Get.end()){
      organizacion.eliminar(Get["eliminar"]);
  }

  if (Get.find("ide")!=Get.end() && Get.find("doc")!=Get.end() && Get.find("name")!=Get.end() && Get.find("lastname")!=Get.end() && Post.find("buttonchange")==Post.end() && Post.find("crear")==Post.end()){
      persona.recibir(Get["ide"],Get["doc"],Get["name"],Get["lastname"]);
  }

  if (Post.find("nombre")==Post.end() && Get.find("doc")==Get.end())
  {
      (new Persona())->inicio();

  }
  if(Post.find("organizacion")==Post.end())
  {
    (new Organizacion())->inicio();
  }
  if(Post.find("calle")==Post.end())
  {
    (new Domicilio())->inicio();
  }

  if(Post.find("dni2")!=Post.end() && Post.find("nombre2")!=Post.end() && Post.find("apellido2")!=Post.end() && Post.find("crear")==Post.end() && Post.find("crear2")==Post.end())
{
    persona.setid(atol(Post["id2"].c_str()));
    persona.setNombre(Post["nombre2"]);
    persona.setApellido(Post["apellido2"]);
    persona.setDni(atol(Post["dni2"].c_str()));
    organizacion.setid(atol(Post["org"].c_str()));
    string i=Post["id2"];
    string n=Post["nombre2"];
    string a=Post["apellido2"];
    string d=Post["dni2"];
    string o=Post["org"];
    persona.modificar(i,d,n,a,o);
    (new Persona())->inicio();
  }


  if (Post.find("nombre")!=Post.end() && Post.find("apellido")!=Post.end()) {
        cout<<"<html><head>"<<endl;
        cout<<"<link href='http://localhost/css/bootstrap.min.css' rel='stylesheet'>"<<endl;
        cout<<"<link href='http://localhost/css/signin.css' rel='stylesheet'>"<<endl;
        cout<<"<link href='http://localhost/css/ejemplo.css' rel='stylesheet'>"<<endl;
        cout << "</head>" <<endl;
        cout << "<body>   <div class='container'>"<<endl;
        cout<<"<div class='centrar'><div class='datos'>"<<endl;

        persona.setNombre(Post["nombre"]);
        persona.setApellido(Post["apellido"]);
        persona.setDni(atol(Post["dni"].c_str()));
        persona.agregar();
        cout<<"</div></div></div></body></html>"<<endl;
  }

  if(Post.find("organizacion")!=Post.end() && Post.find("crear2")!=Post.end())
  {
    organizacion.setNombre(Post["organizacion"]);
    organizacion.agregar();
  }

  if(Post.find("crear3")!=Post.end())
  {
    domicilio.setCalle(Post["calle"]);
    domicilio.setNumero(atol(Post["numero"].c_str()));
    domicilio.agregar();
  }

  return 0;
}
