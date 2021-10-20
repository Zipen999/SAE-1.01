#include <stdio.h>
#include <stdlib.h>
#include "sae.h"
void Saisie (void)
{
	int i,n;
	printf("combien d'article : ");
	scanf("%d", &n );
	int ref[n],qt [n], sds [n];
	float prix[n];
 	for (i=0; i<n; i++)
    	{
     		printf("reference %d : ", i);
     		scanf("%d", &ref[i]);
     		printf("quantité %d : ", i);
     		scanf("%d", &qt[i]);
		printf("Prix %d : ", i);
     		scanf("%f", &prix[i]);
     		printf("seuil de sécurité %d : ", i);
     		scanf("%d", &sds[i]);

	}
	FILE * flot;
	flot=fopen("nom.txt","a");
	if (flot == NULL)
	{
		printf("probleme d'ouverture du fichier \n");
		exit(1);
	}
	for (i=0; i<n; i++)
		fprintf(flot,"%d\t%d\t%.2f\t%d\n",ref[i],qt[i],prix[i],sds[i]);

	fclose(flot);
}

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


void fConsulterStock (int ref[], int qt[],float prix[],int sds[])
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

