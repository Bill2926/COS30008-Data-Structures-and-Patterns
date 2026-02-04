//The Iterator Class
//This maintains the current state :
//
//Current position / index in the sequence
//Reference back to the Range object(to know start, end, step)

#include "range.cpp"

class Iterator {
private:
	int current;
	Range& fRange;	// to know which range it belongs to
public:
	Iterator(Range& aR, int pos = 0) : current(pos), fRange(aR) {};

	int getPos() const {
		return current;
	};

	int operator*() const {
		// Return the current value at right now pos
		int result = fRange.getStart() + (current * fRange.getStep());
		return result;
	};

	Iterator& operator++() {
		current++;
		return *this;
	}

	Iterator operator++(int) {
		Iterator temp = *this;
		++(*this);
		return temp;
	}

	bool operator==(const Iterator& anotherI) const {
		return (current == anotherI.getPos()) && (&fRange == &anotherI.fRange);
	};

	bool operator!=(const Iterator& anotherI) const {
		return !(*this == anotherI);
	};
};