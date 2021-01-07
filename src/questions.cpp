//
// Created by evtus on 1/8/2021.
//

#include "questions.h"
#include "question.h"

questions_t &questions_t::get_instance ()
{
  static questions_t questions;
  return questions;
}

questions_t::questions_t () = default;
questions_t::~questions_t () = default;

const questions_t::container_t &questions_t::get_questions ()
{
  return questions;
}

bool questions_t::register_question (const std::string &name, std::unique_ptr<question_t> question)
{
  if (questions.count (name))
    return false;

  questions[name] = std::move (question);
  return true;
}
