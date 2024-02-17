#include <stdio.h>
#include <stdlib.h>

int
fileAccessCheck(FILE* fp)
{
	if(fp == NULL){
		printf("\ncould't get the file\n\n");
		exit(1);
	}
	return 0;
}

int
printFile(FILE* fp)
{
	char buffer[1000];
	fgets(buffer,1000,fp);
	printf("%s",buffer);
	return 0;
}

int 
main(int argc, char* argv[])
{
	FILE* fptr;
	fptr = fopen(argv[1],"r");
	
	fileAccessCheck(fptr);

	printFile(fptr);
	return 0;
}
