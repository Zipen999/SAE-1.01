#include <stdio.h>
#include <stdlib.h>
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
	printf("#########################################################################\n");
	printf("#\t\t\t\t\t\t\t\t\t#\n");
	printf("#\tBienvenue a l'application de gestion de stock 'Xtrachaus'\t#\n");
	printf("#\t\t\t\t\t\t\t\t\t#\n");

	if (CodeErr== -1 || n == -1)
	{
		printf("#########################################################################\n");
		printf("#\t\t\t\t\t\t\t\t\t#\n");
		printf("#\t!! Vous n'avez pas encore créer de stock, veuillez créer\t#\n#\tun stock avant de faire n'importe quel manipulation !!\t\t#\n");
		printf("#\t\t\t\t\t\t\t\t\t#\n");
	}
	printf("#########################################################################\n");
	printf("#\tCreer un stock: 'c'\t\t\t\t\t\t#\n#\tAfficher le stock: 'o'\t\t\t\t\t\t#\n#\tEtat du stock: 'e'\t\t\t\t\t\t#\n#\tFaire le devis d'une commade: 'd'\t\t\t\t#\n#\tRecapitulatif des ventes: 'r'\t\t\t\t\t#\n#\tApprovisionnement: 'a'\t\t\t\t\t\t#\n#\tSupprimer un article:'s'\t\t\t\t\t#\n#\tRechercher un article avec n° ref: 'n'\t\t\t\t#\n#\tModifier l'article :'m'\t\t\t\t\t\t#\n#\tAjouter un article: 't'\t\t\t\t\t\t#\n");
	printf("#########################################################################\n");
	printf("#\tSUPPRIMER TOUTES LES DONNEES DE L'ENTREPRISE : 'X'\t\t#\n");
	printf("#########################################################################\n\n");
	printf("Que voulez vous faire: ");
	scanf("%c%*c", &choix);

	if (choix =='c')
	{
		CodeErr=fCreerStock();
		if(CodeErr!=1)
		    printf("Stock creer avec succees.\n");
		else
		    printf("Echec de la creation du stock.\n");
	}
	
	if (choix =='o')
		fAfficherStock(ref,qt,prix,sds,n);

	if (choix =='e')
		fEtatStock(ref,qt,prix,sds,n);

	if (choix =='d')
	{
		CodeErr=fDevis(ref,qt,prix,sds,n,qtvendu);
		if(CodeErr!=1)
		    printf("Devis creer avec succees.\n");
		else
		    printf("Echec de la creation du Devis.\n");
	}
	
	if (choix =='r')
   	{
		CodeErr=fConsulterRecap(ref,qtvendu,n);
		if(CodeErr==-1)
		{
		    printf("Echec de l'ouverture du fichier recapitulatif des ventes.\n");
		    exit(1);
		}
		fAffichageRecap(ref,qtvendu,n);
	}

   	if (choix =='a')
	{
		fAfficherStock(ref,qt,prix,sds,n);
		code=fAppro(ref,qt,prix,sds,n);
		if(code==-1)
			printf("Erreur, l'approvisionement ne peut pas s'effectuer.\n");
       		else
		{
		   	printf("\nApprovisionement éffectué. \n");
			printf("\n");
			fAfficherStock(ref,qt,prix,sds,n);
		}
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
		code=fAjouter(ref,qt,prix,sds,n);
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
	if(choix=='x')
		Clean();
}

	
int main (void)
{

	globale();
	return 0;
}
