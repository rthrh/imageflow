#include <iostream>
#include <functional>
#include <utility>
#include <tuple>
#include <memory>

//TODO: remove unnecessary headers so it can include from std



template<typename returnType, typename... Args>
class Functor
{
    public:
        Functor(returnType, Args... args);
        returnType execute(Args... args);

    private:
        Functor();
        std::function<returnType(Args...)> foo;
};
