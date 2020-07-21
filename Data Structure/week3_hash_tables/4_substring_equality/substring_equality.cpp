#include <iostream>
#include <vector>
#include <string>
#include <math.h>

using namespace std;

static const unsigned long long PRIME_1 = 1000000007;
static const unsigned long long PRIME_2 = 1000000009;
static const unsigned long long MULT_1 = 15;
static const unsigned long long MULT_2 = 31;

class Solver {
	string s;
	unsigned int text_size;

	vector<unsigned long long> hash_1;
	vector<unsigned long long> hash_2;

	vector<unsigned long long> power_1;
	vector<unsigned long long> power_2;

	void hashes(vector<unsigned long long> &hash, vector<unsigned long long> &power, long long PRIME){
	    hash.resize(text_size + 1);
	    hash[0] = 0;

        for(int i = 0; i < text_size; i++)
            hash[i + 1] = (hash[i] + s[i] * power[i]) % PRIME;
    }

    void modpow(vector<unsigned long long> &power, unsigned long long PRIME, int MULT) {
      power.resize(text_size);
      power[0] = 1;
      for(int i = 1; i < text_size; i++)
        power[i] = (power[i-1] * MULT) % PRIME;
    }

    unsigned long long difference(vector<unsigned long long> &hashes, vector<unsigned long long> &power, const unsigned long long prime, int start, int length ){
        long long diff = (hashes[start + length] + prime - hashes[start]) % prime;
        return (diff * power[text_size - start - 1]) % prime;
    }

public:
	Solver(string s) : s(s), text_size(s.size()) {
		// initialization, precalculation
	    modpow(power_1, PRIME_1, MULT_1);
	    modpow(power_2, PRIME_2, MULT_2);

        hashes(hash_1, power_1, PRIME_1);
        hashes(hash_2, power_2, PRIME_2);
	}

	bool ask(int a, int b, int l) {

	    if(a==b) return true;

	    long long a_hash_PRIME1 = difference(hash_1, power_1, PRIME_1, a, l);
	    long long b_hash_PRIME1 = difference(hash_1, power_1, PRIME_1, b, l);

	    if(a_hash_PRIME1 != b_hash_PRIME1) return false;

	    long long a_hash_PRIME2 = difference(hash_2, power_2, PRIME_2, a, l);
	    long long b_hash_PRIME2 = difference(hash_2, power_2, PRIME_2, b, l);

	    if(a_hash_PRIME2 != b_hash_PRIME2) return false;

		return true;
	}
};

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);

	string s;
	int q;
	cin >> s >> q;
	Solver solver(s);
	for (int i = 0; i < q; i++) {
		int a, b, l;
		cin >> a >> b >> l;
		cout << (solver.ask(a, b, l) ? "Yes\n" : "No\n");
	}
}
