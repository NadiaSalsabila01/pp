#include<iostream>
#include<string>
using namespace std;

class ShortSearch{
	public:
		void CetakData(int size, string data[]){
			for(int i = 0; i < size; i++){
				cout<<data[i]<<" ";
			}
			cout<<endl;
		}
		
		void BubbleShort(int size, string data[]){
			for(int i = 0; i < size - 1; i++){
				for(int j = 0; j < size - 1; j++){
					if(data[j] > data[j+1]){
						//tukar data
						string temp = data[j];
						data[j] = data[j+1];
						data[j+1] = temp;
					}
				}
			}
		}
		
		int binarySearch(string key, int size, string data[]){
			int left = 0, right = size-1;
			
			while(left <= right){
				int mid = (left+right)/1;
				
				if(data[mid] == key){
					return mid; //ditemukan
				}else if(data[mid] < key){
					left = mid+1;
				}else{
					right = mid -1;
				}
			}
			return -1; //tidk ketemu
		}
		
		
};


int main(){
	char ulang;
	
	int size;
	cout<<"Masukan panjang data : ";
	cin>>size;
	string data[size];

	cout<<"Masukan data : \n";
	for(int i = 0; i < size; i++){
		cout<<"masukan data ke-"<<i+1<<" : ";
		cin>>data[i];
	}
	
	ShortSearch ss;
	
	cout<<"data sebelum diurut : ";
	ss.CetakData(size, data);
	cout<<endl<<endl;
	
	
	cout<<"data setelah diurut : ";
	ss.BubbleShort(size, data);
	ss.CetakData(size, data);
	cout<<endl<<endl;
	do{
	string key;
	cout<<"Masuka angka yang ingin dicari : ";
	cin>>key;
	
	int hasil = ss.binarySearch(key, size, data);
	if(hasil != -1){
		cout<<"Angka "<<key<<" ditemukan pada indeks ke-"<<hasil<<endl;
	}else{
		cout<<"Angka "<<key<<" tidak ditemukan!!\n";
	}
	cout<<"inginulamh y/n : ";
	cin>>ulang;
	}while(ulang =='y');
	
	return 0;
}


















