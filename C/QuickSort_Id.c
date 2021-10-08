#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

/*
	PERTITIONING
	Elemen terakhir dalam list dijadikan pivot
	Elemen dengan nilai lebih kecil dari pivot di swap ke bagian kiri pivot
	Elemen dengan nilai lebih besar dari pivot di swap ke bagian kanan pivot
*/
int partition(int *bil, int l, int r){
	// Menjadikan elemen terakhir list sebagai pivot
	int pivot = bil[r];
	// Tembok yang menjadi pemisah partisi kiri dan kanan
	// Pertama diletakkan di kiri elemen pertama
	int i = l - 1; 
	
	// Looping dari elemen paling kiri hingga elemen sebelum pivot
	for(int j=l; j<=r-1; j++){
		// Jika elemen lebih kecil sama dengan pivot
		if (bil[j] <= pivot){
			// Geser tembok
			i++;
			// Sekarang bil[i] = elemen paling kanan di partisi kiri
			// bil[i] belum tentu lebih kecil dari pvot
			
			// Tukar bil[i] dengan bil[j] yang sudah di cek
			swap(&bil[i], &bil[j]);
		}
	}
	
	// Tukar elemen paling kiri partisi kanan dengan pivot
	swap(&bil[i+1], &bil[r]);
	
	// Mengembalikan index dari pivot yang sudah benar
	return (i+1);	
}

void quickSort(int *bil, int l, int r){
	if(l<r){
		// pi adalah partitioning index
		int pi = partition(bil, l, r);
		// Setelah fungsi dijalankan
		// bil[pi] (sebelum pivot) sudah berada pada posisi yang benar
		
		// Setelah terpisah dan rekursif
		// Lakukan quickSort untuk tiap partisi kiri dan kanan
		quickSort(bil, l, pi-1);
		quickSort(bil, pi+1, r);
	}
}

int main(){
	int i, n, *bil;
	
	printf("Banyak bilangan: "); scanf("%d", &n);
	bil = malloc(sizeof(int) * n);
	
	for(i=0; i<n; i++){
		printf("Input bilangan ke-%d: ", i+1); scanf("%d", &bil[i]);
	}
	
	quickSort(bil, 0, n-1);
	
	printf("Hasil quick sort:\n");
	for(i=0; i<n; i++){
		printf("%d ", bil[i]);
	}
	
	free(bil);
	
	return 0;
}
