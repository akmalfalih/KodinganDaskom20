#include <stdio.h>
#include <string.h>
 
 struct string{
 	char strg[50];
 } temp;
 
int main(){
	int i, k, n;
    
    printf("Jumlah string : "); scanf("%d", &n); getchar();
    struct string a[n];
    for(i = 0; i < n; i++){
    	printf("String %d : ", i+1); gets(a[i].strg);
    }
     
    for(i = 0; i < n; i++){
        int j, bd;
        j = i;
        for(k = i+1; k < n ; k++){
            bd = strcmp(a[j].strg, a[k].strg);
            printf("%d\n", bd);
            if(bd == 1){
               	j = k;
			}
        }
        if(j != i){
        	temp = a[j];
        	a[j] = a[i];
        	a[i] = temp;
		}
    }
     
	printf("Hasil pengurutan : ");
    for (i = 0; i < n; i++){
        printf("%s ", a[i].strg);
    }
    getchar();
    return 0;
}
