/*
 * ShellCommand.cpp
 *
 *  Created on: 6 kwi 2018
 *      Author: mateusz
 */

#include "ShellCommand.h"

ShellCommand::ShellCommand( )
{
}

ShellCommand::~ShellCommand( )
{
}

std::vector< std::string > ShellCommand::DoCommand( const std::string& aCommand )
{
	FILE* file = popen( aCommand.c_str( ), "r" );
	char out[255];
	std::vector< std::string > ret;

	while( fgets( out, 255, file) != NULL )
	{
		ret.push_back( out );
	}
	pclose( file );

	return ret;
}
