//clase agenda

#ifndef AGENDA_HPP
#define  AGENDA_HPP

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "alumno.hpp"
#include "macros.hpp"

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
    bool hayLiderGrupoAdd(int numero);
    bool hayLiderGrupoUpdate(int numero, int pos);
    void mostrarAlumnosTerminal();
    void mostrarAlumnosHTML();
    int searchAlumnoDNI(std::string dni);
    int searchAlumnoApellidos(std::string apellidos);
    bool addAlumno(Alumno alumno);
    bool deleteAlumnoDNI(std::string dni);
    bool deleteAlumnoApellidos(std::string apellidos);
    bool coincideAlumno(std::string apellidos,int pos);
    void mostrarAlumnosMismoGrupo(int grupo);
    void mostrarUnAlumnoDNI(std::string dni);
    void mostrarUnAlumnoApellidos(std::string apellidos);
    void modificarAlumnoDNI(std::string dni,int pos);
    void modificarAlumnoApellidos(std::string apellidos, int pos);
    void crearCopiaSeguridad(std::string nombre);
};


#endif
