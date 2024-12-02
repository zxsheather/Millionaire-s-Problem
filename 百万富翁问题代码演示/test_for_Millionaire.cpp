#include<bits/stdc++.h>
#include "Alice_and_Bob.h"
using namespace std;

signed main() {
    std::cout<< "输入值域以及 Alice 和 Bob 各自的数字\n";
    int N;
    std::cin >> N;
    alice Alice;
    bob Bob;
    Alice.init(N),Bob.init(N);
    Bob.step1(Alice);
    Alice.step2(Bob);
    Bob.step3();
    Bob.step4();
    Bob.step5(Alice);
    Alice.step6();
    return 0;
}