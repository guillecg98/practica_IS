# Diagrama de secuencia *(explicación)*

Tenemos 10 diagramas de secuencia , uno por cada caso de uso:

d0 : Diagrama de uso correspondiente al caso de uso con id 00.
El diagrama comienza justo al iniciar el sistema , cuando nos pide introducir el usuario para poder identificarnos como profesor ayudante o profesor coordinador.
Se le manda un mensaje al sistema con el nombre de usuario , después el sistema envia un mensaje al Fichero donde busca el nombre de usuario.
El sistema solicita una contraseña y el profesor al introducirla , se comprueba que sea correcta.
El sistema muestra el menu y una opcion de hacer un backup en caso de que sea coordinador , y solo el menu en caso de que sea ayudante.
Si se introducen mal los datos de usuario , se muestra un mensaje de error.


