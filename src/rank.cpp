#include <Rcpp.h>
using namespace Rcpp;

#include "rank.h"
#include "helpers.h"

//[[Rcpp::export]]
CharacterVector rank_names(CharacterVector x){
  // const int nn = x.size();
  // CharacterVector xx(nn);
  // for (int i=0; i < nn; ++i) {
  //   std::string trimmedx = multi_space_to_single(x[i]);
  //   xx[i] = trimmedx;
  // }
  
  const int n = x.size();
  CharacterVector y(n);
  for (int i=0; i < n; ++i) {
    std::string z;
    std::string trimmedx = multi_space_to_single( Rcpp::as<std::string>(x[i]) );
    memory_input<> din(trimmedx, "moot");
    // memory_input<> din(x[i], "moot");
    parse< pegax::rank::grammar, pegax::rank::action >( din, z );
    std::string trimmed_z = trim_copy(z);
    y[i] = trimmed_z;
  }
  return y;
  // memory_input<> din(x, "moot");
  // parse< rank::grammar, rank::action >( din, z );
  // return z;
}
