//Amir Valeev CSE-06
// we are asked to implement fst, but i don't know how to fix overlapping
// without additional memory
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class valeev_amir_FST {
private:
    string substring; // Substring for analyzing
    int state;
    int count;       // Our result

public:
    // Constructor
    valeev_amir_FST(string sub) : substring(sub), state(0), count(0) {}

    void process(char ch) {
        // if we have 1 matching char and next is not matching
        while (state > 0 && ch != substring[state]) {
            state = 0;
        }

        // if elements are equal, increase state
        if (ch == substring[state]) {
            state++;
        }

        // if we have found string
        if (state == substring.length()) {
            count++;
            state = 0;
        }
    }

    // getter for result
    int getResult() const {
        return count;
    }
};

int main() {
    string C, S;
    cin >> C >> S;

    // creating fst
    valeev_amir_FST fst(C);

    // Checking every symbol
    for (char ch : S) {
        fst.process(ch);
    }

    int result = fst.getResult();

    // printing result
    if (result == 0) {
        cout << "NOT DETECTED" << endl;
    } else {
        cout << result << endl;
    }

    return 0;
}
