
// COS30008, Doubly-linked Nodes, Tutorial 9, 2022

#pragma once

#include "DoublyLinkedList SPEC.h"

template<typename T>
class DoublyLinkedListIterator
{
private:
	enum class States { BEFORE, DATA , AFTER };					// iterator states

	using Node = DoublyLinkedList<T>;

	const Node* fRoot;											// doubly-linked list

    States fState;												// iterator state
    const Node* fCurrent;										// iterator position
    
public:
    
	using Iterator = DoublyLinkedListIterator<T>;

	DoublyLinkedListIterator(const Node* aRoot)					// constructor
		:fRoot(aRoot), 
		fCurrent(aRoot),
		fState(aRoot != nullptr ? States::DATA : States::AFTER)
	{};				
	
	const T& operator*() const {								// dereference 
		return fCurrent->getPayload();
	};	        	

	Iterator& operator++() {
		switch (fState)
		{
		case States::BEFORE:
			fCurrent = fRoot;
			if (fCurrent == nullptr) fState = States::AFTER;
			else fState = States::DATA;
			break;

		case States::DATA:
			fCurrent = &fCurrent->getNext();   // always advance first
			if (fCurrent == fRoot) {
				fState = States::AFTER;
			}
			break;

		case States::AFTER:
			break;
		}
		return *this;
	}

	Iterator operator++(int) {
		Iterator temp = *this;
		++(*this);
		return temp;
	};									

	Iterator& operator--() {
		switch (fState)
		{
		case States::AFTER:
			fCurrent = &fRoot->getPrevious();  // last element
			fState = States::DATA;
			break;

		case States::DATA:
			if (fCurrent == fRoot) {
				fState = States::BEFORE;
			}
			else {
				fCurrent = &fCurrent->getPrevious();
			}
			break;

		case States::BEFORE:
			break;
		}
		return *this;
	}

	Iterator operator--(int) {
		Iterator temp = *this; // Capture old state
		--(*this);             // Move the actual iterator back using prefix --
		return temp;
	};									// postfix decrement

	bool operator==(const Iterator& aOtherIter) const {
		return (fRoot == aOtherIter.fRoot) &&
			(fState == aOtherIter.fState) &&
			(fCurrent == aOtherIter.fCurrent);
	};		

	bool operator!=(const Iterator& aOtherIter) const {
		return !(*this == aOtherIter);
	};		

	Iterator begin() const {
		return Iterator(fRoot);
	}

	Iterator end() const {
		Iterator temp(fRoot);
		temp.fState = States::AFTER;
		return temp;
	}

	Iterator rbegin() const {
		Iterator temp(fRoot);
		if (fRoot != nullptr) {
			temp.fCurrent = &fRoot->getPrevious();
			temp.fState = States::DATA;
		}
		else {
			temp.fState = States::BEFORE; 
		}
		return temp;
	}

	Iterator rend() const {
		Iterator temp(fRoot);
		temp.fState = States::BEFORE;
		return temp;
	}
};
