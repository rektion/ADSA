#include "my.h"
#include <stdlib.h>

void freeConnexion(Connexion* co)
{
    free(co);
}

void freeListNoeud(Node* head)
{
    Node* tmp;
    
    tmp = head;
    while(tmp != NULL)
    {
        head = head->next;
        free(tmp);
        tmp = head;
    }
}

void freeVille(Ville* ville)
{
    free(ville->Cell);
    freeListNoeud(ville->listLien);
    free(ville->nomVille);
    free(ville);
}

void freeListVilles(Ville* head)
{
    Ville* tmp;
    
    tmp = head;
    while(tmp != NULL)
    {
        head = head->next;
        freeVille(tmp);
        tmp = head;
    }
}