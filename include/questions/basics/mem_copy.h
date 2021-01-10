//
// Created by evtus on 1/8/2021.
//

#ifndef CUDATUTOR_MEM_COPY_H
#define CUDATUTOR_MEM_COPY_H

#include "question.h"

class mem_copy_question_t : public question_t
{
protected:
  const char *get_question_content () const final;

public:
  bool check_answer () const final;
};

#endif // CUDATUTOR_MEM_COPY_H
