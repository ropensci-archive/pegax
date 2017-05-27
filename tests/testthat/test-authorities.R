context("authority_names")

test_that("authority_names works as expected", {
  aa <- authority_names("Linnaeus, 1758")
  
  expect_is(aa, 'character')
  expect_equal(aa, 'Linnaeus')
})

context("authority_years")
test_that("authority_years works", {
  aa <- authority_years("Linnaeus, 1758")
  
  expect_is(aa, 'character')
  expect_equal(aa, '1758')
})
