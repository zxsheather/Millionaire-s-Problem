//Millionaire/Millionaire.h
//Created by zxsheather on 24-11-6
//各函数的实现

#ifndef Millionaire_H
#define Millionaire_H
#include<iostream>
#include<random>
#include<cstdlib>
#include<cmath>
#define MAX 1000
#define MIN 100

long long public_key;
long long private_key;
long long n;

//随机选择整数x；
long long Generate_x(long long min, long long max) {
    std::default_random_engine e{std::random_device{}()};
    srand(e());
    long long l = (rand() % (max - min)) + min;
    return l;
}

//检查是否为质数
bool check_prime(long long p) {
    if(p%2==0) {
        return false;
    }
    for (long long i = 3; i <= static_cast<long long>(sqrt(p)); i+=2) {
        if (p % i == 0) {
            return false;
        }
    }
    return true;
}

//随机选择大质数
long long Generate_p() {
    while (true) {
        long long p = Generate_x(MIN,MAX);
        if (check_prime(p)) {
            return p;
        }
    }
}

//判断互质与否
bool gcd(long long x, long long y) {
    if (x > y) {
        std::swap(x, y);
    }
    while (x != 0) {
        long long r = y % x;
        y = x;
        x = r;
    }
    if (y == 1) {
        return true;
    } else {
        return false;
    }
}

//拓展欧几里得算法，用于求私钥
//返回d = gcd(a, b);和对应于等式ax + by = d中的x、y
long long exgcd(long long a, long long b, long long &x, long long &y){ //扩展欧几里得
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    long long r = exgcd(b, a % b, x, y);
    long long t = x;
    x = y;
    y = t - a / b * y;
    return r;
}
long long mod_reverse(long long a, long long b){ //a*x=1(mod b) 求a的逆元x
    long long d, x, y;
    d = exgcd(a, b, x, y);
    if (d == 1)
        return (x % b + b) % b;
    else
        return -1;
}
struct RSA{
    long long n;
    long long e;
    long long d;
};
//产生大数n,公钥与私钥
RSA RSA_Generate() {
    long long p = Generate_p();
    long long q = Generate_p();
    n = p * q;
    long long f = (p - 1) * (q - 1);
    while (true) {
        public_key = Generate_x(MIN,MAX);
        if (gcd(public_key, f)) {
            break;
        }
    }
    private_key = mod_reverse(public_key, f);
    return (RSA){n,public_key,private_key};
    std::cout << "n=" << n << std::endl;
    std::cout << "公钥为" << public_key << std::endl;
    std::cout << "私钥为" << private_key << std::endl;
}

//快速幂
long long Quick_Pow(long long x, long long key, long long p) {
    long long s = 1, count = x;
    while (key > 0) {
        if ((key & 1) == 1) {
            s = s * count % p;
        }
        count = count * count % p;
        key >>= 1;
    }
    return s;
}

void Send() {
    std::cout<<"请输入大数n"<<std::endl;
    std::cin>>n;
    std::cout<<"请输入公钥"<<std::endl;
    std::cin>>public_key;
    long long x = Generate_x(MIN,MAX);
    std::cout << "x=" << x << std::endl;
    int i;
    int N;
    std::cout << "请输入你的财富i和你们约定的财富上限N:" << std::endl;
    std::cin >> i >> N;
    std::cout << "密文为: " << Quick_Pow(x, public_key, n) - i << std::endl;
}

void Receive() {
    long long ciphertext, j, N;
    std::cout << "请输入密文: " << std::endl;
    std::cin >> ciphertext;
    std::cout << "请输入私钥、n与N: " << std::endl;
    std::cin >> private_key >> n >> N;
    std::cout << "请输入你的财富: " << std::endl;
    std::cin >> j;
    long long p = Generate_p();
    std::cout << "p=" << p << std::endl;
    for (long long k = 1; k <= j; ++k) {
        std::cout << Quick_Pow(ciphertext + k, private_key, n) % p << ' ';
    }
    for (long long k = j + 1; k <= N; ++k) {
        std::cout << Quick_Pow(ciphertext + k, private_key, n) % p + 1 << ' ';
    }
    std::cout<<std::endl;
}

void Check() {
    long long i, p, N, a, b;
    std::cout << "请输入你的财富: " << std::endl;
    std::cin >> i;
    std::cout << "请输入随机数x、N、p与数组: " << std::endl;
    std::cin >> a >> N >> p;
    for (long long k = 0; k < i; ++k) {
        std::cin >> b;
    }
    if (a % p == b % p) {
        std::cout << "他的财富较多"<<std::endl;
    } else {
        std::cout << "你的财富较多"<<std::endl;
    }
}
#endif //Millionaire_H
