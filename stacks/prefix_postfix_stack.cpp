#include<bits/stdc++.h>
using namespace std;

#define MAX 1000



int pre(char s){
    if(s == '^')
    return 3;
    else if(s == '*' || s == '/')
    return 2;
    else if(s == '+' || s == '-')
    return 1;
    else
    return 0;
}
string pre_to_in(string s){
    stack<string> st;
    int len = s.length();
    for(int i = len-1;i>=0;i--){
        if(isoperator(s[i])){
            string x2 = st.top();
            st.pop();
            string x1 = st.top();
            st.pop();
            string temp = '(' + x2 + s[i] + x1 +')';
            st.push(temp);
        }
        else{
            st.push(string(1,s[i]));
        }
    }
    return st.top();
}

string pre_to_post(string s){
    stack<string> st;
    int len = s.length();
    for(int i = len - 1;i>=0;i--){
        if(isoperator(s[i])){
            string s1 = st.top(); st.pop();
            string s2 = st.top(); st.pop();
            string temp = s1 + s2 + s[i];
            st.push(temp);
        }
        else{
            st.push(string(1,s[i]));
        }
    }
    // cout << s[2] << endl;
    return st.top();
}

string post_to_pre(string s){
    stack<string> st;
    int len = s.length();
    for(int i = 0;i<len;i++){
        if(isoperator(s[i])){
            string x2 = st.top(); st.pop();
            string x1 = st.top(); st.pop();
            string temp = s[i] + x1 + x2;
            st.push(temp);
        }
        else{
            st.push(string(1,s[i]));
        }
    }
    return st.top();
}

string post_to_infix(string s){
    stack<string> st;
    int len = s.length();

    for(int i = 0;i<len;i++){
        if(isoperator(s[i])){
            string x2 = st.top(); st.pop();
            string x1 = st.top(); st.pop();
            string temp = '(' + x1 + s[i] + x2 + ')';
            st.push(temp);
        }
        else{
            st.push(string(1,s[i]));
        }
    }
    return st.top();
}
vector <int> calculateSpan(int price[], int n)
{
   // Your code here
    vector<int> s(n);
    stack<int> st;
    st.push(0);
    s[0] = 1;
    for(int i = 1;i<n;i++){
        while (!st.empty() && price[st.top()] <= price[i])
        {
            st.pop();
        }
        
        if(s.empty()){
            s[i] = i + 1;
        }else{
            s[i] = i - st.top();
        }
    }
    return s;
}

void printNGE(int a[],int n){
    stack<int> st;
    st.push(a[0]);
    for(int i = 1;i<n;i++){
        if(st.empty()){
            st.push(a[i]);
        }

        while (!st.empty() && st.top() < a[i])
        {
            cout << st.top() << "-->" << a[i] << endl;
            st.pop();
        }
        st.push(a[i]);
        

    }
    while (!st.empty())
    {
        /* code */
        cout << st.top() << "-->" << "-1" << endl;
        st.pop();
    }
}

void printNFE(int a[],int n,int freq[]){
    stack<int> s;
    s.push(0);
    int result[n] = {0};
    for(int i = 1;i<n;i++){
        if(freq[a[s.top()]] > freq[a[i]]){
            s.push(i);
        }else{
            while (!s.empty() && freq[a[s.top()]] < freq[a[i]])
            {
                result[s.top()] = a[i];
                s.pop();
            }
            
            s.push(i);
        }
    }
    while (!s.empty())
    {
        result[s.top()] == -1;
        s.pop();
    }
    for(int i = 0;i<n;i++){
        cout << result[i] << " ";
    }
}

void infix_to_postfix(string s){
    stack<char> st;
    st.push('N');
    int l = s.length();

    string ns;
    for(int i = 0;i<l;i++){
        if(!isoperator(s[i])){
            ns+= s[i];
        }else if(s[i] == '(')
        {
            st.push('(');
        }
        else if(s[i] == ')')
        {
            while (st.top() != 'N' && st.top() != 'N')
            {
                char c = st.top();
                st.pop();
                ns+= c;
            }
            if(st.top() == '('){
                char c = st.top();
                st.pop();
            }
            
        }
        else{
            while (st.top() != 'N' && pre(s[i]) <= pre(st.top()))
            {
                char c = st.top();
                st.pop();
                ns+= c;
            }
            st.push(s[i]);
        }
    }
    while (st.top() != 'N')
    {
        char c = st.top();
        st.pop();
        ns+=c;
    }
    cout << ns << endl;
}

void preintNGE(int a[],int n){
    stack<int> s;
    s.push((a[0]));
    for(int i = 1;i<n;i++){
        if(s.empty()){
            s.push(a[i]);
            continue;
        }

        while(!s.empty() && s.top() < a[i]){
            cout << s.top() << "-->" << a[i] << endl;
            s.pop();
        }
    }
    while (!s.empty())
    {
        cout << s.top() << "-->" << "-1" << endl;
    }
    
}

bool isoperator(char s){
    if(s == '+' || s== '-' || s== '/' || s == '*'
     || s == '^' || s == '(' || s == ')'){
        return true;
    }
    return false;
}
int evaluatePostfix(string &str)
{
    stack<int> s;
    int r;
    for(int i = 0;i<str.length();i++){
        if(!isoperator(str[i])){
            s.push(str[i] - '0');
        }else{
            int x2 = s.top(); s.pop();
            int x1 = s.top(); s.pop();

            switch (str[i])
            {
            case '+':
                r = x1 + x2;
                break;
            case '-':
                r = x1 - x2;
                break;
            case '*':
                r = x1 * x2;
                break;
            case '/':
                r = x1 / x2;
                break;
            default:
                break;
            }
            s.push(r);
        }
    }
    return s.top();
}
char* reverse(char *S, int len)
{
    //code here
    stack<char> s;
    for(int i = 0;i<len;i++){
        s.push(S[i]);
    }
    for(int i = 0;i<len;i++){
        S[i] = s.top();
        s.pop();
    }
    return S;
}



int _stack :: getMin()
{
   //Your code here
   if(s.empty()){
       return -1;
   }

   return minEle;
}

/*returns poped element from stack*/
int _stack ::pop()
{
   if(s.empty()){
       return -1;
   }else{
       int t = s.top();
       s.pop();
       if(t < minEle){
           minEle = 2*minEle - t;
       }
   }
}

/*push element x into the stack*/
void _stack::push(int x)
{
   //Your code here
   if(s.empty()){
       minEle = x;
       s.push(x);
   }
   else if(x < minEle){
       minEle = x;
        s.push(2*x - minEle);
   }else
   {
       s.push(x);
   }
   
}
int main(){
    
    return 0;
}