#include <stdio.h>
#include <string.h>

struct data{
	char nik[10], nama[25], ttl[20];
};

int main(){
	FILE *f_ktp;
	FILE *f_ktp2;
	int i;
	char cari[25];
	struct data input;
	
	f_ktp = fopen("Data_Penduduk.dat", "rb");
	/*f_ktp2 = fopen("Data_Penduduk2.dat", "wb");
	
	printf("======INPUT======\n\n");
	printf("Silahkan masukkan menu yang ingin Anda hapus : "); gets(cari);
	while (fread(&input, sizeof(input), 1, f_ktp) == 1){
		if (strcmp(input.nama, cari) != 0){
			fwrite(&input, sizeof(input), 1, f_ktp2);
		}
	}
	fclose(f_ktp);
	fclose(f_ktp2);
	remove("Data_Penduduk.dat");
	rename("Data_Penduduk2.dat", "Data_Penduduk.dat"); */
	
	printf("\n\n=======OUTPUT=======\n");

	f_ktp = fopen("Data_Penduduk.dat", "rb");
	i = 0;
	while(fread(&input, sizeof(input), 1, f_ktp) == 1){
		printf("\n- Data penduduk %d", i+1);
		printf("\nNIK\t: %s", input.nik);
		printf("\nNama\t: %s", input.nama);
		printf("\nTTL\t: %s\n", input.ttl);
		i++;
	}
	
	fclose(f_ktp);
	getch();
}
