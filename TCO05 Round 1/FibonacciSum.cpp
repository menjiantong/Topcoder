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

#define fr(i,s,n)    for(int i=s;i<(n);++i)
#define MOD 1000000007

VI A;

map<pp,int>M;
int f(int i,int n)
{
    if(M.count(pp(i,n))==1)return M[pp(i,n)];
    int res;
    //if(res==-1)
    {
        if(i==A.size())
        {
            if(n==0)res=0;
            else res=INF;
        }
        else
        {
            res=f(i+1,n);

            if(n>=A[i])
            res=min(res,1+f(i,n-A[i]));
        }
    }
    M[pp(i,n)]=res;
    return res;
}

class FibonacciSum {
    public:
    int howMany(int n) {



    A.clear();

    A.pb(1);
    A.pb(1);

    int a=1,b=1,c=2;

    while(c<=1000000)
    {
        c=a+b;
        A.pb(c);
        a=b;
        b=c;
    }

    int dp[n+1];
    dp[0]=0;
    dp[1]=1;

    for(int i=2;i<=n;++i)
    {
        dp[i]=1e6;
        for(int j=0;j<A.size();++j)
        {
            if(i>=A[j])
            dp[i]=min(dp[i],dp[i-A[j]]+1);
        }
    }s
    return dp[n];
    }
};

// CUT begin
ifstream data("FibonacciSum.sample");

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

template <typename T>
string to_string(T t) {
    stringstream s;
    s << t;
    return s.str();
}

string to_string(string t) {
    return "\"" + t + "\"";
}

bool do_test(int n, int __expected) {
    time_t startClock = clock();
    FibonacciSum *instance = new FibonacciSum();
    int __result = instance->howMany(n);
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
        int n;
        from_stream(n);
        next_line();
        int __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(n, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1395950414;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : " << 500 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
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
        cout << "FibonacciSum (500 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
