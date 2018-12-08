#include "agenda.hpp"
#include "alumno.hpp"
//#include "grupo.hpp"
//#include "profesor.hpp"
#include "macros.hpp"

#include <iostream>
#include <string>

int menu();

int main()
{

 int opcion,op,curso,grupo,lider,telefono;
 std::string dni,nombre,apellidos,fechaNacimiento,email;
 Agenda agenda;

 do
 {
   opcion = menu();
   Alumno alumno;//se crea un alumno;
   std::cout << CLEAR_SCREEN;
   PLACE(3,1);

   switch(opcion)
   {
     case 0:
      std::cout << INVERSE;
      std::cout << "Fin del programa\n";
      std::cout << RESET;
     break;

     case 1:
      //Cargar fichero de alumnos
      std::cout<<"Esta opcion está en desarrollo\n";
     break;

     case 2:
      //Mostrar todos los alumnos
      std::cout<<"¿Cómo desea visualizarlo?\n [1] Crear Fichero HTML:\n [2] En la Terminal:\n";
      std::cin>>op;
      switch (op)
      {
        case 1:
          agenda.mostrarAlumnosHTML();
          std::cout<<"Se ha creado el fichero <alumnos.html>\n";
          break;
        case 2:
          agenda.mostrarAlumnosTerminal();
          break;
        default:
          std::cout<<"Opcion Incorrecta\n";
          break;
      }
     break;

     case 3:
      //Añadir alumno
      //se piden los datos del alumno por pantalla
      std::cout<<"DNI:\n";
      std::cin>>dni;
      alumno.setDni(dni);
      std::cout<<"Nombre:\n";
      std::cin>>nombre;
      alumno.setNombre(nombre);
      std::cout<<"Apellidos:\n";
      std::cin>>apellidos;
      alumno.setApellidos(apellidos);
      std::cout<<"Telefono:\n";
      std::cin>>telefono;
      alumno.setTelefono(telefono);
      std::cout<<"Fecha de Nacimiento:\n";
      std::cin>>fechaNacimiento;
      alumno.setFechaNacimiento(fechaNacimiento);
      std::cout<<"Email:\n";
      std::cin>>email;
      alumno.setEmail(email);
      std::cout<<"Curso:\n";
      std::cin>>curso;
      alumno.setCurso(curso);
      std::cout<<"Grupo:\n";
      std::cin>>grupo;
      alumno.setGrupo(grupo);
      std::cout<<"Lider: (0=NO, 1=SI)\n";
      std::cin>>lider;
      alumno.setLider(lider);

      if(agenda.searchAlumnoDNI(alumno.getDni()) != 0)//si el alumno existe en la lista
      {
        std::cout<<"Ya existe un alumno con ese DNI\n";
      } else{
        if(agenda.addAlumno(alumno)==true)
        {
          std::cout<<"Se ha añadido el alumno con exito\n";
        } else{
          std::cout<<"La lista de alumnos está llena\n";
        }
      }

     break;

     case 4:
      //Borrar alumno
      std::cout<<"Introduzca el DNI del alumno que quiere eliminar\n";
      //se solicita el dni del alumno que se quiere Borrar
      std::cin>>dni;

      if(agenda.searchAlumnoDNI(dni) == 0)//si el alumno no existe en la lista
      {
        std::cout<<"No existe un alumno con ese DNI\n";
      } else{
        if(agenda.deleteAlumno(dni)==true)
        {
          std::cout<<"Se ha eliminado el alumno con exito\n";
        } else{
          std::cout<<"La lista de alumnos está vacía\n";
        }

      }
     break;

   }
  }while(opcion!=0);

return 0;
}


int menu()
{
	int opcion;
	int posicion;

	// Se muestran las opciones del menú
	posicion=2;

	// Se borra la pantalla
	std::cout << CLEAR_SCREEN;

	PLACE(1,10);
	std::cout << BIBLUE;
	std::cout << "Programa principial | Opciones del menú";
	std::cout << RESET;

	//////////////////////////////////////////////////////////////////////////////
	posicion++;

	PLACE(posicion++,10);
	std::cout <<  "[1] Cargar Fichero de Alumnos";

	//////////////////////////////////////////////////////////////////////////////
	posicion++;

	PLACE(posicion++,10);
	std::cout << "[2] Mostrar Todos los Alumnos";

	PLACE(posicion++,10);
	std::cout << "[3] Añadir Alumno";

	//////////////////////////////////////////////////////////////////////////////
	posicion++;

	PLACE(posicion++,10);
	std::cout << "[4] Borrar Alumno";

	posicion++;

	PLACE(posicion++,10);
	std::cout << BIRED << "[0] Salir";

	//////////////////////////////////////////////////////////////////////////////
	posicion++;

	PLACE(posicion++,10);
	std::cout << BIGREEN;
	std::cout << "Opción: ";
	std::cout << RESET;

	// Se lee el número de opción
	std::cin >> opcion;

    // Se elimina el salto de línea del flujo de entrada
    std::cin.ignore();

	return opcion;
}
