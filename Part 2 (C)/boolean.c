#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include "my.h"

bool areVillesEquals(char* nomVille, Ville* ville)
{
    if(ville == NULL)
        return false;
    else
        return (strcmp(ville->nomVille,nomVille) == 0);
}

// return last si n'existe pas et l'adresse si existe
Ville* doVilleExiste(Ville* head, char* nomVille)
{
    Ville* tmp;
    
    tmp = head;
    if(head == NULL)
        return NULL;
    while(tmp->next != NULL)
    {
        if(areVillesEquals(nomVille, tmp))
            return tmp;
        tmp = tmp->next;
    }
    return tmp;       
}

bool chercheProvenance(char* nomProvenance, Provenances* provenances)
{
    Provenances* tmp = provenances;
    while(tmp != NULL)
    {
        if(strcmp(tmp->provenance->nomVille,nomProvenance)==0)
            return true;
        tmp = tmp->next;
    }
    return false;
}

bool areNodesEquals(Node* a, Node*b)
{
    if(a->data == NULL && b->data == NULL)
        return true;
    else if(a->data == NULL && b->data != NULL)
        return false;
    else if(a->data != NULL && b->data == NULL)
        return false;
    else
        return( ((a->data->villeA == b->data->villeA) && (a->data->villeB == b->data->villeB))
              ||((a->data->villeA == b->data->villeB) && (a->data->villeB == b->data->villeA))
              );
}

// return last si n'existe pas et l'adresse si existe
Node* doNodeExiste(Ville* villeDepart, Node* nodeToCompare)
{
    Node* tmp;
    
    tmp = villeDepart->listLien;
    while(tmp->next != NULL)
    {
        if(areNodesEquals(nodeToCompare, tmp))
            return tmp;
        tmp = tmp->next;
    }
    return tmp;
}

void lighter2(Cell* a, Cell* b,Ville** head)
{
    if(a->poid > b->poid)
    {
        a->poid = b->poid;
        giveListProvenances(a->listProvenances, b->listProvenances, head, false);
    }
    else if((a->poid == b->poid) && (a->poid < 2147483646))
        findAndAddNew(a->listProvenances, b->listProvenances);
}

void lighter3(Cell* a, Cell* b,Ville** head)
{
    if(a->poid > b->poid)
    {
        a->poid = b->poid;
        giveListProvenances(a->listProvenances, b->listProvenances, head, false);
    }
}