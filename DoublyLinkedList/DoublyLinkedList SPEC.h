
// COS30008, Doubly-linked Nodes, Tutorial 9, 2022

#pragma once

template<typename T>
class DoublyLinkedList
{
private:
    T fPayload;
    DoublyLinkedList* fNext;
    DoublyLinkedList* fPrevious;
    
public:
    // l-value constructor and r-value constructor
    explicit DoublyLinkedList(const T& aPayload)
        :fPayload(aPayload), fNext(this), fPrevious(this) {};

    explicit DoublyLinkedList(T&& aPayload)
        :fPayload(move(aPayload)), fNext(this), fPrevious(this) {};

    // link functions
    DoublyLinkedList& push_front(DoublyLinkedList& aNode) {
        aNode.fNext = this;
        aNode.fPrevious = this->fPrevious;
        this->fPrevious->fNext = &aNode;
        this->fPrevious = &aNode;
        return *this;
    };

    DoublyLinkedList& push_back(DoublyLinkedList& aNode) {
        aNode.fPrevious = this;
        aNode.fNext = this->fNext;
        this->fNext->fPrevious = &aNode;
        this->fNext = &aNode;
        return *this; // allow method chaining
    };

    // unlink list node
    void isolate() {
        this->fPrevious->fNext = this->fNext;
        this->fNext->fPrevious = this->fPrevious;
        this->fNext = this->fPrevious = this;
    };
    
    // exchance payload positions of list nodes
    void swap(DoublyLinkedList& aNode) {
        T temp = this->fPayload;
        this->fPayload = aNode.fPayload;
        aNode.fPayload = temp;
    };
    
    // getters
    const T& operator*() const {
        return fPayload;
    };

    const T& getPayload() const {
        return fPayload;
    };
    const DoublyLinkedList& getNext() const {
        return *fNext;
    };
    const DoublyLinkedList& getPrevious() const {
        return *fPrevious;
    };
};
