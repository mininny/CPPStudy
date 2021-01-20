//
//  main.cpp
//  CPPStart
//
//  Created by Minhyuk Kim on 2020/07/25.
//  Copyright © 2020 Mininny. All rights reserved.
//

#include <iostream>
#include <cmath>

using namespace std;

void numberOfCarrots() {
    int carrots;
    double x;
    
    cout << "How many carrots do you have?" << endl;
    cin >> carrots;
    cout << "Shake" << carrots << "carrots!" << endl;
    
    x = pow(carrots, 2);
    cout << "The squared count of carrots is " << x << "." << endl;
}

void printRand() {
    using std::cout;
    cout << "Random: " << rand() << std::endl;
    return;
}

double farenheitFrom(double celcius) {
    return celcius * 1.8 + 32.0;
}

void convertCelsiusToFarenheit() {
    double celcius;
    
    cout << "Enter celsius-unit temperature: ";
    cin >> celcius;
    cout << "As Fahrenheit-unit: " << farenheitFrom(celcius) << endl;
}

int main(int argc, const char * argv[]) {
    cout << "Hello, World!" << endl;
    
    // Single line comment
    /* Multi-line
     comment */
    
    numberOfCarrots();
    printRand();
    convertCelsiusToFarenheit();
    
    return 0;
}
