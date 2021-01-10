//

__global__ void vec_add_reference_kernel (
    const int n,
    const float *in_1,
    const float *in_2,
    float *out)
{
  const int i = threadIdx.x + blockIdx.x * blockDim.x;

  if (i < n)
    out[i] = in_1[i] + in_2[i];
}

void vec_add_reference_kernel_wrapper (
    const int n,
    const float *in_1,
    const float *in_2,
    float *out)
{
  const int block_size = 128;
  const int grid_size = (n + block_size - 1) / block_size;

  vec_add_reference_kernel<<<block_size, grid_size>>> (n, in_1, in_2, out);
}
