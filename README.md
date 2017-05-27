pegax
=====

[![Build Status](https://travis-ci.org/ropenscilabs/pegax.svg?branch=master)](https://travis-ci.org/ropenscilabs/pegax)

Taxonomy PEG (Parsing Expression Grammar) rules

## finally!

![img](inst/img/photo.png)

## E.g.

```
struct name
  : plus< alpha >
{};

struct numbers
  : plus< digit >
{};

struct grammar
  : must< name, one< ',' >, space, numbers, eof >
{};
```

## Install


```r
devtools::install_github("ropenscilabs/pegax")
```


```r
library("pegax")
```


## Parse authority

Author name


```r
authority_names("Linnaeus, 1758")
#> [1] "Linnaeus"
```

Author year


```r
authority_years("Linnaeus, 1758")
#> [1] "1758"
```

Moar


```r
x <- c('Smith, 1456', 'Foobarcheesestuff, 1001', 'Smith, 1987')
authority_names(x)
#> [1] "Smith"             "Foobarcheesestuff" "Smith"
authority_years(x)
#> [1] "1456" "1001" "1987"
```

## R DSL to make custom PEGS for taxonomy

```
pegax({
  plus(alpha)
  one(,)
  numbers(,)
  plus(-)
  space
  plus(????)
  plus(:cat2:)
})
```
