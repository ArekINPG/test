#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct zesp
{
    float rzecz;
    float uroj;
};

void wyp(struct zesp z)
{
    printf("Liczba znaleziona to %2f+%2fi\n", z.rzecz, z.uroj);
}

struct zesp dodawanie(struct zesp k, struct zesp l)
{
    k.rzecz+=l.rzecz;
    k.uroj+=l.uroj;
    return k;//asd
}

float modul(struct zesp k)
{
    float wynik=sqrt(k.rzecz*k.rzecz+k.uroj*k.uroj);
    return wynik;
}

struct zesp sprzezenie(struct zesp k)
{
    k.uroj=-k.uroj;
    return k;
}


int main()
{
    struct zesp x={.rzecz=5, .uroj=4};
    struct zesp y={15, 9};
    printf("To jest dodawanie\n");
    struct zesp p=dodawanie(x,y);
    wyp(p);
    printf("To jest modu³\n");
    float wynik=modul(x);
    printf("%f\n",wynik);
    printf("To jest sprzê¿enie\n");
    struct zesp s=sprzezenie(x);
    wyp(s);
}
