EXEC=minishell;ARGS=;valgrind --tool=memcheck --leak-check=full --leak-resolution=high --show-reachable=yes --suppressions=supress_readline_error --log-file=valgrind_log.txt ./$EXEC $ARGS;grep -A1 "valgrind" valgrind_log.txt|grep $EXEC