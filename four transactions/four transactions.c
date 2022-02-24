#include <stdio.h>
#include <stdlib.h>

#include "calculation.h"
#include "menu.h"


int main(int argc, char** argv) {
	int x, y, selection, run = 1, result, i;
	
	while(run){
		MENU;
		scanf("%d", &selection); 
		switch(selection){
			case 1:
				printf("Toplanacak ilk say�: ");
				scanf("%d", &x);  
				printf("Toplanacak ikinci say�: ");
				scanf("%d", &y); 
				printf("%d + %d = %d \n", x, y, SUM(x,y));
				
				break;
			case 2:
				printf("Eksilen say�: ");
				scanf("%d", &x);  
				printf("��kan say�: ");
				scanf("%d", &y); 
				printf("%d - %d = %d \n", x, y, DIFFERENCE(x,y));
			
				break;
			case 3:
				printf("1.�arpan say�: ");
				scanf("%d", &x);  
				printf("2.�arpan say�: ");
				scanf("%d", &y); 
				printf("%d * %d = %d \n", x, y, PRODUCT(x,y));
			
				break;
			case 4:
				printf("B�l�nen say�: ");
				scanf("%d", &x);  
				printf("B�len say�: ");
				scanf("%d", &y); 
				printf("%d / %d = %d \n", x, y, QUOTIENT(x,y));
				
				break;
			case 5:
				printf("n! , n'i giriniz: ");
				scanf("%d", &x);
				result = 1;
				i = x;
				while(x>1){
					result *=  x--;
				} 
				printf("%d! = ", i);
				for(i; i>=0; i--)
				{					
					if(i == 1){
						printf("%d = %d \n", i, result);
					}
					else if(i>1)
					{
						printf("%d * ", i);	
					}else{
						printf("%d \n", result);
					}
				} 
				
				break;				
			case 6:
				run = 0;
				break;
			default:
				printf("Ge�erli bir giri� yapmad�n�z, tekrar deneyin...\n");
				break;
		}
	}
	
	return 0;
}
