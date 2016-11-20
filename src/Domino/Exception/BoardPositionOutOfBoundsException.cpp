/**
 * @author Patryk Grudniewski <patgrudniewski@gmail.com>
 */
#include "BoardPositionOutOfBoundsException.h"

namespace Domino::Exception {
    /**
     * @param BoardPosition* position
     */
    BoardPositionOutOfBoundsException::BoardPositionOutOfBoundsException(BoardPosition* position)
        : BoardPositionException(position, "Board position is out of bounds") {  }
}
