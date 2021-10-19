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
