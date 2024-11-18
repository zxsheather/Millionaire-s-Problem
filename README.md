# Millionaire's Problem

## 函数及时间复杂度分析

**Generate_x**:产生随机大整数。 $$O(1)$$

**check_prime**:检查是否为质数。 $$O(\sqrt{p})$$

**Generate_p**:产生随机大质数。 $$O(k*\sqrt{p})$$，k表示产生多少大整数会产生一个质数。k与产生整数的范围相关，整数越大，k越大。

**gcd**:判断最大公约数是否为1。 $$O(log(min(x,y))$$

**exgcd**:拓展欧几里得。 $$O(log(min(a,b)))$$

**Quick_Pow**:快速幂。 $$O(log(key))$$

**RSA_Generate**：产生大数、公钥、私钥。 $$O(k*\sqrt{p}+log(f))$$,f为欧拉函数。

**Send**: 加密。 $$O(log(publickey)$$

**Recieve**：解密。 $$O(k*\sqrt{p}+Nlog(privatekey))$$

**Check**: 比较。 $$O(N)$$

#### 参考

[安全多方计算之二：一文搞懂百万富翁问题](https://blog.csdn.net/apr15/article/details/128348229?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522DC9ED0BE-F6A4-4ECC-9364-1207C2060432%2522%252C%2522scm%2522%253A%252220140713.130102334..%2522%257D&request_id=DC9ED0BE-F6A4-4ECC-9364-1207C2060432&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~top_positive~default-1-128348229-null-null.142^v100^pc_search_result_base3&utm_term=百万富翁问题&spm=1018.2226.3001.4187) <br>
[【密码学基础】RSA加密算法](https://blog.csdn.net/qq_16763983/article/details/128101681?ops_request_misc=%257B%2522request%255Fid%2522%253A%25221680307C-55C2-44EA-8D02-345C9AB8491B%2522%252C%2522scm%2522%253A%252220140713.130102334..%2522%257D&request_id=1680307C-55C2-44EA-8D02-345C9AB8491B&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~blog~top_positive~default-1-128101681-null-null.nonecase&utm_term=rsa加密&spm=1018.2226.3001.4450)
<br>
利用RSA密码体制解决安全多方多数据排序问题  邱 梅,罗守山,刘 文,陈 萍  电子学报 2009.5 Vol.37 No.5
