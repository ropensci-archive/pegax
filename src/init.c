#include <R.h>
#include <Rinternals.h>
#include <stdlib.h> // for NULL
#include <R_ext/Rdynload.h>

/* FIXME:
 Check these declarations against the C/Fortran source code.
 */

/* .Call calls */
extern SEXP pegax_peg_sum(SEXP);
extern SEXP pegax_hello_world(SEXP);
extern SEXP pegax_authority_name(SEXP);
extern SEXP pegax_authority_year(SEXP);

static const R_CallMethodDef CallEntries[] = {
  {"pegax_peg_sum", (DL_FUNC) &pegax_peg_sum, 1},
  {"pegax_hello_world", (DL_FUNC) &pegax_hello_world, 1},
  {"pegax_authority_name", (DL_FUNC) &pegax_authority_name, 1},
  {"pegax_authority_year", (DL_FUNC) &pegax_authority_year, 1},
  {NULL, NULL, 0}
};


void R_init_pegax(DllInfo *dll)
{
  R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
  R_useDynamicSymbols(dll, FALSE);
}
