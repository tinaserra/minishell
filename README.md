# minishell
Aussi mignon qu’un vrai shell

## MANS

[man strerror](http://manpagesfr.free.fr/man/man3/strerror.3.html)</br>
[man erno](http://manpagesfr.free.fr/man/man3/errno.3.html)</br>
[man BASH](http://manpagesfr.free.fr/man/man1/bash.1.html)</br>

# Comment utiliser Git en multi ?

Pour lister les branches existantes dans le repository local:
```js
git branch
```
Pour créer une branche en local, il suffit de faire:
```js
git branch [nom-de-la-branche]
```
Pour basculer sur une branche donnée et travailler dessus:
```js
git checkout [nom-de-la-branche]
```
Pour pusher la branche actuelle vers le repository distant:
```js
git push origin [nom-de-la-branche]
```
Pour lister les branches distantes:
```js
git remote show origin
```
Pour un autre développeur qui voudrait utiliser la branche nom-de-la-branche
```js
git fetch origin
git checkout origin/[nom-de-la-branche]
```
La première commande met à jour le repository local avec les changements présents dans le repository ditant. La deuxième crée un branche locale « nom-de-la-branche » câblée sur la branche distante.

Pour appliquer les changements de la branche master distante sur une branche locale spécifique: ```rebase```
```c
// on se positionne sur notre branche master
git checkout master

// on la met à jour par rapport au repository distant
git pull

// on se positionne sur la branche [nom-de-la-branche]
git checkout [nom-de-la-branche]

// on tente d'appliquer les changements fait dans master
git rebase master

// en cas de conflit, les résoudre et faire  "git rebase --continue"
```

Git: [pense-bête](http://www.letuyau.net/2012/09/git-pense-bete/)