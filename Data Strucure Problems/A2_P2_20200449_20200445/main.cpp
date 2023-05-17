#include <iostream>
using namespace std;
class myQueue
{
private:
    int *myQueueArray;
    int QueueMaximum;
    int QueueRear;
    int QueueFront;

public:
    myQueue(int numOfPersons)
    {
        myQueueArray = new int[numOfPersons];
        QueueMaximum = numOfPersons;
        QueueRear=numOfPersons-1;
        QueueFront=0;
    }
    void InsertToQueue(int temp)
    {
        QueueRear==QueueMaximum-1?QueueRear=0:QueueRear++;
        myQueueArray[QueueRear]=temp;
    }
    void DeleteFromQueue()
    {
        QueueFront==QueueMaximum-1?QueueFront=0:QueueFront++;
    }
    int returnQueueFront()
    {
        return myQueueArray[QueueFront];
    }
    int returnElementFromQueue(int myIndex)
    {
        return myQueueArray[myIndex];
    }
    ~myQueue()
    {
        delete[] myQueueArray;
    };

};

int main()
{
    int PersonsNumber,PersonTickets,temp;
    cout<<"Please Enter The Number Of Persons: ";
    cin>>PersonsNumber;
    temp=PersonsNumber;
    myQueue ArrayOfTickets(PersonsNumber);
    while(temp!=0)
    {
        cout<<"Person "<<PersonsNumber-temp<<" Please Enter how many tickets you want: ";
        cin>>PersonTickets;
        ArrayOfTickets.InsertToQueue(PersonTickets);
        temp--;
    }
    int k;
    cout<<"Please Enter The Position Of Searched Person: ";
    cin>>k;
    int numOfPasses=ArrayOfTickets.returnElementFromQueue(k);
    int FirstItem,AllTime=0;
    for(int i=0; i<numOfPasses,ArrayOfTickets.returnElementFromQueue(k)!=0; i++)
    {
        for(int j=0; j<PersonsNumber; j++)
        {

            if(ArrayOfTickets.returnQueueFront()==0)
            {
                ArrayOfTickets.DeleteFromQueue();
                ArrayOfTickets.InsertToQueue(0);
            }
            else
            {
                FirstItem=ArrayOfTickets.returnQueueFront();
                ArrayOfTickets.DeleteFromQueue();
                ArrayOfTickets.InsertToQueue(FirstItem-1);
                AllTime++;
            }

        }
    }
    cout<<"The person at position "<<k<<" has successfully bought "<<numOfPasses<<" tickets and it took "<<AllTime<<" seconds\n";
    return 0;
}
