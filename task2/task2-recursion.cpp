//Fibonacci Series using Recursion 
#include<bits/stdc++.h> 
using namespace std; 

int fibona(int p) 
{ 
	if (p <= 1) 
		return p; 
	return fibona(p-1) + fibona(p-2); 
} 

int main () 
{ 
	int o = 9; 
	cout << fibona(o); 
	return 0; 
} 

