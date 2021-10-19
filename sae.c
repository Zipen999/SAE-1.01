#include <stdio.h>
#include "sae.h"
void fEtatStock(void)
{
	int i,m;
	fConsulterStock(ref,qte,prix,seuil);
	for(i=0;i<n;i++)
	{
		if(qte[i]<=seuil[i])
			m=seuil[i]-ref[i];
			printf("Le produit de référence n°%d doit être approvisionner de %d article(s)\n",ref[i],m);
		if(qte[i]>seuil[i])
			printf("%d produit(s) est(sont) au dessus du seuil de sécurité.\n", i);
	}
	
}
#include <stdio.h>
#include <stdlib.h>
#include "sae.h"
int createstock(void)
{
	int n[],i,q[],s[];
	float p[i];
	FILE * flot;
	flot=fopen("stock.txt","a");
	if (flot == NULL)
	{
		printf("pb d'ouverure du fichier en lecture \n");
		exit(1);
	}
	for (i=0;i++)
	{
		printf("saisissez les valeurs %d %d %f %d ",&n,&q,&p,&s);
	}
	fclose(flot);
}


void affichagestock (int ref[], int qt[],float prix[],int sds[])
{
	int i;
	FILE * flot;
	flot=fopen("nom.txt","r");
	if (flot == NULL)
	{
		printf("probleme d'ouverture du fichier \n");
		return -1;
	}
	fscanf(flot,"%d%d%f%d",&ref,&qt,&prix,&sds);
	while (!feof(flot))
	{
		fscanf(flot,"%d%d%f%d",&ref,&qt,&prix,&sds);
	}
	printf("reference de produit \t quantite \t prix unitaire \t seuil de securite ");
	for (i=0 ; i<n ; i++)
	print("%d \t %2f \t %c \n" , ref[i],qt [i], prix [i], sds [i]);
	fclose(flot);
	
}

