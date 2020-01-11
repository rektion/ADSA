#include <stdbool.h>
#include <stdio.h>
#include "my.h"
#include <string.h>

void getPoidChemin(Ville** head, Chaine* chaine, int* distance, int* temps)
{
    while(chaine->next != NULL)
    {
        getPoid(head,chaine->texte, chaine->next->texte, distance, temps);
        chaine = chaine->next;
    }
}

void giveListProvenances(Provenances* to, Provenances* from, Ville** head, bool mustAdd)
{
    if(mustAdd)
    {
      while(from->next != NULL)
      {
         cherchePuisAjouteVilleDansProvenance(to,from->provenance->nomVille,head);
         from = from->next;
      }
    cherchePuisAjouteVilleDansProvenance(to,from->provenance->nomVille,head);
    }
    else
    {
      freeProvenance(to);
      while(from->next != NULL)
      {
         cherchePuisAjouteVilleDansProvenance(to,from->provenance->nomVille,head);
         from = from->next;
      }
    cherchePuisAjouteVilleDansProvenance(to,from->provenance->nomVille,head);
    }
}

Provenances* getLastProvenance(Provenances* provenance)
{
    Provenances* tmp;
    
    tmp = provenance;
    if(tmp == NULL)
        return NULL;
    
    while(tmp->next != NULL)
        tmp = tmp->next;
    return tmp;
}

// isUsed will be true
Connexion* getNextConnexion(Ville* ville)
{
    Node* lien;
    
    lien = ville->listLien;
    while(lien->data->isUsed)
    {
        if(lien == NULL)
        {
            ville = ville->next;
            if(ville == NULL)
                return NULL;
            lien = ville->listLien;
        }
        else
        {
            lien = lien->next;
            if(lien==NULL)
                return NULL;
        }
    }
    lien->data->isUsed = true;
    return (lien->data);
}

void getPoid(Ville** head, char* a, char* b, int* distance, int* temps)
{
    Ville* ville = *head;
    Node* noeud;
    char* tmp;
    
    while(ville != NULL)
    {
    if(areVillesEquals(a,ville) || areVillesEquals(b,ville))
    {
        noeud = ville->listLien;
        tmp = areVillesEquals(a,ville) ? b : a; // tmp est ce que tu vas chercher dans les connexions de ville
        while( strcmp(getDest(noeud->data,ville)->nomVille,tmp) != 0)
        {
            noeud = noeud->next;
            if(noeud == NULL)
                return;
        }
        *distance += noeud->data->distance;
        *temps += noeud->data->temps;
        return;
    }
    ville = ville->next;
    }
}