#include <stdio.h>
#include "my.h"
#include <string.h>

Ville* getDest(Connexion* data, Ville* origin)
{
    return  (data != NULL ? (strcmp(origin->nomVille, data->villeA->nomVille) != 0 ? data->villeA : data->villeB) : NULL);
}

Ville* findDirectLinkToVille(char* nomVille, Ville** head)
{
    Ville* ville;
    
    ville = *head;
    while(ville != NULL)
    {
        if(areVillesEquals(nomVille,ville))
            return ville;
        ville = ville->next;
    }
    return NULL;
}

Ville* findFixe(Ville** head)
{
    Ville* ville;
    Ville* provenance;
    Cell* tmp;
    
    ville = *head;
    provenance = NULL;
    tmp = createCell();
    while(ville != NULL)
    {
        if( !(ville->Cell->isBlocked) )
        {
          provenance = tmp->poid < ville->Cell->poid ? provenance : ville;
          lighter3(tmp, ville->Cell, head);
        }
        ville = ville->next;
    }
    provenance->Cell->isBlocked = true;
    return provenance;
}

Ville* trouveIemeVille(Ville** head,int i)
{
    Ville* ville;
    
    ville = *head;
    while(i>1 && ville!= NULL)
    {
        ville = ville->next;
        i--;
    }
    return ville;
}