//
// Created by egi on 1/10/21.
//

#ifndef CUDATUTOR_ARRAY_FUNCTIONS_H
#define CUDATUTOR_ARRAY_FUNCTIONS_H

#include <stdexcept>

inline void check (cudaError_t status)
{
  if (status != cudaSuccess)
    throw std::runtime_error (cudaGetErrorString (status));
}

template <typename data_type>
bool is_equal (const int n, const data_type *in_1, const data_type *in_2);

#endif // CUDATUTOR_ARRAY_FUNCTIONS_H
