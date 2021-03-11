#include <iostream>

#include "smt/optimization_solver.h"
#include "test_smt.h"

namespace CVC4 {

using namespace theory;
using namespace smt;

namespace test {

class TestTheoryWhiteBVOpt : public TestSmtNoFinishInit
{
 protected:
  void SetUp() override
  {
    TestSmtNoFinishInit::SetUp();
    d_smtEngine->setOption("produce-assertions", "true");
    d_smtEngine->finishInit();

    d_optslv.reset(new OptimizationSolver(d_smtEngine.get()));
    d_BV32Type.reset(new TypeNode(d_nodeManager->mkBitVectorType(32u)));
    d_BV16Type.reset(new TypeNode(d_nodeManager->mkBitVectorType(16u)));
  }

  std::unique_ptr<OptimizationSolver> d_optslv;
  std::unique_ptr<TypeNode> d_BV32Type;
  std::unique_ptr<TypeNode> d_BV16Type;
};

TEST_F(TestTheoryWhiteBVOpt, signed_max)
{
  Node x = d_nodeManager->mkVar(*d_BV32Type);

  Node a = d_nodeManager->mkConst(BitVector(32u, 0u));
  Node b = d_nodeManager->mkConst(BitVector(32u, 2147483647u));

  // 0 <= x <= 2147483647
  d_smtEngine->assertFormula(d_nodeManager->mkNode(kind::BITVECTOR_SLE, a, x));
  d_smtEngine->assertFormula(d_nodeManager->mkNode(kind::BITVECTOR_SLE, x, b));

  const ObjectiveType obj_type = OBJECTIVE_MAXIMIZE;
  d_optslv->activateObj(x, obj_type, true);

  OptResult r = d_optslv->checkOpt();

  // expect the maxmum x =
  ASSERT_EQ(d_optslv->objectiveGetValue(),
            d_nodeManager->mkConst(BitVector(32u, 2147483647u)));
  std::cout << "Result is :" << r << std::endl;
  std::cout << "Optimized value is: " << d_optslv->objectiveGetValue()
            << std::endl;
}

TEST_F(TestTheoryWhiteBVOpt, signed_min)
{
  Node x = d_nodeManager->mkVar(*d_BV32Type);

  Node a = d_nodeManager->mkConst(BitVector(32u, (unsigned)0xFFFFFFFF));
  Node b = d_nodeManager->mkConst(BitVector(32u, 2147483647u));
  // -1 <= x <= 2147483647
  d_smtEngine->assertFormula(d_nodeManager->mkNode(kind::BITVECTOR_SLE, a, x));
  d_smtEngine->assertFormula(d_nodeManager->mkNode(kind::BITVECTOR_SLE, x, b));

  const ObjectiveType obj_type = OBJECTIVE_MINIMIZE;
  d_optslv->activateObj(x, obj_type, true);

  OptResult r = d_optslv->checkOpt();

  // expect the minimum x = -1
  ASSERT_EQ(d_optslv->objectiveGetValue(),
            d_nodeManager->mkConst(BitVector(32u, (unsigned)0xFFFFFFFF)));
  std::cout << "Result is :" << r << std::endl;
  std::cout << "Optimized value is: " << d_optslv->objectiveGetValue()
            << std::endl;
}

TEST_F(TestTheoryWhiteBVOpt, unsigned_max)
{
  Node x = d_nodeManager->mkVar(*d_BV32Type);

  Node a = d_nodeManager->mkConst(BitVector(32u, (unsigned)0xFFFFFFA1));
  Node b = d_nodeManager->mkConst(BitVector(32u, (unsigned)0xFFFFFFF1));

  // If the gap is too large, it will have a performance issue!!!
  // Need binary search!
  // (unsigned)0xFFFFFFA1 <= x <= (unsigned)0xFFFFFFF1
  d_smtEngine->assertFormula(d_nodeManager->mkNode(kind::BITVECTOR_ULE, a, x));
  d_smtEngine->assertFormula(d_nodeManager->mkNode(kind::BITVECTOR_ULE, x, b));

  const ObjectiveType obj_type = OBJECTIVE_MAXIMIZE;
  d_optslv->activateObj(x, obj_type, false);

  OptResult r = d_optslv->checkOpt();

  ASSERT_EQ(d_optslv->objectiveGetValue(),
            d_nodeManager->mkConst(BitVector(32u, (unsigned)0xFFFFFFF1)));
  std::cout << "Result is :" << r << std::endl;
  std::cout << "Optimized value is: " << d_optslv->objectiveGetValue()
            << std::endl;
}

TEST_F(TestTheoryWhiteBVOpt, unsigned_min)
{
  Node x = d_nodeManager->mkVar(*d_BV32Type);

  Node a = d_nodeManager->mkConst(BitVector(32u, (unsigned)0xFFFFFFA1));
  Node b = d_nodeManager->mkConst(BitVector(32u, (unsigned)0xFFFFFFF1));

  // (unsigned)0xFFFFFFA1 <= x <= (unsigned)0xFFFFFFF1
  d_smtEngine->assertFormula(d_nodeManager->mkNode(kind::BITVECTOR_ULE, a, x));
  d_smtEngine->assertFormula(d_nodeManager->mkNode(kind::BITVECTOR_ULE, x, b));

  const ObjectiveType obj_type = OBJECTIVE_MINIMIZE;
  d_optslv->activateObj(x, obj_type, false);

  OptResult r = d_optslv->checkOpt();

  ASSERT_EQ(d_optslv->objectiveGetValue(),
            d_nodeManager->mkConst(BitVector(32u, (unsigned)0xFFFFFFA1)));
  std::cout << "Result is :" << r << std::endl;
  std::cout << "Optimized value is: " << d_optslv->objectiveGetValue()
            << std::endl;
}

}  // namespace test
}  // namespace CVC4