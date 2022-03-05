#ifndef TEXTPROC_INTERNAL_H
#define TEXTPROC_INTERNAL_H

#include <stddef.h>

/*
 * ***** INTERNAL *****
 *
 * Validate arguments and abort() if invalid parameters are detected.
 *
 * Aborts when:
 * - strlen() return values for str and out are different. For this reason,
 *   please don't call this function when the textproc function calling this
 *   is expected to make the resultant string much longer.
 */
void __textproc_check_string_params(char* str, char* out, size_t bufsiz);

#endif /* TEXTPROC_INTERNAL_H */
