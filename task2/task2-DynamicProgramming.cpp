// C++ program for Fibonacci Series 
// using Dynamic Programming 
#include<bits/stdc++.h> 
using namespace std; 

class DynamicProgramming { 
	
public: 
int fibona(int n) 
{ 

	int fib[n + 2]; 
	int i; 
	fib[0] = 0; 
	fib[1] = 1; 

	for(i = 2; i <= n; i++) 
	{  
	fib[i] = fib[i - 1] + fib[i - 2]; 
	} 
	return fib[n]; 
	} 
}; 
int main () 
{ 
	DynamicProgramming j; 
	int n = 9; 
	
	cout << j.fibona(n); 
	return 0; 
} 



