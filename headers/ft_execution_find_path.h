#ifndef FT_EXECUTION_FIND_PATH_H
# define FT_EXECUTION_FIND_PATH_H

# include "ft_data.h"
# include "libft.h"
# include <stdlib.h>
# include <errno.h>
# include <string.h>
# include <unistd.h>

int	ft_get_size_of_word(char *str);
char	*ft_extract_command(char *_arg);
static char	*ft_construct_command(char *arg, char **all_paths);
char	**ft_get_potential_paths(char **_env);

#endif