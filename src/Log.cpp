//
// Created by Artem Vovchenko on 11.07.2021.
//

#include "../include/Log.h"

namespace Logging {

    MessageHandler getLogger() {
        return MessageHandler(Logger::getDefaultLoggerRef(), "", "");
    }

    MessageHandler getLogger(const std::string& outStreamName) {
        return MessageHandler(Logger::getDefaultLoggerRef(), "", outStreamName);
    }

    MessageHandler getLogger(const std::string& outStreamName, const std::string& prefix) {
        return MessageHandler(Logger::getDefaultLoggerRef(), prefix, outStreamName);
    }

}