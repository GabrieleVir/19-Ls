#include "libft.h"
#include <sys/stat.h>

void	fill_file_checker(int file_checker[7], char ***str_checker)
{
	file_checker[0] = S_IFBLK;
	(*str_checker)[0] = ft_strdup("block device\n");
	file_checker[1] = S_IFCHR;
	(*str_checker)[1] = ft_strdup("character device\n");
	file_checker[2] = S_IFDIR;
	(*str_checker)[2] = ft_strdup("directory\n");
	file_checker[3] = S_IFIFO;
	(*str_checker)[3] = ft_strdup("FIFO/pipe\n");
	file_checker[4] = S_IFLNK;
	(*str_checker)[4] = ft_strdup("symlink\n");
	file_checker[5] = S_IFREG;
	(*str_checker)[5] = ft_strdup("regular file\n");
	file_checker[6] = S_IFSOCK;
	(*str_checker)[6] = ft_strdup("socket\n");
	(*str_checker)[7] = NULL;
}

int		main(int ac, char **av)
{
	struct stat		stat_file;
	int				file_checker[7];
	char			**str_checker;
	int				i = -1;

	str_checker = (char **)malloc(sizeof(char*) * 8);
	fill_file_checker(file_checker, &str_checker);
	if (ac != 2)
	{
		ft_putstr("Error");
		return (1);
	}
	if (stat(av[1], &stat_file) == -1)
	{
		ft_putstr("Error stat");
		return (1);
	}
	ft_putstr("Nom: ");
	ft_putstr(av[1]);
	ft_putstr("\n");
	ft_putstr("Type: ");
	int checker = stat_file.st_mode & S_IFMT;
	while (++i < 7)
	{
		if (checker == file_checker[i])
			ft_putstr(str_checker[i]);
	}
	ft_putnbr(stat_file.st_mode);
	ft_putstr("\n");
	return (0);
}