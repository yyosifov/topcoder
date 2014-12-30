#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#define FOR(i,n) for(int i=0;i<n;i++)
using namespace std;

class TheKingsFactorization {
    public:
    bool isPrime(long long dig) {
        if(dig == 2 || dig == 3) return true;

        if(dig % 2 == 0) return false;
        if(dig % 3 == 0) return false;

        for(long long i = 5; i*i<=dig; i+=2) {
            if(dig % i == 0) return false;
        }

        return true;
    }
    vector<long long> getVector(long long N, vector<long long> primes) {
        int ind = 1, pSize = primes.size();
        vector<long long> res;
        res.push_back(primes[0]);
        N /= primes[0];

        while(ind < pSize) {
            if(N == 1) return res;

            if(N % primes[ind-1] == 0) {
                res.push_back(primes[ind-1]);
                N /= primes[ind-1];
            } else {
                long long next = N / primes[ind];
                if(isPrime(next)) {
                    res.push_back(next);
                    N /= next;
                }
                else {
                    bool found = false;
                    for(long long i=primes[ind-1]+1;i<primes[ind];i++) {
//                      cout << i << " " << isPrime(i) << " " << N << " " << N % i << endl;
                        if(N % i == 0 && isPrime(i)) {
                            res.push_back(i);
                            N /= i;
                            found = true;
                            break;
                        }
                    }

                    if(!found) {
                        res.push_back(primes[ind]);
                        N /= primes[ind];
                    }
                }
            }

            res.push_back(primes[ind]);
            N /= primes[ind];
            ind++;
        }

        if(N != 1) {
            res.push_back(N);
        }

        return res;
    }
};

// Powered by PopsEdit
