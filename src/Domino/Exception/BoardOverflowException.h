/**
 * @author Patryk Grudniewski <patgrudniewski@gmail.com>
 */
#ifndef DOMINO_EXCEPTION_BOARDOVERFLOWEXCEPTION_H
#define DOMINO_EXCEPTION_BOARDOVERFLOWEXCEPTION_H

#include <stdexcept>

namespace Domino::Exception {
    class BoardOverflowException : public std::out_of_range
    {
        public:
            BoardOverflowException();
    };
}

#endif
