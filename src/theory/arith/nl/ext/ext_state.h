/*********************                                                        */
/*! \file shared_check_data.h
 ** \verbatim
 ** Top contributors (to current version):
 **   Gereon Kremer
 ** This file is part of the CVC4 project.
 ** Copyright (c) 2009-2020 by the authors listed in the file AUTHORS
 ** in the top-level source directory and their institutional affiliations.
 ** All rights reserved.  See the file COPYING in the top-level source
 ** directory for licensing information.\endverbatim
 **
 ** \brief Common data shared by multiple checks
 **/

#ifndef CVC4__THEORY__ARITH__NL__EXT__SHARED_CHECK_DATA_H
#define CVC4__THEORY__ARITH__NL__EXT__SHARED_CHECK_DATA_H

#include <vector>

#include "expr/proof_set.h"
#include "expr/node.h"
#include "theory/arith/inference_manager.h"
#include "theory/arith/nl/ext/monomial.h"
#include "theory/arith/nl/nl_model.h"

namespace CVC4 {
namespace theory {
namespace arith {
namespace nl {

struct ExtState
{
  ExtState(InferenceManager& im,
           NlModel& model,
           ProofNodeManager* pnm,
           context::UserContext* c);

  void init(const std::vector<Node>& xts);

  /**
   * Checks whether proofs are enabled.
   */
  bool isProofEnabled() const;
  /**
   * Creates and returns a new LazyCDProof that can be used to prove some lemma.
   */
  CDProof* getProof();

  Node d_false;
  Node d_true;
  Node d_zero;
  Node d_one;
  Node d_neg_one;

  /** The inference manager that we push conflicts and lemmas to. */
  InferenceManager& d_im;
  /** Reference to the non-linear model object */
  NlModel& d_model;
  /**
   * Pointer to the current proof node manager. nullptr, if proofs are
   * disabled.
   */
  ProofNodeManager* d_pnm;
  /** The user context. */
  context::UserContext* d_ctx;
  /**
   * A CDProofSet that hands out CDProof objects for lemmas.
   */
  std::unique_ptr<CDProofSet<CDProof>> d_proof;

  // information about monomials
  std::vector<Node> d_ms;
  std::vector<Node> d_ms_vars;
  std::vector<Node> d_mterms;

  /** Context-independent database of monomial information */
  MonomialDb d_mdb;

  // ( x*y, x*z, y ) for each pair of monomials ( x*y, x*z ) with common factors
  std::map<Node, std::map<Node, Node> > d_mono_diff;
  /** the set of monomials we should apply tangent planes to */
  std::unordered_set<Node, NodeHashFunction> d_tplane_refine;
};

}  // namespace nl
}  // namespace arith
}  // namespace theory
}  // namespace CVC4

#endif
