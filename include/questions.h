//
// Created by evtus on 1/8/2021.
//

#ifndef CUDATUTOR_QUESTIONS_H
#define CUDATUTOR_QUESTIONS_H

#include <memory>
#include <unordered_map>

class question_t;

class questions_t
{
public:
  using container_t = std::unordered_map<std::string, std::unique_ptr<question_t>>;

  questions_t ();
  ~questions_t ();

  static questions_t &get_instance ();

  const container_t &get_questions ();

  bool register_question (const std::string &name, std::unique_ptr<question_t> question);

private:

  container_t questions;
};

#endif // CUDATUTOR_QUESTIONS_H
