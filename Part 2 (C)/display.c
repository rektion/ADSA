#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "my.h"

void printMenu(void)
{
    puts("-----------------------");
    puts("         Menu");
    puts("-----------------------");
    putchar('\n');
}

void waitUserInput(void)
{
    char out[100];
    fgets(out,100,stdin);
}

void afficherChemin(Ville** head, Provenances* depart, Provenances* arrivee, Chaine* ret, int* distance, int* temps, int* count)
{
    (*count)++;
    if(depart->next != NULL)
    {
        afficherChemin(head, depart->next, arrivee, duppliquerChaine(ret), duppliquerIntEtoile(distance),
                       duppliquerIntEtoile(temps), count);
    }
    getLastChaine(ret)->next = createChaine(depart->provenance->nomVille);
    if(strcmp(depart->provenance->nomVille,arrivee->provenance->nomVille) == 0)
    {
        afficherEtFreeChaine(head,ret,distance,temps);
        printf("Il y a donc %d participant a envoyer", *count);
        putchar('\n');
        return;
    }
    afficherChemin(head, depart->provenance->Cell->listProvenances, arrivee, ret, distance, temps, count);
}

void afficherEtFreeChaine(Ville** head, Chaine* chaine, int* distance, int* temps)
{
    Chaine* tmp;
    
    tmp = chaine;
    while(tmp->next != NULL)
    {
        getPoid(head,tmp->texte, tmp->next->texte, distance, temps);
        tmp = tmp->next;
    }
    printf(" %d km, ",*distance);
    puts(fromMinutesToHeures(*temps));
    free(distance);
    free(temps);
    tmp = chaine;
    Chaine* tmpnxt;
    while(tmp != NULL)
    {
        tmpnxt = tmp->next;
        printf("%s ",tmp->texte);
        free(tmp);
        tmp = tmpnxt;
    }
    putchar('\n');
}

void afficherVilles(Ville** head)
{
    Ville* ville;
    
    ville = *head;
    int i =1;
    while(ville != NULL)
    {
        printf("%d) ",i);
        puts(ville->nomVille);
        ville = ville->next;
        i++;
    }
}