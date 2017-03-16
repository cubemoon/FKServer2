//////////////////////////////////////////////////////////////////////
//
// Thread.h
//
//



#ifndef __THREAD_H__
#define __THREAD_H__


//////////////////////////////////////////////////
// include files
//////////////////////////////////////////////////
#include "Type.h"




//当定义此宏时，所有线程将只执行一次后就推出。
//#define _EXEONECE 10

//////////////////////////////////////////////////////////////////////
//
// class Thread
//
// POSIX Thread Class
//
//////////////////////////////////////////////////////////////////////

class Thread 
{

//////////////////////////////////////////////////
// constants
//////////////////////////////////////////////////
public :
	
	enum ThreadStatus 
	{
		READY ,		// 当前线程处于准备状态
		RUNNING ,	// 处于运行状态
		EXITING ,	// 线程正在退出
		EXIT		// 已经退出 
	};
	

//////////////////////////////////////////////////
// constructor and destructor
//////////////////////////////////////////////////

public :

	// constructor
	Thread ( ) ;

	// destructor
	virtual ~Thread () ;


//////////////////////////////////////////////////
// public methods
//////////////////////////////////////////////////

public :

	VOID start () ;
	
	virtual VOID stop () ;

	VOID exit ( VOID * retval = NULL ) ;

	virtual VOID run () ;


//////////////////////////////////////////////////
// 
//////////////////////////////////////////////////
public :
	// get thread identifier
	TID getTID () { return m_TID; }
	
	// get/set thread's status
	ThreadStatus getStatus () { return m_Status; }
	VOID setStatus ( ThreadStatus status ) { m_Status = status; }
	

//////////////////////////////////////////////////
// data members
//////////////////////////////////////////////////

private :

	// thread identifier variable
	TID m_TID;
	
	// thread status
	ThreadStatus m_Status;

#if defined(__WINDOWS__)
	HANDLE m_hThread ;
#endif

};

extern UINT g_QuitThreadCount ;

#if defined(__LINUX__)
VOID * MyThreadProcess ( VOID * derivedThread ) ;
#elif defined(__WINDOWS__)
DWORD WINAPI MyThreadProcess(  VOID* derivedThread ) ;
#endif

#endif
