//
// Created by Artem Vovchenko on 11.07.2021.
//

#ifndef LOGGING_LOGGER_H
#define LOGGING_LOGGER_H


#include <iostream>
#include <fstream>
#include <string>
#include <mutex>

#include "../include/Abstract.h"

namespace Logging {

    class Logger : public ILogger {
    private:
        Logger() = default;
        mutable std::mutex globalMutex;

    public:
        ~Logger() override = default;

        Logger(const Logger &) = delete;

        Logger(Logger &&) = delete;

        Logger &operator=(const Logger &) = delete;

        Logger &operator=(Logger &&) = delete;

        void commitMessage(const std::string &message, const std::string &outStreamName) const override;

        static std::shared_ptr<ILogger> getDefaultLoggerRef();
    };

}


#endif //LOGGING_LOGGER_H
