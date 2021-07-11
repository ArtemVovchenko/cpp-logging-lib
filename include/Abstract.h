//
// Created by Artem Vovchenko on 11.07.2021.
//

#ifndef LOGGING_ABSTRACT_H
#define LOGGING_ABSTRACT_H

class ILogger {
public:
    virtual void commitMessage(const std::string &message, const std::string &outStreamName) const = 0;

    virtual ~ILogger() = default;
};

#endif //LOGGING_ABSTRACT_H
