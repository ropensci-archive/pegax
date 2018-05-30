#ifndef AUTHORNAME_H
#define AUTHORNAME_H

#include <pegtl.hpp>
using namespace tao::TAOCPP_PEGTL_NAMESPACE;

namespace pegax {
  namespace authorname {

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
    // sor< opt< space >, one< '?' > >
    > {};
    
    struct name3
      : rep_min< 1, named > {};
    
    struct numbers
      : plus< digit >
    {};
    
    struct grammar
      : must< opt< one< '(' > >, name3, opt< one< ',' > >, opt< space >, opt< numbers >, opt< sor< one< ')' >, one< '?' > > >, eof >
    {};
    
    template< typename Rule >
    struct action
      : nothing< Rule >
    {};
    
    template<>
    struct action< name3 >
    {
      template< typename Input >
      static void apply( const Input& in, 
                         std::string& v)
      {
        v = in.string();
      }
    };
    
  }  // namespace authorname
} // namespace pegacks

#endif
