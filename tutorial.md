# *INTRODUCCION A GITHUB*


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
