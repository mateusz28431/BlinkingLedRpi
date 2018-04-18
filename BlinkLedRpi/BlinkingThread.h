#ifndef BLINKINGTHREAD_H_
#define BLINKINGTHREAD_H_

#include "CommonThread.h"

class BlinkingThread: public CommonThread
{
	public:

	BlinkingThread( );

	~BlinkingThread( );

	private:

	void ThreadMain( ) const;
};

#endif /* BLINKINGTHREAD_H_ */
