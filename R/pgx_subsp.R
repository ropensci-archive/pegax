#' parse out subspecies ranks
#' 
#' @export
#' @param x character string 
#' @examples 
#' pgx_subsp("var")
#' pgx_subsp("var.")
#' pgx_subsp("subsp.")
#' pgx_subsp("ssp.")
#' pgx_subsp("ssp. ")
#' pgx_subsp(" var. ")
#' pgx_subsp(" var.")
#' pgx_subsp("var. ")
#' pgx_subsp("[var.]")
#' 
#' pgx_subsp(c("[var.]", "var.", "ssp"))
pgx_subsp <- function(x) {
  vapply(x, name_subsp, "", USE.NAMES = FALSE)
}
