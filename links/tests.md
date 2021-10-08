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
- [ ] ```cd /```
- [ ] ```echo $PWD; echo $OLDPWD; cd /; pwd; echo $PWD; echo $OLDPWD```
- [ ] ```cd /.```
- [ ] ```echo $PWD; echo $OLDPWD; cd /.; pwd; echo $PWD; echo $OLDPWD```
- [ ] ```cd/./```
- [ ] ```echo $PWD; echo $OLDPWD; cd /./; pwd; echo $PWD; echo $OLDPWD```
- [ ] ```cd /././././```
- [ ] ```echo $PWD; echo $OLDPWD; cd /././././; pwd; echo $PWD; echo $OLDPWD```
- [ ] ```cd ///```
- [ ] ```echo $PWD; echo $OLDPWD; cd ///; pwd; echo $PWD; echo $OLDPWD```
- [ ] ```cd ////```
- [ ] ```echo $PWD; echo $OLDPWD; cd ////; pwd; echo $PWD; echo $OLDPWD```

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

## Segmentation fault 😭

### ***bash output :***
```
/home/admin/42/minishell1
/home/admin/42
/home/admin/42/minishell1
```
- [ ] ```cd```
- [ ] ```echo $PWD; echo $OLDPWD; cd; echo $OLDPWD```