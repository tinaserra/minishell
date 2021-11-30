# Minishell 🌈
Aussi mignon qu’un vrai shell

### Usage
Start
```
make && ./minishell
```

### Sommaire 🧐

1. [Sujet](https://github.com/tinaserra/minishell#introduction-)
2. [Parsing](https://github.com/tinaserra/minishell#2-parsing-)
3. [Buildtins](https://github.com/tinaserra/minishell#3-buildtins-)
4. [Exécution](https://github.com/tinaserra/minishell#4-ex%C3%A9cution-avec-execve-)
5. [Gestion d'erreur](https://github.com/tinaserra/minishell#5-gestion-derreur--echo--)

### TO DO !!
Liste non exaustive des [Failed tests](https://github.com/tinaserra/minishell/blob/master/links/tests.md)

### Introduction 🤓
Sujet -> [EN](https://github.com/tinaserra/minishell/blob/master/links/sujet_minishell.pdf)</br>
Scale de correction -> [EN](https://github.com/tinaserra/minishell/blob/master/links/scale_minishell.pdf)

## 1. Sujet
L'objectif du projet est de creer notre propre shell.

#### Qu'est-ce qu'un shell ?
Le shell c'est en quelque sorte l'interface utilisaeur d'un systeme. Il permet à l'utilisateur de communiquer avec le système d’exploitation par l'intermédiaire de commandes. L'utilisateur rentre des commandes dans le terminal et grâce à l’interpréteur de commande (tel que bash ou zsh qui sont des shells), les commandes entrées sont exécutées.

#### Attention ⚠️
* Le sujet de minishell a eu plusieurs mises a jour. Ici nous ne faisons pas les termcaps (utilisation de ```readline```, ```rl_clear_history```, ...).
* Nous avons du adapter le code pour utiliser qu'une seule variable globale.
* Nous interprétons les caractères spéciaux ```\``` et ```;```, mais dans la maj du sujet on n'est pas obligés de les gérer.

## 2. Parsing 🤯

On va créer une liste chaînée à partir de l'environnement contenant à chaque maillon le nom de la **commande** et ses **arguments**.

```c++
typedef struct		s_token
{
	char		*word;
	int		type;
	struct s_token	*prev;
	struct s_token	*next;
}			t_token;

typedef struct		s_cmd
{
	char		*cmd;
	char		*tmp;
	t_token		*args;
	t_list		*env;
	int		type;
	int		in;
	int		out;
	struct s_cmd	*prev;
	struct s_cmd	*next;
}			t_cmd;
```

### La tokénisation

Le but va etre de trier notre input par *type*. On **split** selon les quotes et les opérateurs rencontrés. On construit un tableau de structure avec comme attribut le **caractère séparateur** ainsi que la **chaîne** contenue entre les deux délimiteurs.</br>
Chaque type a une valeur (0: point virgule, 1: pipe, 2: redirection, 3: variable d'environnement, 4: newline, 5: texte, 6: exit status).

#### Exemple

```
$ Ceci est un beau $parsing ; Avec des >> commandes | et des arguments
```
```
[5] [Ceci est un beau]
[3] [$parsing]
[0] [; Avec des]
[2] [>> commandes]
[1] [| et des arguments]
```

Pour mieux s'y retrouver dans les types, on fait un **enum**. cela permet en quelque sorte de donner un nom a des int. Par defaut la premiere valeur (ici ```POINT_V```) vaut 0 et les suivantes +1. Il est donc simple de rajouter un type.

```c++
typedef enum		e_type{
	POINT_V,	// = 0
	PIPE,		// = 1
	REDIR,		// = 2
	ENV,		// = 3
	NEWL,		// = 4
	TXT,		// = 5
	EXIT_STATUS	// = 6
}					t_type;
```

En savoir plus sur la tokenisation et l'AST -> [@LucieLeBriquer](https://github.com/LucieLeBriquer/minishell#parsing-de-la-commande)

<!-- ### Étape 1 : séparer

On sépare notre input sur les caractères ```;```, ```|```, ```>```, ```<```, ```>>```, ```<<``` et on commence a renger les chaines dans des types. -->

## 3. Buildtins 👾

*is commming...*

### export, env et unset

* ```env``` permet d'afficher toutes les variables d'environnement.

* ```export``` permet de set des variables d'environnement (deja existante ou non).

* ```unset``` permet de supprimer des variables.
Unset peut supprimer plusieurs variables d'environement simultannement si on lui envoi plusieurs arguments. Si on unset une variable qui n'est pas présente dans les variables on n'a pas de message d'erreur et echo $? renvoi 0

#### Quelques cas

|Exemple|```export```|```env```|Commentaire|
| :--- | :--- | :--- | :--- |
|Sans argument|print la liste de toutes les variables d’environnement dans l’ordre ascii.</br>Sous la forme : ```declare -x NAME="VALUE"``` ou ```declare -x NAME```|print la liste des variables d’environnement dans un ordre random.</br>Sous la forme : ```NAME=VALUE```| |
|Sans ```=```</br>```export maman```|declare -x maman|la variable n'apparait pas| |
|Avec un ```=``` et rien apres</br>```export maman=```|declare -x maman=""| maman= | |
|```export HOME=```|declare -x HOME=""| HOME= |si on fait ```cd``` apres, on ne doit pas avoir le message "HOME not set", il ne se passe rien</br>```echo $?``` renvoi 0|
|cas classique </br>```export lol=mdr```|declare -x lol="mdr"|lol=mdr| |
|Le export +=</br>```export a=b``` ; ```export a+=b``` ; ```export a+=b```|declare -x a="bbb"|a=bbb|On ajoute le nouveau contenu au contenu existant de la variable|
|plusieurs arguments</br>```export var= omg```|declare -x omg declare -x var=""| var=| |



#### Les cas tricky

```sh
➜ export y=ec
➜ $yho a
```

en fait si tu tape dans bash simplement
```$something``` mais la variable ```something``` n'est pas set, il ne se passe rien

donc si je tape``` $something a```
on doit rien faire pour le premier argument et ```a``` est interprete comme si on avait une commande (ici c'est commande not found)

```sh
➜ export var=a
➜ unset var
➜ export $var=test
```

il faut un message d'erreur : 
bash: export: `=test': not a valid identifier

## 4. Exécution avec ```execve``` 🌶

### Les processus

Creér un fork.

```c++
int pid;

pid = fork();
if (pid < 0)
	/* Error forking */
if (pid == 0)
	/* Child process */
else
	/* Parent process */
```



### La fonction execve

L'utilisateur peut rentrer le **nom** de la commande (ex : ```ls```) ou le **path** (ex: ```/bin/ls```).
si c'est juste le nom aui est entré il faut récupérer le path de la commande avec la fonction ```lstat```.
la fonction ```execve``` prend en paramètre le **path ou le nom** du commande a executer, un **tableau d'arguments**, et l'environement (ici on met ```NULL```).

* [Utilisation de exec](https://aljensencprogramming.wordpress.com/2014/03/31/using-the-exec-function-in-unix-like-enviroments/)
* [Utilisation de wait](https://aljensencprogramming.wordpress.com/2014/04/29/waiting-for-and-exiting-from-processes-in-linux-c/)
* [Implémentation de pipe](https://aljensencprogramming.wordpress.com/2014/05/16/implementing-pipes-in-c/)
* [Utilisation de dup2](https://aljensencprogramming.wordpress.com/2014/09/03/review-of-pipes-in-linux-c-with-dup2/)

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

* [@iciamyplant](https://github.com/iciamyplant/Minishell#i---quest-ce-que-minishell--1) Readme
* Liste de [tests](https://github.com/Sethhhhhhh/minishell-tester/blob/master/input) by [@Seth](https://github.com/Sethhhhhhh)
* [man BASH](http://manpagesfr.free.fr/man/man1/bash.1.html)
* [TUTO SHELL](http://marionpatrick.free.fr/man_html/html/tuto_shell.html)
* [Fonctions autorisées par le sujet minishell 👉](https://github.com/tinaserra/minishell/blob/master/links/lexic.md)
* [La fonction kill](https://aljensencprogramming.wordpress.com/2014/05/15/the-kill-function-in-c/)
* [Les signaux 1](https://aljensencprogramming.wordpress.com/2014/05/09/introduction-to-signals-using-alarm-in-linux-c/)
* [Les signaux 2](https://aljensencprogramming.wordpress.com/2014/12/30/review-of-signals-in-linux-c/)

* https://aljensencprogramming.wordpress.com/2016/07/29/linked-lists-in-c/
* https://aljensencprogramming.wordpress.com/2016/07/
* https://aljensencprogramming.wordpress.com/2015/10/
* [Les arbres binaires](https://aljensencprogramming.wordpress.com/2015/09/26/a-very-basic-introduction-to-binary-trees-in-c/)

## Comment utiliser Git en multi ?

[Readme 😏](https://github.com/tinaserra/minishell/blob/master/links/git.md)</br>
Git: [pense-bête](http://www.letuyau.net/2012/09/git-pense-bete/)