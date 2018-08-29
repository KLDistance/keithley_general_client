#include "command_truncate.h"

int parameter_truncate(char *input_str, double **parameter_arr_handle)
{
	// Preallocate sufficient space for parameter, default for 1024 doubles
	double *parameter_space = (double*)malloc(sizeof(double) * 1024);
	if (!parameter_space)
	{
#ifdef _WIN32
		MessageBox(NULL, "Unable to allocate space for SPCI command parameters!", "Error", MB_OK);
#endif
#ifdef __linux
		fprintf(stderr, "Unable to allocate space for SPCI command parameters!\n");
#endif
		return -1;
	}
	unsigned int parameter_num = 0;
	unsigned int i;
	char *tmp_str_ptr = input_str;
	char tmp_buf[32] = { 0 };

	while (*tmp_str_ptr)
	{
		if (*tmp_str_ptr == ' ' && *(tmp_str_ptr + 1))
		{
			for (i = 1; *(tmp_str_ptr + i) != ' ' && *(tmp_str_ptr + i) != '\0'; i++)
			{
				tmp_buf[i] = *(tmp_str_ptr + i);
			}
			parameter_space[parameter_num++] = atof(tmp_buf);
			memset(tmp_buf, 0, 32);
		}
	}

	// Resize the input parameter array handle
	DSSetHandleSize(parameter_arr_handle, parameter_num * sizeof(double));

	// Copy the data from pre-allocated buffer into handle array
	for (i = 0; i < parameter_num; i++)
	{
		(*parameter_arr_handle)[i] = parameter_space[i];
	}
	free(parameter_space);

	return 0;
}