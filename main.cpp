#include <iostream>

template<typename T>
class List
{
public:
    
     List();
    ~List();
    
    void push_back(T data);
    void push_front(T data);
        
    void pop_front();
    void pop_back();
    
    void insert(T data, const int index);
    void removeAt(int index);
    
    void ShiftRight();
    
    void Sort();
    
    void Reverse();
    
    void clear()
    {
        while(Size != 0)
        {
            pop_front();
        }
    }
    
    int GetSize() { return Size; }
    
    T& operator[](const int index);
    
private:
    
    class Node
    {
    public:
        Node* _next;
        Node* _prev;
        T     _data;
        
        Node(T data = T(), Node* prev = nullptr, Node* next = nullptr )
        {
            _data = data;
            _prev = prev;
            _next = next;
        }
    };
    int Size;
    
    Node *head;
    Node *tail;
};

template<typename T>
List<T>::List()
{
    head = nullptr;
    tail = nullptr;
    
    Size = 0;
}

template<typename T>
List<T>::~List()
{
    clear();
}

template<typename T>
void List<T>::push_back(T data)
{
    if(head == nullptr)
    {
        head = tail = new Node(data);
    }
    else
    {
        tail->_next = new Node(data, tail, nullptr);
        
        tail = tail->_next;
    }
    
    ++Size;
}

template<typename T>
void List<T>::push_front(T data)
{
    if(head == nullptr)
    {
        head = tail = new Node(data);
    }
    else
    {
        head->_prev = new Node(data, nullptr, head);
        
        head = head->_prev;
    }
    
    ++Size;
}

template<typename T>
void List<T>::pop_back()
{
    if(Size == 1)
    {
        delete head;
        
        head->_next = nullptr;
    }
    else
    {
        tail = tail->_prev;
        
        delete tail->_next;
        
        tail->_next = nullptr;
    }
}

template<typename T>
void List<T>::pop_front()
{
    if(Size == 1)
    {
        delete head;
        
        head->_next = nullptr;
    }
    else
    {
        head = head->_next;
        
        delete head->_prev;
        
        head->_prev = nullptr;
    }
    
    --Size;
}

template<typename T>
T& List<T>::operator[](const int index)
{
    Node* new_curr = head;
    int counter = 0;
    
    if(index <= Size / 2)
    {
        while(counter < index)
        {
            new_curr = new_curr->_next;
            
            ++counter;
        }
        
        return new_curr->_data;
    }
    else
    {
        counter  = Size - 1;
        new_curr = tail;
        
        while(counter > index)
        {
            new_curr = new_curr->_prev;
            
            --counter;
        }
        
        return new_curr->_data;
    }
}

int main()
{
    List<int> lst;
    
    lst.push_back(1);
    lst.push_back(2);
    lst.push_back(3);
    lst.push_back(4);
            
    for(int i = 0; i < lst.GetSize(); ++i)
    {
        std::cout << lst[i] << " " ;
    }
    std::cout << std::endl;
        
    return 0;
}


