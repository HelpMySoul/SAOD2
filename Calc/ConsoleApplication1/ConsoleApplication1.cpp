#include <iostream>
using namespace std;

int Calc(int argc, char* argv[])
{
	for (int i = 0; argv[2][i] != 0; i++) {
		if (argv[2][0] != '-' && sizeof(argv) != 1) {
			if (!isdigit(argv[2][i])) {
				throw exception("Первое число введено неверно");
			}
		}
	}
	for (int i = 0; argv[3][i] != 0; i++) {
		if (argv[3][0] != '-' && sizeof(argv) != 1) {
			if (!isdigit(argv[3][i])) {
				throw exception("Второе число введено неверно");
			}
		}
	}
	if (string(argv[1]) == "add") {
		return atof(argv[2]) + atof(argv[3]);
	}
	if (string(argv[1]) == "sub") {
		return atof(argv[2]) - atof(argv[3]);
	}
	if (string(argv[1]) == "mul") {
		return atof(argv[2]) * atof(argv[3]);
	}
	if (string(argv[1]) == "div") {
		if (argv[3][0] != '0' && (argv[3][1] != '0' && argv[3][0] != '-')) {
			return atof(argv[2]) / atof(argv[3]);
		}
		else {
			throw exception("Деление на 0");
		}
	}
	throw exception("Неправильная команда");
}
int main(int argc, char* argv[]) {
	cout << Calc(argc, argv);
}