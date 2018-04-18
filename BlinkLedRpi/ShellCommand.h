#ifndef SHELLCOMMAND_H_
#define SHELLCOMMAND_H_
#include <string>
#include <vector>
#include <cstdio>

class ShellCommand {
public:
	ShellCommand( );
	~ShellCommand( );
	std::vector< std::string > DoCommand( const std::string& aCommand );
};

#endif /* SHELLCOMMAND_H_ */
