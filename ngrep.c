#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
		if(strstr(buffer,matchStr)!=NULL)
		{
			printf("%s",buffer);
		}
	}
	return 0;
}

int 
main(int argc, char* argv[])
{
	FILE* fptr;
	int count = 2;
	
	if(argc<2)
	{
		printf("[ussage]: ngrep {searchterm} {filename}\n"); 
		return 1;
	}

	while(count<argc)
	{
		fptr = fopen(argv[count],"r");
		fileAccessCheck(fptr,argv[count]);
		scanFile(fptr,argv[1]);
		fclose(fptr);
		count++;
	}
	return 0;
}
