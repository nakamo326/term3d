#include "term3d.h"

#include <termios.h>


bool	set_terminal_setting(void)
{
	struct termios	termios_p;
	int				ret;

	ret = tcgetattr(STDIN_FILENO, &termios_p);
	if (ret == -1)
	{
		return (false);
	}
	termios_p.c_lflag &= ~(ICANON | ECHO);
	ret = tcsetattr(STDIN_FILENO, TCSANOW, &termios_p);
	if (ret == -1)
	{
		return (false);
	}
	return (true);
}

bool	reset_terminal_setting(void)
{
	struct termios	termios_p;
	int				ret;

	ret = tcgetattr(STDIN_FILENO, &termios_p);
	if (ret == -1)
	{
		return (false);
	}
	termios_p.c_lflag |= ICANON | ECHO;
	ret = tcsetattr(STDIN_FILENO, TCSANOW, &termios_p);
	if (ret == -1)
	{
		return (false);
	}
	return (true);
}
