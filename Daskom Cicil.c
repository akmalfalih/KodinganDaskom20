#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Deklarasi Variabel Global
int i, j, n, cicilan, answer, answer1, x = 3;
int no_struct;
long int offset_byte;
char konfirmasi[90], answer2[50], masuk[50];
char answer3;
char cari[50];

/*
input opsi
lihat barang
menu user
*/


// Deklarasi File
FILE *daftar;
FILE *daftar2;
FILE *input_admin;
FILE *input_admin2;
FILE *konfirm;
FILE *hapus;
FILE *hapus2;

// Deklarasi Struct
struct akun{
	char uname[20], pass[10];
};

struct{
	char nama[25], nik[15], ttl[20], barang[50], tempat[50], npwp[20], hp[15];
	int dp, iuran;
} user, acc, a[50], temp;

struct{
	char nama[50];
	int dp, iuran;
} cicil;

struct{
	int harga;
	char nama[50];
} barang;

// Deklarasi Prosedur Admin
void login_admin(); //sudah
void menu_admin(); //sudah
void input_barang(); //sudah
void input_opsi();
void lihat_barang();
void penyetujuan(); //sudah
void hapus_data(); //sudah
void lihat_data();

// Deklarasi Prosedur User
void user_main(); 
void regis_user();
void login_user(); //sudah
void user_menu();
void pendaftaran();
void pilihan_barang(); //sudah
void pilihan_tempat();
void stat_konfirm(); //sudah



						/* Fungsi Utama */
int main(){ //sudah
	answer1 = 0;
	system("cls");
	printf("\t\t    DDDDDDDD	CCCCCCCC  IIIIIII  LLLL\n");
	printf("\t\t    DDDDDDDDD	CCCCCCCC    III    LLLL\n");
	printf("\t\t    DDD    DDD	CCC\t    III    LLLL\n");
	printf("\t\t    DDD     DDD	CCC\t    III    LLLL\n");
	printf("\t\t    DDD    DDD	CCC\t    III    LLLL\n");
	printf("\t\t    DDDDDDDDD	CCCCCCCC    III    LLLLLLLLL\n");
	printf("\t\t    DDDDDDDD	CCCCCCCC  IIIIIII  LLLLLLLLL\n\n");
	printf("\t\t=======Selamat Datang di Halaman Utama=======\n\n");
	printf("Siapa Anda?\n");
	printf("\t1. Admin\n");
	printf("\t2. User\n");
	printf("Pilihan : "); scanf("%d", &answer1); fflush(stdin);
	switch(answer1){
		case 1	: login_admin(); break;
		case 2	: user_main(); break;
		default : printf("Pilihan tidak ada\nSilahkan ulangi...");
				  main(); break;
	}
	
	system("cls");
	printf("\n\t\t\t****Program Telah Berakhir**");
	printf("\n\t\t****Terima Kasih Sudah Memakai Jasa Kami****");
	
	getch();
	return 0; // Akhir Program
}

						/* Halaman Login Admin */
void login_admin(){
	int val, i = 0, n = 0, j = 3;
	char logname[20], logpass[10];
	struct akun login[10], regis;
	
	system("cls");
	printf("\t\t    DDDDDDDD	CCCCCCCC  IIIIIII  LLLL\n");
	printf("\t\t    DDDDDDDDD	CCCCCCCC    III    LLLL\n");
	printf("\t\t    DDD    DDD	CCC\t    III    LLLL\n");
	printf("\t\t    DDD     DDD	CCC\t    III    LLLL\n");
	printf("\t\t    DDD    DDD	CCC\t    III    LLLL\n");
	printf("\t\t    DDDDDDDDD	CCCCCCCC    III    LLLLLLLLL\n");
	printf("\t\t    DDDDDDDD	CCCCCCCC  IIIIIII  LLLLLLLLL\n\n");
	printf("\t\t=======Selamat Datang di Halaman Login Admin!!=======\n\n");
	printf("Anda memiliki %d kali kesempatan\n", x);
	printf("Username : "); gets(logname);
	printf("Password : "); gets(logpass);

	if((strcmp(logname, "daskom") == 0) && (strcmp(logpass, "123") == 0)){
		val = 1;
	}
	
	char answer3;
	if(x >= 1){
		if(val == 1){																// Login berhasil
			printf("\nAnda berhasil login!\n"); x = 3; system("pause"); menu_admin();
		} else {																	// Uname || pass salah
			printf("\nUsername atau Password yang Anda masukkan salah\n");
			x--;
			getch(); login_admin();													// rekursif login admin
		}
	} else {																		// Kesempatan habis
		printf("\nMaaf, Kesempatan Anda sudah habis");
	}
}

						/* Halaman Menu Admin */
void menu_admin(){
	system("cls");
	char adm;
	printf("\t\t    DDDDDDDD	CCCCCCCC  IIIIIII  LLLL\n");
	printf("\t\t    DDDDDDDDD	CCCCCCCC    III    LLLL\n");
	printf("\t\t    DDD    DDD	CCC\t    III    LLLL\n");
	printf("\t\t    DDD     DDD	CCC\t    III    LLLL\n");
	printf("\t\t    DDD    DDD	CCC\t    III    LLLL\n");
	printf("\t\t    DDDDDDDDD	CCCCCCCC    III    LLLLLLLLL\n");
	printf("\t\t    DDDDDDDD	CCCCCCCC  IIIIIII  LLLLLLLLL\n\n");
	printf("\t\t\t=======MENU ADMIN=======\n\n");
	printf("Menu :");
	printf("\t1. Input Barang\n");
	printf("\t2. Input Opsi cicil\n");
	printf("\t3. Penyetujuan\n");
	printf("\t4. Lihat Barang\n");
	printf("\t5. Hapus Data Pendaftaran User\n");
	printf("\t6. Lihat Data User yang Telah Disetujui\n");
	printf("\t7. Logout\n");
	printf("\t8. Exit\n");
	printf("\nPilihan : "); scanf("%d", &adm); fflush(stdin);
	switch(adm){
		case 1	: input_barang(); break;
		case 2	: input_opsi(); break;
		case 3	: penyetujuan(); break;
		case 4	: lihat_barang(); break;
		case 5	: hapus_data(); break;
		case 6	: lihat_data(); break;
		case 7	: main(); break;
		case 8	: break;
		default : printf("Silahkan Ulangi..."); menu_admin();
	}
}

						/* Halaman Input Barang */
void input_barang(){
	answer = 0;
	system("cls");
	printf("\t\t    DDDDDDDD	CCCCCCCC  IIIIIII  LLLL\n");
	printf("\t\t    DDDDDDDDD	CCCCCCCC    III    LLLL\n");
	printf("\t\t    DDD    DDD	CCC\t    III    LLLL\n");
	printf("\t\t    DDD     DDD	CCC\t    III    LLLL\n");
	printf("\t\t    DDD    DDD	CCC\t    III    LLLL\n");
	printf("\t\t    DDDDDDDDD	CCCCCCCC    III    LLLLLLLLL\n");
	printf("\t\t    DDDDDDDD	CCCCCCCC  IIIIIII  LLLLLLLLL\n\n");
	printf("\t\t=======Halaman Input Barang & Harga=======\n\n");
	printf("Masukkan Jumlah Barang : "); scanf("%d", &answer); fflush(stdin);
	printf("\n");
	input_admin = fopen("input_barang.dat","ab");
	for(i = 0; i < answer; i++){
		printf("\nBarang Ke-%d : ", i+1); gets(barang.nama);
		printf("Harga Barang : "); scanf("%d", &barang.harga); fflush(stdin);
		fwrite(&barang, sizeof(barang), 1, input_admin);
	}
	fclose(input_admin); system("pause"); menu_admin();
}

						/* Halaman Input Opsi Cicilan */
void input_opsi(){
	answer = 0;
	system("cls");
	printf("\t\t    DDDDDDDD	CCCCCCCC  IIIIIII  LLLL\n");
	printf("\t\t    DDDDDDDDD	CCCCCCCC    III    LLLL\n");
	printf("\t\t    DDD    DDD	CCC\t    III    LLLL\n");
	printf("\t\t    DDD     DDD	CCC\t    III    LLLL\n");
	printf("\t\t    DDD    DDD	CCC\t    III    LLLL\n");
	printf("\t\t    DDDDDDDDD	CCCCCCCC    III    LLLLLLLLL\n");
	printf("\t\t    DDDDDDDD	CCCCCCCC  IIIIIII  LLLLLLLLL\n\n");
	printf("\t\t=======Halaman Input Opsi Cicilan=======\n\n");
	printf("\tData barang\n");
	input_admin = fopen("input_barang.dat","rb");
	i = 1;
	while(fread(&barang, sizeof(barang), 1, input_admin) == 1){
		printf("%d. Nama Barang  : %s\n", i, barang.nama);
		printf("    Harga Barang : %d\n", barang.harga);
		i++;
	}
	printf("\nMasukkan nama barang yang ingin diinput cicilannya : "); gets(answer2);
	fclose(input_admin);
	
	input_admin = fopen("input_cicil.dat","ab");
	printf("Jumlah input data : "); scanf("%d", &answer);
	for(i = 0; i < answer; i++){
		printf("%d. Opsi cash (DP) : ", i+1); scanf("%d", &cicil.dp);
		printf("    Iuran bulanan  : "); scanf("%d", &cicil.iuran);
		strcpy(cicil.nama,answer2);
		fwrite(&cicil, sizeof(cicil), 1, input_admin);
	}
	printf("Data cicilan sudah disimpan\n");

	fclose(input_admin);
	system("pause"); menu_admin();
}

						/* Halaman Lihat List Barang dan Harga */
void lihat_barang(){
	answer = 0;
	i = 1;
	system("cls");
	printf("\t\t    DDDDDDDD	CCCCCCCC  IIIIIII  LLLL\n");
	printf("\t\t    DDDDDDDDD	CCCCCCCC    III    LLLL\n");
	printf("\t\t    DDD    DDD	CCC\t    III    LLLL\n");
	printf("\t\t    DDD     DDD	CCC\t    III    LLLL\n");
	printf("\t\t    DDD    DDD	CCC\t    III    LLLL\n");
	printf("\t\t    DDDDDDDDD	CCCCCCCC    III    LLLLLLLLL\n");
	printf("\t\t    DDDDDDDD	CCCCCCCC  IIIIIII  LLLLLLLLL\n\n");
	printf("\t\t\t=======List Barang & Harga=======\n\n");
	input_admin = fopen("input_barang.dat","rb");
	while(fread(&barang, sizeof(barang), 1, input_admin) == 1){
		printf("Barang Ke-%d : %s dengan harga %d\n", i, barang.nama, barang.harga);
		i++;
	}
	fclose(input_admin);
	printf("\nTekan 1 untuk hapus barang atau tekan sembarang untuk kembali ke menu\n"); scanf("%d", &answer); fflush(stdin);
	if(answer == 1){
		input_admin = fopen("input_barang.dat","rb");
		hapus = fopen("hapus.dat","wb");
		printf("\nMasukkan nama barang yang ingin dihapus : "); gets(answer2);
		while(fread(&cicil, sizeof(cicil), 1, input_admin) == 1){
			if(strcmp(barang.nama, answer2) != 0){
				fwrite(&cicil, sizeof(cicil), 1, hapus);
			}
		}
		fclose(input_admin); fclose(hapus);
		remove("input_barang.dat"); rename("hapus.dat","input_barang.dat");
		printf("\nData berhasil dihapus!\n");
	}
	else{
		printf("\nAnda akan dialihkan ke halaman menu admin\n");
	}
	system("pause"); menu_admin();
}

						/* Halaman Penyetujuan Pengajuan Cicilan */
void penyetujuan(){
	system("cls");
	printf("\t\t    DDDDDDDD	CCCCCCCC  IIIIIII  LLLL\n");
	printf("\t\t    DDDDDDDDD	CCCCCCCC    III    LLLL\n");
	printf("\t\t    DDD    DDD	CCC\t    III    LLLL\n");
	printf("\t\t    DDD     DDD	CCC\t    III    LLLL\n");
	printf("\t\t    DDD    DDD	CCC\t    III    LLLL\n");
	printf("\t\t    DDDDDDDDD	CCCCCCCC    III    LLLLLLLLL\n");
	printf("\t\t    DDDDDDDD	CCCCCCCC  IIIIIII  LLLLLLLLL\n\n");
	printf("\t\t =======Halaman Penyetujuan Pendaftaran User=======\n\n");
	daftar = fopen("data pendaftar.dat", "rb");
	printf("\t\tHalaman penyetujuan\n\n");
	i = 1;
	while(fread(&user, sizeof(user), 1, daftar) == 1){
		printf("\n%d. Nama    : %s", i, user.nama);
		printf("\n    NIK    : %s\n", user.nik);
		i++;
	}
	fclose(daftar);
	//copy ke penyetujuan
	konfirm = fopen("penyetujuan.dat", "ab");
	daftar = fopen("data pendaftar.dat", "rb");
	printf("\nPilih nama : "); gets(cari);
	while(fread(&user, sizeof(user), 1, daftar)==1){
		if(strcmp(cari,user.nama)==0){
			fseek(daftar, -sizeof(user), SEEK_CUR);
			acc=user;
			fwrite(&acc, sizeof(acc), 1, konfirm);
			break;
		}
	}
	fclose(konfirm);
	fclose(daftar);
	
	daftar = fopen("data pendaftar.dat", "rb");
	daftar2 = fopen("data pendaftar2.dat", "wb");

	while(fread(&user, sizeof(user), 1, daftar) == 1){
		if(strcmp(user.nama, cari) != 0){
			fwrite(&user, sizeof(user), 1, daftar2);
		}
	}
	 fclose(daftar); fclose(daftar2);
	remove("data pendaftar.dat"); rename("data pendaftar2.dat", "data pendaftar.dat");
	system("pause"); menu_admin();
	}

						/* Halaman Menghapus Data Pendaftaran User */
void hapus_data(){
	system("cls");
	i = 1;
	printf("\t\t    DDDDDDDD	CCCCCCCC  IIIIIII  LLLL\n");
	printf("\t\t    DDDDDDDDD	CCCCCCCC    III    LLLL\n");
	printf("\t\t    DDD    DDD	CCC\t    III    LLLL\n");
	printf("\t\t    DDD     DDD	CCC\t    III    LLLL\n");
	printf("\t\t    DDD    DDD	CCC\t    III    LLLL\n");
	printf("\t\t    DDDDDDDDD	CCCCCCCC    III    LLLLLLLLL\n");
	printf("\t\t    DDDDDDDD	CCCCCCCC  IIIIIII  LLLLLLLLL\n\n");
	printf("\t\t =======Hapus Data Pendaftaran User=======\n");
	daftar=fopen("data pendaftar.dat","rb");
	while(fread(&user,sizeof(user),1,daftar)==1){
		printf("%d. %s\n", i, user.nama);
		i++;
	}
	fclose(daftar);
	
	daftar=fopen("data pendaftar.dat","rb");
	hapus2=fopen("data pendaftar2.dat","wb");
	printf("\nINPUT\n");
	printf("Masukan nama yang ingin dihapus datanya : "); gets(cari);
	while(fread(&user,sizeof(user),1,daftar)==1){
		if(strcmp(user.nama,cari)!=0){
			fwrite(&user,sizeof(user),1,hapus2);
		}
	}
	fclose(daftar); fclose(hapus2);
	remove("data pendaftar.dat");rename("data pendaftar2.dat","data pendaftar.dat");
	printf("\nProses hapus data pendfataran user berhasil!\n");
	system("pause"); menu_admin();
}

						/* Halaman Lihat Data Pengajuan yang Telah Disetujui */
void lihat_data(){
	n = 0;
	system("cls");
	printf("\t\t    DDDDDDDD	CCCCCCCC  IIIIIII  LLLL\n");
	printf("\t\t    DDDDDDDDD	CCCCCCCC    III    LLLL\n");
	printf("\t\t    DDD    DDD	CCC\t    III    LLLL\n");
	printf("\t\t    DDD     DDD	CCC\t    III    LLLL\n");
	printf("\t\t    DDD    DDD	CCC\t    III    LLLL\n");
	printf("\t\t    DDDDDDDDD	CCCCCCCC    III    LLLLLLLLL\n");
	printf("\t\t    DDDDDDDD	CCCCCCCC  IIIIIII  LLLLLLLLL\n\n");
	printf("\t\t =======Data Pengajuan yang Diterima=======\n");
	konfirm=fopen("penyetujuan.dat","rb"); 
		while(fread(&acc,sizeof(acc),1,konfirm)==1){
			a[n] = acc;
			n++;
		}
	fclose(konfirm);
	
	// Sorting berdasarkan nama
	for (i = n-1; i >= 1; i--){
		for (j = 1; j <= i; j++){
			if (strcmp(a[j-1].nama, a[j].nama) > 0){
				temp   = a[j-1];
				a[j-1] = a[j];
				a[j]   = temp;
			}
		}
	}

	
	for(i = 0; i < n; i++){
		printf("\n%d. Nama        : %s", i+1, a[i].nama);
		printf("\n   No. KTP     : %s", a[i].nik);
		printf("\n   No. NPWP    : %s", a[i].npwp);
		printf("\n   TTL         : %s", a[i].ttl);
		printf("\n   No. HP      : %s", a[i].hp);
		printf("\n   Tempat      : %s", a[i].tempat);
		printf("\n   Barang      : %s", a[i].barang);
		printf("\n   DP          : %d", a[i].dp);
		printf("\n   Iuran (12x) : %d\n", a[i].iuran);
	}
	system("pause"); menu_admin();
}

						/* Halaman Awal Admin */
void user_main(){
	system("cls");
	printf("\t\t    DDDDDDDD	CCCCCCCC  IIIIIII  LLLL\n");
	printf("\t\t    DDDDDDDDD	CCCCCCCC    III    LLLL\n");
	printf("\t\t    DDD    DDD	CCC\t    III    LLLL\n");
	printf("\t\t    DDD     DDD	CCC\t    III    LLLL\n");
	printf("\t\t    DDD    DDD	CCC\t    III    LLLL\n");
	printf("\t\t    DDDDDDDDD	CCCCCCCC    III    LLLLLLLLL\n");
	printf("\t\t    DDDDDDDD	CCCCCCCC  IIIIIII  LLLLLLLLL\n\n");
	printf("\t\t\t=======Halaman Utama user=======\n\n");
	printf("Apakah Anda sudah punya akun? (y/t)"); scanf("%c", &answer3); fflush(stdin);
	if(answer3 == 't' ){
		regis_user();
	} else if (answer3 == 'y' ){
		login_user();
	} else {
		printf("Pilihan tidak ada\nSilahkan ulangi!"); main();
	}
}

						/* Halaman Registrasi Akun User */
void regis_user(){
	struct akun regis;
	FILE *f_akun;
	f_akun = fopen("akun_user.dat", "ab");
	
	system("cls");
	printf("\t\t    DDDDDDDD	CCCCCCCC  IIIIIII  LLLL\n");
	printf("\t\t    DDDDDDDDD	CCCCCCCC    III    LLLL\n");
	printf("\t\t    DDD    DDD	CCC\t    III    LLLL\n");
	printf("\t\t    DDD     DDD	CCC\t    III    LLLL\n");
	printf("\t\t    DDD    DDD	CCC\t    III    LLLL\n");
	printf("\t\t    DDDDDDDDD	CCCCCCCC    III    LLLLLLLLL\n");
	printf("\t\t    DDDDDDDD	CCCCCCCC  IIIIIII  LLLLLLLLL\n\n");
	printf("\t\t =======Selamat Datang di Halaman Registrasi User!!=======\n\n");
	printf("Username : "); gets(regis.uname);
	printf("Password : "); gets(regis.pass);
	
	fwrite(&regis, sizeof(regis), 1, f_akun);
	fclose(f_akun);
	
	printf("\nSilahkan Login dengan Akun Anda!");
	getch();
	login_user();
}

						/* Halaman Login User */
void login_user(){
	int val, i = 0, n = 0, j = 3;
	char logname[20], logpass[10];
	struct akun login[10], regis;
	FILE *f_akun;
	f_akun = fopen("akun_user.dat", "rb");
	
	while(fread(&regis, sizeof(regis), 1, f_akun) == 1){
		strcpy(login[i].uname, regis.uname);						// mengambil string pada struct regis user
		strcpy(login[i].pass, regis.pass);							// agar dapat dibandingkan dengan struct login user
		i++;
		n++;
	}
	
	system("cls");
	printf("\t\t    DDDDDDDD	CCCCCCCC  IIIIIII  LLLL\n");
	printf("\t\t    DDDDDDDDD	CCCCCCCC    III    LLLL\n");
	printf("\t\t    DDD    DDD	CCC\t    III    LLLL\n");
	printf("\t\t    DDD     DDD	CCC\t    III    LLLL\n");
	printf("\t\t    DDD    DDD	CCC\t    III    LLLL\n");
	printf("\t\t    DDDDDDDDD	CCCCCCCC    III    LLLLLLLLL\n");
	printf("\t\t    DDDDDDDD	CCCCCCCC  IIIIIII  LLLLLLLLL\n\n");
	printf("\t\t =======Selamat Datang di Halaman Login User!!=======\n\n");
	printf("Anda memiliki %d kali kesempatan\n", x);
	printf("Username : "); gets(logname);
	printf("Password : "); gets(logpass);
	
	for(i = 0; i < n; i++){
		if((strcmp(logname, login[i].uname) == 0) && (strcmp(logpass, login[i].pass) == 0)){
			val = 1;
		}
	}
	
	if(x >= 1){
		if(val == 1){
			printf("\nAnda berhasil login!\n"); x = 3; system("pause"); user_menu();
		} else {
			printf("\nUsername atau Password yang Anda masukkan salah\n");
			x--;
			getch(); login_user();
		}
	} else {
		printf("\nMaaf, Kesempatan Anda sudah habis");
		printf("\n\nSilakan registrasi akun Anda jika belum melakukan registrasi...");
		printf("\nTekan 'y' untuk registrasi atau tekan sembarang untuk mengakhiri program\n"); scanf("%c", &answer3); fflush(stdin);
		if(x <= 1) x = 3;  // mengembalikan nilai x = 3 setelah perulangan berakhir
		if(answer3 == 'y') regis_user();
	}
	fclose(f_akun);
}

						/* Halaman Menu User */
void user_menu(){
	answer = 0;
	system("cls");
	printf("\t\t    DDDDDDDD	CCCCCCCC  IIIIIII  LLLL\n");
	printf("\t\t    DDDDDDDDD	CCCCCCCC    III    LLLL\n");
	printf("\t\t    DDD    DDD	CCC\t    III    LLLL\n");
	printf("\t\t    DDD     DDD	CCC\t    III    LLLL\n");
	printf("\t\t    DDD    DDD	CCC\t    III    LLLL\n");
	printf("\t\t    DDDDDDDDD	CCCCCCCC    III    LLLLLLLLL\n");
	printf("\t\t    DDDDDDDD	CCCCCCCC  IIIIIII  LLLLLLLLL\n\n");
	printf("\t\t\t=======Halaman Utama User=======\n\n");
	printf("Menu :");
	printf("\t1. Pendaftaran\n");
	printf("\t2. Daftar pilihan barang\n");
	printf("\t3. Daftar tempat pengambilan barang\n");
	printf("\t4. Status konfirmasi\n");
	printf("\t5. Logout\n");
	printf("\t6. Exit\n");
	printf("\nPilihan : "); scanf("%d", &answer); fflush(stdin);
	switch(answer){
		case 1	: pendaftaran(); break;
		case 2	: pilihan_barang(); break;
		case 3	: pilihan_tempat(); break;
		case 4	: stat_konfirm(); break;
		case 5	: main(); break;
		case 6	: break;
		default : printf("\nSilahkan ulangi..."); getch(); user_main(); break;
	}
}

						/* Halaman Pendaftaran Cicilan User */
void pendaftaran(){
	answer = 0;
	system("cls");
	printf("\t\t    DDDDDDDD	CCCCCCCC  IIIIIII  LLLL\n");
	printf("\t\t    DDDDDDDDD	CCCCCCCC    III    LLLL\n");
	printf("\t\t    DDD    DDD	CCC\t    III    LLLL\n");
	printf("\t\t    DDD     DDD	CCC\t    III    LLLL\n");
	printf("\t\t    DDD    DDD	CCC\t    III    LLLL\n");
	printf("\t\t    DDDDDDDDD	CCCCCCCC    III    LLLLLLLLL\n");
	printf("\t\t    DDDDDDDD	CCCCCCCC  IIIIIII  LLLLLLLLL\n\n");
	printf("\t\t\t=======Halaman Pendaftaran=======\n\n");
	printf("Silahkan lengkapi data diri Anda\n");
	
	FILE *daftar;
	daftar = fopen("data pendaftar.dat", "ab");
	printf("Nama     : "); gets(user.nama);
	printf("No. KTP  : "); gets(user.nik);
	printf("No. NPWP : "); gets(user.npwp);
	printf("TTL      : "); gets(user.ttl);
	printf("No. HP   : "); gets(user.hp);
	printf("Tempat pengambilan barang (TOKO A / TOKO B / TOKO C)= "); gets(user.tempat);
	
	printf("\nPilih barang dan cicilan :\n");
	input_admin = fopen("input_barang.dat","rb");
	i = 1;
	while(fread(&barang, sizeof(barang), 1, input_admin) == 1){
		printf("%d. Nama barang  : %s", i, barang.nama);
		printf("    Harga barang : %d\n", barang.harga);
		i++;
	}
	fclose(input_admin);
	
	printf("\nMasukkan nama barang yang ingin dicicil = "); gets(user.barang);
	input_admin2 = fopen("input_cicil.dat","rb");
	i = 1;
	while(fread(&cicil, sizeof(cicil), 1, input_admin2) == 1){
		if(strcmp(cicil.nama, user.barang)==0){
			printf("%d. DP    : %d", i, cicil.dp);
			printf("    Iuran : %d\n", cicil.iuran);
			i++;
		}
	}
	fclose(input_admin2);
	
	printf("\n\n=======Masukkan pilihan cicilan=======");
	printf("\nOpsi DP          : "); scanf("%d", &user.dp); fflush(stdin);
	printf("Opsi iuran (x12) : "); scanf("%d", &user.iuran);
	if(fwrite(&user, sizeof(user), 1, daftar) == 1){
		printf("\nData telah tersimpan!\n");
	}
	fclose(daftar); system("pause"); user_menu();
}

						/* Halaman Lihat List Barang & Harga User */
void pilihan_barang(){
	i = 1;
	system("cls");
	printf("\t\t    DDDDDDDD	CCCCCCCC  IIIIIII  LLLL\n");
	printf("\t\t    DDDDDDDDD	CCCCCCCC    III    LLLL\n");
	printf("\t\t    DDD    DDD	CCC\t    III    LLLL\n");
	printf("\t\t    DDD     DDD	CCC\t    III    LLLL\n");
	printf("\t\t    DDD    DDD	CCC\t    III    LLLL\n");
	printf("\t\t    DDDDDDDDD	CCCCCCCC    III    LLLLLLLLL\n");
	printf("\t\t    DDDDDDDD	CCCCCCCC  IIIIIII  LLLLLLLLL\n\n");
	printf("\t\t\t=======List Barang & Harga=======\n\n");
	input_admin = fopen("input_barang.dat","rb");
	while(fread(&barang, sizeof(barang), 1, input_admin) == 1){
		printf("Barang Ke-%d = %s dengan harga %d\n", i, barang.nama, barang.harga);
		i++;
	}
	fclose(input_admin); system("pause"); user_menu();
}

						/* Halaman Lihat Tempat Pengambilan */
void pilihan_tempat(){
	system("cls");
	printf("\t\t    DDDDDDDD	CCCCCCCC  IIIIIII  LLLL\n");
	printf("\t\t    DDDDDDDDD	CCCCCCCC    III    LLLL\n");
	printf("\t\t    DDD    DDD	CCC\t    III    LLLL\n");
	printf("\t\t    DDD     DDD	CCC\t    III    LLLL\n");
	printf("\t\t    DDD    DDD	CCC\t    III    LLLL\n");
	printf("\t\t    DDDDDDDDD	CCCCCCCC    III    LLLLLLLLL\n");
	printf("\t\t    DDDDDDDD	CCCCCCCC  IIIIIII  LLLLLLLLL\n\n");
	printf("\t\t\t=======List Tempat Pengambilan=======\n\n");
	printf("\n\nPilihan tempat\n1. TOKO A\n2. TOKO B\n3. TOKO C\n");
	system("pause"); user_menu();
}

						/* Halaman Registrasi Akun User */
void stat_konfirm(){
	system("cls");
	int stat1 = 0, stat2 = 0;
	printf("\t\t    DDDDDDDD	CCCCCCCC  IIIIIII  LLLL\n");
	printf("\t\t    DDDDDDDDD	CCCCCCCC    III    LLLL\n");
	printf("\t\t    DDD    DDD	CCC\t    III    LLLL\n");
	printf("\t\t    DDD     DDD	CCC\t    III    LLLL\n");
	printf("\t\t    DDD    DDD	CCC\t    III    LLLL\n");
	printf("\t\t    DDDDDDDDD	CCCCCCCC    III    LLLLLLLLL\n");
	printf("\t\t    DDDDDDDD	CCCCCCCC  IIIIIII  LLLLLLLLL\n\n");
	printf("\t\t\t=======Status Konfirmasi=======\n\n");
	daftar = fopen("data pendaftar.dat", "rb");
	printf("\nNama yang ingin Anda lihat statusnya : "); gets(answer2);
	while((fread(&user, sizeof(user), 1, daftar)) == 1){
		if((strcmp(answer2, user.nama)) == 0){
			printf("\nSilahkan tunggu persetujuan admin\n");
			stat1 = 1;
		}
	}
	fclose(daftar);
	
	konfirm = fopen("penyetujuan.dat", "rb");
	while(fread(&acc, sizeof(acc), 1, konfirm) == 1){
		if((strcmp(answer2, acc.nama)) == 0){
			printf("\nSelamat %s!! Pengajuan Anda sudah disetujui Admin\n", acc.nama);
			stat2 = 1;
		}
	}
	fclose(konfirm);
	if((stat1 == 0) && (stat2 == 0)){
		printf("\nMaaf...");
		printf("\nPengajuan cicilan atas nama %s tidak disetujui Admin atau belum terdaftar", answer2);
		printf("\nSilahkan buat pengajuan cicilan lagi...\n");
	}
	system("pause");
	user_menu();
}
