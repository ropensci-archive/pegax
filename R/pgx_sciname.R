#' scientific name parsing
#'
#' these functions only parse names alone - not intended to parse
#' full names with authorities, etc.
#'
#' @export
#' @param x character string of any of the forms: 
#' `<genus>`, `<genus> <epithet>`, `<genus> <epithet> <rank> <subtaxon>`, etc. 
#' @examples
#' # single name, higher level taxon
#' pgx_sciname("Poaceae")
#' 
#' # single name, genus
#' pgx_sciname("Helianthus")
#' pgx_sciname("Helianthus ")
#' 
#' # two names, genus and epithet
#' pgx_sciname("Helianthus annuus")
#' pgx_sciname("Helianthus  annuus")
#' pgx_sciname("Helianthus  annuus ")
#' 
#' # genus, epithet, rank, and infraspecific epithet
#' pgx_sciname("Helianthus annuus var texanus")
#' pgx_sciname("Helianthus annuus var. texanus")
#' 
#' # unknown epithet variations
#' pgx_sciname("Helianthus sp.")
#' pgx_sciname("Helianthus sp")
#' pgx_sciname("Alyxia reinwardti ssp")
#' pgx_sciname("Helianthus spp.")
#' pgx_sciname("Helianthus spp")
#' pgx_sciname("Acarinina aff. pentacamerata")
pgx_sciname <- function(x) {
  stopifnot(inherits(x, "character"))
  sci_name(x)
  # vapply(x, authority_name, "", USE.NAMES = FALSE)
}
