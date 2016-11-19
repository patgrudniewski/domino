/**
 * @author Patryk Grudniewski <patgrudniewski@gmail.com>
 */
#ifndef EXCEPTION_BOARDPOSITIONNOTEMPTYEXCEPTION_H
#define EXCEPTION_BOARDPOSITIONNOTEMPTYEXCEPTION_H

#include <stdexcept>

namespace Domino::Exception {
    class BoardPositionNotEmptyException : public std::runtime_error
    {
        public:
            BoardPositionNotEmptyException();
    };
}

#endif
