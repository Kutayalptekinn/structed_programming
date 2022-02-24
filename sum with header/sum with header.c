#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#include "headerr.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main()
{
	setlocale(LC_ALL,"turkish");
	int x,y;
	int run =1;
	int Selection;
	
	while(run)
	{

		scanf("%d",&Selection);
		
		switch(Selection){
			case 1:
				printf("ilk eleman:");
				scanf("%d",&x);
				printf("ikinci eleman:");
				scanf("%d",&y);
				printf("%d + %d=%d\n",x,y,SUM(x,y));
				break;
				
				case 6:
					printf("Çýkýþ yapýlýyor.");
					run=0;
					break;
		}
	}
	
	return 0;
}
