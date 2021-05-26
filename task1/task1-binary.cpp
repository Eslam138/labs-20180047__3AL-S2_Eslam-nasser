 #include <iostream> 
#include <ctime> 
using namespace std; 
int Random(int n, int b) 
{ 
    srand(time(NULL)); 
    return (n + rand() % (b-n+1)); 
} 
int randomBinarySearch(int array[], int left, 
                            int right, int x) 
{ 
    if (right >= left) 
    { 
        int middle = Random(left, right); 
        if (array[middle] == x) 
            return middle; 
        if (array[middle] > x) 
          return randomBinarySearch(array, left, 
                                    middle-1, x); 
        return randomBinarySearch(array, middle-1+1, 
                                         right, x); 
    } 
    return -1; 
} 

int main(void) 
{ 
    int array[] = {2, 3, 4, 10, 40}; 
    int n = sizeof(array)/ sizeof(array[0]); 
    int x = 10; 
    int result = randomBinarySearch(array, 0, n-1, x); 
    if(result == -1) 
   cout << "Element is not present in array"  << endl;
   else
    cout<<"Element is present at index "<< result; 
    return 0; 
} 