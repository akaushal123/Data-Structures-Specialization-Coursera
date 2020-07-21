#include <iostream>
#include <string>
#include <vector>

using std::string;
typedef unsigned long long ull;
using namespace std;

static const size_t PRIME = 1000000007;
static const size_t MULTIPLIER = 239;

unsigned long long poly_hash(const string& s){
    unsigned long long hash = 0;
    for(int i = static_cast<int> (s.size()) - 1; i >= 0; --i)
        hash = (hash * MULTIPLIER + s[i]) % PRIME;
    return hash;
}

vector<unsigned long long> precompute_hash(const string &text, int pattern_length){
    size_t text_size = text.size();
    vector<unsigned long long> hashes(text_size - pattern_length + 1);
    //last hash size
    string last = text.substr(text_size - pattern_length, pattern_length);

    hashes[text_size - pattern_length] = poly_hash(last);

    unsigned long long y = 1;
    for(size_t i = 1; i <= pattern_length; i++)
        y = (y * MULTIPLIER) %PRIME;

    for(int i = static_cast<int>(text_size - pattern_length - 1); i >= 0 ; i--){
        hashes[i] = ((MULTIPLIER * hashes[i+1] + text[i] - (y * text[i + pattern_length] % PRIME )) + PRIME )%PRIME;
        //hashes[i] = (hashes[i]%PRIME + PRIME)%PRIME;
    }

    return hashes;
}

struct Data {
    string pattern, text;
};

Data read_input() {
    Data data;
    std::cin >> data.pattern >> data.text;
    return data;
}

void print_occurrences(const std::vector<int>& output) {
    for (size_t i = 0; i < output.size(); ++i)
        std::cout << output[i] << " ";
    std::cout << "\n";
}


bool are_equal(string s, string t){
    if(s.size() != t.size()) return false;
    for (int i = 0; i < s.size(); i++)
        if(s[i]!=t[i]) return false;
    return true;
}

//Implemented Rabin-Karp
std::vector<int> get_occurrences(const Data& input) {
    const string &s = input.pattern, t = input.text;
    std::vector<int> ans;

    unsigned long long p_hash = poly_hash(s);
    auto hashes = precompute_hash(t, s.size());
    for(size_t i = 0; i + s.size() <= t.size(); i++){
        if(p_hash != hashes[i]) continue;
        if (t.substr(i,s.size()) == s) ans.push_back(i);
    }

    /*
    for (size_t i = 0; i + s.size() <= t.size(); ++i)
        if (t.substr(i, s.size()) == s)
            ans.push_back(i);
    */
    return ans;
}


int main() {
    std::ios_base::sync_with_stdio(false);
    print_occurrences(get_occurrences(read_input()));
    return 0;
}
