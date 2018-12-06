//clase grupo
#ifndef GRUPO_HPP
#define GRUPO_HPP

#include <iostream>
#include <string>

class Grupo
{
private:
    int idGrupo_;
    std::vector<Alumno> vAlumnos_;

public:

    Grupo(int idGrupo , std::vector<Alumno> vAlumnos){
        setIdGrupo(idGrupo);
        setvAlumnos(vAlumnos);
    };

    void setIdGrupo(int idGrupo){idGrupo_ = idGrupo;};
    void setvAlumnos(std::vector<Alumno> vAlumnos){vAlumnos_ = vAlumnos;};//esta función habria que ver si hace falta
    
    int getIdGrupo(){return idGrupo_;};
    std::vector<Alumno> getvAlumnos(){return vAlumnos_;};

    bool comprobarLider();//comprueba si hay un lider en el grupo indicado

};

#endif