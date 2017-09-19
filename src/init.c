#include <R.h>
#include <Rinternals.h>
#include <stdlib.h> // for NULL
#include <R_ext/Rdynload.h>

/* .Call calls */
extern SEXP _pegax_hello_world(SEXP);
extern SEXP _pegax_authority_name(SEXP);
extern SEXP _pegax_authority_year(SEXP);
extern SEXP _pegax_rank_names(SEXP);

static const R_CallMethodDef CallEntries[] = {
  {"_pegax_hello_world", (DL_FUNC) &_pegax_hello_world, 1},
  {"_pegax_authority_name", (DL_FUNC) &_pegax_authority_name, 1},
  {"_pegax_authority_year", (DL_FUNC) &_pegax_authority_year, 1},
  {"_pegax_rank_names", (DL_FUNC) &_pegax_rank_names, 1},
  {NULL, NULL, 0}
};


void R_init_pegax(DllInfo *dll)
{
  R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
  R_useDynamicSymbols(dll, FALSE);
}
