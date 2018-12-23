#ifndef ALUMNO_HPP
#define ALUMNO_HPP

#include <iostream>
#include <string>

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

  // ------------SOBRECARGA OPERADOR ESCRITURA FICHERO -----------
  friend std::ostream & operator << (std::ostream &out, const Alumno & obj)
  { //para el dni
    int lengDni = obj.dni_.size();
    out.write(reinterpret_cast<char*>(&lengDni), sizeof(int));
    out.write(obj.dni_.c_str(), lengDni);

    //para el nombre
    int lengName = obj.nombre_.size();
    out.write(reinterpret_cast<char*>(&lengName), sizeof(int));
    out.write(obj.nombre_.c_str(), lengName);

    //para el apellido
    int lengApellido = obj.apellidos_.size();
    out.write(reinterpret_cast<char*>(&lengApellido), sizeof(int));
    out.write(obj.apellidos_.c_str(),lengApellido);

    //para el telefono
    out.write( (char*)&obj.telefono_, sizeof(obj.telefono_)); //si no funciona, probar con sizeof(int);

    //para la fecha de nacimiento
    int lengFecha = obj.fechaNacimiento_.size();
    out.write(reinterpret_cast<char*>(&lengFecha), sizeof(int));
    out.write(obj.fechaNacimiento_.c_str(),lengFecha);

    //para el email
    int lengEmail = obj.email_.size();
    out.write(reinterpret_cast<char*>(&lengEmail), sizeof(int));
    out.write(obj.email_.c_str(),lengEmail);

    //para el curso
    out.write( (char*)&obj.curso_, sizeof(obj.curso_));

    //para el grupo
    out.write( (char*)&obj.grupo_, sizeof(obj.grupo_));

    //para el lider
    out.write( (char*)&obj.lider_, sizeof(obj.lider_));

    return out;
  }

//------------SOBRECARGAR OPERADOR SALIDA FICHERO------------
  friend std::istream & operator >> (std::istream &in, Alumno &obj)
  {
    char *buff;

    //para el dni
    int lengDni = obj.dni_.size();
    in.read(reinterpret_cast<char *>(&lengDni), sizeof(int));
    buff = new char[lengDni];
    in.read( buff, lengDni);
    obj.dni_ = "";
    obj.dni_.append(buff, lengDni);

    //para el nombre
    int lengName = obj.nombre_.size();
    in.read(reinterpret_cast<char *>(&lengName), sizeof(int));
    buff = new char[lengName];
    in.read( buff, lengName);
    obj.nombre_ = "";
    obj.nombre_.append(buff, lengName);

    //para el apellido
    int lengApe = obj.apellidos_.size();
    in.read(reinterpret_cast<char *>(&lengApe), sizeof(int));
    buff = new char[lengApe];
    in.read( buff, lengApe);
    obj.apellidos_ = "";
    obj.apellidos_.append(buff, lengApe);

    //para el telefono
    in.read( (char *)&obj.telefono_, sizeof(obj.telefono_));

    //para la fecha
    int lengFecha = obj.fechaNacimiento_.size();
    in.read(reinterpret_cast<char *>(&lengFecha), sizeof(int));
    buff = new char[lengFecha];
    in.read( buff, lengFecha);
    obj.fechaNacimiento_ = "";
    obj.fechaNacimiento_.append(buff, lengFecha);

    //para el email
    //para el apellido
    int lengEmail = obj.email_.size();
    in.read(reinterpret_cast<char *>(&lengEmail), sizeof(int));
    buff = new char[lengEmail];
    in.read( buff, lengEmail);
    obj.email_ = "";
    obj.email_.append(buff, lengEmail);

    //para el curso
    in.read( (char *)&obj.curso_, sizeof(obj.curso_));

    //para el grupo
    in.read( (char *)&obj.grupo_, sizeof(obj.grupo_));

    //para el lider
    in.read( (char *)&obj.lider_, sizeof(obj.lider_));

    return in;
  }

};

#endif
