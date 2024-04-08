#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int opcount = 0;

void badSymbol(int* arr, char* word, int n)
{
	for(int i = 0; i < 26; i++)
	{
		arr[i] = n;
	}
	for(int i = 0; i < n-1; i++)
	{
		if(word[i] == '_') continue;
		arr[word[i] - 'A'] = n-1-i;
	}
}

void goodSuffix(int* arr, char* word, int n)
{
	int flag, temp;
	for(int k = 1; k < n; k++)
	{
		arr[k] = n;
	}
	for(int k = 1; k < n; k++)
	{
		char* suffix = word + n - k;
		for(int i = 0; i < n-k; i++)
		{
			flag = 1; temp = i;
			for(int j = 0; j < k; j++,temp++)
			{
				if(suffix[j] != word[temp])
				{
					flag = 0;
					break;
				}
			}	
			if(flag == 0)	continue;
			if((flag == 1 && i > 0 && suffix[-1] != word[i-1]) || (flag == 1 && i == 0))
			{
				arr[k] = n-temp;
			}
		}
		if(arr[k] == n)
		{
			temp = k-1;
			while(temp >= 1)
			{
				suffix = word+n-temp;
				flag = 1;
				for(int i = 0; i < temp; i++)
				{
					if(suffix[i] != word[i])
					{
						flag = 0;
						break;
					}
				}
				if(flag == 0)
				{
					temp--;
					continue;
				}
				else
				{
					arr[k] = n-temp;
					break;
				}
			}
		}
	}
}

int max(int a, int b)
{
	if(a > b)	return a;
	return b;
}

int main()
{
	printf("\nEnter the word: ");
	char* word = (char*) calloc(20,sizeof(char));
	scanf("%s",word);
	int n = strlen(word);
	
	int* bad = (int*) calloc(27,sizeof(int));
	badSymbol(bad,word,n); 

	int* good = (int*) calloc(n,sizeof(int));
	goodSuffix(good,word,n);

	printf("\nEnter the text: ");
	char* text = (char*) calloc(100,sizeof(char));
	scanf("%s",text);
	int m = strlen(text);

	int i,j,found,temp,k;
	for(i = n-1; i < m;)
	{
		found = 1; temp = i; k = 0;
		for(j = n-1; j >= 0; j--)
		{
			if(word[j] == text[temp--])
			{
				opcount++;
				k++;
			}
			else
			{
				found = 0;
				break;
			}
		}
		if(found)	break;
		else
		{
			char c = text[temp+1];
			if(k == 0)
			{
				if(c == '_')
				{
					i += n;
				}
				else
				{
					i += bad[c-'A'];
				}
			}
			else
			{
				if(c == '_')
				{
					i += max(n-k,good[k]);
				}
				else
				{
					i += max(bad[c-'A'] - k, good[k]);
				}
			}
		}
	}
	if(found)
	{
		printf("\nFound at index %d",temp+1);
	}
	else
	{
		printf("\nNot Found");
	}
	printf("\nOpCount: %d",opcount);
	return 0;
}