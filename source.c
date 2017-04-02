#include "stdio.h"
#include "stdlib.h"
#include "string.h"
struct sayuran{
char nama[10];
char jenis[10];
int banyak;
char kualitas;
int harga;
int total;
}contoh[10],temp;

int totaljen=0,jeniscch=0;
int totalsemua=0,cacahsemua=0;
int kwtotal=0,kwcacah=0;
int i,N;
float rata;

FILE *bahan;

void input_bahan()
{
printf("Masukkan Banyak Data Bahan Makanan : ");
scanf("%d",&N);
printf("\n");
for(i=0; i<N; i++){
fflush(stdin);
printf("Data bahan ke-%d\n",i+1);
fflush(stdin);
printf("Masukkan Nama bahan: ");
fgets(contoh[i].nama,10,stdin);
fflush(stdin);
printf("Masukkan Jenis Bahan Makanan: ");
fgets(contoh[i].jenis,10,stdin);
fflush(stdin);
printf("Masukkan Banyak Bahan Makanan: ");
scanf("%d",&contoh[i].banyak);
fflush(stdin);
printf("Masukkan Kualitas bahan: ");
scanf("%c",&contoh[i].kualitas); fflush(stdin);
}
}
void hit_harga()
{
for(i=0; i<=N; i++){
if(contoh[i].kualitas == 'A'){
if(strncmp(contoh[i].jenis,"sayur",5)==0){
contoh[i].harga=1500;
totaljen=totaljen+contoh[i].harga;
jeniscch=jeniscch+1;
}
else if(strncmp(contoh[i].jenis,"lain",4)==0){
contoh[i].harga=2500;
totaljen=totaljen+contoh[i].harga;
jeniscch=jeniscch+1;
}
cacahsemua=cacahsemua+contoh[i].banyak;
kwtotal=kwtotal+contoh[i].harga;
kwcacah=kwcacah+1;
}
else if(contoh[i].kualitas == 'B' ){
if(strncmp(contoh[i].jenis,"sayur",5)==0){
contoh[i].harga=1200;
totaljen=totaljen+contoh[i].harga;
jeniscch=jeniscch+1;
}
else if(strncmp(contoh[i].jenis,"lain",4)==0){
contoh[i].harga=3000;
totaljen=totaljen+contoh[i].harga;
jeniscch=jeniscch+1;
}
cacahsemua=cacahsemua+contoh[i].banyak;
kwtotal=kwtotal+contoh[i].harga;
kwcacah=kwcacah+1;
}
else if(contoh[i].kualitas == 'C' ){
if(strncmp(contoh[i].jenis,"lain",4)==0){
contoh[i].harga=500;
totaljen=totaljen+contoh[i].harga;
jeniscch=jeniscch+1;
}

}
contoh[i].total=contoh[i].banyak*contoh[i].harga;
totalsemua=totalsemua+contoh[i].total;
}
rata=(float)totalsemua/cacahsemua;
}
void output()
{
for(i=0; i<N; i++){
printf("\nData bahan ke-%d\n",i+1);
printf("Nama bahan : %s\n",contoh[i].nama);
printf("jenis bahan : %s\n",contoh[i].jenis);
printf("Banyak bahan : %d\n",contoh[i].banyak);
printf("Kualitas bahan : %c\n",contoh[i].kualitas);
printf("Harga bahan : %d\n",contoh[i].harga);
printf("Total bahan : %d\n",contoh[i].total);
}
}
void modifBubbleSort()
{
int i,pass,tukar;
pass=1; tukar=1;
while(pass<=N-1 && tukar==1){
tukar=0;
for(i=1; i<=N-pass; i++){
if(strncmp(contoh[i-1].jenis,contoh[i].jenis,5)>0){
temp=contoh[i];
contoh[i]=contoh[i-1];
contoh[i-1]=temp;
tukar=1;
    }
}
pass=pass+1;
}
}
void SelectionSort()
{
int i,pass;
N=5;
for (pass = 0; pass < N; ++pass){
for (i = pass + 1; i < N; ++i){
if (contoh[pass].kualitas>contoh[i].kualitas){
temp = contoh[pass];
contoh[pass] = contoh[i];
contoh[i] = temp;
            }
        }
    }
}
void input_file()
{
bahan=fopen("dat_bahan.txt","w");
for(i=0; i<N; i++){
fwrite(&contoh[i],sizeof(contoh[i]),1,bahan);
    }
}
void baca_file()
{
bahan=fopen("dat_bahan.txt","r");
for(i=0;i<N;i++){
fread(&contoh[i],sizeof(contoh[i]),1,bahan);
    }
}
int main()
{
input_bahan();
hit_harga();
output();
printf("\nRata rata bahan : %.2f\n",rata);
modifBubbleSort();
printf("\nurutan array berdasarkan jenis menggunakan modif bubble sort");
output();
printf("\nTotal jenis bahan : %d\n",totaljen);
printf("\nCacah jenis bahan : %d\n",jeniscch);
SelectionSort();
printf("\nurutan array berdasarkan kualitas menggunakan selection sort");
output();
input_file();
baca_file();
printf("\noutput array yang disimpan di file\n");
output();
printf("\nTotal Kualitas bahan : %d\n",kwtotal);
printf("\nCacah Kualitas bahan : %d\n",kwcacah);
return 0;
}
