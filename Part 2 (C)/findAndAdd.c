#include <stdbool.h>
#include <stdio.h>
#include "my.h"

// Si la ville existe retourne son adresse
// Sinon l'ajoute et return son adresse (qui sera donc last)
Ville* cherchePuisAjouteVille(Ville** head, char* nomVille)
{
    Ville* tmp;
    
    tmp = doVilleExiste(*head, nomVille);
    if(areVillesEquals(nomVille, tmp))  // Si la ville recherchée est le last
        return tmp;
    else
    {
        addVille(&tmp,nomVille);
        if(tmp->next != NULL)
            return tmp->next;
        else
        {
            *head = tmp;
            return tmp; 
        }
    }
}

// Si le noeud existe retourne son adresse
// Sinon l'ajoute et return son adresse (qui sera donc last)
Node* cherchePuisAjouteNoeud(Ville* villeDepart, Node* nodeToLookFor)
{
    if(nodeToLookFor->data->villeA != villeDepart && nodeToLookFor->data->villeB != villeDepart)
        return NULL;
    if(villeDepart->listLien == NULL)
    {
        villeDepart->listLien = nodeToLookFor;
        return villeDepart->listLien;
    }
    Node* tmp;
    tmp= doNodeExiste(villeDepart, nodeToLookFor);
    if(areNodesEquals(nodeToLookFor, tmp)) 
    {
        return tmp;
    }
    else
    {
        addNode(tmp);
        return tmp->next;
    }
}

void cherchePuisAjouteVilleDansProvenance(Provenances* to,char* villeFrom, Ville** head)
{
    Provenances* tmp;
    bool etBil;
    
    tmp = to;
    etBil = true;
    while(tmp != NULL)
    {
        if( areVillesEquals(villeFrom,to->provenance) )
            etBil = false;
        tmp = tmp->next;
    }
    if(etBil)
    {
       if(getLastProvenance(to)->provenance == NULL)
           getLastProvenance(to)->provenance = findDirectLinkToVille(villeFrom, head);
       else
       {
           getLastProvenance(to)->next = createProvenance();
           getLastProvenance(to)->provenance = findDirectLinkToVille(villeFrom, head);
       }
    }
}

void findAndAddNew(Provenances* origin, Provenances* toCompare)
{
    Provenances* tmp;
    
    tmp = toCompare;
        while(tmp != NULL)
        {
            if(!chercheProvenance(tmp->provenance->nomVille,origin)) // si ça n'existe pas
                addProvenance(origin,tmp->provenance); // On ajoute la provenance
            tmp = tmp->next;
        }
}