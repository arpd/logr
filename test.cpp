#include <iostream>
#include "logr.hpp"

using namespace std;

int main() {
    logr::Logger l;//(logr::FLUSH_RULE::);
    logr::LogStreamStdStream* out_strm = new logr::LogStreamStdStream(
            logr::FLUSH_RULE::ON_DESTRUCT);
    l.add_output_stream<logr::LogStreamStdStream>(out_strm);
    l.get_writer(logr::LOG_LEVEL::INFO) << "info msg" << endl;
    l.get_writer(logr::LOG_LEVEL::INFO) << "info msg" << endl;
    l.get_writer(logr::LOG_LEVEL::INFO) << "info msg" << endl;
    l.get_writer(logr::LOG_LEVEL::INFO) << "info msg" << endl;
    l.get_writer(logr::LOG_LEVEL::INFO) << "info msg" << endl;
    l.get_writer(logr::LOG_LEVEL::INFO) << "info msg" << endl;
    l.get_writer(logr::LOG_LEVEL::INFO) << "info msg" << endl;
    delete out_strm;
    return 0;
}
