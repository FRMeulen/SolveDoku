//	Project:	SolveDoku.
//	ObserverBase.cpp	--	Implementation of the Observer class.
//	Revisions:
//	2019-06-06	--	F.R. van der Meulen	--	Created.

//	Include files.
#include "ObserverBase.h"
#include "SubjectBase.h"
#include <iostream>

//	Constructor.
BaseObserver::BaseObserver(BaseSubject *subject) {
	linkedSubject = subject;
	linkedSubject->attach(this);
}

//	Destructor.
BaseObserver::~BaseObserver() {
	//	Detach from attached subject.
	if (linkedSubject) {
		linkedSubject->detach(this);
	}
}

//	This class is abstract!
