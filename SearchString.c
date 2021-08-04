#include <stdio.h>
#include <string.h>

struct data{
	char minuman[50];
};

int main(){
	int i, n;
	char cari[50];
	// Input
	printf("Banyak minuman : "); scanf("%d", &n); getchar();
	struct data a[n];
	
	for(i = 0; i < n; i++){
		printf("Minuman di gelas %d : ", i+1); gets(a[i].minuman);
	}
	printf("\nMinuman yang ingin dicari : "); gets(cari);
	
	// Sequential Search
	i = 0;
	while((i < n) && (strcmp(cari, a[i].minuman) != 0)){
		i++;
	}
	
	// Output
	printf("\n\n=======Output(poin B)=======");
	if(strcmp(cari, a[i].minuman) == 0){
		printf("\n%s terdapat pada gelas %d", cari, i+1);
	} else{
		printf("\n%s tidak ditemukan", cari);
	}
}
