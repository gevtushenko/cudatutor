//
// Created by evtus on 1/8/2021.
//

#ifndef CUDATUTOR_MEM_COPY_01_H
#define CUDATUTOR_MEM_COPY_01_H

#include "question.h"

class mem_copy_02_question_t : public question_t
{
protected:
  const char *get_question_content () const final;

public:
  bool check_answer_implementation () const final;
};

void mem_copy_02_kernel_wrapper (
    const int n,
    const float *in,
    float *out);

#endif // CUDATUTOR_MEM_COPY_01_H
