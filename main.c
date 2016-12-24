#include <stdio.h>
#include <stdlib.h>
#include "malloc.h"
#include <string.h>
#include "tictactoe.h"


void main()
{

  struct jeu *statepointer = malloc(sizeof(struct jeu));
  struct jeu etat = *statepointer;
  int i, choix;

  do{
		system("cls");
	    printf("\n");
		printf("\n");
		printf("\t<==================== TIC TAC TOE ====================>\n");
		printf("\n");
		printf("\n");
		printf("\t\tMenu :\n");
		printf("\n");
		printf("\t\t\t1) Demarrer le jeu.\n");
		printf("\n");
		printf("\t\t\t2) Quitter.\n");
		printf("\n");
		printf("\t\t  Choix  == ");
		scanf_s("%d",&choix);

		switch(choix){
			case 1:
				system("cls");
				printf("\n");
				printf("\tInitialisation de la partie :\n");
				printf("\n");
				printf("\t\tLe joueur qui va commencer ==> Vous\n");
				printf("\n");
				printf("\t\tLes pieces du joueur (Vous)   ==> X\n");
				printf("\n");
				printf("\t\tLes pieces de la machine (AI) ==> O\n");
				printf("\n");
				system("pause");
				system("cls");
				for (i = 0; i < 9; i++) {
					etat.tableau[i] = ' ';
				}
				etat.tableau[9] = '\0';
				etat.joueur = 'x';
				jouer(&etat);
				getchar();
			break;

			case 2:
				exit(0);
			break;

			default:
				printf("\n\tErreur !!\n\n");
				system("pause");
			break;
	}
  }while(choix != 2);





}
