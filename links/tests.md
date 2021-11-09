## A TESTER

- [ ] cat diufosgid # check exit code

<!-- plus double message d'erreur "Cd: command not found" -->
- [x] export PATH='/bin:/usr/bin'; Cd .
- [x] export PATH='/bin:/usr/bin'; cD .

- [x] export PATH='/bin:/usr/bin'; Echo bonjour                               
export PATH='/bin:/usr/bin'; eCho bonjour                               
export PATH='/bin:/usr/bin'; ecHo bonjour                               
export PATH='/bin:/usr/bin'; echO bonjour                               
export PATH='/bin:/usr/bin'; EchO bonjour                               
export PATH='/bin:/usr/bin'; eCHo bonjour                               
export PATH='/bin:/usr/bin'; EcHo bonjour                               
export PATH='/bin:/usr/bin'; eChO bonjour                               
export PATH='/bin:/usr/bin'; eChO -e 'bonjo\nur'                        
env                                                                       
- [x] export A=a; env                                                    
- [x] export A=a B=b C=c; env                                            
- [x] export A=a B=b C=c; env | cat -e                                   
- [x] Env                                                                       
- [x] enV                                                                       
- [x] export PATH='/bin:/usr/bin'; Env                                        
export PATH='/bin:/usr/bin'; enV                                        
- [x] export PATH='/bin:/usr/bin'; Exit; echo a                               
- [x] export PATH='/bin:/usr/bin'; exiT; echo a                               
export                                                                    
- [x] export A=''; export                                                     
export A='"'; export                                                    
export A='$'; export                                                    
export A='\t'; export                                                   
export A='''; export                                                    
export A='a'; export                                                    
export A=a; echo $A                                                       
- [x] export A=a B=b C=c; echo $A$B$C                                           
export BONJOURJESUIS=a; echo $BONJOURJESUIS                               
export bonjourjesuis=a; echo $bonjourjesuis                               
export bonjour_je_suis=a; echo $bonjour_je_suis                           
export BONJOURJESUIS1=a; echo $BONJOURJESUIS1                             
- [x] export bO_nJq123o__1ju_je3234sui__a=a; echo $bO_nJq123o__1ju_je3234sui__a 
- [x] export a0123456789=a; echo $a0123456789                                   
export abcdefghijklmnopqrstuvwxyz=a; echo $abcdefghijklmnopqrstuvwxyz     
export ABCDEFGHIJKLMNOPQRSTUVWXYZ=a; echo $ABCDEFGHIJKLMNOPQRSTUVWXYZ     
- [x] export __________________________=a; echo $__________________________     
- [x] export _bonjour_=a; echo $_bonjour_                                       
- [x] export _=a; echo $_a                                                      
export 1=a                                                                
export BONJOURJESUIS =a                                                   
export BONJOURJESUIS= a                                                   
export BONJOUR\\JESUIS=a                                                  
export BONJOUR\'JESUIS=a                                                  
export BONJOUR\"JESUIS=a                                                  
export BONJOUR\$JESUIS=a                                                  
export BONJOUR\&JESUIS=a                                                  
export BONJOUR\|JESUIS=a                                                  
export BONJOUR\;JESUIS=a                                                  
export BONJOUR\_JESUIS=a                                                  
export BONJOUR\0JESUIS=a                                                  
                       
- [x] export A='bonjour je suis charles'; echo $A                               
- [x] export A="bonjour je suis charles"; echo $A                               
- [x] export A==a; echo $A                                                      
export A===a; echo $A                                                     
export A====a; echo $A                                                    
export A=====a; echo $A                                                   
export A======a; echo $A                                                  
export A=a=a=a=a=a; echo $A                                               
export A 'asdf ' B ' asdf asdf asd f' ' asdf ' '' 'asdf ' C; echo $A$B$C  
export 'asdf ' B ' asdf asdf asd f' ' asdf ' '' 'asdf ' C; echo $A$B$C    
export A 'asdf ' B ' asdf asdf asd f' ' asdf ' '' 'asdf '; echo $A$B$C    
export A B C; echo $A$B$C                                                 
export A B C; env                                                         
export 'AH@'=nop                                                          
export "AH'"=nop                                                          
export 'AH"'=nop                                                          
export 'AH$'=nop                                                          
export 'AH!'=nop                                                          
export 'AH|'=nop                                                          
export 'AH;'=nop                                                          
export 'AH&'=nop                                                          
export 'AH\'=nop                                                          
export TEST='A=a'; export $TEST                                         
export BONJOUR\\JESUIS                                                    
export BONJOUR\'JESUIS                                                    
export BONJOUR\"JESUIS                                                    
export BONJOUR\$JESUIS                                                    
export BONJOUR\&JESUIS                                                    
export BONJOUR\|JESUIS                                                    
export BONJOUR\;JESUIS                                                    
export BONJOUR\_JESUIS                                                    
export BONJOUR\0JESUIS                                                    
Export B=bonjour                                                          
exporT B=bonjour                                                          
export PATH='/bin:/usr/bin'; Export B=bonjour                           
export PATH='/bin:/usr/bin'; exporT B=bonjour                           
pwd | cat -e                                                              
export PWD='/etc'; pwd                                                  
unset PWD; pwd; echo $PWD                                                 
export PWD=foo; pwd; echo $PWD                                            
Pwd                                                                       
pwD                                                                       
export PATH='/bin:/usr/bin'; Pwd                                        
export PATH='/bin:/usr/bin'; pwD                                        
unset                                                                     
export A='a'; unset A; echo $A                                          
export A='a'; unset 'A '; echo $A                                       
export A='a'; unset 'A='; echo $A                                       
export A='a' B='b' C='c'; unset A B C; echo $A$B$C                      
export A='a' B='b' C='c'; unset A; echo $A$B$C                          
export A='a' B='b' C='c'; unset C; echo $A$B$C                          
export A='a' B='b' C='c'; unset A B C                                   
export A='a' B='b' C='c'; unset A                                       
unset 'AH@'=nop                                                           
unset "AH'"=nop                                                           
unset 'AH"'=nop                                                           
unset 'AH$'=nop                                                           
unset 'AH!'=nop                                                           
unset 'AH|'=nop                                                           
unset 'AH;'=nop                                                           
unset 'AH&'=nop                                                           
unset 'AH\'=nop                                                           
Unset TERM                                                                
unseT TERM                                                                
export PATH='/bin:/usr/bin'; Unset TERM                                 
export PATH='/bin:/usr/bin'; unseT TERM                                 
export SHLVL=''; echo $SHLVL                                            
export SHLVL=' 1'; echo $SHLVL                                          
export SHLVL=' 2'; echo $SHLVL                                          
export SHLVL=' 3'; echo $SHLVL                                          
export SHLVL=' ' 3''; echo $SHLVL                                       
export SHLVL=' '\t3''; echo $SHLVL                                      
export SHLVL=' '\t\f\r 3''; echo $SHLVL                                 
export SHLVL=' '3 ''; echo $SHLVL                                       
export SHLVL=' '3\t''; echo $SHLVL                                      
export SHLVL=' '3\r''; echo $SHLVL                                      
export SHLVL=' '3\t\f\r ''; echo $SHLVL                                 
export SHLVL=' '3     a''; echo $SHLVL                                  
export SHLVL=' '3\t\t\ta''; echo $SHLVL                                 
export SHLVL=' 0'; echo $SHLVL                                          
export SHLVL=' -0'; echo $SHLVL                                         
export SHLVL=' -1'; echo $SHLVL                                         
export SHLVL=' 255'; echo $SHLVL                                        
export SHLVL=' 256'; echo $SHLVL                                        
export SHLVL=' 2000000'; echo $SHLVL                                    
export SHLVL=' -2000000'; echo $SHLVL                                   
export SHLVL=' 2147483647'; echo $SHLVL                                 
export SHLVL=' -2147483648'; echo $SHLVL                                
export SHLVL=' 2147483648'; echo $SHLVL                                 
export SHLVL=' -2147483649'; echo $SHLVL                                
export SHLVL=' 3147483648'; echo $SHLVL                                 
export SHLVL=' -3147483649'; echo $SHLVL                                
export SHLVL=' 4294967295'; echo $SHLVL                                 
export SHLVL=' 4294967296'; echo $SHLVL                                 
export SHLVL=' -9223372036854775808'; echo $SHLVL                       
export SHLVL=' 9223372036854775807'; echo $SHLVL                        
export SHLVL=' -9223372036854775809'; echo $SHLVL                       
export SHLVL=' 9223372036854775808'; echo $SHLVL                        
export SHLVL=' 18446744073709551615'; echo $SHLVL                       
export SHLVL=' 18446744073709551616'; echo $SHLVL                       
export SHLVL=' +1'; echo $SHLVL                                         
export SHLVL=' +2'; echo $SHLVL                                         
export SHLVL=' +3'; echo $SHLVL                                         
export SHLVL=' +0'; echo $SHLVL                                         
export SHLVL=' +255'; echo $SHLVL                                       
export SHLVL=' +256'; echo $SHLVL                                       
export SHLVL=' +2000000'; echo $SHLVL                                   
export SHLVL=' +2147483647'; echo $SHLVL                                
export SHLVL=' ++1'; echo $SHLVL                                        
export SHLVL=' ++2'; echo $SHLVL                                        
export SHLVL=' ++3'; echo $SHLVL                                        
export SHLVL=' ++0'; echo $SHLVL                                        
export SHLVL=' ++255'; echo $SHLVL                                      
export SHLVL=' ++256'; echo $SHLVL                                      
export SHLVL=' ++2000000'; echo $SHLVL                                  
export SHLVL=' ++2147483647'; echo $SHLVL                               
export SHLVL=' --1'; echo $SHLVL                                        
export SHLVL=' --2'; echo $SHLVL                                        
export SHLVL=' --3'; echo $SHLVL                                        
export SHLVL=' --0'; echo $SHLVL                                        
export SHLVL=' --255'; echo $SHLVL                                      
export SHLVL=' --256'; echo $SHLVL                                      
export SHLVL=' --2000000'; echo $SHLVL                                  
export SHLVL=' --2147483647'; echo $SHLVL                               
export SHLVL=' bonjour'; echo $SHLVL                                    
export SHLVL=' 0_'; echo $SHLVL                                         
export SHLVL=' _0'; echo $SHLVL                                         
export SHLVL=' 0123456789'; echo $SHLVL                                 
export SHLVL=' -0123456789'; echo $SHLVL                                

mkdir path && mkfifo path/a; a                                     
mkdir path && mkfifo path/a && chmod 777 path/a; a                 

export PATH='doesnotexits'; echo $PATH                                  
export PATH='doesnotexits:asdfasdfas'; echo $PATH                       
export PATH='________'; echo $PATH                                      
export PATH='        '; echo $PATH                                      
export PATH='   :    '; echo $PATH                                      
export PATH='     /bin      '; echo $PATH                               
export PATH='     /sbin      '; echo $PATH                              
export PATH='/bin:/bin:/bin:/bin'; echo $PATH                           
export PATH='/sbin:/sbin:/sbin:/sbin'; echo $PATH                       
export PATH=''; echo $PATH                                              
export PATH=':'; echo $PATH                                             
export PATH=':::::::::::::::::::'; echo $PATH                           
export PATH='/asdfasdf'; echo $PATH                                     
export PATH='/usr/asdf:/usr/lib/asdfasdf'; echo $PATH                   
export PATH='doesnotexits'; whoami                                      
export PATH='doesnotexits:asdfasdfas'; whoami                           
export PATH='________'; whoami                                          
export PATH='        '; whoami                                          
export PATH='   :    '; whoami                                          
export PATH='     /usr/bin      '; whoami                               
export PATH='/usr/bin:/usr/bin:/usr/bin:/usr/bin'; whoami               
export PATH='     /sbin      '; whoami                                  
export PATH='/sbin:/sbin:/sbin:/sbin'; whoami                           
export PATH=''; whoami                                                  
unset PATH; whoami                                                        
export PATH=':'; whoami                                                 
export PATH=':::::::::::::::::::'; whoami                               
export PATH='/asdfasdf'; whoami                                         
export PATH='/usr/asdf:/usr/lib/asdfasdf'; whoami                       
unset PATH; whoami                                                 
export PATH='/usr/bin'; Whoami                                          
export PATH='/usr/bin'; wHoAMi                                          
export PATH='/usr/bIn'; whoami                                          
export PATH='/Usr/bin'; whoami                                          
export PATH='/usr/bIn'; Whoami                                          
export PATH='/Usr/bin'; wHoami                                          
export PATH=''; Whoami                                                  
export PATH=''; wHoami                                                  
echo a | export A=a; echo $A                                              
export A=a | cat; echo $A                                                 
export TEST='bonjour'; echo $TEST                                       
export TEST='bonjour'; echo $TES                                        
export TEST='bonjour'; echo $TEST_                                      
export TEST='bonjour'; echo "|$TEST|"                                   
export TEST='bonjour'; echo "|$TES|"                                    
export TEST='bonjour'; echo "|$TEST_|"                                  
export TEST='bonjour'; echo '|$TEST|'                                   
export TEST='bonjour'; echo '|$TES|'                                    
export TEST='bonjour'; echo '|$TEST_|'                                  
export A='foo' B='bar' C='baz'; echo $A$B$C                             
export A='foo' B='bar' C='baz'; echo "$A$B$C"                           
export A='foo' B='bar' C='baz'; echo '$A$B$C'                           
export A='foo' B='bar' C='baz'; echo $A,$B,$C                           
export A='foo' B='bar' C='baz'; echo "$A,$B,$C"                         
export A='foo' B='bar' C='baz'; echo '$A,$B,$C'                         
export A='foo' B='bar' C='baz'; echo $A"$B"$C"A"$B"$C"                  
export A='foo' B='bar' C='baz'; echo $A'$B'$C'A'$B'$C'                  
export A='foo ' B=' bar  ' C='baz '; echo $A"$B"$C"A"$B"$C"             
export A='foo ' B=' bar  ' C='baz '; echo $A'$B'$C'A'$B'$C'             
echo $A                                                                   
echo $A$B                                                                 
echo $A$B$C                                                               
echo $A$B$C$D                                                             
export A='bonjour\je'; echo [$A]                                        
export A='\b\\o\\\nj\\\\\\\our\\je\\\\'; echo [$A]                      
export A='   \b\\o\\\nj\\\\\\\our\\je\\\\'; echo [$A]                   
export A='\b\\o\\\nj\\\\\\\our\\je\\\\   '; echo [$A]                   
export A='  \b\\o\\\nj\\\\\\\our\\je\\\\ '; echo [$A]                   
export A='a  \b\\o\\\nj\\\\\\\our\\je\\\\ b'; echo [$A]                 
export A=' a  \b\\o\\\nj\\\\\\\our\\je\\\\ b '; echo [$A]               
export A=' '; echo [$A]                                                 
export A='    '; echo [$A]                                              
export A='\ '; echo [$A]                                                
export A=' \  '; echo [$A]                                              
export A='bonjour'; echo \ \ \ \ \ \ \ $A\ \ \ \ \ \                    
export A='bonjour je suis'; echo \ \ \ \ \ \ \ $A\ \ \ \ \ \            
export A='  bonjour je suis  '; echo \ \ \ \ \ \ \ $A\ \ \ \ \ \        
export A='bonjour je suis splited'; echo $A                             
export A='bonjour     je     suis    splited'; echo $A                  
export A='   bonjour     je     suis    splited   '; echo $A            
export A='bonjour je suis splited'; echo [$A]                           
export A='bonjour     je     suis    splited'; echo [$A]                
export A='   bonjour     je     suis    splited   '; echo [$A]          
export A='bonjour je suis splited'; echo "[$A]"                         
export A='bonjour     je     suis    splited'; echo "[$A]"              
export A='   bonjour     je     suis    splited   '; echo "[$A]"        
export A='bonjour je suis splited'; echo \ $A                           
export A='bonjour     je     suis    splited'; echo \ $A                
export A='   bonjour     je     suis    splited   '; echo \ $A          
export A='bonjour je suis splited'; echo $A\                            
export A='bonjour     je     suis    splited'; echo $A\                 
export A='   bonjour     je     suis    splited   '; echo $A\           
export A='   bonjour     je     suis    splited   '; echo $A$A$A        
export ECHO='echo'; $ECHO $ECHO                                         
export A='ec' B='ho'; $A$B bonjour                                      
touch a b c; [EXPORTS LS='ls -l'] $LS                              
echo $                                                                    
echo \$                                                                   
echo \$\$\$\$                                                             
echo \$$\$$                                                               
export A='a' B='b'; echo $\A $\B                                        
export A='a' B='b'; echo $\A$\B                                         
export A=' '; echo $A                                                   
export A='  '; echo $A                                                  
export A='   '; echo $A                                                 
export A='    '; echo $A                                                
export A='  a '; echo $A                                                
export A='                                '; echo $A                    
export A='                     a          '; echo $A                    
export A=' '; echo @$A@                                                 
export A=' '; echo @ $A@                                                
export A=' '; echo @$A @                                                
export A='       '; echo @$A@                                           
export A=' '; echo '@'$A'@'                                             
export A=' '; echo '@' $A'@'                                            
export A=' '; echo '@'$A '@'                                            
export A=' '; echo "@"$A"@"                                             
export A=' '; echo "@" $A"@"                                            
export A=' '; echo "@"$A "@"                                            
export A=' '; echo @"$A"@                                               
export A=' '; echo @ "$A"@                                              
export A=' '; echo @"$A" @                                              
export A='       '; echo @"$A"@                                         
export A=' '; echo '@'"$A"'@'                                           
export A=' '; echo '@' "$A"'@'                                          
export A=' '; echo '@'"$A" '@'                                          
export A=' '; echo "@""$A""@"                                           
export A=' '; echo "@" "$A""@"                                          
export A=' '; echo "@""$A" "@"                                          
export A='' B='' C=''; echo $A$B$C                                      
export A='file'; echo bonjour > $A                                      
export A='fi le'; echo bonjour > $A                                     
export A='fi le'; echo bonjour > "$A"                                   
export A='fi le'; echo bonjour > '$A'                                   

## Leaks
- [x] export qui leak quand on met "" en arg

## Tests ok
- [x] echo bonjour ; |
- [x] echo bonjour | |
- [x] |
- [x] echo bonjour |;
- [x] echo bonjour \; ls
- [x] echo bonjour > test\ 1
- [x] cd $HOME
- [x] echo -n -n -nnnn -nnnnm
- [x] $
- [x] not_cmd bonjour > salut
- [x] env puis export puis env # vars aren't sorted
- [x] echo 2 >> out1
- [x] echo 2 > out1 >> out2
- [x] export "HI= hi"
- [x] export "HI =hi"
- [x] /bin/ls
- [x] /bin/ls -lra
- [x] # write something the press ctrl+c
- [x] # write something then press ctrl+d
- [x] cat < >
- [x] cat < <
- [x] cat > >
- [x] cat < Makefile | grep gcc > output
- [x] unset var1 # with undefined var1
- [x] export "" et unset ""
- [x] echo test > file test1
- [x] cat Makefile | grep pr | head -n 5 | hello (NA) # check status code
- [x] export var; export var=test
- [x] cd ../../../../../.. ; pwd
- [x] $bla # with bla not defined
- [x] /bin/echo bonjour
- [x] not_cmd
- [x] exit # should return the last exit code value
- [x] exit -10
- [x] exit +10
- [x] ;
- [x] export ; env # display is different for both commands
- [x] > log echo coucou
- [x] >> log echo coucou
- [x] echo "\\"
- [x] echo "\n \n \n"
- [x] echo "\n \\n \\\n"
- [x] export LOL=lala ROR=rara
- [x] unset LOL ROR
- [x] l^Ds
- [x] > a ls > b < Makefile
- [x] echo > a Hello World!
- [x] > a echo Hello World!
- [x] echo $PWD; echo $OLDPWD; cd .; pwd; echo $PWD; echo $OLDPWD
- [x] echo $PWD; echo $OLDPWD; cd ..; pwd; echo $PWD; echo $OLDPWD
- [x] echo $PWD; echo $OLDPWD; cd ../../../..; pwd; echo $PWD; echo $OLDPWD
- [x] echo $PWD; echo $OLDPWD; cd ../../../../..; pwd; echo $PWD; echo $OLDPWD
- [x] echo $PWD; echo $OLDPWD; cd /; pwd; echo $PWD; echo $OLDPWD
- [x] echo $PWD; echo $OLDPWD; cd ''; pwd; echo $PWD; echo $OLDPWD
- [x] export "" ; unset ""
- [x] cd /
- [x] echo $PWD; echo $OLDPWD; cd /; pwd; echo $PWD; echo $OLDPWD
- [x] cd /.
- [x] echo $PWD; echo $OLDPWD; cd /.; pwd; echo $PWD; echo $OLDPWD
- [x] cd/./
- [x] echo $PWD; echo $OLDPWD; cd /./; pwd; echo $PWD; echo $OLDPWD
- [x] cd /././././
- [x] echo $PWD; echo $OLDPWD; cd /././././; pwd; echo $PWD; echo $OLDPWD
- [x] cd ///
- [x] echo $PWD; echo $OLDPWD; cd ///; pwd; echo $PWD; echo $OLDPWD
- [x] cd ////
- [x] echo $PWD; echo $OLDPWD; cd ////; pwd; echo $PWD; echo $OLDPWD
- [x] cd ''
- [x] echo $PWD; echo $OLDPWD; cd ''; pwd; echo $PWD; echo $OLDPWD
- [x] cd '' ''
- [x] echo $PWD; echo $OLDPWD; cd '' ''; pwd; echo $PWD; echo $OLDPWD
- [x] cat Makefile | grep pr | head -n 5 | cat test
- [x] echo $PWD; echo $OLDPWD; cd ' // '; pwd; echo $PWD; echo $OLDPWD
- [x] echo $PWD; echo $OLDPWD; cd //home; pwd; echo $PWD; echo $OLDPWD
- [x] cd
- [x] echo $PWD; echo $OLDPWD; cd; echo $OLDPWD


- [x] exit 0 | exit 1
- [x] exit 1 | exit 0



# Failed tests

- [x] cat < test # with non-existent test
- [x] echo bonjour > $test # with test not defined
- [x] file_name_in_current_dir
- [x] sort | ls # check output order
- [x] # write something then press ctrl+\
- [x] echo bonjour > $test w/ t
- [x] sleep 5 | exit
- [x] cat | cat | cat | ls # check outputs order
- [x] export var ="cat Makefile | grep >"
- [x] export "test=ici"=coucou
- [ ] c$var Makefile # with var=at

# Mauvais message d'erreur
- [ ] cat Makefile | grep pr | head -n 5 | cd test (mybin) # check status code

## leaks 🤬



## On gere pas 😳
- [x] ```cat /dev/random | head -n 1 | cat -e```

## on doit pas gerer
- [ ] ```echo "\s" & echo "\\s"```
- [ ] ```echo "\"```
- [ ] ```echo "bip | bip ; coyotte > < \" "```
- [ ] ```cd ~```
- [ ] ```cd //```
- [ ] ```echo $PWD; echo $OLDPWD; cd //; pwd; echo $PWD; echo $OLDPWD```

### Autre



## Segmentation fault 😭


## Message d'erreur 🧐

- [ ] ```cd ' / '```
- [ ] ```echo $PWD; echo $OLDPWD; cd ' / '; pwd; echo $PWD; echo $OLDPWD ```

### Ces cas

OK
```shell
ls | wc |  cat -e ; ls | ckjefvkj
minishell: ckjefvkj: command not found

minishell: ckjefvkj: command not found
```
OK
```shell
ls | wc > b
wc: '>': No such file or directory
0 0 0 b
0 0 0 total
```
OK
- [ ] ```echo puta madre | cat -e```
```
admin ➜ minishell1 echo puta madre | cat -e
puta madre$
free(): invalid pointer
[1]    18526 abort      ./minishell
```
- [x] ```cat | ls```
- [ ] ```ls -la | rev | cat -e```
- [ ] ```cat /dev/random | head -c 10```

### Messages d'erreur

```shell
$ dd ou ; echo $?
dd: unknown operand ou
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