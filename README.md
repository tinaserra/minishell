# Minishell
Aussi mignon qu’un vrai shell

## TO DO !!

### ```echo```

- [ ] plusieurs arguments (strings)
- [ ] gerer les guillemets & backslash
- [ ] les variables d'environnement
- [ ] les redirections (vers un fichier, vers une variable d'env...) ⚠️ a ```cat```
- [ ] Pipe ?? ⚠️ a ```cat```
- [ ] $? -> retourne le code erreur de la derniere commande

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

## ```unset```
## ```env```

- [ ] print la liste des variables d'environnement.
- [ ] print les variables ajoutêes par ```export```
- [ ] Attention aux variables que la commante ```exort``` affiche mais que ```env``` ne doit pas afficher
## ```exit```


### Usage 🧐

Start
```
make && ./minishell
```

Start john's
```
make john && ./minijohn
```

Start tina's
```
make tina && ./minitina
```

## MANS

[man strerror](http://manpagesfr.free.fr/man/man3/strerror.3.html)</br>
[man erno](http://manpagesfr.free.fr/man/man3/errno.3.html)</br>
[man BASH](http://manpagesfr.free.fr/man/man1/bash.1.html)</br>
[TUTO SHELL](http://marionpatrick.free.fr/man_html/html/tuto_shell.html)

## INTRODUCTION 🤓

Sujet -> [EN](https://github.com/tinaserra/minishell/blob/master/links/minishell_en.pdf) | [FR](https://github.com/tinaserra/minishell/blob/master/links/minishell_fr.pdf)
Scale de correction -> [EN](https://github.com/tinaserra/minishell/blob/master/links/scale)

## Comment utiliser Git en multi ?

[Readme 😏](https://github.com/tinaserra/minishell/blob/master/links/git.md)
Git: [pense-bête](http://www.letuyau.net/2012/09/git-pense-bete/)