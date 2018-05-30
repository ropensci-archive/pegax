#include <Rcpp.h>
using namespace Rcpp;

#include "helpers.h"
#include "rank.h"

//[[Rcpp::export]]
CharacterVector rank_names(CharacterVector x){
  const int n = x.size();
  CharacterVector y(n);
  // y[0] = NA_STRING;
  for (int i=0; i < n; ++i) {
    std::string z;
    memory_input<> din(x[i], "moot");
    parse< pegax::rank::grammar, pegax::rank::action >( din, z );
    y[i] = z;
  }
  return y;
  // memory_input<> din(x, "moot");
  // parse< rank::grammar, rank::action >( din, z );
  // return z;
}
