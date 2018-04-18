#ifndef COMMONTHREAD_H_
#define COMMONTHREAD_H_
#include <string>
#include <thread>
class CommonThread {

	std::string iThreadName;

	std::thread iThread;

private:

	void static Start( const CommonThread* aThread );

	virtual void ThreadMain( ) const = 0;

public:

	virtual ~CommonThread( );

	void StartThread( );

protected:

	CommonThread( const std::string& aThreadName );

	void JoinThread( );
};

#endif /* COMMONTHREAD_H_ */
