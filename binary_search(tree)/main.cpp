#include <iostream>
#include <cstring>
#include <conio.h>
#include <iomanip>

using namespace std;


struct Tree
{
	Tree* left;
	Tree* right;
	int Inf;
};

class TreeDF {
private:
	Tree* root;

	Tree* add(int i, Tree* x) {
		if (x == nullptr) {
			x = new Tree;
			x->Inf = i;
			x->left = x->right = NULL;
		}
		else if (i < x->Inf)
			x->left = add(i, x->left);
		else if (i > x->Inf)
			x->right = add(i, x->right);
		return x;
	}

	void inorder(Tree* x) {
		if (x == NULL)
			return;
		inorder(x->left);
		cout << x->Inf << " ";
		inorder(x->right);
	}

	Tree* find(Tree* x, int i) {
		if (x == NULL)
			return NULL;
		else if (i < x->Inf)
			return find(x->left, i);
		else if (i > x->Inf)
			return find(x->right, i);
		else
			return x;
	}

public:
	TreeDF() {
		Tree* root = new Tree;
		root->Inf = NULL;
		root->left = root->right = NULL;
	}

	void add(int i) {
		root = add(i, root);
	}

	void show() {
		inorder(root);
		cout << endl;
	}

	bool find(int i) {
		return (find(root, i) != 0);
	}
};

int main() {
	int n, x;
	cout << "How many elements do you want to input?\nn = ";
	cin >> n;

	TreeDF example;
	
	cout << "Input elements:" << endl;
	for (int i = 0; i < n; i++) {
		cout << "x[" << i + 1 << "] = ";
		cin >> x;
		example.add(x);
	}

	example.show();

	cout << "Which element do you want to find?\nx = ";
	cin >> x;
	cout << "Is there an element " << x << " in the tree ? (1 - YES, 0 - NO)\nAnswer: " << example.find(x) << endl;

	cout << "Which element do you want to find?\nx = ";
	cin >> x;
	cout << "Is there an element " << x << " in the tree ? (1 - YES, 0 - NO)\nAnswer: " << example.find(x) << endl;

	return 0;
}



