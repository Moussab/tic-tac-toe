#include <stdio.h>
#include <stdlib.h>
#include "malloc.h"
#include <string.h>
#include "tictactoe.h"

int minMax(struct jeu *etat,int alpha, int beta)
{

  char resultat = terminer(etat->tableau);

  switch(resultat)
  {
	case 'x':
	  return 1;
	case 'o':
	  return -1;
	case 'd':
	  return 0;
	case ' ':
	  if (etat->joueur == 'x') {
		return maxValeur(genEtatSuivant(etat),alpha,beta);
	  } else {
		return minValeur(genEtatSuivant(etat),alpha,beta);
	  }
  }
}

int maxValeur(struct listeJeu *etatSuivant,int alpha, int beta)
{

  int maxValeurEtat = -2;
  int minMaxValeur;

  while (etatSuivant != NULL)
	{
	  minMaxValeur = minMax(etatSuivant->etat,alpha,beta);
	  if (minMaxValeur > maxValeurEtat) maxValeurEtat = minMaxValeur;
	  if (maxValeurEtat >= beta) return maxValeurEtat;
	  if (alpha < maxValeurEtat) alpha = maxValeurEtat;

	  etatSuivant = etatSuivant->suivant;
	}

  return maxValeurEtat;

}

int minValeur(struct listeJeu *etatSuivant, int alpha, int beta)
{

  int minValeurEtat = 2;
  int minMaxValeur;

  while (etatSuivant != NULL)
	{
	  minMaxValeur = minMax(etatSuivant->etat,alpha,beta);
	  if (minMaxValeur < minValeurEtat) minValeurEtat = minMaxValeur;
	  if (minValeurEtat <= alpha) return minValeurEtat;
	  if (beta > minValeurEtat) beta = minValeurEtat;

	  etatSuivant = etatSuivant->suivant;
	}

  return minValeurEtat;

}

