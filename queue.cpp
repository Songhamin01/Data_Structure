#include "queue.h"

Queue::Queue():LinkedList()
{
    tail = nullptr;
}

Queue::~Queue(){}

// Queue의 정의에 맞게 데이터를 삽입한다.
void Queue::push(int data)
{
    Node* newNode = new Node(data);
    if (size_ == 0)
    {
        head_ = newNode;
        tail = newNode;
    }
    else
    {
       tail->next_ = newNode;
       tail = newNode;
    }
    size_++;
}

// Queue의 정의에 맞게 데이터를 꺼내고 적절한 메모리를 해제한다.
int Queue::pop()
{
   int result = head_->value_;
   Node* temp = head_->next_;
   delete head_;
   head_ = temp;
   size_--;
   return result;
}

// Queue의 정의에 맞게 다음에 pop 될 값을 미리 본다.
int Queue::peek()
{
    return head_->value_;
}

void Queue::operator+=(int data)
{
    push(data);
}

