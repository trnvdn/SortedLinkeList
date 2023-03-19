#include <iostream>
using namespace std;
struct Node
{
    int num;
    Node *next;
};
class List
{
private:
    Node *head;
public:
    List()
    {
        head = NULL;
    }

    void addNode(int d)
    {
        Node *nd = new Node;
        nd->num = d;
        nd->next = NULL;
        if(head == NULL)
        {
            head = nd;
        }
        else
        {
            Node *current = head;
            while(current->next != NULL)
            {
                current = current->next;
            }
            current->next = nd;
        }
    }
    void printList()
    {
        Sort();
        Node *current = head;
        cout<<endl;
        cout<<endl;
        while(current != NULL)
        {
            cout << current->num << " ";
            current = current->next;
        }
        cout<<endl;
        cout<<endl;
    }
    void Remove()
    {
        int value;
        int index = 1;
        Node *temp;
        bool isCorrect = false;
        Node *current = head;
        cout<<"Delete by: \n1.Index\n2.By value first occurence"<<endl;
        int n;
        cin>>n;
        switch(n)
        {
            case 1:
                cout<<"Enter index"<<endl;
                cin >> value;
                while (current->next != NULL)
                {
                    if (index == value-1)
                    {
                        temp = current->next;
                        current->next = current->next->next;
                        delete temp;
                        isCorrect = true;
                        break;
                    }
                    current = current->next;
                    index++;
                }
                break;
            case 2:
                cout<<"Enter value"<<endl;
                cin >> value;
                while (current->next != NULL)
                {
                    if (current->next->num == value)
                    {
                        temp = current->next;
                        current->next = current->next->next;
                        delete temp;
                        isCorrect = true;
                        break;
                    }
                    current = current->next;
                }
                break;
            default:
                cout<<"Uncorrect variant"<<endl;
        }
        if (!isCorrect)
        {
            cout << "Error!" << endl;
        }
        printList();

    }

    void Sort(){
        Node *left = head;
        Node *right = head->next;

        Node *temp = new Node;
        while (left->next)
        {
            while (right)
            {
                if ((left->num) > (right->num))
                {
                    temp->num = left->num;
                    left->num = right->num;
                    right->num = temp->num;
                }
                right = right->next;
            }
            left = left->next;
            right = left->next;
        }
    }
};
int main()
{
    List List;
    while (true)
    {
        int choise;
        cout<<"1.Add data\n2.Print data\n3.Remove data"<<endl;
        cin>>choise;
        switch (choise)
        {
            case 1:
                cout<<"Enter num"<<endl;
                int num;
                cin>>num;
                List.addNode(num);
                break;
            case 2:
                List.printList();
                break;
            case 3:
                List.Remove();
                break;
        }
    }
}