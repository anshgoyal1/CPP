#include<bits/stdc++.h>
using namespace std;

char tree[10];
int root(int key){
    if(tree[0] == '\0'){
        tree[0] = key;
    }else{
        cout << "tree already has root" << endl;
    }
    return tree[0];
}

int set_left(int val,int parent){
    if(tree[parent] == '\0'){
        return 0;
    }else{
        tree[(2*parent )+ 1] = val;
    }
    return val;
}

int set_right(int val,int parent){
    if(tree[parent] == '\0'){
        return 0;
    }else{
        tree[(2*parent )+ 2] = val;
    }
    return parent;
}

int print_tree()
{
    cout << "\n";
    for(int i = 0; i < 10; i++)
    {
        if(tree[i] != '\0')
            cout << tree[i];
        else
            cout << "-";
    }
    return 0;
}
 
// Driver Code
int main()
{
    root('A');
    //insert_left('B',0);
    set_right('C', 0);
    set_left('D', 1);
    set_right('E', 1);
    set_right('F', 2);
    print_tree();
    return 0;
}