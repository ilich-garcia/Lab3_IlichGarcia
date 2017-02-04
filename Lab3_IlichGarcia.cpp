#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

// Para obtener el cociente.
double getQuotient(int);
// Para obtener el residuo.
double getResidue(int);
// Inicializar tablero.
int** initializeTable(int, int);
void printTable(int**, int);


int main() {
	int option;

	do {
		cout << "1. Ejercicio 1. \n2. Ejercicio 2. \n3. Salir. \nOpción: ";
		cin >> option;

		if (option == 1) {
			int quotient, residue, power;
			// vector<int**> newMatrix;

			cout << "Ingrese el grado más grande del polinomio: ";
			cin >> power;
/*
			int matrix** = new int*[3];

			for(int i = 0; i < power; i++) {
				matrix[i] = new int[power];
			}

			for (

			for(int i = power; i >= 0; i++) {
				cout << "Ingrese el polinomio x^" << i << ": ";
		      cin >> matrix[i];

			}*/

			// quotient = getQuotient(power);
         residue = getResidue(power);

			cout << "Residuo: " << residue << endl;
		} else if (option == 2) {
			int size, quantity;

			do {
				cout << "Ingrese tamaño del tablero (mayor a 9): ";
				cin >> size;
				cout << "Ingrese cantidad de minas: ";
				cin >> quantity;

				int** table = NULL;

				table = initializeTable(size, quantity);
				printTable(table, size);
			} while (size <= 9);
		}
	} while (option != 3);

	return 0;
}
/*
double getQuotient(int power) {
	double quotient;
	int** matrix = new int**[power];

	for(int i = power; i >= 0; i--) {
		cout << "Ingrese el polinomio x^" << i << ": ";
		cin >> matrix[i];
	}

	return quotient;
}*/

double getResidue(int size) {
	double residue = 0;
	int* matrix = new int[size + 1];
	int COUNT = 0, a;

   cout << "Ingrese valor de a: ";
   cin >> a;

   for(int i = size; i >= 0; i--) {
      cout << "Ingrese el polinomio x^" << i << ": ";
      cin >> matrix[COUNT];
		COUNT++;
   }

	for(int i = 0; i <= size; i++) {
		if (i == 0) {
			residue = matrix[0];
		} else {
			residue = residue * a + matrix[i];
		}
	}

	return residue;
}

int** initializeTable(int size, int quantity) {
	int COUNT = 0;
	int** table = new int*[size];

	for(int i = 0; i < size; i++) {
		table[i] = new int[size];
	}

	for(int i = 0; i < size; i++) {
		for(int j = 0; j < size; j++) {
			table[i][j] = 0;
		}
	}

	for(int i = 0; i < size; i++) {
      for(int j = 0; j < size; j++) {
         if (rand() % quantity + 0 == i || rand() % quantity + 0 == j) {
            if (COUNT < quantity) {
               table[i][j] = -1;
               COUNT++;
            }
         }
      }
   }

	return table;
}


void printTable(int** table, int size) {
   for(int i = 0; i < size; i++) {
      for(int j = 0; j < size; j++) {
         if (table[i][j] != 0) {
				cout << " " << table[i][j];
			} else {
				cout << "  " << table[i][j];
			}
		}
		
		cout << endl;
   }
}
/*
int** initializeMatrix(int** myMatrix, int size) {
	


}*/
