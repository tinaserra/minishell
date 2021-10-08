# Failed tests

## leaks 🤬

- [x] ```echo $PWD; echo $OLDPWD; cd .; pwd; echo $PWD; echo $OLDPWD```
- [x] ```echo $PWD; echo $OLDPWD; cd ..; pwd; echo $PWD; echo $OLDPWD```
- [x] ```echo $PWD; echo $OLDPWD; cd ../../../..; pwd; echo $PWD; echo $OLDPWD```
- [x] ```echo $PWD; echo $OLDPWD; cd ../../../../..; pwd; echo $PWD; echo $OLDPWD```
- [x] ```echo $PWD; echo $OLDPWD; cd /; pwd; echo $PWD; echo $OLDPWD```
- [x] ```echo $PWD; echo $OLDPWD; cd ''; pwd; echo $PWD; echo $OLDPWD```

## On gere pas 😳

- [x] ```cd ''```
- [x] ```echo $PWD; echo $OLDPWD; cd ''; pwd; echo $PWD; echo $OLDPWD```
- [x] ```cd '' ''```
- [x] ```echo $PWD; echo $OLDPWD; cd '' ''; pwd; echo $PWD; echo $OLDPWD```

### ***bash output :***
```
/home/admin/42/minishell1
/home/admin/42/minishell1
/
/
/home/admin/42/minishell1
```
- [x] ```cd /```
- [x] ```echo $PWD; echo $OLDPWD; cd /; pwd; echo $PWD; echo $OLDPWD```
- [x] ```cd /.```
- [x] ```echo $PWD; echo $OLDPWD; cd /.; pwd; echo $PWD; echo $OLDPWD```
- [x] ```cd/./```
- [x] ```echo $PWD; echo $OLDPWD; cd /./; pwd; echo $PWD; echo $OLDPWD```
- [x] ```cd /././././```
- [x] ```echo $PWD; echo $OLDPWD; cd /././././; pwd; echo $PWD; echo $OLDPWD```
- [x] ```cd ///```
- [x] ```echo $PWD; echo $OLDPWD; cd ///; pwd; echo $PWD; echo $OLDPWD```
- [x] ```cd ////```
- [x] ```echo $PWD; echo $OLDPWD; cd ////; pwd; echo $PWD; echo $OLDPWD```

### ***bash output :***
```
/home/admin/42/minishell1
/home/admin/42/minishell1
//
//
/home/admin/42/minishell1
```
- [ ] ```cd //```
- [ ] ```echo $PWD; echo $OLDPWD; cd //; pwd; echo $PWD; echo $OLDPWD```

### Autre

- [x] ```echo $PWD; echo $OLDPWD; cd ' // '; pwd; echo $PWD; echo $OLDPWD```
- [x] ```echo $PWD; echo $OLDPWD; cd //home; pwd; echo $PWD; echo $OLDPWD```

## Segmentation fault 😭

### ***bash output :***
```
/home/admin/42/minishell1
/home/admin/42
/home/admin/42/minishell1
```
- [x] ```cd```
- [x] ```echo $PWD; echo $OLDPWD; cd; echo $OLDPWD```

## Message d'erreur 🧐

- [x] ```cd ' / '```
- [x] ```echo $PWD; echo $OLDPWD; cd ' / '; pwd; echo $PWD; echo $OLDPWD ```

### Ces cas

```shell
admin ➜ minishell1 ls | wc |  cat -e ; ls | ckjefvkj
minishell: ckjefvkj: command not found

minishell: ckjefvkj: command not found
```

```shell
admin ➜ minishell1 ls | wc > b
wc: '>': No such file or directory
0 0 0 b
0 0 0 total
```

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
$ env fnrf ; echo $?
env: ‘fnrf’: No such file or directory
127
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