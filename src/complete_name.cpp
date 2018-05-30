#include <Rcpp.h>
using namespace Rcpp;

#include "helpers.h"
#include "authority_name.h"
#include "authority_year.h"

// [[Rcpp::depends(piton)]]
#include <pegtl.hpp>
using namespace tao::TAOCPP_PEGTL_NAMESPACE;

namespace pegax {
  namespace completename {

  struct name
    : plus< alpha >
  {};
  
  struct llb
    : any {};

  // struct grammar
  //   : must< 
  //     pegax::authorname::name3,
  //     pegax::authoryear::numbers,
  //     eof 
  // >{};
  struct grammar
    : star< 
      opt< one< '(' > >, 
      pegax::authorname::name3, 
      opt< one< ',' > >, 
      opt< space >, 
      opt< pegax::authoryear::numbers >, 
      opt< sor< one< ')' >, one< '?' > > >, 
      eof 
  >{};

  template< typename Rule >
  struct action
    : nothing< Rule >
  {};

  template<>
  struct action< pegax::authorname::name3 >
  {
    template< typename Input >
    static void apply( const Input& in, std::string& v, const std::string& )
    {
      v = in.string();
    }
  };
  
  template<>
  struct action< pegax::authoryear::numbers >
  {
    template< typename Inp_ut >
    static void apply( const Inp_ut& in, const std::string&, std::string& year)
    {
      year = in.string();
    }
  };

  }  // namespace completename
} // namespace pegax

//[[Rcpp::export]]
DataFrame parse_name(std::string x){
  std::string z = trim_copy(x);
  std::string zz;
  std::string year;
  tao::pegtl::memory_input<> din(z, "moot");
  parse< pegax::completename::grammar, 
         pegax::completename::action >( din, zz, year );
  std::string trimmed_zz = trim_copy(zz);
  std::string trimmed_year = trim_copy(year);
  if (zz.size() == 0) {
    String zz = NA_STRING;
  };
  return DataFrame::create(_["author"] = trimmed_zz,
                           _["year"] = year,
                           _["stringsAsFactors"] = false);
}
