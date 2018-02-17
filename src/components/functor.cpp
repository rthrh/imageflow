#include <functional>
#include <iostream>
#include <memory>
#include <tuple>
#include <utility>

// TODO: remove unnecessary headers so it can include from std

template <typename returnType, typename... Args>
class Functor {
 public:
  Functor(returnType, Args... args);
  returnType execute(Args... args);

 private:
  Functor();
  std::function<returnType(Args...)> foo;
};
