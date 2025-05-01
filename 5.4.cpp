#include <iostream>
using namespace std;

class Fahrenheit;

class Celsius {
public:
    float temp;

    Celsius() {
        temp = 0;
    }

    Celsius(float t) {
        temp = t;
    }

    Fahrenheit toFahrenheit();

    bool operator==(Celsius c) {
        return temp == c.temp;
    }
};

class Fahrenheit {
public:
    float temp;

    Fahrenheit() {
        temp = 32;
    }

    Fahrenheit(float t) {
        temp = t;
    }

    Celsius toCelsius();

    bool operator==(Fahrenheit f) {
        return temp == f.temp;
    }
};

Fahrenheit Celsius::toFahrenheit() {
    return Fahrenheit((temp * 9.0 / 5.0) + 32);
}

Celsius Fahrenheit::toCelsius() {
    return Celsius((temp - 32) * 5.0 / 9.0);
}

int main() {
    int num;
    cout << "Enter number of temperatures to convert: ";
    cin >> num;

    cout << "\n--- Celsius to Fahrenheit ---" << endl;
    for (int i = 0; i < num; i++) {
        float cVal;
        cout << "Enter temperature in Celsius: ";
        cin >> cVal;
        Celsius c(cVal);
        Fahrenheit f = c.toFahrenheit();
        cout << c.temp << "C = " << f.temp << "F" << endl;
    }

    cout << "\n--- Fahrenheit to Celsius ---" << endl;
    for (int i = 0; i < num; i++) {
        float fVal;
        cout << "Enter temperature in Fahrenheit: ";
        cin >> fVal;
        Fahrenheit f(fVal);
        Celsius c = f.toCelsius();
        cout << f.temp << "F = " << c.temp << "C" << endl;
    }

    cout << "\n--- Compare Temperatures ---" << endl;
    float cInput, fInput;
    cout << "Enter temperature in Celsius: ";
    cin >> cInput;
    cout << "Enter temperature in Fahrenheit: ";
    cin >> fInput;

    Celsius c1(cInput);
    Fahrenheit f1(fInput);
    if (c1 == f1.toCelsius()) {
        cout << c1.temp << "C is equal to " << f1.temp << "F" << endl;
    } else {
        cout << c1.temp << "C is NOT equal to " << f1.temp << "F" << endl;
    }

    return 0;
}
