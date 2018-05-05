#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
#define MN 50000

struct node {
	int value;
	node *left;
	node *right;	
};

struct list {
	node *head;
	node *tail;
	list() {
		head = NULL;
		tail = NULL;
	}
	void addTail(node *p) {
		if (head == NULL) {
			head = tail = p;
			return;
		}
		tail->right = p;
		p->left = tail;
		tail = p;
	}
	double average() {
		if (head == NULL) return 0;
		int cnt = 1;
		long long sum = 0;
		node *p = head;
		while (p != tail) {
			sum += (p->value);
			++cnt;
			p= p->right;		
		}
		sum += (p->value);
		return (double)(sum) / cnt;
	}
	
	int order() {
		// 0 = khong co thu tu
		// 1 = tang dan tu trai -> phai
		// 2 = giam dan tu trai -> phai
		if (head == NULL) return 0;
		if (head == tail) return 1;
		node *p;
		if (head->value < tail->value) {
			p = head->right;
			while (p != tail) {
				if (p->value < (p->left)->value) return 0;
				p = p->right;	
			}
			return 1;
		}
		else {
			p = head->right;
			while (p != tail) {
				if (p->value > (p->left)->value) return 0;
				p = p->right;
			}
			return 2;
		}
	}
};

node *getnode(int x) {
	node *p = new node;
	p->value = x;
	p->left = NULL;
	p->right = NULL;
	return p;
}

void questA(list &a) {
	for (int i = 0; i < MN; ++i) {
		int x = rand();
		a.addTail(getnode(x));
	}
}

void questB(list a) {
	cout << "Gia tri trung binh cong la: " << a.average() << endl;
}

void questC(list a) {
	int ans = a.order();
	switch (ans) {
		case 1: cout << "list tang dan" << endl; break;
		case 2: cout << "list giam dan" << endl; break;
		default:
			cout << "list khong co thu tu" << endl;
	}
}

list a;

int main() {
	srand(time(NULL));
	questA(a);
	questB(a);
	questC(a);
	return 0;
}
