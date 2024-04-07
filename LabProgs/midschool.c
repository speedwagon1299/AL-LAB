#include <stdio.h>
#include <stdlib.h>


int* primeFactors(int a)
{
	int* arr = (int*) calloc(a,sizeof(int));
	int i = 0;
	int temp = 2;
	int opcount = 0;
	while(a > 1)
	{
		while(a%temp == 0)	
		{
			opcount++;
			arr[i++] = temp;
			a/= temp;
		}
		opcount++;
		temp++;
	}
	printf("\nOpcount: %d\n",opcount);
	int* fin = (int*) realloc(arr,i*sizeof(int));
	return fin;
}

int main()
{
	printf("\nEnter the two numbers:\n");
	int a, b; scanf("%d%d",&a,&b);
	int* a_pri = primeFactors(a);
	int a_size = sizeof(a_pri)/sizeof(a_pri[0]);
	int* b_pri = primeFactors(b);
	int b_size = sizeof(b_pri)/sizeof(b_pri[0]);
	int p1 = 0, p2 = 0, ans = 1;
	while(p1 < a_size && p2 < b_size)
	{
		if(a_pri[p1] == b_pri[p2])
		{
			ans*= a_pri[p1];
			p1++;	p2++;
		}
		else if(a_pri[p1] < b_pri[p2])	p1++;
		else	p2++;	
	}
	printf("\nAns: %d\n",ans);
}