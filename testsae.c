#include <stdio.h>
#include "sae.h"

void globale (void)
{
	int n;
	n=NbArticle();
	int ref[n],qt[n],sds[n],CodeErr;
	float prix[n];
	char choix;
	CodeErr=fConsulterStock(ref,qt,prix,sds,n);
	printf("\n\nBienvenue a l'application de gestion de stock 'Xtrachaus'\n\n");

	if (CodeErr== -1 || n == -1)
		printf("!! Vous n'avez pas encore créer de stock veuillez créer un stock avant de faire n'importe qu'elle manipulation !! \n\n");

	printf("Créer un stock: 'c'| Afficher le stock: 'o'| Etat du stock: 'e'| Faire le devis d'une commade: 'd'| Récapitulatif des ventes: 'r'| Approvisionnement: 'a'| \nSupprimer un article:'s'| Rechercher un article avec n° ref: 'n'| Modifier une valeur de l'article :'m'\n\n");

	printf("Que voulez vous faire(votre choix): ");
	scanf("%c", &choix);

	if (choix =='c')
		fCreerStock();
	if (choix =='o')
		fAfficherStock(ref,qt,prix,sds,n);
	if (choix =='e')
		{
			fAfficherStock(ref,qt,prix,sds,n);
			printf("\n");
			fEtatStock(ref,qt,prix,sds,n);
		}
	/*if (choix =='d')
		fDevis();
	if (choix =='r')
		fVentes();*/
	if (choix =='a')
		fAppro();
	/*if (choix =='s')
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
