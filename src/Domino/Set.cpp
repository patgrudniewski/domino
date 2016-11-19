/**
 * @author Patryk Grudniewski <patgrudniewski@gmail.com>
 */
#include "Set.h"

namespace Domino {
    using namespace std;

    /**
     * @param vector<int>::const_iterator hash
     * @param tiles_n
     */
    Set::Set(vector<int>::const_iterator hash, int tiles_n)
    {
        int mask = 1,
            mask_limit = pow(2, tiles_n);

        while (mask < mask_limit) {
            bool vertical = (bool)(*hash & mask);
            // @TODO: add tile
            // @TODO: throw exception if impossible

            mask <<= 1;
        }
    }
}
