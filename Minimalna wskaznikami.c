#include <stdio.h>
#include <stdlib.h>
#define R 5
int * minimum(int *tab,int r)
{
	int najmniejsza=tab[0];
	int *wsk = &tab[0];
	int i=1;
	for(;i<r;i++)
	{
		if(tab[i]<=najmniejsza)
		{
			najmniejsza=tab[i];
			wsk=&tab[i];
		}
	}
	return wsk;
}
int main()
{
	int tab[R]={4,2,3,5,9};
	int *wsk = minimum(tab,R);
	printf("wartosc minimalna : %d \n wskaznik na ta wartosc : %p",*wsk,wsk);
}

