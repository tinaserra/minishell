#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
	fork();

	// imprime deux fois
	printf("Salutations Mundo!\n");

	fork();

	// affiche quatre fois
	printf("Salutations, professeur Falken.\n");

	fork();
	fork();

	// affiche bcp
	printf("coucou\n");
	printf("12\n");
	printf("13\n");
	printf("14\n");
	printf("15\n");
	printf("16\n");

	return (0);
}