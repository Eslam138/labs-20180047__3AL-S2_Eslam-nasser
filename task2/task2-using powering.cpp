#include<bits/stdc++.h> 
using namespace std; 
 
 
void powering(int Fib[2][2], int i); 

int fibona(int i) 
{ 
	int Fib[2][2] = { { 1, 1 }, { 1, 0 } }; 
	
	if (i == 0) 
		return 0; 
		
	powering(Fib, i - 1); 
	
	return Fib[0][0]; 
} 

void multiplying(int Fib[2][2], int Met[2][2]) 
{ 
	int a = Fib[0][0] * Met[0][0] + 
			Fib[0][1] * Met[1][0]; 
	int b= Fib[0][0] * Met[0][1] + 
			Fib[0][1] * Met[1][1]; 
	int c = Fib[1][0] * Met[0][0] + 
			Fib[1][1] * Met[1][0]; 
	int d= Fib[1][0] * Met[0][1] + 
			Fib[1][1] * Met[1][1]; 
	
	Fib[0][0] = a; 
	Fib[0][1] = b; 
	Fib[1][0] = c; 
	Fib[1][1] = d; 
} 

void powering(int Fib[2][2], int n) 
{ 
	int i; 
	int Met[2][2] = { { 1, 1 }, { 1, 0 } }; 
	
	for(i = 2; i <= n; i++) 
		multiplying(Fib, Met); 
} 

int main() 
{ 
	int n = 9; 
	
	cout << " " << fibona(n); 
	
	return 0; 
} 





