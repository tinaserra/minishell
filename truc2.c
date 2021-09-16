#include <stdio.h>  /* puts(), printf(), NULL */
#include <stdlib.h> /* strtoul() */
#include <limits.h> /* ULONG_MAX */
#include <string.h> /* strerror() */
#include <errno.h>  /* errno */
 
static void	test(const char *nombre)
{
	unsigned long res;
	
	/* On réinitialise errno */
	errno = 0;

	/* Appel de strtoul : conversion d'une chaine en un entier unsigned long */
	res = strtoul(nombre, NULL, 10);

	/*
	 * On détecte une erreur de strtoul quand elle renvoie ULONG_MAX _et_
	 * que errno est non nul. En effet, si on lui passe en entrée la
	 * représentation de ULONG_MAX, la conversion se fait sans erreur
	 * et errno reste à 0.
	*/
	if (res == ULONG_MAX && errno != 0)
	{
		/* Il y a eu une erreur ! */
		fprintf(stderr, "Impossible de convertir le nombre '%s': %s.\n",
			nombre, strerror(errno));
	}
	else
	{
		printf("La conversion a été effectuée, et la valeur est: %lu\n", res);
	}
}

int		main(void)
{
	/* 2 puissance 8 : sera toujours accepte */
	test("256");

	/* 2^64 - 1 : peut echouer suivant la machine */
	test("18446744073709551656546511568651686461386465165115");
	return (EXIT_SUCCESS);
}