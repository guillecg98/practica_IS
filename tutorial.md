# *INTRODUCCION A GIT*


## Configuración básica

*Nombre del Administrador:*

`git config --global user.name "Alejandro Ariza"`

*Correo electrónico:*

`git config --global user.email p42argea@uco.es`

*Editor de texto:*

`git config --global core.editor "gedit"`

*Color de la interfaz:*

`git config --global color.ui true`

*Listado de la configuración:*

`git config --list`


## USO BÁSICO

**Los tres estados de GIT**


![Imagen 1](https://git-scm.com/figures/18333fig0106-tn.png)


## Comandos Básicos I

*Iniciar repositorio en un directorio:*

`git init`

*Agregar cambios al area de staging:*

`git add`

*Validar cambios en el repositorio:*

`git commit -m "Mensaje"`

*Los dos pases anteriores en uno:*

`git commit -am "Mensaje"`

*Historial de commits:*

`git log`


## Comandos Básicos II

*Ayuda al listado anterior:*

`git help log`

*Listar los 5 commits más recientes:*

`git log -n 5`

*Listar los commits desde una fecha:*

`git log --since=2018-09-18`

*Listar los commits por autor:*

`git log --author="Alejandro"`

*Ver cambios en el directorio:*

`git status`


## Comandos Básicos III

*Ver diferencia entre ficheros en el directorio y el repositorio de git:*

`git fiff`

*Ver diferencia entre ficheros en el staging y el repositorio:*

`git diff --staged`

*Eliminar Archivos:*

~~~
git rm archivo
git commit -m "mensaje"
~~~

*Mover o renombrar archivos:*

~~~
git mv antoguo nuevo
git commit -m "mensaje"
~~~


# *INTRODUCCION A GITHUB*


## Comandos GitHub I

*Añadir repositorio remoto:*
 
`git remote add origin url`

*Ver repositorios remotos:*

`git remote -v`

*Eliminar repositorio remoto:*

`git remote rm origin`

*Añadir cambios del repositorio local al remoto:*

`git push -u origin master`

*Añadir cambios del repositorio remoto al local:*
	
`git pull`

## Comandos GitHub II

*Ver branches remotos:*

`git branch -r`

*Ver todos los branches:*

`git branch -a`

*Clonar un repositorio remoto:*

`git clone url`

## Dar seguimiento a branches remotos

### * LOCAL -> REMOTO

1. Cambios en el repositorio local.

2. Commit de los cambios.

3. Añadir cambios a repositorio remoto:

	`git push`

### * REMOTO -> LOCAL

* Sincrionización y unión:
~~~
	git fetch origin

	git merge origin/master
~~~
* En un solo paso:

`git pull`


## Operaciones con branches remotos

* Creación:

1. Crear un branch local.
2. Hacer cambios en dicho branch
3. Hacer commit
4. Copiar el branch al repositorio remoto:

`git push -u origin branch_remoto`

* Copia:

`git checkout -b local remoto`

* Eliminación:

`git push origin --delete branch_remoto`