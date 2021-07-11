//
// Created by Artem Vovchenko on 11.07.2021.
//

#ifndef LOGGING_MESSAGE_HANDLER_H
#define LOGGING_MESSAGE_HANDLER_H


#include <sstream>
#include <string>
#include <memory>
#include <utility>

#include "../include/Logger.h"
#include "../include/Types.h"
#include "../include/Abstract.h"

namespace Logging {

    class MessageHandler {
    private:
        std::stringstream messageBuilder;
        std::string prefix;
        std::string outStreamName;
        std::shared_ptr<ILogger> loggerReference;

        void generateLogMessageHeader(LogLevel logLevel = INFO);
        void commitCreatedMessage();

        using msgEndType = std::ostream&(std::ostream&);
    public:
        MessageHandler() = delete;

        MessageHandler(std::shared_ptr<ILogger> loggerReference, std::string prefix, std::string outStreamName) :
                loggerReference(std::move(loggerReference)),
                prefix(std::move(prefix)),
                outStreamName(std::move(outStreamName))
        {}

        MessageHandler(const MessageHandler &) noexcept;

        MessageHandler(MessageHandler &&) noexcept;

        MessageHandler& operator=(const MessageHandler &) noexcept;

        MessageHandler& operator=(MessageHandler &&) noexcept;

        MessageHandler& operator()(LogLevel);

        friend MessageHandler& operator<< (MessageHandler& handler, msgEndType endOperator) {
            handler.generateLogMessageHeader();
            handler.messageBuilder << endOperator;
            handler.commitCreatedMessage();
            return handler;
        }

        template<typename T>
        friend MessageHandler& operator<<(MessageHandler& handler, T message) {
            handler.generateLogMessageHeader();
            handler.messageBuilder << message;
            return handler;
        }
    };

}


#endif //LOGGING_MESSAGE_HANDLER_H
