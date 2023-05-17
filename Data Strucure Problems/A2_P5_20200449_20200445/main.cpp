#include<bits/stdc++.h>
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
    bool isSameTree(TreeNode* p, TreeNode* q)
    {
        if(p == NULL || q == NULL)
            return q==p;
        return p->val != q->val?false:!isSameTree(p->left, q->left)? false:isSameTree(p->right, q->right);
    }
};
int main()
{
    Solution result;
    cout<<"Result of Example 1 , p = [1,2,3], q = [1,2,3] : ";
    TreeNode* p=new TreeNode(1);
    p->right=new TreeNode(2);
    p->right->right=new TreeNode(3);
    TreeNode* q=new TreeNode(1);
    q->right=new TreeNode(2);
    q->right->right=new TreeNode(3);
    string rs=result.isSameTree(p,q)?"true\n":"false\n";
    cout<<rs<<endl;

    cout<<"Result of Example 2 , p = [1,2], q = [1,null,2] : ";
    TreeNode* p2=new TreeNode(2);
    p2->left=new TreeNode(1);
    TreeNode* q2=new TreeNode(2);
    q2->left=new TreeNode(NULL);
    q2->left->left=new TreeNode(1);
    rs=result.isSameTree(p2,q2)?"true\n":"false\n";
    cout<<rs<<endl;

    cout<<"Result of Example 3 , p = [1,2,1], q = [1,1,2] : ";
    TreeNode* p3=new TreeNode(1);
    p3->right=new TreeNode(2);
    p3->right->right=new TreeNode(1);
    TreeNode* q3=new TreeNode(1);
    q3->right=new TreeNode(1);
    q3->right->right=new TreeNode(2);
    rs=result.isSameTree(p3,q3)?"true\n":"false\n";
    cout<<rs<<endl;

    cout<<"Result of Example 4 , p = [5,7,2,1,8], q = [5,7,2,1,8] : ";
     TreeNode* p4=new TreeNode(2);
    p4->right=new TreeNode(1);
    p4->right->right=new TreeNode(8);
    p4->left=new TreeNode(7);
    p4->left->left=new TreeNode(5);
    TreeNode* q4=new TreeNode(2);
    q4->right=new TreeNode(1);
    q4->left=new TreeNode(7);
    q4->left->left=new TreeNode(5);
    q4->right->right=new TreeNode(8);
    rs=result.isSameTree(p4,q4)?"true\n":"false\n";
    cout<<rs<<endl;


    cout<<"Result of Example 5 , p = [8,null,7,6,3,1,4,2], q = [8,null,7,6,3,1,4,2] : ";
    TreeNode* p5=new TreeNode(7);
    p5->right=new TreeNode(6);
    p5->right->right=new TreeNode(3);
    p5->left=new TreeNode(NULL);
    p5->left->left=new TreeNode(8);
    p5->right->right->right=new TreeNode(1);
    p5->right->right->right->right=new TreeNode(4);
    p5->right->right->right->right->right=new TreeNode(2);
    TreeNode* q5=new TreeNode(7);
    q5->right=new TreeNode(6);
    q5->right->right=new TreeNode(3);
    q5->left=new TreeNode(NULL);
    q5->left->left=new TreeNode(8);
    q5->right->right->right=new TreeNode(1);
    q5->right->right->right->right=new TreeNode(4);
    q5->right->right->right->right->right=new TreeNode(2);
    rs=result.isSameTree(p5,q5)?"true\n":"false\n";
    cout<<rs<<endl;
}
