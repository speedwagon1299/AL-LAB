#include <stdio.h>
#include <stdlib.h>

void gcd(int a, int b)
{
	int opcount = 0, temp = b;
	while(temp > 0)
	{
		opcount++;
		if(a%temp == 0 && b%temp == 0)	break;
		temp--;
	}
	printf("\nOpCount: %d\n",opcount);
	printf("\nGCD: %d\n",temp);
	return;
}

int main()
{
	printf("\nEnter the two numbers:\n");
	int a,b; scanf("%d%d",&a,&b);
	if(a == b)
	{
		printf("\nGCD: %d\n",a);
		return 0;
	}
	else if(a > b)	gcd(a,b);
	else	gcd(b,a);
	return 0;
}