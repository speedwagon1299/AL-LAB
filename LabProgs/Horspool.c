#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int opcount = 0;

void shiftTable(int* arr, char* word, int n)
{
	for(int i = 0; i < 27; i++)
	{
		arr[i] = n;
	}
	for(int i = 0; i < n-1; i++)
	{
		if(word[i] == '_') continue;
		arr[word[i] - 'A'] = n-1-i;
	}
}

int main()
{
	printf("\nEnter the word: ");
	char* word = (char*) calloc(20,sizeof(char));
	scanf("%s",word);
	int n = strlen(word);
	
	int* shift = (int*) calloc(27,sizeof(int));
	shiftTable(shift,word,n); 

	printf("\nEnter the text: ");
	char* text = (char*) calloc(100,sizeof(char));
	scanf("%s",text);
	int m = strlen(text);
	int i,j,found,temp,count;
	for(i = n-1; i < m;)
	{
		found = 1; temp = i; count = 0;
		for(j = n-1; j >= 0; j--)
		{
			opcount++;
			if(word[j] == text[temp--])
			{
				count = 1;
				continue;
			}
			if(!count)	temp++;
			else	temp+= 2;
			found = 0;
			break;
		}
		if(found)	break;
		if(text[temp] == '_')
		{
			i+= shift[26];
		}
		else
		{
			i += shift[text[temp]-'A'];
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