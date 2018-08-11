#define DLL_IMPLEMENT

#include "csv_operator.h"

int writer_entry(
	double *x_data_arr, 
	double *y_data_arr, 
	unsigned int row_num, 
	unsigned int col_num, 
	char *path, 
	char *info_sheet)
{
	// Allocate space for file IO buffer
	unsigned int file_buffer_size = BUF_LEN * row_num * col_num * 2 + RES_LEN;
	char *file_buffer = (char*)malloc(file_buffer_size);
	char *tmp_buffer = file_buffer;
	if (!file_buffer)
	{
#ifdef _WIN32
		MessageBox(NULL, "Allocate file buffer memory error! Data size exceeds upper limit.", "Error", MB_OK);
#endif
#ifdef __linux
		fprintf(stderr, "Unable to allocate space for file buffer!\n");
#endif
		return -1;
	}
	memset(file_buffer, 0, file_buffer_size);

	// Start write csv file
	FILE *fp_csv = NULL;
	unsigned int i, j;
	unsigned int tmp_product = 0;
	unsigned int iter_length_indicator = 0;
	unsigned int string_length_indicator = 0;

	fp_csv = fopen(path, "w");
	if (fp_csv)
	{
#ifdef _WIN32
		MessageBox(NULL, "Could not create a new csv file.", "Error", MB_OK);
#endif
#ifdef __linux
		fprintf(stderr, "Could not create a new csv file.\n");
#endif
	}
	
	// csv header
	char csv_header[3] = { 0xEF, 0xBB, 0xBF };

	// Write data into buffer

	// Write blank rows
	sprintf(tmp_buffer, "\n\n\n,");
	iter_length_indicator = strlen(tmp_buffer);
	string_length_indicator += iter_length_indicator;
	tmp_buffer += iter_length_indicator;

	// Write channels and physical quantities
	for (i = 0; i < col_num; i++)
	{
		sprintf(tmp_buffer, "Channel%u,,,", i + 1);
		iter_length_indicator = strlen(tmp_buffer);
		string_length_indicator += iter_length_indicator;
		tmp_buffer += iter_length_indicator;
	}
	sprintf(tmp_buffer, "\n,");
	iter_length_indicator = strlen(tmp_buffer);
	string_length_indicator += iter_length_indicator;
	tmp_buffer += iter_length_indicator;
	for (i = 0; i < col_num; i++)
	{
		sprintf(tmp_buffer, "V,I,,");
		iter_length_indicator = strlen(tmp_buffer);
		string_length_indicator += iter_length_indicator;
		tmp_buffer += iter_length_indicator;
	}
	sprintf(tmp_buffer, "\n,");
	iter_length_indicator = strlen(tmp_buffer);
	string_length_indicator += iter_length_indicator;
	tmp_buffer += iter_length_indicator;

	// Write data
	for (i = 0; i < row_num; i++)
	{
		tmp_product = i * col_num;
		for (j = 0; j < col_num; j++)
		{
			sprintf(tmp_buffer, "%.8f,%.8f,,", x_data_arr[tmp_product + j], y_data_arr[tmp_product + j]);
			iter_length_indicator = strlen(tmp_buffer);
			string_length_indicator += iter_length_indicator;
			tmp_buffer += iter_length_indicator;
		}
		sprintf(tmp_buffer, "\n,");
		iter_length_indicator = strlen(tmp_buffer);
		string_length_indicator += iter_length_indicator;
		tmp_buffer += iter_length_indicator;
	}

	// Push the contents into file
	fwrite(csv_header, 3, 1, fp_csv);
	fseek(fp_csv, 3, SEEK_SET);
	fwrite(info_sheet, strlen(info_sheet), 1, fp_csv);
	fseek(fp_csv, strlen(info_sheet) + 3, SEEK_SET);
	fwrite(file_buffer, string_length_indicator, 1, fp_csv);
	fseek(fp_csv, 0, SEEK_SET);

	// Free the memory and close file
	fclose(fp_csv);
	free(file_buffer);

	return 0;
}