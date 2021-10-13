- [x] echo bonjour ; |
- [x] echo bonjour | |
- [x] |
- [x] echo bonjour |;
- [x] echo bonjour \; ls
- [x] echo bonjour > test\ 1
- [x] cd $HOME/Documents
- [x] echo \>
- [x] echo -n -n -nnnn -nnnnm
- [ ] cat /dev/random | head -n 1 | cat -e
- [ ] unset var1 # with undefined var1
- [ ] export "" et unset ""
- [ ] echo test > file test1
- [x] $
- [x] not_cmd bonjour > salut
- [x] env puis export puis env # vars aren't sorted
- [ ] cat Makefile | grep pr | head -n 5 | cd test (mybin) # check status code
- [ ] cat Makefile | grep pr | head -n 5 | hello (NA) # check status code


- [x] echo 2 >> out1 > out2
- [x] echo 2 > out1 >> out2
- [ ] cat < test # with non-existent test
- [ ] export var; export var=test
- [ ] echo bonjour > $test # with test not defined
- [ ] file_name_in_current_dir
- [ ] cd ../../../../../.. ; pwd
- [ ] ctrl-C . 130 sur bin(ex : sleep 10)&line vide
- [ ] ctrl-\ .131 sur bin
- [ ] cat | cat | cat | ls # check outputs order
- [ ] $bla # with bla not defined
- [ ] export var ="cat Makefile | grep >"
- [ ] export "test=ici"=coucou
- [ ] c$var Makefile # with var=at
- [ ] $LESS$VAR
- [ ] /bin/echo bonjour
- [ ] not_cmd
- [ ] sleep 5 | exit
- [ ] echo bonjour > $test w/ t
- [ ] "exit retour a la ligne"
- [ ] minishell # binary not in path without "./" before
- [ ] cat diufosgid # check exit code
- [ ] exit # should return the last exit code value
- [ ] exit -10
- [ ] exit +10
- [ ] ;


- [ ] export ; env # display is different for both commands
- [ ] > log echo coucou


- [ ] echo "\\"
- [ ] echo "\n \n \n"
- [ ] echo "\n \\n \\\n"

- [ ] export LOL=lala ROR=rara
- [ ] unset LOL ROR
- [x] export "HI= hi"
- [x] export "HI =hi"
- [x] /bin/ls
- [x] # write something the press ctrl+c
- [x] # write something then press ctrl+d
- [ ] # write something then press ctrl+\
- [x] echo $?
- [ ] l^Ds

- [ ] sort | ls # check output order
- [x] cat < >
- [x] cat < <
- [x] cat > >
- [ ] > a ls > b < Makefile
- [ ] echo > a Hello World!
- [ ] > a echo Hello World!
- [x] cat < Makefile | grep gcc > output
- [ ] exit 0 | exit 1
- [ ] exit 1 | exit 0



# Failed tests

## leaks 🤬

- [x] ```echo $PWD; echo $OLDPWD; cd .; pwd; echo $PWD; echo $OLDPWD```
- [x] ```echo $PWD; echo $OLDPWD; cd ..; pwd; echo $PWD; echo $OLDPWD```
- [x] ```echo $PWD; echo $OLDPWD; cd ../../../..; pwd; echo $PWD; echo $OLDPWD```
- [x] ```echo $PWD; echo $OLDPWD; cd ../../../../..; pwd; echo $PWD; echo $OLDPWD```
- [x] ```echo $PWD; echo $OLDPWD; cd /; pwd; echo $PWD; echo $OLDPWD```
- [x] ```echo $PWD; echo $OLDPWD; cd ''; pwd; echo $PWD; echo $OLDPWD```
- [ ] ```export "" ; unset ""```

## On gere pas 😳

- [x] ```cd ''```
- [x] ```echo $PWD; echo $OLDPWD; cd ''; pwd; echo $PWD; echo $OLDPWD```
- [x] ```cd '' ''```
- [x] ```echo $PWD; echo $OLDPWD; cd '' ''; pwd; echo $PWD; echo $OLDPWD```
- [ ] ```echo "\s" & echo "\\s"```

- [ ] echo "\"
- [ ] echo "bip | bip ; coyotte > < \" "
- [ ] cd ~
- [ ] cat Makefile | grep pr | head -n 5 | cat test (bin) # check status code

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
- [x] ```ls -la | rev | cat -e```
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