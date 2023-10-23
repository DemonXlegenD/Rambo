#include "Error.h"

void Error::RaiseRuntimeError(const std::string& message) {
    throw std::runtime_error(message);
}

void Error::RaiseOutOfRangeError(const std::string& message) {
    throw std::out_of_range(message);
}

void Error::RaiseLogicError(const std::string& message) {
    throw std::logic_error(message);
}

void Error::RaiseDomainError(const std::string& message) {
    throw std::domain_error(message);
}

void Error::RaiseInvalidArgument(const std::string& message) {
    throw std::invalid_argument(message);
}

void Error::RaiseLengthError(const std::string& message) {
    throw std::length_error(message);
}

void Error::RaiseRangeError(const std::string& message) {
    throw std::range_error(message);
}

void Error::RaiseOverflowError(const std::string& message) {
    throw std::overflow_error(message);
}

void Error::RaiseUnderflowError(const std::string& message) {
    throw std::underflow_error(message);
}

void Error::RaiseSystemError(const std::string& message) {
    //throw std::system_error(std::make_error_code(std::errc::io_error), message);
}

void Error::RaiseFutureError(const std::string& message) {
    //throw std::future_error(std::future_errc::broken_promise, message);
}
