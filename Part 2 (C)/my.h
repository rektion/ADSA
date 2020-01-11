/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   my.h
 * Author: Time
 *
 * Created on 13 décembre 2018, 18:37
 */

#include <stdbool.h>

#ifndef MY_H
#define MY_H

typedef struct s_node Node;
struct s_node
{
   struct s_connexion* data;
   struct s_node* next;
};

typedef struct s_ville Ville;
struct s_ville
{
    char* nomVille; // nom de la ville
    Ville* next; // Pointeur vers la ville suivante
    struct s_node* listLien; 
    struct s_cell* Cell;
};

typedef struct s_connexion Connexion;
struct s_connexion
{
    struct s_ville* villeA; //nom de la ville
    struct s_ville* villeB;  //la ville
    int temps;
    int distance;
    bool isUsed;
};

typedef struct s_cell Cell;
struct s_cell
{
    struct s_provenances* listProvenances;
    int poid;
    bool isBlocked;
};

typedef struct s_provenances Provenances;
struct s_provenances
{
    Ville* provenance;
    Provenances* next;
};

typedef struct s_chaine Chaine;
struct s_chaine
{
    char* texte;
    Chaine* next;
};

void freeListVilles(Ville*);

char* fromMinutesToHeures(int);

void connectConnexion(Connexion*,Node*, Node*);
Chaine* duppliquerChaine(Chaine*);
int* duppliquerIntEtoile(int*);
int openCsv(Ville**, char*);
void setConnexionstoFalse(Ville**);

int findRandomPath(Ville**, Ville*, Ville*);
void freeProvenance(Provenances*);
void rechercherChemin(Ville**, Ville*, Ville*, bool);

bool areVillesEquals(char*, Ville*);
Ville* doVilleExiste(Ville*, char*);
bool chercheProvenance(char*, Provenances*);
bool areNodesEquals(Node*, Node*);
Node* doNodeExiste(Ville*, Node*);
void lighter2(Cell*,Cell*,Ville**);
void lighter3(Cell*,Cell*,Ville**);

void printMenu(void);
void waitUserInput(void);
void afficherChemin(Ville **, Provenances *, Provenances *, Chaine *, int *, int *, int *pInt);
void afficherEtFreeChaine(Ville**, Chaine*, int*, int*);
void afficherVilles(Ville**);

Ville* getDest(Connexion*, Ville*);
Ville* findDirectLinkToVille(char*, Ville**);
Ville* findFixe(Ville**);
Ville* trouveIemeVille(Ville**, int);

void getPoidChemin(Ville**, Chaine*, int*, int*);
void giveListProvenances(Provenances*, Provenances*, Ville**, bool);
Provenances* getLastProvenance(Provenances*);
Connexion* getNextConnexion(Ville*);
void getPoid(Ville**, char*, char*, int*, int*);

void addVille(Ville**, char*);
void addNode(Node*);
void addLine(Ville**, char*, char*, char*, char*);
void addProvenance(Provenances*, Ville*);

Ville* createVille(char*);
Connexion* createConnexion(Ville*, Ville*, int, int);
Node* createNode(void);
Chaine* createChaine(char*);
Provenances* createProvenance(void);
Cell* createCell(void);

Ville* cherchePuisAjouteVille(Ville**, char*);
Node* cherchePuisAjouteNoeud(Ville*, Node*);
void cherchePuisAjouteVilleDansProvenance(Provenances*,char*, Ville**);
void findAndAddNew(Provenances*, Provenances*);

void initialise(void);

int getStrLength(const char*);
int getTime(char*);
char** strCut(char*, char);
Chaine* getLastChaine(Chaine*);

#endif /* MY_H */

