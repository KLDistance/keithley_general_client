#ifndef __CSV_OPERATOR_H__
#define __CSV_OPERATOR_H__

#ifdef _WIN32

// Win define
#include <Windows.h>

#ifdef DLL_IMPLEMENT
#define DLL_API extern __declspec(dllexport)
#else
#define DLL_API extern __declspec(dllimport)
#endif

#endif

// Linux define
#ifdef __linux

#include <stdlib.h>
#include <unistd.h>

#define DLL_IMPLEMENT
#define DLL_API

#endif

#include <string.h>
#include <time.h>
#include <stdio.h>

#define CSV_PATH_LEN 256
#define RES_LEN 8192
#define BUF_LEN 32

typedef struct
{
	char *csv_path;
	unsigned int row_num;
	unsigned int col_num;
	double *x_data_arr;
	double *y_data_arr;
} CSV_STRUCT;

DLL_API int writer_entry(double *x_data_arr, double *y_data_arr, unsigned int row_num, unsigned int col_num, char *path, char *info_sheet);

#endif