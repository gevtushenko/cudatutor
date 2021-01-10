//

#include "questions/basics/mem_copy.h"

__global__ void reference_kernel (
    const int n,
    const float *in,
    float *out)
{
  const int i = threadIdx.x + blockIdx.x * blockDim.x;

  if (i < n)
    out[i] = in[i];
}

void mem_copy_kernel_wrapper (const int n, const float *in, float *out)
{
  const int block_size = 128;
  const int grid_size = (n + block_size - 1) / block_size;

  reference_kernel<<<grid_size, block_size>>> (n, in, out);
}
