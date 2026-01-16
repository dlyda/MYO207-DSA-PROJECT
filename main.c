#include <stdio.h>

//Dilayda Akpınar
//2420161048
//https://www.btkakademi.gov.tr/portal/certificate/validate?certificateId=yjahzmVVnl


int ikili_arama(int dizi[], int BOYUT, int search, int ilk_ind, int son_ind) {
	int orta_ind = (ilk_ind + son_ind) / 2;
	
	
	if (search == dizi[orta_ind]) {
		return orta_ind;
	}
	
	else if (search > dizi[orta_ind] && (son_ind-ilk_ind) > 0 ) {
		return ikili_arama(dizi, BOYUT, search, orta_ind+1, son_ind);
	}
	
	else if (search < dizi[orta_ind] && (son_ind-ilk_ind) > 0) {
		return ikili_arama(dizi, BOYUT, search, 0, orta_ind-1);
	}
	
	else {
		return -1;
	}
}



void dizi_yazdir(int dizi[],int n){
	printf("DIZI: \n");
	int i;
	for(i=0;i<n;i++){
		printf("%d ",dizi[i]);
	}
	printf("\n");
}

void takas(int *ap,int *bp){
	
	int gecici=*ap;
	*ap=*bp;
	*bp=gecici;
	
	
}

int max_hesap(int dizi[],int n,int bas){
	int i;
	int max_eleman=dizi[bas];
	int max_ind=bas;
	
	for(i=bas+1;i<n;i++){
		if(dizi[i]>max_eleman){
			max_eleman=dizi[i];
			max_ind=i;
		}
	}
	return max_ind;
}




void secmeli_siralama(int dizi[],int n){
	int i,max;
	
	for(i=0;i<n;i++){
		max=max_hesap(dizi,n,i);
		takas(dizi+i,dizi+max);
	
		printf("iter.%2d: \n",i+1);
		dizi_yazdir(dizi,n);
	}

		
		
	}






int main(){
	int aranan,sonuc;
	int dizi[]={24,34,12,11,6,8,55};
	int BOYUT = sizeof(dizi) / sizeof(dizi[0]);	
	printf("Siralama Öncesi: \n");
	dizi_yazdir(dizi,BOYUT);
	printf("Aramak istediginiz deger: ");
	scanf("%d", &aranan);
	
	
	
	sonuc = ikili_arama(dizi, BOYUT, aranan, 0, BOYUT-1);
	
	if (sonuc == -1) {
		printf("Aradiginiz deger %d, dizide bulunamadi!\n", aranan);
	}
	else {
		printf("Aradiginiz deger %d, dizinin %d. indisinde bulundu!\n", aranan, sonuc);
	}
		
	

	secmeli_siralama(dizi,BOYUT);
	printf("Siralama Sonrasi: \n");
	 dizi_yazdir(dizi,BOYUT);
	 return 0;
}