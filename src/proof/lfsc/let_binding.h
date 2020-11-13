/*********************                                                        */
/*! \file let_binding.h
 ** \verbatim
 ** Top contributors (to current version):
 **   Andrew Reynolds
 ** This file is part of the CVC4 project.
 ** Copyright (c) 2009-2020 by the authors listed in the file AUTHORS
 ** in the top-level source directory) and their institutional affiliations.
 ** All rights reserved.  See the file COPYING in the top-level source
 ** directory for licensing information.\endverbatim
 **
 ** \brief A let binding
 **/

#include "cvc4_private.h"

#ifndef CVC4__PROOF__LFSC__LET_BINDING_H
#define CVC4__PROOF__LFSC__LET_BINDING_H

#include <map>
#include <vector>

#include "context/cdhashmap.h"
#include "context/cdlist.h"
#include "expr/node.h"

namespace CVC4 {
namespace proof {

/**
 * A let binding is a list and a map that can be printed as a let expression.
 * In particular, the list d_letList is ordered such that
 * d_letList[i] does not contain subterm d_letList[j] for j>i.
 * It is intended that d_letList contains only unique nodes. Each node
 * in d_letList is mapped to a unique identifier in d_letMap.
 *
 * If a term is mapped to identifier 0, then it is not letified. This is
 * used to disable letification for certain terms.
 */
class LetBinding
{
  typedef context::CDList<Node> NodeList;
  typedef context::CDHashMap<Node, uint32_t, NodeHashFunction> NodeIdMap;

 public:
  LetBinding(uint32_t thresh = 2);
  /**
   * Push scope for n.
   *
   * This compute the letification for n, adds the (new) terms that must be
   * letified in this context to letList.
   *
   * Notice that this method does not traverse inside of closures.
   *
   * @param n The node to letify
   * @param letList The list of terms that should be letified within n. This
   * list is ordered in such a way that letList[i] does not contain subterm
   * letList[j] for j>i.
   */
  void push(Node n, std::vector<Node>& letList);
  /** Pop scope for n, reverts the state change of the above method */
  void pop();
  /**
   * @return the identifier for node n.
   */
  uint32_t getId(Node n) const;
  /**
   * Convert n based on the state of the let binding. This replaces all
   * letified subterms of n with a fresh variable whose name prefix is the
   * given one.
   *
   * @param n The node to convert
   * @param prefix The prefix of variables to convert
   * @return the converted node.
   */
  Node convert(Node n, const std::string& prefix) const;

 private:
  /**
   * Compute the count of sub nodes in pn, store in pcount. Additionally,
   * store each node in the domain of pcount in an order in visitList
   * such that visitList[i] does not contain sub visitList[j] for j>i.
   */
  void updateCounts(Node n);
  /**
   * Convert a count to a let binding.
   */
  void convertCountToLet();
  /** The dag threshold */
  uint32_t d_thresh;
  /** An internal context */
  context::Context d_context;
  /** Visit list */
  NodeList d_visitList;
  /** Count */
  NodeIdMap d_count;
  /** The let list */
  NodeList d_letList;
  /** The let map */
  NodeIdMap d_letMap;
};

}  // namespace proof
}  // namespace CVC4

#endif