#include <stdio.h>
#include "my.h"
#include <stdlib.h>
#include <string.h>

void connectConnexion(Connexion* connexion,Node* a, Node* b) // a and b must be last
{
    if(a != NULL && b != NULL)
    {
    a->data = connexion;
    b->data = connexion;
    }
}

Chaine* duppliquerChaine(Chaine* a)
{
    Chaine* ret;
    
    ret = createChaine(a->texte);
    while(a != NULL && a->next != NULL)
    {
        getLastChaine(ret)->next = createChaine(a->next->texte);
        a = a->next;
    }
    return ret;
}

int* duppliquerIntEtoile(int* a)
{
    int* ret;
    
    ret = NULL;
    ret = (int*)malloc(sizeof(int));
    *ret = *a;
    return ret;
}

int openCsv(Ville** head, char* chemin)
{
        FILE *fichier;
        char tampon[BUFSIZ];
        int actuel;
        int c;
        char **ligne;
        actuel = 0;
        
        fichier = fopen(chemin, "r");
        if (!fichier) 
            return -8;
        while ((c = fgetc (fichier)) != '\n' && c != EOF){} // On ne lit pas la première ligne
        while ((c = fgetc (fichier)) != EOF) 
        {
                if (c == ';' || c == '\n') 
                {
                    tampon[actuel++] = '\0';
                    ligne = strCut(tampon,',');
                    addLine(head,ligne[0],ligne[1],ligne[2],ligne[3]);
                    actuel = 0;
                    memset (tampon, 0, sizeof tampon);
                } 
                else 
                    tampon[actuel++] = c;
        }
        fclose (fichier);
    return EXIT_SUCCESS;
}

void setConnexionstoFalse(Ville** head)
{
    Ville* ville;
    Node* node;
    
    ville = *head;
    node = ville->listLien;
    while(ville->next != NULL)
    {
        while(node != NULL)
        {
           node->data->isUsed = false;
           node = node->next;
        }
        ville = ville->next;
        node = ville->listLien;
    }
}