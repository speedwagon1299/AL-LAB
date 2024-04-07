#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int* sieve(int a)
{
	int* arr = (int*) calloc(a/2+1,sizeof(int));
	arr[0] = arr[1] = -1;
	int mul;
	for(int i = 2; i <= a/2; i++)
	{
		mul = 2;
		while(i*mul <= a/2)
		{
			arr[i*mul] = -1;
			mul++;
		}
	}
	return arr;
}

int gcd(int a, int b)
{
	if(b > a)
	{
		int temp = b;
		b = a;
		a = b;
	}
	int* arr = sieve(a);
	int gcd = 1;
	int arr_size = sizeof(arr)/sizeof(sizeof(arr[0]));
	
}