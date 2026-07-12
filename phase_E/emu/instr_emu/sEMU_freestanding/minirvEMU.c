#include "minirvEMU.h"

void inst_cycle();

int main(int argc, char *argv[]) {
  Assert(argc >= 2, "Program is not given");  // 要求至少包含一个参数
  FILE *fp = fopen(argv[1], "r");
  Perror(fp != NULL, "Fail to open %s", argv[1]); // 要求argv[1]是一个可以成功打开的文件
  int ret = fseek(fp, 0, SEEK_END);
  Perror(ret != -1, "Fail to seek the end of the file"); // 要求fseek()成功
  long fsize = ftell(fp);
  Perror(fsize != -1, "Fail to return the file position"); // 要求ftell()成功
  rewind(fp);
  Assert(fsize < MSIZE, "Program size exceeds %d Bytes", MSIZE); // 要求程序大小不超过1024字节
  ret = fread(M, 1, MSIZE, fp);
  Assert(ret == fsize, "Fail to load the whole program"); // 要求完全读出程序的内容
  fclose(fp);
  for (int i = 0; i < 100; i ++) { inst_cycle(); }
  return 0;
}
