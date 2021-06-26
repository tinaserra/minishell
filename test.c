/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vserra <vserra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 17:04:15 by vserra            #+#    #+#             */
/*   Updated: 2021/06/26 17:07:14 by vserra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
// #include <wait.h>

#define READ_PIPE 0 // stdin
#define WRITE_PIPE 1 // stdout

#define BUFFER_MAX 255

int main(void){
	
	pid_t returnPID;

	int thePipe[2];
	char buffer[BUFFER_MAX];

	pipe(thePipe);
	if(thePipe < 0)
	{
		printf("Error creating pipe.\n");
		 exit(EXIT_FAILURE);
	}

	returnPID = fork();
	if(returnPID < 0)
	{
		printf("Error forking.\n");
		exit(EXIT_FAILURE);
	}
	//in child process
	if(returnPID == 0)
	{
		close(thePipe[READ_PIPE]);
		dup2(thePipe[WRITE_PIPE], 1);
		printf("Never attribute to malice that which can be adequately explained by stupidity.\n");
	}
	//in parent process
	else
	{
		close(thePipe[WRITE_PIPE]);
		wait(NULL);
		printf("In parent process: ");
		read(thePipe[READ_PIPE], buffer, BUFFER_MAX);
		printf("%s\n", buffer);
	}

	return 0;

}

// int main(void)
// {

// 	int fd[2], messageLength, returnVal;

// 	char buffer[BUFFER_MAX+1];
// 	char message[BUFFER_MAX+1]; 

// 	if((pipe(fd) < 0))
// 	{
// 		printf("Error creating pipe.\n");
// 		exit(EXIT_FAILURE);
// 	}

// 	if((returnVal=fork()) < 0)
// 	{
// 		printf("Error forking.\n");
// 		exit(EXIT_FAILURE);
// 	}
	
// 	//in child process
// 	if(returnVal==0)
// 	{
// 		//close write descriptor
// 		close(fd[WRITE]);
// 		messageLength = read(fd[READ], buffer, BUFFER_MAX);
// 		buffer[messageLength] = '\0';
// 		printf("received: '%s'\n", buffer);
// 		//close read descriptor
// 		close(fd[READ]);
// 	}

// 	//in parent process
// 	if(returnVal > 0)
// 	{
// 		//close read descriptor
// 		close(fd[READ]);
// 		//copy message
// 		char *s = "A strange game. The only winning move is not to play.";
// 		strcpy(message, s);
// 		//send message
// 		write(fd[WRITE], message, strlen(message));
// 		//close write descriptor
// 		close(fd[WRITE]);
// 		//wait for child process to finish
// 		waitpid(returnVal, NULL, 0);

// 		printf("Exiting parent process.\n");
		
// 		return (0);
// 	}
// }

// int main(void)
// {
// 	int thePipe[2];
// 	pid_t pid;

// 	char buffer[MAX_LINE+1];

// 	// if((pipe(myPipe)) < 0)
// 	// {
// 	// 	printf("Error creating pipe.\n");
// 	// 	exit(EXIT_FAILURE);
// 	// }

// 	if(pipe(thePipe) != 0)
// 		exit(EXIT_FAILURE);

// 	pid = fork();
// 	if(pid < 0)
// 		exit(EXIT_FAILURE);

// 	if(pid == 0)
// 	{
// 		read(thePipe[READ], buffer, MAX_LINE);
// 		printf("Child read: %s\n", buffer);
// 		printf("Exiting from child process.\n");
// 	}
// 	else
// 	{
// 		char *str = "I survived the Kobayashi Maru!";
// 		write(thePipe[WRITE], str, strlen(str));
// 		wait(NULL);
// 		printf("Exiting from parent process.\n");
// 		printf("Descriptors are %d and %d\n", thePipe[READ], thePipe[WRITE]);
// 	}

// 	return 0;
// }
