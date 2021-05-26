#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cstring>
#define MAX_LEVEL 6
const float P = 0.5;
using namespace std;
struct Node
{
    int value;
    Node **www;
    Node(int element, int &value)
    {
        www = new Node * [element + 1];
        memset(www, 0, sizeof(Node*) * (element + 1));
        this->value = value; 
    }
    ~Node()
    {
        delete [] www;        
    } 
};
struct skiplist
{
    Node *header;
    int value;
    int element;
    skiplist() 
    {
        header = new Node(MAX_LEVEL, value);
        element = 0;
    }
    ~skiplist() 
    {
        delete header;
    }
    void print();
    bool Search(int &);
    void insertelement(int &);
    void deleteelement(int &);        
};
float frand() 
{
    return (float) rand() / RAND_MAX;
}
int random_level() 
{
    static bool first = true;
    if (first) 
    {
        srand((unsigned)time(NULL));
        first = false;
    }
    int lvl = (int)(log(frand()) / log(1.-P));
    return lvl < MAX_LEVEL ? lvl : MAX_LEVEL;
}

int main() 
{
    skiplist ss;
    int choice, n;
    
     while (true)
    {
        cout<<endl<<"-----------------------"<<endl;
        cout<<endl<<"Operations on Skip list"<<endl;
        cout<<endl<<"-----------------------"<<endl;
        cout<<"1.Insert Element"<<endl;
        cout<<"2.Search Element"<<endl;
        cout<<"3.Display List "<<endl;
        cout<<"4.Exit "<<endl;
        cout<<"Enter your choice : ";
        cin>>choice;
        if(choice==1)
        {
            cout<<"Enter the element to be inserted: ";
             cin>>n;
             ss.insertelement(n);
             if(ss.Search(n))
                 cout<<"Element Inserted"<<endl;
        }
       else if(choice==2)
        {
            cout<<"Enter the element to be searched: ";
             cin>>n; 
             if(ss.Search(n))
                 cout<<"Element "<<n<<" is in the list"<<endl;
             else
                 cout<<"Element not found"<<endl;
        }
        else if(choice==3)
        {
            cout<<"The List is: ";
             ss.print();
        }
        else if(choice==4)
        {
            exit(1);
            
        }
        else
        {
             cout<<"Wrong Choice"<<endl;
        }
       
    
}
return 0;
}

void skiplist::insertelement(int &value) 
{
    Node *x = header;	
    Node *update[MAX_LEVEL + 1];
    memset(update, 0, sizeof(Node*) * (MAX_LEVEL + 1));
    for (int i = element;i >= 0;i--) 
    {
        while (x->www[i] != NULL && x->www[i]->value < value) 
        {
            x = x->www[i];
        }
        update[i] = x; 
    }
    x = x->www[0];
    if (x == NULL || x->value != value) 
    {        
        int lvl = random_level();
        if (lvl > element) 
        {
            for (int i = element + 1;i <= lvl;i++) 
            {
                update[i] = header;
            }
            element = lvl;
        }
        x = new Node(lvl, value);
        for (int i = 0;i <= lvl;i++) 
        {
            x->www[i] = update[i]->www[i];
            update[i]->www[i] = x;
        }
    }
}

void skiplist::print() 
{
    const Node *x = header->www[0];
    while (x != NULL) 
    {
        cout << x->value;
        x = x->www[0];
        if (x != NULL)
            cout << " - ";
    }
    cout <<endl;
}

bool skiplist::Search(int &s_value) 
{
    Node *x = header;
    for (int i = element;i >= 0;i--) 
    {
        while (x->www[i] != NULL && x->www[i]->value < s_value)
        {
            x = x->www[i];
        }
    }
    x = x->www[0];
    return x != NULL && x->value == s_value;
}