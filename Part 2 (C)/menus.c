#include <stdio.h>
#include <stdlib.h>
#include "my.h"

int AfficheMenu2(Ville** head, Ville* depart, Ville* arrivee) // return -1 si l'utilisateur veut modifier les villes
{
    system("clear");
    printMenu();
    fputs("Ville de depart : ",stdout);
    puts(depart->nomVille);
    fputs("Ville d'arrivée : ",stdout);
    puts(arrivee->nomVille);
    putchar('\n');
    puts("Appuyez sur :");
    puts("1 Pour afficher un chemin possible");
    puts("2 Pour aficher le chemin le plus rapide (ou les plus rapides si égalité)");
    puts("3 Pour afficher le chemin le plus court (ou les plus courts si égalité)");
    puts("Un autre chiffre pour modifier les villes de départ et d'arrivée");
    puts("Si votre fichier est joker.csv, afficher le chemin le plus rapide est inutile vu que le poids est la distance");
    int variable;
    variable = 0;
    scanf("%d",&variable);
    switch (variable) 
    {
    case 1 :
    if(findRandomPath(head,depart,arrivee)==-1)
        rechercherChemin(head,arrivee,depart,true);
    return 0;

    case 2 :
    rechercherChemin(head,arrivee,depart,false);
    return 0;

    case 3 :
    rechercherChemin(head,arrivee,depart,true);
    return 0;

    default: 
    return -1;
    }
}

int AfficheMenu1_5(Ville** head) // return -1 si l'utilisateur veut quitter le programme et -8 s'il s'est trompé et 0 pour modifier lezs villes
{
    puts("Voici la liste des villes\n");
    afficherVilles(head);
    int i;
    Ville* depart;
    
    puts("Veuillez saisir le numéro correspondant à votre ville de départ (saisissez 0 pour quitter)\n");
    scanf("%d",&i);
    if(i==0)
        return -1;
    depart = trouveIemeVille(head,i);
    puts("Veuillez saisir le numéro correspondant à votre ville de d'arrivée (saisissez 0 pour quitter)\n");
    scanf("%d",&i);
    if(i==0)
        return -1;
    Ville* arrivee = trouveIemeVille(head,i);
    if(depart == NULL || arrivee == NULL)
        return -8;
    while(AfficheMenu2(head,depart,arrivee)==0)
    {
        waitUserInput();
        system("clear");
    }
    return 0;
}

int afficheMenu1(void)
{
    printMenu();
    puts("Ce programme est pour la partie 2 seulement. Pour la partie 1,3 et 4, veuillez lancer le programme C#\n");
    puts("Veuillez saisir joker.csv pour charger le fichier de distances de Gotham par rapport aux autres villes\n");
    puts("Veuillez saisir connexions.csv pour charger le fichier de distances de France pour étendre le chaos\n");
    char* chemin = (char*)malloc(sizeof(char)*128);
    scanf("%s",chemin);
    Ville* or;
    Ville** head;
    
    or = NULL;
    head = &or;
    if(openCsv(head,chemin) == -8)
         return -1;
    free(chemin);
    int a;
    while(1)
    {
        a = AfficheMenu1_5(head);
        if(a == -1)
        {
            freeListVilles(*head);
            return 0;
        }
        else if(a == -8)
            puts("Erreur lors de la sélection des villes");
    }
}

void initialise(void)
{
    int a;
    
    a = afficheMenu1();
    if(a == -1)
        puts("FICHIER INTROUVABLE !");
    else if(a == -2)
        puts("Le numéro correspondant aux villes de départ/arrivée est erronné");
    else if(a == 0)
        puts("Appuyez sur une touche pour quitter");
    waitUserInput();
    waitUserInput();
}