#pragma once
#include <stdexcept>
#include <string>

class Error {
public:
    static void RaiseRuntimeError(const std::string& message);
    static void RaiseOutOfRangeError(const std::string& message);
    static void RaiseLogicError(const std::string& message);
    static void RaiseDomainError(const std::string& message);
    static void RaiseInvalidArgument(const std::string& message);
    static void RaiseLengthError(const std::string& message);
    static void RaiseRangeError(const std::string& message);
    static void RaiseOverflowError(const std::string& message);
    static void RaiseUnderflowError(const std::string& message);
    static void RaiseSystemError(const std::string& message);
    static void RaiseFutureError(const std::string& message);

private:
    Error();
};

