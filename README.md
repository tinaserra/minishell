# Minishell
Aussi mignon qu’un vrai shell

## TO DO !!

### Ces cas de pipe

- [ ] ```echo puta madre | cat -e```
```
admin ➜ minishell1 echo puta madre | cat -e
puta madre$
free(): invalid pointer
[1]    18526 abort      ./minishell
```
- [ ] ```cat | ls```
- [ ] ```ls -la | rev | cat -e```
- [ ] ```cat /dev/random | head -c 10```

### ```echo```

- [ ] plusieurs arguments (strings)
- [ ] gerer les guillemets & backslash
- [x] les variables d'environnement
- [ ] les redirections (vers un fichier, vers une variable d'env...) ⚠️ a ```cat```
- [ ] Pipe ?? ⚠️ a ```cat```
- [ ] $? -> retourne le code erreur de la derniere commande

[man echo baby !](http://marionpatrick.free.fr/man_html/html/tuto_shell.html#chp3.3.2.3)

### ```cd```

- [ ] 1 argument : le path
- [ ] attention au ```cd ..``` etc

## ```pwd```

- [ ] Pas d'arguments, ou alors **ignorés**
- [ ] Pipe ?? ⚠️ a ```cat -e```

## ```export```

- [ ] ```export``` *(sans arguments)* : print la liste des variables d'environnement dans l'ordre ascii
- [ ] *avec arguments* : gerer les differentes possibilités de format ```$variable``` ou ```${variable}``` ou ```“$variable”``` ou ```"${variable}"```
- [ ] ```export nom_variable``` Exportation de la variable dans les processus fils.
- [ ] ```export nom_variable=value``` Assignation et exportation de la variable dans les processus fils.

## ```env```

- [ ] print la liste des variables d'environnement.
- [ ] print les variables ajoutêes par ```export```
- [ ] Attention aux variables que la commante ```exort``` affiche mais que ```env``` ne doit pas afficher

## ```unset```
## ```exit```


### Usage 🧐

Start
```
make && ./minishell
```

## INTRODUCTION 🤓

Sujet -> [EN](https://github.com/tinaserra/minishell/blob/master/links/minishell_en.pdf) | [FR](https://github.com/tinaserra/minishell/blob/master/links/minishell_fr.pdf)
Scale de correction -> [EN](https://github.com/tinaserra/minishell/blob/master/links/scale)

## Doc & Lexique des fonctions autorisées

* ```fork``` : crée un process child qui est une copie du process parent

* ```wait``` : suspend le processus appelant jusqu'à ce que l'un de ses childs se termine

* ```waitpid``` : susprend le processus appelant jusqu'à ce que le child spécifié dans le pid ait changé d'état

* ```wait3``` : La même chose que waitpid mais retourne des informations sur l'utilisation des ressources par le child depuis la struct rusage

* ```wait4``` : La même chose que wait3 mais contrairement à wait3 qui prend tout les childs, wait4 peut en spécifier qu'un seul

* ```signal``` : gestion de signaux, en fonction du gestionnaire il peut ignoré comme faire des actions en fonction des signaux

* ```kill``` : envoi un signal à un processus, le signal dépend du pid

* ```getcwd``` : copie le chemin d'accès absolu du répertoire de travail courant dans la chaîne pointée par buf, qui est de longueur size

* ```chdir``` : remplace le répertoire de travail courant du processus appelant par celui indiqué dans le chemin path -- utile pour la commande "cd"

* ```stat``` : récupère l'état du fichier pointé par path et remplit le tampon buf, remplit une structure d'informations sur un fichier -- utile pour la commande "ls"

* ```lstat``` : est identique à stat(), sauf que si path est un lien symbolique, il donne l'état du lien lui-même plutôt que celui du fichier visé

* ```fstat``` : est identique à stat(), sauf que le fichier ouvert est pointé par le descripteur fd

* ```execve``` : execute le fichier en arguments -- utile pour la commande "./"

* ```dup``` : return une copie du descripteur de fichier en arguments

* ```dup2``` : pareil que dup mais avec des sécurités et un new fd spécifique

* ```pipe``` : tube avec 2 descripteurs de fichier, une extrémité du tube écrit et met dans un tampon en attendant que l'autre extrémité la lise

* ```opendir``` : open classique mais pour un répertoire

* ```readdir``` : consulter / lire un répertoire -- utile pour "ls" ?

* ```closedir``` : ferme le répertoire qui a été ouvert avec opendir

* ```strerror``` : Obtenir un message en fonction du code erreur -- utile pour la gestion d'erreur

* ```errno``` : code de la dernière erreur

* ```isatty``` : booléen, renvoi 1 si desc est un descripteur de fichier ouvert connecté à un terminal, sinon 0

* ```ttyname``` : si le fd est connecté à un terminal il retourne le chemin (absolu ?) dans un char*

* ```ttyslot``` : renvoie la position de l'entrée du terminal en cours dans un fichier

* ```ioctl``` : Contrôler les périphériques (pas bien compris) -- utile pour avoir la taille du terminal

* ```getenv``` : prend une variable d'env et retourne la value de la variable dans un char *


## USEFULL LINKS 🤙🏼

[usefull](https://github.com/lucielebriquer)
[man strerror](http://manpagesfr.free.fr/man/man3/strerror.3.html)</br>
[man erno](http://manpagesfr.free.fr/man/man3/errno.3.html)</br>
[man BASH](http://manpagesfr.free.fr/man/man1/bash.1.html)</br>
[TUTO SHELL](http://marionpatrick.free.fr/man_html/html/tuto_shell.html)

## Comment utiliser Git en multi ?

[Readme 😏](https://github.com/tinaserra/minishell/blob/master/links/git.md)
Git: [pense-bête](http://www.letuyau.net/2012/09/git-pense-bete/)