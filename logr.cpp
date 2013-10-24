#include "logr.hpp"
#include <iostream>

namespace logr {
    inline const char* strofenum(LOG_LEVEL l) {
        switch(l) {
            case CATASTROPHE: return "CATASTROPHE";
            case ERROR: return "ERROR";
            case WARNING: return "WARNING";
            case INFO: return "INFO";
            case DEBUG0: return "DEBUG0";
            case DEBUG1: return "DEBUG1";
            case DEBUG2: return "DEBUG2";
            case DEBUG3: return "DEBUG3";
            default: return "LEVEL UNDEFINED";
        }
    }

    Logger::Logger(FLUSH_RULE f) : flush_rule(f), premsg_fn(&default_premsg_fn)
    {
    }

    std::ostringstream& Logger::get_writer(LOG_LEVEL level = INFO) {
        premsg_fn(data);
        return data;
    }

    void Logger::write() {
        /* flush buffered data to all output streams */
        for (std::vector<LogStream*>::iterator ls = out_streams.begin(); ls != out_streams.end(); ++ls) {
            const std::string msg(data.str());
            (*ls)->write(msg);
        }
        data.str("");
    }

    void Logger::set_premsg_fn(void (*fn)(std::ostringstream& s)) {
        premsg_fn = fn;
    }

    Logger::~Logger() {
        write();
    }

    void default_premsg_fn(std::ostringstream& s) {
        s << "|premsg|";
    }

    void LogStreamStdStream::write(const std::string& msg) {
        std::cout << msg << std::endl;
    }

    LogStream::LogStream(FLUSH_RULE flush_rule) : flush_rule(flush_rule) {
    }

    LogStreamStdStream::LogStreamStdStream(FLUSH_RULE flush_rule) :
        LogStream(flush_rule) {
    }
};
