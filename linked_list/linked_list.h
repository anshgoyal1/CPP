class Node{
public:
	int data;
	Node *next;
}

class linked_list
{
private:
	Node *first;
public:
	linked_list(){
		first = NULL;
	};


	~linked_list();
	linked_list(int a[],int n){
		int i;
	struct Node *t,*last;
	first = new struct Node;
	first->data = a[0];
	first->next = NULL;
	last = first;
	for(i = 1;i<n;i++){
		t  = new struct Node;
		t->data = a[i];
		t->next = NULL;
		last->next = t;
		last = t;
	}
	}

	void display(struct Node *p){
	while(p != NULL){
		cout << p->data << " ";
		p = p->next;
	}
}

void display_reccursively(struct Node *p){
	if(p!=NULL)
		{
			cout << p->data << " ";
			display_reccursively(p->next);
	}
}

void display_reccursively_reverse(struct Node *p){
	if(p != NULL){
		display_reccursively_reverse(p->next);
		cout << p->data << " ";
	}
}

int length_of_list(struct Node *p){
	int c = 0;
	while(p!= NULL){
		c++;
		p = p->next;
	}
	return c;
}

int Add(struct Node *p){
	int sum = 0;
	while(p!=NULL){
		sum += p->data;
		p = p->next;
	}
	return sum;
}

int Add_reccursively(struct Node *p){
	if (p == 0)
		return 0;

	return Add_reccursively(p->next) + p->data;
}

int max_element_of_list(struct Node *p){
	int maxi = INT_MIN;
	while(p!=NULL){
		maxi = max(maxi,p->data);
		p = p->next;
	}
	return maxi;
}

int linked_list_linear_search(struct Node *p,int x){
	int i = 0;
	while(p!= NULL){
		if(p->data == x){
			cout << "Found" << endl;
			break;
		}
		i++;
		p = p->next;
	}
	return i;
}

struct Node *search(struct Node *p,int key){
	struct Node *q = NULL;
	while(p != NULL){
		if(p->data == key){
			q->next = p->next;
			p->next = first;
			first = p;
			return p;
		}

		q = p;
		p = p->next;
	}
	return NULL;
}

void insert(struct Node *p,int pos,int data){
	struct Node *t = new struct Node;
	if(pos == 0){
		t->data = data;
		t->next = first;
		first = t;
	}
	else if(pos > 0){
		for(int i = 0;i<pos-1;i++){
			p = p->next;
		}

		t->data = data;
		t->next = p->next;
		p->next = t;
	}
}

void insert_at_sort(struct Node *p,int key){
	struct Node *q = NULL;
	while(p != NULL && p->data < key){
		q = p;
		p = p->next;
	}

	auto *t = new struct Node;
	t->data = key;
	t->next = q->next;
	q->next = t;
}

int delete_node(int pos){
	struct Node *p= first;
	struct Node *q = NULL;
	int x;
	
	if(pos == 0){
		first = first->next;
		x = p->data;
		free(p);
	}
	else{
		for(int i = 0;i<pos-1;i++){
			q = p;
			p= p->next;
		}
		q->next = p->next;
		x = p->data;
		free(p);
	}
	return x;
}

bool is_sorted(struct Node *p){
	int x = INT_MIN;
	while(p!= NULL){
		if(x > p->data){
			return false;
		}
		x = p->data;
		p = p->next;
	}
	return true;
}
void delete_duplicates(){
	struct Node *p = first;
	struct Node *q = first->next;
	while(q!=NULL){
		if(p->data != q->data){
			p = q;
			q = q->next;
		}
		else{
			p->next = q->next;
			delete q;
			q = p->next;
		}
	}
}
void reverse_list(struct Node *p){
	int a[100];
	int i = 0;
	while(p!=NULL){
		a[i] = p->data;
		i++;
		p = p->next;
	}
	p = first;
	i--;
	while(p!=NULL){
		p->data = a[i--];
		p = p->next;
	}
}

void reverse1(struct Node *p){
	struct Node *q = NULL, *r = NULL;
	while(p != NULL){
		r = q;
		r = p;
		p = p->next;
		q->next = r;
	}

	first = q;
}

void reverse_reccursively(struct Node *q,struct Node *p){
	if(p != NULL){
		reverse_reccursively(p,p->next);
		p->next = q;
	}
	else{
		q = first;
	}
}
void concatenation(struct Node *p,struct Node *q){
	while(p->next != NULL){
		p = p->next;
	}p->next = q;
	q = NULL;
}

struct Node *third = NULL;
void merge(struct Node *p,struct Node *q){
	struct Node *last;
	if(p->data < q->data){
		third = last = p;
		p = p->next;
		third->next = NULL;
	}else{
		third = last = q;
		q = q->next;
		third->next = NULL;
	}

	while(p && q){
		if(p->data < q->data){
			last->next = p;
			last = p;
			p = p->next;
			last->next = NULL;
		}else{
			last->next = q;
			last = q;
			q = q->next;
			last->next = NULL;
		}
	}
	if(p)
		last->next = p;
	if(q)
		last->next = q;
}

bool isloop(struct Node *first){
	struct Node *p,*q;
	p = q = first;
	do{
		p = p->next;
		q = q->next;
		q = q? q->next:NULL;
	}while(p && q && p != q);

	if(p == q){
		return true;
	}else{
		return false;
	}
}
};