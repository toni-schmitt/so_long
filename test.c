#include "so_long.h"
#include <unistd.h>
#define _XOPEN_SOURCE 700
#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>
int main(void)
{
	DIR *dp;
	struct dirent *ep;
	dp = opendir("./maps");

	if (dp != NULL)
	{
		int i =0;
		while (ep = readdir(dp))
		{
			if (i == 0 || i == 1)
			{
				i++;
				continue;
			}
			char *cmd = ft_strjoin("./so_long ./maps/", ep->d_name);
			ft_printf("%s\n", cmd);
			system(cmd);
			i++;
		}

		(void)closedir(dp);
	}
	else
		perror("Couldn't open the directory");

	return 0;
}