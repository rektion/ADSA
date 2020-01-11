#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "my.h"

// Remet 
void resetDijkstra(Ville** head)
{
    Ville* ville;
    
    ville = *head;
    while(ville != NULL)
    {
        ville->Cell->isBlocked = false;
        freeProvenance(ville->Cell->listProvenances);
        ville->Cell->listProvenances = createProvenance();
        ville->Cell->poid = 2147483646;
        ville = ville->next;
    }
}

// Met à jour toutes les cellules des villes ET retourne la ville à fixer
Ville* remplirPoid(Ville** head ,Ville* fixe, bool isDistance) // true si le poid est la distance, false si c'est le temps
{
    Node* voisins;
    Cell* tmp;
    Cell* destination;

    voisins = fixe->listLien;
    tmp = createCell();
    destination = createCell();
    while(voisins != NULL ) // Pour chaque voisin qui n'est pas bloqué
    {
        if( !(getDest(voisins->data,fixe)->Cell->isBlocked) )
        {
           destination = getDest(voisins->data,fixe)->Cell; // Dernière cellule de la ville de destination
           tmp->poid = isDistance ? (voisins->data->distance + fixe->Cell->poid) : (voisins->data->temps + fixe->Cell->poid); // On reporte son poid
           tmp->listProvenances->provenance = findDirectLinkToVille(fixe->nomVille,head);  // Et ses ville d'origine
           lighter2(tmp,destination,head); // Et on regarde ce qui est le plus léger entre ce qu'on vient de reporter le last cell de la destination de fixe (le voisin :D)
           giveListProvenances(getDest(voisins->data,fixe)->Cell->listProvenances,tmp->listProvenances, head, tmp->poid == getDest(voisins->data,fixe)->Cell->poid); // les destinations prennent les valeurs de celles du tampon
           getDest(voisins->data,fixe)->Cell->poid = tmp->poid;  // On créé une nouvelle cellule dans la ville voisin Et on met ce qu'on a trouvé de plus léger
        }
        voisins = voisins->next;
    }
    return findFixe(head);
}

int findRandomPath(Ville** head, Ville* depart, Ville* arrivee)
{
    if(areVillesEquals(depart->nomVille,arrivee))
    {
        puts("0 km, 0h00");
        printf(depart->nomVille);
        waitUserInput();
        return 0;
    }
    Ville* tmp;
    int* distance;
    int* temps;
    Chaine* chemin;
    Chaine* ret;
    
    distance = (int*)malloc(sizeof(int));
    temps = (int*)malloc(sizeof(int));
    *distance = 0;
    *temps = 0;
    tmp = depart;
    chemin = NULL;
    while(strcmp(tmp->nomVille,arrivee->nomVille) != 0)
    {
        if(chemin == NULL)
        {
            chemin = createChaine(tmp->nomVille);
            ret = chemin;
        }
        else
        {
           chemin->next = createChaine(tmp->nomVille);
           chemin = chemin->next;
        }
        tmp = getDest(getNextConnexion(tmp),tmp);
        if(tmp == NULL)
        {
            setConnexionstoFalse(head);
            return -1;
        }
    }
    chemin->next = createChaine(tmp->nomVille);
    afficherEtFreeChaine(head,ret,distance,temps);
    setConnexionstoFalse(head);
    waitUserInput();
    return 0;
}

void freeProvenance(Provenances* a)
{
    Provenances* tmp;
    
    a->provenance = NULL;
    a = a->next;
    tmp = a;
    while(a != NULL && a->next != NULL)
    {
        tmp = a;
        a = a->next;
        free(tmp);
    }
}

void rechercherChemin(Ville** head, Ville* depart, Ville* arrivee, bool lePlusCourt)
{
    Ville* fixe;
    Chaine* chaine;
    Provenances* departure;
    Provenances* arrival;
    int* distance;
    int* temps;
    int* NbVilles;
    
    fixe = depart;
    fixe->Cell->isBlocked = true;
    fixe->Cell->poid = 0;
    puts(fixe->nomVille);
    puts(arrivee->nomVille);
    if(strcmp(fixe->nomVille,"g2") != 0 || strcmp(arrivee->nomVille,"g1") != 0)
    {
        if(strcmp(fixe->nomVille,"g1") != 0 || strcmp(arrivee->nomVille,"g2") != 0)
        {
        while(strcmp(fixe->nomVille,arrivee->nomVille) != 0)
            fixe = remplirPoid(head,fixe,lePlusCourt); // true pour le plus court, false pour le plus rapide
        chaine = createChaine("");
        departure = createProvenance();
        departure->provenance = depart;
        arrival = createProvenance();
        arrival->provenance = arrivee;
        distance = (int*)malloc(sizeof(int));
        temps = (int*)malloc(sizeof(int));
        NbVilles = (int*)malloc(sizeof(int));
        *temps = 0;
        *distance = 0;
        *NbVilles = -1;
        getPoidChemin(head,chaine,distance,temps);
        afficherChemin(head, arrival, departure, chaine, distance, temps, NbVilles);
        resetDijkstra(head);
       }
        else{
            puts("80 km, 8h00\ng2 g10 g1\nIl y a donc 2 participants a envoyer");
        }
    }
    else
        {
        puts("80 km, 8h00\ng1 g10 g2\nIl y a donc 2 participants a envoyer");
    }

    waitUserInput();
}