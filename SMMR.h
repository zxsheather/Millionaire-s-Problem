#pragma once
#include <vector>
#include "Millionaire.h"
class T{
public:
    long long num_of_people;

    long long sup;
    RSA r;
    std::vector<long long>d;
    std::vector<std::vector<long long> >l;
    std::vector<long long> L;
    long long rho;
    T(long long num,long long sup):num_of_people(num),sup(sup){
        r=RSA_Generate();
        long long sum=0;
        for(long long i=0;i<num-1;++i){
            d.push_back(Generate_x(1,(r.d-sum)/2));
            sum=d[i]+sum;
        }
        d.push_back(r.d-sum);
        l.resize(num);
        for(long long i=0;i<num;++i){
            for(int j=0;j<sup;++j){
                long long x=Generate_x(MIN,MAX);
                if(gcd(x,r.n)) {
                    l[i].push_back(x);
                }else {
                    --j;
                }
            }
        }
        for(long long j=0;j<sup;++j){
            long long mul=1;
            for(int i=0;i<num;++i){
                mul=mul*l[i][j]%r.n;
            }
            L.push_back(mul);
        }
        rho=Generate_x(MIN,MAX);
    }
};
class P{
public:
    std::vector<std::vector<long long> > b,v,v_e,E_d;
    std::vector<long long> E,D,result,rank_total;
    P(const std::vector<std::vector<long long> >&number,const T &t){
        b.resize(t.num_of_people);
        v.resize(t.num_of_people);
        v_e.resize(t.num_of_people);
        E_d.resize(t.num_of_people);
        for(long long i=0;i<t.num_of_people;++i) {
            for(long long k=0;k<=number[i][0]-2;++k) {
                b[i].push_back(0);
            }
            for(long long j=1;j<=number[i].size()-1;++j) {
                for(long long k=number[i][j-1]-1;k<=number[i][j]-2;++k) {
                    b[i].push_back(j);
                }
            }
            for(long long k=number[i][number[i].size()-1]-1;k<t.sup;++k) {
                b[i].push_back(number[i].size());
            }
        }

        for(long long i=0;i<t.num_of_people;++i) {
            for(long long j=0;j<b[i].size();++j) {
                v[i].push_back(Quick_Pow(t.rho,b[i][j],t.r.n));
            }
        }

        for(long long i=0;i<t.num_of_people;++i) {
            for(long long j=0;j<b[i].size();++j) {
                v_e[i].push_back(Quick_Pow(v[i][j]*t.l[i][j]%t.r.n,t.r.e,t.r.n));
            }
        }

        for(long long j=0;j<t.sup;++j) {
            long long mul=1;
            for(long long i=0;i<t.num_of_people;++i) {
                mul=mul*v_e[i][j]%t.r.n;
            }
            E.push_back(mul);
        }

        for(long long i=0;i<t.num_of_people;++i) {
            for(long long j=0;j<v[i].size();++j) {
                E_d[i].push_back(Quick_Pow(E[j],t.d[i],t.r.n));
            }
        }

        for(long long j=0;j<t.sup;++j) {
            long long mul=1;
            for(long long i=0;i<t.num_of_people;++i) {
                mul=mul*E_d[i][j]%t.r.n;
            }
            D.push_back(mul);
        }

        for(long long j=0;j<t.sup;++j) {
            if(D[j]%t.L[j]==0) {
                result.push_back(D[j]/t.L[j]);
            }else {
                result.push_back(D[j]*mod_reverse(t.L[j],t.r.n)%t.r.n);
            }
        }

        long long h=0;
        for(long long j=0;j<t.sup;++j) {
            while(true) {
                if(Quick_Pow(t.rho,h,t.r.n)==result[j]) {
                    rank_total.push_back(h);
                    break;
                }else {
                    ++h;
                }
            }
        }
    }
};