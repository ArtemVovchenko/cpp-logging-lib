//
// Created by Artem Vovchenko on 11.07.2021.
//

#ifndef LOGGING_LOG_H
#define LOGGING_LOG_H

#include <string>
#include "../include/MessageHandler.h"

namespace Logging {
    MessageHandler getLogger();
    MessageHandler getLogger(const std::string&);
    MessageHandler getLogger(const std::string&, const std::string&);
}

#endif //LOGGING_LOG_H
