# Doc & Lexique des fonctions autorisées

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