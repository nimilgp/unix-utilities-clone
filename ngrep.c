#include <stdio.h>
#include <stdlib.h>

int
fileAccessCheck(FILE* fp,char* fileName)
{
	if(fp == NULL){
		printf("\nngrep: could't get the file:%s\n\n",fileName);
		exit(1);
	}
	return 0;
}

int
scanFile(FILE* fp,char* matchStr)
{
	char* buffer;
	size_t buff_size = 64;
	buffer = (char*)malloc(buff_size*sizeof(char));
	
	while(getline(&buffer,&buff_size,fp) != -1)
	{
		printf("%s",buffer);
	}
	return 0;
}

int 
main(int argc, char* argv[])
{
	FILE* fptr;
	
	fptr = fopen(argv[2],"r");
	fileAccessCheck(fptr,argv[2]);
	scanFile(fptr,argv[1]);
	fclose(fptr);

	return 0;
}
