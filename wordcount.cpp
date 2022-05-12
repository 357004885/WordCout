#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc,char** argv)
{
	char *s1 = "-w";
	char *s2 = "-c";
	FILE *fp;
	char ch;
	int i,a,b;
	i=a=b=0;
	fp=fopen(argv[2],"r");
	if(fp==NULL)
	{
		printf("can not open the file\n");
		exit(0);
	}
	ch=fgetc(fp);
	if(strcmp(argv[1],s1) == 0)
	{
		while (ch!=EOF)
		{
			i++;    
			if(ch==' '||ch=='.'||ch==',') 
				i--;
			ch=fgetc(fp);  
		}
		printf("字符数量为：%d",i);
	}
	else if(strcmp(argv[1],s2) == 0)
	{
		while (ch!=EOF)
		{
			if(ch==' '||ch==','||ch=='.')
			{	
				ch=fgetc(fp);
		 		if(!(ch==' '||ch==','||ch=='.'))
					b++;
			}
			else ch=fgetc(fp);
		}
		printf("单词数量为：%d",b);
	}
	else
	{
		printf("输入错误");	
	}
	fclose(fp);  
return 0;
}

