#include <dirent.h>
#include <stdio.h>
#include "libft.h"


int     main(int ac, char **av)
{
	DIR				*dirp;
	struct dirent	*dp;

	if (ac != 2)
	{
		ft_putstr("Error");
		return (1);
	}
	dirp = opendir(av[1]);
	if (dirp == NULL)
		return (1);
	while ((dp = readdir(dirp)) != NULL)
	{
		ft_putstr(dp->d_name);
		ft_putstr("\n");
	}
	(void)closedir(dirp);
	return (0);
}