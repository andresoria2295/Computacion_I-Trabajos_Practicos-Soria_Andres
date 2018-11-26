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

/*
  if (Get.find("eliminar_id")!=Get.end()){
      persona.eliminar(Get["eliminar_id"]);
  }
*/

  if(Post.find("button_eliminar_form")!=Post.end())
  {
    persona.eliminar(Post["eliminar_id"]);
  }

/*
  if(Get.find("modificar_id")!=Get.end() && Post.find("button_cambiar")==Post.end())
  {
    persona.recibir(Get["modificar_id"],Get["dni"],Get["nombre"],Get["apellido"]);
  }
  */

  if(Post.find("button_modificar_form")!=Post.end())
  {
    persona.recibir(Post["modificar_id"],Post["dni"],Post["nombre"],Post["apellido"]);
  }

/*
  if(Get.find("asignarorg_idpersona")!=Get.end() && Post.find("button_asignar_organizacion")==Post.end())
  {
    organizacion.asignar(Get["asignarorg_idpersona"]);
  }
  */

  if(Post.find("button_asignar_organizacion_form")!=Post.end())
  {
    organizacion.asignar(Post["asignarorg_idpersona"]);

  }

/*
  if(Get.find("asignardom_idpersona")!=Get.end() && Post.find("button_asignar_domicilio")==Post.end())
  {
    domicilio.asignar(Get["asignardom_idpersona"]);
  }
*/

  if(Post.find("button_asignar_domicilio_form")!=Post.end())
  {
    domicilio.asignar(Post["asignardom_idpersona"]);

  }


  if(Post.find("button_asignar_organizacion")!=Post.end())
  {
    organizacion.setid(atol(Post["sel_idorganizacion"].c_str()));
    persona.setid(atol(Post["id_persona"].c_str()));
    string id_persona=Post["id_persona"];
    string id_organizacion=Post["sel_idorganizacion"];
    organizacion.cambiar(id_persona, id_organizacion);
  }

  if(Post.find("button_asignar_domicilio")!=Post.end())
  {
    domicilio.setid(atol(Post["sel_id_domicilio"].c_str()));
    persona.setid(atol(Post["id_persona"].c_str()));
    string id_persona=Post["id_persona"];
    string id_domicilio=Post["sel_id_domicilio"];
    domicilio.cambiar(id_persona, id_domicilio);
  }

/*
  if(Post.find("button_agregar_persona")!=Post.end() && Post.find("button_agregar_organizacion")==Post.end() && Post.find("button_agregar_domicilio")==Post.end() && Get.find("modificar_id")==Get.end() && Get.find("asignarorg_idpersona")==Get.end() && Get.find("asignardom_idpersona")==Get.end())
  {
    cout << "empieza 3" << endl;
    (new Persona())->inicio();
    (new Organizacion())->inicio();
    (new Domicilio())->inicio();
    cout << "termina 3" << endl;
  }
*/

/*
  if(Post.find("button_agregar_domicilio")==Post.end() && Get.find("modificar_id")==Get.end() && Get.find("asignarorg_idpersona")==Get.end() && Get.find("asignardom_idpersona")==Get.end())
  {
    (new Domicilio())->inicio();
  }
*/

  if(Post.find("button_cambiar")!=Post.end())
  {
    persona.setid(atol(Post["id2"].c_str()));
    persona.setNombre(Post["nombre2"]);
    persona.setApellido(Post["apellido2"]);
    persona.setDni(atol(Post["dni2"].c_str()));
  //  organizacion.setid(atol(Post["org"].c_str()));
  //  domicilio.setid(atol(Post["dom"].c_str()));
    string i=Post["id2"];
    string n=Post["nombre2"];
    string a=Post["apellido2"];
    string d=Post["dni2"];
  //  string o=Post["org"];
  //  string dom=Post["dom"];
  //  persona.modificar(i,d,n,a,o,dom);
    persona.modificar(i,d,n,a);
  }


    if(Post.find("button_agregar_organizacion")==Post.end() && Post.find("button_agregar_persona")==Post.end() && Post.find("button_agregar_domicilio")==Post.end() && Post.find("button_modificar_form")==Post.end() && Post.find("button_asignar_organizacion_form")==Post.end() && Post.find("button_asignar_domicilio_form")==Post.end())
    {
      (new Persona())->inicio();
      (new Organizacion())->inicio();
      (new Domicilio())->inicio();
    }


  if (Post.find("button_agregar_persona")!=Post.end()) {
        persona.setNombre(Post["nombre"]);
        persona.setApellido(Post["apellido"]);
        persona.setDni(atol(Post["dni"].c_str()));
        persona.agregar();
  }

  if(Post.find("button_agregar_persona")!=Post.end() && Post.find("button_agregar_organizacion")==Post.end() && Post.find("button_agregar_domicilio")==Post.end() && Post.find("button_modificar_form")==Post.end() && Post.find("button_asignar_organizacion_form")==Post.end() && Post.find("button_asignar_domicilio_form")==Post.end())
  {
    (new Persona())->inicio();
    (new Organizacion())->inicio();
    (new Domicilio())->inicio();
  }


  if(Post.find("organizacion")!=Post.end() && Post.find("button_agregar_organizacion")!=Post.end())
  {
    organizacion.setNombre(Post["organizacion"]);
    organizacion.agregar();
  }


    if(Post.find("button_agregar_organizacion")!=Post.end() && Post.find("button_agregar_persona")==Post.end() && Post.find("button_agregar_domicilio")==Post.end() && Post.find("button_modificar_form")==Post.end() && Post.find("button_asignar_organizacion_form")==Post.end() && Post.find("button_asignar_domicilio_form")==Post.end())
    {
      (new Persona())->inicio();
      (new Organizacion())->inicio();
      (new Domicilio())->inicio();
    }


  if(Post.find("button_agregar_domicilio")!=Post.end())
  {
    domicilio.setCalle(Post["calle"]);
    domicilio.setNumero(atol(Post["numero"].c_str()));
    domicilio.agregar();
  }

  if(Post.find("button_agregar_domicilio")!=Post.end() && Post.find("button_agregar_persona")==Post.end() && Post.find("button_agregar_organizacion")==Post.end() && Post.find("button_modificar_form")==Post.end() && Post.find("button_asignar_organizacion_form")==Post.end() && Post.find("button_asignar_domicilio_form")==Post.end())
  {
    (new Persona())->inicio();
    (new Organizacion())->inicio();
    (new Domicilio())->inicio();
  }


  return 0;
}
