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
  /* Statistics and Printing Functions Go Here */
  print_statistics(test , SIZE);

 /* print the array before sorting*/
  printf("\n\n");
  print_array(test , SIZE);

 /*print the array after descending order sorting*/
 printf("\n\n");
 sort_array(test , SIZE);
 print_array(test , SIZE);

}

/* Add other Implementation File Code Here */
void print_statistics(unsigned char* arr, unsigned int length)
{
  unsigned char mean = find_mean(arr , length);
  unsigned char median = find_median(arr , length);
  unsigned char max = find_maximum(arr , length);
  unsigned char min = find_minimum(arr , length);

  printf("the mean is %d\n", mean);
  printf("the median is %d\n", median);
  printf("the maximum value is %d\n" , max);
  printf("the minimum value is %d\n" , min);
}

void print_array(unsigned char* arr , unsigned int length)
{
 for(int i = 0; i<length ; i++)
 {
  printf("%d\n" , arr[i]);
 }
}

unsigned char find_median(unsigned char* arr , unsigned int length)
{
 quick_sort(arr , length);

 unsigned char median;

 if(length%2 == 0)
 {
  median = (arr[length/2] + arr[length/2 - 1])/2;
 }

 else
 {
  median = arr[length/2];
 }
 return median;
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

void sort_array(unsigned char* arr ,unsigned int length)
{
 quick_sort(arr , length);
 unsigned int start = 0;
 unsigned int end = length-1;

 while(start<end)
 {
  unsigned char temp = arr[start];
  arr[start] = arr[end];
  arr[end] = temp;

  start++;
  end--;
 }
}

void swap(unsigned char* a , unsigned char* b)
{
 unsigned char temp = *a;
 *a = *b;
 *b = temp;
}


void quick_sort(unsigned char* arr , unsigned int length)
{
 quick_sort_recursion(arr , 0 , length-1);
}

void quick_sort_recursion(unsigned char* arr , unsigned int low , unsigned int high)
{
 if (low<high)
 {
  unsigned int pivot_index = partition(arr,low,high);
  quick_sort_recursion(arr , low , pivot_index-1);
  quick_sort_recursion(arr ,pivot_index+1, high);
 }
}

unsigned int partition(unsigned char* arr, unsigned int low , unsigned int high)
{
 unsigned char pivot_value = arr[high];
 unsigned int i = low;
 for(unsigned int j = low ; j<high ; j++)
 {
  if(arr[j]<= pivot_value)
  {
   swap(&arr[i] , &arr[j]);
   i++;
  }
 }
 swap(&arr[i] , &arr[high]);
 return i;
}
