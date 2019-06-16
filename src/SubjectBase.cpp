//	Project:	SolveDoku.
//	SubjectBase.cpp	--	Implementation of the BaseSubject class.
//	Revisions:
//	2019-06-07	--	F.R. van der Meulen	--	Created.

//	Include files.
#include "SubjectBase.h"
#include <iostream>

//	Constructor.
BaseSubject::BaseSubject() {

}

//	Destructor.
BaseSubject::~BaseSubject() {

}

//	notifyAll	--	Notifies all attached observers of update.
//	Parameters:	none.
//	Returns:	void.
void BaseSubject::notifyAll() {
	std::cout << std::endl;
	std::cout << "--------------------" << std::endl;
	std::cout << "--Iteration start!--" << std::endl;
	std::cout << "--------------------" << std::endl;
	std::cout << std::endl;


	for (unsigned int i = 0; i < observers.size(); i++) {
		observers[i]->update();
	}
}

//	attach	--	Attaches an observer.
//	Parameters:
//		obs	--	Observer pointer.
//	Returns:	void.
void BaseSubject::attach(BaseObserver *obs) {
	observers.push_back(obs);
}

//	detach	--	Detaches an observer.
//	Parameters:
//		obs	--	Observer pointer.
//	Returns:	void.
void BaseSubject::detach(BaseObserver *obs) {
	for (unsigned int i = 0; i < observers.size(); i++) {
		if (observers[i] == obs) {
			obs->linkedSubject = 0;
			observers.erase(observers.begin() + i);
		}
	}
}
