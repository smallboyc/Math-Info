#include "utils.hpp"
#include <Eigen/Dense>
#include <chrono>
#include <iostream>

// Matrices de permutation
// La permutation s'effectue en changeant l'odre des éléments de la matrice
// identité (Id). La matrice Id est forcément carré.

// Si P est une matrice de permutation et A une matrice de même dimension que P
//  P*A (permute sur les lignes) != A*P (permute sur les colonnes)

// Exemple : Matrice 4x4 de permutation sur les lignes/colonnes 2 et 4
// (dépend de l'ordre de multiplication)
//  1 0 0 0
//  0 0 0 1
//  0 0 1 0
//  0 1 0 0

void matrix_display(const Eigen::MatrixXd &m) {
  for (int i = 0; i < m.cols(); i++) {
    for (int j = 0; j < m.cols(); j++)
      std::cout << m(i, j) << " ";
    std::cout << "\n";
  }
}

int main() {
  unsigned int seed =
      std::chrono::system_clock::now().time_since_epoch().count();
  srand(seed);

  Eigen::MatrixXd my_matrix(4, 4);
  my_matrix << 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15;

  // MOI
  Eigen::MatrixXd permutation_matrix(4, 4);
  permutation_matrix << 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0;

  std::cout << "Ma matrice : " << "\n";
  matrix_display(my_matrix);
  std::cout << "\n";

  std::cout << "Permutation sur les lignes 2 & 4" << "\n";
  Eigen::MatrixXd line_permutation_matrix =
      matrix_product(permutation_matrix, my_matrix);
  matrix_display(line_permutation_matrix);
  std::cout << "\n";

  std::cout << "Permutation sur les colonnes 2 & 4" << "\n";
  Eigen::MatrixXd column_permutation_matrix =
      matrix_product(permutation_matrix, my_matrix);
  matrix_display(column_permutation_matrix);
  std::cout << "\n";

  // EIGEN
  Eigen::PermutationMatrix<4, 4> eigen_permutation_matrix;
  eigen_permutation_matrix.indices() = {0, 3, 2, 1};
  matrix_display(my_matrix * eigen_permutation_matrix);
  std::cout << "\n";

  return 0;
}
