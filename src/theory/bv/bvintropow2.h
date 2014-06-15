

#include "cvc4_private.h"
#include "expr/node.h"

#include <vector>
#include <ext/hash_map>

#ifndef __CVC4__THEORY__BV__BV_INTRO_POW_H
#define __CVC4__THEORY__BV__BV_INTRO_POW_H

namespace CVC4 {
namespace theory {
namespace bv {


class BVIntroducePow2 {
public:
  static void pow2Rewrite(std::vector<Node>& assertionsToPreprocess);

private:
  typedef __gnu_cxx::hash_map<Node, Node, NodeHashFunction> NodeMap;
  static Node pow2Rewrite(Node assertionsToPreprocess, NodeMap& cache);
}; 



}/* CVC4::theory::bv namespace */
}/* CVC4::theory namespace */

}/* CVC4 namespace */


#endif /* __CVC4__THEORY__BV__BV_INTRO_POW_H */
