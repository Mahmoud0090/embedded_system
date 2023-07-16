/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file <stats.c> 
 * @brief <implementation of the functions defined in statc.h >
 *
 * <here are the implementations of statistics and printing functions
   performed on an unsigned char type array >
 *
 * @author <Mahmoud Abdulaal>
 * @date <14-07-2023>
 *
 */


#include <stdio.h>
#include "stats.h"
#include <stdlib.h>

/* Size of the Data Set */
#define SIZE (40)

void main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  /* Other Variable Declarations Go Here */
  

 /* print the array before sorting*/
  printf("\n\n");
  print_array(test , SIZE);

}

/* Add other Implementation File Code Here */

void print_array(unsigned char* arr , unsigned int length)
{
 for(int i = 0; i<length ; i++)
 {
  printf("%d\n" , arr[i]);
 }
}

unsigned char find_mean(unsigned char* arr , unsigned int length)
{
 unsigned int sum = 0;
 unsigned char mean = 0;
 for(int i = 0; i<length ; i++)
 {
  sum += arr[i];
 }
 mean = sum/length;
 return mean;
}

unsigned char find_maximum(unsigned char* arr ,unsigned int length)
{
 unsigned char max = 0;
 for(int i = 0;i<length ; i++)
 {
  if(arr[i]>max)
  {
   max = arr[i];
  }
 }
 return max;
}

unsigned char find_minimum(unsigned char* arr ,unsigned int length)
{
 unsigned char min = 255 ;
 for(int i = 0;i<length ; i++)
 {
  if(arr[i]<min)
  {
   min = arr[i];
  }
 }
 return min;
}


