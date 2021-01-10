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
  bool check_answer () const final;
};

#endif // CUDATUTOR_VEC_ADD_H
