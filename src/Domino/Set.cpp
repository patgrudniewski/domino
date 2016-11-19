/**
 * @author Patryk Grudniewski <patgrudniewski@gmail.com>
 */
#include "Set.h"

namespace Domino {
    using namespace std;

    /**
     * @param Board* board
     * @param vector<int>::const_iterator hash
     */
    Set::Set(Board *board, vector<int>::const_iterator hash)
    {
        int tiles_n = board->getMaxTilesCount(),
            mask = 1,
            mask_limit = pow(2, tiles_n);

        while (mask < mask_limit) {
            bool vertical = (bool)(*hash & mask);
            // @TODO: add tile to the board
            // @TODO: throw exception if impossible

            mask <<= 1;
        }
    }
}
