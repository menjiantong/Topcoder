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

int f1(string s,string t)
{
    int n=s.length();
    int dp[n+1][n+1];
    fill(dp,0);

    for(int i=0;i<=n;++i)
    {
        for(int j=0;j<=n;++j)
        {
            if(i==0)dp[i][j]=j;
            else if(j==0)dp[i][j]=i;
            else
            {
                dp[i][j]=min(1+dp[i-1][j],min(1+dp[i][j-1],dp[i-1][j-1]+(s[i-1]!=t[j-1])));
            }
        }
    }

   // cout<<s<<" "<<t<<" "<<dp[n][n]<<endl;
    return dp[n][n];
}

int f2(string s,string t,int j,int d)
{
    int n=s.length();
    for(int i=j+1;i<n;++i)
    {
        s[i]=t[i];
    }
    //cout<<s<<endl;
    int m=f1(s,t);

    char ch='a';

    while(count(all(t),ch)>0)ch++;

    for(int i=j+1;i<n;++i)
    {
        s[i]=ch;
    }

    int M=f1(s,t);
    //cout<<m<<" "<<M<<endl;
    return (d>=m && d<=M);
}

class FarStrings {
    public:
    vector<string> find(string t) {

    int n=t.size();

    vector<string>ans;
    for(int i=1;i<=n;++i)
    {
        string s(n,'?');

        for(int j=0;j<n;++j)
        {
            for(int k=0;k<26;++k)
            {
                s[j]=(char)(k+97);
                if(f2(s,t,j,i)==1)
                {
                    break;
                }
            }
        }
        ans.pb(s);
    }

    return ans;
    }
};

// CUT begin
ifstream data("FarStrings.sample");

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

template <typename T> string to_string(vector<T> ts) {
    stringstream s;
    s << "[ ";
    for (int i = 0; i < ts.size(); ++i) {
        if (i > 0) s << ", ";
        s << to_string(ts[i]);
    }
    s << " ]";
    return s.str();
}

bool do_test(string t, vector<string> __expected) {
    time_t startClock = clock();
    FarStrings *instance = new FarStrings();
    vector<string> __result = instance->find(t);
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
        string t;
        from_stream(t);
        next_line();
        vector<string> __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(t, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1398664785;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : " << 800 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
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
        cout << "FarStrings (800 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
