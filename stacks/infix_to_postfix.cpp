#include<bits/stdc++.h>
using namespace std;
bool isOperator(char x) {
  switch (x) {
  case '+':
  case '-':
  case '/':
  case '*':
    return true;
  }
  return false;
}
int prec(char c){
    if(c == '^'){
        return 3;
    }
    else if(c == '*' || c == '/'){
        return 2;
    }
    else if(c == '+' || c == '-'){
        return 1;
    }
    else{
        return 0;
    }
}

void pretoinfix(string s){
    stack<string> st;
    int len = s.length();

    for(int i = len - 1;i>=0;i--){
        if(isOperator(s[i])){
            string op1 = st.top(); st.pop();
            string op2 = st.top(); st.pop();

            string k = "(" + op1 + s[i] + op2 + ")";
            st.push(k);
            
        }else{
            st.push(string(1,s[i]));
        }
    }
    
    cout << st.top() << endl;
}

void infixToPostfix(string s){
    stack<char> st;
    st.push('N');
    int l = s.length();
    string result;
    for(int i = 0;i<l;i++){
        if((s[i] >= 'a' && s[i] <= 'z') ||
        (s[i] >= 'A' && s[i] <= 'Z')){
            result += s[i];
        }

        else if(s[i] == '('){
            st.push('(');
        }
        else if(s[i] == ')'){
            while(st.top() != 'N' && st.top() != '('){
                char c = st.top();
                st.pop();
                result += c;
            }
            if(st.top() == '('){
                char c = st.top();
                st.pop();
            }
        }
        else{
            while(st.top() != 'N' && prec(s[i]) <= prec(st.top())){
                char c = st.top();
                st.pop();
                result += c;
            }
            st.push(s[i]);
        }
    }

    while(!st.empty()){
        char c = st.top();
                st.pop();
                result += c;
    }
    cout << result << endl;
}

void pretopost(string s){
    stack<string> st;
    int l = s.length();
    for(int i = l - 1;i>=0;i--){
        if(isOperator(s[i])){
            string op1 = st.top();
            st.pop();
            string op2 = st.top();
            st.pop();
            string temp = op1 + op2 + s[i];
            st.push(temp);
        }else{
            st.push(string(1,s[i]));
        }
    }
    cout << st.top() << endl;
}
void posttoin(string s){
    stack<string> st;
    int l = s.length();
    for(int i = 0;i<l;i++){
        if(!isOperator(s[i])){
            st.push(string(1,s[i]));
        }else{
            string op1 = st.top(); st.pop();
            string op2 = st.top(); st.pop();
            string temp = "(" + op2 + s[i] + op1 + ")";
            st.push(temp);
        }
    }
    cout << st.top() << endl;
}
void stock_span(int a[],int n,int s[]){
    stack<int> st;
    st.push(0);

    s[0] = 1;
    for(int i = 1;i<n;i++){
        while(!st.empty() && a[st.top()] <= a[i]){
            st.pop();
        }
        s[i] = (st.empty())?i+1: i - st.top();
        st.push(i);
    }

}
void posttopre(string s){
    stack<string> st;
    int l = s.length();
    for(int i = 0;i<l;i++){
        if(isOperator(s[i])){
            string op1 = st.top(); st.pop();
            string op2 = st.top(); st.pop();

            string temp = s[i] + op2 + op1;
            st.push(temp);
        }else{
            st.push(string(1,s[i]));
        }
    }
    cout << st.top() << endl;
}
stack<char> st;
string ns;
void insert_at_bottom(char x){
    if(st.size() == 0){
        st.push(x);
    }
    else{

        char a = st.top();
        st.pop();
        insert_at_bottom(x);

        st.push(a);
    }
}

void reverse(){
    if(st.size() > 0){
        char x  = st.top();
        st.pop();

        reverse();

        insert_at_bottom(x);
    }
}

stack<int> stsort;
void sorted_insert(int x){
    if(stsort.empty() && x > stsort.top()){
        stsort.push(x);
    }else{
        int a = stsort.top();
        stsort.pop();
        sorted_insert(x);

        stsort.push(a);
    }
}

void sort(){
    if(!stsort.empty()){
        int x = stsort.top();
        stsort.pop();

        sort();

        sorted_insert(x);
    }
}

void sort_stack(stack<int> s){
    stack<int> temp;
    while(!s.empty()){
        int t = s.top();
        s.pop();
        while(!temp.empty() && temp.top() > t){
            int x = temp.top();
            temp.pop();
            s.push(x);
        }
        temp.push(t);
    }
}

void sort_array_using_stack(vector<int> a){
    stack<int> s;
    while(!a.empty()){
        int t = a.back();
        a.pop_back();
        while(!s.empty() && t > s.top()){
            a.push_back(s.top());
            s.pop();
        }
        s.push(t);
    }
    while(!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }
}
void deleteElements(int a[],int n,int k){
    stack<int> s;
    s.push(a[0]);
    int count = 0;
    for(int i = 1;i<n;i++){
        while(!s.empty() && s.top() < a[i] && count < k){
            s.pop();
            count++;
        }
        s.push(a[i]);
    }

    vector<int> res;
    while(!s.empty()){
        res.push_back(s.top());
        s.pop();
    }
}

bool check_queue_can_be_sorted(int n,queue<int> q){
    stack<int> st; 
    int expected = 1; 
    int fnt; 
  
    // while given Queue is not empty. 
    while (!q.empty()) { 
        fnt = q.front(); 
        q.pop(); 
  
        // if front element is the expected element 
        if (fnt == expected) 
            expected++; 
  
        else { 
            // if stack is empty, push the element 
            if (st.empty()) { 
                st.push(fnt); 
            } 
  
            // if top element is less than element which 
            // need to be pushed, then return fasle. 
            else if (!st.empty() && st.top() < fnt) { 
                return false; 
            } 
  
            // else push into the stack. 
            else
                st.push(fnt); 
        } 
  
        // while expected element are coming from 
        // stack, pop them out. 
        while (!st.empty() && st.top() == expected) { 
            st.pop(); 
            expected++; 
        } 
    } 
  
    // if the final expected element value is equal 
    // to initial Queue size and the stack is empty. 
    if (expected - 1 == n && st.empty()) 
        return true; 
  
    return false; 
}
int main(){
    queue<int> q; 
    q.push(5); 
    q.push(1); 
    q.push(2); 
    q.push(3); 
    q.push(4); 
  
    int n = q.size(); 
  
    (check_queue_can_be_sorted(n,q) ? (cout << "Yes") : 
                         (cout << "No")); 
    return 0; 
}