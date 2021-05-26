// C++ program for implementation of Heap Sort
#include <iostream>
using namespace std;
void heapsorts(int array[], int g, int f)
{
	int max = f;
	int left = 2 * f + 1; 
	int right = 2 * f + 2; 
	if (left < g && array[left] > array[max])
		max = left;
	if (right < g && array[right] > array[max])
		max = right;
	if (max != f) {
		swap(array[f], array[max]);
		heapsorts(array, g, max);
	}
}
void heapSorts(int array[], int g)
{
	for (int i = g/ 2 - 1; i >= 0; i--)
		heapsorts(array, g, i);
	for (int i = g - 1; i > 0; i--) {
		swap(array[0], array[i]);
		heapsorts(array, i, 0);
	}
}
void printer(int array[], int n)
{
	for (int i = 0; i < n; ++i)
		cout << array[i] << " ";
	cout << "\n";
}
int main()
{
	int arr[] = { 12, 11, 13, 5, 6, 7 };
	int n = sizeof(arr) / sizeof(arr[0]);

	heapSorts(arr, n);

	cout << "Sorted array is \n";
	printer(arr, n);
}
