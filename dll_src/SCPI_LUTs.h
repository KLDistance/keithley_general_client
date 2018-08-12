#ifndef __SCPI_LUTS_H__
#define __SCPI_LUTS_H__

#include <stdio.h>
#include <string.h>
#include <time.h>

#ifdef __linux
#include <stdlib.h>
#endif

#ifdef _WIN32
#include <Windows.h>
#endif

#define IN 
#define OUT 

// Set buffer for specific SCPI out
#define LUT_SCPI_OUT_BUFFER 32

// Machine type buffer size
#define MACHINE_TYPE_BUFFER 32

#ifdef DLL_IMPLEMENT
#define DLL_API extern __declspec(dllexport)
#else
#define DLL_API extern __declspec(dllimport)
#endif

// Functions and global variables

// Misen prime
const int misen_prime = 1 << 17; // prime 131072

// Get the table size so that labview can pass into an array
DLL_API int get_table_size(IN char *file_path, IN char *machine_type, OUT unsigned int *arr_size);
// Load the table from file and truncate into two arrays: reference array and command array
DLL_API int load_table(IN char *file_path, IN unsigned int str_index, IN unsigned int arr_length, OUT char *SCPI_ref_arr, OUT char *SCPI_str_arr);
// Search the command
DLL_API int search_pattern();

// Loading procedure used in get_table_size and load_table functions
int load_LUT_from_file(IN const char *LUT_file_path, OUT char **LUT_txt_str);
// Search corresponding command from array used in search_pattern procedure
int get_SCPI_from_LUT(char *LUT_txt_str, char corresponding_SCPI[LUT_SCPI_OUT_BUFFER]);
// Used in truncate and search procedure
int rabin_karp_search(const char *src, const char *pat, int ascii_len);

#endif

/*
Set the file format as follows:

!NI-VISA
$VISA=6517B
SENS_FUNC_VOLT#:SENS:FUNC 'VOLT'%
SENS_FUNC_CURR#:SENS:FUNC 'CURR'%
SENS_FUNC_CURR#:SENS:FUNC 'RES'%
SENS_CURR_RANG_AUTO_1#:SENS:CURR:RANG:AUTO 1%
SENS_CURR_RANG_AUTO_0#:SENS:CURR:RANG:AUTO 0%
SENS_CURR_RANG_?#:SENS:CURR:RANG <?>%
SENS_FILT_0#:SENS:CURR:AVER:STAT 0%
SENS_ZCH_0#:SYST:ZCH 0%
SENS_ZCH_1#:SYST:ZCH 1%
SENS_CURR_NPLC_0.01#:SENS:CURR:NPLC 0.01%
SENS_CURR_NPLC_0.1#:SENS:CURR:NPLC 0.1%
SOUR_VOLT_0#:SOUR:VOLT 0%
SOUR_VOLT_?#:SOUR:VOLT <?>%
SOUR_OUTP_0#:OUTP 0%
SOUR_OUTP_1#:OUTP 1%
TRAC_FEED_CONT_NEXT#:TRAC:FEED:CONT NEXT%

!
*/