#include <Rcpp.h>
using namespace Rcpp;

// [[Rcpp::depends(piton)]]
#include <pegtl.hpp>

using namespace tao::TAOCPP_PEGTL_NAMESPACE;
// using namespace pegtl = tao::pegtl;

namespace authoryear
{

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
  : must< name2, one< ',' >, space, numbers, eof >
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
  std::string numbers;
  memory_input<> din(x, "mooter");
  parse< authoryear::grammar, authoryear::action >( din, numbers );
  return numbers;
}
