#include <bits/stdc++.h>

using namespace std;

struct Stack
{
	int size;
	int top;
	int *S;
};
void create(struct Stack *st)
{
	printf("Enter Size");
	scanf("%d",&st->size);
	st->top=-1;
	st->S=(int *)malloc(st->size*sizeof(int));
	}
void Display(struct Stack st)
{
	int i;
	for(i=st.top;i>=0;i--)
	printf("%d ",st.S[i]);
	printf("\n");
}
void push(struct Stack *st,int x)
{
	if(st->top==st->size-1)
	printf("Stack overflow\n");
	else
	{
	st->top++;
	st->S[st->top]=x;
	}

}
int pop(struct Stack *st)
{
	int x=-1;
	if(st->top==-1)
	printf("Stack Underflow\n");
	else
	{
	x=st->S[st->top--];
	}
	return x;
}
int peek(struct Stack st,int index)
{
	int x=-1;
	if(st.top-index+1<0)
	printf("Invalid Index \n");
	x=st.S[st.top-index+1];
	return x;
}
int isEmpty(struct Stack st)
{
	if(st.top==-1)
	return 1;
	return 0;
}
int isFull(struct Stack st)
{
	return st.top==st.size-1;
	}
int stackTop(struct Stack st)
{
	if(!isEmpty(st))

	return st.S[st.top];
	return -1;
}
stack<int> st;
void insert_at_bottom(int x){
	if(st.empty()){
		st.push(x);
	}else{
		int a = st.top();
		st.pop();
		insert_at_bottom(x);

		st.push(a);
	}
}

void reverse(){
	if(st.size() > 0){
		int x = st.top();
		st.pop();

		reverse();

		insert_at_bottom(x);
	}
}
int main()
{
	struct Stack st;
	create(&st);
	push(&st,10);
	push(&st,20);
	push(&st,30);
	push(&st,40);
	printf("%d \n",peek(st,2));

	Display(st);
	return 0;
}