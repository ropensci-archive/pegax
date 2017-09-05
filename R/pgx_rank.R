#' parse out rank names
#'
#' @export
#' @param x character string
#' @examples
#' pgx_ranks("var")
#' pgx_ranks("var.")
#' pgx_ranks("subsp.")
#' pgx_ranks("ssp.")
#' pgx_ranks("ssp. ")
#' pgx_ranks(" var. ")
#' pgx_ranks(" var.")
#' pgx_ranks("var. ")
#' pgx_ranks("[var.]")
#'
#' pgx_ranks(c("[var.]", "var.", "ssp"))
pgx_ranks <- function(x) {
  vapply(x, rank_name, "", USE.NAMES = FALSE)
}
