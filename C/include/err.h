/**
 * @file	err.h
 * @brief	Header file containing error check routines
 * @author	Jones <jonessos.ben@gmail.com>
 *
 */

#ifndef __ERR_H__
#define __ERR_H__

/*
 * Error messages
 */
/** Print an error message with details */
#define pr_err_msg(file, line)		{				\
	fprintf(stderr,							\
		"Error: inside @func %s, from @file %s, @line %d\n",	\
		__FUNCTION__, file, line);				\
	ret = -1;							\
	goto exit;							\
}

/** Error check for pointers */
#define do_error_ptr(x, file, line)	if (x == NULL) \
						pr_err_msg(file, line)
/** Error check for integers
 *
 * @warning	Consider as en error iff return is less than 0
 */
#define do_error_int(x, file, line)	if (x < 0) \
						pr_err_msg(file, line)
/**
 * @brief	For returning named error values to the caller functions
 */
typedef enum {
	BAD_RETURN = -1		/**< Bad return value */
} ErrorCodes;

#endif			/* __ERR_H__ */
