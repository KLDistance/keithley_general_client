#define DLL_IMPLEMENT

#include "SCPI_LUTs.h"

DLL_API int get_table_size(IN char *file_path, IN char *machine_type, OUT unsigned int *arr_size)
{
	char *LUT_txt_str = NULL;
	char *specific_txt_str = NULL;
	unsigned int specific_tmp_file_size = 0;
	unsigned int ascii_len = 8;
	unsigned int pattern_index = 0;
	char *tmp_index = NULL;
	char *tmp_start = NULL;
	unsigned int i, j;
	
	if (load_LUT_from_file(file_path, &LUT_txt_str)) return -1;
	pattern_index = rabin_karp_search(LUT_txt_str, machine_type, ascii_len);
	tmp_index = LUT_txt_str + pattern_index + strlen(machine_type) + 1;
	tmp_start = tmp_index;

	for (*arr_size = 0; *tmp_index != '!'; tmp_index++) if (*tmp_index == '#') (*arr_size)++;

	// Write specific command into a new tmp file
	FILE *fp_tmp = NULL;
	fp_tmp = fopen("tmp_command.ini", "w");
	if (!fp_tmp)
	{
#ifdef _WIN32
		MessageBox(NULL, "Unable to create a new command tmp file!", "Error", MB_OK);
#endif
#ifdef __linux
		fprintf(stderr, "Unable to create a new command tmp file!\n");
#endif
		free(LUT_txt_str);
		return -1;
	}
	specific_tmp_file_size = (unsigned int)(tmp_index - tmp_start - 1);
	specific_txt_str = (char*)malloc(specific_tmp_file_size);
	if (!specific_txt_str)
	{
#ifdef _WIN32
		MessageBox(NULL, "Unable to allocate space for file buffer!", "Error", MB_OK);
#endif
#ifdef __linux
		fprintf(stderr, "Unable to allocate space for file buffer!\n");
#endif
		fclose(fp_tmp);
		return -1;
	}
	memset(specific_txt_str, 0, specific_tmp_file_size);
	strncpy(specific_txt_str, tmp_start, specific_tmp_file_size);
	fwrite(specific_txt_str, specific_tmp_file_size, 1, fp_tmp);

	free(specific_txt_str);
	free(LUT_txt_str);
	fclose(fp_tmp);

	return 0;
}

DLL_API int load_table(IN unsigned int arr_length, OUT LStrHandle SCPI_ref_arr, OUT LStrHandle SCPI_str_arr)
{
	char *specific_LUT = NULL;
	char *tmp_forward = NULL;
	char *tmp_backward = NULL;
	unsigned int i;
	
	if (load_LUT_from_file("tmp_command.ini", &specific_LUT))
	{
#ifdef _WIN32
		MessageBox(NULL, "Unable to open SCPI_LUT file! Please ensure the command file is in valid path.", "Error", MB_OK);
#endif
#ifdef __linux
		fprintf(stderr, "Unable to open SCPI_LUT file! Please ensure the command file is in valid path.\n");
#endif
		return -1;
	}
	
	tmp_forward = specific_LUT;
	tmp_backward = specific_LUT;
	for (i = 0; i < arr_length; i++)
	{
		while (*tmp_forward != '#') tmp_forward++;
		DSSetHandleSize(SCPI_ref_arr[i], (unsigned int)(tmp_forward - tmp_backward));
		strncpy(SCPI_ref_arr[i]->str, tmp_backward, (unsigned int)(tmp_forward - tmp_backward));
		tmp_backward = ++tmp_forward;

		while (*tmp_forward != '%') tmp_forward++;
		DSSetHandleSize(SCPI_str_arr[i], (unsigned int)(tmp_forward - tmp_backward));
		strncpy(SCPI_str_arr[i]->str, tmp_backward, (unsigned int)(tmp_forward - tmp_backward));
		tmp_backward = ++tmp_forward;
	}
	free(specific_LUT);

	return 0;
}

// May not be used later
DLL_API int search_pattern()
{

	return 0;
}

int load_LUT_from_file(IN const char *LUT_file_path, OUT char **LUT_txt_str)
{
	FILE *fp_SCPI_LUT = NULL;
	size_t file_size = 0;

	fp_SCPI_LUT = fopen(LUT_file_path, "r");
	if (!fp_SCPI_LUT)
	{
#ifdef _WIN32
		MessageBox(NULL, "Unable to open SCPI_LUT file! Please ensure the command file is in valid path.", "Error", MB_OK);
#endif
#ifdef __linux
		fprintf(stderr, "Unable to open SCPI_LUT file! Please ensure the command file is in valid path.\n");
#endif
		return -1;
	}
	fseek(fp_SCPI_LUT, 0, SEEK_END);
	file_size = ftell(fp_SCPI_LUT);
	fseek(fp_SCPI_LUT, 0, SEEK_SET);

	*LUT_txt_str = (char*)malloc(file_size + 4);
	if (!*LUT_txt_str)
	{
#ifdef _WIN32
		MessageBox(NULL, "Unable to allocate space for file buffer.", "Error", MB_OK);
#endif
#ifdef __linux
		fprintf(stderr, "Unable to allocate space for file buffer.\n");
#endif
		fclose(fp_SCPI_LUT);
		return -1;
	}
	memset(*LUT_txt_str, 0, file_size + 4);
	fread(*LUT_txt_str, file_size, 1, fp_SCPI_LUT);
	fclose(fp_SCPI_LUT);

	return 0;
}

int get_SCPI_from_LUT(char *LUT_txt_str, char corresponding_SCPI[LUT_SCPI_OUT_BUFFER])
{
	
	return 0;
}

int rabin_karp_search(const char *src, const char *pat, int ascii_len)
{
	int src_len = strlen(src);
	int pat_len = strlen(pat);
	int i, j;
	int pat_hash = 0;
	int src_hash = 0;
	int head_char = 1;

	// Obtain the number which is hashed from ascii_len to the power of pat_len - 1
	for (i = 0; i < pat_len; i++) head_char = (head_char * ascii_len) % misen_prime;

	// Prehash
	for (i = 0; i < pat_len; i++)
	{
		pat_hash = (ascii_len * pat_hash + pat[i]) % misen_prime;
		src_hash = (ascii_len * src_hash + src[i]) % misen_prime;
	}

	// Slide the pattern along the source string
	for (i = 0; i <= src_len - pat_len; i++)
	{
		if (src_hash == pat_hash)
		{
			// Check similar hash pattern
			for (j = 0; j < pat_len; j++)
			{
				if (src[i + j] != pat[i + j]) break;
			}
			return i;
		}
		if (i < src_len - pat_len)
		{
			src_hash = (ascii_len * (src_hash - src[i] * head_char) + src[i + pat_len]) % misen_prime;
			if (src_hash < 0) src_hash += misen_prime;
		}
	}

	return 0;
}