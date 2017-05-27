#' authority parsing
#' 
#' @export
#' @name authorities
#' @param x character string of form: `<author>, <year>`
#' @examples 
#' authority_names("Linnaeus, 1758")
#' authority_years("Linnaeus, 1758")
#' 
#' x <- c('Arrhenatherum elatius var. elatius',
#'            'Secale cereale subsp. cereale', 'Secale cereale ssp. cereale',
#'            'Vanessa atalanta (Linnaeus, 1758)')
#'            
#' x <- c('Smith, 1456', 'Foobarcheesestuff, 1001', 'Smith, 1987')
#' authority_names(x)
#' authority_years(x)

#' @export
#' @rdname authorities
authority_names <- function(x) {
  vapply(x, authority_name, "", USE.NAMES = FALSE)
}

#' @export
#' @rdname authorities
authority_years <- function(x) {
  vapply(x, authority_year, "", USE.NAMES = FALSE)
}
