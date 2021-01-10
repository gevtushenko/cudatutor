//

#include "questions/basics/vec_add.h"

#include "answer.h"

const char *vec_add_question_t::get_question_content () const
{
  return R"(
#include <boost/config.hpp> // for BOOST_SYMBOL_EXPORT

extern "C" BOOST_SYMBOL_EXPORT int run ()
{
return 42;
}
)";
}

__global__ void reference_kernel (
    const int n,
    const float *in_1,
    const float *in_2,
    float *out)
{
  const int i = threadIdx.x + blockIdx.x * blockDim.x;

  if (i < n)
    out[i] = in_1[i] + in_2[i];
}

bool vec_add_question_t::check_answer_implementation () const
{
  auto run = load_answer<int()> ("answer.so", "run");
  return run () == 42;
}
