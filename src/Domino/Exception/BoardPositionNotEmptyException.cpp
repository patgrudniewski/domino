/**
 * @author Patryk Grudniewski <patgrudniewski@gmail.com>
 */
#include "BoardPositionNotEmptyException.h"

namespace Domino::Exception {
    using namespace std;

    BoardPositionNotEmptyException::BoardPositionNotEmptyException()
        :runtime_error("Board position is not empty")
    {
    }
}
