#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    char imie[30];
    char nazwisko[30];
    int rokuro;
}dane;
struct lista
{
    dane panagodnosc;
    struct lista* next;
}lista;
void printList(struct lista *head)
{
 struct lista* tmp;
 if(head==NULL) return NULL;
 else
 {
  for(tmp=head; tmp!=NULL; tmp=tmp->next)
  {
   printf("%s - ",tmp->panagodnosc.imie);
   printf("%s - ",tmp->panagodnosc.nazwisko);
   printf("%d\n",tmp->panagodnosc.rokuro);
  }
 }
}
struct lista* addList(struct lista *head)
{
    struct lista* tmp=malloc(sizeof(lista));
 if(tmp==NULL)
 {
  printf("Blad alokacji!");
  deleteList(&head);
  return NULL;
 }
 char* imie;
 char* nazwisko;
 int rokuro;
 printf("Podaj swoje: Imie, Nazwisko, Rok urodzenia");
 fgets(tmp->panagodnosc.imie,30,stdin);
 fgets(tmp->panagodnosc.nazwisko,30,stdin);
 scanf("%d",tmp->panagodnosc.rokuro);
 tmp->next=head;
 return tmp;
}
void deleteElem(struct lista** head)
{
    if(head!=NULL)
 {
 struct lista* tmp=*head;
 *head=(*head)->next;
 free(tmp);
 }
}
void deleteList(struct lista** head)
{
 struct lista* tmp;
 while(*head!=NULL)
    {
       tmp=*head;
       *head=(*head)->next;
       free(tmp);
    }
    head=NULL;
}
int main()
{
 struct lista* head=NULL;
 head=addList(head);
 if(head==NULL) return -1;
 head=addList(head);
 if(head==NULL) return -1;
 printList(head);
 deleteElem(&head);
 printList(head);
 deleteElem(&head);
 printList(head);
 deleteList(&head);
 printList(head);
 return 0;
}