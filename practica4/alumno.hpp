#ifndef ALUMNO_HPP
#define ALUMNO_HPP

#include <iostream>
#include <cstring>
//clase alumno
class Alumno
{
private:
  std::string dni_;
  std::string nombre_;
  std::string apellidos_;
  int telefono_;
  std::string fechaNacimiento_;
  std::string email_;
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

  Alumno(std::string dni, std::string nombre, std::string apellidos, int telefono, std::string fechaNacimiento, std::string email, int curso, int grupo, int lider) {
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

  inline std::string getDni() const { return dni_;}
  inline std::string getNombre() const { return nombre_;}
  inline std::string getApellidos() const { return apellidos_;}
  inline int getTelefono() const { return telefono_;}
  inline std::string getFechaNacimiento() const { return fechaNacimiento_;}
  inline std::string getEmail() const { return email_;}
  inline int getCurso() const { return curso_;}
  inline int getGrupo() const { return grupo_;}
  inline int getLider() const { return lider_;}

  inline void setDni(std::string dni) { dni_ = dni;}
  inline void setNombre(std::string nombre) { nombre_ = nombre;}
  inline void setApellidos(std::string apellidos) { apellidos_ = apellidos;}
  inline void setTelefono(int telefono) { telefono_ = telefono;}
  inline void setFechaNacimiento(std::string fechaNacimiento) { fechaNacimiento_ = fechaNacimiento;}
  inline void setEmail(std::string email) { email_ = email;}
  inline void setCurso(int curso) { curso_ = curso;}
  inline void setGrupo(int grupo) { grupo_ = grupo;}
  inline void setLider(int lider) { lider_ = lider;}
};

#endif
