#include <iostream>

using namespace std;
int search(char arr[], char x, int n)
{
    for (int i = 0; i < n; i++)
        if (arr[i] == x)
            return i;
    return -1;
}

void print(char in[], char pre[], int n)
{
        int root = search(in, pre[0], n);

    if (root != 0)
        print(in, pre + 1, root);

    if (root != n - 1)
        print(in + root + 1, pre + root + 1, n - root - 1);

    cout << pre[0] << " ";
}
void printPostOrder(string str1,string str2)
{
    char a1[str1.size()],a2[str1.size()];
    for (int i = 0 ;i<str1.size();i++)
    {
        a1[i] = str1[i];
        a2[i] = str2[i];
    }
    print(a2,a1,str1.size());
    cout << endl;
}
int main()
{
    //FGBCA
    printPostOrder("ABFGC", "FBGAC");
    /*
              4
           3     5
         1   2
    */
    //1 2 3 5 4
    printPostOrder("43125","13245");
    /*
              A
           B     C
    */
    //BCA
    printPostOrder("ABC","BAC");
    /*
               A
           B       C
         F   G   D   H
    */
    //F G B D H C A
    printPostOrder("ABFGCDH","FBGADCH");
    /*
                 5
            3         7
         2    4     6   8

    */
    //2 4 3 6 8 7 5
    printPostOrder("5324768","2345678");

    return 0;
}
