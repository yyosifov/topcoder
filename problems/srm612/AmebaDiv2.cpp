#include <string>
#include <vector>
using namespace std;

class AmebaDiv2 {
	public:
	int simulate(vector <int> X, int A) {
		for(int i=0;i<X.size();i++) A = (X[i] == A) ? 2 * A : A;
		return A;
	}
};