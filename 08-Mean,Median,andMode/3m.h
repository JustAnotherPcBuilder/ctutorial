#ifndef __3M_H__
#define __3M_H__

typedef struct{
    int count;
    int *list;
}m_mode_t;

typedef struct{
    int count;
    int list[2];
}m_median_t;

/**
 *
 * @brief		This function assigns the list's mode to the 
 *				provided mode pointer.
 * 
 * This function sort's the array to track the mode instead of 
 * using a hashmap. IT WILL alter the list!
 *
 * @param mode	A pointer to a m_mode_t struct where the values 
 *				will be saved to.
 *
 * @note		The mode struct will allocate memory for the mode(s).
 *
 * @param count	The length of the list.
 *
 * @param list	A pointer to the array containing the list of ints.
 *
 * @return		0 when successful
 *				-1 when error
 *
 * ***************************************************************
 */
int mode(m_mode_t *mode, int count, int *list);


/**
 *
 * @brief		This function returns the list's mean rounded to the
 *				provided round's number.
 * 
 * @param count	The length of the list
 *
 * @param list	A pointer to the array containing the list of ints
 *
 * @param round	The number of places the mean will be rounded to.
 *
 * @return		The mean of the provided array.
 *
 * ***************************************************************
 */
double mean(int count, int *list, int round);


/**
 *
 * @brief		This function assigns the list's median to the 
 *				provided median pointer.
 *
 * If the list is even, this function will set both numbers to 
 * the m_median_t struct that may be considered the median.
 * 
 * @param median	A pointer to a m_median_t struct.
 *
 * @note		This assigns the median value(s) through a pointer
 *				instead of returning because there may be multiple
 *				medians. Instead of allocating memory, this will 
 *				write to a struct which will have the space for 2.
 *
 * @param count	The length of the list
 *
 * @param list	A pointer to the array containing the list of ints
 *
 * @return		0 when successful
 *				-1 when error
 *
 * ***************************************************************
 */
int median(m_median_t *median, int count, int *list);

#endif
