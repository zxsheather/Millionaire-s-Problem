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

具体应用如下：
**1.直接应用**：这点是百万富翁问题的直接运用。可以直接套用该原型的公式。以此使两个乃至多个人持有的数据之间进行比较。可运用的领域包括：a.金融领域（如联合征信/信贷评估，金融机构可以将不同客户的信息通过该公式操作来评估客户之间的信用，以此来对不同的客户进行对应的处理。）b.医疗领域（患者信息处理，医院在比较患者信息时可以使用该公式，从而比较患者的病危程度，以此来进行不同危急情况的处理，从而提高医院的运行效率。/多维度健康分析 MPC赋能医疗机构对病人在多家医院的病历和智能硬件生物数据进行分析，从而在病人、医院和智能硬件厂商数据不泄露的情况下，对病人有更精准的诊断。同时，针对医疗机构的联合数据分析可以让药品研究机构对某特定地区特定病种有更全面的了解。 ）c.商业领域（不同企业间比较企业数据信息的同时为避免泄漏企业具体信息时可采用该策略）d.教育领域（比较不同地区、不同学校、不同班级、不同个体的教育资源，教育成绩时可采用该策略，避免相关信息的泄漏。） 

**2.深度应用**：百万富翁问题解决策略的本质是MPC理论框架，而MPC理论具有更广泛的应用：a.AI的进一步发展：当下的AI研究需要往AI中添加大量的数据，其中必然包含许多私人的、具备隐私性的信息。使用MPC框架可以较好的解决信息的传递；b.解决数据孤岛问题中的安全隐患，推动个人、组织之间的信息传递与交流，进一步促进全球信息化。c.MPC与区块链技术的互补结合，区块链的计算过程中并不考虑输入数据的保密性，这些输入数据在链上都是透明的、可追溯的，这在追求数据透明的应用场景如食品安全溯源自然是常规操作，但在某些场景下，输入数据有一定的机密性，不透明反而是需求。而MPC强调计算过程中输入数据的保密性，输入数据被锁在“黑箱”里。因此两者间具有融合的可能，从而塑造更完善的信息传递工具。

**3.实际的案例**：a.华控清交信息科技（北京）有限公司：这个团队通过综合运用密码学混淆电路、不经意传输、秘密分享、同态加密、同态承诺、零知识证明等多种理论和协议，结合计算机工程技术，研发出了一个软硬件结合的多方安全计算平台。据介绍，这个计算平台可以在多方输入且不暴露输入信息的情况下进行密文计算，最终得出与明文一致的密文计算结果，可支持涵盖AI算法训练在内的几乎全部计算类型和多种数据格式。目前，华控清交已经在金融行业多方联合风控、多方联合建模，能源行业风电效率优化、政府领域电子政务等场景有具体落地和试点项目。b.蚂蚁金服：今年 5 月，蚂蚁金服推出其基于 MPC 的安全计算平台“摩斯”，据称提供了一种全新的安全和保护隐私的数据合作方式，能够在本地数据不泄露、原始数据不出域的前提下，通过密码学算法，分布式执行既定逻辑的运算并获得预期结果，高效、安全地完成数据合作。目前，“摩斯”已广泛应用于联合金融风控、保险快速理赔、民生政务、多方联合营销、多方联合科研、跨境数据合作等多个领域。
#### 参考

[安全多方计算之二：一文搞懂百万富翁问题](https://blog.csdn.net/apr15/article/details/128348229?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522DC9ED0BE-F6A4-4ECC-9364-1207C2060432%2522%252C%2522scm%2522%253A%252220140713.130102334..%2522%257D&request_id=DC9ED0BE-F6A4-4ECC-9364-1207C2060432&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~top_positive~default-1-128348229-null-null.142^v100^pc_search_result_base3&utm_term=百万富翁问题&spm=1018.2226.3001.4187) <br>
[【密码学基础】RSA加密算法](https://blog.csdn.net/qq_16763983/article/details/128101681?ops_request_misc=%257B%2522request%255Fid%2522%253A%25221680307C-55C2-44EA-8D02-345C9AB8491B%2522%252C%2522scm%2522%253A%252220140713.130102334..%2522%257D&request_id=1680307C-55C2-44EA-8D02-345C9AB8491B&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~blog~top_positive~default-1-128101681-null-null.nonecase&utm_term=rsa加密&spm=1018.2226.3001.4450)
<br>
利用RSA密码体制解决安全多方多数据排序问题     邱 梅,罗守山,刘 文,陈 萍    电子学报 2009.5 Vol.37 No.5
