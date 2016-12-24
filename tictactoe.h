struct listeJeu {
  struct jeu *etat;
  struct listeJeu *suivant;
};

struct jeu {
  char tableau[10];
  char joueur;
};

void jouer(struct jeu *etat);
int finJeu(struct jeu *etat);
void bougerJoueur(struct jeu *etat,int deplacer);
void bougerMachine(struct jeu *etat);
int minMax(struct jeu *etat,int alpha, int beta);
int maxValeur(struct listeJeu *etatSuivant,int alpha, int beta);
int minValeur(struct listeJeu *etatSuivant,int alpha, int beta);
struct listeJeu *genEtatSuivant(struct jeu *etat);
char terminer(char *tableau);
char verifLigne(char *tableau);
char verifDiagonal(char *tableau);
char verifColonne(char *tableau);
void afficherJeu(struct jeu *etat);
int avoirJoueurDeplacement(struct jeu *etat);
