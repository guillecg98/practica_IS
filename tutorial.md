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

## Comandos básicos IV

*Deshacer cambios con git:*

`Git Checkout -- Nombre_fichero`

*Retirar archivos del staging: *

`git reset HEAD nombre_fichero`

*Complementar último commit: *
 
`git commit --amend -m "Mensaje"`

*Recuperar version de un fichero de commit antiguo:*

`git checkout <id_commit> -- nombre_archivo`

*Revertir un commit:*

`git revert <id_commit>`

## Comandos básicos V

*Deshacer multiples cambios en el repositorio:*

`git reset --soft <id_commit>`

`git reset --mixed <id_commit>`

`git reset --hard <id_commit>`

*Listar archivos que git no controla:*

`git clean -n`

*Eliminar archivos que git no controla:*

`git clean -f`

*Ignorar archivos en el repositorio:*

`.gitignore`

## Comandos básicos VI

*Listar el contenido del repositorio de git:*

`git ls-tree master`

`git ls-tree masterˆˆˆ`

`git ls-tree master ̃3`

*Log en una línea:*

`git log --oneline`

*Log con los tres últimos commits en una línea:*

`git log --oneline -3`


## Comandos básicos VII

*Examinar el contenido de un commit:*

`git show <id>`

*Comparar un commit con el actual:*

`git diff <id> nombre_archivo`

*Comparar dos commits:*

`git diff id..id nombre_archivo`


## Comandos Ramas I

*Ver listado de ramas:*

`git branch`

*Crear una rama:*

`git branch nombre_rama`

*Cambiarnos a una rama:*

`git checkout nombre_rama`

*Crear una rama y moverse en un paso:*

`git checkout -b nombre_rama`

*Comparar ramas:*

`git diff nombre_rama .. nombre_rama`

## Comandos Ramas II

*Ver ramas id´enticas a la actual:*

`git branch -- merged`

*Renombrar ramas:*

`git branch -m nombre_antiguo nombre_nuevo`

*Eliminar ramas*

~~~
git branch -d nombre_rama

git branch -D nombre_rama
~~~

*Integrar ramas a la actual:*

`git merge nombre_rama`

*Resolver conflictos (se suele hacer manualmente):*

`git merge -- abort`

## Comandos Ramas III

*Almacenar cambios temporales:*

`git stash save " Mensaje "`

*Listar cambios:*

`git stash list`

*Ver contenido de un cambio temporal:*

`git stash show -p nombre_stash`

*Eliminar un cambio temporal:*

`git stash drop nombre_stash`

*Aplicar cambio del stash:*
~~~
git stash apply nombre_stash`

git stash pop nombre_stash
~~~

![Git no es GitHub](http://www.klebercarvalho.com/blog/wp-content/uploads/2018/08/Github2.png)



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
