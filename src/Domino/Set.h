/**
 * @author Patryk Grudniewski <patgrudniewski@gmail.com>
 */
#ifndef DOMINO_SET_H
#define DOMINO_SET_H

#include <cmath>
#include <vector>

namespace Domino {
    class Set {
        public:
            /**
             * @param std::vector<int>::const_iterator hash
             * @param int tiles_n
             */
            Set(std::vector<int>::const_iterator hash, int tiles_n);
    };
}

#endif
