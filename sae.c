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

void fVerifVal(int val)
{
	while(val<0)
	{
		printf("Valeur inférieur à 0!\n");
		printf("Veuillez réessayer: ");
		scanf("%d",& val);
			if(val>=0)
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
    fAfficherStock(ref,qt,prix,sds,n);
	int i,m;
	for(i=0;i<n;i++)
	{
		m=sds[i]-qt[i];
		if(qt[i]<sds[i])
			printf("Le produit de référence n°%d doit être approvisionner de %d article(s)\n",ref[i],m);
		if(qt[i]>sds[i])
			printf("Etat produit ref n°%d OK\n",ref[i]);
		if(qt[i]=sds[i])
			printf("Produit ref n°%d est au seuil de securite.\n",ref[i]);
	}
}

int fRecherche (int ref[],int n)
{
	int i,nref;
	printf("Donner le N° de reference:");
	scanf("%d",&nref);
	fVerifVal(nref);
	for (i=0;i<n;i++)
		if (ref[i]==nref)
			return i;
	return -1;
}

int fRecherche2 (int ref[],int n,int nref)
{
	int i;
	for (i=0;i<n;i++)
		if (ref[i]==nref)
			return i;
	return -1;
}

int fAppro (int ref[],int qt[],float prix[],int sds[],int n)
{
	int val, m,code;
	printf("Entrer la référence du produit que vous voulez approvisionner\n");
	val=fRecherche(ref,n);
		if(val==-1)
        {		
        	printf("Reference non éxistante.\n");
            return -1;
        }
	printf("Entrer la quantité approvisinné:");
	scanf("%d",& m);
	fVerifVal(m);
	qt[val]=qt[val]+m;
	code=fEnreg(ref,qt,prix,sds,n);
	if(code==-1)
		return -1;
}

int fEnreg(int ref[],int qt[],float prix[],int sds[],int n)
{
	int i;
	FILE * flot;
	flot=fopen("nom.txt","w");
	if (flot == NULL)
		return -1;
	for (i=0; i<n; i++)
		fprintf(flot,"%d\t%d\t%.2f\t%d\n",ref[i],qt[i],prix[i],sds[i]);
	fclose(flot);
}

int fSuppression (int ref[],int qt[],float prix[],int sds[],int n)
{
	int code,codeErr,i,nref;
	code=fRecherche(ref,n);
	if (code!=-1)
    {
        for(i=code;i<n-1;i++)
	    {
	        ref[i]=ref[i+1];
	        qt[i]=qt[i+1];
	        prix[i]=prix[i+1];
	        sds[i]=sds[i+1];
	    }
        n--;
        FILE * nombre;
	        nombre=fopen("Nombre_d'article.txt","w");
	        if (nombre == NULL)
	        {
		        printf("probleme d'ouverture du fichier \n");
		        exit(1);
	        }
		        fprintf(nombre,"%d",n);
        fclose(nombre);
		fEnregNombre(n);
		codeErr=fEnreg(ref,qt,prix,sds,n);
		if(codeErr==-1)
			return -1;
    }
    else
		return -1;
}
void fEnregNombre(int n)
{
        FILE * nombre;
	        nombre=fopen("Nombre_d'article.txt","w");
	        if (nombre == NULL)
	        {
		        printf("probleme d'ouverture du fichier \n");
		        exit(1);
	        }
		        fprintf(nombre,"%d",n);
        fclose(nombre);
}

int fAjouter(int ref[],int qt[],float prix[],int sds[],int n)
{
	int i,prods,nb,code,nref;
	printf("Combien de produits voulez vous ajouter:");
	scanf("%d",& prods);
	fVerifVal(prods);
	n=NbArticle();
	nb=n+prods;
	for(i=n+1;i<nb;i++)
    {
     	printf("Reference: ");
     	scanf("%d", &ref[i]);
		ref[i]=nref;
		code=fRecherche2(ref,n,nref);
		printf("%d\n",code);
		while(code!=-1)
		{
			printf("La reference existe deja.\n");
			printf("Veuillez resaisir la reference: ");
		 	scanf("%d", &ref[i]);
			ref[i]=nref;
			code=fRecherche2(ref,n,nref);
            printf("%d",code);
			if(code==-1)
				break;
		}
		fVerif(ref,i);
     	printf("Quantité: ");
     	scanf("%d", &qt[i]);
		fVerif(qt,i);
		printf("Prix: ");
     	scanf("%f", &prix[i]);
		fVerifReal(prix,i);
     	printf("Seuil de sécurité: ");
     	scanf("%d", &sds[i]);
		fVerif(sds,i);

	}
	fEnregNombre(nb);
	code=fEnreg(ref,qt,prix,sds,nb);
	if(code==-1)
		return -1;
}

int fModifier(int ref[],int qt[],float prix[],int sds[],int n)
{
	int code;
	fAfficherStock(ref,qt,prix,sds,n);
	printf("Produit que vous voulez modifier. ");
	code=fRecherche(ref,n);
	if(code==-1)
	{
		printf("Reference non éxistante.\n");
		return -1;
	} 	
	printf("reference %d : ", code);
 	scanf("%d", &ref[code]);
	fVerif(ref,code);
 	printf("quantité %d : ", code);
 	scanf("%d", &qt[code]);
	fVerif(qt,code);
	printf("Prix %d : ", code);
 	scanf("%f", &prix[code]);
	fVerifReal(prix,code);
 	printf("seuil de sécurité %d : ", code);
 	scanf("%d", &sds[code]);
	fVerif(sds,code);
	code=fEnreg(ref,qt,prix,sds,n);
	if(code==-1)
		return -1;
}
