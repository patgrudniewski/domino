/**
 * @author Patryk Grudniewski <patgrudniewski@gmail.com>
 */
#include "BoardOverflowException.h"

namespace Domino::Exception {
    using namespace std;

    BoardOverflowException::BoardOverflowException()
        :out_of_range("Trying to add tile into full board") {  };
}
