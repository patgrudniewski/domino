/**
 * @author Patryk Grudniewski <patgrudniewski@gmail.com>
 */
#include "InvalidTileLocationException.h"

using Exception::ChainException;

namespace Domino::Exception {
    using namespace std;

    InvalidTileLocationException::InvalidTileLocationException(TileLocation* location, exception& previous)
        :runtime_error("Invalid tile location"), ChainException(previous), location(location) {  }
}
