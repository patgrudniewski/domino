/**
 * @author Patryk Grudniewski <patgrudniewski@gmail.com>
 */
#ifndef DOMINO_EXCEPTION_INVALIDHASHEXCEPTION_H
#define DOMINO_EXCEPTION_INVALIDHASHEXCEPTION_H

#include <exception>
#include <stdexcept>
#include <vector>

#include "../../Exception/ChainException.h"

using Exception::ChainException;

namespace Domino::Exception {
    class InvalidHashException : public std::runtime_error, public ChainException
    {
        public:
            /**
             * @param std::vector<unsigned int>::const_iterator hash
             * @param std::exception* previous
             */
            InvalidHashException(std::vector<unsigned int>::const_iterator hash, std::exception& previous);

            /**
             * @return std::vector<unsigned int>::const_iterator
             */
            std::vector<unsigned int>::const_iterator getHash();
        private:
            /**
             * @var std::vector<unsigned int>::const_iterator
             */
            std::vector<unsigned int>::const_iterator hash;
    };
}

#endif
