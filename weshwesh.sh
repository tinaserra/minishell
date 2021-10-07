make re

echo START > my_output
echo START > bash_output

input="tests/echo.txt"
while IFS= read -r line
do
	echo "$line" | ./minishell > wesh \
	&& cat wesh | sed 's/^.\{39\}//g' | sed -n '1~2p' | sed "1d" >> my_output
	echo "$line" | bash >> bash_output

	rm -f wesh
done < "$input"

cat my_output | sed '/exit/d' > my_output
#cat my_output2 | sed 's/exit//' > my_output2

#echo "** DIFF START ------------------------ **"
#diff bash_output my_output
#echo "** DIFF END -------------------------- **"