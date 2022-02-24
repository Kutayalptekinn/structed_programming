#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main()
{
	char Main_text[500]="I Want More Text to Search in Main Text";
	char Searched[500]="Text";
	int Main_Text_Length=0;
	int Searched_Text_length=0;
	int i,j,Control=0;
	
	printf("Searched Text:");
	scanf("%s",Searched);
	
	i=0;
	while(Main_text[i]!=0)
	{
			i++;
			Main_text[i]=tolower(Main_text[i]);
	}

	Main_Text_Length=i;
	
	i=0;
	while(Searched[i]!=0)
	{
			i++;
			Searched[i]=tolower(Searched[i]);
	}

	Searched_Text_length=i;
	
	
	
	
	
	
	
	for(i=0;i<(Main_Text_Length-Searched_Text_length+1);i++)
	{
	     j=0;
	     while((j<Searched_Text_length)&&(Searched[j]==Main_text[i+j]))
	    {
		j++;
		}	
		if(j==Searched_Text_length)
		{
			printf("Found: %d to %d\n",i+1,i+j+1);
			Control++;
		}
	}
	if(Control==0)
	{
		printf("not found");
		
	}
	else{
			printf("rep num: %d",Control);
		}
	
	
	return 0;
}
