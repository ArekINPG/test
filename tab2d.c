#include <stdio.h>
#include <stdlib.h>
#define R 5

int * Create_tab(int size)
{
    int* temp=malloc(size*sizeof(int));
    if(temp==NULL) printf("Allocation fail (2D)");
    else
    {
        printf("Allocation of 1D array completed! on adress : %p to %p (%d bytes)\n",temp,&(temp[size-1]),(&(temp[size])-temp));
    }
    return temp;
}

void Fill_tab(int* tab,int size)
{
    for(int i=0;i<size;i++) tab[i]=i;
}

void Print_tab(int* tab,int size)
{
    printf("Array displayed : ");
    for(int i=0;i<size;i++)
    {
        printf("%d ",tab[i]);
    }
}
int main()
{
    int* tab = Create_tab(R);
    Fill_tab(tab,R);
    Print_tab(tab,R);
    free(tab);
    printf("\n");
    return 0;
}