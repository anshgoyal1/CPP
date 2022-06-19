#include <bits/stdc++.h>

using namespace std;

struct Node
{
	struct Node *prev;
	int data;
	struct Node *next;
};
struct Node *first = NULL;
void create(int a[],int n){
	int i;
	struct Node *t;
	struct Node *last;
	first = new struct Node;
	first->data = a[0];
	first->prev = first->next = NULL;
	last = first;
	for(int i = 1;i<n;i++){
		t = new struct Node;
		t->data = a[i];
		t->next = last->next;
		t->prev = last;
		last->next = t;
		last = t;
	}
}


void insert(struct Node *p,int pos,int x){
	struct Node *t;
	if(pos == 0){
		t = new struct Node;
		t->data = x;
		t->prev = NULL;
		t->next = first;
		first->prev = t;
		first = t;
	}
	else{
		for(int i = 0;i<pos-1;i++){
			p = p->next;
		}
		t = new struct Node;
		t->data = x;
		t->prev = p;
		t->next = p->next;
		if(p->next){
			p->next->prev = t;
			
		}p->next = t;
	}
}
void display(struct Node *p){
	while(p){
		cout << p->data << " ";
		p = p->next;
	}
}
int main(){
	int a[] = {1,2,3,4,5};
	int n = 5;
	create(a,n);
	display(first);
}