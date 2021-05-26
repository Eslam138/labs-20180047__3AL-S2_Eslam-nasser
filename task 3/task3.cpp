#include <iostream>
using namespace std;
int OrderStatistics(int array[], int l, int i)
{
	int max = 0;

	for (int i = 0; i < l; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
		int count[max + 1] = { 0 };
	for (int i = 0; i < l; i++) 
	{
		count[array[i]]++;
	}
	
	int min = 0;
	for (int num = 1; num <= max; num++)
	{
		if (count[num] > 0) {
			min+= count[num];
		}
		if (min >= i) 
		{
			return num;
		}
	}
}
int main()
{
	int array[] = { 7, 1, 4, 4, 20, 15, 8 };
	int index = sizeof(array) / sizeof(array[0]);
	int i = 3;
	cout << OrderStatistics(array, index, i);

	return 0;
}
