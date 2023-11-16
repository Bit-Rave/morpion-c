#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


bool verifgagnant(char tableau[3][3]) {
	//checker les lignes 
	for (int i = 0; i < 3; i++)
	{
		if (tableau[i * 0] == tableau[i * 1] && tableau[i * 1] == tableau[i * 2] && tableau[i * 0] != ' ') {
			printf("gagne sur la ligne %d\n", i);
			return true; 

		}

	}
	//checker les colones
	for (int i = 0; i < 3; i++)
	{
		if (tableau[0 * i] == tableau[1 * i] && tableau[1 * i] == tableau[2 * i] && tableau[0 * i] != ' ') {
			printf("gagne sur la colone %d\n", i);
			return true;
		}
	}
	// checker les diagonales 
	if (tableau[0][0] == tableau[1][1] && tableau[1][1] == tableau[2][2] && tableau[0][0] != "") {
		printf("gagne sur la diagonale 1");
		return true;
	}
	if (tableau[0][2] == tableau[1][1] && tableau[1][1] == tableau[2][0] && tableau[0][2] != "") {
		printf("gagne sur la diagonale 2");
		return true;
	}
}


int afficherjeux(char table[3][3]) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++)
		{
			printf(" %c", table[i * j]);
		}
		printf("\n");
	}
	return 0;
}


int main() {
	bool gagnant;
	char tour = 'x';
	int coordoneeX;
	int coordoneeY;
	bool correct;


	char cadrillage[3][3];{{' ', ' ', ' '},
							{' ', ' ', ' '},
							{' ', ' ', ' '}};

	do
	{
		printf("Au tour du Joueur %c\n", tour);
		do
		{
			printf("Entrez une coordone Y entre 1 et 3: ");
			scanf("%d", &coordoneeY);

			printf("\nEntrez une coordone X entre 1 et 3: ");
			scanf("%d", &coordoneeX);
			correct = true; //verifiercase(coordoneeX, coordoneeY, cadrillage);
		} while (!correct);

		afficherjeux(cadrillage);

		if (tour == 'x') {
			tour = 'y';
		}
		else {
			tour = 'x';
		}


		gagnant = verifgagnant(cadrillage);
	} while (!gagnant);

	printf("Joueur gagnant : %c", tour);
}