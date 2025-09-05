module light(
	output reg [15:0] led,
	input clk, rst
);
	reg [31:0] count;
	always @(posedge clk) begin
		if (rst) begin
			led <= 1;
			count <= 0;
		end
		else begin
			if (count == 0) 
				led <= {led[14:0], led[15]};
			count <= (count == 500000 ? 32'b0 : count+1);
		end
	end
endmodule
