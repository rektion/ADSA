#include <stdio.h>
#include "my.h"
#include <stdlib.h>
#include <string.h>

// Taille du char*
int getStrLength(const char* str)
{
    if(str == NULL)
        return 0;
    int i;
    
    i = 0;
    while(str[i] != '\0')
        i++;
    return i;
}

// Va convertir par exemple 1:12 en 72 minutes
int getTime(char* time)
{
    if(time == NULL)
        return -1;
    int taille;
    char* heures;
    char* minutes;
    int i;
    int j;
    
    taille = getStrLength(time);
    heures = (char*)malloc(sizeof(char)*taille);
    minutes = (char*)malloc(sizeof(char)*taille);
    j = 0;
    for(i = 0; i < taille && time[i] != ':'; i++)
        heures[i] = time[i]; 
    for(i+=1; i < taille; i++)
    {
        minutes[j] = time[i];
        j++;
    }
    i = atoi(heures)*60;
    j = atoi(minutes);
    free(heures);
    free(minutes);
    return (i+j);
}

// Calcule le nombre de fois qu'un caractère séparateur apparait dans un char*
int ComptenombreCaractere(char* str,char caractere)
{
	int compteur=0;
	for(int i=0;i<strlen(str);i++)
	{
		if(str[i]==caractere)
		{
			compteur++;
		}
	}
	return compteur;
}

// Prend un paramètre un char* et retourne les sub char* entre les caractères séparateurs
char** strCut(char* str, char separateur)
{
	int k;
        int j;
        int nbre_lignes;
        j = 0;
        k = 0;
	char** tableau=NULL;
	
        nbre_lignes = 1 + ComptenombreCaractere(str,separateur);
	tableau = (char**)malloc(sizeof(char*)*nbre_lignes);  // Nombre de lignes
	for(int i=0;i<nbre_lignes;i++)
		tableau[i]=(char*)malloc(strlen(str)*sizeof(char)); //on ne connait pas la taille de chaque mot; donc on crée un tableau plus grand.
	for(int i=0;i<strlen(str);i++)
	{
            if(str[i]==separateur)
            {
		tableau[k][j]='\0';
		k++;
                j = -1;
            }
            else
		tableau[k][j]=str[i];
            j++;
	}
	return tableau;
}

// Retourne le dernier chaine*
Chaine* getLastChaine(Chaine* chaine)
{
    Chaine* tmp;
    
    tmp = chaine;
    if(chaine == NULL)
        return chaine;
    while(tmp->next != NULL)
        tmp = tmp->next;
    return tmp;
}