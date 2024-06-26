`ifndef MASKED_NOT_SV
`define MASKED_NOT_SV

`include "dev_package.sv"

module masked_not #(
    parameter NUM_SHARES = 2
)(
    in_a, out_b
);
    import dev_package::*;
    
    input  bit[NUM_SHARES-1:0] in_a;
    output bit[NUM_SHARES-1:0] out_b;
    
    /// @todo Implement a masked NOT operation.

    /// @details Masking is encoding A as A_0 ^ A_1 ^ ... A_{n-1}.
    /// To negate the original value, negate just one of the shares.

endmodule : masked_not
`endif // MASKED_NOT_SV
