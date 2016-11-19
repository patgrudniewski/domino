/**
 * @author Patryk Grudniewski <patgrudniewski@gmail.com>
 */
#ifndef DOMINO_EXCEPTION_BOARDPOSITIONNOTEMPTYEXCEPTION_H
#define DOMINO_EXCEPTION_BOARDPOSITIONNOTEMPTYEXCEPTION_H

#include <stdexcept>
#include <utility>

namespace Domino::Exception {
    class BoardPositionNotEmptyException : public std::runtime_error
    {
        public:
            /**
             * @param int x
             * @param int y
             */
            BoardPositionNotEmptyException(int x, int y);

            /**
             * @return int
             */
            int getPositionX();

            /**
             * @return int
             */
            int getPositionY();

        private:
            std::pair<int, int> position;
    };
}

#endif
