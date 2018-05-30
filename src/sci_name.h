#ifndef SCINAME_H
#define SCINAME_H

#include <Rcpp.h>
using namespace Rcpp;

#include "authority_year.h"
#include "rank.h"

#include <pegtl.hpp>
using namespace tao::TAOCPP_PEGTL_NAMESPACE;

namespace pegax {
  namespace sciname {

  struct spaceChars : space {};
  struct softSpace : star< spaceChars >{};

  struct name
    : plus< alpha >
  {};

  struct name2
    : must<
      name,
      opt< softSpace >,
      opt< name >
    > {};
  
  struct epithet
    : plus< alpha > 
  {};
  
  struct infraname
    : plus< alpha > 
  {};
  
  // various possible combinations 
  struct just_a_name
    : must< name >
  {};
  struct genus_epithet
    : must< name, softSpace, epithet >
  {};
  struct genus_epithet_infra
    : must< name, softSpace, epithet, softSpace, infraname >
  {};
  struct genus_epithet_rank_infra
    : must< name, softSpace, epithet, softSpace, pegax::rank::oror, softSpace, infraname >
  {};
  struct genus_approx
    : must< name, softSpace, pegax::rank::approximation >
  {};
  struct genus_approx_name
    : must< name, softSpace, pegax::rank::approximation, softSpace, infraname >
  {};
  struct genus_name_approx_name
    : must< name, softSpace, pegax::rank::approximation, softSpace, pegax::rank::approximation, softSpace, infraname >
  {};
  struct genus_name_approx
    : must< name, softSpace, pegax::rank::approximation, softSpace, pegax::rank::approximation >
  {};
  
  struct grammar
    : star<
      sor<
        just_a_name,
        genus_epithet,
        genus_epithet_infra,
        genus_epithet_rank_infra,
        genus_approx,
        genus_approx_name,
        genus_name_approx_name,
        genus_name_approx
      >,
      eof
   > {};

  template< typename Rule >
  struct action
    : nothing< Rule >
  {};

  template<>
  struct action< name >
  {
    template< typename Input >
    static void apply( const Input& in, 
                       std::string& v, 
                       const std::string&, 
                       const std::string&, 
                       const std::string&,
                       const std::string& )
    {
      v = in.string();
    }
  };
  
  template<>
  struct action< epithet >
  {
    template< typename Input >
    static void apply( const Input& in, 
                       const std::string&, 
                       std::string& v, 
                       const std::string&, 
                       const std::string&,
                       const std::string& )
    {
      v = in.string();
      // v = std::string( in.begin(), in.size() );
    }
  };
  
  template<>
  struct action< pegax::rank::oror >
  {
    template< typename Input >
    static void apply( const Input& in, 
                       const std::string&, 
                       const std::string&, 
                       std::string& v, 
                       const std::string&,
                       const std::string& )
    {
      v = in.string();
    }
  };
  
  template<>
  struct action< pegax::rank::annotators >
  {
    template< typename Input >
    static void apply( const Input& in, 
                       const std::string&, 
                       const std::string&, 
                       const std::string&,
                       std::string& v, 
                       const std::string& )
    {
      v = in.string();
    }
  };
  
  template<>
  struct action< infraname >
  {
    template< typename Input >
    static void apply( const Input& in, 
                       const std::string&, 
                       const std::string&, 
                       const std::string&,
                       const std::string&,
                       std::string& v )
    {
      v = in.string();
    }
  };

  }  // namespace sciname
} // namespace pegax
 
#endif
