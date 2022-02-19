/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal_setting.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynakamot  <ynakamot@student.42tokyo.j      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 19:28:03 by ynakamot          #+#    #+#             */
/*   Updated: 2022/02/18 19:28:03 by ynakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "term3d.h"

void	set_terminal_setting(void)
{
	struct termios	termios_p;
	int				ret;

	ret = tcgetattr(STDIN_FILENO, &termios_p);
	if (ret == -1)
		error_exit("ERROR: Failed to read terminal setting.");
	termios_p.c_lflag &= ~(ICANON | ECHO);
	ret = tcsetattr(STDIN_FILENO, TCSANOW, &termios_p);
	if (ret == -1)
		error_exit("ERROR: Failed to set non-canonical mode.");
	return ;
}

void	reset_terminal_setting(void)
{
	struct termios	termios_p;
	int				ret;

	ret = tcgetattr(STDIN_FILENO, &termios_p);
	if (ret == -1)
		error_exit("ERROR: Failed to read terminal setting.");
	termios_p.c_lflag |= ICANON | ECHO;
	ret = tcsetattr(STDIN_FILENO, TCSANOW, &termios_p);
	if (ret == -1)
		error_exit("ERROR: Failed to set canonical mode.");
	return ;
}

char	get_control_char(void)
{
	char	buf[10];
	int		old_flag;

	old_flag = fcntl(STDIN_FILENO, F_GETFL);
	fcntl(STDIN_FILENO, F_SETFL, old_flag | O_NONBLOCK);
	read(STDIN_FILENO, buf, 10);
	fcntl(STDIN_FILENO, F_SETFL, old_flag);
	return (buf[0]);
}
