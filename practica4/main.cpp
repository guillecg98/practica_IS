#include "agenda.hpp"
#include "alumno.hpp"
#include "grupo.hpp"
#include "profesor.hpp"

#include <iostream>
#include <string>
#include "macros.hpp"


int main()
{

 int opcion;
 Agenda agenda;

 do
 {
   opcion = menu();
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
     break;

     case 2:
      //Mostrar todos los alumnos
     break;

     case 3:
      //Añadir alumno
      Alumno alumno;
      //se piden los datos del alumno por pantalla
      if(agenda.searchAlumno(alumno.getDni()) != 0)//si el alumno existe en la lista
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
      //se solicita el dni del alumno que se quiere Borrar
      if(agenda.searchAlumno(alumno.getDni()) == 0)//si el alumno existe en la lista
      {
        std::cout<<"No existe un alumno con ese DNI\n";
      } else{
        if(agenda.deleteAlumno(/*dni*/)==true)
        {
          std::cout<<"Se ha eliminado el alumno con exito\n";
        } else{
          std::cout<<"La lista de alumnos está vacía\n";
        }

      }
     break;

   }
  }(while (opcion!=0);

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
