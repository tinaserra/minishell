# Minishell 🌈
Aussi mignon qu’un vrai shell

### Usage
Start
```
make && ./minishell
```

### Sommaire 🧐

* 1. Sujet
* 2. Parsing
* 3. Buildtins
* 4. Exécution
* 5. Gestion d'erreur

### TO DO !!
Liste non exaustive des [Failed tests](https://github.com/tinaserra/minishell/blob/master/links/tests.md)

## Introduction 🤓
Sujet -> [EN](https://github.com/tinaserra/minishell/blob/master/links/minishell_en.pdf)</br>
Scale de correction -> [EN](https://github.com/tinaserra/minishell/blob/master/links/scale)

### 1. Sujet
L'objectif du projet est de creer notre propre shell.

#### Qu'est-ce qu'un shell ?
Le shell c'est en quelque sorte l'interface utilisaeur d'un systeme. Il permet à l'utilisateur de communiquer avec le système d’exploitation par l'intermédiaire de commandes. L'utilisateur rentre des commandes dans le terminal et grâce à l’interpréteur de commande (tel que bash ou zsh qui sont des shells), les commandes entrées sont exécutées.

#### Precisions
* Le sujet de minishell a eu plusieurs mises a jour. Ici nous ne faisons pas les termcaps (utilisation de ```readline```, ```rl_clear_history```, ...).
* Nous avons adapte pour utiliser qu'une seule variable globale.
* Nous interpretons les special characters ```\``` or ```;```, mais dans la maj du sujet on n'est pas obliges de le faire.

## 2. Parsing 🤯

## 3. Buildtins 👾

### ```echo```
- [x] les redirections (vers un fichier, vers une variable d'env...) ⚠️ a ```cat```
- [ ] Pipe ?? ⚠️ a ```cat```
- [ ] $? -> retourne le code erreur de la derniere commande
[man echo baby !](http://marionpatrick.free.fr/man_html/html/tuto_shell.html#chp3.3.2.3)

### ```pwd```
- [ ] Pas d'arguments, ou alors **ignorés**
- [ ] Pipe ?? ⚠️ a ```cat -e```

### ```export```
- [ ] ```export``` *(sans arguments)* : print la liste des variables d'environnement dans l'ordre ascii
- [ ] *avec arguments* : gerer les differentes possibilités de format ```$variable``` ou ```${variable}``` ou ```“$variable”``` ou ```"${variable}"```
- [ ] ```export nom_variable``` Exportation de la variable dans les processus fils.
- [ ] ```export nom_variable=value``` Assignation et exportation de la variable dans les processus fils.

### ```env```
- [ ] print la liste des variables d'environnement.
- [ ] print les variables ajoutêes par ```export```
- [ ] Attention aux variables que la commante ```exort``` affiche mais que ```env``` ne doit pas afficher


## 4. Exécution avec ```execve``` 🌶

## 5. Gestion d'erreur & ```echo $?``` 🦄

⚠️ les codes de retours sont différents sur mac et linux

|Numéro de code de sortie|Sens|Exemple|Commentaire|
| :--- | :--- | :--- | :--- |
|```1```|Catchall pour les erreurs générales|```let "var1 = 1/0"```|Erreurs diverses, telles que "diviser par zéro" et autres **opérations non autorisées**|
|```2```|Mauvaise utilisation des commandes intégrées du shell (selon la documentation Bash)|```exit 3.14159```|**Mot - clé ou commande manquant** , ou **problème d'autorisation** (et code de retour diff en cas d'échec de la comparaison de fichiers binaires )|
|```126```|La commande invoquée ne peut pas s'exécuter|```/dev/null```|Le **problème d'autorisation** ou la commande n'est pas un exécutable|
|```127```|```command not found```|```fdp```|Problème possible avec **$PATH** ou **une faute de frappe**|
|```128```|Argument invalide pour quitter|```exit 3.14159```|**exit** ne prend que des arguments entiers compris entre 0 et 255 (voir la première note de bas de page)|
|```128+n```|Signal d'erreur fatale "n"|```kill -9 $PPID of script```|``$?`` renvoie 137 (128 + 9)|
|```130```|Script terminé par Control-C|```Ctl-C```|**Control-C** est le signal d'erreur fatale 2 , (130 = 128 + 2, voir ci-dessus)|
|```255*```|État de sortie hors de portée|```exit -1```|**exit** ne prend que des arguments entiers compris entre 0 et 255|

* [man strerror](http://manpagesfr.free.fr/man/man3/strerror.3.html)
* [man errno](http://manpagesfr.free.fr/man/man3/errno.3.html)

## USEFULL LINKS 🤙🏼

* Usefull [Readme](https://github.com/LucieLeBriquer/minishell)
* [@iciamyplant](https://github.com/iciamyplant/Minishell#i---quest-ce-que-minishell--1) Readme
* Liste de [tests](https://github.com/Sethhhhhhh/minishell-tester/blob/master/input) by [@Seth](https://github.com/Sethhhhhhh)
* [man BASH](http://manpagesfr.free.fr/man/man1/bash.1.html)
* [TUTO SHELL](http://marionpatrick.free.fr/man_html/html/tuto_shell.html)
* [Fonctions autorisées par le sujet minishell 👉](https://github.com/tinaserra/minishell/blob/master/links/lexic.md)

## Comment utiliser Git en multi ?

[Readme 😏](https://github.com/tinaserra/minishell/blob/master/links/git.md)</br>
Git: [pense-bête](http://www.letuyau.net/2012/09/git-pense-bete/)