//Amir Valeev CSE-06
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class lastname_firstname_FST {
private:
    string substring; // Substring for analyzing
    int state;
    int count;       // Our result
    vector<int> overlap; // array which helps to deal with overlapping

    // filling array with lengths of ovelapping substrings
    void Overlap() {
        int len = 0;
        overlap[0] = 0;
        int i = 1;

        while (i < substring.length()) {
            if (substring[i] == substring[len]) {
                len++;
                overlap[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = overlap[len - 1];
                } else {
                    overlap[i] = 0;
                    i++;
                }
            }
        }
    }

public:
    // Constructor
    lastname_firstname_FST(string sub) : substring(sub), state(0), count(0) {
        overlap.resize(substring.length(), 0);
        Overlap();
    }

    void process(char ch) {
        // if we have 1 matching char and next is not matching
        while (state > 0 && ch != substring[state]) {
            state = overlap[state - 1];
        }

        // if elements are equal, increase state
        if (ch == substring[state]) {
            state++;
        }

        // if we have found string
        if (state == substring.length()) {
            count++;
            state = overlap[state - 1]; // fixing overlapping problem
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
    lastname_firstname_FST fst(C);

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
