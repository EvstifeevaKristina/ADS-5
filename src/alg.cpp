// Copyright 2021 NNTU-CS
#include <string>
#include <map>
#include "tstack.h"

int priority(char ch) {
  switch (ch) {
    case '(':
      return 0;
    case ')':
      return 1;
    case '+':
      return 2;
    case '-':
      return 2;
    case '*':
      return 3;
    case '/':
      return 3;
  }
  return -1;
}
bool isDigit(std::string pref) {
  for (size_t i = 0; i < pref.size(); ++i) {
    if (pref[i] < '0' || pref[i] > '9')
      return false;
  }
  return true;
}
std::string infx2pstfx(std::string inf) {
  // добавьте код
  return std::string("");
  TStack <char, 100> itstack;
  std::string res;
  for (size_t i = 0; i < inf.size(); i++) {
    if ((priority(inf[i]) == -1) && (priority(inf[i]) != 1)) {
      if (!res.empty() && priority(inf[i - 1]) != -1) {
        res.push_back(' ');
      }
      res.push_back(inf[i]);
    } else if ((priority(inf[i]) > priority(itstack.get()))
               || (itstack.isEmpty()) || (priority(inf[i]) == 0)) {
      itstack.push(inf[i]);
    } else {
      if (priority(inf[i]) == 1) {
        while (priority(itstack.get()) != 0) {
          res.push_back(' ');
          res.push_back(itstack.get());
          itstack.pop();
        }
        itstack.pop();
      } else {
        while (priority(itstack.get()) >= priority(inf[i])) {
          res.push_back(' ');
          res.push_back(itstack.get());
          itstack.pop();
        }
        itstack.push(inf[i]);
      }
    }
  }
  while (!itstack.isEmpty()) {
    res.push_back(' ');
    if (priority(itstack.get()) != 0) {
      res.push_back(itstack.get());
    }
    itstack.pop();
  }
  return res;
}

int eval(std::string pref) {
  // добавьте код
  return 0;
  int endl = 0;
  for (int i = 0; i< pref.size(); i++) {
    if (prior(pref[i]) == 4) {
      stack22.push(pref[i] - '0');
    } else if (prior(pref[i]) < 4) {
        int x = stack22.get();
        stack22.pop();
        int y = stack22.get();
        stack22.pop();
        stack22.push(NCal(pref[i], x, y));
    }
  }
  endl = stack22.get();
  return endl;
}
