#ifndef LREC_READER_H
#define LREC_READER_H

#include <stdio.h>
#include "containers/lrec.h"
#include "mapping/context.h"
#include "input/file_reader_mmap.h"

// The void* pvhandle is either FILE* for stdio readers or file_reader_mmap_state_t* for mmap readers.
typedef lrec_t* lrec_reader_process_func_t(void* pvhandle, void* pvstate, context_t* pctx);
typedef void    lrec_reader_sof_func_t(void* pvstate);
typedef void    lrec_reader_free_func_t(void* pvstate);

typedef struct _lrec_reader_t {
	void*                       pvstate;
	lrec_reader_process_func_t* pprocess_func;
	lrec_reader_sof_func_t*     psof_func;
	lrec_reader_free_func_t*    pfree_func;
} lrec_reader_t;

#endif // LREC_READER_H
