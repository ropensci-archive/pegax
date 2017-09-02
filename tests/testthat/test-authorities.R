context("authority_names")

test_that("authority_names works as expected", {
  aa <- pgx_authority_names("Linnaeus, 1758")
  
  expect_is(aa, 'character')
  expect_equal(aa, 'Linnaeus, ')
})

context("authority_years")
test_that("authority_years works", {
  aa <- pgx_authority_years("Linnaeus, 1758")
  
  expect_is(aa, 'character')
  expect_equal(aa, '1758')
})
