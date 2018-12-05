//clase agenda

#ifndef AGENDA_HPP
#define  AGENDA_HPP

#include <iostream>
#include <vector>
#include <string>
#include "alumno.hpp"
#include "grupo.hpp"

class Agenda{
private:
  std::vector<Alumno> vAlumnos;
  std::vector<Grupo> vGrupos;

public:

    Agenda()
    {
      setvAlumnos(NULL);
      setvGrupos(NULL);
    }

    inline void setvAlumnos(std::vector<Alumno> v)
    {
      for(int i=0; i<v.size(); i++)
      {
        vAlumnos[i]=v[i];
      }
    }

    inline void setvGrupos(std::vector<Grupo> v)
    {
      for(int i=0; i<v.size(); i++)
      {
       vGrupos[i]=v[i];
      }
    }

    inline std::vector<Alumno> getVectorAlumnos()
    {
      return vAlumnos;
    }

    inline std::vector<Grupo> getVectorGrupos()
    {
      return vGrupos;
    }

    bool isLider(std::string dni);
    void mostrarAlumnosTerminal();
    void mostrarAlumnosHTML();
    bool searchAlumnoDNI(string dni);
    void addAlumno(Alumno alumno);
    void deleteAlumno(Alumno alumno);
};


#endif
