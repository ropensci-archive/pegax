#' Clean taxonomic names of symbols
#'
#' @export
#' @param x (character) one or more taxonomic names
#' @return names in a vector
#' @details doesn't use PEGs, just regular C++ 
#' @examples
#' pgx_symbols(x = "Ste>phanolaimus spartinae")
#' pgx_symbols("Ste*phanolaimus")
#' pgx_symbols("{Stephanolaimus spartinae}")
#' pgx_symbols("Stephanolaimus spartinae|%")
pgx_symbols <- function(x) {
  stopifnot(inherits(x, "character"))
  (x <- replace_specific_symbols(x))
  #scrub_names(x)
}
