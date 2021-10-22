#include <stdio.h>
#include <stdlib.h>
#include "sae.h"
void fCreerStock (void)
{
	int i,n;
	printf("combien d'article : ");
	scanf("%d", &n );
		FILE * nombre;
		nombre=fopen("Nombre_d'article.txt","w");
		if (nombre == NULL)
		{
			printf("probleme d'ouverture du fichier \n");
			exit(1);
		}
			fprintf(nombre,"%d",n);

		fclose(nombre);
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

int NbArticle (void)
{
	int n;
	FILE * nombre;
	nombre=fopen("Nombre_d'article.txt","r");
	if (nombre == NULL)
	{
		printf("probleme d'ouverture du fichier \n");
		exit(1);
	}
	fscanf(nombre,"%d",&n);
	fclose(nombre);
	return n;
}

void fConsulterStock (int ref[],int qt[],float prix[],int sds[],int n)
{
	int i;
	FILE * flot;
	flot=fopen("nom.txt","r");
	if (flot == NULL)
	{
		printf("probleme d'ouverture du fichier \n");
		exit(1);
	}
	while (!feof(flot))
		for (i=0 ; i<n ; i++)
			fscanf(flot,"%d%d%f%d",& ref[i],& qt[i],& prix[i],& sds[i]);
	fclose(flot);
}

void fAfficherStock (int ref[],int qt[],float prix[],int sds[],int n)
{
	int i;
	printf("Reference:\tQuantite:\tPrix:\tSeuil de securite:\n");
	for (i=0 ; i<n ; i++)
		printf("%d\t\t%d\t\t%.2f\t\t%d\n" ,ref[i], qt[i], prix[i], sds[i]);
}

void fEtatStock(int ref[],int qt[],float prix[],int sds[],int n)
{
	int i,m;
	for(i=0;i<n;i++)
	{
		m=sds[i]-qt[i];
		if(qt[i]<sds[i])
			printf("Le produit de référence n°%d doit être approvisionner de %d article(s)\n",ref[i],m);
		if(qt[i]>sds[i])
			printf("%d produit(s) est(sont) au dessus du seuil de sécurité.\n", i+1);
	}
	
}


