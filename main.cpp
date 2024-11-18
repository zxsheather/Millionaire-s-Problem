//Millionaire/main.cpp
//Created by zxsheather on 24-11-6
//主程序
#include <iostream>
#include "Millionaire.h"
#include "SMMR.h"

int main() {
  int select;
  std::cout << "请输入指令：" << std::endl;
  std::cout << "0--终止程序。" << std::endl;
  std::cout << "1--Yao's Protocol" << std::endl;
  std::cout << "2--SMMR" << std::endl;
  std::cin >> select;
  if (select == 0) {
    exit(0);
  } else if (select == 1) {
    int select2;
    void (*func[4])() = {nullptr, Send, Receive, Check};
    while (true) {
      std::cout << "请输入指令：" << std::endl;
      std::cout << "0--终止程序" << std::endl;
      std::cout << "1--加密" << std::endl;
      std::cout << "2--解密" << std::endl;
      std::cout << "3--比较财富多少" << std::endl;
      std::cout << "4--生成RSA大数、公钥与密钥" << std::endl;
      std::cin >> select2;
      if (select2 == 0) {
        exit(0);
      } else if (select2 == 4) {
        RSA r = RSA_Generate();
        std::cout << "n=" << r.n << std::endl;
        std::cout << "公钥为" << r.e << std::endl;
        std::cout << "私钥为" << r.d << std::endl;
      } else {
        func[select2]();
      }
    }
  } else if (select == 2) {
    std::cout<<"请输入参与方的个数，以及所有数据的上限"<<std::endl;
    long long num, sup;
    std::cin>>num>>sup;

    T t(num,sup);
    std::vector<std::vector<long long> > number;
    number.resize(num);
    std::cout<<"请输入各参与方的数据个数与所需比较的数据"<<std::endl;
    for (int i = 0; i < num; ++i) {
      long long N;
      std::cin>>N;
      for (int j = 0; j < N; ++j) {
        long long a;
        std::cin >> a;
        number[i].push_back(a);
      }
    }
    P p(number, t);
    std::cout << "大数n=" << t.r.n << std::endl;
    std::cout << "公钥e=" << t.r.e << std::endl;
    std::cout << "私钥d=" << t.r.d << std::endl;
    std::cout << "私钥分发: ";
    for (int i = 0; i < num; ++i) {
      std::cout << t.d[i] << ' ';
    }
    std::cout << std::endl;
    std::cout << std::endl;

    for (int j = 0; j < num; ++j) {
      for (int i = 0; i < sup; ++i) {
        std::cout << p.b[j][i] << ' ';
      }
      std::cout << std::endl;
    }
    std::cout << std::endl;

    for (int j = 0; j < num; ++j) {
      for (int i = 0; i < sup; ++i) {
        std::cout << p.v[j][i] << ' ';
      }
      std::cout << std::endl;
    }
    std::cout << std::endl;

    for (int j = 0; j < num; ++j) {
      for (int i = 0; i < sup; ++i) {
        std::cout << p.v_e[j][i] << ' ';
      }
      std::cout << std::endl;
    }
    std::cout << std::endl;

    for (int i = 0; i < sup; ++i) {
      std::cout << p.E[i] << ' ';
    }
    std::cout << std::endl << std::endl;

    for (int i = 0; i < sup; ++i) {
      std::cout << p.D[i] << ' ';
    }
    std::cout << std::endl << std::endl;

    for (int i = 0; i < sup; ++i) {
      std::cout << p.result[i] << ' ';
    }
    std::cout << std::endl << std::endl;

    for (int i = 0; i < sup; ++i) {
      std::cout << p.rank_total[i] << ' ';
    }
    std::cout << std::endl << std::endl;
  }
  return 0;
}
