/*
 * RpiGPIO.h
 *
 *  Created on: 9 kwi 2018
 *      Author: mateusz
 */

#ifndef RPIGPIO_H_
#define RPIGPIO_H_

namespace rpi {

typedef enum
{
	Gpio_Pin_2 = 0x02,
	Gpio_Pin_3 = 0x03,
	Gpio_Pin_4 = 0x04,
	Gpio_Pin_5 = 0x05,
	Gpio_Pin_6 = 0x06,
	Gpio_Pin_7 = 0x07,
	Gpio_Pin_8 = 0x08,
	Gpio_Pin_9 = 0x09,
	Gpio_Pin_10 = 0x0A,
	Gpio_Pin_11 = 0x0B,
	Gpio_Pin_12 = 0x0C,
	Gpio_Pin_13 = 0x0D,
	Gpio_Pin_16 = 0x10,
	Gpio_Pin_17 = 0x11,
	Gpio_Pin_18 = 0x12,
	Gpio_Pin_19 = 0x13,
	Gpio_Pin_20 = 0x14,
	Gpio_Pin_21 = 0x15,
	Gpio_Pin_Invalid = 0xFF
} ERpiGpioPin;

typedef enum
{
	Gpio_Dir_In = 0x00,
	Gpio_Dir_Out = 0x01,
	Gpio_Dir_NotSet = 0xFF
} ERpioGpioDir;

typedef enum
{
	Gpio_State_Reset = 0x00,
	Gpio_State_Set = 0x01,
	Gpio_State_NotSet = 0xFF
} ERpioGpioState;

class RpiGPIO
{
	ERpiGpioPin iPin;

	ERpioGpioDir iDir;

	bool iIsInitialized;

public:

	RpiGPIO( const ERpiGpioPin aPin, const ERpioGpioDir aDir = ERpioGpioDir::Gpio_Dir_In  );

	~RpiGPIO( );

	ERpioGpioDir GetPinDirection( );

	ERpioGpioState GetPinState( );

	ERpioGpioDir SetPinDirection( );

private:

	bool IsValidGPIOPin( const ERpiGpioPin aPin );

	bool IsValidGPIODir( const ERpioGpioDir aPin );

	bool IsInitialized( const ERpiGpioPin aPin );

	ERpioGpioDir GetSystemPinDirection( );

	bool SetSystemPinDirection( const ERpioGpioDir aDir );
};

} /* namespace rpi */

#endif /* RPIGPIO_H_ */
