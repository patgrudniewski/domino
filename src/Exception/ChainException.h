/**
 * @author Patryk Grudniewski <patgrudniewski@gmail.com>
 */
#ifndef EXCEPTION_CHAINEXCEPTION_H
#define EXCEPTION_CHAINEXCEPTION_H

#include <exception>

namespace Exception {
    class ChainException
    {
        public:
            /**
             * @param std::exception& previous
             */
            ChainException(std::exception& previous);

            /**
             * @return std::exception&
             */
            std::exception& getPrevious();

        private:
            /**
             * @var std::exception&
             */
            std::exception& previous;
    };
}

#endif
