/* sISA spec:
 *
 *  7  6 5  4 3   2 1   0
 * +----+----+-----+-----+
 * | 00 | rd | rs1 | rs2 | R[rd]=R[rs1]+R[rs2]       add指令, 寄存器相加
 * +----+----+-----+-----+
 * | 10 | rd |    imm    | R[rd]=imm                 li指令, 装入立即数, 高位补0
 * +----+----+-----+-----+
 * | 11 |   addr   | rs2 | if (R[0]!=R[rs2]) PC=addr bner0指令, 若不等于R[0]则跳转
 * +----+----------+-----+
 *
 * An example case: evaluate 1+2+...+N (N is user input)
 * The corresponding sISA instrs:
 *   0b10010000, // li r1, 0
 *   0b10100000, // li r2, 0
 *   0b10110001, // li r3, 1
 *   0b00010111, // add r1, r1, r3
 *   0b00101001, // add r2, r2, r1
 *   0b11001101, // bner0 r1, 3
 *   0b01000010, // out r2
 * The corresponding runtime environment needed:
 * 1, 在程序执行开始前
 *   1) 加载程序: 将程序从文件中读入M
 *   2) 传递参数: 在r0寄存器中存放程序的参数
 * 2, 在程序执行过程中
 *   1) 可通过out指令以整数方式输出指定寄存器的值
 * 3, 在程序执行结束后
 *   1) 通过自定义指令out来输出结果
 */

#include <stdint.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

uint8_t PC = 0;
uint8_t R[4];
uint8_t M[16];

typedef union {
  struct {
    uint8_t rs2 : 2;
    uint8_t rs1 : 2;
    uint8_t rd : 2;
    uint8_t op : 2;
  } r;
  struct {
    uint8_t imm : 4;
    uint8_t rd : 2;
    uint8_t op : 2;
  } li;
  struct {
    uint8_t rs2 : 2;
    uint8_t addr : 4;
    uint8_t op : 2;
  } bne;
  struct {
    uint8_t rd : 2;
    uint8_t : 4;
    uint8_t op : 2;
  } out;
  uint8_t byte;
} inst_t;

void inst_cycle() {
  inst_t instr = *(inst_t*)&M[PC];
  switch ((instr.byte >> 6) & 0b11) {
    case 0b00: R[instr.r.rd] = R[instr.r.rs1] + R[instr.r.rs2]; break;
    case 0b10: R[instr.li.rd] = instr.li.imm; break;
    case 0b11:  
               if (R[instr.bne.rs2] != R[0]) { 
                 PC = instr.bne.addr;
                 return; 
               }
               break;
    case 0b01: printf("%u\n", R[2]); break;
    default: printf("Unsuppported instruction\n"); break;
  }
  PC++;
}

int main(int argc, char* argv[]) {
  assert(argc >= 3);
  R[0] = atoi(argv[2]);
  FILE *fp = fopen(argv[1], "r");
  assert(fp != NULL);
  int ret = fseek(fp, 0, SEEK_END);
  assert(ret != -1);
  long fsize = ftell(fp);
  assert(fsize != -1);
  rewind(fp);
  assert(fsize < 16);
  ret = fread(M, 1, 16, fp);
  assert(ret == fsize); // assert file is read completely
  fclose(fp);
  for (int i = 0; i < 100; i++) {
    inst_cycle();
  }
  return 0;
}
