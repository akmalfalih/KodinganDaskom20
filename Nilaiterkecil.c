#include <stdio.h>
#include <string.h>

struct input{
	char string[100];
};

int main(){
	int n, i, panjang[n], min;
	struct input a[100];
	
	printf("Jumlah string : "); scanf("%d", &n); getchar();
	for(i = 0; i < n; i++){
		printf("String %d : ", i+1); gets(a[i].string);
		panjang[i] = strlen(a[i].string);
	}
	min = panjang[0];
	
	for(i = 0; i < n; i++){
		if(panjang[i] < min){
			min = panjang[i];
		}
	}
	printf("Panjang string terpendek : %d", min);
	return 0;
}
