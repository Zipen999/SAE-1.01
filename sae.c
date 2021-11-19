#include <stdio.h>
#include <stdlib.h>
#include "sae.h"

int fCreerStock (void)
{
	int i,n;
	CodeSuppression();
	printf("Combien d'articles : ");
	scanf("%d", &n );
	while(n<1)
		{
			printf("Il faut au moins 1 article!\n");
			printf("Veuillez réesayer: ");
			scanf("%d",&n);
			if(n>0)
				break;
		}
		FILE * nombre;
		nombre=fopen("Nombre.txt","w");
		if (nombre == NULL)
		{
			printf("probleme d'ouverture du fichier \n");
		    return-1;
		}
			fprintf(nombre,"%d",n);

		fclose(nombre);
	int ref[n],qt [n], sds [n];
	float prix[n];
 	for (i=0; i<n; i++)
    {
     	printf("reference %d : ", i+1);
     	scanf("%d", &ref[i]);
		fVerif(ref,i);
     	printf("quantité %d : ", i+1);
     	scanf("%d", &qt[i]);
		fVerif(qt,i);
		printf("Prix %d : ", i+1);
     	scanf("%f", &prix[i]);
		fVerifReal(prix,i);
     	printf("seuil de sécurité %d : ", i+1);
     	scanf("%d", &sds[i]);
		fVerif(sds,i);

	}
	FILE * flot;
	flot=fopen("nom.txt","a");
	if (flot == NULL)
	{
		printf("Probleme d'ouverture du fichier \n");
		return-1;
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

void fVerifVal(int *val)
{
	while(*val<=0)
	{
		printf("Valeur inférieur ou egale à 0!\n");
		printf("Veuillez réessayer: ");
		scanf("%d",val);
			if(*val>0)
				break;
	}
}
void fVerifRef(int ref[],int ref2[], int n, int pos)
{
    int j,val;
    val=ref2[pos];
    j=fRecherche2(ref,n,val);
	while(j!=-1)
	{
		printf("Reference deja presente.\n");
		printf("Veuillez réessayer: ");
		scanf("%d",& ref2[pos]);
        val=ref2[pos];
        j=fRecherche2(ref,n,val);
			if(j==-1)
				break;
	}
}

int fRecherche (int ref[],int n)
{
	int i,nref;
	printf("Donner le N° de reference:");
	scanf("%d%*c",&nref);
	fVerifVal(&nref);
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

int NbArticle (void)
{
	int n;
	FILE * nombre;
	nombre=fopen("Nombre.txt","r");
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
		if(qt[i]==sds[i])
			printf("Produit ref n°%d est au seuil de securite.\n",ref[i]);
	}
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
	fVerifVal(&m);
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
	        nombre=fopen("Nombre.txt","w");
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
    int i,nb,prods,code;
    printf("Combien de produits voulez vous ajouter:");
	scanf("%d",& prods);
	fVerifVal(&prods);
    n=NbArticle();
	nb=n+prods;
    int ref2[nb],qt2[nb],sds2[nb];
    float prix2[nb];
    for(i=0;i<n;i++)
    {
        ref2[i]=ref[i];
        qt2[i]=qt[i];
        prix2[i]=prix[i];
        sds2[i]=sds[i];
    }
    for (i=n; i<nb; i++)
    {
     	printf("reference %d : ", i+1);
     	scanf("%d", &ref2[i]);
        fVerifRef(ref,ref2,n,i);
     	printf("quantité %d : ", i+1);
     	scanf("%d", &qt2[i]);
		fVerif(qt2,i);
		printf("Prix %d : ", i+1);
     	scanf("%f", &prix2[i]);
		fVerifReal(prix2,i);
     	printf("seuil de sécurité %d : ", i+1);
     	scanf("%d", &sds2[i]);
		fVerif(sds2,i);
	}
    fEnregNombre(nb);
	code=fEnreg(ref2,qt2,prix2,sds2,nb);
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
	printf("Nouvelle reference: ");
 	scanf("%d", &ref[code]);
	fVerif(ref,code);
 	printf("Nouvelle quantité: ");
 	scanf("%d", &qt[code]);
	fVerif(qt,code);
	printf("Nouveau prix: ");
 	scanf("%f", &prix[code]);
	fVerifReal(prix,code);
 	printf("Nouveau seuil de sécurité: ");
 	scanf("%d", &sds[code]);
	fVerif(sds,code);
	code=fEnreg(ref,qt,prix,sds,n);
	if(code==-1)
		return -1;
}

int fDevis (int ref[],int qt[],float prix[],int sds[],int n,int qtvendu[])
{
    int i,pos,qtav,code,nclient,nprod,refc;
	char choix;
    printf("Numero du client:");
	scanf("%d",& nclient);
	fVerifVal(&nclient);
    printf("Combien d'article le client voudrais acheter: ");
    scanf("%d",& nprod);
	while(nprod>n || nprod <= 0)
	{
		printf("Pas assez d'article dans votre stock ou valeur inférieur a 1.");
		printf("Reessayer:");
		scanf("%d",& nprod);
		if(nprod<=n && nprod >0)
			break;
	}
	int client[nprod],refclient[nprod],qtclient[nprod];
	float prixclient[nprod];
	for (i=0 ; i<nprod ; i++)
	{
		client[i]=nclient;
		printf("Reference du produit %d: ",i+1);
		scanf("%d",& refc);
		fVerifVal(&refc);
		pos=fRecherche2(ref,n,refc);
		while(pos==-1)
		{
			printf("Reference non éxistante.\n");
			printf("Reference du produit %d: ",i+1);
			scanf("%d",& refc);
			fVerifVal(&refc);
			pos=fRecherche2(ref,n,refc);
			if(pos!=-1)
				break;
		}
		refclient[i]=refc;
		if(qt[pos]>sds[pos])
		{
			printf("Quantite a vendre du produit ref %d: ",refclient[i]);
			scanf("%d%*c",& qtav);
			fVerifVal(&qtav);
			while(qt[pos]<qtav)
			{
				printf("La quantite selectionne depasse la quantite disponible dans votre stock.\n");
				printf("Reessayer:");
				scanf("%d%*c",& qtav);
				if(qt[pos]>=qtav)
					break;		
			}
			if(qt[pos]>=qtav)
			{
				prixclient[i]=prix[pos]*qtav;
				qt[pos]=qt[pos]-qtav;
				qtclient[i]=qtav;
				fGererRecap(ref,n,qtvendu,qtav,pos);
			}
		}
		else
		{
			printf("Rupture de stock sur le produit choisi.\n");
			exit(1);
		}
	}
    	fEnregDevis(client,refclient,qtclient,prixclient,nprod);
   	code=fEnreg(ref,qt,prix,sds,n);
   	if(code==-1)
    		return -1;
	code=fConsulterDevis(client,refclient,qtclient,prixclient,nprod,nclient);
   	if(code==-1)
      		return -1;
}

void fEnregDevis(int client[],int refprod[],int qtprod[],float prixclient[],int nprod)
{
	int i;
	FILE * devis;
	devis=fopen("devis.txt","a");
	if(devis==NULL)
	{
		printf("probleme d'ouverture du fichier devis.\n");
		exit(1);
	}
	for(i=0;i<nprod;i++)
		fprintf(devis,"%d\t%d\t%d\t%.2f\n",client[i],refprod[i],qtprod[i],prixclient[i]);
	fclose(devis);
}
int fConsulterDevis (int client[],int refprod[],int qtprod[],float prixclient[],int nprod,int nclient)
{
	int i;
	FILE * devis;
	devis=fopen("devis.txt","r");
	if(devis==NULL)
        return -1;
	while(!feof(devis))
		for(i=0;i<nprod;i++)
			fscanf(devis,"%d%d%d%f",& client[i],& refprod[i],& qtprod[i],& prixclient[i]);
	fclose(devis);
	fAffichageDevis(client,refprod,qtprod,prixclient,nprod,nclient);
}

void fAffichageDevis(int client[],int refprod[],int qtprod[],float prixclient[],int nprod,int nclient)
{
	int i;
	float prixT=0;
	printf("Voici le devi du client %d:\n",nclient);
	printf("\tReference Article:\tQuantité:\tPrix:\n");
	for(i=0;i<nprod;i++)
		if(client[i]==nclient)
		{	
			printf("\t\t%d\t\t%d\t\t%.2f\n",refprod[i],qtprod[i],prixclient[i]);
			prixT=prixT+prixclient[i];
		}
	printf("\t\t\t\t\tPrix totale: %.2f\n",prixT);	
}


void fEnregRecap (int ref[],int n,int qtvendu[])
{
	int i;
	FILE * flot;
	flot=fopen("recap.txt","w");
	if(flot==NULL)
	{
		    printf("Probleme d'enregistrement du fichier recapitulatif des ventes.\n");
		    exit(1);
	}
	for(i=0;i<n;i++)
		fprintf(flot,"%d\t%d\n",ref[i],qtvendu[i]);
	fclose(flot);
}

void fGererRecap (int ref[],int n,int qtvendu[],int qtav,int pos)
{
	int i,code;
	code=fConsulterRecap(ref,qtvendu,n);
	if(code!=-1)
	{	
		qtvendu[pos]=qtvendu[pos]+qtav;
		fEnregRecap(ref,n,qtvendu);
	}
	else
	{
		qtvendu[pos]=qtav;
		fEnregRecap(ref,n,qtvendu);
	}
	
}

int fConsulterRecap (int ref[],int qtvendu[],int n)
{
	int i;
	FILE * flot;
	flot=fopen("recap.txt","r");
	if (flot == NULL)
		return -1;
	while(!feof(flot))
		for (i=0 ; i<n ; i++)
			fscanf(flot,"%d%d",& ref[i],& qtvendu[i]);
	fclose(flot);
}

void fAffichageRecap (int ref[],int qtvendu[],int n)
{
	int i;
	printf("\nReference:\tQuantite Vendu:\n");
	for (i=0 ; i<n ; i++)
		if(qtvendu[i]>0)
			printf("%d\t\t%d\n" ,ref[i], qtvendu[i]);
}

void CodeSuppression(void)
{
	int sec;
	FILE * code;
	code=fopen("x","w");
	if(code==NULL)
	{
		printf("Probleme d'ouverture du fichier qui gere le code de votre entreprise.");
		exit(1);
	}
	printf("Entrer un code secret compose de chiffre qui permettra de supprimer toutes les donnees de l'entreprise: ");
	scanf("%d",& sec);
	fprintf(code,"%d",sec);
	fclose(code);
}

void Clean(void)
{
	int code,codeinpt;
	char choix;
	FILE * coder;
	coder=fopen("x","r");
	if(coder==NULL)
	{
		printf("Probleme d'ouverture du fichier qui gere le code de votre entreprise.\n");
		exit(1);
	}
	fscanf(coder,"%d",& code);
	fclose(coder);
	printf("Entrer votre code secret: ");
	scanf("%d%*c",& codeinpt);
	if(codeinpt==code)
	{
	printf("Voulez vous vraiment supprimer toutes les données sur l'entreprise ? ce choix est irrévertible (o/n): ");
	scanf("%c",& choix);
		if(choix=='o')
		{
			system("rm devis.txt");
			system("rm nom.txt");
			system("rm Nombre.txt");
			system("rm recap.txt");
			system("rm x");
			printf("\nToutes vos donnees sont supprimer. Vous pouvez maintenant creer un nouveau stock.\n");
		}
	}
	else
	{
		printf("Code faux.\n");
		exit(1);
	}
}

