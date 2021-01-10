//
// Created by evtus on 1/8/2021.
//

#ifndef CUDATUTOR_VEC_ADD_H
#define CUDATUTOR_VEC_ADD_H

#include "question.h"

class vec_add_question_t : public question_t
{
protected:
  const char *get_question_content () const final;

public:
  bool check_answer_implementation () const final;
};

void vec_add_reference_kernel_wrapper (
    const int n,
    const float *in_1,
    const float *in_2,
    float *out);

#endif // CUDATUTOR_VEC_ADD_H
