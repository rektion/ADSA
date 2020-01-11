#include <stdio.h>
#include <stdlib.h>
#include "my.h"

void addVille(Ville** last, char* nomVille)
{
    if(*last == NULL) // Cas d'initialisation : premier maillon = NULL
        *last = createVille(nomVille);
    else
        (*last)->next = createVille(nomVille);
}

void addNode(Node* last)
{
    last->next = createNode();
}

void addLine(Ville** head, char* nomVille1, char* nomVille2, char* distanceC, char* tempsC) // Prend les 4 éléments de la ligne et créé les villes/noueds/connexions
{
    Ville* ville1;
    Ville* ville2;
    int distance;
    int temps;
    Node* nodeToCompare1;
    Node* nodeToCompare2;
    
    distance = atoi(distanceC);
    temps = getTime(tempsC);
    ville1 = cherchePuisAjouteVille(head,nomVille1);
    ville2 = cherchePuisAjouteVille(head,nomVille2);
    nodeToCompare1 = createNode();
    nodeToCompare2 = createNode();
    nodeToCompare1->data = createConnexion(ville1,ville2,distance,temps);
    nodeToCompare2->data = createConnexion(ville1,ville2,distance,temps);
    connectConnexion(nodeToCompare1->data,cherchePuisAjouteNoeud(ville1,nodeToCompare1),cherchePuisAjouteNoeud(ville2, nodeToCompare2));
}

void addProvenance(Provenances* origin, Ville* toAdd)
{
    Provenances* last;
    
    last = getLastProvenance(origin);
    last->next = createProvenance();
    last->next->provenance = toAdd;
}