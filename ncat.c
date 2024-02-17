#include <stdio.h>
#include <stdlib.h>

int
fileAccessCheck(FILE* fp,char* fileName)
{
	if(fp == NULL){
		printf("\nncat: could't get the file:%s\n\n",fileName);
		exit(1);
	}
	return 0;
}

int
printFile(FILE* fp)
{
	char buffer[100];
	while(fgets(buffer,100,fp)!=NULL)
	{
		printf("%s",buffer);
	}
	return 0;
}

int 
main(int argc, char* argv[])
{
	FILE* fptr;
	int count = 1;
	while(count<argc){
		fptr = fopen(argv[count],"r");
		fileAccessCheck(fptr,argv[count]);
		printFile(fptr);
		fclose(fptr);
		count++;
	}
	exit(0);
	return 0;
}
