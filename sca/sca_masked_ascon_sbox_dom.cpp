#include "Context.h"
#include "CorrSet.h"
#include "Expr.h"
#include "StaticExpr.h"
#include "TransientExpr.h"
#include "SboxChecker.h"
#include "PtrVector.h"

#include <cassert>
#include <vector>
#include <array>

#define TRANSIENT
#ifndef TRANSIENT
    using V = StaticExpr;
#else
    using V = TransientExpr;
#endif

#define USE_V1 1
#define USE_V2 2

#define VERSION USE_V2

void test_dut()
{
    constexpr uint32_t NUM_QUADRATIC = NUM_SHARES * (NUM_SHARES - 1) / 2;
    static_assert(NUM_SHARES >= 2 && NUM_SHARES <= 5);
    SboxChecker<V> checker(FILE_PATH, TOP_MODULE);

    /// @todo Implement a cocoverif testbench for your masked Ascon Sbox.

    /// @details Generally, follow the same steps as for the DOM Multiplier
    /// but be careful regarding the bit ordering in the masked Sbox inputs.
    /// Here, you can use the concat(PtrVector<V>&, PtrVector<V>&) and
    /// PtrVector<V>::slice functions to glue together two bit-vectors or
    /// extract specified bits from a bit-vector.
    
    {
        PtrVector<V> tuple = checker.check_sim_property<V>(NUM_SHARES - 1, Context::ni_t::NI);
        if (!tuple.empty()) checker.print_violation(tuple);
    }
    {
        PtrVector<V> tuple = checker.check_sim_property<V>(NUM_SHARES - 1, Context::ni_t::SNI);
        if (!tuple.empty()) checker.print_violation(tuple);
    }
    {
        PtrVector<V> tuple = checker.check_sim_property<V>(NUM_SHARES - 1, Context::ni_t::PINI);
        if (!tuple.empty()) checker.print_violation(tuple);
    }
}

int main()
{
    test_dut();
    return 0;
}