# Cahier de charge SAE-1.01
Eleve: HASSANI Mohamed  
Groupe: 2

## Contexte de l'entreprise :
Programme de gestion de stock pour l'entreprise XtraChaus

L'entreprise XtraChaus est une entreprise qui produit des chaussures.
Chaque type de chaussure possède:
- Une propre référence (*On prend pas compte de la pointure dans ce programme*)
- Une quantité.
- Un prix.
- Un seuil de sécurité.

## Fonctionnalités réalisé:
``` globale ```: La fonction globale va gérer toutes les autres fonctions, c'est la fonction qui va créer la plupart des variables/tableaux, afficher le menu du programme, afficher les messages d'erreurs et bien sur demander à l'utilisateur ce qu'il veut faire dès l'exécution.

```fCreerStock```: La fonction qui va permettre à l'utilisateur de créer son stock, cette fonction va créer 3 fichiers .txt:
- Le premier __Nombre.txt__  va enregistrer la taille n de nos 4 tableaux (*référence, quantité, prix, seuil de sécurité*) entrer par l'utilisateur pour but de rendre le programme plus autonome et éviter de demander à l'utilisateur de rappeler la taille du stock à chaque fois et aussi pour éviter des tableaux vides.
- Le deuxième __nom.txt__ va enregistrer cette fois-ci le contenu de nos 4 tableaux de taille n.
- Le troisième __x__ va enregistrer un code secret entrer par l'utilisateur dès la création de son stock, il lui sera demandé plus tard s'il veut supprimer tous les fichiers du stock de l'entreprise et recommencer à 0.

la fonction fait aussi appel à la fonction ```fVerif``` pour un tableau d'entier et ```fVerifReal``` pour un tableau réel qui vont vérifier si la valeur entrer par l'utilisateur n'est pas inférieur à 0 pour un entier et inférieur à 0.01 pour un réel(*prix*) sinon l'utilisateur devrait resaisir sa valeur.

```fNbArticle```: Cette fonction va charger la taille n'est pas partie de __Nombre.txt__ de nos tableaux à chaque exécution et retournera -1 si le fichier n'est pas encore créé.

```fConsulterStock```: Cette fonction va charger notre stock à partir du fichier __nom.txt__ dans des tableaux de taille n (*'n' est obtenu grace à* ```fNbArticle```) à chaque exécution si le fichier n'est pas présent la fonction retournera -1.

Si ```fNbArticle``` ou ```fConsulterStock``` retourne la valeur -1 cela veut dire que l'utilisateur n'a pas encore créé de stock, donc on affichera un message lors de la première exécution du programme qui avertira l'utilisateur qu'il ne possède aucun stock et qu'il faudrait en créer un avant de faire n'importe quelle manipulation.

```fAfficherStock```: Affiche le stock créer par l'utilisateur.

```fEtatStock```: Affiche le stock et vérifie la quantité par rapport au seuil de sécurité d'un article, la fonction affichera l'état du stock de chaque article.(*la variable ```m``` affiche à l'utilisateur la quantité à approvisionner pour atteindre le seuil de sécurité*).

```fAppro```: Cette fonction permet à l'utilisateur d'effectuer l'approvisionnement ou réapprovisionnement d'un article à partir de son numéro de référence, donc on fait appel à la fonction ```fRecherche``` qui va demander le num de référence à l'utilisateur, la fonction ```fRecherche``` rend -1 si la référence n'est pas présente dans notre tableau référence ou rend la position du de la référence donnée si la valeur est présente. ```fAppro``` ajoute la quantité entrée par l'utilisateur à notre quantité existant et appelle ```fEnreg``` qui va écraser le fichier __nom.txt__ avec nos nouvelles valeurs et rend -1 en cas d'erreur.

```fSuppression```: Cette fonction permet à l'utilisateur de supprimer un article, pour faire cela la fonction fera appel à ```fRecherche```, si la référence existe on décalera toutes nos valeurs de nos tableaux, on réduira la taille de nos tableaux de 1 en écrasant n présent dans __Nombre.txt__ grâce à ```fEnregNombre``` et en écrasant les tableaux présents dans __nom.txt__ grâce à ```fEnreg```.

```fAjouter```: Cette fonction permet à l'utilisateur d'ajouter un ou plusieurs nouveaux articles (*cette fonction ma causer beaucoup de problèmes car les tableaux ne sont pas dynamiques donc j'ai opté pour une autre solution que j'explique ici*),  pour ajouter un ou plusieur article la fonction demande à l'utilisateur d'entrer le nombre d'article qu'il veut ajouter à son stock, bien sûr les toutes les valeurs sont vérifiées dans cette fonction, une nouvelle  fonction de vérification est créé ```fVerifVal``` qui utilise un pointeur cette fois-ci pour vérifier et modifier la valeur en cas ou elle est inférieure à 0 car on travaille plus avec des tableaux mais avec une variable.  Donc on charge nos tableaux et leur taille n et on crée une nouvelle taille à partir de la somme de "n" et le nombre de nouveaux articles "prods" qui s'appellera "nb". on crée de nouveaux tableaux (*référence, quantité, prix,seuil de securité*) de taille nb, on met tous nos articles actuels dans nos nouveaux tableaux et on demande a l'utilisateur d'entrer ses nouvelles valeurs. À la fin on écrase nos 4 nouveaux tableaux dans le fichier __nom.txt__.

```fModifier```: Cette fonction permet de modifier toutes les valeurs d'un article, a cherché la référence et si elle est présente on écrase les valeurs des 4 tableaux (*référence, quantité, prix, seuil de sécurité*) actuelle par ceux que l'utilisateur saisi avec vérification, on enregistre dans le fichier __nom.txt__.

```fDevis```: Permet de créer, afficher et enregistrer dans __devis.txt__ le devis d'un client identifié par son propre numéro, les quantités vendues seront aussi enregistrées dans un fichier __recap.txt__ (*Dans mon cas la fonction fDevis fait aussi office de la fonction 'faire une vente'*). On vérfie plusieurs valeurs:
- Le numéro du client doit être > 0.
- La référence de l'article doit être présente dans le tableau ref sinon on resaisit la référence (*appelle à la fonction ```fRecherche2``` qui cette fois-ci ne demande pas d'entrer la référence de l'article mais effectue que la vérification de présence de la référence*).
- L'article sélectionné doit avoir une quantité supérieure à son seuil de sécurité.
- La quantité voulue par le client ne doit pas dépasser la quantité présente dans le stock sinon on resaisit la valeur. 

Si toutes ces conditions sont validées on va multiplier le prix a l'unité de notre article par la quantité voulu par le client et le stocker dans un tableau, on va soustraire la quantité présente dans le stock par la quantité vendu, on va mettre la quantité vendue dans un tableau pour reconnaitre la quantité acheter de chaque client et on fait appel à ```fGererRecap``` qui va lire le fichier __recap.txt__ grâce à ```fConsulterRecap```, si le fichier n'est pas présent on initialisera un tableau qui fait office de la quantité vendue à 0 et on incrémente la quantité vendu dans un tableau qui aura la même position que ça référence et si le fichier existe déjà on prend la valeur présente et on rajoute la quantité vendue. On enregistre dans le fichier __recap.txt__ avec ```fEnregRecap```.

```fAffichageRecap```:  Affiche le récapitulatif des ventes. Si le nombre de produits vendus est > 0 on affiche la référence du produit et la quantité vendue.

```CodeSuppression```: Est une fonction appelée lors de la création d'un stock qui enregistre le code secret dans le fichier __x__.

```Clean```: Est la fonction qui va permettre à l'utilisateur qui gère le stock de supprimer toutes les données concernant son stock(les devis créés, le fichier contenant le stock de l'entreprise, le fichier récapitulatif de ventes et le fichier contenant le code). La fonction regarde si le code entrer est le même que celui présent dans le fichier __x__ et demande a l'utilisateur s'il veut vraiment tout supprimer.

#### Remarque:
- La fonction fDevis ne fonctionne pas correctement sur les pc de l'iut il se peut que ce soit un problème de droits (*Lors de la saisie de la référence d'article à vendre, le programme ne donne pas la main à l'utilisateur pour saisir la quantité à vendre et met 0*).

voici le résultat sur ma machine:
![image](https://user-images.githubusercontent.com/78689752/141314943-34cc789e-d94c-4bee-a58e-e58a87772794.png)

