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

![Git no es GitHub](Github2.png)





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
