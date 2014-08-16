#include <string>
#include <vector>
#include <iostream>
using namespace std;
typedef long long lld;

class LongLongTripDiv2 {
	public:
	string isAble(long long D, int T, int B) {
		lld t, b;
		t = T, b = B;
		
		if(t * b < D) return "Impossible";
		cout << "HERe";
		lld left = 0;
		lld right = t;
		while(right - left > 3) {
			lld mid = (left + right) / 2;
			if(mid * b > D) {
				right = mid - 1;
				continue;
			}
			lld x = D - mid * b;
			if(x + mid == t) { return "Possible"; }
			else if(x + mid > t) left = mid + 1;
			else right = mid - 1;
		}
		
		for(lld i=left;i<=right;i++) {
			lld x = D - i*b;
			if(i + x == T) return "Possible";
		}
		return "Impossible";
	}
};