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
				printf("Toplanacak ilk sayý: ");
				scanf("%d", &x);  
				printf("Toplanacak ikinci sayý: ");
				scanf("%d", &y); 
				printf("%d + %d = %d \n", x, y, SUM(x,y));
				
				break;
			case 2:
				printf("Eksilen sayý: ");
				scanf("%d", &x);  
				printf("Çýkan sayý: ");
				scanf("%d", &y); 
				printf("%d - %d = %d \n", x, y, DIFFERENCE(x,y));
			
				break;
			case 3:
				printf("1.Çarpan sayý: ");
				scanf("%d", &x);  
				printf("2.Çarpan sayý: ");
				scanf("%d", &y); 
				printf("%d * %d = %d \n", x, y, PRODUCT(x,y));
			
				break;
			case 4:
				printf("Bölünen sayý: ");
				scanf("%d", &x);  
				printf("Bölen sayý: ");
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
				printf("Geçerli bir giriþ yapmadýnýz, tekrar deneyin...\n");
				break;
		}
	}
	
	return 0;
}
