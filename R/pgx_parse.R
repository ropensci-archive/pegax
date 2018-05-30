#' parse complete names
#'
#' @export
#' @param x scientific name character string
#' @examples
#' pgx_parse("Linnaeus")
#' pgx_parse("(Linnaeus)")
#' pgx_parse("Linnaeus 1789")
#' pgx_parse("Helianthus annuus L.")
#' \dontrun{
#' # needs a name
#' pgx_parse("1789")
#' }
pgx_parse <- function(x) {
  stopifnot(inherits(x, "character"))
  parse_name(x)
  # vapply(x, authority_name, "", USE.NAMES = FALSE)
}
