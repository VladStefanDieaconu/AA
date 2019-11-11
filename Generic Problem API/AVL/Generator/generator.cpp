#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;

int main() {

	int i;
	srand(time(NULL));

	cout << "What kind of test do you want? For which verification? [1-7]\n";
	int whichTest;
	cin >> whichTest;

	if (whichTest == 1) {
		std::ofstream test1("test1.in");
		test1 << 1 << "\n";

		cout << "How many lines of random input do you want in order to test PUT?\n";
		int linesOfInput1;
		cin >> linesOfInput1;
		test1 << linesOfInput1 << "\n";
		for(i = 0; i < linesOfInput1; ++i) {
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

		cout << "How many lines do you want to remove? \n";
		int linesOfInput2;
		cin >> linesOfInput2;
		test2 << linesOfInput2 << "\n";

		for(i = 0; i < linesOfInput1; ++i) {
			test2 << rand() % 10000 <<'\n';
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

		cout << "How many modifications do you want do make? \n";
		int linesOfInput2;
		cin >> linesOfInput2;
		test3 << linesOfInput2 << "\n";

		cout << "How many removes do you want to make? \n";
		int linesOfInput3;
		cin >> linesOfInput3;
		test3 << linesOfInput3 << "\n";


		for(i = 0; i < linesOfInput1; ++i) {
			test3 << rand() % 10000 << '\n';
		}

		for(i = 0; i < linesOfInput1; ++i) {
			test3 << rand() % 10000 << " " << rand() % 10000 << '\n';
		}


		for(i = 0; i < linesOfInput3; ++i) {
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
		cout << "Here you dont need any input, it works on consecutive numbers";
	}

	if (whichTest == 7) {
		std::ofstream test7("test7.in");
		test7 << 7 << "\n";

		cout << "How many lines of random input do you want in order to test PUT?\n";
		int linesOfInput1;
		cin >> linesOfInput1;
		test7 << linesOfInput1 << "\n";

		cout << "How many lines of random input do you want in order to test MODIFY?\n";
		int linesOfInput2;
		cin >> linesOfInput2;
		test7 << linesOfInput2 << "\n";

		cout << "How many nodes do you wish to remove? \n";
		int linesOfInput3;
		cin >> linesOfInput3;
		test7 << linesOfInput3 << "\n";

		for(i = 0; i < linesOfInput1; ++i) {
			test7 << rand() % 10000 << '\n';
		}


		for(i = 0; i < linesOfInput2; ++i) {
			test7 << rand() % 10000 << " " << rand() % 10000 << '\n';
		}

		for(i = 0; i < linesOfInput3; ++i) {
			test7 << rand() % 10000 << '\n';
		}

		test7.close();
		return 0;
	}

	return 0;
}
