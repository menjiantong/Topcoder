#include <bits/stdc++.h>

using namespace std;

#define INF                         (int)1e9
#define EPS                         1e-9
#define all(a)                      a.begin(), a.end()
#define in(a,b)                     ( (b).find(a) != (b).end())
#define pb                          push_back
#define fill(a,v)                   memset(a, v, sizeof a)
#define sz(a)                       ((int)(a.size()))
#define mp                          make_pair
#define f                           first
#define sc                          second
#define bitcount                    __builtin_popcount

#define SSTR( x ) dynamic_cast< std::ostringstream & >(( std::ostringstream() << std::dec << x ) ).str()
#define SST(x) atoi(x)
#define checkbit(n,b)                ( (n >> b) & 1)

typedef long long LL;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int,int> pp;
typedef vector<string> VS;

#define DREP(a)                      sort(all(a)); a.erase(unique(all(a)),a.end())
#define fr(i,s,n)    for(int i=s;i<(n);++i)
#define MOD 1000000007
class MinimumSquare {
    public:
    long long minArea(vector<int> x, vector<int> y, int K) {
    int n=x.size();


    vector<LL>X,Y;

    for(int i=0;i<n;++i)
    {
        X.pb(x[i]+1);
        X.pb(x[i]-1);
        Y.pb(y[i]+1);
        Y.pb(y[i]-1);
    }

    long long ans=6e18;
    DREP(X);
    DREP(Y);


    for(int i=0;i<X.size();++i)
    {
        for(int j=i+1;j<X.size();++j)
        {
            vector<LL>tp;
            for(int k=0;k<n;++k)
            {
                if(x[k]>X[i] && x[k]<X[j])
                {
                    tp.pb(y[k]);
                }
            }

            sort(all(tp));

            LL m=1e15;
            for(int i1=K-1;i1<tp.size();++i1)
            {
                m=min(m,tp[i1]-tp[i1-K+1]);
            }

            if(m+2<=(X[j]-X[i]))
            {
                ans=min(ans,(LL)(X[j]-X[i])*(X[j]-X[i]));
            }
        }
    }

     for(int i=0;i<Y.size();++i)
    {
        for(int j=i+1;j<Y.size();++j)
        {
            vector<LL>tp;
            for(int k=0;k<n;++k)
            {
                if(y[k]>Y[i] && y[k]<Y[j])
                {
                    tp.pb(x[k]);
                }
            }

            sort(all(tp));

            LL m=1e15;
            for(int i1=K-1;i1<tp.size();++i1)
            {
                m=min(m,tp[i1]-tp[i1-K+1]);
            }

            if(m+2<=(Y[j]-Y[i]))
            {
                ans=min(ans,(LL)(Y[j]-Y[i])*(Y[j]-Y[i]));
            }
        }
    }

    return ans;
    }
};

// CUT begin
ifstream data("MinimumSquare.sample");

string next_line() {
    string s;
    getline(data, s);
    return s;
}

template <typename T> void from_stream(T &t) {
    stringstream ss(next_line());
    ss >> t;
}

void from_stream(string &s) {
    s = next_line();
}

template <typename T> void from_stream(vector<T> &ts) {
    int len;
    from_stream(len);
    ts.clear();
    for (int i = 0; i < len; ++i) {
        T t;
        from_stream(t);
        ts.push_back(t);
    }
}

template <typename T>
string to_string(T t) {
    stringstream s;
    s << t;
    return s.str();
}

string to_string(string t) {
    return "\"" + t + "\"";
}

bool do_test(vector<int> x, vector<int> y, int K, long long __expected) {
    time_t startClock = clock();
    MinimumSquare *instance = new MinimumSquare();
    long long __result = instance->minArea(x, y, K);
    double elapsed = (double)(clock() - startClock) / CLOCKS_PER_SEC;
    delete instance;

    if (__result == __expected) {
        cout << "PASSED!" << " (" << elapsed << " seconds)" << endl;
        return true;
    }
    else {
        cout << "FAILED!" << " (" << elapsed << " seconds)" << endl;
        cout << "           Expected: " << to_string(__expected) << endl;
        cout << "           Received: " << to_string(__result) << endl;
        return false;
    }
}

int run_test(bool mainProcess, const set<int> &case_set, const string command) {
    int cases = 0, passed = 0;
    while (true) {
        if (next_line().find("--") != 0)
            break;
        vector<int> x;
        from_stream(x);
        vector<int> y;
        from_stream(y);
        int K;
        from_stream(K);
        next_line();
        long long __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(x, y, K, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1396108803;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : " << 250 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    cout.setf(ios::fixed, ios::floatfield);
    cout.precision(2);
    set<int> cases;
    bool mainProcess = true;
    for (int i = 1; i < argc; ++i) {
        if ( string(argv[i]) == "-") {
            mainProcess = false;
        } else {
            cases.insert(atoi(argv[i]));
        }
    }
    if (mainProcess) {
        cout << "MinimumSquare (250 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
