#include "GenomicRanges.h"
#include <R_ext/Rdynload.h>

#define CALLMETHOD_DEF(fun, numArgs) {#fun, (DL_FUNC) &fun, numArgs}

static const R_CallMethodDef callMethods[] = {

/* cigar_utils.c */
	CALLMETHOD_DEF(valid_cigar, 2),
	CALLMETHOD_DEF(split_cigar, 1),
	CALLMETHOD_DEF(cigar_op_table, 1),
	CALLMETHOD_DEF(cigar_to_qwidth, 2),
	CALLMETHOD_DEF(cigar_to_qwidth2, 2),
	CALLMETHOD_DEF(cigar_to_width, 1),
	CALLMETHOD_DEF(cigar_qnarrow, 3),
	CALLMETHOD_DEF(cigar_narrow, 3),
	CALLMETHOD_DEF(cigar_to_IRanges, 3),
	CALLMETHOD_DEF(cigar_to_list_of_IRanges_by_alignment, 4),
	CALLMETHOD_DEF(cigar_to_list_of_IRanges_by_rname, 6),

/* compact_bit_vector.c */
	CALLMETHOD_DEF(logical_as_compact_raw_vector, 1),
	CALLMETHOD_DEF(compact_raw_vector_as_logical, 2),
	CALLMETHOD_DEF(subset_compact_raw_vector, 2),
	CALLMETHOD_DEF(compact_raw_vector_bit_count, 1),
	CALLMETHOD_DEF(compact_raw_vector_last_bit, 1),
	CALLMETHOD_DEF(compact_raw_vector_set_op, 3),

	{NULL, NULL, 0}
};

void R_init_GenomicRanges(DllInfo *info)
{
	R_registerRoutines(info, NULL, callMethods, NULL, NULL);
	return;
}

