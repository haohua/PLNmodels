// [[Rcpp::depends(RcppArmadillo)]]
#include <RcppArmadillo.h>

using namespace Rcpp;
using namespace arma;

//' @export
// [[Rcpp::export]]
Rcpp::List fn_optim_PLN_profiled_Cpp(const arma::vec par,
                                     const arma::mat Y,
                                     const arma::mat X,
                                     const arma::mat O,
                                     double KY) {

  int n = Y.n_rows, p = Y.n_cols, d = X.n_cols ;

  arma::mat Theta = par.subvec(0      , p*d      -1) ; Theta.reshape(p,d) ;
  arma::mat M     = par.subvec(p*d    , p*(n+d) - 1) ; M.reshape(n,p) ;
  arma::mat S     = par.subvec(p*(n+d), p*(2*n+d)-1) ; S.reshape(n,p) ;

  arma::mat Omega = n * inv_sympd(M.t()*M + diagmat(sum(S, 0)));
  arma::mat Z = O + X * Theta.t() + M;
  arma::mat A = exp (Z + .5 * S) ;

  double objective = accu(A - Y % Z - .5 * log(S)) - .5 * n*real(log_det(Omega)) + KY ;

  arma::vec grd_Theta = vectorise((A-Y).t() * X);
  arma::vec grd_M     = vectorise(M * Omega + A-Y) ;
  arma::vec grd_S     = vectorise(.5 * (ones(n) * diagvec(Omega).t() + A - 1/S));

  arma::vec grad = join_vert(join_vert(grd_Theta, grd_M),grd_S) ;

  return Rcpp::List::create(Rcpp::Named("objective") = objective,
                            Rcpp::Named("gradient" ) = grad);
}


// Rcpp::List fn_optim_PLN_Cpp(const arma::vec par,
//                             const arma::mat Y,
//                             const arma::mat X,
//                             const arma::mat O,
//                             double KY) {
//
//   int n = Y.n_rows, p = Y.n_cols, d = X.n_cols ;
//
//   arma::mat Theta = par.subvec(0        , p*d        -1) ; Theta.reshape(p,d) ;
//   arma::mat Omega = par.subvec(p*d      , p*(p+d)    -1) ; Omega.reshape(p,p) ;
//   arma::mat M     = par.subvec(p*(p+d)  , p*(p+d+n)  -1) ; M.reshape(n,p) ;
//   arma::mat S     = par.subvec(p*(p+d+n), p*(p+d+2*n)-1) ; S.reshape(n,p) ;
//
//   arma::mat S_bar(sum(S, 0)) ;
//   arma::mat MtM = M.t() * M ;
//   double log_detOmega = real(log_det(Omega)) ;
//
//   arma::mat Z = O + X * Theta.t() + M;
//   arma::mat A = exp (Z + .5 * S) ;
//
//   double logP_Z = .5 * (n * log_detOmega - dot(diagvec(Omega), S_bar) - trace(Omega * MtM))  ;
//   double objective = accu(A - Y % Z - .5 * log(S) - .5) - logP_Z + KY ;
//
//   arma::mat C = chol(Omega);
//   arma::mat OmegaInv = solve(trimatu(C), eye(p, p));
//
//   arma::vec grd_Theta = vectorise((A-Y).t() * X);
//   arma::vec grd_Omega = vectorise(.5*(MtM + diagmat(S_bar) - n*OmegaInv)) ;
//   arma::vec grd_M     = vectorise(A-Y + M * Omega) ;
//   arma::vec grd_S     = vectorise(.5 * (ones(n) * diagvec(Omega).t() + A - 1/S)) ;
//
//   arma::vec grad = join_vert(join_vert(grd_Theta, grd_Omega),join_vert(grd_M,grd_S)) ;
//
//   return Rcpp::List::create(Rcpp::Named("objective") = objective,
//                             Rcpp::Named("gradient" ) = grad);
// }
//
