#include "CommonThread.h"

void Test( )
{

}

CommonThread::~CommonThread()
{
}

CommonThread::CommonThread( const std::string& aThreadName ) : iThreadName( aThreadName )
{
}

void CommonThread::StartThread( )
{
	iThread = std::thread( Start, this );
}

void CommonThread::JoinThread( )
{
	iThread.join( );
}

void CommonThread::Start( const CommonThread* aThread )
{
	aThread->ThreadMain( );
}
