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
VS m;
VI t;

int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};

int dp[50][50];

int f(int i,int j,int mask)
{
    int& res=dp[i][j];
    if(res==-1)
    {
        if(m[i][j]=='!')
        {
            res=1;
        }
        else
        {
            res=0;
            for(int k=0;k<4;++k)
            {
                int nx=i+dx[k];
                int ny=j+dy[k];

                if(nx>=0 && ny>=0 && nx<m.size() && ny<m[0].length())
                {
                    if(m[nx][ny]!='#')
                    {
                        if(m[nx][ny]=='.' || m[nx][ny]=='!')
                        {
                            res=max(res,f(nx,ny,mask));
                        }
                        else
                        {
                            int tmp=m[nx][ny]-'A';
                            if(mask&(1<<tmp))
                            {
                                res=max(res,f(nx,ny,mask));
                            }
                        }
                    }
                }
            }
        }
    }
    return res;
}

class ColorfulMazeTwo {
    public:
    double getProbability(vector<string> M, vector<int> T) {
    m=M;
    t=T;

    for(int i=0;i<m.size();++i)
    {
        for(int j=0;j<m[0].length();++j)
        {
            if(m[i][j]=='$')
            {
                double ans=0;
                fill(dp,-1);
                for(int k=0;k<(1<<7);++k)
                {
                    fill(dp,-1);
                    double tmp=1.0;
                    int ok=f(i,j,k);

                    if(ok)
                    {
                        for(int h=0;h<7;++h)
                        {
                            if((k>>h)&1)
                            {
                                tmp=tmp*(100-t[h])/100.0;
                            }
                        }

                        ans=max(ans,tmp);
                    }
                }
                return ans;
            }
        }
    }
    }
};

// CUT begin
ifstream data("ColorfulMazeTwo.sample");

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

bool double_equal(const double &a, const double &b) { return b==b && a==a && fabs(b - a) <= 1e-9 * max(1.0, fabs(a) ); }

bool do_test(vector<string> maze, vector<int> trap, double __expected) {
    time_t startClock = clock();
    ColorfulMazeTwo *instance = new ColorfulMazeTwo();
    double __result = instance->getProbability(maze, trap);
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
        vector<string> maze;
        from_stream(maze);
        vector<int> trap;
        from_stream(trap);
        next_line();
        double __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(maze, trap, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1395842991;
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
        cout << "ColorfulMazeTwo (1000 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
