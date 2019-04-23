#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define SIZE 5
struct baza
{
int max_size;
int act_size;
struct wpis *tab;
};
struct wpis
{
char imie[30];
char nazwisko[30];
long numer;
};
void wypisz(struct baza b)
{
int i;
if(b.act_size==0)
{
    printf("Baza jest pusta");
}
for(i=0;i<b.act_size;i++)
    {
        printf("Wpis %i, Nazwisko to",i);
        puts(b.tab[i].nazwisko);
        printf("\nImie to");
        puts(b.tab[i].imie);
        printf("\nNumer to %l",b.tab[i].numer);
    }
}
int dodaj( struct baza *a_bazy, struct wpis *a_wpisu)
{
    if(!(a_bazy->act_size<a_bazy->max_size))
    {
        struct wpis *nowy_tab = realloc(a_bazy->tab,(a_bazy->act_size+a_bazy->max_size)*sizeof(*a_wpisu));
        if(nowy_tab==NULL)
        {
            printf("Blad alokacji!");
            return -1;
        }
        a_bazy->tab=nowy_tab;
    }
    (*a_bazy).tab[(*a_bazy).act_size]=*a_wpisu;
    (*a_bazy).act_size++;
    return 0;
}
void usun(struct baza *a_bazy,int indeks)
{
    for(;indeks<(a_bazy->act_size-1);indeks++)
    {
        a_bazy->tab[indeks]=a_bazy->tab[indeks+1];
    }
    a_bazy->act_size--;
    return 0;
}
void wypisz(struct baza b)
{
    int i=0;
    if(b.act_size==0) printf("Baza jest pusta!\n");
    for(;i<b.act_size;i++)
    {
        printf("Wpis %d : \n    Nazwisko : ",i);
        puts(b.tab[i].nazwisko);
        printf("\n    Imie : ");
        puts(b.tab[i].imie);
        printf("\n    Numer : %ld\n",b.tab[i].numer);
    }
}
void main()
{
struct wpis a;
struct baza b;
b.max_size=SIZE;
b.act_size=0;
b.tab=malloc(SIZE*sizeof(struct wpis));
if(b.tab==NULL)
{
    printf("Alokacja nieudana\n");
    return -1;
}
int operacja=0;
int i;
 do
  {
   printf("Co mam zrobiæ? (1 - wypisanie, 2 - dodawanie, 3 - usuwanie, 0 - koniec)\n");
   scanf("%d", &operacja);
   switch(operacja)
      {
      case 1:
      wypisz(b);
       break;
      case 2:
      printf("Imie : ");
      fgets(temp.imie,30,stdin);
      printf("Nazwisko : ");
      fgets(temp.nazwisko,30,stdin);
      printf("Numer telefonu : ");
      scanf("%ld", &(temp.numer));
      int pow=dodaj(&b, &temp);
      if(pow==-1) return 0;
        break;
      case 3:
      printf("Indeks wpisu do usuniecia : ");
      int indeks;
      scanf("%d",&indeks);
      usun(&b,indeks);
      printf("Wpis usuniety!\n");
        break;
      }
   } while(operacja != 0);
   free(b.tab);
}