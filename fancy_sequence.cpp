class Fancy {
public:
    using ll = long long int;
    ll M = 1e9 + 7;
    ll mult;
    ll add;
    vector<ll> sequence;
    ll power(ll x, ll n) {
        if(n == 0) return 1;

        ll ans = power(x, n / 2) % M;
        ll result = (ans * ans) % M;

        if(n & 1) return (x * result) % M;
        else return result % M;
    }
    Fancy() {
        sequence.clear();
        mult = 1;
        add = 0;
    }
    
    void append(int val) {
        ll x = (((val  - add + M) % M) * (power(mult, M-2) % M))%M; 
        // Here I have added M, to prevent it from becoming negative. 
        // here for moding 1 / mult I am using here FLT, theorm, which says for 
        //(x / M) % M -> power(x, M-2) % M . . . VVVIMP
        sequence.push_back(x); 
    }
    
    void addAll(int inc) {
        add = (add + inc) % M;
    }
    
    void multAll(int m) {
        add = (add * m) % M;
        mult = (mult * m) % M;
    }
    
    int getIndex(int idx) {
        if(idx >= sequence.size()) return -1;
        return (sequence[idx] * mult + add) % M;
    }
};

/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy* obj = new Fancy();
 * obj->append(val);
 * obj->addAll(inc);
 * obj->multAll(m);
 * int param_4 = obj->getIndex(idx);
 */