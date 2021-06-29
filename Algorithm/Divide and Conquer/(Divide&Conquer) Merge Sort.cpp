// Divide & Conquer Merge Sort
/*made by Von-Neumann */

#include <stdc++.h>

using namespace std;

int sorted[99999];
void merge(int arr[],int sorted[], int start, int median, int end) {
	int i = start,k = start;
	int j = median + 1;
	while (i<=median&& j<= end) {
		
		if (arr[i] <= arr[j]) 
			sorted[k++] = arr[i++];
			
		else 
			sorted[k++] = arr[j++];
	}
	int tmp = i > median ? j : i;

	while (k <= end)
		sorted[k++] = arr[tmp++];

	for (int i = start; i <= end; i++)
		arr[i] = sorted[i];
}

void merge_sort(int arr[], int start, int end) {
	
	if (start < end) {
		int median = (start + end) / 2;
		merge_sort(arr, start, median);
		merge_sort(arr, median+1, end);
		merge(arr,sorted, start, median, end);
	}
}

int main() {
	int length;
	cout << "배열의 길이 입력:";
	cin >> length;
	int *arr = new int[length];
	
	for (int i = 0; i < length; i++)
		cin >> arr[i];
	
	merge_sort(arr, 0, length-1);

	for (int i = 0; i < length; i++)
	cout << arr[i]<< " ";

	delete[] arr;
}