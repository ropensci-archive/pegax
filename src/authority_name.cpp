#include <Rcpp.h>
#include "helpers.h"
#include "authority_name.h"

//[[Rcpp::export]]
std::string authority_name(std::string x){
  std::string z = trim_copy(x);
  std::string name;
  // std::string yr;
  memory_input<> din(z, "moot");
  parse< pegax::authorname::grammar, pegax::authorname::action >( din, name );
  // parse< pegax::authorname::grammar, pegax::authorname::action >( din, name, yr );
  std::string trimmed_name = trim_copy(name);
  trimmed_name = replace_all_symbols(trimmed_name);
  return trimmed_name;
}
