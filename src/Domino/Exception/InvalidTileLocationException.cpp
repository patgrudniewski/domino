/**
 * @author Patryk Grudniewski <patgrudniewski@gmail.com>
 */
#include "InvalidTileLocationException.h"

using Exception::ChainException;

namespace Domino::Exception {
    using namespace std;

    /**
     * @param TileLocation* location
     * @param exception& previous
     */
    InvalidTileLocationException::InvalidTileLocationException(TileLocation* location, exception& previous)
        :runtime_error("Invalid tile location"), ChainException(previous), location(location) {  }

    /**
     * @return TileLocation*
     */
    TileLocation* InvalidTileLocationException::getLocation()
    {
        return this->location;
    }
}
