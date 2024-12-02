#include<bits/stdc++.h>
#define int long long

std::mt19937_64 rnd(20061010);

bool check_prime(int n) {
    for (int i = 2;i * i <= n;i++)
        if (n % i == 0)
            return 0;
    return 1;
}

int generate_prime(int L,int R) {
    int p=rnd() % (R - L + 1) + L;
    while(!check_prime(p))
        p = rnd() % (R - L + 1) + L;
    return p;
}

int poww(int a, int b, int Mod) {
    int res = 1;
    while(b){
        if (b & 1)res = res * a % Mod;
        a = a * a % Mod, b >>= 1;
    }
    return res;
}

class bob;
class alice {
private:
    int num, N;
    int open_key, mod;
    int x, p;
    std::vector<int>r;
public:
    void init(int);
    void step1(int,int);
    int E(int);
    void step2(bob &Bob);
    void step5(std::vector<int>,int);
    void step6();
};

class bob {
private:
    int num, N;
    int open_key, private_key, mod, phimod;
    int y, p;
    std::vector<int>a, z;
public:
    void init(int);
    void step1(alice &Alice);
    int E(int);
    int D(int);
    void step2(int);
    void step3();
    void step4();
    void step5(alice &Alice);
};

void alice::init(int N) {std::cin >> num;this->N = N;}
void alice::step1(int open_key,int mod) {
    this->open_key = open_key,
    this->mod = mod;
    std::cout << "Alice 接受到了来自 Bob 的公钥 " << open_key << ',' << mod << "\n\n";
}
int alice::E(int x) {
    return poww(x, open_key, mod);
}
void alice::step2(bob &Bob) {
    x = rnd() % mod;
    while(E(x) < num)
        x = rnd() % mod;
    std::cout << "Alice 生成了随机数 x = " << x <<" 并且将 E(x)-i = " << E(x)-num << " 发送给了 Bob\n\n";
    Bob.step2(E(x) - num);
}

void bob::init(int N) {std::cin >> num;this->N = N;}
int bob::E(int x) {
    return poww(x, open_key, mod);
}
int bob::D(int x) {
    return poww(x, private_key, mod);
}
void bob::step2(int y) {this->y = y;}
void bob::step3() {
    
    a.resize(N + 1);
    for (int i = 1; i <= N; i++)
        a[i] = D(y+i);
    std::cout << "Bob 接受到了数字 y = " << y << " 并且计算出了如下的 N 个数字：\n";
    for (int i = 1; i <= N; i++)
        std::cout << a[i] << (i == N?'\n': ' ');
    std::cout << '\n';
}
void bob::step4() {
    
    z.resize(N + 1);
    int p = generate_prime(1000,1<<15);
    while(1) {
        for (int i = 1; i <= N; i++)
            z[i] = a[i] % p;
        auto c = z;
        sort(c.begin() + 1,c.end());
        int fl = 0;
        for (int i = 2; i <= N; i++)
            if (c[i] - c[i-1] <= 1) fl = 1;
        if (fl == 0) break;
        p = generate_prime(1000,1<<15);
    }
    this->p = p;
    std::cout << "Bob 选择了随机质数 p = " << p << " 并且计算出计算出了如下的 N 个数字：\n";
    for (int i = 1; i <= N; i++)
        std::cout << z[i] << (i == N?'\n': ' ');
    std::cout << '\n';
}

void exgcd(int a,int b,int &x,int &y) {
    if (a == 1) {
        x = 1, y = 0;
        return;
    }
    exgcd(b, a%b, x, y);
    int t = a / b;
    int tx = y, ty = x - t * y;
    x = tx, y = ty;
    assert(a * x + b * y == 1);
}

void bob::step1(alice &Alice) {
    // generate RSA,and tell Alice the open key & mod
    int p = generate_prime(1000, 1<<15);
    int q = generate_prime(1000, 1<<15);
    while(p == q)
        q = generate_prime(1000, 1<<15);
    mod = p * q, phimod = (p - 1) * (q - 1);
    open_key = rnd() % phimod;
    while(std::__gcd(open_key, phimod)!=1)
        open_key = rnd() % mod;
    int a, b;
    exgcd(open_key, phimod, a, b);
    assert(a * open_key + b * phimod == 1);
    private_key = (a % phimod + phimod) % phimod;
    // std::cerr << p << ' ' << q << '\n';
    // std::cerr << open_key << ' ' << private_key << ' ' << phimod << '\n';
    // std::cerr << "error:" << open_key * private_key % phimod <<'\n';
    assert(open_key * private_key % phimod == 1);
    std::cout << "Bob 生成了公钥 " << open_key << ',' << mod << " 与私钥 " << private_key << "\n\n";
    Alice.step1(open_key, mod);
}

void bob::step5(alice &Alice){
    std::cout << "Bob 将以下数字和 p 发送给 Alice \n";
    std::vector<int> c(N+1);
    for (int i = 1; i <= N; i++)
        if (i <= num)
            c[i] = z[i];
        else
            c[i] = (z[i] + 1) % p;
    for (int i = 1; i <= N; i++)
        std::cout << c[i] << ' ';
    std::cout << p << "\n\n";
    Alice.step5(c,p);
}

void alice::step5(std::vector<int> r, int p) {
    this->r = r,this->p = p;
}

void alice::step6() {
    std::cout << "Alice 将收到的第 i = " << num << " 位与 x mod p = " << x % p << "进行比较\n";
    std::cout << "第 i 位是 " << r[num] << "\n\n";
    if (r[num] == x % p)
        std::cout << "相同,Alice 发现自己的数小于等于对方的数\n";
    else
        std::cout << "不同,Alice 发现自己的数大于对方的数\n";
    std::cout << "Alice 再将结果告诉对方,协议结束\n";
}
