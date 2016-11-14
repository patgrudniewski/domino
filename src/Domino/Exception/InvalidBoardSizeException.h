/**
 * @author Patryk Grudniewski <patgrudniewski@gmail.com>
 */
#ifndef DOMINO_EXCEPTION_INVALIDBOARDSIZEEXCEPTION_H
#define DOMINO_EXCEPTION_INVALIDBOARDSIZEEXCEPTION_H

#include <stdexcept>
#include <exception>

namespace Domino::Exception {
    class InvalidBoardSizeException: public std::invalid_argument
    {
        public:
            InvalidBoardSizeException();
    };
}

#endif
