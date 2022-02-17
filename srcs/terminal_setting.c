#include "term3d.h"

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

char	get_control_char(void)
{
	char	ret;
	int		old_flag;

	ret = 0;
	old_flag = fcntl(STDIN_FILENO, F_GETFL);
	fcntl(STDIN_FILENO, F_SETFL, old_flag | O_NONBLOCK);
	set_terminal_setting();
	ret = getchar();
	reset_terminal_setting();
	fcntl(STDIN_FILENO, F_SETFL, old_flag);
	return (ret);
}
