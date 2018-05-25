#include <R.h>
#include <Rinternals.h>
#include <stdlib.h> // for NULL
#include <R_ext/Rdynload.h>

/* .Call calls */
extern SEXP _pegax_authority_name(SEXP);
extern SEXP _pegax_authority_year(SEXP);
extern SEXP _pegax_rank_names(SEXP);
extern SEXP _pegax_scrub_names(SEXP);
extern SEXP _pegax_replace_all_symbols(SEXP);
extern SEXP _pegax_replace_specific_symbols(SEXP);

static const R_CallMethodDef CallEntries[] = {
  {"_pegax_authority_name", (DL_FUNC) &_pegax_authority_name, 1},
  {"_pegax_authority_year", (DL_FUNC) &_pegax_authority_year, 1},
  {"_pegax_rank_names", (DL_FUNC) &_pegax_rank_names, 1},
  {"_pegax_scrub_names", (DL_FUNC) &_pegax_scrub_names, 1},
  {"_pegax_replace_all_symbols", (DL_FUNC) &_pegax_replace_all_symbols, 1},
  {"_pegax_replace_specific_symbols", (DL_FUNC) &_pegax_replace_specific_symbols, 1},
  {NULL, NULL, 0}
};


void R_init_pegax(DllInfo *dll)
{
  R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
  R_useDynamicSymbols(dll, FALSE);
}
