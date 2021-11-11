void globale (void);
int NbArticle (void);
void fEnregNombre(int n);
void fVerif(int tab[],int i);
void fVerifReal(float tab[],int i);
void fVerifVal(int *val);
void fVerifRef(int ref[],int ref2[], int n, int pos);
int fCreerStock (void);
void fEtatStock(int ref[],int qt[],float prix[],int sds[],int n);
int fConsulterStock (int ref[],int qt[],float prix[],int sds[],int n);
void fAfficherStock (int ref[],int qt[],float prix[],int sds[],int n);
int fAppro (int ref[],int qt[],float prix[],int sds[],int n);
int fRecherche (int ref[],int n);
int fRecherche2 (int ref[],int n,int nref);
int fEnreg(int ref[],int qt[],float prix[],int sds[],int n);
int fSuppression (int ref[],int qt[],float prix[],int sds[],int n);
int fAjouter(int ref[],int qt[],float prix[],int sds[],int n);
int fModifier(int ref[],int qt[],float prix[],int sds[],int n);

int fDevis (int ref[],int qt[],float prix[],int sds[],int n,int qtvendu[]);
void fEnregDevis(int client[],int refprod[],int qtprod[],float prixclient[],int nprod);
int fConsulterDevis (int client[],int refprod[],int qtprod[],float prixclient[],int nprod,int nclient);
void fAffichageDevis(int client[],int refprod[],int qtprod[],float prixclient[],int nprod,int nclient);

void fEnregRecap (int ref[],int n,int qtvendu[]);
void fGererRecap (int ref[],int n,int qtvendu[],int qtav,int pos);
int fConsulterRecap (int ref[],int qtvendu[],int n);
void fAffichageRecap (int ref[],int qtvendu[],int n);

void CodeSuppression(void);
void Clean(void);
