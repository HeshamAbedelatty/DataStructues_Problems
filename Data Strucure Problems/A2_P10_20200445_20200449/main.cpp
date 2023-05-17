#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node*left;
    Node*right;
    Node(int x)
    {
        data = x;
        left =NULL;
        right = NULL;
    }
};
Node* InserDataIntoBinarySearchTree(Node* myNode, int data)
{
    (myNode == NULL)?new Node(data):(data < myNode->data)?myNode->left = InserDataIntoBinarySearchTree(myNode->left, data):(data > myNode->data)?myNode->right = InserDataIntoBinarySearchTree(myNode->right, data): myNode;
}
int count = 0;
Node * KthSmallest(Node* myNode, int k)
{
    if (myNode== NULL)
        return NULL;
    Node* left = KthSmallest(myNode->left, k);
    if (left != NULL)
        return left;
    count++;
    if (count == k)
    {
        count=0;
       return myNode;
    }

    Node* right= KthSmallest(myNode->right, k);
}

int ksmallestElementSum(Node *myNode, int k, int &counter)
{
    if (myNode == NULL || counter > k)
        return 0;
    int result = ksmallestElementSum(myNode->left, k, counter);
    if (counter >= k)
        return result;
    result += myNode->data;
    counter++;
    return (counter >= k)?result:result + ksmallestElementSum(myNode->right, k, counter);
}




int main()
{
    cout<<"Test Case 1 :\n";
    Node* root = new Node(49);
    root=InserDataIntoBinarySearchTree(root,51);
    root=InserDataIntoBinarySearchTree(root,52);
    root=InserDataIntoBinarySearchTree(root,54);
    root=InserDataIntoBinarySearchTree(root,74);
    root=InserDataIntoBinarySearchTree(root,75);
    root=InserDataIntoBinarySearchTree(root,85);
    int countt = 0;
    int k = 3;
    Node * m=KthSmallest(root, k);
    (m == NULL)?cout << "k is bigger than num of nodes in binary search tree\n\n":cout<<k<<"-th Smallest Element is "<<m->data <<"\nsum of all the elements which is less or equal to "<<m->data<<" is "<<ksmallestElementSum(root, k,countt)<<"\n";
    cout<<"-------------------------------------------------------------------\n\n";


    cout<<"Test Case 2 :\n";
    Node* root2 = new Node(15);
    root2=InserDataIntoBinarySearchTree(root2,12);
    root2=InserDataIntoBinarySearchTree(root2,10);
    root2=InserDataIntoBinarySearchTree(root2,8);
    root2=InserDataIntoBinarySearchTree(root2,13);
    root2=InserDataIntoBinarySearchTree(root2,90);
    root2=InserDataIntoBinarySearchTree(root2,2);
    countt = 0;
    k = 4;
    m=KthSmallest(root2, k);
    (m == NULL)?cout << "k is bigger than num of nodes in binary search tree\n\n":cout<<k<<"-th Smallest Element is "<<m->data <<"\nsum of all the elements which is less or equal to "<<m->data<<" is "<<ksmallestElementSum(root2, k,countt)<<"\n";
    cout<<"-------------------------------------------------------------------\n\n";



    cout<<"Test Case 3 :\n";
    Node * root3=NULL;
    root3=InserDataIntoBinarySearchTree(root3,51);
    root3=InserDataIntoBinarySearchTree(root3,42);
    root3=InserDataIntoBinarySearchTree(root3,93);
    root3=InserDataIntoBinarySearchTree(root3,15);
    root3=InserDataIntoBinarySearchTree(root3,73);
    root3=InserDataIntoBinarySearchTree(root3,66);
    countt = 0;
    k = 3;
    m=KthSmallest(root3, k);
    (m == NULL)?cout << "k is bigger than num of nodes in binary search tree\n\n":cout<<k<<"-th Smallest Element is "<<m->data <<"\nsum of all the elements which is less or equal to "<<m->data<<" is "<<ksmallestElementSum(root3, k,countt)<<"\n";
    cout<<"-------------------------------------------------------------------\n\n";



        cout<<"Test Case 4 :\n";
        Node* root4 = NULL;
         root4=InserDataIntoBinarySearchTree(root4,51);
         root4=InserDataIntoBinarySearchTree(root4,20);
         root4=InserDataIntoBinarySearchTree(root4,19);
         root4=InserDataIntoBinarySearchTree(root4,28);
         root4=InserDataIntoBinarySearchTree(root4,100);
         root4=InserDataIntoBinarySearchTree(root4,42);
         root4=InserDataIntoBinarySearchTree(root4,10);
         root4=InserDataIntoBinarySearchTree(root4,23);
        countt = 0;
         k = 5;
         m=KthSmallest(root4, k);
        (m == NULL)?cout << "k is bigger than num of nodes in binary search tree\n\n":cout<<k<<"-th Smallest Element is "<<m->data <<"\nsum of all the elements which is less or equal to "<<m->data<<" is "<<ksmallestElementSum(root4, k,countt)<<"\n";
        cout<<"-------------------------------------------------------------------\n\n";


        cout<<"Test Case 5 :\n";
        Node* root5 = NULL;

        root5=InserDataIntoBinarySearchTree(root5,24);
        root5=InserDataIntoBinarySearchTree(root5,86);
        root5=InserDataIntoBinarySearchTree(root5,53);
        root5=InserDataIntoBinarySearchTree(root5,15);
        root5=InserDataIntoBinarySearchTree(root5,78);
        root5=InserDataIntoBinarySearchTree(root5,22);
        root5=InserDataIntoBinarySearchTree(root5,11);

        countt = 0;
        k = 1;
        m=KthSmallest(root5, k);
        (m == NULL)?cout << "k is bigger than num of nodes in binary search tree\n\n":cout<<k<<"-th Smallest Element is "<<m->data <<"\nsum of all the elements which is less or equal to "<<m->data<<" is "<<ksmallestElementSum(root5, k,countt)<<"\n";
        cout<<"-------------------------------------------------------------------\n\n";


    return 0;
}


