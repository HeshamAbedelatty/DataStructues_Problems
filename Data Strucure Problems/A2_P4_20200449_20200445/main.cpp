#include <iostream>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
        right(right) {}
};

class Solution
{
public:

    bool isSymmetric(TreeNode* left, TreeNode *right)
    {
        if ((left == NULL) && (right == NULL))
        {
            return true;
        }
        else   if ((left != NULL) && (right != NULL))
        {
            return (left->val == right->val) &&
                   isSymmetric(left->right, right->left) &&
                   isSymmetric(left->left, right->right);
        }
        else
            return false;
    }

    bool isSymmetric(TreeNode* root)
    {
        return (root == nullptr)?true
               :isSymmetric(root->left, root->right);
    }
};

int main()
{
    Solution result;
    string rs;
    // use to display output :
    // if issymmetic == true return is symmetric ---- else isnot  symmetric
    cout<<"Test Case 1:\n";
    TreeNode* myNode1 = new TreeNode(1);
    myNode1->left = new TreeNode(2);
    myNode1->right = new TreeNode(3);
    myNode1->left->right = new TreeNode(4);
    myNode1->right->left = new TreeNode(5);
    rs=result.isSymmetric(myNode1)?"The binary tree [3,2,4,1,4,2,3] is symmetric\n\n":"The binary tree [3,2,4,1,4,2,3] is not symmetric\n";
    cout<<rs;
    cout << " ---------------------------------------------------------------------------------------- \n" ;
    cout<<"Test Case 2:\n";
    TreeNode* myNode2 = new TreeNode(1);
    myNode2->left = new TreeNode(2);
    myNode2->right = new TreeNode(2);
    myNode2->left->right = new TreeNode(3);
    myNode2->right->right = new TreeNode(3);
    rs=result.isSymmetric(myNode2)?"The binary tree [2,3,1,2,3] is symmetric\n\n":"The binary tree [2,3,1,2,3] is not symmetric\n";
    cout<<rs;
    cout << " \n---------------------------------------------------------------------------------------- \n" ;
    cout<<"Test Case 3:\n";
    TreeNode* myNode3 = new TreeNode(1);
    myNode3->left = new TreeNode(2);
    myNode3->right = new TreeNode(3);
    myNode3->left->right = new TreeNode(4);
    myNode3->right->left = new TreeNode(5);
    rs=result.isSymmetric(myNode3)?"The binary tree [4,2,1,3,5] is symmetric\n\n":"The binary tree [4,2,1,3,5] is not symmetric\n";
    cout<<rs;
    cout << " ---------------------------------------------------------------------------------------- \n" ;

    cout<<"Test Case 4:\n";
    TreeNode* myNode4 = new TreeNode(1);
    myNode4->left = new TreeNode(7);
    myNode4->right = new TreeNode(5);
    myNode4->left->right = new TreeNode(8);
    myNode4->right->right = new TreeNode(12);
    myNode4->right->right->right= new TreeNode(19);

    rs=result.isSymmetric(myNode4)?"The binary tree [ 8,5,7,1,12,19] is symmetric\n\n":"The binary tree [8,5,7,1,12,19] is not symmetric\n";
    cout<<rs;
    cout << " \n---------------------------------------------------------------------------------------- \n" ;
    cout<<"Test Case 5:\n";
    TreeNode* myNode5 = new TreeNode(1);
    myNode5->left = new TreeNode(2);
    myNode5->right = new TreeNode(3);
    myNode5->left->right = new TreeNode(4);
    myNode5->right->left = new TreeNode(5);
    myNode5->right->left-> right = new TreeNode(8);
    myNode5->left->right ->left= new TreeNode(14);



    rs=result.isSymmetric(myNode5)?"The binary tree [14,8,4,2,1,3,5] is symmetric\n\n":"The binary tree [14,8,4,2,1,3,5] is symmetric\n";
    cout<<rs;
    cout << " ---------------------------------------------------------------------------------------- \n" ;

}
