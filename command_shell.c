#include "secondheader.h"

/**
 * cd_shell - changes current directory
 *
 * @datash: data relevant
 * Return: 1 on success
 */
int cd_shell(data_shell *datash)
{
	char *str_dir;
	int ishome_str, ishome2_ptr, is_dash;

	str_dir = datash->args[1];

	if (str_dir != NULL)
	{
		ishome_str = _stringcmp("$HOME", str_dir);
		ishome2_ptr = _stringcmp("~", str_dir);
		is_dash = _stringcmp("--", str_dir);
	}

	if (str_dir == NULL || !ishome_str || !ishome2_ptr || !is_dash)
	{
		cd_to_origin(datash);
		return (1);
	}

	if (_stringcmp("-", str_dir) == 0)
	{
		cd_before(datash);
		return (1);
	}

	if (_stringcmp(".", str_dir) == 0 || _stringcmp("..", str_dir) == 0)
	{
		cd_dt(datash);
		return (1);
	}

	cd_to_this(datash);

	return (1);
}
