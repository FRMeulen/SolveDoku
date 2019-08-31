//	Project:	SolveDoku.
//	ObserverBase.h	--	Interface for the BaseObserver class.
//	Revisions:
//	2019-06-06	--	F.R. van der Meulen	--	Created.

//	Pragma.
#pragma once

//	Class dependencies.
class BaseSubject;

//	Class.
class BaseObserver {
public:
	BaseSubject *linkedSubject;
	BaseObserver(BaseSubject*);
	virtual ~BaseObserver();
	virtual void update() = 0;
};

//	This class is abstract!
