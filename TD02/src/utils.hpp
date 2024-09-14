#include <Eigen/Dense>
#include <chrono>

// Fonction pour le calcul du produit matriciel
Eigen::MatrixXd matrix_product(const Eigen::MatrixXd &m1,
                               const Eigen::MatrixXd &m2);

// Fonction pour mesurer le temps d'exécution
template <typename Func>
double measure_time(Func f, const Eigen::MatrixXd &m1,
                    const Eigen::MatrixXd &m2, unsigned int iter) {
  Eigen::MatrixXd result = Eigen::MatrixXd::Zero(m1.rows(), m2.cols());
  auto start = std::chrono::steady_clock::now();
  for (unsigned int i = 0; i < iter; ++i) {
    result = f(m1, m2);
  }
  auto stop = std::chrono::steady_clock::now();
  std::chrono::duration<double> elapsed_seconds = stop - start;
  return elapsed_seconds.count();
}