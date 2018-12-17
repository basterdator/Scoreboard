// ==============================================
//  C o m p u t e r      A r c h i t e c t u r e
//			    Winter 2018-2019
//			  TEL-AVIV UNIVERSITY
//    S c o r e b o a r d      P r o j e c t
// * * * * * * * * * * * * * * * * * * * * * * * 
//  Daniel Lawton                     ?????????    
//  Anton Chaplianka                  310224209
// ==============================================

#pragma once
#define _CRT_SECURE_NO_WARNINGS 1 
#define _WINSOCK_DEPRECATED_NO_WARNINGS 1 

#define BUFFER_SIZE 20
#define MEM_SIZE 4096
#define LINE_LEN 10

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Structs.h"

int ReadConfiguration(char *filename);
int ReadMemoryIntoMemArray(char *filename, int *mem);

int main(int argc, char *argv[])
{
	int mem[MEM_SIZE];
	if (argv[1] != NULL) 
	{
		return ReadConfiguration(argv[1]);
	}
	else
	{
		printf("Error! no argument provided!\n");
		return -1;
	}
}


// Input argument:  char *filename: A string with the name of the memory file.
// Output argument: int *mem: a pointer to the memory array.
// The function returns 0 if read and write completes, -1 otherwise.
int ReadMemoryIntoMemArray(char *filename, int *mem)   
{
	if ((filename != NULL) & (&mem != NULL)) { // checking if the parameters given are not null
		/* open the file for reading */
		int i = 0;
		int num;
		char *end;
		FILE *fp;
		char line[LINE_LEN];
		fp = fopen(filename, "r");
		if (fp == NULL) {
			printf("Error, File opening failed, Exiting...\n");
			return -1;
		}
		else {
			/* iterate over all file lines */
			while (fgets(line, sizeof line, fp)) {
				printf("%s", line);
				num = strtol(line, &end, 16);
				printf("%d\n", num);
				mem[i] = num;
				++i;
			}
			fclose(fp);
			return 0;
		}

	}
	else {
		return -1;
	}
}

int ReadConfiguration(char *filename)
{
	if (filename != NULL) 
	{
		FILE *fp;
		int i;
		int num_of_units = 0;
		char parm[14];
		char num[4];
		fp = fopen(filename, "r");
		if (fp == NULL) 
		{
			printf("Error! File opening failed, Exiting...\n");
			return -1;
		}
		else 
		{
			/*Calculate the number of functional units in total*/
			fscanf(fp, "%s = %s\n", parm, num);
			while (strcmp(parm, "add_nr_units") == 0 || strcmp(parm, "sub_nr_units") == 0 || strcmp(parm, "mul_nr_units") == 0 || strcmp(parm, "div_nr_units") == 0 || strcmp(parm, "ld_nr_units") == 0 || strcmp(parm, "st_nr_units") == 0)
			{
				printf("Parm: %s, Num: %s\n", parm, num);
				num_of_units = num_of_units + atoi(num);
				fscanf(fp, "%s = %s\n", parm, num);
			}
			printf("Num of units: %d\n", num_of_units);
			/*Allocate the memory to the struct of units*/
			//func_unit = calloc(num_of_units * sizeof(FuncUnit));
			fclose(fp);
			return 0;


		}
	}
	
}


