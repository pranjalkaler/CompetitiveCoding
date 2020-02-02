#include <iostream>
using namespace std;

void CountSort(int arr[], int size) {
	int max = 0, i;
	int index = 0;
	int brr[size];
	for(i = 0; i<size; i++) {
		brr[i] = arr[i];
		if(arr[i] > max)
			max = arr[i];
	}
	max++;
	int count[max];
	for (i = 0; i<=max; i++) {
		count[i]  = 0;
	}
	for(i = 0; i<size; i++) {
		count[arr[i]]++;
	}
	for(i = 1; i<=max; i++) {
		count[i] += count[i - 1];
	}
	for(i = 0; i < size; i++) {
		arr[(count[brr[i]]--) - 1] = brr[i];
	}
}

void printArr(int arr[], int size, string msg) {
	cout << msg << endl;
	for(int i = 0; i<size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main() {
	int arr[] = {6,3,9,1,2,7,4,9,6,2,1,6};
	printArr(arr, 12, "Array before sorting:");
	CountSort(arr, 12);
	printArr(arr, 12, "Array after sorting: ");
	return 0;
}
