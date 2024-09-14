#include "utils.hpp"
#include <Eigen/Dense>
#include <chrono>
#include <iostream>

int main() {
  unsigned int seed =
      std::chrono::system_clock::now().time_since_epoch().count();
  srand(seed);

  // Produit matriciel
  Eigen::MatrixXd M_1 = Eigen::MatrixXd::Random(512, 512);
  Eigen::MatrixXd M_2 = Eigen::MatrixXd::Random(512, 512);
  const unsigned int iter = 2;

  // Calcul du temps pour Eigen
  double time_eigen =
      measure_time([](const Eigen::MatrixXd &m1,
                      const Eigen::MatrixXd &m2) { return m1 * m2; },
                   M_1, M_2, iter);
  std::cout << "temps calcul du produit matricielle (EIGEN)  : " << time_eigen
            << " s" << std::endl;

  // Calcul du temps pour ma fonction
  double time_mine = measure_time(matrix_product, M_1, M_2, iter);
  std::cout << "temps calcul du produit matricielle (MOI) : " << time_mine
            << " s" << std::endl;

  return 0;
}
