#include "../inc/libmx.h"

static void empty_error(const char *file) {
    mx_printerr("error: file ");
    mx_printerr(file);
    mx_printerr(" is empty\n");
    exit(0);
}

static void existence_error(const char *file) {
    mx_printerr("error: file ");
    mx_printerr(file);
    mx_printerr(" does not exist\n");
    exit(0);
}

char	*mx_file_to_str(const char *file) {
	int	fd = open(file, O_RDONLY);
	int	len = 0;
	char *str = NULL;
	char c = 0;

	if (fd < 0)
        existence_error(file);
	while (read(fd, &c, 1))
		len++;
	close(fd);
	if (len <= 0)
        empty_error(file);
    fd = open(file, O_RDONLY);
	str = mx_strnew(len);
	for (int i = 0; read(fd, &c, 1); i++)
		str[i] = c;
	close(fd);
	return str;
}
