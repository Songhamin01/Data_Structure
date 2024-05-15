#include "stack.h"

// TODO: Stack 클래스 구현 작성
Stack::Stack():LinkedList()
{
    tail = nullptr;
}

Stack::~Stack(){}

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
       newNode->next_ = head_;
       head_ = newNode;
    }
    size_++;
}

// Stack의 정의에 맞게 데이터를 꺼내고 적절한 메모리를 해제한다.
int Stack::pop()
{
    int result = head_->value_;
    Node* temp = head_->next_;
    delete head_;
    head_ = temp;
    size_--;
    return result;
} 

// Stack의 정의에 맞게 다음에 pop 될 값을 미리 본다.
int Stack::peek()
{
    return head_->value_;
}

void Stack::operator+=(int data)
{
    push(data);
}