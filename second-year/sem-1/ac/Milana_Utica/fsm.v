module d_ff(
    input clk, rst, d, 
    output reg q
);
    always @ (posedge clk, posedge rst)
        if (rst == 1)       q<=0;
        else            q<=d;
endmodule

module fsm(
  input clk, rst_b,
  input I1,a7,i8
  output o3,u4,u7,u8
);
  localparam S_V5 = 0;
  localparam S_R7 = 1;
  localparam S_E7 = 2;
 
  d_ff inst1 (.clk(clk),.rst(rst_b), .d(S_R7),.q(S_V5))
  d_ff inst2 (.clk(clk),.rst(rst_b), .d(S_R7),.q(S_E7))
  d_ff inst3 (.clk(clk),.rst(rst_b), .d(S_V5),.q(S_E7))
  d_ff inst4 (.clk(clk),.rst(rst_b), .d(S_R7),.q(S_R7))
  d_ff inst5 (.clk(clk),.rst(rst_b), .d(S_E7),.q(S_E7))

  	assign inst1=((I1&a7)|(I1&~i8)) | (i8&~I1) | (I1&i8&~a7) | (~I1&~i8);
	assign inst2=((I1&a7&i8)|(~I1&~i8)) | (I1&a7&~i8);
	assign inst3=(i8&~I1&~a7) | ((a7&i8&~I1)|(I1&~a7&~i8));
	assign inst4=((I1&a7&i8)|(I1&~a7&~i8)|(a7&~I1&~i8)) ;
	assign inst5=I1&i8&~a7;
 	
assign o3=inst1 | inst2 | inst3 | inst4 | inst5;
assign u4=inst1 | inst5;
assign u7=inst1 | inst3 | inst4 | inst5;
assign u8=inst1 | inst2 | inst3 | inst4 | inst5;

module fsm_tb;
  reg clk, rst_b, I1,a7,i8;
  wire o3,u4,u7,u8;
  
  fsm inst1(.clk(clk),.rst_b(rst_b),.I1(I1),.a7(a7),.i8(i8),.o3(o3),.u4(u4),.u7(u7),.u8(u8);
  localparam CLK_PERIOD=50;
  localparam RUNNING_CYCLES=24;
  initial begin
    clk=0;
    repeat (2*RUNNING_CYCLES) #(CLK_PERIOD/2) clk=~clk;
  end
  localparam RST_DURATION=10;
  initial begin
    rst_b=1;
    #RST_DURATION rst_b=0;
  end
  initial begin
    {I1,a7,i8}=3'b011;
#(1*CLK_PERIOD) {I1,a7,i8}=3'b111;
#(1*CLK_PERIOD) {I1,a7,i8}=3'b001;
#(1*CLK_PERIOD) {I1,a7,i8}=3'b110;
#(1*CLK_PERIOD) {I1,a7,i8}=3'b010;
#(1*CLK_PERIOD) {I1,a7,i8}=3'b100;
#(1*CLK_PERIOD) {I1,a7,i8}=3'b000;
#(1*CLK_PERIOD) {I1,a7,i8}=3'b010;
#(1*CLK_PERIOD) {I1,a7,i8}=3'b110;
#(1*CLK_PERIOD) {I1,a7,i8}=3'b111;
#(1*CLK_PERIOD) {I1,a7,i8}=3'b101;
#(1*CLK_PERIOD) {I1,a7,i8}=3'b000;
#(1*CLK_PERIOD) {I1,a7,i8}=3'b011;
#(1*CLK_PERIOD) {I1,a7,i8}=3'b000;
#(1*CLK_PERIOD) {I1,a7,i8}=3'b011;
#(1*CLK_PERIOD) {I1,a7,i8}=3'b110;
#(1*CLK_PERIOD) {I1,a7,i8}=3'b001;
#(1*CLK_PERIOD) {I1,a7,i8}=3'b111;
#(1*CLK_PERIOD) {I1,a7,i8}=3'b101;
#(1*CLK_PERIOD) {I1,a7,i8}=3'b010;
#(1*CLK_PERIOD) {I1,a7,i8}=3'b111;
#(1*CLK_PERIOD) {I1,a7,i8}=3'b110;
#(1*CLK_PERIOD) {I1,a7,i8}=3'b011;
#(1*CLK_PERIOD) {I1,a7,i8}=3'b000;
#(1*CLK_PERIOD) {I1,a7,i8}=3'b100;
#(1*CLK_PERIOD) {I1,a7,i8}=3'b010;
#(1*CLK_PERIOD) {I1,a7,i8}=3'b100;
#(1*CLK_PERIOD) {I1,a7,i8}=3'b011;
#(1*CLK_PERIOD) {I1,a7,i8}=3'b010;
#(1*CLK_PERIOD) {I1,a7,i8}=3'b011;
#(1*CLK_PERIOD) {I1,a7,i8}=3'b110;
#(1*CLK_PERIOD) {I1,a7,i8}=3'b100;
#(1*CLK_PERIOD) {I1,a7,i8}=3'b011;
#(1*CLK_PERIOD) {I1,a7,i8}=3'b000;
#(1*CLK_PERIOD) {I1,a7,i8}=3'b100;
#(1*CLK_PERIOD) {I1,a7,i8}=3'b110;

    
  end
endmodule