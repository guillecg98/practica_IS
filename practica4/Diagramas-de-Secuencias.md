# Diagrama de secuencia *(explicación)*

### Tenemos 10 diagramas de secuencia , uno por cada caso de uso:

1.  d0 : Diagrama de secuencia correspondiente al caso de uso con id 00.

El diagrama comienza justo al iniciar el sistema , cuando nos pide introducir el usuario para poder identificarnos como profesor ayudante o profesor coordinador.
Se le manda un mensaje al sistema con el nombre de usuario , después el sistema comprueba en el fichero de profesores que el usuario existe.
El sistema solicita una contraseña y el profesor al introducirla , se comprueba que sea correcta.
El sistema muestra el menu y las opciones de hacer copia de seguridad en caso de que sea coordinador , y solo el menu en caso de que sea ayudante.
Si se introducen mal los datos de usuario , se muestra un mensaje de error.

2.  d1 : Diagrama de secuencia correspondiente al caso de uso con id 01.

El diagrama comienza cuando el usuario (bien coordinador o bien ayudante) solicita la opcion de Cargar Fichero de alumnos en el sistema.
El sistema solicita el nombre del fichero de alumnos a cargar.
Si el fichero existe, los alumnos son cargados en el sistema.
En caso de no existir el fichero indicado se informa al usuario con un mensaje de error.

3. d2 : Diagrama de secuencia correspondiente al caso de uso con id 02.

El diagrama comienza cuando el usuario (bien coordinador o bien ayudante) solicita la opcion de Añadir un nuevo alumno al sistema.
El sistema comprueba que hay menos de 150 alumnos en ese momento, ya que es el maximo permitido.
En caso de haber 150, se informa con un mensaje de error al ususario.
En caso de que cupiese un nuevo alumno, se solicitan sus datos.
Una vez introducidos los datos se comprueba que estén correctos sin que coincidan con los datos de un alumno ya introducido (Email y DNI).

4. d3 : Diagrama de secuencia correspondiente al caso de uso con id 03.

El diagrama comienza cuando el usuario (bien coordinador o bien ayudante) solicita la opcion de guardar los datos del sistema en un fichero.
En primer lugar se comprueba que el sistema tenga datos.
Se solicita al usuario el nombre del fichero en el que se insertarán los datos del sistema.
El sistema crea un fichero binario con los datos y a continuacion borra los datos del sistema.

5. d4 : Diagrama de secuencia correspondiente al caso de uso con id 04.

El diagrama comienza cuando el usuario (bien coordinador o bien ayudante) solicita la opcion de mostrar un solo alumno del sistema.
El sistema solicita el DNI o los apellidos del alumno que se desea visualizar.
En caso de que los datos introducidos no se encuentren, se informa al usuario de que el alumno no existe mediante un mensaje de error.
En caso de que el usuario haya introducido sus Apellidos y coincidan con los de otro alumno del sistema, se solicitará el DNI.
En caso de encontrarlo se muestra al alumno en cuestion.

6. d5 : Diagrama de secuencia correspondiente al caso de uso con id 05.

El diagrama comienza cuando el usuario (bien coordinador o bien ayudante) solicita la opcion de mostrar todos los alumnos.
En primer lugar el sistema solicita al usuario el formato de visualización(Markdown o Terminal).
Si el usuario desea visualizarlo en formato markdown, se copian los datos a un archivo <fichero>.md y se enviará al usuario.
Si el usuario desea visualizarlo en formato terminal, se mostrará por pantalla la lista de alumnos y sus datos.
En caso de que en ese momento no existan alumnos en el sistema se informará al usuario con un mensaje de error.

7. d6 : Diagrama de secuencia correspondiente al caso de uso con id 06.

El diagrama comienza cuando el usuario (bien coordinador o bien ayudante) solicita la opcion de mostrar los alumnos de 1 grupo concreto.
El sistema solicita el numero del grupo que desea visualizar (recordamos que hay grupos que pueden estar formados por un unico alumno).
El sistema recoge la informacion de los alumnos del grupo indicado y los muestra por pantalla.
En caso de que el grupo indicado no exista se informará al usuario con un mensaje de error.

8. d7 : Diagrama de secuencia correspondiente al caso de uso con id 07.

El diagrama comienza cuando el usuario (bien coordinador o bien ayudante) solicita la opcion de modificar los datos de un alumno.
El sistema solicita, al igual que en la opcion de mostrar UN solo alumno, el DNI o los apellidos del alumno que desea modificar.
En caso de que los apellidos coincidan, se solicitará el DNI.
En caso de que no se encuentren los datos indicados en el sistema, se notificará al usuario con un mensaje de error indicando que el alumno no existe.
Una vez encontrado el alumno, se solicitan los nuevos datos y se modifican.

9. d8 Diagrama de secuencia correspondiente al caso de uso con id 08.

El diagrama comienza cuando el usuario (bien coordinador o bien ayudante) solicita la opcion de eliminar un alumno.
El sistema solicita el DNI del alumno que se desea eliminar.
En caso de no encontrarlo se notifica al usuario de que dicho alumno no existe.
En caso de encontrarlo se eliminan sus datos del sistema.

10. d9 Diagrama de secuencia correspondiente al caso de uso con id 09.

El diagrama comienza cuando el usuario solicita la opcion de crear copia de seguridad.
El sistema comprueba que el usuario tiene los permisos adecuados.
En caso de que no tenga permisos no podrá acceder a crear la copia de seguridad.
En caso de tener permisos, solicitara un nombre del fichero al cual se le quiere hacer la copia.
Si el fichero indicado no existe se dará un mensaje de error.
Si el fichero indicado existe se crea la copia de seguridad.

11. d10 Diagrama de secuencia correspondiente al caso de uso con id 10.

El diagrama comienza cuando el usuario solicita la opcion de cargar copia de seguridad.
El sistema comprueba que el usuario tiene los permisos adecuados.
En caso de que no tenga permisos no podrá acceder a cargar la copia de seguridad.
En caso de tener permisos, solicitara un nombre del fichero que contiene la copia de seguridad.
Si el fichero no existe se da un mensaje de error.
Si el fichero existe, se cargan en el sistema los datos de dicha copia de seguridad.
