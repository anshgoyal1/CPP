#include <bits/stdc++.h>
using namespace std;
#define int long long int
const int mod = 1e9 + 7;
#define yes cout << "Yes" << endl;
#define no cout << "No" << endl;
#define PI 3.141592653589793
#define all(a) (a).begin(), (a).end()
#define display(x)               \
    for(auto a:x) cout << a << " "; \
    cout << endl;
#define endl '\n'

#define TIME cerr << "\nTime elapsed: " << setprecision(5) << 1000.0 * clock() / CLOCKS_PER_SEC << "ms\n";
#define DECIMAL(n) \
    cout << fixed; \
    cout << setprecision(n);
#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
int dx[8] = {1,-1,0,0,1,1,-1,-1};
int dy[8] = {0,0,1,-1,-1,1,-1,1};


int manhattan_distance(int x,int y,int a,int b){
    return abs(a -x) + abs(b - y);
}
bool vowelOrConsonant(char x)
{
    if (x == 'a' || x == 'e' || x == 'i' ||
                   x == 'o' || x == 'u')
        return true;
    else
        return false;
}

void code_likh_le()
{
    int n,x;
    cin >> n >> x;
    vector<int> a(n);
    for(int i = 0;i< n;i++){
        cin >> a[i];
    }

    sort(all(a));
    int ans = 0;
    int l = 0;
    int r = n - 1;

    while(l < r){
        if(a[l] + a[r] <= x){
            l++;
            r--;
        }else{
            r--;
        }
        ans++;
    }
    if(l == r){
        ans++;
    }
    
    cout << ans << endl;
}   

int32_t main()
{
    FAST;

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin); //file input.txt is opened in reading mode i.e "r"
    freopen("output.txt","w",stdout);  //file output.txt is opened in writing mode i.e "w"
    #endif

    int t = 1;
    // cin >> t;

    for (int i = 1; i <= t; i++)
    {
        // cout << "Case #" << i << ": ";
        code_likh_le();
    }

    // TIME;
    return 0;
}