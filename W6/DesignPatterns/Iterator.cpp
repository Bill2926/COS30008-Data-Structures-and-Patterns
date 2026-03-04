#include <iostream>

using namespace std;

class Iterator {
	// Iterator interface, this class dictates every Iterator behaviors
	// Every subclass (special Iterator class) must implement
public:
	virtual ~Iterator() {};
	virtual void getNext() = 0;
	virtual bool hasMore() = 0;
};

class IterableCollection {
	// Interface (parent) of all special Iterator(s) we planned to create
public:
	virtual ~IterableCollection() {};
	virtual Iterator* createIterator() = 0;
};

class ConcreteCollection : public IterableCollection {
	// Our special collection
private:
	string books[3] = { "Cpp basics", "Lmao", "Intro to AI" };
public:
	//ConcreteCollection(Iterator* anIter) : it_ptr(anIter) {};
	Iterator* createIterator() override;
	int size() const { return 3; }
	string getBook(int index) const {
		return books[index];
	}
};

class ConcreteIterator : public Iterator {
	// Our special Iterator created to SERVE ConcreteCollection
private:
	ConcreteCollection* bookCollection;
	int currentPosition = 0;
public:
	ConcreteIterator(ConcreteCollection* c) : bookCollection(c) {};

	bool hasMore() override {
		if (currentPosition < bookCollection->size()) {
			return true;
		}
		else {
			return false;
		}
	}

	void getNext() override {
		if (hasMore()) {
			cout << "Current book: " << bookCollection->getBook(currentPosition) << endl;
			currentPosition++;
		}
		else {
			cout << "ERROR" << endl;
		}
	}
};

Iterator* ConcreteCollection::createIterator() {
	return new ConcreteIterator(this);
}

int main() {
	IterableCollection* concol = new ConcreteCollection;
	Iterator* concol_iter = concol->createIterator();
	concol_iter->getNext();
	cout << concol_iter->hasMore() << endl;
	concol_iter->getNext();
	concol_iter->getNext();
	cout << concol_iter->hasMore() << endl;
	concol_iter->getNext();

	delete concol;
	delete concol_iter;
	return 0;
}