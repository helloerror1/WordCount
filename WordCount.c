#include<stdio.h>
#include <stdlib.h>
#include <ctype.h>
int main(int argc, char *argv[])
{
	if(argc==3)
	{
		char data;
	    FILE *fp = fopen(argv[2],"r");
	    printf(fp);
        if((fp=fopen(argv[2],"r"))==NULL){
             printf("错误：文件读取失败\n");
             return -1;
         }       
		if(!strcmp(argv[1],"-c"))
		{
			char temp;
			int num=0;
			temp=fgetc(fp);
			while(temp!=EOF){
				temp=fgetc(fp);
				num++;
			}
			printf("字符数:%d",num);
		}
		else if(!strcmp(argv[1],"-w"))
		{
			int w=0;
			char a=fgetc(fp);
			while(a!=EOF)
			{
				if((a>='a'&&a<='z')||(a>='A'&&a<='Z')||(a>='0'&&a<='9'))
				{
					while((a>='a'&&a<='z')||(a>='A'&&a<='Z')||(a>='0'&&a<='9'))
					a=fgetc(fp);
					w++;
					a=fgetc(fp);
				}
				else{
					a=fgetc(fp);
				}
			}
			printf("单词数:%d",w);
		}		
	}
	else{
		printf("错误：运行参数必须要3个\n");
		printf("用法：wordcount1.exe [parameter] [file_name]\n");
	}
	return 0;
 } 
