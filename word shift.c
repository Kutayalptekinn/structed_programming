#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[])
{
	int i = 0;
	int c,k;
	char a[50];
	char b[50];
	printf("enter the which will make shift word:\n");
	gets(a);
	
	printf("for left press 1 or right 2:\n");
	scanf("%d",&k);
	
	printf("how many words place change:\n");
	scanf("%d",&c);
	
	if(k==2)
	{
		while(a[i]!=0)
		{
			if(a[i]+c<'z' && a[i]+c>'a' )
			b[i]=a[i]+c;
			
			if(a[i]==' ')
			b[i]=' ';
			
			if(a[i]+c>'z'&& a[i]!=' ')
			b[i]=((a[i]+c)%25)+'a';
			//42+112 34
			i++;
			
		}	
		printf("word the right shift one:\n");
		printf("%s",b);	
	}
	
	else if(k==1)
	{
		while(a[i]!=0)
		{
			if(a[i]-c<'z' && a[i]-c>'a' )
			b[i]=a[i]-c;
			
			if(a[i]==' ')
			b[i]=' ';			
			
			if(a[i]-c<'a' && a[i]!=' ')
			b[i]=((a[i]-c-'a')+26)+'a';
			
			i++;
			
		}	
		printf("word the left shift one:\n");
		puts(b);	
		
		
	}
	return 0;
}

//i=0;
//		while(b[i]!=0)
//		{
//		printf("%c",b[i]);
//		i++;
//		}
