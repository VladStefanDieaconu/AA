#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;

int main() {

	int i;
	srand(time(NULL));

	cout << "What kind of test do you want? For which verification? [1-6]\n";
	int whichTest;
	cin >> whichTest;

	if (whichTest == 1) {
		std::ofstream test1("test1.in");
		test1 << 1 << "\n";

		cout << "How many lines of random input do you want in order to test PUT?\n";
		int linesOfInput1;
		cin >> linesOfInput1;
		test1 << linesOfInput1 << "\n";

		cout << "How many lines of random keys in order to test GET? \n";
		int linesOfInput2;
		cin >> linesOfInput2;
		test1 << linesOfInput2 << "\n";

		for(i = 0; i < linesOfInput1; ++i) {
			test1 << rand() % 10000 << " " << rand() % 10000 << '\n';
		}

		for(i = 0; i < linesOfInput2; ++i) {
			test1 << rand() % 10000 << '\n';
		}

		test1.close();
		return 0;
	}

	if (whichTest == 2) {
		std::ofstream test2("test2.in");
		test2 << 2 << "\n";

		cout << "How many lines of random input do you want in order to test PUT?\n";
		int linesOfInput1;
		cin >> linesOfInput1;
		test2 << linesOfInput1<< "\n";

		cout << "How many lines of random keys in order to test GET? \n";
		int linesOfInput2;
		cin >> linesOfInput2;
		test2 << linesOfInput2 << "\n";

		for(i = 0; i < linesOfInput1; ++i) {
			test2 << rand() % 10000 << " " << rand() % 10000 << '\n';
		}

		for(i = 0; i < linesOfInput2; ++i) {
			test2 << rand() % 10000 << '\n';
		}

		test2.close();
		return 0;
	}

	if (whichTest == 3) {
		std::ofstream test3("test3.in");
		test3 << 3 << "\n";

		cout << "How many lines of random input do you want in order to test PUT?\n";
		int linesOfInput1;
		cin >> linesOfInput1;
		test3 << linesOfInput1 << "\n";

		cout << "How many lines of random keys in order to test GET? \n";
		int linesOfInput2;
		cin >> linesOfInput2;
		test3 << linesOfInput2 << "\n";


		for(i = 0; i < linesOfInput1; ++i) {
			test3 << rand() % 10000 << " " << rand() % 10000 << '\n';
		}

		
		for(i = 0; i < linesOfInput2; ++i) {
			test3 << rand() % 10000 << '\n';
		}

		test3.close();
		return 0;
	}

	if (whichTest == 4) {
		cout << "Here you dont need any input, it works on consecutive numbers";
	}

	if (whichTest == 5) {
		cout << "Here you dont need any input, it works on consecutive numbers";
	}

	if (whichTest == 6) {
		std::ofstream test6("test6.in");
		test6 << 6 << "\n";

		cout << "How many lines of random input do you want in order to test PUT?\n";
		int linesOfInput1;
		cin >> linesOfInput1;
		test6 << linesOfInput1 << "\n";

		cout << "How many lines of random input do you want in order to test MODIFY?\n";
		int linesOfInput2;
		cin >> linesOfInput2;
		test6 << linesOfInput2 << "\n";

		cout << "How many lines of random keys in order to test remove? \n";
		int linesOfInput3;
		cin >> linesOfInput3;
		test6 << linesOfInput3 << "\n";

		for(i = 0; i < linesOfInput1; ++i) {
			test6 << rand() % 10000 << " " << rand() % 10000 << '\n';
		}


		for(i = 0; i < linesOfInput2; ++i) {
			test6 << rand() % 10000 << " " << rand() % 10000 << '\n';
		}

		for(i = 0; i < linesOfInput3; ++i) {
			test6 << rand() % 10000 << '\n';
		}

		test6.close();
		return 0;
	}

	return 0;
}
