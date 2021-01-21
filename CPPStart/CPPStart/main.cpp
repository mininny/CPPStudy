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
    
    cout << "당근 몇 개가 있나요?" << endl;
    cout << "How many carrots do you have?" << endl;
    cout << "ニンジンはいくつありますか。" << endl;
    cout << "¿cuantas zanahorias tienes?" << endl;
    cin >> carrots;
    cout << "당근 " << carrots << "개를 흔들어 주세요!" << endl;
    cout << "Shake" << carrots << "carrots!" << endl;
    cout << "ニンジン" << carrots << "を振ってください。" << endl;
    cout << "¡agitar" << carrots << "zanahorias!" << endl;
    
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
    
    cout << "섭씨 온도를 입력하세요: " << endl;
    cout << "Enter celsius-unit temperature: " << endl;
    cout << "摂氏温度を入力してください: " << endl;
    cout << "ingrese la temperatura en unidad celsius: " << endl;
    cout << "Input: ";
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
