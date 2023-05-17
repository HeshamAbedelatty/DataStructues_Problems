#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    string data;
    Node*left,*right;
    Node()
    {
        data = "";
        left = NULL;
        right= NULL;
    }
    Node(string x)
    {
        left = NULL;
        right = NULL;
        data = x;
    }
};

int toInt(string s)
{
    int num = 0;

    if(s[0]!='-')
        for (int i=0; i<s.length(); i++)
            num = num*10 + (s[i]-'0');
    // If it is negative, calculate the +ve number
    // first ignoring the sign and invert the
    // sign at the end
    else
    {
        for (int i=1; i<s.length(); i++)
            num = num*10 + (s[i]-'0');
        num = num*-1;
    }

    return num;
}

// This function receives a node of the syntax tree
// and recursively evaluates it
int eval(Node* root)
{
    // empty tree
    if (!root)
        return 0;

    // leaf node i.e, an integer
    if (!root->left && !root->right)
        return toInt(root->data);

    // Evaluate left subtree
    int l_val = eval(root->left);

    // Evaluate right subtree
    int r_val = eval(root->right);

    // Check which operator to apply
    if (root->data=="+")
        return l_val+r_val;

    if (root->data=="-")
        return l_val-r_val;

    if (root->data=="*")
        return l_val*r_val;

    if (root->data== "/")
        return l_val/r_val;

    if (root->data== "^")
        return l_val^r_val;

    return l_val%r_val;
}
void Test1()
{
    cout << "Expression: + 3 * 4 / 8 2"<< endl;
    Node *root = new Node("+");
    root->left = new Node("3");
    root->right = new Node("*");
    root->right->left = new Node("4");
    root->right->right = new Node("/");
    root->right->left = new Node("8");
    root->right->right = new Node("2");
    cout <<"Evaluation: "<<eval(root) << endl;
    cout << "----------------------------------"<<endl;
    delete(root);
}
void Test2()
{
    cout << "Expression: + * 5 4 - 100 / 20 2"<< endl;
    Node * root = new Node("+");
    root->left = new Node("*");
    root->left->left = new Node("5");
    root->left->right = new Node("4");
    root->right = new Node("-");
    root->right->left = new Node("100");
    root->right->right = new Node("/");
    root->right->right->left = new Node("20");
    root->right->right->right = new Node("2");
    cout <<"Evaluation: "<<eval(root) << endl;
    cout << "----------------------------------"<<endl;
    delete (root);
}
void Test3()
{
    cout << "Expression: + + 4 2 * 3 - 15 1"<< endl;
    Node * root = new Node("+");
    root->left = new Node("+");
    root->left->left = new Node("4");
    root->left->right = new Node("2");
    root->right = new Node("*");
    root->right->left = new Node("3");
    root->right->right = new Node("-");
    root->right->right->left = new Node("15");
    root->right->right->right = new Node("1");
    cout <<"Evaluation: "<<eval(root) << endl;
    cout << "----------------------------------"<<endl;
    delete (root);
}
void Test4()
{
    cout << "Expression: / - % + 1 2 3 6 + 2 3"<< endl;
    Node * root = new Node("/");
    root->left = new Node("-");
    root->left->right = new Node("6");
    root->left->left = new Node("%");
    root->left->left->right = new Node("3");
    root->left->left->left = new Node("+");
    root->left->left->left->left = new Node("1");
    root->left->left->left->right = new Node("2");
    root->right = new Node("+");
    root->right->left = new Node("2");
    root->right->right = new Node("3");
    cout <<"Evaluation: "<<eval(root) << endl;
    cout << "----------------------------------"<<endl;
    delete (root);
}
void Test5()
{
    cout << "Expression: - + 3 + 4 * 15  6 + % 14 3 * 65 6"<< endl;
    Node * root = new Node("-");
    root->left = new Node("+");
    root->left->left = new Node("3");
    root->left->right = new Node("+");
    root->left->right->left= new Node("4");
    root->left->right->right= new Node("*");
    root->left->right->right->left= new Node("15");
    root->left->right->right->right= new Node("6");
    root->right = new Node("+");
    root->right->left = new Node("%");
    root->right->left->left= new Node("14");
    root->right->left->right= new Node("3");
    root->right->right = new Node("*");
    root->right->right->left = new Node("65");
    root->right->right->right = new Node("5");
    cout <<"Evaluation: "<<eval(root) << endl;
    cout << "----------------------------------"<<endl;
    delete (root);
}
int main()
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    return 0;
}
