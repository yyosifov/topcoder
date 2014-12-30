#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#define FOR(i,n) for(int i=0;i<n;i++)
using namespace std;

class TheKingsArmyDiv2 {
    public:
    int getNumber(vector <string> state) {
        bool hasHappy = false;
        FOR(i, state.size()) {
            FOR(j, state[i].size()) {
                if(state[i][j] == 'S') continue;
                if(state[i][j] == 'H') hasHappy = true;

                // state[i][j];
                // check row
                if(j + 1 < state[i].size()) {
                    if(state[i][j] == state[i][j+1]) {
                        return 0;
                    }
                }

                // check col
                if(i+1 < state.size()) {
                    if(state[i][j] == state[i+1][j]) {
                        return 0;
                    }
                }
            }
        }
        return hasHappy ? 1 : 2;
    }
};

// Powered by PopsEdit
