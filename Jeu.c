#include <stdio.h>
#include <stdlib.h>
#include "malloc.h"
#include <string.h>
#include "tictactoe.h"

void jouer(struct jeu *etat)
{

  system("cls");
  printf("\n\t\tTableau courant :\n");
  printf("\n\t\t==> Main au joueur %c (Vous)\n",etat->joueur);

  afficherJeu(etat);

  if(finJeu(etat) == 1) {
	system("pause");
	return;
  }

  bougerJoueur(etat,avoirJoueurDeplacement(etat));
  
  if(finJeu(etat) == 1) {
	system("pause");
	return;
  }

  bougerMachine(etat);

  system("pause");
  jouer(etat);

}

int finJeu(struct jeu *etat)
{
  char resultat = terminer(etat->tableau);

  switch( resultat )
  {
	case 'x':
	  printf("\t***** Vous avez gagné !!!  ^_^ *****\n\n\n");
	  return 1;
	  break;
	case 'o':
	  printf("\t***** Vous avez perdu -_- *****\n\n\n");
	  return 1;
	  break;
	case 'd':
	  printf("\t***** Match nul ... prochaine fois *****\n\n\n");
	  return 1;
	  break;
  };

  return 0;

}

void bougerJoueur(struct jeu *etat,int deplacer)
{
  etat->tableau[deplacer] = 'x';
  etat->joueur = 'o';
  afficherJeu(etat);
  printf("\t\tJoueur position ==> %d\n\n",deplacer+1);
  

}

void bougerMachine(struct jeu *etat)
{ 
  int minstatevalue = 2;
  int minimaxValeur;
  struct jeu *nextgame;

  struct listeJeu *etatSuivant = genEtatSuivant(etat);

  printf("\n\t\t==> Main a la Machine %c (AI)\n\n",etat->joueur);


  while (etatSuivant != NULL)
	{
	  minimaxValeur = minMax(etatSuivant->etat,-2,2);
	  if (minimaxValeur < minstatevalue) {
		minstatevalue = minimaxValeur;
		nextgame = etatSuivant->etat;
	  }
	  etatSuivant = etatSuivant->suivant;
	}

  strcpy(etat->tableau,nextgame->tableau);
  etat->joueur = nextgame->joueur;
  afficherJeu(etat);
}

struct listeJeu *genEtatSuivant(struct jeu *etat)
{

 
  int i, j;
  struct listeJeu *root;
  struct listeJeu *previousstate;
  struct listeJeu *currentstate;
  struct jeu *currentgame;

  

  root = malloc(sizeof(struct listeJeu));
  currentstate = root;

  for (i = 0; i < 9; i++) {
	if (etat->tableau[i] == ' ') {
	  if (currentstate == NULL) {
		currentstate = malloc(sizeof(struct listeJeu));
		previousstate->suivant = currentstate;
	  }

	  currentstate->suivant = NULL;

	  currentstate->etat = malloc(sizeof(struct jeu));
	  currentgame = currentstate->etat;

	  previousstate = currentstate;
	  currentstate = currentstate->suivant;

	  strcpy(currentgame->tableau,etat->tableau);
	  currentgame->tableau[i] = etat->joueur;

	  if (etat->joueur == 'x') {
		currentgame->joueur = 'o';
	  } else {
		currentgame->joueur = 'x';
	  }

	}
  }


   return root;

}

int avoirJoueurDeplacement(struct jeu *etat)
{

  int deplacer;

  printf("\n\tVeuillez entrer un nombre entre 1 et 9 pour se deplacer :  ");
  scanf("%d",&deplacer);

  if(deplacer < 1 || deplacer > 9 || etat->tableau[deplacer - 1] != ' ') {
	printf("\n\t====> Deplacement invalid.\n\n");
	system("pause");
	system("cls");
	printf("\n\t\tTableau courant avec le joueur %c\n",etat->joueur);
	afficherJeu(etat);
	return avoirJoueurDeplacement(etat);
  }

  return (deplacer - 1);

}
