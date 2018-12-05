//funciones clase agenda
#include "agenda.hpp"


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