# TEST YOYO

## Leaks

## PAS OK

touch a b c; /usr/bin/ls                                           
touch a b c; /usr/bin/ls -l                                        
touch a b c; cp /usr/bin/ls bonjour; ./bonjour                     
touch a b c; cp /usr/bin/ls bonjour; ./bonjour -l                  
touch a b c; echo bonjour > a; cp /usr/bin/cat ls; ./ls . a b c    
touch a b c; echo bonjour > a; cp /usr/bin/cat ls; ls . a b c      
echo > somefile

## Ok
- [x] echo $PWD; echo $OLDPWD; cd .; pwd; echo $PWD; echo $OLDPWD
- [x] echo $PWD; echo $OLDPWD; cd ..; pwd; echo $PWD; echo $OLDPWD
- [x] echo $PWD; echo $OLDPWD; cd ../..; pwd; echo $PWD; echo $OLDPWD
- [x] echo $PWD; echo $OLDPWD; cd ../../..; pwd; echo $PWD; echo $OLDPWD
- [x] echo $PWD; echo $OLDPWD; cd ../../../..; pwd; echo $PWD; echo $OLDPWD
- [x] echo $PWD; echo $OLDPWD; cd ''; pwd; echo $PWD; echo $OLDPWD
- [x] echo $PWD; echo $OLDPWD; cd /; pwd; echo $PWD; echo $OLDPWD
- [x] echo $PWD; echo $OLDPWD; cd ../../../../..; pwd; echo $PWD; echo $OLDPWD
- [x] echo $PWD; echo $OLDPWD; cd '' ''; pwd; echo $PWD; echo $OLDPWD
- [x] echo $PWD; echo $OLDPWD; cd '' '' ''; pwd; echo $PWD; echo $OLDPWD
- [x] echo $PWD; echo $OLDPWD; cd ' '; pwd; echo $PWD; echo $OLDPWD
- [x] echo $PWD; echo $OLDPWD; cd /; pwd; echo $PWD; echo $OLDPWD
- [x] echo $PWD; echo $OLDPWD; cd /.; pwd; echo $PWD; echo $OLDPWD
- [x] echo $PWD; echo $OLDPWD; cd /./; pwd; echo $PWD; echo $OLDPWD
- [x] echo $PWD; echo $OLDPWD; cd /././././; pwd; echo $PWD; echo $OLDPWD
- [x] echo $PWD; echo $OLDPWD; cd //; pwd; echo $PWD; echo $OLDPWD
- [x] echo $PWD; echo $OLDPWD; cd ///; pwd; echo $PWD; echo $OLDPWD
- [x] echo $PWD; echo $OLDPWD; cd ////; pwd; echo $PWD; echo $OLDPWD
- [x] echo $PWD; echo $OLDPWD; cd; echo $OLDPWD
- [x] echo $PWD; echo $OLDPWD; cd ' /'; pwd; echo $PWD; echo $OLDPWD
- [x] echo $PWD; echo $OLDPWD; cd ' / '; pwd; echo $PWD; echo $OLDPWD
- [x] echo $PWD; echo $OLDPWD; cd ' // '; pwd; echo $PWD; echo $OLDPWD
- [x] echo $PWD; echo $OLDPWD; cd //home; pwd; echo $PWD; echo $OLDPWD
- [x] echo $PWD; echo $OLDPWD; cd ' //home'; pwd; echo $PWD; echo $OLDPWD
- [x] echo
- [x] echo bonjour
- [x] echo bonjour | cat -e
- [x] echo lalalala lalalalal alalalalal alalalala
- [x] echo lalalala                lalalalal      alalalalal alalalala          
- [x] echo -n
- [x] echo -n bonjour
- [x] echo -n lalalala lalalalal alalalalal alalalala
- [x] echo -n lalalala                lalalalal      alalalalal alalalala
- [x] echo bonjour -n
- [x] echo -n bonjour -n
- [x]                         echo                     bonjour             je
- [x]                         echo       -n            bonjour             je
- [x] echo a '' b '' c '' d
- [x] echo a "" b "" c "" d
- [x] echo -n a '' b '' c '' d
- [x] echo -n a "" b "" c "" d
- [x] echo '' '' ''                                                             
- [x] Echo bonjour                                                              
eCho bonjour                                                              
ecHo bonjour                                                              
echO bonjour                                                              
EchO bonjour                                                              
eCHo bonjour                                                              
EcHo bonjour                                                              
- [x] eChO bonjour                                                              
- [x] echo -n -n -n -n bonjour                                                  
- [x] echo -nnnnnnnnnnnnnnnnnnnnn bonjour                                       
- [x] echo -nnnnnnnnnnnnnnnnnnnnn -n -n -n bonjour -n -n                        
- [x] mkdir -m 000 d; echo $PWD; echo $OLDPWD; cd d; echo $OLDPWD
mkdir -m 001 d; echo $PWD; echo $OLDPWD; cd d; echo $OLDPWD
mkdir -m 002 d; echo $PWD; echo $OLDPWD; cd d; echo $OLDPWD
mkdir -m 003 d; echo $PWD; echo $OLDPWD; cd d; echo $OLDPWD
mkdir -m 004 d; echo $PWD; echo $OLDPWD; cd d; echo $OLDPWD
- [x] mkdir -m 005 d; echo $PWD; echo $OLDPWD; cd d; echo $OLDPWD
mkdir -m 006 d; echo $PWD; echo $OLDPWD; cd d; echo $OLDPWD
- [x] mkdir -m 007 d; echo $PWD; echo $OLDPWD; cd d; echo $OLDPWD
- [x] mkdir -m 010 d; echo $PWD; echo $OLDPWD; cd d; echo $OLDPWD
mkdir -m 020 d; echo $PWD; echo $OLDPWD; cd d; echo $OLDPWD
mkdir -m 030 d; echo $PWD; echo $OLDPWD; cd d; echo $OLDPWD
mkdir -m 040 d; echo $PWD; echo $OLDPWD; cd d; echo $OLDPWD
mkdir -m 050 d; echo $PWD; echo $OLDPWD; cd d; echo $OLDPWD
mkdir -m 060 d; echo $PWD; echo $OLDPWD; cd d; echo $OLDPWD
- [x] mkdir -m 070 d; echo $PWD; echo $OLDPWD; cd d; echo $OLDPWD

Cd .
cD .

- [x] exit
- [x] exit 2
- [x] exit 3
- [x] exit ' 3'         
- [x] exit '\t3'
- [x] exit '\t\f\r 3'   
- [x] exit '3 '         
- [x] exit '3\t'        
exit '3\r'        
exit '3\t\f\r '   
exit '3     a'    
exit '3\t\t\ta' 
- [x] exit 0            
- [x] exit -0           
- [x] exit -1           
- [x] exit 255          
- [x] exit 256   
- [x] exit 2000000      
- [x] exit -2000000  
- [x] exit 2147483647
- [x] exit -2147483648
- [x] exit 2147483648            
- [x] exit -2147483649
- [x] exit 3147483648            
- [x] exit -3147483649   
- [x] exit 4294967295            
- [x] exit 4294967296            
- [x] exit -9223372036854775808  
- [x] exit 9223372036854775807  

<!-- bash: exit: 9223372036854775808: numeric argument required -->
- [x] exit -9223372036854775809  
- [x] exit 9223372036854775808   
- [x] exit 18446744073709551615  
- [x] exit 18446744073709551616

- [x] exit +1                    
- [x] exit +2                    
- [x] exit +3                    
- [x] exit +0   
- [x] exit +255                  
- [x] exit +256                  
- [x] exit +2000000              
- [x] exit +2147483647   
- [x] exit ++1                   
- [x] exit ++2                   
- [x] exit ++3                   
- [x] exit ++0                   
- [x] exit ++255                 
- [x] exit ++256                 
- [x] exit ++2000000             
- [x] exit ++2147483647          
- [x] exit --1                   
- [x] exit --2                   
- [x] exit --3                   
- [x] exit --0                   
- [x] exit --255                 
- [x] exit --256                 
- [x] exit --2000000             
- [x] exit --2147483647
- [x] exit bonjour    
- [x] exit 0_                    
- [x] exit _0  
- [x] exit 0123456789            
- [x] exit -0123456789  
- [x] exit 00000000000000000000000000000000000000000000001 
- [x] exit 0 bonjour 
- [x] exit bonjour 0    
- [x] exit 0 1     
- [x] exit 0 1 2 3 4 5 6 7 8 9              
- [x] exit bonjoru; echo should have exited 
- [x] exit 9999; echo should have exited    
- [x] Exit; echo a 
- [x] exiT; echo a  


## Strange cases

mkdir -m 100 d; echo $PWD; echo $OLDPWD; cd d; echo $OLDPWD [pas ok](prout)
mkdir -m 200 d; echo $PWD; echo $OLDPWD; cd d; echo $OLDPWD
mkdir -m 300 d; echo $PWD; echo $OLDPWD; cd d; echo $OLDPWD [pas ok](prout)
mkdir -m 400 d; echo $PWD; echo $OLDPWD; cd d; echo $OLDPWD
mkdir -m 500 d; echo $PWD; echo $OLDPWD; cd d; echo $OLDPWD
mkdir -m 600 d; echo $PWD; echo $OLDPWD; cd d; echo $OLDPWD
mkdir -m 700 d; echo $PWD; echo $OLDPWD; cd d; echo $OLDPWD
mkdir -m 755 d; echo $PWD; echo $OLDPWD; cd d; echo $OLDPWD
mkdir -m 644 d; echo $PWD; echo $OLDPWD; cd d; echo $OLDPWD
mkdir -m 311 d; echo $PWD; echo $OLDPWD; cd d; echo $OLDPWD
mkdir -m 111 d; echo $PWD; echo $OLDPWD; cd d; echo $OLDPWD
mkdir -m 222 d; echo $PWD; echo $OLDPWD; cd d; echo $OLDPWD
mkdir -m 333 d; echo $PWD; echo $OLDPWD; cd d; echo $OLDPWD

mkdir -m 0777 d; echo $PWD; echo $OLDPWD; cd d; echo $OLDPWD
mkdir -m 1000 d; echo $PWD; echo $OLDPWD; cd d; echo $OLDPWD
mkdir -m 2000 d; echo $PWD; echo $OLDPWD; cd d; echo $OLDPWD
mkdir -m 3000 d; echo $PWD; echo $OLDPWD; cd d; echo $OLDPWD
mkdir -m 4000 d; echo $PWD; echo $OLDPWD; cd d; echo $OLDPWD
mkdir -m 5000 d; echo $PWD; echo $OLDPWD; cd d; echo $OLDPWD
mkdir -m 6000 d; echo $PWD; echo $OLDPWD; cd d; echo $OLDPWD
mkdir -m 7000 d; echo $PWD; echo $OLDPWD; cd d; echo $OLDPWD
mkdir -m 1777 d; echo $PWD; echo $OLDPWD; cd d; echo $OLDPWD
mkdir -m 2777 d; echo $PWD; echo $OLDPWD; cd d; echo $OLDPWD
mkdir -m 3777 d; echo $PWD; echo $OLDPWD; cd d; echo $OLDPWD
mkdir -m 4777 d; echo $PWD; echo $OLDPWD; cd d; echo $OLDPWD
mkdir -m 5777 d; echo $PWD; echo $OLDPWD; cd d; echo $OLDPWD
mkdir -m 6777 d; echo $PWD; echo $OLDPWD; cd d; echo $OLDPWD
mkdir -m 7777 d; echo $PWD; echo $OLDPWD; cd d; echo $OLDPWD
mkdir -m 0000 d; echo $PWD; echo $OLDPWD; cd d; echo $OLDPWD

## Non testé

- [x] pwd                                                                       
- [x] cd ..; pwd                                                         
- [x] cd ../..; pwd                                                      
- [x] cd ../../..; pwd                                                   
- [x] cd /; pwd                                                          
- [x] cd $HOME; pwd                                                      
- [x] notfound                                                                  
- [x] notfound a b c    
- [x] echo foo>bar
- [x] echo foo >bar                                                             
- [x] echo foo> bar 
- [x] echo foo > bar 
- [x] mkdir somedir; somedir

mkdir somedir; somedir/ 

.mkdir somedir; /somedir/                                          
mkdir somedir; ./somedir  

mkdir somedir; somedir
ln -s somedir somedirsoftlink; somedirsoftlink/     
ln -s somedir somedirsoftlink; ./somedirsoftlink/   
ln -s somedir somedirsoftlink; somedirsoftlink      
ln -s somedir somedirsoftlink; ./somedirsoftlink    
ln -s somedir somedirsoftlink; somedirsoftlink      
touch _; _                                                         
touch -; '-'                                                       
touch _; ./_                                                       
touch a; mv a ./-; ./-                                             
touch .; ./.                                                       
touch ..; ./..                                                     
                    
echo > somefile && chmod 000 somefile; ./Somefile                  
echo > somefile && chmod 000 somefile; ./someFILE                  
echo bonjour > test                                                       
echo > test bonjour                                                       
> test echo bonjour                                                       
echo bonjour >> test                                                      
echo >> test bonjour                                                      
>> test echo bonjour                                                      
echo bonjour > test; cat < test                                    
echo bonjour > test                                                       
echo > test'sticked' bonjour                                              
> test'sticked' echo bonjour                                              
echo bonjour >> test'sticked'                                             
echo >> test'sticked' bonjour                                             
>> test'sticked' echo bonjour                                             
echo bonjour > test'sticked'; cat < test'sticked'                  
echo bonjour > test'sticked'; < test'sticked' cat                  
echo > test"sticked" bonjour                                              
> test"sticked" echo bonjour                                              
echo bonjour >> test"sticked"                                             
echo >> test"sticked" bonjour                                             
>> test"sticked" echo bonjour                                             
echo bonjour > test"sticked"; cat < test"sticked"                  
echo bonjour > test"sticked"; < test"sticked" cat                  
echo > test'yo'"sticked" bonjour                                          
> test'yo'"sticked" echo bonjour                                          
echo bonjour >> test'yo'"sticked"                                         
echo >> test'yo'"sticked" bonjour                                         
>> test'yo'"sticked" echo bonjour                                         
echo bonjour > test'yo'"sticked"; cat < test'yo'"sticked"          
echo bonjour > test'yo'"sticked"; < test'yo'"sticked" cat          
echo bonjour > test > je > suis                                           
echo > test > je bonjour > suis                                           
> test echo bonjour > je > suis                                           
echo bonjour >> test > je >> suis                                         
echo >> test bonjour > je > suis                                          
>> test echo > je bonjour > suis                                          
echo bonjour > test; echo salut > je; cat < test < je              
echo bonjour>test>je>suis                                                 
>test echo bonjour>je>suis                                                
echo bonjour>>test>je>>suis                                               
echo bonjour > test; echo salut > je; cat<test<je                  
echo bonjour > a'b'c'd'e'f'g'h'i'j'k'l'm'n'o'p'q'r's't'u'v'w'x'y'z'       
echo bonjour > a"b"c"d"e"f"g"h"i"j"k"l"m"n"o"p"q"r"s"t"u"v"w"x"y"z"       
echo bonjour > a'b'c"d"e'f'g"h"i'j'k"l"m'n'o"p'q'r"s't'u"v"w"x"y'z'       
> file                                                                    
echo bonjour > file; < file                                        
>                                                                         
>>                                                                        
<                                                                         
echo >                                                                    
echo >>                                                                   
echo <                                                                    
> test                                                                    
>> test                                                                   
touch test; < test                                                 
echo foo >>> bar                                                          
echo foo >>>> bar                                                         
echo foo >>>>> bar                                                        
echo bonjour > bar; cat << < bar                                   
echo bonjour > bar; cat << << bar                                  
echo bonjour > bar; cat <<<<< bar                                  
cat < doesnotexist                                                        
echo a > a; echo bonjour >> a                                      
echo a > a; echo bonjour >> a >> a                                 
echo a > a; echo bonjour > a                                       
echo a > a; echo bonjour > a >> a                                  
echo $?                                                                   
echo; echo $?                                                             
notfound; echo $?                                                         
cat < doesntexist; echo $?                                                
echo bonjour > noperm; chmod 000 noperm; cat < noperm; echo $?     
echo                                                                      
notfound                                                                  
cat < doesntexist                                                         
echo bonjour > noperm; chmod 000 noperm; cat < noperm              
echo bonjour; echo je                                                     
echo bonjour ;echo je                                                     
echo bonjour ; echo je                                                    
echo bonjour;                                                             
echo;                                                                     
echo ;                                                                    
echo ;                                                                    
; echo                                                                    
 ;echo                                                                    
 ; echo                                                                   
ls doesnotexists ; echo bonjour                                           
ls doesnotexists; echo bonjour                                            
echo bonjour; ls doesnotexists                                            
echo a ; ;                                                                
echo a ; ;                                                                
;                                                                         
; ;                                                                       
; ; ;                                                                     
echo a ; ; echo b                                                         
;;                                                                        
;;;                                                                       
;;;;;                                                                     
echo a ;; echo b                                                          
echo a ;;;;; echo b                                                       
cat /etc/shells | head -c 10                                              
cat -e /etc/shells | head -c 10                                           
cat -e /etc/shells | cat -e | head -c 10                                  
cat -e /etc/shells | cat -e | cat -e | head -c 10
echo bonjour | cat                                                        
echo bonjour | cat -e                                                     
touch a b c d; mkdir m1 m2 m3; ls | cat -e                         
touch a b c d; mkdir m1 m2 m3; ls -l | cat -e                      
touch a b c d; mkdir m1 m2 m3; ls -l | cat -e | cat | cat | cat    
echo|                                                                     
echo |                                                                    
echo |                                                                    
|cat                                                                      
| cat                                                                     
 | cat                                                                    
echo a | export A=a; echo $A                                              
export A=a | cat; echo $A                                                 
echo bonjour | | cat -e                                                   
echo bonjour | asdf                                                       
asdf | echo bonjour                                                       
echo a ||| echo b                                                         
ls asdfasdf | echo a                                                      
echo a | ls asdfasdf                                                      
ls asdfasdf | echo a; echo b                                              
echo a | ls asdfasdf; echo b                                              
echo a > foo | cat -e                                                     
echo a >> foo | cat -e                                                    
echo b > foo; echo a | cat -e < foo                                
echo b > foo; echo a > bar | cat -e < foo                          
< | a                                                                     
> | a                                                                     
>> | a                                                                    
< ; a                                                                     
> ; a                                                                     
>> ; a                                                                    
; | a                                                                     
; < a                                                                     
; > a                                                                     
; >> a                                                                    
| ; a                                                                     
| < a                                                                     
| > a                                                                     
| >> a                                                                    
> a ; a                                                                   
< a ; a                                                                   
>> a ; a                                                                  
echo $_                                                                   
echo; echo $_                                                             
env; echo $_                                                              
export A=a; echo $_                                                       
unset A; echo $_                                                          
echo a b c d; echo $_                                                     
cat -e /etc/shells; echo $_                                               
echo a; echo "$_"                                                         
echo a; echo '$_'                                                         
echo a; echo "@$_@"                                                       
echo $SHLVL                                                               

echo \a                                                                   
\e\c\h\o bonjour                                                          
echo charles\                                                             
echo \ \ jesuis\ \ charles                                                
echo \ \ jesuis\; \ charles                                               
echo \ \ jesuis\&\& \ charles                                             
echo \ \ jesuis\|\| \ charles                                             
echo \ \ jesuis \|\| \ charles                                            
echo \ \ jesuis\; \ charles                                               
echo \ \ \ \ \ \ \ \                                                      
echo \ \ \ \ \ \ \ \               \ \ \ \ \ \                            
echo \$PATH                                                               
echo \$\P\A\T\H                                                           
echo\ bonjour                                                             
\ echo bonjour                                                            
 \ echo bonjour                                                           
                 \ echo bonjour                                           
 \                 echo bonjour                                           
                 \                    echo bonjour                        
/bin/echo " \  "                                                          
/bin/echo " \" "                                                          
/bin/echo " \' "                                                          
/bin/echo " \a "                                                          
/bin/echo " \b "                                                          
/bin/echo " \| "                                                          
/bin/echo " \! "                                                          
/bin/echo " \@ "                                                          
/bin/echo " \$ "                                                          
/bin/echo " \$LESS "                                                      
/bin/echo " \$? "                                                         
/bin/echo " \\ "                                                          
/bin/echo " \\\ "                                                         
/bin/echo " \\\\ "                                                        
/bin/echo " \\\\\ "                                                       
/bin/echo " \\\\\\ "                                                      
/bin/echo " \\\\\\\ "                                                     
/bin/echo " \\\\\\\\ "                                                    
/bin/echo ' \  '                                                          
/bin/echo ' \" '                                                          
/bin/echo ' \a '                                                          
/bin/echo ' \b '                                                          
/bin/echo ' \| '                                                          
/bin/echo ' \! '                                                          
/bin/echo ' \@ '                                                          
/bin/echo ' \$ '                                                          
/bin/echo ' $LESS '                                                       
/bin/echo ' \$? '                                                         
/bin/echo ' \\ '                                                          
/bin/echo ' \\\ '                                                         
echo \                                                                    
echo "\""'bonjour'                                                        






'echo' 'bonjour'                                                          
'echo' 'je' 'suis' 'charles'                                              
"echo" "bonjour"                                                          
"echo" "je" "suis" "charles"                                              
echo je'suis'"charles"                                                    
echo "je"suis'charles'                                                    
echo 'je'"suis"charles                                                    
echo "\""                                                                 
echo "\$"                                                                 
echo "\\"                                                                 
echo "\a"                                                                 
echo "\A"                                                                 
ls ""                                                                     
ls ''                                                                     
ls "" "" "" '' """"                                                       
ls '' '' '''' ''                                                          
'     echo' bonjour                                                       
'echo     ' bonjour                                                       
"     echo" bonjour                                                       
"echo     " bonjour                                                       
''echo bonjour                                                            
""echo bonjour                                                            
''''''''''''''''''''''''''''''''''''''''''''''''''''''''''echo bonjour    
""""""""""""""""""""""""""""""""""""""""""""""""""""""""""echo bonjour    
echo'' bonjour                                                            
echo"" bonjour                                                            
echo'''''''''''''''''''''''''''''''''''''''''''''''''''''''''' bonjour    
echo"""""""""""""""""""""""""""""""""""""""""""""""""""""""""" bonjour    
ec''ho bonjour                                                            
ec""ho bonjour                                                            
ec''''''''''''''''''''''''''''''''''''''''''''''''''''''''''ho bonjour    
ec""""""""""""""""""""""""""""""""""""""""""""""""""""""""""ho bonjour    
'''''''e''''''''''c''''''''''''h''''''''o''''''''''''''''''''' bonjour    
"""""""e""""""""""c""""""""""""h""""""""o""""""""""""""""""""" bonjour    
echo '"'                                                                  
echo '""""""""""""""""""""""""""'                                         
echo "'"                                                                  
echo "''''''''''''''''''''''''''"                                         
echo '                                                                    
echo "                                                                    
echo '''                                                                  
echo """                                                                  
echo '''''''''''''''''''''''''''''''''''''''''''                          
echo """""""""""""""""""""""""""""""""""""""""""                          
echo 'AH\'                                                                
echo "AH\"                                                                
echo "AH\""                                                               
echo '\''                                                                 
echo "\""                                                                 
echo "\\""                                                                
echo bonjour > "fi le"                                                    
echo bonjour > 'fi le'                                                    
echo foo                                                                  
echo                    foo                                               
             echo foo                                                     
echo foo                                                                  
         echo           foo                                               
echo\t\t\t\t\t\t\t\t\t\tfoo                                               
\t\t\t\t\t\techo\tfoo                                                     
echo\tfoo\t\t\t\t\t\t                                                     
\t\t\t\techo\t\t\t\tfoo\t\t\t\t                                           
\fecho\ffoo                                                               
\necho\nfoo                                                               
\recho\rfoo                                                               
\vecho\vfoo                                                               
\t\r\v\fecho\v\t\r\vfoo                                                   
                                                                          
                                                                          
\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t                                
            \t\t\t           \t\t\t                                       