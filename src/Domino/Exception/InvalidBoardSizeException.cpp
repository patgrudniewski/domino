/**
 * @author Patryk Grudniewski <patgrudniewski@gmail.com>
 */

#include "InvalidBoardSizeException.h"

namespace Domino::Exception {
    InvalidBoardSizeException::InvalidBoardSizeException()
        :invalid_argument("Invalid board size") {  }
}
