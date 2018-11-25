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
