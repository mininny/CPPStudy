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
    
    int carrots;
    
    cout << "당근 몇개가 있나요?" << endl;
    cin >> carrots;
    cout << "당근 " << carrots << "개를 흔들어 주세요!" << endl;
    
    double x = pow(carrots, 2);
    cout << "제곱은 " << x << "개" << endl;
    
    printRand();
    
    cout << "섭씨 온도를 입력하세요: ";
    double celcius;
    cin >> celcius;
    cout << "화씨론: " << celciusToFarenheit(celcius) << endl;
    
    return 0;
}

void printRand() {
    using std::cout;
    cout << "Random: " << rand() << std::endl;
    return;
}

double celciusToFarenheit(double celcius) {
    return celcius * 1.8 + 32.0;
}
