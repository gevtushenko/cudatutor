//
// Created by evtus on 1/8/2021.
//

#ifndef CUDATUTOR_QUESTIONS_H
#define CUDATUTOR_QUESTIONS_H

#include <memory>
#include <vector>

class question_t;

class questions_t
{
public:
  using container_t = std::vector<std::unique_ptr<question_t>>;

  questions_t ();
  ~questions_t ();

  const container_t &get_questions ();

private:

  container_t questions;
};

#endif // CUDATUTOR_QUESTIONS_H
