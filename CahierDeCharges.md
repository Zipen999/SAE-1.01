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
``` globale ``` : La fonction globale va gerer toutes les autres fonction, c'est la fonction qui va créer la plupart des variables/tableaux, afficher le menu du programme, afficher les messages d'erreurs et bien sur demander à l'utilisateur ce qu'il veut faire dès l'execution.

```fCreerStock``` La fonction qui va permettre à l'utilisateur de créer son stock, cette fonction va créer 3 fichier .txt:
- Le premier __Nombre.txt__  va enregistrer la taille n de nos 4 tableaux (*référence, quantité, prix,seuil de securité*) entrer par l'utilisateur pour but de rendre le programme plus autonome et éviter de demander a l'utilisateur de rappeler la taille du stock a chaque fois et aussi pour eviter des tableaux vides.
- Le deuxieme __nom.txt__ va enregistrer cette fois ci le contenu de nos 4 tableaux de taille n.
- Le troisieme __x__ va enregistrer un code secret entrer par l'utilisateur dès la création de son stock, il lui sera demander plus tard s'il veut supprimer tout les fichiers du stock de l'entreprise et recommencer à 0.

la fonction fait aussi appelle a la fonction ```fVerif``` pour un tableau d'entier et ```fVerifReal``` pour un tableau réel qui vont vérifier si la valeur entrer par l'utilisateur n'est pas inférieur à 0 pour un entier et inférieur à 0.01 pour un réel(*prix*) sinon l'utilisateur devrait resaisir sa valeur.

```fNbArticle``` Cette fontion va charger la taille n a partir de __Nombre.txt__ de nos tableaux à chaque éxécution et retournera -1 si le fichier n'est pas encore créer.

```fConsulterStock``` cette fonction va charger notre stock a partir du fichier __nom.txt__ dans des tableaux de taille n (*n est obtenu grace a fNbArticle*) à chaque éxécution si le fichier n'est pas présent la fonction retournera -1.

Si ```fNbArticle``` ou ```fConsulterStock``` retourne la valeur -1 cela veut dire que l'utilisateur n'a pas encore créer de stock, donc on affichera un message lors de la premiere éxécution du programme qui avertira l'utilisateur qu'il ne possede aucun stock et qui'il faudrait en créer un avant de faire n'importe quel manipulation.

```fAfficherStock``` Affiche le stock créer par l'utilisateur.

```fEtatStock``` Affiche le stock et vérifie la quantité par rapport au seuil de sécurité d'un article,la fonction affichera l'etat du stock de chaque article.(*la variable ```m``` affiche a l'utilisateur la quantité a approvisionner pour atteindre le seuil de sécurité*).

```fAppro``` Cette fonction permet a l'utilisateur d'éfféctuer l'approvisionnement ou réaprovisionnement d'un article a partir de son numero de référence, donc on fait appelle a la fonciton ```fRecherche``` qui va demander le num de référence à l'utilisateur, la fonciton ```fRecherche``` rend -1 si la référence n'est pas présente dans notre tableau référence ou rend la position du de la référence donné si la valeur est présénte. ```fAppro``` ajoute la quantité entrer par l'utilisateur a notre quantité éxistant et appelle ```fEnreg``` qui va écraser le fichier __nom.txt__ avec nos nouvelles valeurs et rend -1 en cas d'erreur.

```fSuppression``` Cette fonction permet a l'utilisateur de supprimer un article, pour faire cela la fonction fera appelle a ```fRecherche```, si la référence existe on décalera toutes nos valeurs de nos tableaux, on réduira la taille de nos tableaux de 1 en écrasant n présent dans __Nombre.txt__ grâce à ```fEnregNombre``` et en écrasant les tableaux present dans __nom.txt__ grâce à ```fEnreg```.

```fAjouter``` Cette fonction permet a l'utilisateur d'ajouter un ou plusieurs nouveaux articles (*cette fonction ma causer beaucoup de probleme car les tableaux ne sont pas dynamique donc j'ai opter pour une autre solution que j'éxplique ici*),  pour ajouter un ou plusieurs article la fonction demande a l'utilisateur d'entrer le nombre d'article qu'il veut ajouter à son stock, bien sur les toutes les valeurs sont vérifié dans cette fonction, une nouvelle fonction de vérification est crée ```fVerifVal``` qui utilise un pointeur cette fois ci pour vérifier et modifier la valeur en cas ou elle est inférieur à 0 car on travaille plus avec des tableaux mais avec une variable.  Donc on charge nos tableaux et leur taille n et on crée une nouvelle taille a partir de la somme de 'n' et le nombre de nouveau articles 'prods' qui s'appelera 'nb'. on crée de nouveaux tableaux (*référence, quantité, prix,seuil de securité*) de taille nb, on met tout nos articles actuelle dans nos nouveaux tableaux et on demande a l'utilisateur d'entrer ses nouvelles valeurs. A la fin on écrase nos 4 nouveaux tableaux dans le fichier __nom.txt__.

```fModifier``` Cette fonction permet de modifier toutes les valeurs d'un article, on chercher la référence et si elle est présente on écrase les valeurs des 4 tableaux (*référence, quantité, prix,seuil de securité*) actuelle par ceux que l'utilisateur saisi avec vérfication, on enregistre dans le fichier __nom.txt__.

```fDevis``` Permet de créer, afficher et enregistrer dans __devis.txt__ le devis d'un client identifié par son propre numéro, les quantités vendus seront aussi enregistrer dans un fichier __recap.txt__ (*Dans mon cas la fonction fDevis fait aussi office de la fonction 'faire une vente'*). On vérfier plusieurs valeurs:
- Le numéro du client doit être > 0.
- La référence de l'article doit être présente dans le tableau ref sinon on resaisi la reference (*appelle a la fonction ```fRecherche2``` qui cette fois ci ne demande pas d'entrer la reference de l'article mais effectue que la vérification de présence de la reference*).
- L'article selectionné doit avoir une quantité supérieur a son seuil de sécurité
- La quantité voulu par le client ne doit pas dépasser la quantité présente dans le stock sinon on resaisi la valeur.  Si toute ces conditions sont validé on va multiplié le prix a l'unité de notre article par la quantité voulu par le client et le stocker dans un tableau, on va soustraire la quantité présente dans le stock par la quantité vendu, on va mettre la quantité vendu dans un tableau pour reconnaitre la quantité acheter de chaque client et on fait appelle a ```fGererRecap``` qui va lire le fichier __recap.txt__ grâce à ```fConsulterRecap```, si le fichier n'est pas présent on initialisera un tableau qui fait office de la quantité vendu à 0 et on incrémente la quantité vendu dans un tableau qui aura la même position que ça référence et si le fichier éxiste déja on prend la valeur présente et on rajoute la quantité vendu. On enregistre dans le fichier __recap.txt__ avec ```fEnregRecap```.
