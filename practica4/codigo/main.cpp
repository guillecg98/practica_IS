#include "agenda.hpp"
#include "alumno.hpp"
#include "profesor.hpp"
#include "macros.hpp"

#include <iostream>
#include <string>

int menu();
int menuP();

int main()
{

 std::cout << CLEAR_SCREEN;

 int opcion,op,curso,grupo,lider,telefono,pos;
 std::string dni,nombre,apellidos,fechaNacimiento,email,file,username, password;
 Agenda agenda;
 Alumno alumno;//se crea un alumno;
 Profesor p;

  std::cout << "Introduzca su Nombre de Usuario\n";
  std::cin >> username;
  if(!p.loginUsername(username))
  {
    std::cout << "Usuario incorrecto\n";
    return -1;
  }else {
    std::cout << "Introduzca su contraseña" << '\n';
    std::cin >> password;
    if(p.loginPassword(username, password) == false)
    {
      std::cout << "Contraseña incorrecta" << '\n';
      return -1;
    }else {
      if(p.loginId(username))
      {
        std::cout<<"\n";
        do
        {
          opcion = menuP();
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
             std::cout<<"Introduzca el nombre del fichero\n";
             std::cin>>file;
             agenda.cargarDatosFichero(file);
            break;

            case 2:
             //Guardar datos en fichero
             std::cout<<"Introduzca el nombre del fichero\n";
             std::cin>>file;
             agenda.guardarDatosFichero(file);
             break;

            case 3:
             //Mostrar todos los alumnos
             std::cout<<"¿Cómo desea visualizarlo?\n [1] Crear Fichero HTML:\n [2] En la Terminal:\n";
             std::cin>>op;
             switch (op)
             {
               case 1:
                 agenda.mostrarAlumnosHTML();
                 std::cout<<"Si su navegador no se abre automaticamente con los datos de los alumnos\nSe ha creado el fichero <alumno.html>, ejecutelo desde su carpeta\n";
                 system("xdg-open alumno.html &"); //Abrimos el fichero generado con el navegador por defecto
                 break;
               case 2:
                 agenda.mostrarAlumnosTerminal();


                      std::cout << "Pulse ";
                      std::cout << BIGREEN;
                      std::cout << "ENTER";
                      std::cout << RESET;
                      std::cout << " para mostrar el ";
                      std::cout << INVERSE;
                      std::cout << "menú";
                      std::cout << RESET;

                      // Pausa
                      std::cin.ignore();
                      std::cin.ignore();


                      std::cout << CLEAR_SCREEN;
                 break;
               default:
                 std::cout<<"Opcion Incorrecta\n";
                 break;
             }
             break;

            case 4:
             //Añadir alumno
             std::cout<<"Introduzca los Datos del nuevo alumno\n";
             //se piden los datos del alumno por pantalla
             std::cout<<"1.DNI: ";
             std::cin>>dni;
             alumno.setDni(dni);
             std::cout<<"2.Nombre: ";
             std::cin>>nombre;
             alumno.setNombre(nombre);
             std::cout<<"3.Apellidos: ";
             std::getline(std::cin,apellidos);
             std::getline(std::cin,apellidos);
             alumno.setApellidos(apellidos);
             std::cout<<"4.Telefono: ";
             std::cin>>telefono;
             alumno.setTelefono(telefono);
             std::cout<<"5.Fecha de Nacimiento: ";
             std::cin>>fechaNacimiento;
             alumno.setFechaNacimiento(fechaNacimiento);
             std::cout<<"6.Email: ";
             std::cin>>email;
             alumno.setEmail(email);
             std::cout<<"7.Curso: ";
             std::cin>>curso;
             alumno.setCurso(curso);
             std::cout<<"8.Grupo: ";
             std::cin>>grupo;
             alumno.setGrupo(grupo);
             if(agenda.hayLiderGrupoAdd(alumno.getGrupo()))
             {
               std::cout<<"El alumno que está añadiendo no puede ser lider del grupo debido a que ya hay un lider en el mismo\n";
               alumno.setLider(0);
             }else {
               std::cout<<"9.Lider (0=NO, 1=SI): ";
               std::cin>>lider;
               alumno.setLider(lider);
             }
             if(agenda.searchAlumnoDNI(alumno.getDni()) != -1)//si el alumno existe en la lista
             {
               std::cout<<"\n";
               std::cout<<"Error: Ya existe un alumno con ese DNI\n";
             } else{
               if(agenda.addAlumno(alumno)==true)
               {
                 std::cout<<"\n";
                 std::cout<<"Se ha añadido el alumno con éxito\n";
               } else{
                 std::cout<<"\n";
                 std::cout<<"Error: La lista de alumnos está llena\n";
               }
             }
             break;

            case 5:
             //Borrar alumno
             std::cout<<"Introduzca los apellidos del alumno que quiere eliminar:\n";
             std::getline(std::cin,apellidos);
             if(agenda.searchAlumnoApellidos(apellidos) == -1)//no existe en la agenda
             {
               std::cout<<"No se ha encontrado un alumno con esos apellidos.\n";
               //se solicita el dni del alumno que se quiere Borrar
               std::cout<<"Introduzca el DNI del alumno que quiere eliminar:\n";
               std::cin>>dni;
               if(agenda.searchAlumnoDNI(dni) == -1)//si el alumno no existe en la lista
               {
                 std::cout<<"No existe un alumno con ese DNI\n";
               }else {
                 if(agenda.deleteAlumnoDNI(dni)==true)
                 {
                   std::cout<<"Se ha eliminado el alumno con exito\n";
                 }else {
                   std::cout<<"La lista de alumnos está vacía\n";
                 }
               }
             }else {//si existe
               if(agenda.coincideAlumno(apellidos,agenda.searchAlumnoApellidos(apellidos)))//si los apellidos del alumno coinciden con los de otro, se solicita DNI
               {
                 std::cout<<"Hay dos o más alumnos con ese Apellido, porfavor especifique su DNI:\n";
                 std::cin>>dni;
                 if(agenda.searchAlumnoDNI(dni) == -1)//si el alumno no existe en la lista
                 {
                   std::cout<<"No existe un alumno con ese DNI\n";
                 }else {
                   if(agenda.deleteAlumnoDNI(dni)==true)
                   {
                     std::cout<<"Se ha eliminado el alumno con exito\n";
                   }else {
                     std::cout<<"La lista de alumnos está vacía\n";
                   }
                 }
               }else {
                 if(agenda.deleteAlumnoApellidos(apellidos)==true)
                 {
                   std::cout<<"Se ha eliminado el alumno con exito\n";
                 }else {
                   std::cout<<"La lista de alumnos está vacía\n";
                 }
               }
             }
             break;

            case 6:
            //Mostrar Alumnos de un grupo
            std::cout<<"Introduzca numero de grupo:\n";
            std::cin>>grupo;
            agenda.mostrarAlumnosMismoGrupo(grupo);
            break;

            case 7:
             //Modificar alumno
             std::cout<<"Introduzca los apellidos del alumno que quiere eliminar:\n";
             std::getline(std::cin,apellidos);
             if(agenda.searchAlumnoApellidos(apellidos) == -1)//no existe en la agenda
             {
               std::cout<<"No se ha encontrado un alumno con esos apellidos.\n";
               //se solicita el dni del alumno que se quiere Borrar
               std::cout<<"Introduzca el DNI del alumno que quiere eliminar:\n";
               std::cin>>dni;
               pos = agenda.searchAlumnoDNI(dni);
               if(pos != -1)//si se encuentra alumno por su dni
               {
                 agenda.modificarAlumnoDNI(dni,pos);
               }else {
                 std::cout<<"No existe un alumno con el DNI indicado.\n";
               }
             }else { //los apellidos existen en la agenda
               if(agenda.coincideAlumno(apellidos,agenda.searchAlumnoApellidos(apellidos)))//si los apellidos del alumno coinciden con los de otro, se solicita DNI
               {
                 std::cout<<"Hay dos o más alumnos con ese Apellido, porfavor especifique su DNI:\n";
                 std::cin>>dni;
                 pos = agenda.searchAlumnoDNI(dni);
                 if(pos != -1)//si se encuentra alumno por su dni
                 {
                   agenda.modificarAlumnoDNI(dni,pos);
                 }else {
                   std::cout<<"No existe un alumno con el DNI indicado.\n";
                 }
               }else {
                 agenda.modificarAlumnoApellidos(apellidos,agenda.searchAlumnoApellidos(apellidos));
               }
             }
            break;

            case 8:
            //MOstrar UN alumno
            std::cout<<"Introduzca los apellidos del alumno que quiere eliminar:\n";
            std::getline(std::cin,apellidos);
            if(agenda.searchAlumnoApellidos(apellidos) == -1)//no existe en la agenda
            {
              std::cout<<"No se ha encontrado un alumno con esos apellidos.\n";
              //se solicita el dni del alumno que se quiere Borrar
              std::cout<<"Introduzca el DNI del alumno que quiere eliminar:\n";
              std::cin>>dni;
              agenda.mostrarUnAlumnoDNI(dni);
            }else { //existe alumno
              if(agenda.coincideAlumno(apellidos,agenda.searchAlumnoApellidos(apellidos)))//si los apellidos del alumno coinciden con los de otro, se solicita DNI
              {
                std::cout<<"Hay dos o más alumnos con ese Apellido, porfavor especifique su DNI:\n";
                std::cin>>dni;
                agenda.mostrarUnAlumnoDNI(dni);
              }else {
                agenda.mostrarUnAlumnoApellidos(apellidos);
              }
            }
             break;


            case 9:
              //opcion a desarrollar de Crear Copia de seguridad
              std::cout<<"Introduzca el fichero del cual quiere crear la copia\n";
              std::cin>>file;
              agenda.crearCopiaSeguridad(file);
              break;

            case 10:
              //opcion a desarrollar de cargar copia de seguridad
              std::cout<<"Introduzca el nombre de la copia de seguridad a cargar\n";
              std::cin>>file;
              agenda.cargarDatosFichero(file);
              std::cout<<"Se han cargado los datos de la copia: <"<<file<<">\n";

              break;

              default:
                std::cout << BIRED;
  				      std::cout << "Opción incorrecta ";
  				      std::cout << RESET;
  				      std::cout << "--> ";
  			  	    std::cout << ONIRED;
  				      std::cout << opcion << std::endl;
  				      std::cout << RESET;
                break;
            }
            if (opcion !=0 && opcion !=3)
            {
              PLACE(25,1);
              std::cout << "Pulse ";
              std::cout << BIGREEN;
              std::cout << "ENTER";
              std::cout << RESET;
              std::cout << " para mostrar el ";
              std::cout << INVERSE;
              std::cout << "menú";
              std::cout << RESET;

              // Pausa
              std::cin.ignore();
              std::cin.ignore();

              std::cout << CLEAR_SCREEN;
            }

         }while(opcion!=0);

      }else {
        std::cout<<"\n";
        do
        {
          //------------------------------------/MENU SIN PRIVILEGIOS-------------------------------
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
             std::cout<<"Introduzca el nombre del fichero\n";
             std::cin>>file;
             agenda.cargarDatosFichero(file);
            break;

            case 2:
             //Guardar datos en fichero
             std::cout<<"Introduzca el nombre del fichero\n";
             std::cin>>file;
             agenda.guardarDatosFichero(file);
             break;

            case 3:
             //Mostrar todos los alumnos
             std::cout<<"¿Cómo desea visualizarlo?\n [1] Crear Fichero HTML:\n [2] En la Terminal:\n";
             std::cin>>op;
             switch (op)
             {
               case 1:
                 agenda.mostrarAlumnosHTML();
                 std::cout<<"Si su navegador no se abre automaticamente con los datos de los alumnos\nSe ha creado el fichero <alumno.html>, ejecutelo desde su carpeta\n";
                 system("xdg-open alumno.html &"); //Abrimos el fichero generado con el navegador por defecto
                 break;
               case 2:
                 agenda.mostrarAlumnosTerminal();


                      std::cout << "Pulse ";
                      std::cout << BIGREEN;
                      std::cout << "ENTER";
                      std::cout << RESET;
                      std::cout << " para mostrar el ";
                      std::cout << INVERSE;
                      std::cout << "menú";
                      std::cout << RESET;

                      // Pausa
                      std::cin.ignore();
                      std::cin.ignore();


                      std::cout << CLEAR_SCREEN;
                 break;
               default:
                 std::cout<<"Opcion Incorrecta\n";
                 break;
             }
             break;

            case 4:
             //Añadir alumno
             std::cout<<"Introduzca los Datos del nuevo alumno\n";
             //se piden los datos del alumno por pantalla
             std::cout<<"1.DNI: ";
             std::cin>>dni;
             alumno.setDni(dni);
             std::cout<<"2.Nombre: ";
             std::cin>>nombre;
             alumno.setNombre(nombre);
             std::cout<<"3.Apellidos: ";
             std::getline(std::cin,apellidos);
             std::getline(std::cin,apellidos);
             alumno.setApellidos(apellidos);
             std::cout<<"4.Telefono: ";
             std::cin>>telefono;
             alumno.setTelefono(telefono);
             std::cout<<"5.Fecha de Nacimiento: ";
             std::cin>>fechaNacimiento;
             alumno.setFechaNacimiento(fechaNacimiento);
             std::cout<<"6.Email: ";
             std::cin>>email;
             alumno.setEmail(email);
             std::cout<<"7.Curso: ";
             std::cin>>curso;
             alumno.setCurso(curso);
             std::cout<<"8.Grupo: ";
             std::cin>>grupo;
             alumno.setGrupo(grupo);
             if(agenda.hayLiderGrupoAdd(alumno.getGrupo()))
             {
               std::cout<<"El alumno que está añadiendo no puede ser lider del grupo debido a que ya hay un lider en el mismo\n";
               alumno.setLider(0);
             }else {
               std::cout<<"9.Lider (0=NO, 1=SI): ";
               std::cin>>lider;
               alumno.setLider(lider);
             }
             if(agenda.searchAlumnoDNI(alumno.getDni()) != -1)//si el alumno existe en la lista
             {
               std::cout<<"\n";
               std::cout<<"Error: Ya existe un alumno con ese DNI\n";
             } else{
               if(agenda.addAlumno(alumno)==true)
               {
                 std::cout<<"\n";
                 std::cout<<"Se ha añadido el alumno con éxito\n";
               } else{
                 std::cout<<"\n";
                 std::cout<<"Error: La lista de alumnos está llena\n";
               }
             }
             break;

            case 5:
             //Borrar alumno
             std::cout<<"Introduzca los apellidos del alumno que quiere eliminar:\n";
             std::getline(std::cin,apellidos);
             if(agenda.searchAlumnoApellidos(apellidos) == -1)//no existe en la agenda
             {
               std::cout<<"No se ha encontrado un alumno con esos apellidos.\n";
               //se solicita el dni del alumno que se quiere Borrar
               std::cout<<"Introduzca el DNI del alumno que quiere eliminar:\n";
               std::cin>>dni;
               if(agenda.searchAlumnoDNI(dni) == -1)//si el alumno no existe en la lista
               {
                 std::cout<<"No existe un alumno con ese DNI\n";
               }else {
                 if(agenda.deleteAlumnoDNI(dni)==true)
                 {
                   std::cout<<"Se ha eliminado el alumno con exito\n";
                 }else {
                   std::cout<<"La lista de alumnos está vacía\n";
                 }
               }
             }else {//si existe
               if(agenda.coincideAlumno(apellidos,agenda.searchAlumnoApellidos(apellidos)))//si los apellidos del alumno coinciden con los de otro, se solicita DNI
               {
                 std::cout<<"Hay dos o más alumnos con ese Apellido, porfavor especifique su DNI:\n";
                 std::cin>>dni;
                 if(agenda.searchAlumnoDNI(dni) == -1)//si el alumno no existe en la lista
                 {
                   std::cout<<"No existe un alumno con ese DNI\n";
                 }else {
                   if(agenda.deleteAlumnoDNI(dni)==true)
                   {
                     std::cout<<"Se ha eliminado el alumno con exito\n";
                   }else {
                     std::cout<<"La lista de alumnos está vacía\n";
                   }
                 }
               }else {
                 if(agenda.deleteAlumnoApellidos(apellidos)==true)
                 {
                   std::cout<<"Se ha eliminado el alumno con exito\n";
                 }else {
                   std::cout<<"La lista de alumnos está vacía\n";
                 }
               }
             }
             break;

            case 6:
            //Mostrar Alumnos de un grupo
            std::cout<<"Introduzca numero de grupo:\n";
            std::cin>>grupo;
            agenda.mostrarAlumnosMismoGrupo(grupo);
            break;

            case 7:
             //Modificar alumno
             std::cout<<"Introduzca los apellidos del alumno que quiere eliminar:\n";
             std::getline(std::cin,apellidos);
             if(agenda.searchAlumnoApellidos(apellidos) == -1)//no existe en la agenda
             {
               std::cout<<"No se ha encontrado un alumno con esos apellidos.\n";
               //se solicita el dni del alumno que se quiere Borrar
               std::cout<<"Introduzca el DNI del alumno que quiere eliminar:\n";
               std::cin>>dni;
               pos = agenda.searchAlumnoDNI(dni);
               if(pos != -1)//si se encuentra alumno por su dni
               {
                 agenda.modificarAlumnoDNI(dni,pos);
               }else {
                 std::cout<<"No existe un alumno con el DNI indicado.\n";
               }
             }else { //los apellidos existen en la agenda
               if(agenda.coincideAlumno(apellidos,agenda.searchAlumnoApellidos(apellidos)))//si los apellidos del alumno coinciden con los de otro, se solicita DNI
               {
                 std::cout<<"Hay dos o más alumnos con ese Apellido, porfavor especifique su DNI:\n";
                 std::cin>>dni;
                 pos = agenda.searchAlumnoDNI(dni);
                 if(pos != -1)//si se encuentra alumno por su dni
                 {
                   agenda.modificarAlumnoDNI(dni,pos);
                 }else {
                   std::cout<<"No existe un alumno con el DNI indicado.\n";
                 }
               }else {
                 agenda.modificarAlumnoApellidos(apellidos,agenda.searchAlumnoApellidos(apellidos));
               }
             }
            break;

            case 8:
            //MOstrar UN alumno
            std::cout<<"Introduzca los apellidos del alumno que quiere eliminar:\n";
            std::getline(std::cin,apellidos);
            if(agenda.searchAlumnoApellidos(apellidos) == -1)//no existe en la agenda
            {
              std::cout<<"No se ha encontrado un alumno con esos apellidos.\n";
              //se solicita el dni del alumno que se quiere Borrar
              std::cout<<"Introduzca el DNI del alumno que quiere eliminar:\n";
              std::cin>>dni;
              agenda.mostrarUnAlumnoDNI(dni);
            }else { //existe alumno
              if(agenda.coincideAlumno(apellidos,agenda.searchAlumnoApellidos(apellidos)))//si los apellidos del alumno coinciden con los de otro, se solicita DNI
              {
                std::cout<<"Hay dos o más alumnos con ese Apellido, porfavor especifique su DNI:\n";
                std::cin>>dni;
                agenda.mostrarUnAlumnoDNI(dni);
              }else {
                agenda.mostrarUnAlumnoApellidos(apellidos);
              }
            }
             break;

            default:
              std::cout << BIRED;
				      std::cout << "Opción incorrecta ";
				      std::cout << RESET;
				      std::cout << "--> ";
			  	    std::cout << ONIRED;
				      std::cout << opcion << std::endl;
				      std::cout << RESET;
              break;
          }
          if (opcion !=0 && opcion != 3)
          {
            PLACE(25,1);
            std::cout << "Pulse ";
            std::cout << BIGREEN;
            std::cout << "ENTER";
            std::cout << RESET;
            std::cout << " para mostrar el ";
            std::cout << INVERSE;
            std::cout << "menú";
            std::cout << RESET;

            // Pausa
            std::cin.ignore();
            std::cin.ignore();


            std::cout << CLEAR_SCREEN;
          }
         }while(opcion!=0);
      }
    }
  }

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

  posicion++;

	PLACE(posicion++,10);
	std::cout <<  "[2] Guardar los datos en un Fichero";

	//////////////////////////////////////////////////////////////////////////////
	posicion++;

	PLACE(posicion++,10);
	std::cout << "[3] Mostrar Todos los Alumnos";

  posicion++;

	PLACE(posicion++,10);
	std::cout << "[4] Añadir Alumno";

	//////////////////////////////////////////////////////////////////////////////
	posicion++;

	PLACE(posicion++,10);
	std::cout << "[5] Borrar Alumno";

  	posicion++;

	PLACE(posicion++,10);
	std::cout << "[6] Mostrar alumnos mismo grupo";

  posicion++;

  PLACE(posicion++,10);
  std::cout << "[7] Modificar alumno";

  posicion++;

  PLACE(posicion++,10);
  std::cout << "[8] Mostrar un solo alumno";

  	//////////////////////////////////////////////////////////////////////////////
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

int menuP() //Este es el menu que se le mostrará a los usuarios privilegiados
{
	int opcion;
	int posicion;

	// Se muestran las opciones del menú
	posicion=2;

	// Se borra la pantalla
	std::cout << CLEAR_SCREEN;

	PLACE(1,10);
	std::cout << BIBLUE;
	std::cout << "Programa principial (USUARIO PRIVILEGIADO) | Opciones del menú";
	std::cout << RESET;

	//////////////////////////////////////////////////////////////////////////////
	posicion++;

	PLACE(posicion++,10);
	std::cout <<  "[1] Cargar Fichero de Alumnos";

  posicion++;

	PLACE(posicion++,10);
	std::cout <<  "[2] Guardar los datos en un Fichero";

	//////////////////////////////////////////////////////////////////////////////
	posicion++;

	PLACE(posicion++,10);
	std::cout << "[3] Mostrar Todos los Alumnos";

  posicion++;

	PLACE(posicion++,10);
	std::cout << "[4] Añadir Alumno";

	//////////////////////////////////////////////////////////////////////////////
	posicion++;

	PLACE(posicion++,10);
	std::cout << "[5] Borrar Alumno";

  	posicion++;

	PLACE(posicion++,10);
	std::cout << "[6] Mostrar alumnos mismo grupo";

  posicion++;

  PLACE(posicion++,10);
  std::cout << "[7] Modificar alumno";

  posicion++;

  PLACE(posicion++,10);
  std::cout << "[8] Mostrar un solo alumno";

  posicion++;

  PLACE(posicion++,10);

  std::cout << "[9] Crear Copia de Seguridad";

  posicion++;

  PLACE(posicion++,10);
  std::cout << "[10] Cargar Copia de Seguridad";

	//////////////////////////////////////////////////////////////////////////////
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
