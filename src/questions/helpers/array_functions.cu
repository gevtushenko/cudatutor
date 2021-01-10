#include "questions/helpers/array_functions.h"

template <typename data_type>
__global__ void comparison_kernel (const int n, const data_type *in_1, const data_type *in_2, int *result)
{
  const int i = threadIdx.x + blockIdx.x * blockDim.x;

  if (i < n)
    if (in_1[i] != in_2[i])
      *result = 1;
}

template <typename data_type>
bool is_equal (const int n, const data_type *in_1, const data_type *in_2)
{
  int *device_flag {};
  cudaMalloc (&device_flag, sizeof (int));
  cudaMemset (device_flag, 0, sizeof (int));

  const int block_size = 128;
  const int grid_size = (n + block_size - 1) / block_size;

  comparison_kernel<<<grid_size, block_size>>> (n, in_1, in_2, device_flag);

  int host_flag {};
  cudaMemcpy (&host_flag, device_flag, sizeof (int), cudaMemcpyDeviceToHost);

  cudaFree (device_flag);

  return host_flag == 0;
}

#define IS_EQUAL_INSTANTIATION(TYPE) \
template bool is_equal<TYPE> (const int n, const TYPE *in_1, const TYPE *in_2)

IS_EQUAL_INSTANTIATION(float);
