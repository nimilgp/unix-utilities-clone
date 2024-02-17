#include <stdio.h>
#include <stdlib.h>

int
fileAccessCheck(FILE* fp,char* fileName)
{
	if(fp == NULL){
		printf("\nnunzip: could't get the file:%s\n\n",fileName);
		exit(1);
	}
	return 0;
}

int 
isItDigit(char val)
{
	if(val >= '0' && val <= '9')
	{
		return 1;
	}
	return 0;
}

int
unCompressFile(FILE* fp)
{
	char temp;
	char char_val;
	int count = 0;

	while(fread(&temp,sizeof(char),1,fp)!=0)
	{
		if(isItDigit(temp))
		{
			count = count*10;
			count += temp-'0';	
		}
		else
		{
			char_val = temp;
			for(int i = 0; i<count; i++)
			{
				printf("%c",char_val);
			}
			count = 0;
		}
	}
	return 0;
}

int 
main(int argc, char* argv[])
{
	FILE* fptr;
	int count = 1;
	
	if(argc<2)
	{
		printf("[ussage] : nunzip {file} ...");
	}
	while(count<argc){
		fptr = fopen(argv[count],"r");
		fileAccessCheck(fptr,argv[count]);
		unCompressFile(fptr);
		fclose(fptr);
		count++;
	}
	printf("\n");
	exit(0);
	return 0;
}
