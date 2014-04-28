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

int a[100][100];


class Family {
    public:
    string isFamily(vector<int> p1, vector<int> p2) {

    int f=1;
    fill(a,0);
    for(int i=0;i<p1.size();++i)
    {
        if(p1[i]!=-1)
        {
            a[p1[i]][p2[i]]=1;
            a[p2[i]][p1[i]]=1;
        }
    }

    queue<int>Q;

    int col[100];
    int vis[100];
    fill(vis,0);
    fill(col,-1);
    for(int i=0;i<100;++i)
    {
        if(!vis[i])
        {
            Q.push(i);
            vis[i]=1;
            col[i]=0;

            while(!Q.empty())
            {
                int tmp=Q.front();
                Q.pop();

                for(int j=0;j<100;++j)
                {
                    if(a[j][tmp]==1)
                    {
                        if(!vis[j])
                        {
                            Q.push(j);
                            vis[j]=1;
                            col[j]=1-col[tmp];
                        }
                        else
                        {
                            if(col[j]==col[tmp])f=0;
                        }
                    }
                }
            }
        }
    }


    if(f)return "Possible";
    return "Impossible";
    }
};

// CUT begin
ifstream data("Family.sample");

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

bool do_test(vector<int> parent1, vector<int> parent2, string __expected) {
    time_t startClock = clock();
    Family *instance = new Family();
    string __result = instance->isFamily(parent1, parent2);
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
        vector<int> parent1;
        from_stream(parent1);
        vector<int> parent2;
        from_stream(parent2);
        next_line();
        string __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(parent1, parent2, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1398396959;
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
        cout << "Family (250 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
