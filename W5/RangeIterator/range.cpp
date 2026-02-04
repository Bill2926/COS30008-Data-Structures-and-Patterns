//The Range Class
//This holds the parameters of your range :
//
//Start value(where to begin)
//End value(where to stop, exclusive like in Python)
//Step value(how much to increment each time)
//
//Example conceptual ranges :
//
//Range(0, 10, 1) → 0, 1, 2, 3, 4, 5, 6, 7, 8, 9
//Range(5, 15, 2) → 5, 7, 9, 11, 13
//Range(10, 0, -1) → 10, 9, 8, 7, 6, 5, 4, 3, 2, 1

class Range {
private:
	int start;
	int endV;
	int step;
public:
	Range(int s, int e, int st) : start(s), endV(e), step(st) {};

	int getStart() const { return start; };
	int getEnd() const { return endV; };
	int getStep() const { return step; };
	int getSize() const { return (endV - start + step - 1) / step; };

	Iterator begin() {
		return Iterator(*this, 0);
	};

	Iterator end() {
		return Iterator(*this, getSize());
	};
};