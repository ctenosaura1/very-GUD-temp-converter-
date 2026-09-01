#include <iostream>

bool chooseUnit();
void convert(bool isCelsius);

bool chooseUnit() {
	char unit;
	bool isCelsius;
	while (true) {
		std::cout << "Celsius or Fahrenheit? (C / F)\n";
		std::cin >> unit;
		if (unit == 'c' || unit == 'C' || unit == 'f' || unit == 'F') {
			break;
		}
		std::cout << "Error. Enter C or F only.\n";
	}
	return (unit == 'C' || unit == 'c');
}

void convert(bool isCelsius) {
	float temperature;
	float convertedTemperature;
	while (true) {
		std::cout << "Enter temperature (without units).\n";
		std::cin >> temperature;
		if (!std::cin.fail()) {
			break;
		}
		std::cout << "Error. Enter a number only.\n";
		std::cin.clear();
		std::cin.ignore(10000, '\n');
	}
	if (isCelsius == true) {
		convertedTemperature = temperature * 1.8f + 32.0f;
		std::cout << "Converted to Fahrenheit [" << convertedTemperature << "].\n";
	}
	else {
		convertedTemperature = (temperature - 32.0f) * 5.0f / 9.0f;
		std::cout << "Converted to Celsius [" << convertedTemperature << "].\n";
	}
}

int main() {
	while (true) {
		bool choice = chooseUnit();
		convert(choice);
		std::cout << "\n------------------------------------------------\n\n";
	}
}