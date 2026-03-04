#include <iostream>
#include <vector>

using namespace std;

// This mini project is for me to practice Factory Method and Recursion
// The Burger Shop

// Factory Method:
class Ingredient {
public:
	virtual ~Ingredient() {};
	virtual int price() = 0;	// Pure abstract class
};

class Patty : public Ingredient {
public:
	int price() override { return 5; }
};

class Lettuce : public Ingredient {
public:
	int price() override { return 1; }
};

class Bun : public Ingredient {
public:
	int price() override { return 2; }
};

// The CREATOR 
class IngredientFacto {
public:
	virtual ~IngredientFacto() {};
	virtual Ingredient* addIngredient() = 0;
};

class PattyFacto : public IngredientFacto{
public:
	Ingredient* addIngredient() override {
		return new Patty;
	}
};

class LettuceFacto : public IngredientFacto {
public:
	Ingredient* addIngredient() override {
		return new Lettuce;
	}
};

class BunFacto : public IngredientFacto {
public:
	Ingredient* addIngredient() override {
		return new Bun;
	}
};

class Burger {
private:
	vector<Ingredient*> myBurger;
public:
	~Burger() {
		// Clean up the memory we were given
		for (Ingredient* ingre : myBurger) {
			delete ingre;
		}
		cout << "Burger memory cleaned up!" << endl;
	}

	void add(Ingredient* ingre) {
		myBurger.push_back(ingre);
	}

	int recurPrice(int index) {
		if (index == myBurger.size()) {
			return 0;
		}

		return myBurger[index]->price() + recurPrice(index + 1);
	}
};

int main() {
	Burger bugu;
	PattyFacto pattyf;
	LettuceFacto lettucef;
	BunFacto bunf;

	Ingredient* patty = pattyf.addIngredient();
	Ingredient* lettuce = lettucef.addIngredient();
	Ingredient* bun = bunf.addIngredient();

	bugu.add(patty);
	bugu.add(lettuce);
	bugu.add(bun);

	int price = bugu.recurPrice(0);

	cout << price << endl;

	//delete patty;
	//delete lettuce;
	//delete bun;
	// All of the above already be done since the Burger instance deleted when main() ends.

	return 0;
}