//
// Created by Artem Vovchenko on 11.07.2021.
//

#include "../include/Logger.h"

namespace Logging {

    void Logger::commitMessage(const std::string &message, const std::string &outStreamName) const {
        if (outStreamName.empty()) {
            std::lock_guard<std::mutex> guard(globalMutex);
            std::cout << message;
        } else {
            std::lock_guard<std::mutex> guard(globalMutex);
            std::ofstream outstream(outStreamName, std::ios::app);
            outstream << message;
            outstream.close();
        }
    }

    std::shared_ptr<ILogger> Logger::getDefaultLoggerRef() {
        static auto ref = std::shared_ptr<ILogger>(new Logger());
        return ref;
    }
}
