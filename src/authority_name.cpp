#include <Rcpp.h>
using namespace Rcpp;

// [[Rcpp::depends(piton)]]
#include <pegtl.hpp>
using namespace tao::TAOCPP_PEGTL_NAMESPACE;

namespace authorname
{

// Parsing rule that matches a non-empty sequence of
// alphabetic ascii-characters with greedy-matching.

struct name
  : plus< alpha >
{};

// name - with optional apostrophe
struct named
  : seq<
    alpha,
    opt< one< '\'', '-', '_', '.' > >,
    plus< alpha >,
    opt< one< ',' > >,
    opt< space >
> {};

// name - with optional apostrophe
struct name3
  : rep_min< 1, named > {};

// Parsing rule that matches a non-empty sequence of
// numbers of length 4.

struct numbers
  : plus< digit >
{};

// Parsing rule that matches a sequence of the 'prefix'
// rule, the 'name' rule, a literal "!", and 'eof'
// (end-of-file/input), and that throws an exception
// on failure.

struct grammar
  : must< opt< one< '(' > >, name3, opt< one< ',' > >, opt< space >, numbers, opt< one< ')' > >, eof >
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
struct action< name3 >
{
  template< typename Input >
  static void apply( const Input& in, std::string& v)
  {
    v = in.string();
  }
};

}  // namespace authorname

//[[Rcpp::export]]
std::string authority_name(std::string x){
  std::string name;
  memory_input<> din(x, "moot");
  parse< authorname::grammar, authorname::action >( din, name );
  return name;
}
