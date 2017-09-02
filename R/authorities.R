#' authority parsing
#'
#' these functions only parse authorities alone - not intended to parse
#' authorities from whole taxonomic names that include authorities
#'
#' @export
#' @name authorities
#' @param x character string of form: `<author>, <year>`
#' @examples
#' pgx_authority_names("Linnaeus, 1758")
#' pgx_authority_names("(Linnaeus, 1758)")
#'
#' \dontrun{
#' # fails on space
#' pgx_authority_names("(Linnaeus 1758)")
#'
#' # fails on numbers
#' pgx_authority_names("Arahal et al., 2001")
#' pgx_authority_names("(Torno, Tomo and Marschoff, 1977)")
#' pgx_authority_names("Forster")
#' pgx_authority_names("(Pursh) Elliott")
#' pgx_authority_names("(Scribn.) Soreng")
#'
#' # fails on name3
#' pgx_authority_names("(J. Sm.) Ching")
#' pgx_authority_names("(A. Gray) A. Nelson ex B.L. Rob.")
#' pgx_authority_names("C. W. Hart, 1971")
#' }
#'
#' pgx_authority_years("Linnaeus, 1758")
#' # pgx_authority_years("(Linnaeus, 1758)")
#' # pgx_authority_years("(Linnaeus 1758)")
#'
#' x <- c('Smith, 1456', 'Foobarcheesestuff, 1001', 'Smith, 1987')
#' pgx_authority_names(x)
#' pgx_authority_years(x)
#'
#' # with sample data
#' # plyr::llply(pg_authorities, pgx_authority_names, .inform = TRUE)
#' pgx_authority_names(pg_authorities[4])
#' # pgx_authority_years(pg_authorities)
#'
#' \dontrun{
#' # these not intended to work here, but in sep function for whole names
#' x <- c('Arrhenatherum elatius var. elatius',
#'            'Secale cereale subsp. cereale', 'Secale cereale ssp. cereale',
#'            'Vanessa atalanta (Linnaeus, 1758)')
#' }

#' @export
#' @rdname authorities
pgx_authority_names <- function(x) {
  vapply(x, authority_name, "", USE.NAMES = FALSE)
}

#' @export
#' @rdname authorities
pgx_authority_years <- function(x) {
  vapply(x, authority_year, "", USE.NAMES = FALSE)
}
