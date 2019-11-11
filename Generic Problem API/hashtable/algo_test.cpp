#include "algo.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <list>
#include <math.h>
#include <string>
#include <vector>

using namespace std;

unsigned int hashingFunction(int nr){
    return nr  % 10;
}

unsigned int hashingFunction1(int nr){
    return 13*nr + 71 * sqrt(nr);
}

unsigned int hashingFunction2(int nr){
	srand(time(NULL));
    return 91*nr + 71 * sqrt(nr) + 13 * rand() % 10000;
}

int main(){
	int nrTest;
	int numOfLinesToTest;
	int numOfLinesToVerify;

	Hashtable<int, int> my_table(10, &hashingFunction); // adauga un undex (1 sau 2) pentru a schimba functia de HASH

	cin >> nrTest;

	if (nrTest == 1) {
		cin >> numOfLinesToTest;
		cin >> numOfLinesToVerify;
		int key[numOfLinesToTest];
		int value[numOfLinesToTest];
		int auxKey[numOfLinesToVerify];

		for(int i = 0; i < numOfLinesToTest; ++i) {
			cin >> key[i];
			cin >> value[i];
			my_table.put(key[i], value[i]);
		}

		for(int j = 0; j < numOfLinesToVerify; ++j) {
			cin >> auxKey[j];
		}

		for(int j = 0; j < numOfLinesToVerify; ++j) {
			bool check = my_table.has_key(auxKey[j]);
			if (check) {
				cout << "Table has key " << auxKey[j];

				int aux = my_table.get(key[j]);
				cout << " and its value is " << aux << "\n";
			} else {
				cout << "Table does not have the key " << auxKey[j] << "\n";
			}
		}
	}

	if (nrTest == 2) {
		cin >> numOfLinesToTest;
		cin >> numOfLinesToVerify;
		int key[numOfLinesToTest];
		int value[numOfLinesToTest];
		for(int i = 0; i < numOfLinesToTest; ++i) {
			cin >> key[i];
			cin >> value[i];
			my_table.put(key[i], value[i]);
		}

		for(int j = 0; j < numOfLinesToVerify; ++j) {
			int auxKey;
			cin >> auxKey;

			my_table.remove(auxKey);
		}

		for(int i = 0; i < numOfLinesToTest; ++i) {
			bool check = my_table.has_key(key[i]);
			if (check) {
				cout << "Table has key " << key[i];

				int aux = my_table.get(key[i]);
				cout << " and its value is " << aux << "\n";
			} else {
				cout << "Table does not have the key " << key[i] << "\n";
			}
		}
	}

	if (nrTest == 3) {
		cin >> numOfLinesToTest;
		cin >> numOfLinesToVerify;
		int key[numOfLinesToTest];
		int value[numOfLinesToTest];
		for(int i = 0; i < numOfLinesToTest; ++i) {
			cin >> key[i];
			cin >> value[i];
			my_table.put(key[i], value[i]);
		}

		for(int j = 0; j < numOfLinesToVerify; ++j) {
			int auxKey;
			int auxValue;

			cin >> auxKey;
			cin >> auxValue;

			my_table.modify(auxKey, auxValue);
		}

		for(int i = 0; i < numOfLinesToTest; ++i) {
			bool check = my_table.has_key(key[i]);
			if (check) {
				cout << "Table has key " << key[i];

				int aux = my_table.get(key[i]);
				cout << " and its value now is " << aux << "\n";
			} else {
				cout << "Table does not have the key " << key[i] << "\n";
			}
		}
	}

	if (nrTest == 4) {
		string line;
		int i = 0;
		int l = 0;
		clock_t begin;
		clock_t end;

		double elapsed_secs_put;
		double elapsed_secs_remove;
		double elapsed_secs_modify;

		// Testarea operatiei "put"
		begin = clock();

		while (i < 100000) {
			i++;
			my_table.put(i, i);
		}
		
		end = clock();
		elapsed_secs_put = double(end - begin) / CLOCKS_PER_SEC;
		cout << "put: " << elapsed_secs_put  << '\n';


		// Testarea operatiei "modify"
		begin = clock();

		while (l < i) {
			l++;
			my_table.modify(l, l*sqrt(i/l));
		}

		end = clock();
		elapsed_secs_modify = double(end - begin) / CLOCKS_PER_SEC;
		cout << "modify: " << elapsed_secs_modify << '\n';


		// Testarea operatiei "remove"
		begin = clock();

		while (i!=0) {
			my_table.remove(i);
			--i;;
		}

		end = clock();
		elapsed_secs_remove = double(end - begin) / CLOCKS_PER_SEC;
		cout << "remove: " << elapsed_secs_remove << '\n';

	}

	if (nrTest == 5) {
		string line;
		int i = 0;
		int j = 0;
		int l = 0;
		clock_t begin;
		clock_t end;

		double elapsed_secs_put;
		double elapsed_secs_remove;
		double elapsed_secs_modify;

		// Testarea operatiei "put"
		begin = clock();

		while (i < 100000) {
			i++;
			my_table.put(i, i);
		}
		
		end = clock();
		elapsed_secs_put = double(end - begin) / CLOCKS_PER_SEC;
		cout << "put: " << elapsed_secs_put  << '\n';


		// Testarea operatiei "modify"
		begin = clock();

		while (l < i) {
			l++;
			my_table.modify(l, l*sqrt(i/l));
		}

		end = clock();
		elapsed_secs_modify = double(end - begin) / CLOCKS_PER_SEC;
		cout << "modify: " << elapsed_secs_modify << '\n';


		// Testarea operatiei "remove"
		begin = clock();

		while (j < i) {
			my_table.remove(j);
			++j;
		}

		end = clock();
		elapsed_secs_remove = double(end - begin) / CLOCKS_PER_SEC;
		cout << "remove: " << elapsed_secs_remove << '\n';

	}

	if (nrTest == 6) {
		string line;
		int numOfLinesToVerify1;
		cin >> numOfLinesToTest;
		cin >> numOfLinesToVerify;
		cin >> numOfLinesToVerify1;
		int key[numOfLinesToTest];
		int value[numOfLinesToTest];
		clock_t begin;
		clock_t end;

		double elapsed_secs_put;
		double elapsed_secs_remove;
		double elapsed_secs_modify;

		// Testarea operatiei "put"
		begin = clock();
		for(int i = 0; i < numOfLinesToTest; ++i) {
			cin >> key[i];
			cin >> value[i];
			my_table.put(key[i], value[i]);
		}
		
		end = clock();
		elapsed_secs_put = double(end - begin) / CLOCKS_PER_SEC;
		cout << "put: " << elapsed_secs_put  << '\n';


		// Testarea operatiei "modify"
		begin = clock();

		for(int j = 0; j < numOfLinesToVerify; ++j) {
			int auxKey;
			int auxValue;

			cin >> auxKey;
			cin >> auxValue;

			my_table.modify(auxKey, auxValue);
		}

		end = clock();
		elapsed_secs_modify = double(end - begin) / CLOCKS_PER_SEC;
		cout << "modify: " << elapsed_secs_modify << '\n';


		// Testarea operatiei "remove"
		begin = clock();

		for(int j = 0; j < numOfLinesToVerify1; ++j) {
			int auxKey;
			cin >> auxKey;

			my_table.remove(auxKey);
		}

		end = clock();
		elapsed_secs_remove = double(end - begin) / CLOCKS_PER_SEC;
		cout << "remove: " << elapsed_secs_remove << '\n';
	}
	return 0;
}
