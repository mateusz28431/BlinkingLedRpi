#include <iostream>
#include "BlinkingThread.h"
#include "RpiGPIO.h"

BlinkingThread::BlinkingThread( ) : CommonThread( "BlinkingThread" )
{
}

BlinkingThread::~BlinkingThread( )
{
	JoinThread( );
}

void BlinkingThread::ThreadMain( ) const
{
	using std::cout;
	using std::endl;
	rpi::RpiGPIO gpio(rpi::ERpiGpioPin::Gpio_Pin_2 );

	cout << "Blinking thread started" << endl;
}
