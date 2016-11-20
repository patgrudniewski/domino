/**
 * @author Patryk Grudniewski <patgrudniewski@gmail.com>
 */
#include "BoardPositionNotEmptyException.h"

namespace Domino::Exception {
    /**
     * @param BoardPosition* position
     */
    BoardPositionNotEmptyException::BoardPositionNotEmptyException(BoardPosition* position)
        :BoardPositionException(position, "Board position is not empty") {  }
}
