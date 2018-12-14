//clase agenda

#ifndef AGENDA_HPP
#define  AGENDA_HPP

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "alumno.hpp"

using namespace std;

class Agenda{
  private:
    std::vector<Alumno> vAlumnos;
  public:

    inline std::vector<Alumno> getVectorAlumnos() const { return vAlumnos;}


    inline void setvAlumnos(std::vector<Alumno> v) //esta funcion la utilizaremos para cargar los datos de un fichero al vector de alumnos.
    {
      for(int i=0; i<v.size(); i++)
      {
        vAlumnos[i]=v[i];
      }
    }

    void cargarDatosFichero(std::string nombre);
    void guardarDatosFichero(std::string nombre);
    bool isLider(std::string dni);
    void mostrarAlumnosTerminal();
    void mostrarAlumnosHTML();
    int searchAlumnoDNI(std::string dni);
    bool addAlumno(Alumno alumno);
    bool deleteAlumno(std::string dni);
    void mostrarAlumnosMismoGrupo(int grupo);
    void mostrarUnAlumno(std::string dni);
    void modificarAlumno(std::string dni,int pos);
    void crearCopiaSeguridad(std::string nombre);
};


#endif
