#include <stdio.h>
#include <stdlib.h>
#include "sae.h"
void fCreerStock (void)
{
	int i,n;
	printf("Combien d'articles : ");
	scanf("%d", &n );
	while(n<=1)
		{
			printf("Il faut au moins 1 article!\n");
			printf("Veuillez réesayer: ");
			scanf("%d",&n);
			if(n>0)
				break;
		}
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
		fVerif(ref,i);
     		printf("quantité %d : ", i);
     		scanf("%d", &qt[i]);
		fVerif(qt,i);
		printf("Prix %d : ", i);
     		scanf("%f", &prix[i]);
		fVerifReal(prix,i);
     		printf("seuil de sécurité %d : ", i);
     		scanf("%d", &sds[i]);
		fVerif(sds,i);

	}
	FILE * flot;
	flot=fopen("nom.txt","a");
	if (flot == NULL)
	{
		printf("Probleme d'ouverture du fichier \n");
		exit(1);
	}
	for (i=0; i<n; i++)
		fprintf(flot,"%d\t%d\t%.2f\t%d\n",ref[i],qt[i],prix[i],sds[i]);

	fclose(flot);
}

void fVerif(int tab[],int i)
{
	while(tab[i]<0)
	{
		printf("Valeur inférieur à 0!\n");
		printf("Veuillez réessayer: ");
		scanf("%d",& tab[i]);
			if(tab[i]>=0)
				break;
	}
}
void fVerifReal(float tab[],int i)
{
	while(tab[i]<=0)
	{
		printf("Valeur inférieur à 0.01!\n");
		printf("Veuillez réessayer: ");
		scanf("%f",& tab[i]);
			if(tab[i]>=0)
				break;
	}
}

int NbArticle (void)
{
	int n;
	FILE * nombre;
	nombre=fopen("Nombre_d'article.txt","r");
	if (nombre == NULL)
		return -1;
	fscanf(nombre,"%d",&n);
	fclose(nombre);
	return n;
}

int fConsulterStock (int ref[],int qt[],float prix[],int sds[],int n)
{
	int i;
	FILE * flot;
	flot=fopen("nom.txt","r");
	if (flot == NULL)
		return -1;
	while (!feof(flot))
		for (i=0 ; i<n ; i++)
			fscanf(flot,"%d%d%f%d",& ref[i],& qt[i],& prix[i],& sds[i]);
	fclose(flot);
}

void fAfficherStock (int ref[],int qt[],float prix[],int sds[],int n)
{
	int i;
	printf("\nReference:\tQuantite:\tPrix:\tSeuil de securite:\n");
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

/*void fAppro (int ref[],int qt[],float prix[],int sds[],int n)
{
	
}*/

