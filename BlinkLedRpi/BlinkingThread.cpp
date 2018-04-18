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
	using namespace rpi;

	cout << "Blinking thread started" << endl;

	RpiGPIO gpio3(ERpiGpioPin::Gpio_Pin_3, ERpioGpioDir::Gpio_Dir_Out );

	if( !gpio3.IsInitialized( ))
	{
		std::cout << "Cannot initialize gpio\n";
		return;
	}

	while( true )
	{
		gpio3.SetPinState( ERpioGpioState::Gpio_State_Set );
		std::this_thread::sleep_for( std::chrono::seconds( 1 ) );
		gpio3.SetPinState( ERpioGpioState::Gpio_State_Reset );
		std::this_thread::sleep_for( std::chrono::seconds( 1 ) );
	}
}
