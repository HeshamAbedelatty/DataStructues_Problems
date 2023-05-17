#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node* left;
    Node* right;
    Node(int d)
    {
        data=d;
        left=right=NULL;
    }
};
Node * root;
void TreeInOrder(Node* root)
{
    if (root != NULL)
    {
        TreeInOrder(root->left);
        cout << root->data <<",";
        TreeInOrder(root->right);
    }
}
void flip(Node* node=root )
{
    if(!node)
        return;
    Node *Temp=node->right;
    node->right=node->left;
    node->left=Temp;
    flip(node->left);
    flip(node->right);
}

int main()
{
    cout<<"Test Case 1:\n";
    Node*myNode=new Node(1);
    myNode->right=new Node(3);
    myNode->left=new Node(2);
    myNode->left->left=new Node(4);
    myNode->left->right=new Node(5);
    cout<<"Before Flipping:\t";
    TreeInOrder(myNode);
    flip(myNode);
    cout<<"\nAfter Flipping : \t";
    TreeInOrder(myNode);

    cout<<"\n\nTest Case 2:\n";
    Node*myNode2=new Node(10);
    myNode2->right=new Node(15);
    myNode2->left=new Node(9);
    myNode2->right->left=new Node(14);
    cout<<"Before Flipping:\t";
    TreeInOrder(myNode2);
    flip(myNode2);
    cout<<"\nAfter Flipping : \t";
    TreeInOrder(myNode2);


    cout<<"\n\nTest Case 3:\n";
    Node*myNode3=new Node(15);
    myNode3->right=new Node(18);
    myNode3->right->right=new Node(21);
    cout<<"Before Flipping:\t";
    TreeInOrder(myNode3);
    flip(myNode3);
    cout<<"\nAfter Flipping : \t";
    TreeInOrder(myNode3);

    cout<<"\n\nTest Case 4:\n";
    Node*myNode4=new Node(8);
    myNode4->right=new Node(1);
    myNode4->right->right=new Node(12);
    myNode4->right->left=new Node(4);
    myNode4->left=new Node(3);
    myNode4->left->left=new Node(2);
    myNode4->left->right=new Node(7);
    cout<<"Before Flipping:\t";
    TreeInOrder(myNode4);
    flip(myNode4);
    cout<<"\nAfter Flipping : \t";
    TreeInOrder(myNode4);

    cout<<"\n\nTest Case 5:\n";
    Node*myNode5=new Node(1);
    myNode5->right=new Node(2);
    myNode5->right->right=new Node(3);
    myNode5->right->right->right=new Node(4);
    myNode5->right->left=new Node(5);
    myNode5->left=new Node(6);
    myNode5->left->right=new Node(7);
    myNode5->left->left=new Node(8);
    myNode5->left->left->left=new Node(10);
    myNode5->left->left->right=new Node(9);
    cout<<"Before Flipping:\t";
    TreeInOrder(myNode5);
    flip(myNode5);
    cout<<"\nAfter Flipping : \t";
    TreeInOrder(myNode5);
    cout<<"\n\n\n";

}














