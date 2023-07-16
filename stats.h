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
 * @file <stats.h> 
 * @brief <declaration of statistical fuctions on a dataset >
 *
 * <this file contains functions declaration that perform finding the mean,median,
max , min , sorting the array , and printing the statistics>
 *
 * @author <Mahmoud Abdulaal>
 * @date <14-07-2023 >
 *
 */
#ifndef __STATS_H__
#define __STATS_H__

/* Add Your Declarations and Function Comments here */ 

/**
 * @brief <print statistics of an array>
 *
 * <printing statistics of an array include printing max ,min , mean and median>
 * @param <unsigned char* arr>
 * @param <unsigned int length>
 */
void print_statistics(unsigned char* arr, unsigned int length);

/**
 * @brief <printing the array elements>
 *
 * <the function will print the values of the passed array>
 *
 * @param <unsigned char* array>
 * @param <unsigned int length>
*/
void print_array(unsigned char* arr, unsigned int length);

/**
 * @brief <finding the median of an array>
 *
 * <finding the median of an array and returning it as unsigned char
   this function will use sorting function, then will find the median>

 * @param <unsigned char* array>
 * @param <unsigned int length>
 
 * @return<unsigned char>
 */
unsigned char find_median(unsigned char* arr , unsigned int length);

/**
 * @brief <finding the mean of an array>
 *
 * <finding the mean of an array and returning the value as unsigned char>

 * @param <unsigned char* array>
 * @param <unsigned int length>

 * @return<unsigned char>
*/
unsigned char find_mean(unsigned char* arr , unsigned int length);

/**
 * @brief <finding the max of an array>
 *
 * <finding the max of an array and returning the value as unsigned char>

 * @param <unsigned char* array>
 * @param <unsigned int length>

 * @return<unsigned char>
*/

unsigned char find_maximum(unsigned char* arr , unsigned int length);


/**
 * @brief <finding the min of an array>
 *
 * <finding the min of an array and returning the value as unsigned char>

 * @param <unsigned char* array>
 * @param <unsigned int length>

 * @return<unsigned char>
*/

unsigned char find_minimum(unsigned char* arr , unsigned int length);


/**
 * @brief <sorting an array in descending order>
 *
 * <sorting the array in descending order >

 * @param <unsigned char* array>
 * @param <unsigned int length>
*/

void sort_array(unsigned char* arr , unsigned int length);


#endif /* __STATS_H__ */
