#include <Rcpp.h>
using namespace Rcpp;

#include "helpers.h"
#include "sci_name.h"

// std::string sci_name(std::string x){
//   std::string z = trim_copy(x);
//   std::string out;
//   memory_input<> din(z, "mooter");
//   parse< pegax::sciname::grammar, pegax::sciname::action >( din, out );
//   return out;
// }

//[[Rcpp::export]]
DataFrame sci_name(std::string x){
  std::string z = trim_copy(x); // trim blank spaces before parsing
  
  std::string zz; // genus or other higher level name
  std::string ep; // epithet
  std::string rr; // rank
  std::string ai; // annotation identification, e.g., "cf."
  std::string ie; // infraspecific epithet
  
  tao::pegtl::memory_input<> din(z, "moot");
  parse< pegax::sciname::grammar, 
         pegax::sciname::action >( din, zz, ep, rr, ai, ie );
  
  std::string trimmed_zz = trim_copy(zz);
  std::string trimmed_ep = trim_copy(ep);
  std::string trimmed_rr = trim_copy(rr);
  std::string trimmed_ai = trim_copy(ai);
  std::string trimmed_ie = trim_copy(ie);
  // if (trimmed_zz.size() == 0) {
  //   String trimmed_zz = R_NaString ;
  // };
  // if (trimmed_ep.size() == 0) {
  //   String trimmed_ep = R_NaString;
  // };
  // if (trimmed_rr.size() == 0) {
  //   String trimmed_rr = R_NaString;
  // };
  
  return DataFrame::create(_["genus"] = trimmed_zz,
                           _["epithet"] = trimmed_ep,
                           _["rank"] = trimmed_rr,
                           _["annotation_identification"] = trimmed_ai,
                           _["infraspecific_epithets"] = trimmed_ie,
                           _["stringsAsFactors"] = false);
}
