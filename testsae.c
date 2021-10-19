#include <stdio.h>
#include "sae.h"

void globale (void)
{
	char choix;
	printf("\n\nBienvenue a l'application de gestion de stock 'Xtrachaus'\n\n");
	printf("Créer un stock: 'c'| Consulter le stock: 'o'| Etat du stock: 'e'| Faire le devis d'une commade: 'd'| Récapitulatif des ventes: 'r'| Approvisionnement: 'a'| \nSupprimer un article:'s'| Rechercher un article avec n° ref: 'n'| Modifier une valeur de l'article :'m'\n\n");

	printf("Que voulez vous faire(votre choix): ");
	scanf("%c", &choix);

	/*if (choix =='c')
		fCreerStock();
	if (choix =='o')
		fConsulterStock();*/
	if (choix =='e')
		fEtatStock();
	/*if (choix =='d')
		fDevis();
	if (choix =='r')
		fVentes();
	if (choix =='a')
		fAppro();
	if (choix =='s')
		fSupp();
	if (choix =='n')
		fRecherche();
	if (choix =='m')
		fModifier();*/
}

	
int main (void)
{

	globale();
	return 0;
}
