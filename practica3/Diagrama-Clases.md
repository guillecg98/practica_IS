## Diagrama de clase *(explicación)*

En nuestro diagrama de clases podemos encontrar 3 clases distintas:

1. Clase Agenda, la cual representa el objeto de una lista de alumnos. Donde crearemos todas las funciones de gestión de alumnos. Usaremos un vector de alumnos para guardar los datos de la agenda.
2. Clase Alumno, la cual representa un alumno de la vida real. Clase que usaremos para almacenar los datos de cada alumno (atributos) y para cada uno de ellos sus getters y setters.
3. Clase Profesor, la cual representa un profesor que gestiona la lista de alumnos. La clase que interactuará con la Agenda. Cada profesor podrá loguearse en el sistema y dependiendo de su rol podrá crear/cargar copias de seguridad o no.

* La clase Alumno se relaciona con la clase Agenda (cardinalidad 1:N)y con la clase Grupo (cardinalidad 0:N).
* La clase Profesor se relaciona con la clase Agenda con cardinalidad 1:N.

