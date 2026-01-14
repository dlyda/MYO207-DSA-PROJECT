#include <stdio.h>
#define BOYUT 7
//Dilayda Akpınar
//2420161048
//
https://www.btkakademi.gov.tr/portal/certificate/validate?certificateId=yjahzmVVnl


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
	
	int dizi[BOYUT]={24,34,12,11,6,8,55};
	
	
	printf("Siralama Öncesi: \n");
	dizi_yazdir(dizi,BOYUT);
	secmeli_siralama(dizi,BOYUT);
	printf("Siralama Sonrasi: \n");
	 dizi_yazdir(dizi,BOYUT);
	 return 0;
}