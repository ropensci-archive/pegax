#' parse out rank names
#'
#' @export
#' @param x (character) one or more taxonomic names
#' @return the ranks, length equal to lentgh of input vector (empty 
#' character stirng `""` if no match)
#' @examples
#' pgx_ranks("Helianthus annuus var. annuus") # => var.
#' pgx_ranks("Helianthus annuus ssp. annuus") # => ssp.
#' pgx_ranks("Helianthus annuus ssp.") # => ssp.
#' 
#' pgx_ranks("Fagus sylvatica subsp. orientalis")
#' pgx_ranks("Fagus sylvatica subsp. orientalis (Lipsky) Greuter & Burdet")
#' pgx_ranks("Potamogeton iilinoensis var. ventanicola")
#' pgx_ranks("Potamogeton iilinoensis var. ventanicola (Hicken) Horn af Rantzien")
#' pgx_ranks("Triticum repens var. vulgäre")
#' # pgx_ranks("Aus bus Linn. var. bus")
#' pgx_ranks("Callideriphus flavicollis morph. reductus Fuchs 1961")
#' pgx_ranks("Caulerpa cupressoides forma nuda")
#' pgx_ranks("Chlorocyperus glaber form. fasciculariforme (Lojac.) Soó")
#' pgx_ranks("Polypodium vulgare nothosubsp. mantoniae (Rothm.) Schidlay")
#' pgx_ranks("Prunus armeniaca convar. budae (Pénzes) Soó")
#' # pgx_ranks("Polypodium pectinatum (L.) f. typica Rosenst.")
#' pgx_ranks("Poa annua fo varia")
#' pgx_ranks("Polyrhachis orsyllus nat musculus Forel 1901")
#' pgx_ranks("Xenodon sp.")
#' pgx_ranks("Acarinina aff. pentacamerata")
#' pgx_ranks("Lacanobia nr. subjuncta Bold:Aab, 0925")
#' pgx_ranks("Calidris cf. cooperi")
#' 
#' # many at once
#' pgx_ranks(c("Helianthus annuus var. annuus", 
#'   "Helianthus annuus ssp. annuus", "Caulerpa cupressoides forma nuda"))
#' 
pgx_ranks <- function(x) {
  stopifnot(inherits(x, "character"))
  rank_names(x)
}

# pgx_ranks <- function(x) {
#   vapply(x, rank_name, "", USE.NAMES = FALSE)
# }
