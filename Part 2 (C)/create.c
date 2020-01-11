#include <stdio.h>
#include "my.h"
#include <stdlib.h>

Ville* createVille(char* nomVille)
{
    Ville* ville;
    
    ville = (Ville*)malloc(sizeof(Ville));
    ville->listLien = NULL; // On créé le head des noeuds de la ville
    ville->Cell = createCell();
    ville->next = NULL;
    ville->nomVille = nomVille;
    return ville;
}

Connexion* createConnexion(Ville* a, Ville* b, int distance, int temps)
{
    Connexion* connexion;
    
    connexion = (Connexion*)malloc(sizeof(Connexion));
    connexion->distance = distance;
    connexion->temps = temps;
    connexion->villeA = a;
    connexion->villeB = b;
    connexion->isUsed = false;
    return connexion;
}

Node* createNode(void)
{
    Node* node;
    
    node = (Node*)malloc(sizeof(Node));
    node->next = NULL;
    node->data = NULL;
    return node;
}

Chaine* createChaine(char* texte)
{
    Chaine* chaine;
    
    chaine = (Chaine*)malloc(sizeof(Chaine));
    chaine->texte = texte;
    chaine->next = NULL;
    return chaine;
}

Provenances* createProvenance(void)
{
    Provenances* provenance;
    
    provenance = (Provenances*)malloc(sizeof(Provenances));
    provenance->next = NULL;
    provenance->provenance = NULL;
    return provenance;
}

Cell* createCell(void)
{
    Cell* cell;
    
    cell = (Cell*)malloc(sizeof(Cell));
    cell->isBlocked = false;
    cell->listProvenances = createProvenance();
    cell->poid = 2147483646;
    return cell;
}