#include <stdio.h>

#define grav 10
int m, h;

void energi_potensial(int a, int b, int c){	
	int ep;
	ep = a * b * c;
	printf("Energi potensial benda = %d J", ep);
}

void main(){
	printf("Masukkan massa benda (kg) : "); scanf("%d", &m);
	printf("Masukkan ketinggian benda (m) : "); scanf("%d", &h);
	energi_potensial(m, grav, h);
	printf("\n*percepatan gravitasi g = 10 m/s2");
}
