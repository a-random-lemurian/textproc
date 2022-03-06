#ifndef TEXTPROC_INTERNAL_H
#define TEXTPROC_INTERNAL_H

#include <textproc.h>
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

size_t __textproc_longest_chartbl_value_len(const chartbl_lookup_row *clr);
size_t __textproc_longest_chartbl_value_len_n(const chartbl_lookup_row *clr,
                                              size_t num_tbl_entries);

#endif /* TEXTPROC_INTERNAL_H */
