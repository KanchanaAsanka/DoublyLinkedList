#ifndef DOUBLY_LINKED_LIST 
#define DOUBLY_LINKED_LIST

#include<iostream>
using namespace std;
template <typename T>
struct Node
{
    T data;
    Node *next, *prv;

    Node():next(nullptr), prv(nullptr){}
    Node(T val): data(val), next(nullptr), prv(nullptr){}
    Node(T val, Node *nxtVal):data(val), next(nxtVal), prv(nullptr){}
    Node(T val, Node *nxtVal, Node *prvVal):data(val), next(nxtVal), prv(prvVal){}
};


template<typename T>
class DoublyLinkedList
{
private:
    Node<T> *head, *tail;
    int iSize;
public:
    DoublyLinkedList();
    ~DoublyLinkedList();
    bool isEmpty();
    void AddToHead(T val);
    void AddToTail(T val);
    bool AddTo(int index, T val);
    T front();
    T back();
    bool removeNode(T val);
    bool removeNodefrom(int index);
    T findIndexData(int index);
    bool findData(T val);
    void printLL();
};

template<typename T>
DoublyLinkedList<T>::DoublyLinkedList()
{
    head = nullptr;
    tail = nullptr;
    iSize = 0;
}
template<typename T>
DoublyLinkedList<T>::~DoublyLinkedList()
{
    Node<T> *runner = head;

    while(runner)
    {
        Node<T> *tmp = runner->next;
        delete runner;
        runner = tmp;
    }
}
template<typename T>
bool DoublyLinkedList<T>::isEmpty()
{
    return iSize == 0? true: false;
}

template<typename T>
void DoublyLinkedList<T>::AddToHead(T val)
{
    if(head)
    {
        Node<T> *node = new Node(val, head);
        head->prv = node;
        head = node;
    }
    else
    {
        head = new Node(val);
        tail = head;
    }
    iSize++;
}

template<typename T>
void DoublyLinkedList<T>::AddToTail(T val)
{
    if(tail)
    {
        Node<T> *node = new Node(val);
        tail->next = node;
        node->prv = tail;
        tail = node;
    }
    else
    {
        tail = new Node(val);
        head = tail;
    }
    iSize++;
}

template<typename T>
bool DoublyLinkedList<T>::AddTo(int index, T val)
{
    if(index> iSize+1)
        return false;

    if(index == 1)
    {
        AddToHead(val);
        return true;
    }
    else if(index == iSize+1)
    {
        AddToTail(val);
        return true;
    }
    Node<T> *runner=nullptr;
    if(index < (iSize/2))
    {
        runner = head;
        int iCnt=1;

        while(iCnt<index && runner)
        {
            iCnt++;
            runner = runner->next;
        }
        Node<T> *newNode = new Node(val, runner, runner->prv);
        runner->prv->next = newNode;
        runner->prv = newNode;         
    }
    else
    {
        runner=tail;
        int iCnt=iSize;

        while (iCnt>=index && runner)
        {
            iCnt--;
            runner = runner->prv;
        }
        Node<T> *newNode = new Node(val, runner->next, runner);
        runner->next->prv = newNode;
        runner->next = newNode;
        
    }   
    iSize++;
    return true;
}

template<typename T>
T DoublyLinkedList<T>::front()
{
    if(!head)
        throw std::runtime_error("Empty lsit");
    return head->data;
}

template<typename T>
T DoublyLinkedList<T>::back()
{
    if(!tail)
        throw std::runtime_error("Empty lsit");    
    return tail->data;
}

template<typename T>
bool DoublyLinkedList<T>::removeNodefrom(int index)
{
    if(index> iSize)
        return false;

    if(index == 1)
    {
        Node<T> *tmp = head->next;
        delete head;
        head = tmp;
        head->prv = nullptr;
        iSize--;
        return true;
    }
    else if(index == iSize)
    {
        Node<T> *tmp = tail->prv;
        delete tail;
        tail = tmp;
        tail->next = nullptr;
        iSize--;
        return true;
    }
    Node<T> *runner=nullptr;
    if(index < (iSize/2))
    {
        runner = head;
        int iCnt=1;

        while(runner && iCnt < index)
        {
            iCnt++;
            runner = runner->next;
        }
    }
    else
    {
        runner=tail;
        int iCnt=iSize;

        while (runner && iCnt>index)
        {
            iCnt--;
            runner = runner->prv;
        }
        
    }
    runner->prv->next = runner->next;
    runner->next->prv= runner->prv;
    iSize--;
    delete runner; 

    return true;
}

template<typename T>
bool DoublyLinkedList<T>::removeNode(T val)
{
    Node<T> *runner = head;
    bool bFound = false;
    
    while(runner)
    {
        if(runner->data == val)
        {
            bFound=true;
            Node<T> *tmpNode = runner->next;
            
            if(runner->prv)
                runner->prv->next = tmpNode;
            else
                head = tmpNode;
            
            if(tmpNode)
                tmpNode->prv = runner->prv;
            else
                tail = runner->prv;    
            
            delete runner;
            runner = tmpNode;   
            iSize--;
        }
        else
            runner = runner->next;
    }
    return bFound;
}

template<typename T>

void DoublyLinkedList<T>::printLL()
{
    Node<T> *runner=head;

    while(runner)
    {
        cout<<runner->data<<" ";
        runner=runner->next;
    }
    cout<<endl;
}

template<typename T>
T DoublyLinkedList<T>::findIndexData(int index)
{
    if(index > iSize)
        throw std::runtime_error("index outof bound");
    
    Node<T> *runner =nullptr;
    if(index < iSize/2)
    {
        runner=head;
        int iCnt=1;

        while(iCnt < index && runner)
        {
            iCnt++;
            runner = runner->next;
        }
    }
    else
    {
        runner=tail;
        int iCnt=iSize;

        while(runner && iCnt > index)
        {
            iCnt--;
            runner = runner->prv;
        }
    }
    return runner->data;
}

template<typename T>
bool DoublyLinkedList<T>::findData(T val)
{
    Node<T> *runner = head;
    
    while(runner)
    {
        if(runner->data == val)
            return true;
        runner = runner->next;
    }
    return false;
}
#endif