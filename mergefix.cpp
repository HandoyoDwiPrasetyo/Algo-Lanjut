#include <iostream>
#include <string.h>
#include <fstream>

using namespace std;

typedef struct{
string nama_fasilitas;
string biaya;
}fasilitas;

typedef struct{
string nopen;
string nama;
string alamat;
string ruang;
int fasil;
fasilitas fslts[100];
}biodata;

int menu1();
int menu2();
int menu3();

void urutan(biodata bdt[], int &data);
void sequential(int &data);
void binary();
void bubble(biodata bdt[], int &data);
void selection(biodata bdt[], int &data);
void insertion(biodata bdt[], int &data);
void shell(biodata bdt[], int &data);
void merge(biodata bdt[], int l, int m, int r);
void mergeSort(biodata bdt[], int l, int r);
void quick(biodata bdt[], int awal, int akhir);
//void sambung();
void tulisdata(ofstream &data_tulis, int &data, biodata bdt[], string &hasil_sambung);
void tulisdata_urut(ofstream &data_tulis, int &data, biodata bdt[], string &hasil_urut);
void bacadata(ifstream &datamasuk, int &data, biodata bdt[], string &namafile);
string namafile, namabatas, namafasil, hasil_sambung,hasil_sambung2,hasil_sambung3, hasil_urut, hasil_urut2, hasil_urut3;

biodata bdt[100], temp;
string file;
char kembali, namafile_sambung1[20], namafile_sambung2[20], banyak_data1[20], banyak_data2[20], banyak_file1[20];
bool found;
int  data, banyakdata1, banyakdata2, pilihtransaksi, batas;
ifstream data_masuk, input, sambung_masuk1, sambung_masuk2, banyak_keluar1, banyak_keluar2 , batas_output1, batas_output2, batas_output3;
ofstream  hasil_masuk, data_tulis;
fstream dataku, output, batas_input1, batas_input3;

int main(){
	do{
	switch(menu1()){
		case 1 :
			cout<<"--------------------------------------------------";
			cout<<"\nBerapa Data Yang Ingin di Input : ";cin>>data;
			cout<<"--------------------------------------------------"<<endl;
			cout<<"Masukkan Nama File : ";cin>>namafile;
			cout<<"Masukkan Nama File Untuk Simpan Banyak Data : ";cin>>namabatas;
			cout<<"Masukkan Nama File yang untuk simpan banyak fasilitas : ";cin>>namafasil;
			dataku.open(namafile.c_str(), ios::trunc | ios::out);
			batas_input1.open(namabatas.c_str(), ios::out | ios::trunc);
			batas_input3.open(namafasil.c_str(), ios::out | ios::trunc);
			batas_input1<<data;
			for(int i=0; i<data; i++){
				cout<<"--------------------------------------------------"<<endl;
				cout<<endl<<"Masukkan No.Pendaftaran	: ";cin>>bdt[i].nopen;
				cout<<endl<<"Masukkan Nama		: ";cin.ignore();getline(cin, bdt[i].nama);
				cout<<endl<<"Masukkan Alamat 	: ";getline(cin,bdt[i].alamat);
				cout<<endl<<"Masukkan Ruang 		: ";cin>>bdt[i].ruang;
				cout<<"--------------------------------------------------"<<endl;
				cout<<"Berapa Fasilitas Kesehatan Yang Anda Butuhkan : ";cin>>bdt[i].fasil;
				cout<<"--------------------------------------------------"<<endl;
					batas_input3<<bdt[i].fasil<<endl;
					dataku<<bdt[i].nopen<<endl;
					dataku<<bdt[i].nama<<endl;
					dataku<<bdt[i].alamat<<endl;
					dataku<<bdt[i].ruang<<endl;
				cout<<"Fasilitas : ";
				for(int a=0; a<bdt[i].fasil; a++){
					cout<<endl<<a+1<<". ";cin.ignore();getline(cin,bdt[i].fslts[a].nama_fasilitas);
					cout<<" Biaya : ";cin>>bdt[i].fslts[a].biaya;
						dataku<<bdt[i].fslts[a].nama_fasilitas<<endl;
						dataku<<bdt[i].fslts[a].biaya<<endl;
				}
			}
			batas_input1.close();
			batas_input3.close();
			dataku.close();
		break;
		case 2 :	
			switch(menu2()){
				case 1 :
					bacadata(data_masuk, data, bdt, namafile);
					sequential(data);
				break;
				case 2 :
					switch(menu3()){
						case 1 :	
							cout<<"/t >> BUBBLE SORT <<"<<endl;
							bacadata(data_masuk, data, bdt, namafile);
							bubble(bdt,data);
							binary();
						break;
						case 2 :
							cout<<"/t >> SELECTION SORT <<"<<endl;
							bacadata(data_masuk, data, bdt, namafile);
							selection(bdt,data);
							binary();
						break;
						case 3 :
							cout<<"/t >> INSERTION SORT <<"<<endl;
							bacadata(data_masuk, data, bdt, namafile);
							insertion(bdt,data);
							binary();
						break;
						case 4 :
							cout<<"/t >> SHELL SORT <<"<<endl;
							bacadata(data_masuk, data, bdt, namafile);
							shell(bdt,data);
							binary();
						break;
						case 5 :
							cout<<"/t >> MERGE SORT <<"<<endl;
							bacadata(data_masuk, data, bdt, namafile);
							mergeSort(bdt, 0, data - 1); 
							urutan(bdt,data);
							binary();
						break;
						case 6 :
							cout<<"/t >> QUICK SORT <<"<<endl;
							bacadata(data_masuk, data, bdt, namafile);
							int awal = 0;
							quick(bdt, awal, data);
							urutan(bdt, data);
							binary();
						break;
					}
				break;
				case 3 :
					
				break;
			}
		break;
		case 3 :	system("cls");
			cout<<"Menu Transaksi : "<<endl;
			cout<<"1. Merging Sambung "<<endl;
			cout<<"2. Merging Urut "<<endl;
			cout<<"Pilih Transaksi : ";cin>>pilihtransaksi;
			switch(pilihtransaksi){
					case 1 :
						cout<<"Merging Sambung"<<endl;
						cout<<"Masukkan Nama file Hasil Merging Sambung : ";cin>>hasil_sambung;
						cout<<"Masukkan Nama file Hasil data Merging Sambung : ";cin>>hasil_sambung2;
						cout<<"Masukkan Nama file Hasil fasil Merging Sambung : ";cin>>hasil_sambung3;
						bacadata(data_masuk, data, bdt, namafile);
						tulisdata(data_tulis, data, bdt, hasil_sambung);
						bacadata(data_masuk, data, bdt, namafile);
						tulisdata(data_tulis, data, bdt, hasil_sambung);
					break;
					case 2 :
						cout<<"Merging Urut"<<endl;
						cout<<"Masukkan Nama file Hasil Merging Urut : ";cin>>hasil_urut;
						cout<<"Masukkan Nama file Hasil data Merging Urut : ";cin>>hasil_urut2;
						cout<<"Masukkan Nama file Hasil fasil Merging Urut : ";cin>>hasil_urut3;
						bacadata(data_masuk, data, bdt, namafile);
						tulisdata_urut(data_tulis, data, bdt, hasil_urut);
						bacadata(data_masuk, data, bdt, namafile);
						tulisdata_urut(data_tulis, data, bdt, hasil_urut);
					break;
				}
		break;
		case 4 :	system("cls");
			exit(0);
		break;
		}cout<<"\nKembali ? (y/n)";cin>>kembali;
	}while(kembali=='y'||kembali=='Y');
}


int menu1(){ system("cls");
	int pilih;
	cout<<"==========================================="<<endl;
	cout<<"|| MENU :				||"<<endl;
	cout<<"|| 1. Input Data			||"<<endl;
	cout<<"|| 2. Searching				||"<<endl;
	cout<<"|| 3. Transaksi		 		||"<<endl;
	cout<<"|| 4. Exit				||"<<endl;
	cout<<"==========================================="<<endl;
	cout<<"\nPilih Menu : ";cin>>pilih;
	return pilih;
}

int menu2(){ system("cls");
	int pilihsearch;
	cout<<"==========================================="<<endl;
	cout<<"|| Menu Searching : 			||"<<endl;
	cout<<"|| 1. Sequential Search 		||"<<endl;
	cout<<"|| 2. Binary Search 			||"<<endl;
	cout<<"|| 3. Kembali Ke Menu Utama ?		||"<<endl;
	cout<<"==========================================="<<endl;
	cout<<"\nPilih Menu : ";cin>>pilihsearch;
	return pilihsearch;
}

int menu3(){ system("cls");
	int pilihsort;
		cout<<"==========================================="<<endl;
		cout<<"|| Pilih Metode Sorting : 		||"<<endl;
		cout<<"|| 1. Bubble Sort			||"<<endl;
		cout<<"|| 2. Selection Sort			||"<<endl;
		cout<<"|| 3. Insertion sort			||"<<endl;
		cout<<"|| 4. Shell sort			||"<<endl;	
		cout<<"|| 5. Merge sort			||"<<endl;
		cout<<"|| 6. Quick Sort			||"<<endl;
		cout<<"==========================================="<<endl;
		cout<<"\nPilih Sort : ";cin>>pilihsort;
		return pilihsort;
}

void urutan(biodata bdt[], int &data){
	cout<<endl;
	cout<<"Data Yang Telah Urut : "<<endl;
	cout<<"======================================================"<<endl;
	for(int i=0; i<data; i++){
		cout<<"----------------------------------------------"<<endl;
		cout<<" No.Pendaftaran	: "<<bdt[i].nopen<<endl;
		cout<<" Nama		: "<<bdt[i].nama<<endl;
		cout<<" Alamat 	: "<<bdt[i].alamat<<endl;
		cout<<" Ruang 		: "<<bdt[i].ruang<<endl;
		cout<<"----------------------------------------------"<<endl;
		cout<<" Fasilitas : "<<endl;
		for(int a=0; a<bdt[i].fasil; a++){
			cout<<"    "<<a+1<<". "<<bdt[i].fslts[a].nama_fasilitas<<endl;
			cout<<"     Biaya : "<<bdt[i].fslts[a].biaya<<endl;
		}
		cout<<"----------------------------------------------"<<endl;
	}
}

void sequential(int &data){ //system("cls");
	string cari;
	cout<<"--------------------------------------------------"<<endl;
	cout<<"Masukkkan No.Pendaftaran : ";cin>>cari;
	cout<<"--------------------------------------------------"<<endl;
	int i;
	found = false;
	i=0;
	while( (i<data) & (!found) ){
		if(bdt[i].nopen == cari){
		found = true;
		}
		else{
		i = i+1;
		}
	}
	if(found){
		cout<<"=============================================="<<endl;
		cout<<" No.Pendaftaran	: "<<bdt[i].nopen<<endl;
		cout<<" Nama		: "<<bdt[i].nama<<endl;
		cout<<" Alamat 	: "<<bdt[i].alamat<<endl;
		cout<<" Ruang 		: "<<bdt[i].ruang<<endl;
		cout<<"----------------------------------------------"<<endl;
		cout<<" Fasilitas : ";
			int k=0;
			for(int b = 0; b<bdt[i].fasil; b++){
			cout<<endl<<k+1<<". "<<bdt[i].fslts[b].nama_fasilitas<<endl;
			cout<<" Biaya : "<<bdt[i].fslts[b].biaya<<endl;
			k++;
			}
		cout<<"----------------------------------------------"<<endl;
			
		}
	else{
		cout<<"--------------------------------------------------------------------"<<endl;
		cout<<"    >>   No.Pendaftaran Yang Anda Cari Tidak Ada   <<"<<endl;
		cout<<"--------------------------------------------------------------------"<<endl;
	}
}

void bubble(biodata bdt[], int &data){ system("cls");
	int  i, j;
	biodata temp;
	for(i=0; i<data-1; i++){
		for(j=0; j<data-1-i; j++){
			if( bdt[j].nopen > bdt[j+1].nopen ){
				temp = bdt[j];
				bdt[j] = bdt[j+1];
				bdt[j+1] = temp;
			}
		}
	}
	urutan(bdt,data);
}

void selection(biodata bdt[], int &data){ system("cls");
	int  c, j;
	for(c=0; c<data; c++){
		for(j=c+1; j<data; j++){
			if(bdt[c].nopen>bdt[j].nopen){
				temp = bdt[c];
				bdt[c] = bdt[j];
				bdt[j] = temp;
			}
		}
	}
	urutan(bdt,data);
}

void insertion(biodata bdt[], int &data){ system("cls");
	int i,j ;
	for(i=1; i<data; i++){
		temp = bdt[i];
		j = i-1;
		while( (temp.nopen<bdt[j].nopen) & (j>=0) ){
			bdt[j+1] = bdt[j];
			j = j-1;
			bdt[j+1] = temp;
		}
	}
	urutan(bdt, data);
}

void shell(biodata bdt[], int &data){ system("cls");
	int i=0, j=0, k=0;
	for(k=data/2; k>0; k=k/2){
		for(j=k; j<data; j++){
			for(i=j-k; i>=0; i-=k){
				if(bdt[i+k].nopen >= bdt[i].nopen)
					break;
				else{
					temp = bdt[i];
					bdt[i] = bdt[i+k];
					bdt[i+k] = temp;
				}
			}
		}
	}
	urutan(bdt, data);
}

void quick(biodata bdt[], int low, int high){ //system("cls");
	if(low < high){
		int get = low;
		int j;
		//change order
		for(int i=low; i<high; i++){
			if(bdt[i].nopen < bdt[get].nopen){
				for(j =i; j>get; j--){
					biodata temp = bdt[j];
					bdt[j]=bdt[j-1];
					bdt[j-1] = temp;
				}	
				get=j+1;
			}
		}
		quick(bdt, low, get);
		quick(bdt, get+1, high);
	}
}

void merge(biodata bdt[], int l, int m, int r){ system("cls");
	int i, j, k; 
	int n1 = m - l + 1; 
	int n2 = r - m;
	biodata Ln[n1], Rn[n2];
	for (i = 0; i < n1; i++) {
		Ln[i].nopen = bdt[l + i].nopen;
		Ln[i] = bdt[l + i];
	} 
	for (j = 0; j < n2; j++) {
		Rn[j].nopen = bdt[m + 1+ j].nopen; 
		Rn[j] = bdt[m + 1+ j];
	}
	i = 0; 
	j = 0; 
	k = l; 
	while (i < n1 && j < n2) 
	{ 
		if (Ln[i].nopen <= Rn[j].nopen) 
		{ 
			bdt[k].nopen = Ln[i].nopen; 
			bdt[k] = Ln[i]; 
			i++; 
		} 
		else
		{ 
			bdt[k].nopen = Rn[j].nopen; 
			bdt[k] = Rn[j];
			j++; 
		} 
		k++; 
	} 
	while (i < n1) 
	{ 
		bdt[k].nopen = Ln[i].nopen; 
		bdt[k] = Ln[i]; 
		i++; 
		k++; 
	} 
	while (j < n2) 
	{ 
		bdt[k].nopen = Rn[j].nopen; 
		bdt[k] = Rn[j]; 
		j++; 
		k++; 
	} 
} 

void mergeSort(biodata bdt[], int l, int r) { 
	if (l < r) 
	{ 
		int m = l+(r-l)/2; 
		mergeSort(bdt, l, m); 
		mergeSort(bdt, m+1, r); 
		merge(bdt, l, m, r); 
	} 
} 

void binary(){
	string cari;
	cout<<"----------------------------------------------"<<endl;
	cout<<"Masukkkan No.Pendaftaran : ";
	cin>>cari;
	cout<<"----------------------------------------------"<<endl;
	int i, j, k;
	found = false;
	int x = 0;
	i = 0;
	j = data;
	while((!found)&&(i<=j)){
		k=(i+j)/2;
		if(cari == bdt[k].nopen)
			found = true;
		else{
			if(cari < bdt[k].nopen)
				j = k-1; //i tetap
			else 
				i = k+1; //j tetap
		}
	}
	if(found){
		cout<<"=============================================="<<endl;
		cout<<" No.Pendaftaran	: "<<bdt[k].nopen<<endl;
		cout<<" Nama				: "<<bdt[k].nama<<endl;
		cout<<" Alamat 			: "<<bdt[k].alamat<<endl;
		cout<<" Ruang 				: "<<bdt[k].ruang<<endl;
		cout<<"----------------------------------------------"<<endl;
			cout<<" Fasilitas : ";
			for(int j=0; j<bdt[k].fasil; j++){
			cout<<endl<<x+1<<". "<<bdt[k].fslts[j].nama_fasilitas<<endl;
			cout<<" Biaya : "<<bdt[k].fslts[j].biaya<<endl;
			x++;
			}
			cout<<"----------------------------------------------"<<endl; 
	}
	else{
		cout<<"--------------------------------------------------------------------"<<endl;
		cout<<"    >>   No.Pendaftaran Yang Anda Cari Tidak Ada   <<"<<endl;
		cout<<"--------------------------------------------------------------------"<<endl;
	}
}

void bacadata(ifstream &data_masuk, int &data, biodata bdt[], string &namafile){
	up :
	int i = 0;
	cout<<"Masukkan Nama File : ";cin>>namafile;
	cout<<"Masukkan Nama File yang untuk simpan banyak data : ";cin>>namabatas;
	cout<<"masukkan Nama File yang untuk simpan banyak fasilitas : ";cin>>namafasil;
	data_masuk.open(namafile.c_str(), ios::in);
	batas_output1.open(namabatas.c_str(), ios::in);
	batas_output3.open(namafasil.c_str(), ios::in);
	
	i = 0;
	if(data_masuk.is_open() && batas_output1.is_open() && batas_output3.is_open()){
		
		while(!batas_output3.eof()){
			batas_output3>>bdt[i].fasil;
			i++;
		}
		i = 0;
		while(!data_masuk.eof()){
				getline(data_masuk, bdt[i].nopen);
				getline(data_masuk, bdt[i].nama);
				getline(data_masuk, bdt[i].alamat);
				getline(data_masuk, bdt[i].ruang);
				for(int a=0; a<bdt[i].fasil; a++){
					getline(data_masuk, bdt[i].fslts[a].nama_fasilitas);
					getline(data_masuk, bdt[i].fslts[a].biaya);
				}
			i++;
		}data=i-1;
		while(!batas_output1.eof()){
			batas_output1>>data;
		}
		data_masuk.close();
		batas_output1.close();
		batas_output3.close();
			for(int i=0; i<data; i++){
				cout<<"Nopen : "<<bdt[i].nopen<<endl;
				cout<<"Nama : "<<bdt[i].nama<<endl;
				cout<<"Alamat : "<<bdt[i].alamat<<endl;
				cout<<"Ruang : "<<bdt[i].ruang<<endl;
				for(int a=0; a<bdt[i].fasil; a++){
					cout<<"Nama fasilitas : "<<bdt[i].fslts[a].nama_fasilitas<<endl;
					cout<<"Biaya : "<<bdt[i].fslts[a].biaya<<endl;
				}
			}
	}else{
		cout << "File " << namafile << " tidak ditemukan" << endl;
		input.close();
		data_masuk.close();
		batas_output1.close();
		batas_output3.close();
		goto up;
	} 
}

void tulisdata(ofstream &data_tulis, int &data, biodata bdt[], string &hasil_sambung){
	
			data_tulis.open(hasil_sambung, ios::app |  ios::out);
			batas_input3.open(hasil_sambung3, ios::app | ios::out);
			for(int i=0; i<data; i++){
				cout<<"No. Pendaftaran : "<<bdt[i].nopen<<endl;
				cout<<"Nama : "<<bdt[i].nama<<endl;
				cout<<"Alamat : "<<bdt[i].alamat<<endl;
				cout<<"Ruang : "<<bdt[i].ruang<<endl;
				data_tulis<<bdt[i].nopen<<endl;
				data_tulis<<bdt[i].nama<<endl;
				data_tulis<<bdt[i].alamat<<endl;
				data_tulis<<bdt[i].ruang<<endl;
				batas_input3<<bdt[i].fasil<<endl;
				for(int a=0; a<bdt[i].fasil; a++){
					cout<<"Nama Fasilitas : "<<bdt[i].fslts[a].nama_fasilitas<<endl;
					cout<<"Biaya : "<<bdt[i].fslts[a].biaya<<endl;
					data_tulis<<bdt[i].fslts[a].nama_fasilitas<<endl;
					data_tulis<<bdt[i].fslts[a].biaya<<endl;
				}
			}
				data_tulis.close();
			batas_input3.close();
	}
void tulisdata_urut(ofstream &data_tulis, int &data, biodata bdt[], string &hasil_urut){

		data_tulis.open(hasil_urut, ios::app |  ios::out);
		batas_input3.open(hasil_urut3, ios::app | ios::out);
		int  i, j;
		biodata temp;
		for(i=0; i<data-1; i++){
			for(j=0; j<data-1-i; j++){
				if( bdt[j].nopen > bdt[j+1].nopen ){
				temp = bdt[j];
				bdt[j] = bdt[j+1];
				bdt[j+1] = temp;
				}
			}
		}
			for(int i=0; i<data; i++){
				cout<<"No. Pendaftaran : "<<bdt[i].nopen<<endl;
				cout<<"Nama : "<<bdt[i].nama<<endl;
				cout<<"Alamat : "<<bdt[i].alamat<<endl;
				cout<<"Ruang : "<<bdt[i].ruang<<endl;
				data_tulis<<bdt[i].nopen<<endl;
				data_tulis<<bdt[i].nama<<endl;
				data_tulis<<bdt[i].alamat<<endl;
				data_tulis<<bdt[i].ruang<<endl;
				batas_input3<<bdt[i].fasil<<endl;
				for(int a=0; a<bdt[i].fasil; a++){
					cout<<"Nama Fasilitas : "<<bdt[i].fslts[a].nama_fasilitas<<endl;
					cout<<"Biaya : "<<bdt[i].fslts[a].biaya<<endl;
					data_tulis<<bdt[i].fslts[a].nama_fasilitas<<endl;
					data_tulis<<bdt[i].fslts[a].biaya<<endl;
				}
			}
				data_tulis.close();
			batas_input3.close();
	}


