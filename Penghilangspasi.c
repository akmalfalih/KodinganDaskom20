#include <stdio.h>
#include <string.h>

int main(){
	char string[100];
	int i, panjang;
	
	printf("Masukkan string : "); gets(string);
	panjang = strlen(string);
	
	printf("String tanpa spasi : ");
	for (i = 0; i <= panjang; i++){
		if(string[i] != 32){
			printf("%c", string[i]);
		}
	}
}
