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
