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

```fCreerStock``` La fonction qui va permettre à l'utilisateur de créer son stock, cette fonction va créer 2 fichier .txt:
- Le premier __Nombre.txt__  va enregistrer la taille n de nos 4 tableaux (*référence, quantité, prix,seuil de securité*) entrer par l'utilisateur pour but de rendre le programme plus autonome et éviter de demander a l'utilisateur de rappeler la taille du stock a chaque fois et aussi pour eviter des tableaux vides.
- Le deuxieme __nom.txt__ va enregistrer cette fois ci le contenu de nos 4 tableaux de taille n.  

la fonction fait aussi appelle a la fonction ```fVerif``` pour un tableau d'entier et ```fVerifReal``` pour un tableau réel qui vont vérifier si la valeur entrer par l'utilisateur n'est pas inférieur à 0 pour un entier et inférieur à 0.01 pour un réel(*prix*) sinon l'utilisateur devrait resaisir sa valeur.

```fNbArticle``` Cette fontion va charger la taille n a partir de __Nombre.txt__ de nos tableaux à chaque éxécution et retournera -1 si le fichier n'est pas encore créer.

```fConsulterStock``` cette fonction va charger notre stock a partir du fichier __nom.txt__ dans des tableaux de taille n (*n est obtenu grace a fNbArtcile*) à chaque éxécution si le fichier n'est pas présent la fonction retournera -1.

Si ```fNbArticle``` ou ```fConsulterStock``` retourne la valeur -1 cela veut dire que l'utilisateur n'a pas encore créer de stock, donc on affichera un message lors de la premiere éxécution du programme qui avertira l'utilisateur qui'il ne possede aucun stock et qui'il faudrait en créer un avant de faire n'importe quel manipulation.

```fAfficherStock``` Affiche le stock créer par l'utilisateur.

```fEtatStock``` Affiche le stock et va vérifier la quantité par rapport au seuil de sécurité d'un article,la fonction affichera l'etat du stock de chaque article.(*la variable ```m``` affiche a l'utilisateur la quantité a approvisionner pour atteindre le seuil de sécurité*).
