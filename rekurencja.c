#include <stdio.h>
#include <stdlib.h>

int potega(float n,int k)
{
    if(k==0)
    {
        return 1;
    }
    else return potega(n,k-1)*n;
}

int main()
{
    float n=0.0;
    int k=0;
    int w=0;
    printf("Podaj liczbe ktora jest liczba rzeczywista\n");
    scanf("%f",&n);
    printf("podaj potege do ktorej chcesz podniesc liczbe\n");
    scanf("%i",&k);
    if(k<0)
    {
        printf("wyk³adnik ma byæ liczb¹ naturaln¹");
        return 0;
    }
    else
    {
        w=potega(n,k);
        printf("wynik to %i",w);
        return 0;
    }

}

