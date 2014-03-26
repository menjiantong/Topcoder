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
#define MOD 999983
string s;

int dp[101][910][450][2][2];
int k;
LL f(int j,int sum,int even,int f2,int f3)
{
    int& res=dp[j][sum][even][f2][f3];
    if(res==-1)
    {
        if(j==2*k)
        {
            if(sum==0 || even==0)
            {
                res=1;
            }
            else res=0;
        }
        else
        {
            res=0;
            for(int i=0;i<s.length();++i)
            {
                int nsum=sum;

                if(f3)nsum=-1*nsum;

                if(j<k)
                {
                    nsum=nsum+s[i]-'0';
                }
                else
                    nsum=nsum-(s[i]-'0');


                int f4=0;

                if(nsum<0)
                {
                    nsum=-1*nsum;
                    f4=1;
                }

                int tmp=even;
                if(j%2==0)
                {
                    if(f2)tmp=-1*tmp;
                    tmp=tmp+s[i]-'0';
                }
                else
                {
                    if(f2)tmp=-1*tmp;
                    tmp=tmp-s[i]+'0';
                }

                int f1=0;
                if(tmp<0)
                {
                    tmp=-1*tmp;
                    f1=1;
                }
                res+=f(j+1,nsum,tmp,f1,f4);
                res%=MOD;
            }
        }
    }
    return res;
}

class CharmingTicketsEasy {
    public:
    int count(int K, string g) {

    s=g;

    fill(dp,-1);
    k=K;
    return f(0,0,0,0,0);

    }
};

// CUT begin
ifstream data("CharmingTicketsEasy.sample");

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

bool do_test(int K, string good, int __expected) {
    time_t startClock = clock();
    CharmingTicketsEasy *instance = new CharmingTicketsEasy();
    int __result = instance->count(K, good);
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
        int K;
        from_stream(K);
        string good;
        from_stream(good);
        next_line();
        int __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(K, good, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1395520293;
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
        cout << "CharmingTicketsEasy (1000 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
