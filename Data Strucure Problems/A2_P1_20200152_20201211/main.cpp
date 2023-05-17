#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    string data;
    Node*next;
    Node()
    {
        data = "";
        next = NULL;
    }
};
class Stack
{
    Node * top;
    int Count = 0;
public:
    Stack()
    {
        top = NULL;
    }
    bool isEmpty()
    {
        if(top == NULL)
            return true;
        else
            return false;
    }
    void Push (string value)
    {
        Count ++;
        if (isEmpty())
        {
            Node *newNode = new Node ();
            newNode->data = value;
            newNode->next = NULL;
            top = newNode;
        }
        else
        {
            Node *newNode = new Node ();
            newNode->data = value;
            newNode->next = top;
            top = newNode;
        }
    }
    string Pop()
    {
        Count--;
        Node *delptr = top;
        string value;
        value = top->data;
        top = top->next;
        delete delptr;
        return value;
    }
    string Top()
    {
        return top->data;
    }
    int Size()
    {
        return Count;
    }
};

string solution(string S)
{
    string result;
    string garbage;
    Stack  s;
    result.append("/");
    int l = S.length(); //len to l
    for (int i = 0; i < l; i++)
    {

        garbage.clear();

        while (S[i] == '/')
            i++;

        while (i < l && S[i] != '/')
        {
            garbage.push_back(S[i]);
            i++;
        }

        if (garbage.compare("..") == 0)
        {
            if (!s.isEmpty())
                s.Pop();
        }

        else if (garbage.compare(".") == 0)
            continue;

        else if (garbage.length() != 0)
            s.Push(garbage);
    }

    Stack Test ;
    while (!s.isEmpty())
    {
        Test.Push(s.Top());
        s.Pop();
    }

    while (!Test.isEmpty())
    {
        string temp = Test.Top();

        if (Test.Size() != 1)
            result.append(temp + "/");
        else
            result.append(temp);

        Test.Pop();
    }

    return result;
}

int main()
{
    string array[5];
    for (int i = 0; i < 5; i++)
    {
        cin >> array[i];
        string str(array[i]);
        string r = solution(str);
        cout <<r<<endl;
        cout << "-----------------------"<<endl;
    }

    return 0;
}
