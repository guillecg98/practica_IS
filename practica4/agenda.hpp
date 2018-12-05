//clase agenda

#ifndef AGENDA_HPP
#define  AGENDA_HPP

#include <iostream>
#include <vector>
#include <fstream>
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

    inline void cargarDatosFichero(std::string nombre)
    {
      std::ifstream f;
      f.open(nombre, std::ios::binary);
      if(!f.is_open())
      {
        std::cout<<"El fichero no se pudo abrir"<<\n;
      }
      else
      {
        //std::vector<Alumno> vAlumnos(std::istreambuf_iterator<char>(f), {});
        for(int i=0; i<vAlumnos.size(); i++)
        {
          std::ios::f>>"Alumno">>\n>>vAlumnos[i].getDni()>>\n;
          std::ios::f>>vAlumnos[i].getNombre()>>\n;
          std::ios::f>>vAlumnos[i].getApellidos()>>\n;
          std::ios::f>>vAlumnos[i].getTelefono()>>\n;
          std::ios::f>>vAlumnos[i].getFechaNacimiento()>>\n;
          std::ios::f>>vAlumnos[i].getEmail()>>\n;
          std::ios::f>>vAlumnos[i].getCurso()>>\n;
          std::ios::f>>vAlumnos[i].getGrupo()>>\n;
          std::ios::f>>vAlumnos[i].getLider()>>\n;
        }
      }
      f.close();
    }

};


#endif
