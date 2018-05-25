#include <Rcpp.h>
using namespace Rcpp;

// [[Rcpp::depends(piton)]]
#include <pegtl.hpp>
using namespace tao::TAOCPP_PEGTL_NAMESPACE;

namespace scrub
{
  struct asa
    : seq< plus< alpha >, space, plus< alpha > >
  {};

  struct txtspacetxt
    : sor< 
      seq< asa, space  >, 
      seq< plus< alpha >, space >
    >
  {};

  struct txtany
    : seq< opt< space >, plus< tao::TAOCPP_PEGTL_NAMESPACE::any > >
  {};
  
  struct oror
    : plus< alpha >
  {};

  // grammar
  struct grammar
    : star< 
      txtspacetxt,
      oror, 
      opt< txtany >,
      eof >
  {};

  template< typename Rule >
  struct action
    : nothing< Rule >
  {};

  template<>
  struct action< oror >
  { 
    template< typename Input >
    static void apply( const Input& in, std::string& v)
    {
      v = in.string();
    }
  };
}  // namespace scrub

//[[Rcpp::export]]
CharacterVector scrub_names(CharacterVector x){
  const int n = x.size();
  CharacterVector y(n);
  for (int i=0; i < n; ++i) {
    std::string z;
    // std::string zz = string(x[i]);
    // std::string xx = rep_specific_symbols2(x[i]);
    memory_input<> din(x[i], "moot");
    parse< scrub::grammar, scrub::action >( din, z );
    y[i] = z;
  }
  return y;
}
