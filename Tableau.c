#include <stdio.h>
#include <stdlib.h>
#include "malloc.h"
#include <string.h>
#include "tictactoe.h"

char terminer(char *tableau)
{

  char lignes;
  char diagonals;
  char colonnes;

  lignes = verifLigne(tableau);
  diagonals = verifDiagonal(tableau);
  colonnes = verifColonne(tableau);

  if (lignes != ' ' && lignes != 'd') {
	return lignes;
  }

  if (colonnes != ' ') {
	return colonnes;
  }

  if (diagonals != ' ') {
	return diagonals;
  }

  if (lignes == 'd') {
	return 'd';
  } else {
	return ' ';
  }

}

char verifLigne(char *tableau)
{

  int i;
  int espacesLibre = 0;

  for (i = 0; i < 3; i++) {
    if ((tableau[3*i] == ' ') || (tableau[(3*i)+1] == ' ') || (tableau[(3*i)+2] == ' ')) espacesLibre = 1;
    if ((tableau[3*i] != ' ') && (tableau[3*i] == tableau[(3*i)+1]) && (tableau[(3*i)+1] == tableau[(3*i)+2])) return tableau[3*i];
  }

  if (espacesLibre == 1) {
	return ' ';
  } else {
	return 'd';
  }

}

char verifDiagonal(char *tableau)
{

  if ((tableau[0] != ' ') && (tableau[0] == tableau[4]) && (tableau[4] == tableau[8])) return tableau[0];
  if ((tableau[2] != ' ') && (tableau[2] == tableau[4]) && (tableau[4] == tableau[6])) return tableau[2];
  return ' ';

}

char verifColonne(char *tableau)
{

  int i;

  for (i = 0; i < 3; i++) {
    if ((tableau[i] != ' ') && (tableau[i] == tableau[i+3]) && (tableau[i+3] == tableau[i+6])) return tableau[i];
  }

  return ' ';

}

void afficherJeu(struct jeu *etat)
{
  printf("\n");
  printf("\t\t\t %c | %c | %c \n",etat->tableau[0],etat->tableau[1],etat->tableau[2]);
  printf("\t\t\t-----------\n");
  printf("\t\t\t %c | %c | %c \n",etat->tableau[3],etat->tableau[4],etat->tableau[5]);
  printf("\t\t\t-----------\n");
  printf("\t\t\t %c | %c | %c \n\n",etat->tableau[6],etat->tableau[7],etat->tableau[8]);

}
