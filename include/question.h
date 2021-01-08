//
// Created by evtus on 1/8/2021.
//

#ifndef CUDATUTOR_QUESTION_H
#define CUDATUTOR_QUESTION_H

class question_t
{
private:
  bool write_question (const char *question_path) const;

protected:
  virtual const char *get_question_content () const = 0;
  virtual bool check_answer_implementation () const = 0;

public:
  bool ask_the_question () const;
  bool check_answer () const;
};

#endif // CUDATUTOR_QUESTION_H
