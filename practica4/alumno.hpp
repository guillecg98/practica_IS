#ifndef ALUMNO_HPP
#define ALUMNO_HPP

#include <iostream>
#include <string>
using namespace std;

//clase alumno
class Alumno
{
private:
  string dni_;
  string nombre_;
  string apellidos_;
  int telefono_;
  string fechaNacimiento_;
  string email_;
  int curso_;
  int grupo_;
  int lider_; // == 1 si el alumno es lider de un grupo; == 0 si el alumno no es lider

public:

  Alumno() {
    setDni("");
    setNombre("");
    setApellidos("");
    setTelefono(0);
    setFechaNacimiento("");
    setEmail("");
    setCurso(0);
    setGrupo(0);
    setLider(0);
  }

  Alumno(string dni, string nombre, string apellidos, int telefono, string fechaNacimiento, string email, int curso, int grupo, int lider) {
    setDni(dni);
    setNombre(nombre);
    setApellidos(apellidos);
    setTelefono(telefono);
    setFechaNacimiento(fechaNacimiento);
    setEmail(email);
    setCurso(curso);
    setGrupo(grupo);
    setLider(lider);
  }

  inline string getDni() const { return dni_;}
  inline string getNombre() const { return nombre_;}
  inline string getApellidos() const { return apellidos_;}
  inline int getTelefono() const { return telefono_;}
  inline string getFechaNacimiento() const { return fechaNacimiento_;}
  inline string getEmail() const { return email_;}
  inline int getCurso() const { return curso_;}
  inline int getGrupo() const { return grupo_;}
  inline int getLider() const { return lider_;}

  inline void setDni(string dni) { dni_ = dni;}
  inline void setNombre(string nombre) { nombre_ = nombre;}
  inline void setApellidos(string apellidos) { apellidos_ = apellidos;}
  inline void setTelefono(int telefono) { telefono_ = telefono;}
  inline void setFechaNacimiento(string fechaNacimiento) { fechaNacimiento_ = fechaNacimiento;}
  inline void setEmail(string email) { email_ = email;}
  inline void setCurso(int curso) { curso_ = curso;}
  inline void setGrupo(int grupo) { grupo_ = grupo;}
  inline void setLider(int lider) { lider_ = lider;}

  
};

#endif
