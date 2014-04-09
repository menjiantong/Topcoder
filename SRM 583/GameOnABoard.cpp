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

static const long INF1 =  0x7F7F7F7F7F7F7F7F;

#define fr(i,s,n)    for(int i=s;i<(n);++i)
#define MOD 1000000007

int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};

class GameOnABoard {
    public:
    int optimalChoice(vector<string> a) {

    int r=a.size();
    int c=a[0].length();

    int ans=INF;

    for(int i=0;i<r;++i)
    {
        for(int j=0;j<c;++j)
        {
            int dis[r][c];
            fill(dis,INF1);

            deque<pp>d;

            d.push_back(pp(i,j));
            dis[i][j]=0;
            int worst=0;

            if(a[i][j]=='1')
            {
                dis[i][j]++;
                worst++;
            }
            while(!d.empty())
            {
                pp top=d.front();
                d.pop_front();

                int x=top.f;
                int y=top.sc;

                for(int k=0;k<4;++k)
                {
                    int nx=x+dx[k];
                    int ny=y+dy[k];

                    if(nx>=0 && ny>=0 && nx<r && ny<c)
                    {
                        if(dis[x][y]+a[nx][ny]-'0'<dis[nx][ny])
                        {
                            dis[nx][ny]=dis[x][y]+a[nx][ny]-'0';
                             worst=max(worst,dis[nx][ny]);
                            if(a[nx][ny]=='0')
                            {
                                d.push_front(pp(nx,ny));
                            }
                            else
                            {
                                d.push_back(pp(nx,ny));
                            }
                        }
                    }
                }
            }

            ans=min(ans,worst);
        }
    }

        return ans;
    }
};

// CUT begin
ifstream data("GameOnABoard.sample");

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

bool do_test(vector<string> cost, int __expected) {
    time_t startClock = clock();
    GameOnABoard *instance = new GameOnABoard();
    int __result = instance->optimalChoice(cost);
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
        vector<string> cost;
        from_stream(cost);
        next_line();
        int __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(cost, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1396874813;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : " << 900 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
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
        cout << "GameOnABoard (900 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
