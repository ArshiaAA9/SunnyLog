#include "SunnyLog.h"

#include <format>
#include <iostream>
#include <string_view>

void SunnyLog::setLevel(LogLevel level) { m_level = level; }

void SunnyLog::info(std::string_view info) {
    std::cout << Colors::yellow << "[WARN] " << Colors::reset << info << '\n';
}

std::string SunnyLog::getLogTag(LogLevel level) {
    switch (level) {
        case LogLevel::INFO:
            return std::format("{} [INFO]  {}", Colors::green, Colors::reset);
        case LogLevel::TRACE:
            return std::format("{} [TRACE] {}", Colors::green, Colors::reset);
        case LogLevel::DEBUG:
            return std::format("{} [DEBUG] {}", Colors::green, Colors::reset);
        case LogLevel::WARN:
            return std::format("{} [WARN]  {}", Colors::yellow, Colors::reset);
        case LogLevel::ERROR:
            return std::format("{} [ERROR] {}", Colors::red, Colors::reset);
    }
    return std::format("{} [UNKNOWN] {}", Colors::gray, Colors::reset);
}
