// Divide & Conquer Quick Sort
/*made by Charles Antony Hoare */

#include <stdc++.h>

using namespace std;

void quick_sort(int arr[], int start, int end) {
	if (start > end) return ;
	int pivot = start;
	int i = pivot + 1;
	int j = end;
	
	int temp;
	while (i <= j) {
		

		while (i <= end && arr[i] <= arr[pivot])
			i++;
		while (j > start && arr[j] >= arr[pivot])
			j--;
		if (i > j) {
			temp = arr[j];
			arr[j] = arr[pivot];
			arr[pivot] = temp;
		}
		else {
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}

	quick_sort(arr, start, j - 1);
	quick_sort(arr, j+1, end);
}

int main() {
	int length;
	cout << "배열의 길이 입력:";
	cin >> length;
	int *arr = new int[length];
	
	for (int i = 0; i < length; i++)
		cin >> arr[i];
	
	quick_sort(arr, 0, length-1);

	for (int i = 0; i < length; i++)
	cout << arr[i]<< " ";

	delete[] arr;
}