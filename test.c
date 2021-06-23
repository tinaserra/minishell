#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    
    char *args[] = {"/bin/ls", NULL} ;

    execve("/bin/ls", args, NULL);

	return (0);
}