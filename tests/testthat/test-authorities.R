context("authority_names")

test_that("authority_names works as expected", {
  aa <- pgx_authority_names("Linnaeus, 1758")
  
  expect_is(aa, 'character')
  expect_equal(aa, 'Linnaeus')
})

context("authority_years")
test_that("authority_years works", {
  aa <- pgx_authority_years("Linnaeus, 1758")
  expect_is(aa, 'character')
  expect_equal(aa, '1758')
  
  bb <- pgx_authority_years("(Linnaeus, 1758)")
  expect_is(bb, 'character')
  expect_equal(bb, '1758')
  
  cc <- pgx_authority_years("Linnaeus ( 2014)")
  expect_is(cc, 'character')
  expect_equal(cc, '( 2014)')
  
  dd <- pgx_authority_years("Linnaeus 2014?")
  expect_is(dd, 'character')
  expect_equal(dd, '2014?')
})
