% Generated by roxygen2: do not edit by hand
% Please edit documentation in R/PLNLDAfit-class.R
\docType{data}
\name{PLNLDAfit}
\alias{PLNLDAfit}
\title{An R6 Class to represent a PLNfit in a LDA framework}
\format{An object of class \code{R6ClassGenerator} of length 24.}
\usage{
PLNLDAfit
}
\description{
The function \code{\link{PLNPCA}} produces a collection of models which are instances of object with class \code{PLNPCAfit}.

This class comes with a set of methods, some of them being useful for the user:
See the documentation for \code{\link[=PLNPCAfit_plot_PCA]{plot_PCA}}, \code{\link[=PLNPCAfit_plot_individual_map]{plot_individual_map}}
and \code{\link[=PLNPCAfit_plot_correlation_circle]{plot_correlation_circle}}
}
\section{Fields}{

\describe{
\item{\code{model_par}}{a list with the matrices associated with the estimated parameters of the pPCA model: Theta (covariates), Sigma (latent covariance) and B (latent loadings)}

\item{\code{var_par}}{a list with two matrices, M and S, which are the estimated parameters in the variational approximation}

\item{\code{loglik}}{variational lower bound of the loglikelihood}

\item{\code{BIC}}{variational lower bound of the BIC}

\item{\code{ICL}}{variational lower bound of the ICL}

\item{\code{R_squared}}{approximated goodness-of-fit criterion}

\item{\code{criteria}}{a vector with loglik, BIC, ICL, R_squared and degrees of freedom}

\item{\code{degrees_freedom}}{number of parameters in the current PLN model}

\item{\code{percent_var}}{the percent of variance explained by each axis}

\item{\code{corr_circle}}{a matrix of correlations to plot the correlation circles}

\item{\code{scores}}{a matrix of scores to plot the individual factor maps}
}}

\seealso{
The function \code{\link{PLNPCA}}, the class \code{\link[=PLNfamily]{PLNfamily}}
}
\keyword{datasets}