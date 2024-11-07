//Millionaire/main.cpp
//Created by zxsheather on 24-11-6
//主程序
#include <iostream>
#include "A.h"

int main(){
    int select;
    void (*func[4])()={nullptr,Send,Receive,Check};
    while(true) {
        std::cin>>select;
        if(select==0) {
            exit(0);
        }else {
            func[select]();
        }
    }
    return 0;
}
