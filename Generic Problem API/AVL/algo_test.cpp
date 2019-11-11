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

int main()
{
    BST t;

    int nrTest;
    int numOfLinesToTest;

    cin >> nrTest;

    if (nrTest == 1) {
        cin >> numOfLinesToTest;
        int inserts[numOfLinesToTest];

        for(int i = 0; i < numOfLinesToTest; ++i) {
            cin >> inserts[i];
            t.insert(inserts[i]);
        }
         t.display();  
    }

    if (nrTest == 2) {
        cin >> numOfLinesToTest;
        int inserts[numOfLinesToTest];

        int numOfRemoves;
        cin >> numOfRemoves;

        int removeThis;

        for(int i = 0; i < numOfLinesToTest; ++i) {
            cin >> inserts[i];
            t.insert(inserts[i]);
        } 

        for (int i = 0; i < numOfRemoves; ++i) {
            cin >> removeThis;
            t.remove(removeThis);
        }
         t.display();  
    }

    if (nrTest == 3) {
        cin >> numOfLinesToTest;
        int inserts[numOfLinesToTest];

        int numOfModifiers;
        int auxX;
        int auxY;
        cin >> numOfModifiers;

        int numOfRemoves;
        cin >> numOfRemoves;
        int removeThis;

        for(int i = 0; i < numOfLinesToTest; ++i) {
            cin >> inserts[i];
            t.insert(inserts[i]);
        }

        for(int i = 0; i < numOfModifiers; ++i) {
            cin >> auxX;
            cin >>auxY;
            t.modify(auxX, auxY);
        }

        for (int i = 0; i < numOfRemoves; ++i) {
            cin >> removeThis;
            t.remove(removeThis);
        }
         t.display();  
    }

    if (nrTest == 4) {
        clock_t begin;
        clock_t end;

        double elapsed_secs_put;

        // Testarea operatiei "insert"
        begin = clock();

        for(int i = 0; i < 1000000; ++i) {
            t.insert(i);
        }
        
        end = clock();
        elapsed_secs_put = double(end - begin) / CLOCKS_PER_SEC;
        cout << "insert time ascending: " << elapsed_secs_put  << '\n';
        
    }

    if (nrTest == 5) {
        srand(time(NULL));

        clock_t begin;
        clock_t end;

        double elapsed_secs_put;

        // Testarea operatiei "insert"
        begin = clock();

        for(int i = 0; i < 1000000; ++i) {
            t.insert(1000000-i);
        }
        
        end = clock();
        elapsed_secs_put = double(end - begin) / CLOCKS_PER_SEC;
        cout << "insert time: " << elapsed_secs_put  << '\n';
         
    }

    if (nrTest == 6) {
        srand(time(NULL));

        clock_t begin;
        clock_t end;

        double elapsed_secs_put;

        // Testarea operatiei "insert"
        begin = clock();

        for(int i = 0; i < 1000000; ++i) {
            t.insert(rand() % 10000);
        }
        
        end = clock();
        elapsed_secs_put = double(end - begin) / CLOCKS_PER_SEC;
        cout << "insert time: " << elapsed_secs_put  << '\n';
         
    }

    if (nrTest == 7) {

        string line;
        int i = 0;
        int l = 0;
        clock_t begin;
        clock_t end;

        double elapsed_secs_put;
        double elapsed_secs_remove;
        double elapsed_secs_modify;

        cin >> numOfLinesToTest;

        int numOfModifiers;
        int auxX;
        int auxY;
        int aux;
        cin >> numOfModifiers;

        int numOfRemoves;
        cin >> numOfRemoves;
        int removeThis;

        // Testarea operatiei "insert"
        begin = clock();

        for(int i = 0; i < numOfLinesToTest; ++i) {
            cin >> aux;
            t.insert(aux);
        }

        end = clock();
        elapsed_secs_put = double(end - begin) / CLOCKS_PER_SEC;
        cout << "put: " << elapsed_secs_put  << '\n';

        // Testarea operatiei "modify"
        begin = clock();

        for(int i = 0; i < numOfModifiers; ++i) {
            cin >> auxX;
            cin > >auxY;
            t.modify(auxX, auxY);
        }

        end = clock();
        elapsed_secs_modify = double(end - begin) / CLOCKS_PER_SEC;
        cout << "modify: " << elapsed_secs_modify << '\n';


        // Testarea operatiei "remove"
        begin = clock();

        for (int i = 0; i < numOfRemoves; ++i) {
            cin >> removeThis;
            t.remove(removeThis);
        }

        end = clock();
        elapsed_secs_remove = double(end - begin) / CLOCKS_PER_SEC;
        cout << "remove: " << elapsed_secs_remove << '\n';
         
    }


    return 0;
}