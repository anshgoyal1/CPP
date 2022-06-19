#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *next;
};

struct Node *first = NULL;

void create(int a[], int n)
{
	int i;
	struct Node *t, *last;
	first = new struct Node;
	first->data = a[0];
	first->next = NULL;
	last = first;
	for (i = 1; i < n; i++)
	{
		t = new struct Node;
		t->data = a[i];
		t->next = NULL;
		last->next = t;
		last = t;
	}
}

void display(struct Node *p)
{
	while (p != NULL)
	{
		cout << p->data << " ";
		p = p->next;
	}
}

void display_reccursively(struct Node *p)
{
	if (p != NULL)
	{
		cout << p->data << " ";
		display_reccursively(p->next);
	}
}

void display_reccursively_reverse(struct Node *p)
{
	if (p != NULL)
	{
		display_reccursively_reverse(p->next);
		cout << p->data << " ";
	}
}

void reverse(struct Node *p)
{
	struct Node *q = NULL, *r = NULL;
	while (p != NULL)
	{
		r = p->next;
		p->next = q;
		q = p;
		p = r;
	}
	p = q;
}
int length_of_list(struct Node *p)
{
	int c = 0;
	while (p != NULL)
	{
		c++;
		p = p->next;
	}
	return c;
}

Node *reverse_in_groups_of_k(Node *head, int k)
{
	struct Node *curr = head;
	Node *next = NULL, Node *prev = NULL;
	int count = 0;
	while (curr != NULL && count < k)
	{
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
		count++;
	}

	if (next != NULL)
	{
		head->next = reverse_in_groups_of_k(next, k);
	}
	return head;
}
int Add(struct Node *p)
{
	int sum = 0;
	while (p != NULL)
	{
		sum += p->data;
		p = p->next;
	}
	return sum;
}

int Add_reccursively(struct Node *p)
{
	if (p == 0)
		return 0;

	return Add_reccursively(p->next) + p->data;
}

int max_element_of_list(struct Node *p)
{
	int maxi = INT_MIN;
	while (p != NULL)
	{
		maxi = max(maxi, p->data);
		p = p->next;
	}
	return maxi;
}

int linked_list_linear_search(struct Node *p, int x)
{
	int i = 0;
	while (p != NULL)
	{
		if (p->data == x)
		{
			cout << "Found" << endl;
			break;
		}
		i++;
		p = p->next;
	}
	return i;
}

vector<pair<int, int>> sumpairs(Node *head, int k)
{
	unordered_map<int, int> m;
	Node *p = head;
	while (p != NULL)
	{
		m[p->data]++;
		p = p->next;
	}
	Node *q;
	while (q != NULL)
	{
		int d = k - q->data;
		if (m[d])
		{
		}
	}
}

int countTriplets(Node *head, int x)
{
	unordered_map<int, int> m;
	;
	Node *p = head;
	while (p != NULL)
	{
		m[p->data]++;
		p = p->next;
	}
	int count = 0;
	for (Node *ptr1 = head; ptr1 != NULL; ptr1 = ptr1->next)
	{
		for (Node *ptr2 = ptr1->next; ptr2 != NULL; ptr2 = ptr2->next)
		{
			int d = x - ptr1->data - ptr2->data;
			if (m[d])
			{
				count++;
			}
		}
	}
	return count / 3;
}

struct Node *search(struct Node *p, int key)
{
	struct Node *q = NULL;
	while (p != NULL)
	{
		if (p->data == key)
		{
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

void insert(struct Node *p, int pos, int data)
{
	struct Node *t = new struct Node;
	if (pos == 0)
	{
		t->data = data;
		t->next = first;
		first = t;
	}
	else if (pos > 0)
	{
		for (int i = 0; i < pos - 1; i++)
		{
			p = p->next;
		}

		t->data = data;
		t->next = p->next;
		p->next = t;
	}
}

void insert_at_sort(struct Node *p, int key)
{
	struct Node *q = NULL;
	while (p != NULL && p->data < key)
	{
		q = p;
		p = p->next;
	}

	auto *t = new struct Node;
	t->data = key;
	t->next = q->next;
	q->next = t;
}

int delete_node(int pos)
{
	struct Node *p = first;
	struct Node *q = NULL;
	int x;
	if (pos == 0)
	{
		first = first->next;
		x = p->data;
		free(p);
	}
	else
	{
		for (int i = 0; i < pos - 1; i++)
		{
			q = p;
			p = p->next;
		}
		q->next = p->next;
		x = p->data;
		free(p);
	}
	return x;
}

bool is_sorted(struct Node *p)
{
	int x = INT_MIN;
	while (p != NULL)
	{
		if (x > p->data)
		{
			return false;
		}
		x = p->data;
		p = p->next;
	}
	return true;
}

void move_to_front(Node *head)
{
	if (head == NULL || head->next == NULL)
	{
		return;
	}

	Node *secLast = NULL;
	Node *last = head;
	while (last->next)
	{
		secLast = last;
		last = last->next;
	}
	secLast = NULL;
	last->next = head;
	head = last;
}
void delete_duplicates()
{
	struct Node *p = first;
	struct Node *q = first->next;
	while (q != NULL)
	{
		if (p->data != q->data)
		{
			p = q;
			q = q->next;
		}
		else
		{
			p->next = q->next;
			delete q;
			q = p->next;
		}
	}
}
void reverse_list(struct Node *p)
{
	int a[100];
	int i = 0;
	while (p != NULL)
	{
		a[i] = p->data;
		i++;
		p = p->next;
	}
	p = first;
	i--;
	while (p != NULL)
	{
		p->data = a[i--];
		p = p->next;
	}
}

void reverse1(struct Node *p)
{
	struct Node *q = NULL, *r = NULL;
	while (p != NULL)
	{
		r = p;
		p = p->next;
		q->next = r;
	}

	first = q;
}
}
}

void add_two_numbers(Node *p, Node *q)
{
	Node *r = new struct Node;
	Node *last;
	int sum = p->data + q->data;
	int carry = 0;
	if (sum > 9)
	{
		carry = sum - 9;
	}
	r->data = sum % 10;
	r->next = NULL;
	last = r;
	p = p->next;
	q = q->next;
	while (p && q)
	{
		sum = carry + p->data + q->data;

		if (sum > 9)
		{
			carry = sum - 9;
		}
		sum = sum % 10;

		Node *temp = new struct Node;
		temp->data = sum;
		temp->next = NULL;
		last->next = temp;
		last = temp;
	}
	while (p)
	{
		sum = carry + p->data;

		if (sum > 9)
		{
			carry = sum - 9;
		}
		sum = sum % 10;

		Node *temp = new struct Node;
		temp->data = sum;
		temp->next = NULL;
		last->next = temp;
		last = temp;
	}
	while (q)
	{
		sum = carry + q->data;

		if (sum > 9)
		{
			carry = sum - 9;
		}
		sum = sum % 10;

		Node *temp = new struct Node;
		temp->data = sum;
		temp->next = NULL;
		last->next = temp;
		last = temp;
	}
}

void reverse_reccursively(struct Node *q, struct Node *p)
{
	if (p != NULL)
	{
		reverse_reccursively(p, p->next);
		p->next = q;
	}
	else
	{
		q = first;
	}
}
void concatenation(struct Node *p, struct Node *q)
{
	while (p->next != NULL)
	{
		p = p->next;
	}
	p->next = q;
	q = NULL;
}

struct Node *third = NULL;
void merge(struct Node *p, struct Node *q)
{
	struct Node *last;
	if (p->data < q->data)
	{
		third = last = p;
		p = p->next;
		third->next = NULL;
	}
	else
	{
		third = last = q;
		q = q->next;
		third->next = NULL;
	}

	while (p && q)
	{
		if (p->data < q->data)
		{
			last->next = p;
			last = p;
			p = p->next;
			last->next = NULL;
		}
		else
		{
			last->next = q;
			last = q;
			q = q->next;
			last->next = NULL;
		}
	}
	if (p)
		last->next = p;
	if (q)
		last->next = q;
}
Node *find_first_of_loop(Node *head)
{
	if (head == NULL || head->next == NULL)
	{
		return NULL;
	}

	Node *slow = head;
	Node *fast = head;
	slow = slow->next;
	fast = fast->next->next;

	while (fast != NULL && fast->next != NULL)
	{
		if (slow == fast)
		{
			break;
		}
		slow = slow->next;
		fast = fast->next->next;
	}

	if (slow != fast)
	{
		return NULL;
	}
	slow = head;
	while (slow != fast)
	{
		slow = slow->next;
		fast = fast->next;
	}
	return slow;
}
bool isloop(struct Node *first)
{
	struct Node *p, *q;
	p = q = first;
	do
	{
		p = p->next;
		q = q->next;
		q = q ? q->next : NULL;
	} while (p && q && p != q);

	if (p == q)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void insert_node_in_clist(struct Node *head, int pos, int x)
{
	struct Node *p, *t;
	p = head;
	if (pos == 0)
	{
		t = new struct Node;
		t->data = x;
		if (head == NULL)
		{
			head = t;
			head->next = head;
		}
		else
		{
			while (p->next != head)
				p = p->next;
			p->next = t;
			t->next = head;
			head = t;
		}
	}
	else
	{
		for (int i = 0; i < pos - 1; i++)
		{
			p = p->next;
		}
		t = new struct Node;
		t->data = x;
		t->next = p->next;
		p->next = t;
	}
}

void rotateList(Node **head, int n)
{
	if (head == NULL)
	{
		return;
	}
	Node *curr = *head;
	int count = 1;
	while (count < n && curr != NULL)
	{
		count++;
		curr = curr->next;
	}

	if (curr == NULL)
	{
		return;
	}
	Node *NthNode = curr;
	while (curr != NULL)
	{
		curr = curr->next;
	}
	curr->next = *head;
	*head->prev = curr;
	*head = NthNode->next;
	*head->prev = NULL;
	NthNode->next = NULL;
}

void reverse(Node *head, int k)
{
	Node *newHead = NULL;
	Node *curr = head;
	Node *next = NULL;
	int count = 0;
	while (count < k && curr != NULL)
	{
		next = curr->next;
		push(&newHead, curr);
		curr = next;
		count++;
	}
}

void push(Node **head, int new_data)
{
	Node *new_node = new Node();
	new_node->data = new_data;
	new_node->next = *head;
	*head = new_node;
}

void union_and_intersection(Node *root1, Node *root2)
{
	unordered_map<int, int> mp;
	while (root1 || root2)
	{
		while (root1)
		{
			mp[root1->data]++;
			root1 = root1->next;
		}
		while (root2)
		{
			mp[root2->data]++;
			root2 = root2->next;
		}
	}
	Node *Union = NULL;
	for (auto it : mp)
	{
		push(&Union, it.first);
	}
}

int main()
{
	struct Node *temp;
	int A[] = {3, 5, 7, 7, 10, 25, 8, 32, 2};
	create(A, 8);
	concatenation(first, first);
	// cout << is_sorted(first) << endl;
	// delete_duplicates();
	// display(first);
	cout << isloop(first) << endl;
	// cout << linked_list_linear_search(first,25) << endl;
	return 0;
}