#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


bool verifgagnant(char tableau[3][3]) {
	// Checker les lignes 
	for (int i = 0; i < 3; i++) {
		if (tableau[i][0] == tableau[i][1] && tableau[i][1] == tableau[i][2] && tableau[i][0] != ' ') {
			printf("Gagne sur la ligne %d\n", (i + 1));
			return true;
		}
	}

	// Checker les colonnes
	for (int i = 0; i < 3; i++) {
		if (tableau[0][i] == tableau[1][i] && tableau[1][i] == tableau[2][i] && tableau[0][i] != ' ') {
			printf("Gagne sur la colonne %d\n", (i + 1));
			return true;
		}
	}

	// Checker les diagonales 
	if (tableau[0][0] == tableau[1][1] && tableau[1][1] == tableau[2][2] && tableau[0][0] != ' ') {
		printf("Gagne sur la diagonale 1\n");
		return true;
	}

	if (tableau[0][2] == tableau[1][1] && tableau[1][1] == tableau[2][0] && tableau[0][2] != ' ') {
		printf("Gagne sur la diagonale 2\n");
		return true;
	}

	return false;
}


int afficherjeux(char table[3][3]) {
	printf("y\\x  1   2   3\n");
	printf("   /-----------\\\n");
	printf("1. | %c | %c | %c |\n", table[0][0], table[0][1], table[0][2]);
	printf("   |-----------|\n");
	printf("2. | %c | %c | %c |\n", table[1][0], table[1][1], table[1][2]);
	printf("   |-----------|\n");
	printf("3. | %c | %c | %c |\n", table[2][0], table[2][1], table[2][2]);
	printf("   \\-----------/\n");

	return 0;
}

bool verifcorrect(int y, int x, char cadrillage[3][3]) {
	if (y >= 1 && y <= 3) {
		if (x >= 1 && x <= 3) {
			if (cadrillage[y - 1][x - 1] == ' ') {
				
				return true;
			}
			else {
				printf("La case est deja occupee !\n");
				return false;
			}

		}
		else {
			printf("La coordonnee X n'est pas correct");
			return false;
		}
	}
	else {
		printf("La coordonee Y n'est pas correct");
		return false;
	}
}


int main() {
	bool gagnant;
	char tour = 'x';
	int coordoneeX;
	int coordoneeY;
	bool correct;


	char cadrillage[3][3] = { {' ', ' ', ' '}, { ' ', ' ', ' ' }, { ' ', ' ', ' ' } };

	afficherjeux(cadrillage);
	do
	{
		printf("Au tour du Joueur %c\n", tour);

		do
		{
			 
			printf("\nEntrez une coordone X (colone) entre 1 et 3: ");
			scanf_s("%d", &coordoneeX);

			printf("Entrez une coordone Y (ligne) entre 1 et 3: ");
			scanf_s("%d", &coordoneeY);

			correct = verifcorrect(coordoneeY, coordoneeX, cadrillage);
		} while (!correct);

		system("clear");
		afficherjeux(cadrillage);
		cadrillage[coordoneeY - 1][coordoneeX - 1] = tour;
		

		gagnant = verifgagnant(cadrillage);
		if (gagnant) {
			printf("Joueur gagnant : %c", tour);
		}

		if (tour == 'x') {
			tour = 'o';
		}
		else {
			tour = 'x';
		}

	} while (!gagnant);
}