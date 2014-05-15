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

int a=0,b=0,c2=0,n;
LL dp[51][51][51][4][4];
LL f(int a1,int b1,int c1,int last,int first)
{
    //cout<<"here\n";
    LL& res=dp[a1][b1][c1][last][first];
    if(res==-1)
    {
        int i=a1+b1+c1;
        res=0;
        if(i==0)
        {
            if(a1<a)res=f(a1+1,b1,c1,1,1);
            if(b1<b)res+=f(a1,b1+1,c1,2,2);
            if(c1<c2)res+=f(a1,b1,c1+1,3,3);
        }
        else
        if(i==n)
        {
            res=(last!=first);
        }
        else
        {
            if(last!=1 && a1<a)res=f(a1+1,b1,c1,1,first);
            if(last!=2 && b1<b)res+=f(a1,b1+1,c1,2,first);
            if(last!=3 && c1<c2)res+=f(a1,b1,c1+1,3,first);
        }
        res%=MOD;
    }
   // if(n==4)
    //cout<<i<<" "<<last<<" "<<first<<" "<<res<<endl;
    return res;
}

class ColorfulCupcakesDivTwo {
    public:
    int countArrangements(string c) {

   // c="ABABABABABABABABABABABABABABABABABABABABABABABABAB";
    n=c.length();
    fill(dp,-1);
    a=b=c2=0;
    for(int i=0;i<n;++i)
    {
        a+=(c[i]=='A');
        b+=(c[i]=='B');
        c2+=(c[i]=='C');
    }

    return (int)f(0,0,0,0,0);
    }
};

// CUT begin
ifstream data("ColorfulCupcakesDivTwo.sample");

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

bool do_test(string cupcakes, int __expected) {
    time_t startClock = clock();
    ColorfulCupcakesDivTwo *instance = new ColorfulCupcakesDivTwo();
    int __result = instance->countArrangements(cupcakes);
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
        string cupcakes;
        from_stream(cupcakes);
        next_line();
        int __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(cupcakes, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1399611865;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : " << 950 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
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
        cout << "ColorfulCupcakesDivTwo (950 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
