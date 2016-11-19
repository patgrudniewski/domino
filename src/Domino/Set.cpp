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
        :board(board)
    {
        int tiles_n = this->board->getMaxTilesCount(),
            mask = 1,
            mask_limit = pow(2, tiles_n);

        while (mask < mask_limit) {
            this->board->addTile((bool)(*hash & mask));

            // @TODO: throw exception if impossible

            mask <<= 1;
        }
    }
}