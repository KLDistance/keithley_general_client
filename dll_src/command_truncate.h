#ifndef __COMMAND_TRUNCATE_H__
#define __COMMAND_TRUNCATE_H__

#include <stdio.h>
#include <string.h>

#include "../../Dependencies/extcode.h"

#ifdef _WIN32
#include <Windows.h>
#pragma comment(lib, "../../Dependencies/labview.lib")
#endif

#ifdef __linux
#include <stdlib.h>
#endif

#ifdef DLL_IMPLEMENT 
#define DLL_API extern __declspec(dllexport)
#else
#define DLL_API extern __declspec(dllimport)
#endif

DLL_API int parameter_truncate(char *input_str, double **parameter_arr_handle);

#endif

