//Millionaire/main.cpp
//Created by zxsheather on 24-11-6
//主程序
#include <iostream>
#include "Millionaire.h"

int main(){
    int select;
    void (*func[5])()={nullptr,RSA_Generate,Send,Receive,Check};
    while(true) {
        std::cout<<"请输入指令："<<std::endl;
        std::cout<<"0--终止程序"<<std::endl;
        std::cout<<"1--生成RSA大数、公钥与密钥"<<std::endl;
        std::cout<<"2--加密"<<std::endl;
        std::cout<<"3--解密"<<std::endl;
        std::cout<<"4--比较财富多少"<<std::endl;
        std::cin>>select;
        if(select==0) {
            exit(0);
        }else {
            func[select]();
        }
    }
    return 0;
}
