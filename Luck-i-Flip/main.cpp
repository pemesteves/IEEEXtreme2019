#include <iostream>
#include <set>
#include <vector>

using namespace std;


int bet_val(const string & s1, const string & s2) {
    int total = 0;
    for (unsigned i = 0; i < s1.size(); i++) {
        if (s1[i] == s2[i])
            total++;
    }
    return total;
}

void check_bet(string word, vector<int> & count, vector<string> & bets) {
    int max_val = -1;
    vector<int> max_is;
    
    for (unsigned j = 0; j < bets.size(); j++) {
        
        int new_val = bet_val(word, bets[j]);
        if (new_val == max_val) {
            max_is.push_back(j);
        }
        else if (new_val > max_val) {
            max_val = new_val;
            max_is.clear();
            max_is.push_back(j);
        }
    }
    if (max_is.size() > 1) return;
    
    for (int & n : max_is) count[n]++;
}


void generate_words(const vector<char> &alphabet, int &word_length, vector<int> & count, vector<string> & bets)
{
    vector<int> index(word_length, 0);

    for (;;) {
        string word(index.size(), ' ');
        for (unsigned i = 0; i < index.size(); ++i) {
            word[i] = alphabet[index[i]];
        }
        
        check_bet(word, count, bets);
        
        for (int i = (int)index.size() - 1; ; --i) {
            if (i < 0) return;

            ++index[i];

            if (index[i] == (int) alphabet.size()) {
                index[i] = 0;
            } else {
                break;
            }
        }
    }

}

int main() {
    
    int b; cin >> b;
    
    vector<string> bets;
    string bet;
    for (int i = 0; i < b; i++) {
        cin >> bet;
        bets.push_back(bet);    
    }
    int n = bet.length();
    
    
    vector<char> alphabet = {'0', '1'};
    vector<int> count(n, 0);
    generate_words(alphabet, n, count, bets);
    
    int min_bet = count[0];
    for (int i = 1; i < n; i++) {
        min_bet = min(min_bet, count[i]);
    }
    
    cout << min_bet << endl;
    
    return 0;
}