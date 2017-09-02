#include <Rcpp.h>
using namespace Rcpp;

// [[Rcpp::depends(piton)]]
#include <pegtl.hpp>

using namespace tao::TAOCPP_PEGTL_NAMESPACE;
// using namespace pegtl = tao::pegtl;

namespace subspec
{

// Parsing rule that matches a non-empty sequence of
// alphabetic ascii-characters with greedy-matching.

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

}  // namespace subspec

//[[Rcpp::export]]
std::string name_subsp(std::string x){
  std::string z;
  memory_input<> din(x, "moot");
  parse< subspec::grammar, subspec::action >( din, z );
  return z;
}
