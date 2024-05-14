#include "linked_list.h"

// TODO: LinkedList 클래스 구현 작성
LinkedList::LinkedList()
{
    head_ = nullptr;
    size_ = 0;
}

LinkedList::~LinkedList()
{
    for(int i = 0; i < size_; i++)
    {
        Node* temp = head_;
        head_ = head_->next_;
        delete temp;
    }
}

void LinkedList::insert(int index, int value)
{
    Node* newNode = new Node(value);
    Node* prev = nullptr;
    Node* temp = head_;
    for(int i = 0; i < index; i++)
    {
        prev = temp;
        temp = temp->next_;
    }
    if (index != 0)
    {
        prev->next_ = newNode;
    }
    else
        head_ = newNode;
    newNode->next_ = temp;
    size_++;
}

int LinkedList::get(int index)
{
    Node* temp = head_;
    for (int i = 0; i < index; i++)
    {
        temp = temp->next_;
    }
    return temp->value_;
}

void LinkedList::remove(int index)
{
    Node* prev = head_;
    Node* temp = head_;
    // temp를 제거 대상 이전노드로 이동
    for (int i = 0; i < index; i++)
    {
        prev = temp;
        temp = temp->next_;
    }
    if(index == 0)
        head_ = head_->next_;
    else
        prev->next_ = temp->next_;
    delete temp;
    size_--;
}

void LinkedList::print()
{
    Node* temp = head_;
    for(int i = 0; i < size_; i++)
    {
        std::cout << temp->value_ << " ";
        temp = temp->next_;
    }
    std::cout << std::endl;
}