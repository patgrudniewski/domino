/**
 * @author Patryk Grudniewski <patgrudniewski@gmail.com>
 */
#ifndef DOMINO_EXCEPTION_INVALIDTILELOCATIONEXCEPTION_H
#define DOMINO_EXCEPTION_INVALIDTILELOCATIONEXCEPTION_H

#include <exception>
#include <stdexcept>

#include "../../Exception/ChainException.h"
#include "../TileLocation.h"

using Exception::ChainException;

namespace Domino::Exception {
    class InvalidTileLocationException : public std::runtime_error, public ChainException
    {
        public:
            /**
             * @param TileLocation* location
             * @param std::exception* previous
             */
            InvalidTileLocationException(TileLocation* location, std::exception& previous);

            /**
             * @return std::exception&
             */


        private:
            /**
             * @var TileLocation*
             */
            TileLocation* location;
    };
}

#endif
