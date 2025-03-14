// Amir Valeev CSE-06
#include <iostream>
#include <vector>
#include <string>


using namespace std;
vector<int> counting(vector<vector<string>> languages, vector<string> sentence){
    vector<int> count (languages.size());
    // initializing vector count with zeros
    for (int i = 0; i < languages.size(); i++){
        count[i] = 0;
    }
    for (int i = 0; i < languages.size(); i++){
        for (int j = 0; j < languages[i].size(); j++){
            for (int k = 0; k < sentence.size(); k++){
                // checking if word from language equals to word from sentence
                if (languages[i][j] == sentence[k]){
                    count[i]++;
                }
            }
        }
    }
    return count;
}
// function for finding the maximum value in vector
int findMax(vector<int> count){
    int max = -10^10;
    for (int i: count){
        if (i > max){
            max = i;
        }
    }
    return max;
}
int main(){
    int N;
    cin >> N;

    vector<vector<string>> lanquages(N); // initializing the nested vectors for languages

    for (int i = 0; i < N; i++) {
        int L_i;
        cin >> L_i;
        lanquages[i].resize(L_i); // resizing the nested vector for language
        for (int j = 0; j < L_i; j++) {
            cin >> lanquages[i][j]; // input languages
        }
    }
    int M;
    cin >> M;
    vector<string> input_str (M); // vector for sentence for analyzing
    for (int i = 0; i < M; i++){
        cin >> input_str[i]; // input string
    }

    vector<int> count(N); // vector for counting coincidences
    count = counting(lanquages,input_str); // function for counting coincidences
    int max = findMax(count);

    for (int i = 0; i < N; i++){
        if (count[i] == max){
            cout << (i+1) << " ";
        }
    }
}
