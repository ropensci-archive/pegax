#include <Rcpp.h>
using namespace Rcpp;

#include "helpers.h"

// [[Rcpp::depends(piton)]]
#include <pegtl.hpp>
using namespace tao::TAOCPP_PEGTL_NAMESPACE;

namespace authoryear
{

struct spaceChars : space {};
struct softSpace : star< spaceChars >{};

// Parsing rule that matches a non-empty sequence of
// alphabetic ascii-characters with greedy-matching.

struct name
  : plus< alpha >
{};

// name - with optional apostrophe
struct name2
  : seq<
    alpha,
    opt< one< '\'', '-', '_' > >,
    plus< alpha >
> {};

struct yearNumber
  : seq<
    sor< one< '1' >, one< '2' > >,
    // one< digit >,
    // sor< one< '0' >, one< '2' >, one< '2' >, one< '3' >, one< '4' >, one< '5' >, one< '6' >, one< '7' >, one< '8' >, one< '9' > >,
    plus< digit >,
    opt< one< '?' > >
>{};

struct yearWithChar
  : seq< 
    yearNumber,
    plus< alpha >
>{};

struct yearWithParens
  : seq<
    ::string< '(' >,
    softSpace,
    sor< yearWithChar, yearNumber>,
    softSpace,
    ::string< ')' >
>{};

struct yearWithPage
  : seq<
    sor< yearWithChar, yearNumber >,
    softSpace,
    ::string< ':' >,
    softSpace,
    star< digit >
>{};

struct yearApprox
  : seq<
    ::string< '[' >,
    softSpace,
    yearNumber,
    softSpace,
    ::string< ']' >
>{};
  
struct yearWithDot
  : seq< 
    yearNumber, 
    ::string< '.' >
>{};

struct yearRange
  : seq< 
    yearNumber,
    ::string< '-' >,
    plus< digit >,
    star< alpha >
>{};
  
struct numbers
  : sor< yearNumber, yearWithChar, yearWithParens, yearWithPage, 
    yearApprox, yearWithDot, yearRange >
{};



// Parsing rule that matches a sequence of the 'prefix'
// rule, the 'name' rule, a literal "!", and 'eof'
// (end-of-file/input), and that throws an exception
// on failure.

struct grammar
  : must< 
    opt< one< '(' > >, 
    name2, 
    opt< one< ',' > >, 
    space, 
    numbers, 
    opt< one< ')' > >,
    eof 
>{};

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
struct action< numbers >
{
  template< typename Input >
  static void apply( const Input& in, std::string& v)
  {
    v = in.string();
  }
};

}  // namespace authoryear

//[[Rcpp::export]]
std::string authority_year(std::string x){
  std::string z = trim_copy(x);
  std::string numbers;
  memory_input<> din(z, "mooter");
  parse< authoryear::grammar, authoryear::action >( din, numbers );
  return numbers;
}
