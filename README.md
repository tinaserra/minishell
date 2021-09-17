# Minishell
Aussi mignon qu’un vrai shell

## TO DO !!

### Ces cas

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

### Messages d'erreur

```shell
$ dd ou ; echo $?
dd: unknown operand ou
1
```
```shell
$ pwd fr ; echo $?
pwd: too many arguments
1
```
```shell
$ kill ooi ; echo $?
kill: illegal pid: ooi
1
```
```shell
$ ls -l execution.sh | ./execution.sh ; echo $?
zsh: no such file or directory: ./execution.sh
ls: execution.sh: No such file or directory
127
```
```shell
$ exit $? # Vraiment tres fun
bash-3.2$ exit $?
exit
$ echo $?
0
```
```shell
bash-3.2$ exit 3.14 ; echo $?
exit
bash: exit: 3.14: numeric argument required
$ echo $? # Mac
255
$ echo $? # Linux
2
```
```
bash-3.2$ exit -1
exit
$ echo $?
255
```
```shell
$ chmod pute +5 ; echo $?
chmod: Invalid file mode: pute
1
```
```shell
$ chmode pute -*52 ; echo $?
zsh: no matches found: -*52
1
```
```shell
$ stty -f pute ; echo $?
stty: stdin isn't a terminal
1
```
```shell
/dev/null ; echo $?
zsh: permission denied: /dev/null
126
```
```shell
bash-3.2$ exit 4643153
exit
$ echo $?
81
```

### ```echo```

- [x] les redirections (vers un fichier, vers une variable d'env...) ⚠️ a ```cat```
- [ ] Pipe ?? ⚠️ a ```cat```
- [ ] $? -> retourne le code erreur de la derniere commande

[man echo baby !](http://marionpatrick.free.fr/man_html/html/tuto_shell.html#chp3.3.2.3)


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


### Usage 🧐

Start
```
make && ./minishell
```

## INTRODUCTION 🤓

Sujet -> [EN](https://github.com/tinaserra/minishell/blob/master/links/minishell_en.pdf) | [FR](https://github.com/tinaserra/minishell/blob/master/links/minishell_fr.pdf)
Scale de correction -> [EN](https://github.com/tinaserra/minishell/blob/master/links/scale)

## ```echo $?```

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

## USEFULL LINKS 🤙🏼

[usefull](https://github.com/lucielebriquer)
[man strerror](http://manpagesfr.free.fr/man/man3/strerror.3.html)</br>
[man errno](http://manpagesfr.free.fr/man/man3/errno.3.html)</br>
[man BASH](http://manpagesfr.free.fr/man/man1/bash.1.html)</br>
[TUTO SHELL](http://marionpatrick.free.fr/man_html/html/tuto_shell.html)</br>
[Fonctions autorisées par le sujet minishell 👉](https://github.com/tinaserra/minishell/blob/master/links/lexic.md)</br>

## Comment utiliser Git en multi ?

[Readme 😏](https://github.com/tinaserra/minishell/blob/master/links/git.md)
Git: [pense-bête](http://www.letuyau.net/2012/09/git-pense-bete/)