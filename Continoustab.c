#include <stdio.h>
#include <stdlib.h>
#define R 5
int createContinousMatrix(int*** atab, int n)
{
    int** temp=malloc(n*sizeof(n*sizeof(int)));
    if(temp == NULL) return -1;
    *temp=malloc(n*n*sizeof(int));
    if(*temp == NULL) return -1;
    int i;
    for(i=0;i<n;i++)
    {
        temp[i]=*temp+(i*n);
    }
    *atab=temp;
    return 0;
//Komentzarz do GitHuba
}
void deleteContinousMatrix(int*** atab)
{
    free(**atab);
    free(*atab);
    *atab=NULL;
}
int copyMatrix(int*** pdest, int** src, int n)
{
    int** temp;
    int t = createContinousMatrix(&temp,n);
    if(t==-1)
    {
        printf("Blad alokacji");
        return -1;
    }
    int i;
    for(i=0;i<(n*n);i++)
    {
        (*temp)[i]=(*src)[i];
    }
    *pdest=temp;
    return 0;
}
void fillMatrix(int** tab, int n)
{
    int i,j,x=1;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            tab[i][j]=x;
            x++;
        }
    }
}
void printMatrix(int** tab, int n)
{
    int j,i;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%4d ",tab[i][j]);
        }
        printf("\n");
    }
}
int main()
{
    int** tab;
    int t = createContinousMatrix(&tab,R);
    if(t==-1)
    {
        printf("Blad alokacji");
        return -1;
    }
    fillMatrix(tab,R);
    printf("tab : \n");
    printMatrix(tab,R);
    printf("\nctab : \n");
    int** ctab;
    t = copyMatrix(&ctab,tab,R);
    if(t==-1)
    {
        printf("Blad alokacji");
        return -1;
    }
    printMatrix(ctab,R);
    deleteContinousMatrix(&tab);
    deleteContinousMatrix(&ctab);
    return 0;
}