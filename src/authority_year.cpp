#include <Rcpp.h>
#include "helpers.h"
#include "authority_year.h"

//[[Rcpp::export]]
std::string authority_year(std::string x){
  std::string z = trim_copy(x);
  std::string numbers;
  memory_input<> din(z, "mooter");
  parse< pegax::authoryear::grammar, pegax::authoryear::action >( din, numbers );
  return numbers;
}
