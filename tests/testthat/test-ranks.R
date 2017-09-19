context("ranks")

test_that("pgx_ranks works as expected", {
  aa <- pgx_ranks("Helianthus annuus var. annuus")
  bb <- pgx_ranks("Helianthus annuus ssp. annuus")

  expect_is(aa, 'character')
  expect_is(bb, 'character')
  
  expect_equal(aa, 'var')
  expect_equal(bb, 'ssp')
})

test_that("pgx_ranks accepts many inputs", {
  aa <- pgx_ranks(c("Helianthus annuus var. annuus", 
                     "Helianthus annuus ssp. annuus", "Caulerpa cupressoides forma nuda"))
  expect_is(aa, 'character')
  expect_equal(aa, c("var", "ssp", "forma"))
})
