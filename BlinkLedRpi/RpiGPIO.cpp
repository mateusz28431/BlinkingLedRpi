/*
 * RpiGPIO.cpp
 *
 *  Created on: 9 kwi 2018
 *      Author: mateusz
 */

#include "RpiGPIO.h"
#include "ShellCommand.h"
#include <iostream>
#include <algorithm>
#define RPI_LOG( a ) (std::cout<< "RPIO_GPIO: " << ( a )<< std::endl)
namespace rpi {

const std::string GPIO_PATH = "/sys/class/gpio";

RpiGPIO::RpiGPIO( const ERpiGpioPin aPin, const ERpioGpioDir aDir )
{
	iIsInitialized = IsInitialized( aPin );

	if( !IsValidGPIOPin( aPin ) )
	{
		RPI_LOG( "Invalid gpio" );
		iPin = Gpio_Pin_Invalid;
	}
	else
		iPin = aPin;


	iDir = aDir;

}

RpiGPIO::~RpiGPIO( )
{
}


bool RpiGPIO::IsValidGPIOPin( const ERpiGpioPin aPin )
{
	switch( aPin )
	{
		case Gpio_Pin_2:
		case Gpio_Pin_3:
		case Gpio_Pin_4:
		case Gpio_Pin_5:
		case Gpio_Pin_6:
		case Gpio_Pin_7:
		case Gpio_Pin_8:
		case Gpio_Pin_9:
		case Gpio_Pin_10:
		case Gpio_Pin_11:
		case Gpio_Pin_12:
		case Gpio_Pin_13:
		case Gpio_Pin_16:
		case Gpio_Pin_17:
		case Gpio_Pin_18:
		case Gpio_Pin_19:
		case Gpio_Pin_20:
		case Gpio_Pin_21:
			return true;
		default:
			return false;

	}
}

bool RpiGPIO::IsValidGPIODir( const ERpioGpioDir aDir )
{
	switch( aDir )
	{
		case Gpio_Dir_In:
		case Gpio_Dir_Out:
			return true;
		default:
			return false;
	}
}

bool RpiGPIO::IsInitialized( const ERpiGpioPin aPin )
{
	ShellCommand cmd;
	std::string gpioPin = "gpio" + std::to_string( aPin );
	std::vector< std::string > out = cmd.DoCommand( "ls " + GPIO_PATH + " | grep " + gpioPin );

	if( !out.size( ) )
		return false;
	out[0].erase( std::remove(out[0].begin(), out[0].end(), '\n'), out[0].end() );

	if( out[0].compare( gpioPin ) == 0 )
		return true;
	else
		return false;

}

ERpioGpioDir RpiGPIO::GetSystemPinDirection( )
{
	ShellCommand cmd;
	std::vector< std::string > out = cmd.DoCommand( "cat " + GPIO_PATH + "/gpio" + std::to_string( iPin ) + "/direction" );

	if( out.size( ) == 0 )
		return ERpioGpioDir::Gpio_Dir_NotSet;

	if( out[0].compare( "in\n" ) == 0 )
		return ERpioGpioDir::Gpio_Dir_In;
	else if( out[0].compare( "out\n" ) == 0 )
		return ERpioGpioDir::Gpio_Dir_Out;
	else
		return ERpioGpioDir::Gpio_Dir_NotSet;
}

bool RpiGPIO::SetSystemPinDirection( const ERpioGpioDir aDir )
{
	ShellCommand cmd;
	std::vector< std::string > out = cmd.DoCommand( "cat " + GPIO_PATH + "/gpio" + std::to_string( iPin ) + "/direction" );

	if( out.size( ) == 0 )
		return ERpioGpioDir::Gpio_Dir_NotSet;

	if( out[0].compare( "in\n" ) == 0 )
		return ERpioGpioDir::Gpio_Dir_In;
	else if( out[0].compare( "out\n" ) == 0 )
		return ERpioGpioDir::Gpio_Dir_Out;
	else
		return ERpioGpioDir::Gpio_Dir_NotSet;
}

ERpioGpioDir RpiGPIO::GetPinDirection( )
{
	return ERpioGpioDir::Gpio_Dir_NotSet;
}

ERpioGpioDir RpiGPIO::SetPinDirection( )
{

}

} /* namespace rpi */
