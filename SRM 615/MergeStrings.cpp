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

string s,a,b,s1;

string dp1[55][55];
int dp[55][55];

string f(int j,int k)
{
    int i=j+k;
    int& res=dp[j][k];
    if(res==-1)
    {
        res=0;
        if(i==s.length())
        {
            if(j==a.length() && k==b.length())
            {
                dp1[j][k]="";
            }
        }
        else
        {
            dp1[j][k]="a";

            if(s[i]=='?')
            {
                if(j<a.length())
                {
                    if(f(j+1,k)!="a")dp1[j][k]=min(dp1[j][k],a[j]+f(j+1,k));
                }

                if(k<b.length())
                {
                    if(f(j,k+1)!="a")
                     dp1[j][k]=min(dp1[j][k],b[k]+f(j,k+1));
                }
            }
            else
            {
                if(j<a.length())
                {
                    if(f(j+1,k)!="a")
                    if(s[i]==a[j])dp1[j][k]=min(dp1[j][k],a[j]+f(j+1,k));
                }
                if(k<b.length())
                {
                    if(f(j,k+1)!="a")
                    if(s[i]==b[k])dp1[j][k]=min(dp1[j][k],b[k]+f(j,k+1));
                }
            }
        }
    }

    return dp1[j][k];
}

class MergeStrings {
    public:
    string getmin(string S, string A, string B) {

    s=S;
    a=A;
    b=B;

    fill(dp,-1);

    string ans=f(0,0);

    if(ans!="a")
    return ans;
    else return "";
    }
};

// CUT begin
ifstream data("MergeStrings.sample");

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

bool do_test(string S, string A, string B, string __expected) {
    time_t startClock = clock();
    MergeStrings *instance = new MergeStrings();
    string __result = instance->getmin(S, A, B);
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
        string S;
        from_stream(S);
        string A;
        from_stream(A);
        string B;
        from_stream(B);
        next_line();
        string __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(S, A, B, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1396680614;
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
        cout << "MergeStrings (1000 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
