/****************************************************************************
 *                                                                          *
 * File    : main.c                                                         *
 *                                                                          *
 * Purpose : Console mode (command line) program.                           *
 *                                                                          *
 * History : Date      Reason                                               *
 *           00/00/00  Created                                              *
 *                                                                          *
 ****************************************************************************/

#include <stdio.h>
#include "calc_time.h"

/****************************************************************************
 *                                                                          *
 * Function: main                                                           *
 *                                                                          *
 * Purpose : Main entry point.                                              *
 *                                                                          *
 * History : Date      Reason                                               *
 *           00/00/00  Created                                              *
 *                                                                          *
 ****************************************************************************/

int main(int argc, char *argv[])
{
 struct tm one_time;

    printf("Enter day:");
	scanf("%d",&one_time.tm_mday);
	printf("Enter month:");
    scanf("%d",&one_time.tm_mon);
    printf("Enter year:");
	scanf("%d",&one_time.tm_year);
	printf("Enter hour:");
    scanf("%d",&one_time.tm_hour);
    printf("Enter minute:");
	scanf("%d",&one_time.tm_min);
	printf("Enter seconds:");
    scanf("%d",&one_time.tm_sec);

	printf("Day of week: %d\n",day_of_week(one_time.tm_year,one_time.tm_mon,one_time.tm_mday));
    printf("Unix seconds:%l\n",getUnixSeconds(&one_time));

    return 0;
}

