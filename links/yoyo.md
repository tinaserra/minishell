# TEST YOYO

## Leaks


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

exit
exit 2
exit 3
exit ' 3'         
exit '\t3'        
exit '\t\f\r 3'   
exit '3 '         
exit '3\t'        
exit '3\r'        
exit '3\t\f\r '   
exit '3     a'    
exit '3\t\t\ta'   
exit 0            
exit -0           
exit -1           
exit 255          
exit 256          
exit 2000000      
exit -2000000     
exit 2147483647
exit -2147483648           
exit 2147483648            
exit -2147483649           
exit 3147483648            
exit -3147483649           
exit 4294967295            
exit 4294967296            
exit -9223372036854775808  
exit 9223372036854775807   
exit -9223372036854775809  
exit 9223372036854775808   
exit 18446744073709551615  
exit 18446744073709551616  
exit +1                    
exit +2                    
exit +3                    
exit +0                    
exit +255                  
exit +256                  
exit +2000000              
exit +2147483647           
exit ++1                   
exit ++2                   
exit ++3                   
exit ++0                   
exit ++255                 
exit ++256                 
exit ++2000000             
exit ++2147483647          
exit --1                   
exit --2                   
exit --3                   
exit --0                   
exit --255                 
exit --256                 
exit --2000000             
exit --2147483647          
exit bonjour               
exit 0_                    
exit _0                    
exit 0123456789            
exit -0123456789  
exit 00000000000000000000000000000000000000000000001 
exit 0 bonjour 
exit bonjour 0    
exit 0 1     
exit 0 1 2 3 4 5 6 7 8 9              
exit bonjoru; echo should have exited 
exit 9999; echo should have exited    
Exit; echo a 
exiT; echo a  



pwd                                                                       
cd ..; pwd                                                         
cd ../..; pwd                                                      
cd ../../..; pwd                                                   
cd /; pwd                                                          
cd $HOME; pwd                                                      

notfound                                                                  
notfound a b c                                                            
echo "\"" >>a"b""c"                                                       
echo foo>bar                                                              
echo foo >bar                                                             
echo foo> bar                                                             
echo foo > bar                                                            
touch a b c; /usr/bin/ls                                           
touch a b c; /usr/bin/ls -l                                        
touch a b c; cp /usr/bin/ls bonjour; ./bonjour                     
touch a b c; cp /usr/bin/ls bonjour; ./bonjour -l                  
touch a b c; echo bonjour > a; cp /usr/bin/cat ls; ./ls . a b c    
touch a b c; echo bonjour > a; cp /usr/bin/cat ls; ls . a b c      
echo > somefile
chmod 000 somefile; ./somefile                    
chmod 001 somefile; ./somefile                    
chmod 002 somefile; ./somefile                    
chmod 003 somefile; ./somefile                    
chmod 004 somefile; ./somefile                    
chmod 005 somefile; ./somefile                    
chmod 006 somefile; ./somefile                    
chmod 007 somefile; ./somefile                    
chmod 010 somefile; ./somefile                    
chmod 020 somefile; ./somefile                    
chmod 030 somefile; ./somefile                    
chmod 040 somefile; ./somefile                    
chmod 050 somefile; ./somefile                    
chmod 060 somefile; ./somefile                    
chmod 070 somefile; ./somefile                    
chmod 100 somefile; ./somefile                    
chmod 200 somefile; ./somefile                    
chmod 300 somefile; ./somefile                    
chmod 400 somefile; ./somefile                    
chmod 500 somefile; ./somefile                    
chmod 600 somefile; ./somefile                    
chmod 700 somefile; ./somefile                    
chmod 755 somefile; ./somefile                    
chmod 644 somefile; ./somefile                    
chmod 311 somefile; ./somefile                    
chmod 111 somefile; ./somefile                    
chmod 222 somefile; ./somefile                    
chmod 333 somefile; ./somefile
mkdir somedir; somedir/ 
.mkdir somedir; /somedir/                                          
mkdir somedir; somedir
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
mkdir -m 0777 somedir; ./somedir                                   
mkdir -m 1000 somedir; ./somedir                                   
mkdir -m 2000 somedir; ./somedir                                   
mkdir -m 3000 somedir; ./somedir                                   
mkdir -m 4000 somedir; ./somedir                                   
mkdir -m 5000 somedir; ./somedir                                   
mkdir -m 6000 somedir; ./somedir                                   
mkdir -m 7000 somedir; ./somedir                                   
mkdir -m 1777 somedir; ./somedir                                   
mkdir -m 2777 somedir; ./somedir                                   
mkdir -m 3777 somedir; ./somedir                                   
mkdir -m 4777 somedir; ./somedir                                   
mkdir -m 5777 somedir; ./somedir                                   
mkdir -m 6777 somedir; ./somedir                                   
mkdir -m 0000 somedir; ./somedir                                   
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