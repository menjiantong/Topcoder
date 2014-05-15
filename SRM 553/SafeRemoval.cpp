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

int B[4][55];
int k,n;
VI a0,a1,a2,a3;
int dp[51][51][51][51];
int f(int a,int b,int c,int d)
{
    int& res=dp[a][b][c][d];
    if(res==-1)
    {
        int i=a+b+c+d;
        if(i==(n-k))
        {
            res=0;
        }
        else
        {
            int sum=0;
            sum+=B[0][a]+B[1][b]+B[2][c]+B[3][d];
            if(sum%4==0)
            {
                res=-INF;
            }
            else
            {
                if(a>0)res=f(a-1,b,c,d);
                if(b>0)res=max(res,f(a,b-1,c,d));
                if(c>0)res=max(res,f(a,b,c-1,d));
                if(d>0)res=max(res,f(a,b,c,d-1));
            }
        }
    }
    return res;
}

class SafeRemoval {
    public:
    int removeThem(vector<int> a, int K) {
    k=K;
    n=a.size();
    a0.clear();
    a1.clear();
    a2.clear();
    a3.clear();

    for(int i=0;i<a.size();++i)
    {
        if(a[i]%4==0)a0.pb(a[i]);
        if(a[i]%4==1)a1.pb(a[i]);
        if(a[i]%4==2)a2.pb(a[i]);
        if(a[i]%4==3)a3.pb(a[i]);
    }

    sort(a0.rbegin(),a0.rend());
    sort(a1.rbegin(),a1.rend());
    sort(a2.rbegin(),a2.rend());
    sort(a3.rbegin(),a3.rend());

    B[0][0]=a0[0];
    for(int i=1;i<a0.size();++i)
    {
        B[0][i]=B[0][i-1]+a0[i];
    }

    B[1][0]=a1[0];
    for(int i=1;i<a1.size();++i)
    {
        B[1][i]=B[1][i-1]+a1[i];
    }

    B[2][0]=a2[0];
    for(int i=1;i<a2.size();++i)
    {
        B[2][i]=B[2][i-1]+a2[i];
    }

    B[3][0]=a3[0];
    for(int i=1;i<a3.size();++i)
    {
        B[3][i]=B[3][i-1]+a3[i];
    }


    fill(dp,-1);
    return f(0,0,0,0);
    }
};

// CUT begin
ifstream data("SafeRemoval.sample");

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

bool do_test(vector<int> seq, int k, int __expected) {
    time_t startClock = clock();
    SafeRemoval *instance = new SafeRemoval();
    int __result = instance->removeThem(seq, k);
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
        vector<int> seq;
        from_stream(seq);
        int k;
        from_stream(k);
        next_line();
        int __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(seq, k, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1399613818;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : " << 1000 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
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
        cout << "SafeRemoval (1000 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
