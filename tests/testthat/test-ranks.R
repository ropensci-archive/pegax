context("ranks")

test_that("pgx_ranks works as expected", {
  aa <- pgx_ranks("Helianthus annuus var. annuus")
  bb <- pgx_ranks("Helianthus annuus ssp. annuus")

  expect_is(aa, 'character')
  expect_is(bb, 'character')
  
  expect_equal(aa, 'var.')
  expect_equal(bb, 'ssp.')
})

test_that("pgx_ranks accepts many inputs", {
  aa <- pgx_ranks(c("Helianthus annuus var. annuus", 
                     "Helianthus annuus ssp. annuus", "Caulerpa cupressoides forma nuda"))
  expect_is(aa, 'character')
  expect_equal(aa, c("var.", "ssp.", "forma"))
})

# using spec json
test_that("pgx_ranks passes json spec", {
  # FIXME: these should all eventually match successfully
  #  for now, those patterns that aren't working we just return empty string: ""
  
  library(jsonlite)
  # json <- jsonlite::fromJSON("tests/testthat/rank_spec.json", FALSE)
  json <- jsonlite::fromJSON("rank_spec.json", FALSE)
  json <- unlist(lapply(json, "[[", "entries"), FALSE)
  for (i in seq_along(json)) {
    # cat(paste0("doing: ", i, " taxon: ", json[[i]]$name), sep = "\n")
    expect_equal(pgx_ranks(json[[i]]$name), json[[i]]$rank_out)
  }
})

test_that("pgx_ranks doesn't work with authorities with trailing dots", {
  nms <- c("Aus bus Linn. var. bus", "Poa annua fovaria", 
           "Polyrhachis orsyllus natmusculus Forel 1901", 
           "Polypodium pectinatum (L.) f. typica Rosenst.", 
           "Prunus mexicana S. Watson var. reticulata", 
           "Armeria (Mill.) Willd. fma. originaria Bern.", 
           "Armeria maaritima (Mill.) Willd. fma. originaria Bern.")
  for (i in seq_along(nms)) {
    expect_equal(pgx_ranks(nms[[i]]), "")
  }
})

# for (i in seq_along(json)) {
#   cat("\n")
#   cat(paste0("doing: ", i, " taxon: ", json[[i]]$name), sep = "\n")
#   cat(pgx_ranks(json[[i]]$name), sep = "\n")
# }
