#include "stack.h"

// TODO: Stack 클래스 구현 작성
Stack::Stack():LinkedList()
{
    tail = nullptr;
}

Stack::~Stack()
{
    LinkedList::~LinkedList();
}

// Stack의 정의에 맞게 데이터를 삽입한다.
void Stack::push(int data)
{
    Node* newNode = new Node(data);
    if (size_ == 0)
    {
        head_ = newNode;
        tail = newNode;
    }
    else
    {
        Node* temp = head_;
        for (int i = 0; i < size_; i++)
        {
            temp = temp->next_;
        }
        temp->next_ = newNode;
        tail = newNode;
    }
    size_++;
}

// Stack의 정의에 맞게 데이터를 꺼내고 적절한 메모리를 해제한다.
int Stack::pop()
{
    int result = tail->value_;
    Node* temp = head_;
    for (int i = 0; i < size_-1; i++)
    {
        temp = temp->next_;
    }
    tail = temp;
    temp = temp->next_;
    delete temp;
    size_--;
    return result;
} 

// Stack의 정의에 맞게 다음에 pop 될 값을 미리 본다.
int Stack::peek()
{
    return tail->value_;
}

void Stack::operator+=(int data)
{
    push(data);
}