#include<bits/stdc++.h>
using namespace std;

class Node
{  public:
    any data;
    Node*next;
    Node *previous;

    Node(auto data)
    {
        this->data = data;
        next = NULL;
        previous = NULL;
    }
    
    void print_node()
     {
        if(data.type() == typeid(double))
        {
            cout<<any_cast<double>(data);
        }
        else if(data.type() == typeid(float))
        {
            cout<< any_cast<float>(data);
        }
        else if(data.type() == typeid(long long))
        {
            cout<<any_cast<long long>(data);
              
        }
        else if(data.type() == typeid(long))
        {
           cout<<any_cast<long>(data);
        }
        else if(data.type() == typeid(int))
        {
            cout<<any_cast<int>(data);
        }
        else if(data.type() == typeid(char))
        {
            cout<<any_cast<char>(data);
        }
        else if(data.type() == typeid( const char*))
        {
            cout<<any_cast<const char*>(data);
        }
     }

     
     
  
};

class List
{
     Node* head;
     Node* tail;
     int size;
     public:
     List()
     {
         head = NULL;
         tail = NULL;
         size = 0;
     }
     bool empty()
     {
         return size == 0;
     }
     int Size()
     {
         return size;
     }

     void insert_at_end(auto data)
     {
         if(head == NULL)
         {
             head = new Node(data);
             tail = head;
         }
         else
         {
            Node *newnode = new Node(data);
            tail->next = newnode;
            newnode->previous = tail;
            tail = newnode;
            
             
         }
         size++;
     }
     void insert_at_start(auto data)
     {
         if(head == NULL)
         {
             head = new Node(data);
             tail = head;
             
         }
         else
         {
            Node* newhead = new Node(data);
            head->previous = newhead;
            newhead->next = head;
            head = newhead;
         }
         
         size++;
     }
     
     void print()
     {
         if(empty())
         {
             cout<<"[]"<<endl;
             return;
         }
         Node* h = head;
         cout<<"["<<"";
         while(h->next!=NULL)
         {
             h->print_node();
             cout<<",";
             h = h->next;
         }
         h->print_node();
         cout<<"]"<<endl;
     }

     void delete_at_end()
     {
         if(empty())
         {
             return;
         }
         else if(size == 1)
         {
              delete tail;
              tail = NULL;
              head = NULL;
             
             

         }
         else
         {
             Node* deletenode = tail;
             tail = tail->previous;
             tail->next = NULL;
             delete deletenode;
         }
         size--;
         
     }
     void delete_at_start()
     {
         if(empty())
         {
             return;
         }
         else if(size == 1)
         {
             delete head;
             head = NULL;
             tail = NULL;
         }
         else
         {
            Node*deletenode = head;
            deletenode->next->previous = NULL;
            head = head->next;
            delete deletenode;
         }
         
         size--;
     }
     any get(int index)
     {
         if(index>=size || index<0)
         {
             return "bad input";
             //throw exception
         }
         else
         {
              Node* temp = head;
              
              int i = 0;
              while(i<index)
              {
                  temp = temp->next;
                  i++;
              }

              return temp->data; 
              
         }
     }


};



