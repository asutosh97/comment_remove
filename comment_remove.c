#include<stdio.h>
int main(int argc,char *argv[])
{
	FILE *fp1,*fp2;
	fp1=fopen(argv[1],"r");
	fp2=fopen("without_comments.c","w");
	char c;
	c=fgetc(fp1);
	while(c!=EOF)
	{
		if(c=='/')
		{
			if((c=fgetc(fp1))=='/')
			{
				while((c=fgetc(fp1))!='\n'&&(c!=EOF));
			}
			else if(c=='*')
			{
				X:
				while((c=fgetc(fp1))!='*'&&(c!=EOF));
				if(c=='*')
				{
					if((c=fgetc(fp1))!='/')
						goto X;
				}
			}
			else
			{
				fputc('/',fp2);
				fputc(c,fp2);
			}
		}
		else
		{
			fputc(c,fp2);
		}
		c=fgetc(fp1);
	}
	fclose(fp1);
	fclose(fp2);
	printf("Succcessful!!!\n");
	return 0;
}