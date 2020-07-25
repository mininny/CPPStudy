//
//  main.cpp
//  CPPStart
//
//  Created by Minhyuk Kim on 2020/07/25.
//  Copyright © 2020 Mininny. All rights reserved.
//

#include <iostream>
#include <cmath>

void printRand();
double celciusToFarenheit(double);

int main(int argc, const char * argv[]) {
    using namespace std;
    
    cout << "Hello, World!" << endl;
    
    // Single line comment
    /* Multi-line
     comment */
    
    numberOfCarrots();
    printRand();
    convertCelsiusToFarenheit();
    
    return 0;
}

void numberOfCarrots() {
    int carrots;
    double x;
    
    cout << "당근 몇개가 있나요?" << endl;
    cin >> carrots;
    cout << "당근 " << carrots << "개를 흔들어 주세요!" << endl;
    
    x = pow(carrots, 2);
    cout << "제곱은 " << x << "개" << endl;
}

void printRand() {
    using std::cout;
    cout << "Random: " << rand() << std::endl;
    return;
}

void convertCelsiusToFarenheit() {
    double celcius;
    cout << "섭씨 온도를 입력하세요: ";
    cin >> celcius;
    cout << "화씨론: " << farenheitFrom(celcius) << endl;
}

double farenheitFrom(double celcius) {
    return celcius * 1.8 + 32.0;
}
