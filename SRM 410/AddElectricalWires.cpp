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

VS w;
int n;
int vis[100];
int dp[100];
int f=0;
int cnt=0;
void dfs(int i)
{
    vis[i]=1;
    if(dp[i]==1)f=1;
    cnt++;
    for(int j=0;j<n;++j)
    {
        if(w[i][j]=='1' && !vis[j])dfs(j);
    }
}

class AddElectricalWires {
    public:
    int maxNewWires(vector<string> W, vector<int> g) {

    fill(dp,0);
    for(int i=0;i<g.size();++i)
    {
        dp[g[i]]=1;
    }

    w=W;
    n=w.size();
    fill(vis,0);

    VI a,b;
    int total=0;
    int ans=0;
    for(int i=0;i<n;++i)
    {
        if(!vis[i])
        {
            f=0;
            cnt=0;
            dfs(i);
            if(f)
            {
                a.pb(cnt);
            }
            else total+=cnt;
        }
    }

    sort(all(a));

    for(int i=0;i<a.size()-1;++i)
    {
        ans=ans+(a[i]*(a[i]-1))/2;
    }

    total+=a[a.size()-1];

    ans=ans+total*(total-1)/2;

    int num=0;
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
        {
            if(W[i][j]=='1')num++;
        }
    }

    num/=2;

    return ans-num;
    }
};

// CUT begin
ifstream data("AddElectricalWires.sample");

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

bool do_test(vector<string> wires, vector<int> gridConnections, int __expected) {
    time_t startClock = clock();
    AddElectricalWires *instance = new AddElectricalWires();
    int __result = instance->maxNewWires(wires, gridConnections);
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
        vector<string> wires;
        from_stream(wires);
        vector<int> gridConnections;
        from_stream(gridConnections);
        next_line();
        int __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(wires, gridConnections, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1395597651;
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
        cout << "AddElectricalWires (250 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
