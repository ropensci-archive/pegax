#ifndef RANK_H
#define RANK_H

#include "authority_name.h"

#include <pegtl.hpp>
using namespace tao::TAOCPP_PEGTL_NAMESPACE;

namespace pegax {
  namespace rank {

    struct var
      : seq<
        ::string< 'v', 'a', 'r' >, // var
        opt< one< '.' > >
      > 
    {};

    struct variety
      : ::string< 'v', 'a', 'r', 'i', 'e', 't', 'y' > // variety
    {};

    struct var_bracket
      : ::string< '[', 'v', 'a', 'r', '.', ']' > // var.
    {};

    struct subsp
      : seq<
        ::string< 's', 'u', 'b', 's', 'p' >, // subsp
        opt< one< '.' > >
      > 
    {};

    struct ssp
      : seq<
        ::string< 's', 's', 'p' >, // ssp
        opt< one< '.' > >
      >
    {};

    // below from gnparser
    struct rankVar
      : seq<
        sor<
          ::string< 'v', 'a', 'r', 'i', 'e', 't', 'y' >, // variety
          ::string< '[', 'v', 'a', 'r', '.', ']' >, // [var.]
          ::string< 'v', 'a', 'r' > // var
        >,
        sor< space, one<'.'> >
      >
    {};

    struct rankForma
      : seq<
        sor<
          ::string< 'f', 'o', 'r', 'm', 'a' >, // forma
          ::string< 'f', 'm', 'a' >, // fma
          ::string< 'f', 'o', 'r', 'm' >, // form
          ::string< 'f', 'o' >, // fo
          ::string< 'f' > // f
        >,
        sor<space, one<'.'>>
        // opt< sor<space, one<'.'>> >
      > 
    {};
      
    struct rankSsp
      : seq<
        sor<
          ::string< 's', 's', 'p' >, // ssp
          ::string< 's', 'u', 'b', 's', 'p' > // subsp
        >,
        sor< one< '.' >, seq< one< '.' >, space >, space >
      >
    {};

    struct rankOther
      : seq<
        sor<
          ::string< 'm', 'o', 'r', 'p', 'h', '.' >, // morph.
          ::string< 'n', 'o', 't', 'h', 'o', 's', 'u', 'b', 's', 'p', '.' >, // nothosubsp.
          ::string< 'c', 'o', 'n', 'v', 'a', 'r', '.' >, // convar.
          ::string< 'p', 's', 'e', 'u', 'd', 'o', 'v', 'a', 'r', '.' >, // pseudovar.
          ::string< 's', 'e', 'c', 't', '.' >, // sect.
          ::string< 's', 'e', 'r', '.' >, // ser.
          ::string< 's', 'u', 'b', 'v', 'a', 'r', '.' >, // subvar.
          ::string< 's', 'u', 'b', 'f', '.' >, // subf.
          ::string< 'r', 'a', 'c', 'e' >, // race
          // ::string< 'α' >,
          // ::string< 'β', 'β' >,
          // ::string< 'β' >,
          // ::string< 'γ' >,
          // ::string< 'δ' >,
          // ::string< 'ε' >,
          // ::string< 'φ' >,
          // ::string< 'θ' >,
          // ::string< 'μ' >,
          ::string< 'a', '.' >, // a.
          ::string< 'b', '.' >, // b.
          ::string< 'c', '.' >, // c.
          ::string< 'd', '.' >, // d.
          ::string< 'e', '.' >, // e.
          ::string< 'g', '.' >, // g.
          ::string< 'k', '.' >, // k.
          ::string< 'p', 'v', '.' >, // pv.
          ::string< 'p', 'a', 't', 'h', 'o', 'v', 'a', 'r', '.' > // pathovar.
        >,
        opt< space >
        >
      {};
      
      struct rankUninomial
        : seq<
          sor<
            ::string< 's', 'e', 'c', 't' >, // sect
            ::string< 's', 'u', 'b', 's', 'e', 'c', 't' >, //subsect
            ::string< 't', 'r', 'i', 'b' >, // trib
            ::string< 's', 'u', 'b', 't', 'r', 'i', 'b' >, // subtrib
            ::string< 's', 'u', 'b', 's', 'e', 'r' >, // subser
            ::string< 's', 'e', 'r' >, // ser
            ::string< 's', 'u', 'b', 'g', 'e', 'n' >, //subgen
            ::string< 'f', 'a', 'm' >, // fam
            ::string< 's', 'u', 'b', 'f', 'a', 'm' >, // subfam
            ::string< 's', 'u', 'p', 'e', 'r', 't', 'r', 'i', 'b' > // supertrib
          >,
          sor< space, one< '.' >>
        >
      {};
        
      struct approximation
        : sor< 
          ::string< 's', 'p', '.', 'n', 'r', '.' >, // sp.nr.
          ::string< 's', 'p', '.', ' ', 'n', 'r', '.' >, // sp. nr.
          ::string< 's', 'p', '.', 'a', 'f', 'f', '.' >, // sp.aff.
          ::string< 's', 'p', '.', ' ', 'a', 'f', 'f', '.' >, // sp. aff.
          ::string< 'm', 'o', 'n', 's', 't', '.' >, // monst.
          ::string< '?' >, // ?
          seq<
            sor< 
              ::string< 's', 'p', 'p' >, // spp
              ::string< 'n', 'r' >, // nr
              ::string< 's', 'p' >, // sp
              ::string< 'a', 'f', 'f' >, // aff
              ::string< 's', 'p', 'e', 'c', 'i', 'e', 's' > // species
            >,
            sor<space, one<'.'>>
            // opt< one< '.' > >
          >
        >
      {};
        
      struct comparison
        : seq< ::string< 'c', 'f' >, opt< one< '.' > >  // cf.
        >
      {};

      struct rankOtherUncommon
        : seq<
          sor<
            ::string< '*' >, // *
            ::string< 'n', 'a', 't' >, // nat
            ::string< 'f', '.', 's', 'p' >, // f.sp
            ::string< 'm', 'u', 't', '.' > // mut.
          >,
          sor<space, one<'.'>>
        >
      {};
        
      struct asa
        : seq< plus< alpha >, space, plus< alpha > >
      {};
      
      struct txtspacetxt
        : sor<
            seq< asa, space, plus< alpha > >,
            seq< plus< alpha >, space >,
            seq< asa, space >
        > {};
      
      struct txtany
        // : seq< opt< space >, plus< tao::TAOCPP_PEGTL_NAMESPACE::any > >
        : seq< space, plus< tao::TAOCPP_PEGTL_NAMESPACE::any > >
      {};
        
    struct oror
      : sor< 
        rankVar, rankForma, rankSsp, rankOther, rankOtherUncommon,
        rankUninomial, approximation, comparison 
      >
    {};
    
    struct annotators
      : sor< approximation, comparison >
    {};
    
    struct nameoptdot
      : star<
        plus< alpha >,
        opt< one<'.'> >
      >
    {};
    
    struct authur
      : seq< opt< one< '(' > >, plus< alpha >, opt< sor< one< ')' >, one< '?' > > >, space >
      // : seq< opt< one< '(' > >, plus< tao::TAOCPP_PEGTL_NAMESPACE::any >, opt< sor< one< ')' >, one< '?' > > >, space >
      // : seq< opt< one< '(' > >, nameoptdot, opt< sor< one< ')' >, one< '?' > > >, space >
    {};

    // grammar
    // matches: 
    //   (text - space - text) - (<any rank> OR <author> + <any rank>) - (space - text)
    //   (text - space) - (<any rank> OR <author> + <any rank>) - (space - text)
    struct grammar
      : sor< 
        // opt< txtspacetxt >, opt< space >, 
        // txtspacetxt,
        // sor< oror, seq< seq< authorname::authornoyear, space >, oror > >,
        // oror,
        // opt< space >, opt< txtany >, 
        seq< plus< alpha >, space, oror, opt< txtany > >,
        seq< plus< alpha >, space, plus< alpha >, space, oror, opt< txtany > >,
        seq< plus< alpha >, space, rep_min_max< 0, 3, authur >, oror, opt< txtany > >,
        seq< plus< alpha >, space, plus< alpha >, space, rep_min_max< 0, 3, authur >, oror, opt< txtany > >,
        // txtany,
        // opt< txtany >,
        eof 
      >
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

  }  // namespace rank
} // namespace pegax

#endif
