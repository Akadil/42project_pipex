#ifndef FT_EXECUTION_H
# define FT_EXECUTION_H

# include "ft_data.h"
# include "libft.h"
# include "ft_error.h"
# include <unistd.h>
# include <errno.h>
# include <stdio.h>
# include <stdlib.h>

char    *ft_find_path_exit(t_data *my_data, char *full_command);

#endif