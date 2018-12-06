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

    do{
       opcion = menu();		

		std::cout << CLEAR_SCREEN;
		PLACE(3,1);

        switch(opcion)
        {
           case 0: 
					std::cout << INVERSE;
					std::cout << "Fin del programa" << std::endl;
					std::cout << RESET;
			break;
            
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
	std::cout <<  "[1] Comprobar si la provincia tiene municipios";

	//////////////////////////////////////////////////////////////////////////////
	posicion++;

	PLACE(posicion++,10);
	std::cout << "[2] Cargar la provincia desde un fichero";

	PLACE(posicion++,10);
	std::cout << "[3] Grabar la provincia en un fichero";

	//////////////////////////////////////////////////////////////////////////////
	posicion++;
 
	PLACE(posicion++,10);
	std::cout << "[4] Consultar datos de la provincia";

	PLACE(posicion++,10);
	std::cout <<  "[5] Mostrar municipios de la provincia";

	PLACE(posicion++,10);
	std::cout << "[6] Modificar datos de la provincia: código o nombre";

	PLACE(posicion++,10);
	std::cout << "[7] Borrar todos los municipios de una provincia";

	//////////////////////////////////////////////////////////////////////////////
	posicion++;

	PLACE(posicion++,10);
	std::cout << "[8] Consultar un municipio";

	PLACE(posicion++,10);
	std::cout << "[9] Insertar un municipio";

	PLACE(posicion++,10);
	std::cout << "[10] Borrar un municipio";

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
