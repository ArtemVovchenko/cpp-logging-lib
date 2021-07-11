//
// Created by Artem Vovchenko on 11.07.2021.
//

#include <sstream>
#include <string>
#include <memory>
#include <utility>
#include <thread>

#include "../include/MessageHandler.h"

static std::string currentTime() {
    // TODO: Add seconds
    auto now = std::chrono::system_clock::now();
    auto itt = std::chrono::system_clock::to_time_t(now);
    std::ostringstream ss;
    ss << std::put_time(gmtime(&itt), "%d.%m.%y %T");
    return ss.str();
}

namespace Logging {

    // Constructors
    MessageHandler::MessageHandler(const MessageHandler& other) noexcept {
        messageBuilder << other.messageBuilder.str();
        prefix = other.prefix;
        outStreamName = other.outStreamName;
        loggerReference = other.loggerReference;
    }

    MessageHandler::MessageHandler(MessageHandler&& other) noexcept {
        std::swap(messageBuilder, other.messageBuilder);
        std::swap(prefix, other.prefix);
        std::swap(outStreamName, other.outStreamName);
        std::swap(loggerReference, other.loggerReference);
    }

    MessageHandler& MessageHandler::operator=(const MessageHandler& other) noexcept {
        if (this != &other) {
            messageBuilder << other.messageBuilder.str();
            prefix = other.prefix;
            outStreamName = other.outStreamName;
            loggerReference = other.loggerReference;
        }
        return *this;
    }

    MessageHandler& MessageHandler::operator=(MessageHandler&& other) noexcept {
        if (this != &other) {
            std::swap(messageBuilder, other.messageBuilder);
            std::swap(prefix, other.prefix);
            std::swap(outStreamName, other.outStreamName);
            std::swap(loggerReference, other.loggerReference);
        }
        return *this;
    }

    // Workflow methods
    void MessageHandler::generateLogMessageHeader(LogLevel logLevel) {
        if (!messageBuilder.str().empty()) return;
        messageBuilder << currentTime() << "; ";
        switch (logLevel) {
            case INFO:
                messageBuilder << "INFO; ";
                break;
            case DEBUG:
                messageBuilder << "DEBUG; ";
                break;
            case WARNING:
                messageBuilder << "WARNING; ";
                break;
            case ERROR:
                messageBuilder << "ERROR; ";
                break;
            default:
                messageBuilder << "INFO; ";
                break;
        }
        messageBuilder << prefix << "(" << std::hash<std::thread::id>{}(std::this_thread::get_id()) << "): ";
    }

    void MessageHandler::commitCreatedMessage() {
        loggerReference->commitMessage(messageBuilder.str(), outStreamName);
        messageBuilder.str("");
    }

    MessageHandler &MessageHandler::operator()(LogLevel logLevel) {
        generateLogMessageHeader(logLevel);
        return *this;
    }

}
