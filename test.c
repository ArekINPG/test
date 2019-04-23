#include <stdio.h>
#include <stdlib.h>
#define R 5

double** createMatrix(int n)
{
    int * tab=malloc(n*sizeof(n*sizeof(double)));
    return &tab;
}
void fillMatrix(double** tab, int n)
{
    int x=1;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            tab[i][j]=x;
            x++;
        }
    }//asd
//Komentarz na rzecz zmian do Githuba LOL
    }
}
void printMatrix(double** tab, int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%4lf ",tab[i][j])
        }
    printf("\n");
    }
}
void deleteMatrix(double** tab, int n)
{
    ;
}

int main()
{
    double** tab=createMatrix(R);
    fillMatrix(tab, R);
    printMatrix(tab, R);
    free(tab);
    return 0;

}