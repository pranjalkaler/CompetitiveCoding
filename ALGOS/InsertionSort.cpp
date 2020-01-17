#include <iostream>
using namespace std;

int* insertionSort(int* arr,int len){
	for(int j=1;j<len;j++){
		int key = arr[j];
		int i = j-1; 
		
		while(key<arr[i] && i>=0){
			arr[i+1]=arr[i];
			i = i-1;
		}
		arr[i+1]=key;
	}
	return arr;
}

int main(){
	int *arr = new int[5];
	arr[0] = 11;
	arr[1] = 5;
	arr[2] = 3;
	arr[3] = 2;
	arr[4] = 7;
	int *sorted_arr = insertionSort(arr,5);	
	for(int i=0;i<5;i++){
		cout<<arr[i]<<endl;
	}
	return 0;
}
