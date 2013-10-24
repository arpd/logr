#ifndef LOGGER_H
#define LOGGER_H
#include <sstream>
#include <vector>

namespace logr {
    enum LOG_LEVEL { CATASTROPHE, ERROR, WARNING, INFO,
                       DEBUG0, DEBUG1, DEBUG2, DEBUG3 };
    enum FLUSH_RULE { ON_WRITE, ON_WRITE_N, ON_DESTRUCT };
    inline const char* strofenum(LOG_LEVEL l);
    void default_premsg_fn(std::ostringstream& s);

    class LogStream {
    public:
        LogStream(FLUSH_RULE flush_rule);
        virtual void write(const std::string& msg) =0;
    protected:
        FLUSH_RULE flush_rule;
    };

    class LogStreamStdStream : public LogStream {
    public:
        LogStreamStdStream(FLUSH_RULE);
        virtual void write(const std::string& msg);
    };

    class Logger {
    public:
        Logger(FLUSH_RULE f = ON_DESTRUCT);
        virtual ~Logger();
        std::ostringstream& get_writer(LOG_LEVEL level);
        template <typename _StreamTypeT>
        void add_output_stream(_StreamTypeT* t);
        template <typename _StreamTypeT>
        void add_output_stream(_StreamTypeT t);
        void set_premsg_fn(void (*fn)(std::ostringstream& s));
    private:
        Logger(const Logger&);
        Logger& operator=(const Logger&);
        inline void write();
        void (*premsg_fn)(std::ostringstream& s);
    protected:
        const FLUSH_RULE flush_rule;
        std::ostringstream data;
        std::vector<LogStream*> out_streams;
    };

    template <typename _StreamTypeT>
    void Logger::add_output_stream(_StreamTypeT* t) {
        out_streams.push_back(t);
    }

    template <typename _StreamTypeT>
    void Logger::add_output_stream(_StreamTypeT t) {
        //out_streams.push_back(t);
    }
};
#endif
