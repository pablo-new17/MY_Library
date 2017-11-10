#ifndef SINGLETON_H
#define SINGLETON_H

#include <QtGlobal>
#include <QScopedPointer>

#include "call_once.h"

template <class T>
class Singleton
{
	Q_DISABLE_COPY(Singleton)

private:
										Singleton();
										~Singleton();

	static QBasicAtomicPointer<T* (void)>	create;
	//static QBasicAtomicPointer<void>	create;
	static QBasicAtomicInt				flag;
	static QBasicAtomicPointer<void>	tptr;
	bool								inited;

	typedef T*							(*CreateInstanceFunction)();
	static void							init();

public:
	static T*							instance(CreateInstanceFunction create);

};
#endif // SINGLETON_H
