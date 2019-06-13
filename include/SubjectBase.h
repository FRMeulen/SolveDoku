//	Project:	SolveDoku.
//	SubjectBase.h	--	Interface for the BaseSubject class.
//	Revisions:
//	2019-06-06	--	F.R. van der Meulen	--	Created.

//	Pragma.
#pragma once

//	Include files.
#include "ObserverBase.h"
#include <vector>

//	Class.
class BaseSubject {
public:
	//	Constructors & Destructors.
	BaseSubject();
	~BaseSubject();

	//	Fields.
	std::vector<BaseObserver*> observers;

	//	Methods.
	void notifyAll();
	void attach(BaseObserver*);
	void detach(BaseObserver*);
};
