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
compressFile(FILE* fp)
{
	char cur_char;
	char temp_char;
	int count = 0;
	
	while(fread(&cur_char,sizeof(char),1,fp)!=0)
	{
		if(count == 0)
		{
			temp_char = cur_char;
		}
		if(temp_char == cur_char)
		{
			count++;
		}
		else
		{
			printf("%d",count);
			printf("%c",temp_char);

			temp_char = cur_char;
			count = 1;
		}
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
		compressFile(fptr);
		fclose(fptr);
		count++;
	}
	printf("\n");
	exit(0);
	return 0;
}
