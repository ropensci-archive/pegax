#include <Rcpp.h>
using namespace Rcpp;

// [[Rcpp::depends(piton)]]
#include <pegtl.hpp>
using namespace tao::TAOCPP_PEGTL_NAMESPACE;

namespace rank
{

  struct var
    : seq<
      ::string< 'v', 'a', 'r' >,
      opt< one< '.' > >
    > {};

  struct variety
    : ::string< 'v', 'a', 'r', 'i', 'e', 't', 'y' >
    {};

  struct var_bracket
    : ::string< '[', 'v', 'a', 'r', '.', ']' >
    {};

  struct subsp
    : seq<
      ::string< 's', 'u', 'b', 's', 'p' >,
      opt< one< '.' > >
    > {};

  struct ssp
    : seq<
      ::string< 's', 's', 'p' >,
      opt< one< '.' > >
    > {};

  // below from gnparser
  struct rankVar
    : seq<
      sor<
        ::string< 'v', 'r', 'i', 'e', 't', 'y' >,
        ::string< '[', 'v', 'a', 'r', '.', ']' >,
        ::string< 'v', 'a', 'r' >
      >,
      opt< space, one<'.'> >
    >{};

  struct rankForma
    : seq<
      sor<
        ::string< 'f', 'o', 'r', 'm', 'a' >,
        ::string< 'f', 'm', 'a' >,
        ::string< 'f', 'o', 'r', 'm' >,
        ::string< 'f', 'o' >,
        ::string< 'f' >
      >,
      opt< space, one<'.'> >
    > {};
    
  struct rankSsp
    : seq<
      sor<
        ::string< 's', 's', 'p' >,
        ::string< 's', 'u', 'b', 's', 'p' >
      >,
      opt< space, one<'.'> >
    >{};

  struct rankOther
    : seq<
      sor<
        ::string< 'm', 'o', 'r', 'p', 'h', '.' >,
        ::string< 'n', 'o', 't', 'h', 'o', 's', 'u', 'b', 's', 'p', '.' >,
        ::string< 'c', 'o', 'n', 'v', 'a', 'r', '.' >,
        ::string< 'p', 's', 'e', 'u', 'd', 'o', 'v', 'a', 'r', '.' >,
        ::string< 's', 'e', 'c', 't', '.' >,
        ::string< 's', 'e', 'r', '.' >,
        ::string< 's', 'u', 'b', 'v', 'a', 'r', '.' >,
        ::string< 's', 'u', 'b', 'f', '.' >,
        ::string< 'r', 'a', 'c', 'e' >,
        // ::string< 'α' >,
        // ::string< 'β', 'β' >,
        // ::string< 'β' >,
        // ::string< 'γ' >,
        // ::string< 'δ' >,
        // ::string< 'ε' >,
        // ::string< 'φ' >,
        // ::string< 'θ' >,
        // ::string< 'μ' >,
        ::string< 'a', '.' >,
        ::string< 'b', '.' >,
        ::string< 'c', '.' >,
        ::string< 'd', '.' >,
        ::string< 'e', '.' >,
        ::string< 'g', '.' >,
        ::string< 'k', '.' >,
        ::string< 'p', 'v', '.' >,
        ::string< 'p', 'a', 't', 'h', 'o', 'v', 'a', 'r', '.' >
      >,
      opt< space >
    >{};
    
    struct rankUninomial
      : seq<
        sor<
          ::string< 's', 'e', 'c', 't' >,
          ::string< 's', 'u', 'b', 's', 'e', 'c', 't' >,
          ::string< 't', 'r', 'i', 'b' >,
          ::string< 's', 'u', 'b', 't', 'r', 'i', 'b' >,
          ::string< 's', 'u', 'b', 's', 'e', 'r' >,
          ::string< 's', 'e', 'r' >,
          ::string< 's', 'u', 'b', 'g', 'e', 'n' >,
          ::string< 'f', 'a', 'm' >,
          ::string< 's', 'u', 'b', 'f', 'a', 'm' >,
          ::string< 's', 'u', 'p', 'e', 'r', 't', 'r', 'i', 'b' >
        >,
        opt< one< '.' >>
      >{};
      
    struct approximation
      : sor< 
        ::string< 's', 'p', '.', 'n', 'r', '.' >,
        ::string< 's', 'p', '.', ' ', 'n', 'r', '.' >,
        ::string< 's', 'p', '.', 'a', 'f', 'f', '.' >,
        ::string< 's', 'p', '.', ' ', 'a', 'f', 'f', '.' >,
        ::string< 'm', 'o', 'n', 's', 't', '.' >,
        ::string< '?' >,
        seq<
          sor< 
            ::string< 's', 'p', 'p' >,
            ::string< 'n', 'r' >,
            ::string< 's', 'p' >,
            ::string< 'a', 'f', 'f' >,
            ::string< 's', 'p', 'e', 'c', 'i', 'e', 's' >
          >,
          opt< one< '.' > >
        >
      >{};
      
    struct comparison
      : seq< ::string< 'c', 'f' >, opt< one< '.' > > 
    >{};

    struct rankOtherUncommon
      : sor<
        ::string< '*' >,
        ::string< 'n', 'a', 't' >,
        ::string< 'f', '.', 's', 'p' >,
        ::string< 'm', 'u', 't', '.' >
      >{};
      
// struct oror
//   : seq<
//     opt< space >,
//     sor< var, variety, var_bracket, subsp, ssp >,
//     opt< space >
// > {};

struct oror
  : sor< var, variety, var_bracket, subsp, ssp >
{};

// grammar
struct grammar
  : must< opt< space >, oror, opt< space >, eof >
{};

// Class template for user-defined actions that does
// nothing by default.

template< typename Rule >
struct action
  : nothing< Rule >
{};

// Specialisation of the user-defined action to do
// something when the 'name' rule succeeds; is called
// with the portion of the input that matched the rule.

template<>
struct action< oror >
{
  template< typename Input >
  static void apply( const Input& in, std::string& v)
  {
    v = in.string();
  }
};

}  // namespace rank

//[[Rcpp::export]]
std::string rank_name(std::string x){
  std::string z;
  memory_input<> din(x, "moot");
  parse< rank::grammar, rank::action >( din, z );
  return z;
}
