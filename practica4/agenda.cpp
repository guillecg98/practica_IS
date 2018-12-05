//funciones clase agenda
#include "agenda.hpp"

bool Agenda::isLider(std::string dni)
{
  for(int i=0; i<vAlumnos.size(); i++)
  {
    if(vAlumnos[i].getDni() == dni)
    {
      return true;
    }
  }
  return false;
}

void Agenda::mostrarAlumnosTerminal()
{
  for(int i=0; i<vAlumnos.size(); i++)
  {
    std::cout<< "Alumno "<<i+1<<": \n";
    std::cout<<"DNI: " << vAlumnos[i].getDni() << "\n";
    std::cout<<"Nombre: " << vAlumnos[i].getNombre() << "\n";
    std::cout<<"Apellidos: " << vAlumnos[i].getApellidos() << "\n";
    std::cout<<"Telefono: " << vAlumnos[i].getTelefono() << "\n";
    std::cout<<"Fecha de Nacimiento: " << vAlumnos[i].getFechaNacimiento() << "\n";
    std::cout<<"Email: " << vAlumnos[i].getEmail() << "\n";
    std::cout<<"Curso: " << vAlumnos[i].getCurso() << "\n";
    std::cout<<"Grupo: " << vAlumnos[i].getGrupo() << "\n";

    if( isLider(vAlumnos[i].getDni()) == true )
    {
      std::cout<<"El alumno es lider\n";
    }else{
      std::cout<<"El alumno no es lider\n";
    }
  }
}

void Agenda::mostrarAlumnosHTML()
{

}

int searchAlumno(string dni){

     for(int i=0; i<vAlumnos.size(); i++)
      {
       if(vAlumnos[i].getDNI().compare(dni) == 0){
         return i;
       }
      }
      return 0;

};


void addAlumno(Alumno alumno){
  if(vAlumnos.size > 151){
    if(searchAlumno(alumno.getDni()) == 0){
      vAlumnos.push_back(alumno);}
        }
        else
        {
      printf("La lista de alumnos está llena");}
      };

void deleteAlumno(Alumno alumno){
  if(!vAlumnos.empty()){
  vAlumnos.pop_back();
  }else{
    printf("La lista está vacia");
  }
};