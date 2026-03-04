//#pragma once
//#include "FactoryMethod.cpp"
//#include "Adapter.cpp"
//#include "Iterator.cpp"
//
//using namespace std;
//
//int main() {
//	// Factory method
//	//TechCourseFactory* course = new TechCourseFactory();
//	//course->handEssential();
//
//	//cout << endl;
//
//	//FinCourseFactory* course1 = new FinCourseFactory();
//	//course1->handEssential();
//
//	// Adapter
//	// Target* target = new Target; // Cant be used because Target is an Interface/Abstract class
//	//Service* service_ptr = new Service;
//	//cout << "Current voltage of Service: " << service_ptr->myElec() << endl;
//	//cout << "I can't charge with this shit" << endl;
//	//Target* target_ptr = new Adapter(service_ptr);
//	//target_ptr->chargePhone();
//
//	//delete service_ptr;
//	//delete target_ptr;
//
//	// Iterator
//	IterableCollection* concol = new ConcreteCollection;
//	Iterator* concol_iter = concol->createIterator();
//	concol_iter->getNext();
//	concol_iter->hasMore();
//	concol_iter->getNext();
//	concol_iter->getNext();
//	concol_iter->hasMore();
//	concol_iter->getNext();
//
//	delete concol;
//	delete concol_iter;
//
//	return 0;
//}