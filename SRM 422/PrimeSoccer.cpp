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

int a,b;

double dp[20][20][20];

int f1(int n)
{
    if(n<=1)return 0;
    for(int i=2;i*i<=n;++i)
    {
        if(n%i==0)return 0;
    }
    return 1;
}

double f(int i,int c1,int c2)
{
    cout<<i<<" "<<c1<<" "<<c2<<endl;
   // double& res=dp[i][c1][c2];
    double res;
        if(i==18)
        {
            cout<<"here\n";
            if(f1(c1) || f1(c2))res=1;
            else res=0;
        }
        else
        {
            res=(100.0-a)/100.0*(100.0-b)/100.0*f(i+1,c1,c2);
            res+=(100.0-a)/100.0*(b/100.0)*f(i+1,c1,c2+1);
            res+=a/100.0*(100.0-b)/100.0*f(i+1,c1+1,c2);
            res+=a/100.0*b/100.0*f(i+1,c1+1,c2+1);
        }
    return res;
}

class PrimeSoccer {
    public:
    double getProbability(int A, int B) {

    a=A;
    b=B;

    for(int i=0;i<20;++i)
    {
        for(int j=0;j<20;++j)
        {
            for(int k=0;k<20;++k)dp[i][j][k]=-1;
        }
    }

    return f(0,0,0);
    }
};

// CUT begin
ifstream data("PrimeSoccer.sample");

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

bool double_equal(const double &a, const double &b) { return b==b && a==a && fabs(b - a) <= 1e-9 * max(1.0, fabs(a) ); }

bool do_test(int skillOfTeamA, int skillOfTeamB, double __expected) {
    time_t startClock = clock();
    PrimeSoccer *instance = new PrimeSoccer();
    double __result = instance->getProbability(skillOfTeamA, skillOfTeamB);
    double elapsed = (double)(clock() - startClock) / CLOCKS_PER_SEC;
    delete instance;

    if (double_equal(__expected, __result)) {
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
        int skillOfTeamA;
        from_stream(skillOfTeamA);
        int skillOfTeamB;
        from_stream(skillOfTeamB);
        next_line();
        double __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(skillOfTeamA, skillOfTeamB, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1398190787;
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
        cout << "PrimeSoccer (500 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
