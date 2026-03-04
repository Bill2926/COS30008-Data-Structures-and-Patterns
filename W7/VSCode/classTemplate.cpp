#include <iostream>

using namespace std;

template<typename DataType>
struct SinglyLinkedList {
    DataType data;
    SinglyLinkedList* nextNode;

    SinglyLinkedList(DataType& aData, SinglyLinkedList* aNode = nullptr)
        : data(aData), nextNode(aNode) {}

    SinglyLinkedList(DataType&& aData, SinglyLinkedList* aNode = nullptr)
        : data(move(aData)), nextNode(aNode) {}

    void outLoud() const {
        cout << "I'm " << data << ", " << "my next is: " << nextNode->data<< endl;
    }
};

template<typename T>
void recur(SinglyLinkedList<T>* aSingLi) {
    if (aSingLi == nullptr) {
        return;
    }

    cout << "I'm " << aSingLi->data << ", " << "my next is: " << aSingLi->nextNode<< endl;
    recur(aSingLi->nextNode);
}

using intList = SinglyLinkedList<int>;
using nameList = SinglyLinkedList<string>;

int main() {
    // string name = "bill";
    // SinglyLinkedList genesis(name);
    // SinglyLinkedList<string> ec("Ec", &genesis);
    // genesis.outLoud();
    // ec.outLoud();

    nameList per1("Bill");
    nameList per2("Arabica", &per1);
    nameList per3("Ec", &per2);

    recur(&per3);

    return 0;
}