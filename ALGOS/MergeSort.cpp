#include <iostream>

using namespace std;

int* Merge(int* arr1, int l1, int* arr2, int l2) {
	int *arr = new int[l1+l2];
	int itr1, itr2, itr3;
	itr1 = itr2 = itr3 = 0;
	while(itr1 < l1 && itr2 < l2) {
		if(arr1[itr1] < arr2[itr2])
			arr[itr3++] = arr1[itr1++];
		else
			arr[itr3++] = arr2[itr2++];
	}
	if(itr2 < l2) {
		while(itr2 < l2)
			arr[itr3++] = arr2[itr2++];
	}
	if(itr1 < l1) {
		while(itr1 < l1)
			arr[itr3++] = arr1[itr1++];
	}
	return arr;
}

int* MergeSort(int* arr, int l, int r) {
	if(l < r) {
		int mid = l + (r - 1) / 2;
		auto arr1 = MergeSort(arr, l, mid);
		auto arr2 = MergeSort(arr, mid+1, r);
		arr = Merge(arr1, mid - l + 1, arr2, r - mid);
	}
	return arr;
}

int main(){
	int *arr = new int[5];
	arr[0] = 11;
	arr[1] = 5;
	arr[2] = 3;
	arr[3] = 2;
	//arr[4] = 7;

	for(int a = 0; a<4; a++)
		cout << arr[a] << " >>" << &arr[a] << "<< " << endl;

	int *sorted_arr = MergeSort(arr, 0, 4);	

	for( int i=0; i<4; i++) {
		cout << sorted_arr[i] << endl;
	}
	return 0;
}
