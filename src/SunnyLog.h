#pragma once
#include <iostream>
#include <string>
#include <string_view>
#include <unordered_map>

enum LogLevel { ERROR, WARN, INFO, DEBUG, TRACE };

struct Colors {
    inline static constexpr std::string_view reset = "\033[0m";
    inline static constexpr std::string_view red = "\033[31m";
    inline static constexpr std::string_view green = "\033[32m";
    inline static constexpr std::string_view yellow = "\033[33m";
    inline static constexpr std::string_view blue = "\033[34m";
    inline static constexpr std::string_view magenta = "\033[35m";
    inline static constexpr std::string_view cyan = "\033[36m";
    inline static constexpr std::string_view white = "\033[37m";
    inline static constexpr std::string_view gray = "\033[90m";
};

class SunnyLog {
public:
    SunnyLog() = default;

    template <typename T>
    static void log(T msg) {
        std::cout << getLogTag(m_level) << msg;
    }

    template <typename T>
    static void log(T msg, LogLevel level) {
        std::cout << getLogTag(level) << msg;
    }

    static void setLevel(LogLevel level);

    static void warn();
    static void error();
    static void info(std::string_view info);
    static void debug();

private:
    static std::string getLogTag(LogLevel level);
    inline static LogLevel m_level = LogLevel::INFO;
};
