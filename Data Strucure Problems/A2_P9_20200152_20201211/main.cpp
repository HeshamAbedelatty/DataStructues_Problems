#include <bits/stdc++.h>
using namespace std;


class Node {
public:
	int data;
	Node * left;
	Node * right;
    Node()
    {
        data = 0;
        left = NULL;
        right= NULL;
    }
    Node(int value)
    {
	   data = value;
	   left = NULL;
	   right = NULL;
    }
};


void mirror(Node* Test)
{
    if (Test == NULL)
        return;
    else {
        Node* temp;

        mirror(Test->left);
        mirror(Test->right);

        temp = Test->left;
        Test->left = Test->right;
        Test->right = temp;
    }
}
bool isStructSame(Node* a, Node* b)
{
	if (a == NULL && b == NULL) {
		return true;
	}
	if (a != NULL && b != NULL && isStructSame(a->left, b->left) && isStructSame(a->right, b->right)) {
		return true;
	}
	return false;
}

bool FoldabilltyCheck(Node* root)
{
	bool result;

	if (root == NULL)
		return true;

	mirror(root->left);

	result = isStructSame(root->left, root->right);

	mirror(root->left);

	return result;
}

void Test1()
{
    /*
         1
		/ \
       4   3
		\ /
		5 3
	*/
	Node* root = new Node(1);
	root->left = new Node(4);
	root->right = new Node(3);
	root->right->left = new Node(3);
	root->left->right = new Node(5);
    if (FoldabilltyCheck(root) == 1) {
		cout << "tree is foldable"<<endl;
	}
	else {
		cout << "tree is not foldable"<< endl;
	}
	delete(root);
}
void Test2()
{
    /*
         1
		/ \
       2   3
      /     \
	 4     	 5
	*/
	Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->right->right = new Node(5);
	root->left->left = new Node(4);
    if (FoldabilltyCheck(root) == 1) {
		cout << "tree is foldable"<<endl;
	}
	else {
		cout << "tree is not foldable"<< endl;
	}
	delete(root);
}
void Test3()
{
    /*
        10
       /  \
      7   15
     /    /
    5   11
	*/
	Node* root = new Node(10);
	root->left = new Node(7);
	root->right = new Node(15);
	root->right->left = new Node(11);
	root->left->left = new Node(5);

	if (FoldabilltyCheck(root) == 1) {
		cout << "tree is foldable"<<endl;
	}
	else {
		cout << "tree is not foldable"<< endl;
	}
	delete(root);
}

void Test4()
{
    /*
          1
		/   \
       2     3
	  / \   / \
     5   4 7   6
	*/
	Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->right->left = new Node(7);
	root->right->right = new Node(6);
	root->left->right = new Node(4);
    root->left->left = new Node(5);
	if (FoldabilltyCheck(root) == 1) {
		cout << "tree is foldable"<<endl;
	}
	else {
		cout << "tree is not foldable"<< endl;
	}
	delete(root);
}
void Test5()
{
    /*
          1
		/   \
       2     3
	    \   / \
         4 7   6
	*/
	Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->right->left = new Node(7);
	root->right->right = new Node(6);
	root->left->right = new Node(4);

	if (FoldabilltyCheck(root) == 1) {
		cout << "tree is foldable"<<endl;
	}
	else {
		cout << "tree is not foldable"<< endl;
	}
	delete(root);
}
int main(void)
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
	return 0;
}

