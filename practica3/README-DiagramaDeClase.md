## Diagrama de clase *(explicación)*

En nuestro diagrama de clases podemos encontrar 4 clases distintas:

1. Clase Agenda, la cual deriva de la clase alumno. Donde crearemos todas las funciones de trata de alumnos. Usaremos un vector de alumnos y otro de grupos para guardar dichos alumnos.
2. Clase Alumno: Es la clase que usaremos para almacenar los datos de cada alumno. Con todos sus atributos y para cada uno de ellos su getter y setter.
3. Clase Profesor: La clase que añadimos en última instancia para guardar los datos del profesor y que pudiera loguearse en el sistema. Dependiendo de su rol podrá hacer o cargar copias de seguridad o n (función is_admin()).
4. Clase Grupo, la cual vuelve a derivar de la clase alumno. Donde haremos los cambios para poder controlar los grupos y comprobar el líder de cada uno de ellos. Usaremos un vector de alumnos para tales cambios.

* La clase Alumno se relaciona con la clase Agenda (cardinalidad 1:N)y con la clase Grupo (cardinalidad 0:N).
* La clase Profesor se relaciona con la clase Agenda con cardinalidad 1:N.

