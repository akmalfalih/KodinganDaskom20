#include<stdio.h>

struct mahasiswa{
	char nama[100], nim[20], jrsn[100];
};

int main(){
	int i, n;
	struct mahasiswa a[100];
	
	printf("Jumlah mahasiswa : "); scanf("%d", &n);
	
	for (i = 0; i <= n-1; i++){
		printf("- Mahasiswa ke-%d\n", i+1);
		printf("Nama \t: "); fflush(stdin); gets(a[i].nama);
		printf("NIM \t: "); gets(a[i].nim);
		printf("Jurusan : "); gets(a[i].jrsn);
		printf("\n");
	}
	
	printf("\nDaftar mahasiswa yang ikut responsi :\n");
	for (i = 0; i <= n-1; i++){
		printf("%d. %s (%s) Jurusan %s\n", i+1, a[i].nama, a[i].nim, a[i].jrsn);
	}
	return 0;
}
