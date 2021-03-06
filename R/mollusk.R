##' Mollusk data set
##'
##' This data set gives the abundance of 32 mollusk species in 163 samples.
##' For each sample, 4 additional informations (covariates) are knowne.
##'
##' @format A list with 2 two data frames:
##' \describe{
##'   \item{Abundance}{a 163 x 32 data frame of abundancies/counts (163 samples and 32 mollusk species)}
##'   \item{Covariate}{a 163 x 4 data frame of covariates:
##'   \describe{
##'     \item{site}{a factor with 8 levels indicating the sampling site}
##'     \item{season}{a factor with 4 levels indicating the season}
##'     \item{method}{a factor with 2 levels for the method of sampling - wood or string}
##'     \item{duration}{a numeric with 3 levels for the time of exposure in week}
##'   }
##'   }
##' }
##'
##' In order to prepare the data for using formula in multivariate analysis (multiple outputs and inputs), use \code{\link[=prepare_data]{prepare_data}}.
##' Original data set has been extracted from ade4.
##'
##' @seealso \code{\link[=prepare_data]{prepare_data}}
##' @references Richardot-Coulet, M., Chessel D. and Bournaud M. (1986) Typological value of the benthos of old beds of a large river. Methodological approach. Archiv fùr Hydrobiologie, 107, 363–383.
#' @examples
#' data(mollusk)
#' mollusc <- prepare_data(mollusk$Abundance, mollusk$Covariate)
##' @source Data from Richardot-Coulet, Chessel and Bournaud.
"mollusk"

