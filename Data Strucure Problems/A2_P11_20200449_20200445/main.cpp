#include <iostream>
using namespace std;
class BSTNODE
{

public:
    int data;
    BSTNODE* left,*right;
    BSTNODE(int item)
    {
        data=item;
        left=right=NULL;
    }
};

class BSTFCI
{
public:
    BSTNODE* N;
    BSTFCI(int key)
    {
        N = new BSTNODE(key);

    }
    bool isBalanced(BSTNODE* node,int * height)
    {
        int leftSubTreeHeight,RightSubTreeHeight=0;
        if (node == NULL)
        {
            *height=0;
            return 1;
        }
        isBalanced(node->left, &leftSubTreeHeight);
        isBalanced(node->right, &RightSubTreeHeight);
        *height=(leftSubTreeHeight>RightSubTreeHeight?leftSubTreeHeight:RightSubTreeHeight)+1;
        return (leftSubTreeHeight- RightSubTreeHeight)==1?1:0;
    }
    bool areTwoTreeSame(BSTNODE * t1, BSTNODE *t2)
    {
        return(t1 == NULL && t2 == NULL)?true:(t1 == NULL || t2 == NULL)?false:(t1->data == t2->data && areTwoTreeSame(t1->left, t2->left) && areTwoTreeSame(t1->right, t2->right) );
    }
    bool isSubtree(BSTNODE *tree, BSTNODE *sub_tree)
    {
        return (sub_tree == NULL)?true:(tree == NULL)?false:(areTwoTreeSame(tree, sub_tree))?true:isSubtree(tree->left, sub_tree) || isSubtree(tree->right, sub_tree);
    }
    bool isSubTree(BSTFCI* T, BSTFCI* S)
    {
        return isSubtree(T->N,S->N);
    }

    void CalculateRange(BSTNODE *myNode, int num1, int num2)
    {
        if(num1>num2)
        {
            int temp=num1;
            num1=num2;
            num2=temp;
        }
        if (myNode != NULL)
        {
            this->CalculateRange(myNode->left, num1, num2);
            if (myNode->data >= num1 && myNode->data <= num2)
            {
                cout<<"   " << myNode->data;
            }
            this->CalculateRange(myNode->right, num1, num2);
        }
    }
    void printRange(int num1,int num2)
    {
        if (this->N == nullptr)
            cout << "Empty Binary Search Tree";
        else
        {
            cout << "Numbers Between range ["<<num1<< "," << num2 << "] is " ;
            this->CalculateRange(this->N, num1, num2);
        }
        cout << endl;


    }

};







int main()
{
    int h=0;
    cout<<"BINARY SEARCH TREE 1 IN INORDER: [1,3,2,4,6,7,8,10,13,14]\n";
    cout<<"BINARY SEARCH TREE 2 IN INORDER: [1,3,2,4,6,7]\n";
    cout<<"BINARY SEARCH TREE 3 IN INORDER: [1,3,5,6,7,9,11]\n";
    cout<<"BINARY SEARCH TREE 4 IN INORDER: [1,3,5]\n";
    cout<<"BINARY SEARCH TREE 5 IN INORDER: [4,6,8,10,12,15,18,21,22]\n";
    cout<<"BINARY SEARCH TREE 6 IN INORDER: [15,18,21,22]\n";


    BSTFCI* tree1=new BSTFCI(8);
    tree1->N->right=new BSTNODE(10);
    tree1->N->right->right=new BSTNODE(14);
    tree1->N->right->right->left=new BSTNODE(13);
    tree1->N->left=new BSTNODE(3);
    tree1->N->left->left=new BSTNODE(1);
    tree1->N->left->right=new BSTNODE(6);
    tree1->N->left->right->right=new BSTNODE(7);
    tree1->N->left->right->left=new BSTNODE(4);
    tree1->N->left->right->left->left=new BSTNODE(2);

    BSTFCI* tree2=new BSTFCI(3);
    tree2->N->right=new BSTNODE(6);
    tree2->N->left=new BSTNODE(1);
    tree2->N->right->right=new BSTNODE(7);
    tree2->N->right->left=new BSTNODE(4);
    tree2->N->right->left->left=new BSTNODE(2);


    BSTFCI* tree3=new BSTFCI(6);
    tree3->N->right=new BSTNODE(9);
    tree3->N->left=new BSTNODE(3);
    tree3->N->left->left=new BSTNODE(1);
    tree3->N->left->right=new BSTNODE(5);
    tree3->N->right->right=new BSTNODE(11);
    tree3->N->right->left=new BSTNODE(7);

    BSTFCI* tree4=new BSTFCI(3);
    tree4->N->right=new BSTNODE(5);
    tree4->N->left=new BSTNODE(1);

    BSTFCI* tree5=new BSTFCI(10);
    tree5->N->right=new BSTNODE(18);
    tree5->N->left=new BSTNODE(6);
    tree5->N->left->left=new BSTNODE(4);
    tree5->N->left->left->left=new BSTNODE(8);
    tree5->N->left->left->left->left=new BSTNODE(12);
    tree5->N->right->right=new BSTNODE(21);
    tree5->N->right->left=new BSTNODE(15);
    tree5->N->right->right->right=new BSTNODE(22);


    BSTFCI* tree6=new BSTFCI(18);
    tree6->N->right=new BSTNODE(21);
    tree6->N->left=new BSTNODE(15);
    tree6->N->right->right=new BSTNODE(22);
    cout<<"-------------------------------------------------------------------\n";
    cout<<"IsBalanced Test Cases: \n";
    (tree1->isBalanced(tree1->N,&h))?cout << "Tree 1 is balanced"<<endl:cout << "Tree 1 is not balanced" <<endl;
    h=0;
    (tree2->isBalanced(tree2->N,&h))?cout << "Tree 2 is balanced"<<endl:cout << "Tree 2 is not balanced" <<endl;
    h=0;
    (tree3->isBalanced(tree3->N,&h))?cout << "Tree 3 is balanced"<<endl:cout << "Tree 3 is not balanced" <<endl;
    h=0;
    (tree4->isBalanced(tree4->N,&h))?cout << "Tree 4 is balanced"<<endl:cout << "Tree 4 is not balanced" <<endl;
    h=0;
    (tree5->isBalanced(tree5->N,&h))?cout << "Tree 5 is balanced"<<endl:cout << "Tree 5 is not balanced" <<endl;
    h=0;
    (tree6->isBalanced(tree6->N,&h))?cout << "Tree 6 is balanced"<<endl:cout << "Tree 6 is not balanced" <<endl;

    cout<<"-------------------------------------------------------------------\n";
    cout<<"IsSubTree Test Cases: \n";
    (tree1->isSubTree(tree1,tree2))?cout << "Tree 2 is subtree from Tree 1"<<endl:cout << "Tree 2 is not subtree from Tree 1" <<endl;
    (tree1->isSubTree(tree1,tree3))?cout << "Tree 3 is subtree from Tree 1"<<endl:cout << "Tree 3 is not subtree from Tree 1" <<endl;
    (tree1->isSubTree(tree3,tree4))?cout << "Tree 4 is subtree from Tree 3"<<endl:cout << "Tree 4 is not subtree from Tree 3" <<endl;
    (tree1->isSubTree(tree3,tree5))?cout << "Tree 5 is subtree from Tree 3"<<endl:cout << "Tree 5 is not subtree from Tree 3" <<endl;
    (tree1->isSubTree(tree5,tree6))?cout << "Tree 6 is subtree from Tree 5"<<endl:cout << "Tree 6 is not subtree from Tree 5" <<endl;
    cout<<"-------------------------------------------------------------------\n";
    cout<<"Print Range Test Cases: \n";
    cout<<"In Tree 1: ";
    tree1->printRange(3,8);
    cout<<"In Tree 2: ";
    tree2->printRange(4,7);
    cout<<"In Tree 3: ";
    tree3->printRange(9,11);
    cout<<"In Tree 4: ";
    tree4->printRange(1,5);
    cout<<"In Tree 5: ";
    tree5->printRange(4,22);
    cout<<"In Tree 6: ";
    tree6->printRange(18,21);




    cout<<"-------------------------------------------------------------------\n";






    return 0;
}
