//
// Created by evtus on 1/8/2021.
//

#include "questions.h"
#include "question.h"

#include "questions/vec_add.h"

questions_t::questions_t ()
{
  questions.push_back (std::make_unique<vec_add_question_t> ());
}

questions_t::~questions_t () = default;

const questions_t::container_t &questions_t::get_questions ()
{
  return questions;
}
