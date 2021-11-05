#include <stdio.h>
#include "sae.h"

void globale (void)
{
	int n,i;
	n=NbArticle();
	int ref[n],qt[n],sds[n],CodeErr,code,CodeSup;
    int qtvendu[n];
    for (i=0 ; i<n ; i++)
        qtvendu[i]=0;
	float prix[n];
	char choix;
	CodeErr=fConsulterStock(ref,qt,prix,sds,n);
	printf("\n\nBienvenue a l'application de gestion de stock 'Xtrachaus'\n\n");

	if (CodeErr== -1 || n == -1)
		printf("!! Vous n'avez pas encore créer de stock veuillez créer un stock avant de faire n'importe quel manipulation !! \n\n");

	printf("Créer un stock: 'c'| Afficher le stock: 'o'| Etat du stock: 'e'| Faire le devis d'une commade: 'd'| Récapitulatif des ventes: 'r'| Approvisionnement: 'a'| \nSupprimer un article:'s'| Rechercher un article avec n° ref: 'n'| Modifier l'article :'m'| Ajouter un article: 't'\n\n");

	printf("Que voulez vous faire(votre choix): ");
	scanf("%c%*c", &choix);
	if (choix =='c')
		fCreerStock();
	if (choix =='o')
		fAfficherStock(ref,qt,prix,sds,n);
	if (choix =='e')
		fEtatStock(ref,qt,prix,sds,n);
	if (choix =='d')
		fDevis(ref,qt,prix,sds,n,qtvendu);
	/*if (choix =='r')
    {
		fGererRecap(ref,n,qtvendu,qtav);
	}*/
    if (choix =='a')
	{
		fAfficherStock(ref,qt,prix,sds,n);
		code=fAppro(ref,qt,prix,sds,n);
		if(code==-1)
			printf("Erreur, l'approvisionement ne peut pas s'effectuer.\n");
        else
            printf("Approvisionement éffectué. \n");
		printf("\n");
		fAfficherStock(ref,qt,prix,sds,n);
	}
	if (choix =='s')
	{
        CodeSup=fSuppression(ref,qt,prix,sds,n);
        if(CodeSup!=-1)
            printf("Suppression éffectué. \n");
        else
			printf("Erreur, la suppression ne peut pas s'effectuer.\n");
	}
	if (choix =='n')
		{
			code=fRecherche(ref,n);
			if (code!=-1)
            {
                printf("\nReference:\tQuantite:\tPrix:\tSeuil de securite:\n");
				printf("%d\t\t%d\t\t%.2f\t\t%d\n" ,ref[code], qt[code], prix[code], sds[code]);
			}			
			else 
				printf("La réference n'existe pas\n");
		}

	if (choix =='t')
    {
		code==fAjouter(ref,qt,prix,sds,n);
		if(code==-1)
			printf("Erreur, l'ajout ne peut pas s'effectuer.\n");
        else
            printf("Ajout éffectué. \n");
    }
	if (choix =='m')
    {
		code=fModifier(ref,qt,prix,sds,n);
		if(code==-1)
			printf("Erreur, la modification ne peut pas s'effectuer.\n");
        else
            printf("Modification éffectué. \n");
    }
}

	
int main (void)
{

	globale();
	return 0;
}
