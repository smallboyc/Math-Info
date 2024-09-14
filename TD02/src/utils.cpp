#include <Eigen/Dense>
#include "utils.hpp"

// Fonction pour le calcul du produit matriciel
Eigen::MatrixXd matrix_product(const Eigen::MatrixXd &m1,
                               const Eigen::MatrixXd &m2) {
  Eigen::MatrixXd result = Eigen::MatrixXd::Zero(m1.rows(), m2.cols());
  for (int i = 0; i < m1.rows(); i++)
    for (int j = 0; j < m2.cols(); j++)
      for (int k = 0; k < m1.cols(); k++) {
        result(i, j) += m1(i, k) * m2(k, j);
      }
  return result;
}