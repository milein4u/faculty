module SRT2(
	input clk, rst,
	input [7:0] Deimpartit, Impartitor,
	output reg [7:0] Cat, Rest,
	reg [7:0] x, y, aux,
	reg [8:0] P,
	reg [2:0] q,
	integer i, k
);

	always @(posedge clk, negedge rst)
	begin
	 if(!rst)
	 begin
	  Cat <= 0;
	  Rest <= 0;
	 end
	 else
	 begin
	  Cat <= x;
	  Rest <= P[8:0];
	 end
	end

	always @(*)
	begin
	 x = Deimpartit;
	 y = Impartitor;
	 P = 0;
	 q = 0;
	 i = 7;
	 q = 0;
	 while(!y[i])
	 begin
	  k = k + 1;
	  i = i - 1;
	 end
	 {P,x,y} = {P,x,y} << k;
	 for(i = 0; i < 8; i = i + 1)
	 begin
	  P = (P <<1) | x[7];
	  x = x <<1;
	  q = {P[8],P[7],P[6]};
	  case (q)
		3'b001 : begin
			 P = P - y;
			 x = x + 1;
			 end
		3'b010 : begin
			 P = P - y;
			 x = x + 1;
			 end
		3'b011 : begin
			 P = P - y;
			 x = x + 1;
			 end
		3'b100 : begin
			 P = P + y;
			 x = x - 1;
			 end
		3'b101 : begin
			 P = P + y;
			 x = x - 1;
			 end
		3'b110 : begin
			 P = P + y;
			 x = x - 1;
			 end
		default: begin end
	  endcase
	end
	if(P[8] == 1)
	begin
	 P = P + y;
	 x = x - 1;
	end

	P = P >> k;
end
endmodule

module SRT2_tb;
	reg clk,rst;
	reg [7:0] Deimpartit, Impartitor;
	wire [7:0] Cat, Rest;
			

	SRT2 (.clk(clk), .rst(rst), .Deimpartit(Deimpartit),
		.Impartitor(Impartitor), .Cat(Cat), .Rest(Rest));
	
	
	initial 
		forever #1 clk = ~clk;
	
	initial 
		$display("time\tclk\trst\tDeimpartit\tImpartitor\tCat\tRest");
		$monitor("%4t\t%b\t%b\t%b\t%b\t%b\t%b",$time,clk,rst,Deimpartit,
			Impartitor,Cat,Rest);

	initial
	begin
		clk = 0;
		rst = 0;

		#1;
		rst = 1;

		#10
		Deimpartit = 127;
		Impartitor = 25;

	end
endmodule
