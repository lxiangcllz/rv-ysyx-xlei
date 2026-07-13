
/home/yzh/projectn/am-kernels/kernels/slider/build/slider-minirv-logisim.elf:     file format elf32-littleriscv


Disassembly of section .text:

00000000 <_start>:
       0:	00000413          	addi	s0,zero,0
       4:	00093137          	lui	sp,0x93
       8:	00010113          	addi	sp,sp,0 # 93000 <_end>
       c:	000010b7          	lui	ra,0x1
      10:	dbc08093          	addi	ra,ra,-580 # dbc <_trm_init>
      14:	000080e7          	jalr	ra,0(ra)

00000018 <display_image>:
      18:	fe012823          	sw	zero,-16(sp)
      1c:	fea10923          	sb	a0,-14(sp)
      20:	fea12423          	sw	a0,-24(sp)
      24:	fe914203          	lbu	tp,-23(sp)
      28:	fe4109a3          	sb	tp,-13(sp)
      2c:	ff012783          	lw	a5,-16(sp)

00000030 <slli_3>:
      30:	00f787b3          	add	a5,a5,a5
      34:	00f787b3          	add	a5,a5,a5
      38:	0004b6b7          	lui	a3,0x4b
      3c:	f0068693          	addi	a3,a3,-256 # 4af00 <image>
      40:	fdc10113          	addi	sp,sp,-36
      44:	00d787b3          	add	a5,a5,a3
      48:	10000713          	addi	a4,zero,256
      4c:	00f12423          	sw	a5,8(sp)
      50:	00010593          	addi	a1,sp,0
      54:	00100793          	addi	a5,zero,1
      58:	00b00513          	addi	a0,zero,11
      5c:	02112023          	sw	ra,32(sp)
      60:	00012023          	sw	zero,0(sp)
      64:	00012223          	sw	zero,4(sp)
      68:	00e12623          	sw	a4,12(sp)
      6c:	00e12823          	sw	a4,16(sp)
      70:	00f10a23          	sb	a5,20(sp)
      74:	000010b7          	lui	ra,0x1
      78:	a8408093          	addi	ra,ra,-1404 # a84 <ioe_write>
      7c:	000080e7          	jalr	ra,0(ra)
      80:	02012083          	lw	ra,32(sp)
      84:	02410113          	addi	sp,sp,36
      88:	00008067          	jalr	zero,0(ra)

0000008c <main>:
      8c:	ff410113          	addi	sp,sp,-12
      90:	00112423          	sw	ra,8(sp)
      94:	000010b7          	lui	ra,0x1
      98:	a7c08093          	addi	ra,ra,-1412 # a7c <ioe_init>
      9c:	000080e7          	jalr	ra,0(ra)
      a0:	00000513          	addi	a0,zero,0
      a4:	01800093          	addi	ra,zero,24
      a8:	000080e7          	jalr	ra,0(ra)
      ac:	00812083          	lw	ra,8(sp)
      b0:	00000513          	addi	a0,zero,0
      b4:	00c10113          	addi	sp,sp,12
      b8:	00008067          	jalr	zero,0(ra)

000000bc <__am_gpu_fbdraw>:
      bc:	00852583          	lw	a1,8(a0)

000000c0 <beq_54.L28>:
      c0:	feb12823          	sw	a1,-16(sp)
      c4:	fe812e23          	sw	s0,-4(sp)
      c8:	00003437          	lui	s0,0x3
      cc:	a0840413          	addi	s0,s0,-1528 # 2a08 <_check_8bit_0_table>
      d0:	ff014183          	lbu	gp,-16(sp)
      d4:	003401b3          	add	gp,s0,gp
      d8:	0001c183          	lbu	gp,0(gp)
      dc:	ff114203          	lbu	tp,-15(sp)
      e0:	00440233          	add	tp,s0,tp
      e4:	00024203          	lbu	tp,0(tp) # 0 <_start>
      e8:	004181b3          	add	gp,gp,tp
      ec:	ff214203          	lbu	tp,-14(sp)
      f0:	00440233          	add	tp,s0,tp
      f4:	00024203          	lbu	tp,0(tp) # 0 <_start>
      f8:	004181b3          	add	gp,gp,tp
      fc:	ff314203          	lbu	tp,-13(sp)
     100:	00440233          	add	tp,s0,tp
     104:	00024203          	lbu	tp,0(tp) # 0 <_start>
     108:	004181b3          	add	gp,gp,tp
     10c:	00003237          	lui	tp,0x3
     110:	a0020213          	addi	tp,tp,-1536 # 2a00 <_same_result_table>
     114:	00320233          	add	tp,tp,gp
     118:	00024203          	lbu	tp,0(tp) # 0 <_start>
     11c:	ffc12403          	lw	s0,-4(sp)

00000120 <slli_63>:
     120:	00420233          	add	tp,tp,tp
     124:	00420233          	add	tp,tp,tp
     128:	00410233          	add	tp,sp,tp
     12c:	000011b7          	lui	gp,0x1
     130:	85c18193          	addi	gp,gp,-1956 # 85c <non_taken_182.L12+0x28>
     134:	fe312823          	sw	gp,-16(sp)
     138:	14800193          	addi	gp,zero,328
     13c:	fe312623          	sw	gp,-20(sp)
     140:	fec22203          	lw	tp,-20(tp) # ffffffec <_end+0xfff6cfec>
     144:	00020067          	jalr	zero,0(tp) # 0 <_start>

00000148 <non_taken_54.L28>:
     148:	01052703          	lw	a4,16(a0)
     14c:	00052683          	lw	a3,0(a0)
     150:	00452783          	lw	a5,4(a0)
     154:	fe810113          	addi	sp,sp,-24
     158:	00e12423          	sw	a4,8(sp)
     15c:	00112a23          	sw	ra,20(sp)

00000160 <or_66>:
     160:	fed12823          	sw	a3,-16(sp)
     164:	fef12623          	sw	a5,-20(sp)
     168:	00013737          	lui	a4,0x13
     16c:	c0070713          	addi	a4,a4,-1024 # 12c00 <_logic_shift_table+0x10000>
     170:	fe012223          	sw	zero,-28(sp)
     174:	ff314203          	lbu	tp,-13(sp)
     178:	fe4102a3          	sb	tp,-27(sp)
     17c:	fef14203          	lbu	tp,-17(sp)
     180:	fe410223          	sb	tp,-28(sp)
     184:	fe412203          	lw	tp,-28(sp)
     188:	00470233          	add	tp,a4,tp
     18c:	00024203          	lbu	tp,0(tp) # 0 <_start>
     190:	fe4105a3          	sb	tp,-21(sp)
     194:	ff214203          	lbu	tp,-14(sp)
     198:	fe4102a3          	sb	tp,-27(sp)
     19c:	fee14203          	lbu	tp,-18(sp)
     1a0:	fe410223          	sb	tp,-28(sp)
     1a4:	fe412203          	lw	tp,-28(sp)
     1a8:	00470233          	add	tp,a4,tp
     1ac:	00024203          	lbu	tp,0(tp) # 0 <_start>
     1b0:	fe410523          	sb	tp,-22(sp)
     1b4:	ff114203          	lbu	tp,-15(sp)
     1b8:	fe4102a3          	sb	tp,-27(sp)
     1bc:	fed14203          	lbu	tp,-19(sp)
     1c0:	fe410223          	sb	tp,-28(sp)
     1c4:	fe412203          	lw	tp,-28(sp)
     1c8:	00470233          	add	tp,a4,tp
     1cc:	00024203          	lbu	tp,0(tp) # 0 <_start>
     1d0:	fe4104a3          	sb	tp,-23(sp)
     1d4:	ff014203          	lbu	tp,-16(sp)
     1d8:	fe4102a3          	sb	tp,-27(sp)
     1dc:	fec14203          	lbu	tp,-20(sp)
     1e0:	fe410223          	sb	tp,-28(sp)
     1e4:	fe412203          	lw	tp,-28(sp)
     1e8:	00470233          	add	tp,a4,tp
     1ec:	00024203          	lbu	tp,0(tp) # 0 <_start>
     1f0:	fe410423          	sb	tp,-24(sp)
     1f4:	fe812703          	lw	a4,-24(sp)
     1f8:	00c52603          	lw	a2,12(a0)

000001fc <beq_73.L32>:
     1fc:	fee12823          	sw	a4,-16(sp)
     200:	fe812e23          	sw	s0,-4(sp)
     204:	00003437          	lui	s0,0x3
     208:	a0840413          	addi	s0,s0,-1528 # 2a08 <_check_8bit_0_table>
     20c:	ff014183          	lbu	gp,-16(sp)
     210:	003401b3          	add	gp,s0,gp
     214:	0001c183          	lbu	gp,0(gp)
     218:	ff114203          	lbu	tp,-15(sp)
     21c:	00440233          	add	tp,s0,tp
     220:	00024203          	lbu	tp,0(tp) # 0 <_start>
     224:	004181b3          	add	gp,gp,tp
     228:	ff214203          	lbu	tp,-14(sp)
     22c:	00440233          	add	tp,s0,tp
     230:	00024203          	lbu	tp,0(tp) # 0 <_start>
     234:	004181b3          	add	gp,gp,tp
     238:	ff314203          	lbu	tp,-13(sp)
     23c:	00440233          	add	tp,s0,tp
     240:	00024203          	lbu	tp,0(tp) # 0 <_start>
     244:	004181b3          	add	gp,gp,tp
     248:	00003237          	lui	tp,0x3
     24c:	a0020213          	addi	tp,tp,-1536 # 2a00 <_same_result_table>
     250:	00320233          	add	tp,tp,gp
     254:	00024203          	lbu	tp,0(tp) # 0 <_start>
     258:	ffc12403          	lw	s0,-4(sp)

0000025c <slli_82>:
     25c:	00420233          	add	tp,tp,tp
     260:	00420233          	add	tp,tp,tp
     264:	00410233          	add	tp,sp,tp
     268:	66800193          	addi	gp,zero,1640
     26c:	fe312823          	sw	gp,-16(sp)
     270:	28000193          	addi	gp,zero,640
     274:	fe312623          	sw	gp,-20(sp)
     278:	fec22203          	lw	tp,-20(tp) # ffffffec <_end+0xfff6cfec>
     27c:	00020067          	jalr	zero,0(tp) # 0 <_start>

00000280 <non_taken_73.L32>:
     280:	00c68733          	add	a4,a3,a2
     284:	10000513          	addi	a0,zero,256

00000288 <blt_86.L19>:
     288:	fe812e23          	sw	s0,-4(sp)
     28c:	fe912c23          	sw	s1,-8(sp)
     290:	fee12823          	sw	a4,-16(sp)
     294:	00050413          	addi	s0,a0,0
     298:	ff012483          	lw	s1,-16(sp)
     29c:	fe812423          	sw	s0,-24(sp)
     2a0:	feb14183          	lbu	gp,-21(sp)

000002a4 <slli_91>:
     2a4:	003181b3          	add	gp,gp,gp
     2a8:	fe312423          	sw	gp,-24(sp)
     2ac:	fe914183          	lbu	gp,-23(sp)

000002b0 <slli_93>:
     2b0:	003181b3          	add	gp,gp,gp
     2b4:	fe912423          	sw	s1,-24(sp)
     2b8:	feb14203          	lbu	tp,-21(sp)

000002bc <slli_96>:
     2bc:	00420233          	add	tp,tp,tp
     2c0:	fe412423          	sw	tp,-24(sp)
     2c4:	fe914203          	lbu	tp,-23(sp)
     2c8:	004181b3          	add	gp,gp,tp

000002cc <slli_98>:
     2cc:	003181b3          	add	gp,gp,gp

000002d0 <sub_99>:
     2d0:	fe312a23          	sw	gp,-12(sp)
     2d4:	fe912423          	sw	s1,-24(sp)
     2d8:	00033237          	lui	tp,0x33
     2dc:	b0020213          	addi	tp,tp,-1280 # 32b00 <_logic_shift_table+0x2ff00>
     2e0:	feb14183          	lbu	gp,-21(sp)
     2e4:	004181b3          	add	gp,gp,tp
     2e8:	0001c183          	lbu	gp,0(gp)
     2ec:	fe3103a3          	sb	gp,-25(sp)
     2f0:	fea14183          	lbu	gp,-22(sp)
     2f4:	004181b3          	add	gp,gp,tp
     2f8:	0001c183          	lbu	gp,0(gp)
     2fc:	fe310323          	sb	gp,-26(sp)
     300:	fe914183          	lbu	gp,-23(sp)
     304:	004181b3          	add	gp,gp,tp
     308:	0001c183          	lbu	gp,0(gp)
     30c:	fe3102a3          	sb	gp,-27(sp)
     310:	fe814183          	lbu	gp,-24(sp)
     314:	004181b3          	add	gp,gp,tp
     318:	0001c183          	lbu	gp,0(gp)
     31c:	fe310223          	sb	gp,-28(sp)
     320:	ff412183          	lw	gp,-12(sp)
     324:	fe412203          	lw	tp,-28(sp)
     328:	00440233          	add	tp,s0,tp
     32c:	00120213          	addi	tp,tp,1 # 1 <_start+0x1>
     330:	fe412423          	sw	tp,-24(sp)
     334:	feb14203          	lbu	tp,-21(sp)

00000338 <slli_104>:
     338:	00420233          	add	tp,tp,tp
     33c:	fe412423          	sw	tp,-24(sp)
     340:	fe914203          	lbu	tp,-23(sp)
     344:	004181b3          	add	gp,gp,tp
     348:	00003237          	lui	tp,0x3
     34c:	b0820213          	addi	tp,tp,-1272 # 2b08 <_slt1_table>
     350:	00320233          	add	tp,tp,gp
     354:	ff812483          	lw	s1,-8(sp)
     358:	ffc12403          	lw	s0,-4(sp)
     35c:	00024203          	lbu	tp,0(tp) # 0 <_start>

00000360 <slli_108>:
     360:	00420233          	add	tp,tp,tp
     364:	00420233          	add	tp,tp,tp
     368:	00410233          	add	tp,sp,tp
     36c:	000011b7          	lui	gp,0x1
     370:	86018193          	addi	gp,gp,-1952 # 860 <non_taken_182.L12+0x2c>
     374:	fe312823          	sw	gp,-16(sp)
     378:	38800193          	addi	gp,zero,904
     37c:	fe312623          	sw	gp,-20(sp)
     380:	fec22203          	lw	tp,-20(tp) # ffffffec <_end+0xfff6cfec>
     384:	00020067          	jalr	zero,0(tp) # 0 <_start>

00000388 <non_taken_86.L19>:
     388:	00812703          	lw	a4,8(sp)
     38c:	10000513          	addi	a0,zero,256
     390:	00812823          	sw	s0,16(sp)
     394:	00e78733          	add	a4,a5,a4

00000398 <blt_112.L31>:
     398:	fe812e23          	sw	s0,-4(sp)
     39c:	fe912c23          	sw	s1,-8(sp)
     3a0:	fee12823          	sw	a4,-16(sp)
     3a4:	00050413          	addi	s0,a0,0
     3a8:	ff012483          	lw	s1,-16(sp)
     3ac:	fe812423          	sw	s0,-24(sp)
     3b0:	feb14183          	lbu	gp,-21(sp)

000003b4 <slli_117>:
     3b4:	003181b3          	add	gp,gp,gp
     3b8:	fe312423          	sw	gp,-24(sp)
     3bc:	fe914183          	lbu	gp,-23(sp)

000003c0 <slli_119>:
     3c0:	003181b3          	add	gp,gp,gp
     3c4:	fe912423          	sw	s1,-24(sp)
     3c8:	feb14203          	lbu	tp,-21(sp)

000003cc <slli_122>:
     3cc:	00420233          	add	tp,tp,tp
     3d0:	fe412423          	sw	tp,-24(sp)
     3d4:	fe914203          	lbu	tp,-23(sp)
     3d8:	004181b3          	add	gp,gp,tp

000003dc <slli_124>:
     3dc:	003181b3          	add	gp,gp,gp

000003e0 <sub_125>:
     3e0:	fe312a23          	sw	gp,-12(sp)
     3e4:	fe912423          	sw	s1,-24(sp)
     3e8:	00033237          	lui	tp,0x33
     3ec:	b0020213          	addi	tp,tp,-1280 # 32b00 <_logic_shift_table+0x2ff00>
     3f0:	feb14183          	lbu	gp,-21(sp)
     3f4:	004181b3          	add	gp,gp,tp
     3f8:	0001c183          	lbu	gp,0(gp)
     3fc:	fe3103a3          	sb	gp,-25(sp)
     400:	fea14183          	lbu	gp,-22(sp)
     404:	004181b3          	add	gp,gp,tp
     408:	0001c183          	lbu	gp,0(gp)
     40c:	fe310323          	sb	gp,-26(sp)
     410:	fe914183          	lbu	gp,-23(sp)
     414:	004181b3          	add	gp,gp,tp
     418:	0001c183          	lbu	gp,0(gp)
     41c:	fe3102a3          	sb	gp,-27(sp)
     420:	fe814183          	lbu	gp,-24(sp)
     424:	004181b3          	add	gp,gp,tp
     428:	0001c183          	lbu	gp,0(gp)
     42c:	fe310223          	sb	gp,-28(sp)
     430:	ff412183          	lw	gp,-12(sp)
     434:	fe412203          	lw	tp,-28(sp)
     438:	00440233          	add	tp,s0,tp
     43c:	00120213          	addi	tp,tp,1 # 1 <_start+0x1>
     440:	fe412423          	sw	tp,-24(sp)
     444:	feb14203          	lbu	tp,-21(sp)

00000448 <slli_130>:
     448:	00420233          	add	tp,tp,tp
     44c:	fe412423          	sw	tp,-24(sp)
     450:	fe914203          	lbu	tp,-23(sp)
     454:	004181b3          	add	gp,gp,tp
     458:	00003237          	lui	tp,0x3
     45c:	b0820213          	addi	tp,tp,-1272 # 2b08 <_slt1_table>
     460:	00320233          	add	tp,tp,gp
     464:	ff812483          	lw	s1,-8(sp)
     468:	ffc12403          	lw	s0,-4(sp)
     46c:	00024203          	lbu	tp,0(tp) # 0 <_start>

00000470 <slli_134>:
     470:	00420233          	add	tp,tp,tp
     474:	00420233          	add	tp,tp,tp
     478:	00410233          	add	tp,sp,tp
     47c:	000011b7          	lui	gp,0x1
     480:	86418193          	addi	gp,gp,-1948 # 864 <non_taken_182.L12+0x30>
     484:	fe312823          	sw	gp,-16(sp)
     488:	49800193          	addi	gp,zero,1176
     48c:	fe312623          	sw	gp,-20(sp)
     490:	fec22203          	lw	tp,-20(tp) # ffffffec <_end+0xfff6cfec>
     494:	00020067          	jalr	zero,0(tp) # 0 <_start>

00000498 <non_taken_112.L31>:
     498:	00f787b3          	add	a5,a5,a5
     49c:	00f787b3          	add	a5,a5,a5
     4a0:	00f787b3          	add	a5,a5,a5
     4a4:	00f787b3          	add	a5,a5,a5
     4a8:	00f787b3          	add	a5,a5,a5
     4ac:	00f787b3          	add	a5,a5,a5
     4b0:	00f787b3          	add	a5,a5,a5
     4b4:	00f787b3          	add	a5,a5,a5
     4b8:	00d787b3          	add	a5,a5,a3

000004bc <slli_138>:
     4bc:	00f787b3          	add	a5,a5,a5
     4c0:	00f787b3          	add	a5,a5,a5
     4c4:	20000437          	lui	s0,0x20000
     4c8:	00f40433          	add	s0,s0,a5
     4cc:	00812783          	lw	a5,8(sp)

000004d0 <slli_139>:
     4d0:	00c60633          	add	a2,a2,a2
     4d4:	00c60633          	add	a2,a2,a2

000004d8 <bge_141.L9>:
     4d8:	fef12423          	sw	a5,-24(sp)
     4dc:	feb14183          	lbu	gp,-21(sp)

000004e0 <slli_144>:
     4e0:	003181b3          	add	gp,gp,gp
     4e4:	fe312423          	sw	gp,-24(sp)
     4e8:	fe914183          	lbu	gp,-23(sp)
     4ec:	fff78213          	addi	tp,a5,-1
     4f0:	fe412423          	sw	tp,-24(sp)
     4f4:	feb14203          	lbu	tp,-21(sp)

000004f8 <slli_148>:
     4f8:	00420233          	add	tp,tp,tp
     4fc:	fe412423          	sw	tp,-24(sp)
     500:	fe914203          	lbu	tp,-23(sp)
     504:	004181b3          	add	gp,gp,tp
     508:	00003237          	lui	tp,0x3
     50c:	b1820213          	addi	tp,tp,-1256 # 2b18 <_or1_table>
     510:	00418233          	add	tp,gp,tp
     514:	00024203          	lbu	tp,0(tp) # 0 <_start>

00000518 <slli_152>:
     518:	00420233          	add	tp,tp,tp
     51c:	00420233          	add	tp,tp,tp
     520:	00410233          	add	tp,sp,tp
     524:	65800193          	addi	gp,zero,1624
     528:	fe312823          	sw	gp,-16(sp)
     52c:	53c00193          	addi	gp,zero,1340
     530:	fe312623          	sw	gp,-20(sp)
     534:	fec22203          	lw	tp,-20(tp) # ffffffec <_end+0xfff6cfec>
     538:	00020067          	jalr	zero,0(tp) # 0 <_start>

0000053c <non_taken_141.L9>:
     53c:	00912623          	sw	s1,12(sp)
     540:	00000493          	addi	s1,zero,0
     544:	00040513          	addi	a0,s0,0 # 20000000 <_end+0x1ff6d000>
     548:	00c12223          	sw	a2,4(sp)
     54c:	00b12023          	sw	a1,0(sp)
     550:	000010b7          	lui	ra,0x1
     554:	de008093          	addi	ra,ra,-544 # de0 <memcpy>
     558:	000080e7          	jalr	ra,0(ra)
     55c:	00012583          	lw	a1,0(sp)
     560:	00412603          	lw	a2,4(sp)
     564:	00812783          	lw	a5,8(sp)
     568:	00148493          	addi	s1,s1,1
     56c:	40040413          	addi	s0,s0,1024
     570:	00c585b3          	add	a1,a1,a2

00000574 <bne_158.L18>:
     574:	fef12823          	sw	a5,-16(sp)
     578:	fe912623          	sw	s1,-20(sp)
     57c:	fe812e23          	sw	s0,-4(sp)
     580:	fe912c23          	sw	s1,-8(sp)
     584:	0004b437          	lui	s0,0x4b
     588:	d0040413          	addi	s0,s0,-768 # 4ad00 <_check_same_array>
     58c:	ff014183          	lbu	gp,-16(sp)
     590:	00340233          	add	tp,s0,gp
     594:	00100193          	addi	gp,zero,1
     598:	00320023          	sb	gp,0(tp) # 0 <_start>
     59c:	fec14183          	lbu	gp,-20(sp)
     5a0:	003401b3          	add	gp,s0,gp
     5a4:	00018023          	sb	zero,0(gp)
     5a8:	00024183          	lbu	gp,0(tp) # 0 <_start>
     5ac:	ff114483          	lbu	s1,-15(sp)
     5b0:	00940233          	add	tp,s0,s1
     5b4:	00100493          	addi	s1,zero,1
     5b8:	00920023          	sb	s1,0(tp) # 0 <_start>
     5bc:	fed14483          	lbu	s1,-19(sp)
     5c0:	009404b3          	add	s1,s0,s1
     5c4:	00048023          	sb	zero,0(s1)
     5c8:	00024483          	lbu	s1,0(tp) # 0 <_start>
     5cc:	009181b3          	add	gp,gp,s1
     5d0:	ff214483          	lbu	s1,-14(sp)
     5d4:	00940233          	add	tp,s0,s1
     5d8:	00100493          	addi	s1,zero,1
     5dc:	00920023          	sb	s1,0(tp) # 0 <_start>
     5e0:	fee14483          	lbu	s1,-18(sp)
     5e4:	009404b3          	add	s1,s0,s1
     5e8:	00048023          	sb	zero,0(s1)
     5ec:	00024483          	lbu	s1,0(tp) # 0 <_start>
     5f0:	009181b3          	add	gp,gp,s1
     5f4:	ff314483          	lbu	s1,-13(sp)
     5f8:	00940233          	add	tp,s0,s1
     5fc:	00100493          	addi	s1,zero,1
     600:	00920023          	sb	s1,0(tp) # 0 <_start>
     604:	fef14483          	lbu	s1,-17(sp)
     608:	009404b3          	add	s1,s0,s1
     60c:	00048023          	sb	zero,0(s1)
     610:	00024483          	lbu	s1,0(tp) # 0 <_start>
     614:	009181b3          	add	gp,gp,s1
     618:	00003237          	lui	tp,0x3
     61c:	a0020213          	addi	tp,tp,-1536 # 2a00 <_same_result_table>
     620:	00320233          	add	tp,tp,gp
     624:	00024203          	lbu	tp,0(tp) # 0 <_start>
     628:	ff812483          	lw	s1,-8(sp)
     62c:	ffc12403          	lw	s0,-4(sp)

00000630 <slli_167>:
     630:	00420233          	add	tp,tp,tp
     634:	00420233          	add	tp,tp,tp
     638:	00410233          	add	tp,sp,tp
     63c:	65400193          	addi	gp,zero,1620
     640:	fe312823          	sw	gp,-16(sp)
     644:	54400193          	addi	gp,zero,1348
     648:	fe312623          	sw	gp,-20(sp)
     64c:	fec22203          	lw	tp,-20(tp) # ffffffec <_end+0xfff6cfec>
     650:	00020067          	jalr	zero,0(tp) # 0 <_start>

00000654 <non_taken_158.L18>:
     654:	00c12483          	lw	s1,12(sp)
     658:	01012403          	lw	s0,16(sp)
     65c:	01412083          	lw	ra,20(sp)
     660:	01810113          	addi	sp,sp,24
     664:	00008067          	jalr	zero,0(ra)
     668:	10000713          	addi	a4,zero,256

0000066c <bne_170.L11>:
     66c:	fec12823          	sw	a2,-16(sp)
     670:	fee12623          	sw	a4,-20(sp)
     674:	fe812e23          	sw	s0,-4(sp)
     678:	fe912c23          	sw	s1,-8(sp)
     67c:	0004b437          	lui	s0,0x4b
     680:	d0040413          	addi	s0,s0,-768 # 4ad00 <_check_same_array>
     684:	ff014183          	lbu	gp,-16(sp)
     688:	00340233          	add	tp,s0,gp
     68c:	00100193          	addi	gp,zero,1
     690:	00320023          	sb	gp,0(tp) # 0 <_start>
     694:	fec14183          	lbu	gp,-20(sp)
     698:	003401b3          	add	gp,s0,gp
     69c:	00018023          	sb	zero,0(gp)
     6a0:	00024183          	lbu	gp,0(tp) # 0 <_start>
     6a4:	ff114483          	lbu	s1,-15(sp)
     6a8:	00940233          	add	tp,s0,s1
     6ac:	00100493          	addi	s1,zero,1
     6b0:	00920023          	sb	s1,0(tp) # 0 <_start>
     6b4:	fed14483          	lbu	s1,-19(sp)
     6b8:	009404b3          	add	s1,s0,s1
     6bc:	00048023          	sb	zero,0(s1)
     6c0:	00024483          	lbu	s1,0(tp) # 0 <_start>
     6c4:	009181b3          	add	gp,gp,s1
     6c8:	ff214483          	lbu	s1,-14(sp)
     6cc:	00940233          	add	tp,s0,s1
     6d0:	00100493          	addi	s1,zero,1
     6d4:	00920023          	sb	s1,0(tp) # 0 <_start>
     6d8:	fee14483          	lbu	s1,-18(sp)
     6dc:	009404b3          	add	s1,s0,s1
     6e0:	00048023          	sb	zero,0(s1)
     6e4:	00024483          	lbu	s1,0(tp) # 0 <_start>
     6e8:	009181b3          	add	gp,gp,s1
     6ec:	ff314483          	lbu	s1,-13(sp)
     6f0:	00940233          	add	tp,s0,s1
     6f4:	00100493          	addi	s1,zero,1
     6f8:	00920023          	sb	s1,0(tp) # 0 <_start>
     6fc:	fef14483          	lbu	s1,-17(sp)
     700:	009404b3          	add	s1,s0,s1
     704:	00048023          	sb	zero,0(s1)
     708:	00024483          	lbu	s1,0(tp) # 0 <_start>
     70c:	009181b3          	add	gp,gp,s1
     710:	00003237          	lui	tp,0x3
     714:	a0020213          	addi	tp,tp,-1536 # 2a00 <_same_result_table>
     718:	00320233          	add	tp,tp,gp
     71c:	00024203          	lbu	tp,0(tp) # 0 <_start>
     720:	ff812483          	lw	s1,-8(sp)
     724:	ffc12403          	lw	s0,-4(sp)

00000728 <slli_179>:
     728:	00420233          	add	tp,tp,tp
     72c:	00420233          	add	tp,tp,tp
     730:	00410233          	add	tp,sp,tp
     734:	74c00193          	addi	gp,zero,1868
     738:	fe312823          	sw	gp,-16(sp)
     73c:	28000193          	addi	gp,zero,640
     740:	fe312623          	sw	gp,-20(sp)
     744:	fec22203          	lw	tp,-20(tp) # ffffffec <_end+0xfff6cfec>
     748:	00020067          	jalr	zero,0(tp) # 0 <_start>

0000074c <non_taken_170.L11>:
     74c:	00812703          	lw	a4,8(sp)

00000750 <bne_182.L12>:
     750:	fee12823          	sw	a4,-16(sp)
     754:	fec12623          	sw	a2,-20(sp)
     758:	fe812e23          	sw	s0,-4(sp)
     75c:	fe912c23          	sw	s1,-8(sp)
     760:	0004b437          	lui	s0,0x4b
     764:	d0040413          	addi	s0,s0,-768 # 4ad00 <_check_same_array>
     768:	ff014183          	lbu	gp,-16(sp)
     76c:	00340233          	add	tp,s0,gp
     770:	00100193          	addi	gp,zero,1
     774:	00320023          	sb	gp,0(tp) # 0 <_start>
     778:	fec14183          	lbu	gp,-20(sp)
     77c:	003401b3          	add	gp,s0,gp
     780:	00018023          	sb	zero,0(gp)
     784:	00024183          	lbu	gp,0(tp) # 0 <_start>
     788:	ff114483          	lbu	s1,-15(sp)
     78c:	00940233          	add	tp,s0,s1
     790:	00100493          	addi	s1,zero,1
     794:	00920023          	sb	s1,0(tp) # 0 <_start>
     798:	fed14483          	lbu	s1,-19(sp)
     79c:	009404b3          	add	s1,s0,s1
     7a0:	00048023          	sb	zero,0(s1)
     7a4:	00024483          	lbu	s1,0(tp) # 0 <_start>
     7a8:	009181b3          	add	gp,gp,s1
     7ac:	ff214483          	lbu	s1,-14(sp)
     7b0:	00940233          	add	tp,s0,s1
     7b4:	00100493          	addi	s1,zero,1
     7b8:	00920023          	sb	s1,0(tp) # 0 <_start>
     7bc:	fee14483          	lbu	s1,-18(sp)
     7c0:	009404b3          	add	s1,s0,s1
     7c4:	00048023          	sb	zero,0(s1)
     7c8:	00024483          	lbu	s1,0(tp) # 0 <_start>
     7cc:	009181b3          	add	gp,gp,s1
     7d0:	ff314483          	lbu	s1,-13(sp)
     7d4:	00940233          	add	tp,s0,s1
     7d8:	00100493          	addi	s1,zero,1
     7dc:	00920023          	sb	s1,0(tp) # 0 <_start>
     7e0:	fef14483          	lbu	s1,-17(sp)
     7e4:	009404b3          	add	s1,s0,s1
     7e8:	00048023          	sb	zero,0(s1)
     7ec:	00024483          	lbu	s1,0(tp) # 0 <_start>
     7f0:	009181b3          	add	gp,gp,s1
     7f4:	00003237          	lui	tp,0x3
     7f8:	a0020213          	addi	tp,tp,-1536 # 2a00 <_same_result_table>
     7fc:	00320233          	add	tp,tp,gp
     800:	00024203          	lbu	tp,0(tp) # 0 <_start>
     804:	ff812483          	lw	s1,-8(sp)
     808:	ffc12403          	lw	s0,-4(sp)

0000080c <slli_191>:
     80c:	00420233          	add	tp,tp,tp
     810:	00420233          	add	tp,tp,tp
     814:	00410233          	add	tp,sp,tp
     818:	000011b7          	lui	gp,0x1
     81c:	83418193          	addi	gp,gp,-1996 # 834 <non_taken_182.L12>
     820:	fe312823          	sw	gp,-16(sp)
     824:	38800193          	addi	gp,zero,904
     828:	fe312623          	sw	gp,-20(sp)
     82c:	fec22203          	lw	tp,-20(tp) # ffffffec <_end+0xfff6cfec>
     830:	00020067          	jalr	zero,0(tp) # 0 <_start>

00000834 <non_taken_182.L12>:
     834:	01412083          	lw	ra,20(sp)
     838:	00040637          	lui	a2,0x40
     83c:	20000537          	lui	a0,0x20000
     840:	01810113          	addi	sp,sp,24
     844:	00001237          	lui	tp,0x1
     848:	de020213          	addi	tp,tp,-544 # de0 <memcpy>
     84c:	00020067          	jalr	zero,0(tp) # 0 <_start>
     850:	000010b7          	lui	ra,0x1
     854:	de008093          	addi	ra,ra,-544 # de0 <memcpy>
     858:	000080e7          	jalr	ra,0(ra)
     85c:	00008067          	jalr	zero,0(ra)
     860:	00812823          	sw	s0,16(sp)
     864:	0004b437          	lui	s0,0x4b
     868:	c0040413          	addi	s0,s0,-1024 # 4ac00 <_logic_shift_table+0x48000>
     86c:	04100513          	addi	a0,zero,65
     870:	00912623          	sw	s1,12(sp)
     874:	000010b7          	lui	ra,0x1
     878:	da408093          	addi	ra,ra,-604 # da4 <putch>
     87c:	000080e7          	jalr	ra,0(ra)
     880:	00144503          	lbu	a0,1(s0)
     884:	00140413          	addi	s0,s0,1

00000888 <bne_203.L15>:
     888:	fea12823          	sw	a0,-16(sp)
     88c:	fe812e23          	sw	s0,-4(sp)
     890:	00003437          	lui	s0,0x3
     894:	a0840413          	addi	s0,s0,-1528 # 2a08 <_check_8bit_0_table>
     898:	ff014183          	lbu	gp,-16(sp)
     89c:	003401b3          	add	gp,s0,gp
     8a0:	0001c183          	lbu	gp,0(gp)
     8a4:	ff114203          	lbu	tp,-15(sp)
     8a8:	00440233          	add	tp,s0,tp
     8ac:	00024203          	lbu	tp,0(tp) # 0 <_start>
     8b0:	004181b3          	add	gp,gp,tp
     8b4:	ff214203          	lbu	tp,-14(sp)
     8b8:	00440233          	add	tp,s0,tp
     8bc:	00024203          	lbu	tp,0(tp) # 0 <_start>
     8c0:	004181b3          	add	gp,gp,tp
     8c4:	ff314203          	lbu	tp,-13(sp)
     8c8:	00440233          	add	tp,s0,tp
     8cc:	00024203          	lbu	tp,0(tp) # 0 <_start>
     8d0:	004181b3          	add	gp,gp,tp
     8d4:	00003237          	lui	tp,0x3
     8d8:	a0020213          	addi	tp,tp,-1536 # 2a00 <_same_result_table>
     8dc:	00320233          	add	tp,tp,gp
     8e0:	00024203          	lbu	tp,0(tp) # 0 <_start>
     8e4:	ffc12403          	lw	s0,-4(sp)

000008e8 <slli_212>:
     8e8:	00420233          	add	tp,tp,tp
     8ec:	00420233          	add	tp,tp,tp
     8f0:	00410233          	add	tp,sp,tp
     8f4:	000011b7          	lui	gp,0x1
     8f8:	91418193          	addi	gp,gp,-1772 # 914 <non_taken_203.L15>
     8fc:	fe312823          	sw	gp,-16(sp)
     900:	000011b7          	lui	gp,0x1
     904:	87418193          	addi	gp,gp,-1932 # 874 <non_taken_182.L12+0x40>
     908:	fe312623          	sw	gp,-20(sp)
     90c:	fec22203          	lw	tp,-20(tp) # ffffffec <_end+0xfff6cfec>
     910:	00020067          	jalr	zero,0(tp) # 0 <_start>

00000914 <non_taken_203.L15>:
     914:	0004b437          	lui	s0,0x4b
     918:	c0c40413          	addi	s0,s0,-1012 # 4ac0c <_logic_shift_table+0x4800c>
     91c:	06200513          	addi	a0,zero,98
     920:	000010b7          	lui	ra,0x1
     924:	da408093          	addi	ra,ra,-604 # da4 <putch>
     928:	000080e7          	jalr	ra,0(ra)
     92c:	00144503          	lbu	a0,1(s0)
     930:	00140413          	addi	s0,s0,1

00000934 <bne_220.L16>:
     934:	fea12823          	sw	a0,-16(sp)
     938:	fe812e23          	sw	s0,-4(sp)
     93c:	00003437          	lui	s0,0x3
     940:	a0840413          	addi	s0,s0,-1528 # 2a08 <_check_8bit_0_table>
     944:	ff014183          	lbu	gp,-16(sp)
     948:	003401b3          	add	gp,s0,gp
     94c:	0001c183          	lbu	gp,0(gp)
     950:	ff114203          	lbu	tp,-15(sp)
     954:	00440233          	add	tp,s0,tp
     958:	00024203          	lbu	tp,0(tp) # 0 <_start>
     95c:	004181b3          	add	gp,gp,tp
     960:	ff214203          	lbu	tp,-14(sp)
     964:	00440233          	add	tp,s0,tp
     968:	00024203          	lbu	tp,0(tp) # 0 <_start>
     96c:	004181b3          	add	gp,gp,tp
     970:	ff314203          	lbu	tp,-13(sp)
     974:	00440233          	add	tp,s0,tp
     978:	00024203          	lbu	tp,0(tp) # 0 <_start>
     97c:	004181b3          	add	gp,gp,tp
     980:	00003237          	lui	tp,0x3
     984:	a0020213          	addi	tp,tp,-1536 # 2a00 <_same_result_table>
     988:	00320233          	add	tp,tp,gp
     98c:	00024203          	lbu	tp,0(tp) # 0 <_start>
     990:	ffc12403          	lw	s0,-4(sp)

00000994 <slli_229>:
     994:	00420233          	add	tp,tp,tp
     998:	00420233          	add	tp,tp,tp
     99c:	00410233          	add	tp,sp,tp
     9a0:	000011b7          	lui	gp,0x1
     9a4:	9c018193          	addi	gp,gp,-1600 # 9c0 <non_taken_220.L16>
     9a8:	fe312823          	sw	gp,-16(sp)
     9ac:	000011b7          	lui	gp,0x1
     9b0:	92018193          	addi	gp,gp,-1760 # 920 <non_taken_203.L15+0xc>
     9b4:	fe312623          	sw	gp,-20(sp)
     9b8:	fec22203          	lw	tp,-20(tp) # ffffffec <_end+0xfff6cfec>
     9bc:	00020067          	jalr	zero,0(tp) # 0 <_start>

000009c0 <non_taken_220.L16>:
     9c0:	0004b437          	lui	s0,0x4b
     9c4:	c2040413          	addi	s0,s0,-992 # 4ac20 <_logic_shift_table+0x48020>
     9c8:	02000513          	addi	a0,zero,32
     9cc:	000010b7          	lui	ra,0x1
     9d0:	da408093          	addi	ra,ra,-604 # da4 <putch>
     9d4:	000080e7          	jalr	ra,0(ra)
     9d8:	00144503          	lbu	a0,1(s0)
     9dc:	00140413          	addi	s0,s0,1

000009e0 <bne_237.L17>:
     9e0:	fea12823          	sw	a0,-16(sp)
     9e4:	fe812e23          	sw	s0,-4(sp)
     9e8:	00003437          	lui	s0,0x3
     9ec:	a0840413          	addi	s0,s0,-1528 # 2a08 <_check_8bit_0_table>
     9f0:	ff014183          	lbu	gp,-16(sp)
     9f4:	003401b3          	add	gp,s0,gp
     9f8:	0001c183          	lbu	gp,0(gp)
     9fc:	ff114203          	lbu	tp,-15(sp)
     a00:	00440233          	add	tp,s0,tp
     a04:	00024203          	lbu	tp,0(tp) # 0 <_start>
     a08:	004181b3          	add	gp,gp,tp
     a0c:	ff214203          	lbu	tp,-14(sp)
     a10:	00440233          	add	tp,s0,tp
     a14:	00024203          	lbu	tp,0(tp) # 0 <_start>
     a18:	004181b3          	add	gp,gp,tp
     a1c:	ff314203          	lbu	tp,-13(sp)
     a20:	00440233          	add	tp,s0,tp
     a24:	00024203          	lbu	tp,0(tp) # 0 <_start>
     a28:	004181b3          	add	gp,gp,tp
     a2c:	00003237          	lui	tp,0x3
     a30:	a0020213          	addi	tp,tp,-1536 # 2a00 <_same_result_table>
     a34:	00320233          	add	tp,tp,gp
     a38:	00024203          	lbu	tp,0(tp) # 0 <_start>
     a3c:	ffc12403          	lw	s0,-4(sp)

00000a40 <slli_246>:
     a40:	00420233          	add	tp,tp,tp
     a44:	00420233          	add	tp,tp,tp
     a48:	00410233          	add	tp,sp,tp
     a4c:	000011b7          	lui	gp,0x1
     a50:	a6c18193          	addi	gp,gp,-1428 # a6c <non_taken_237.L17>
     a54:	fe312823          	sw	gp,-16(sp)
     a58:	000011b7          	lui	gp,0x1
     a5c:	9cc18193          	addi	gp,gp,-1588 # 9cc <non_taken_220.L16+0xc>
     a60:	fe312623          	sw	gp,-20(sp)
     a64:	fec22203          	lw	tp,-20(tp) # ffffffec <_end+0xfff6cfec>
     a68:	00020067          	jalr	zero,0(tp) # 0 <_start>

00000a6c <non_taken_237.L17>:
     a6c:	00100513          	addi	a0,zero,1
     a70:	000010b7          	lui	ra,0x1
     a74:	db008093          	addi	ra,ra,-592 # db0 <halt>
     a78:	000080e7          	jalr	ra,0(ra)

00000a7c <ioe_init>:
     a7c:	00100513          	addi	a0,zero,1
     a80:	00008067          	jalr	zero,0(ra)

00000a84 <ioe_write>:
     a84:	00b00793          	addi	a5,zero,11

00000a88 <bne_255.L46>:
     a88:	fea12823          	sw	a0,-16(sp)
     a8c:	fef12623          	sw	a5,-20(sp)
     a90:	fe812e23          	sw	s0,-4(sp)
     a94:	fe912c23          	sw	s1,-8(sp)
     a98:	0004b437          	lui	s0,0x4b
     a9c:	d0040413          	addi	s0,s0,-768 # 4ad00 <_check_same_array>
     aa0:	ff014183          	lbu	gp,-16(sp)
     aa4:	00340233          	add	tp,s0,gp
     aa8:	00100193          	addi	gp,zero,1
     aac:	00320023          	sb	gp,0(tp) # 0 <_start>
     ab0:	fec14183          	lbu	gp,-20(sp)
     ab4:	003401b3          	add	gp,s0,gp
     ab8:	00018023          	sb	zero,0(gp)
     abc:	00024183          	lbu	gp,0(tp) # 0 <_start>
     ac0:	ff114483          	lbu	s1,-15(sp)
     ac4:	00940233          	add	tp,s0,s1
     ac8:	00100493          	addi	s1,zero,1
     acc:	00920023          	sb	s1,0(tp) # 0 <_start>
     ad0:	fed14483          	lbu	s1,-19(sp)
     ad4:	009404b3          	add	s1,s0,s1
     ad8:	00048023          	sb	zero,0(s1)
     adc:	00024483          	lbu	s1,0(tp) # 0 <_start>
     ae0:	009181b3          	add	gp,gp,s1
     ae4:	ff214483          	lbu	s1,-14(sp)
     ae8:	00940233          	add	tp,s0,s1
     aec:	00100493          	addi	s1,zero,1
     af0:	00920023          	sb	s1,0(tp) # 0 <_start>
     af4:	fee14483          	lbu	s1,-18(sp)
     af8:	009404b3          	add	s1,s0,s1
     afc:	00048023          	sb	zero,0(s1)
     b00:	00024483          	lbu	s1,0(tp) # 0 <_start>
     b04:	009181b3          	add	gp,gp,s1
     b08:	ff314483          	lbu	s1,-13(sp)
     b0c:	00940233          	add	tp,s0,s1
     b10:	00100493          	addi	s1,zero,1
     b14:	00920023          	sb	s1,0(tp) # 0 <_start>
     b18:	fef14483          	lbu	s1,-17(sp)
     b1c:	009404b3          	add	s1,s0,s1
     b20:	00048023          	sb	zero,0(s1)
     b24:	00024483          	lbu	s1,0(tp) # 0 <_start>
     b28:	009181b3          	add	gp,gp,s1
     b2c:	00003237          	lui	tp,0x3
     b30:	a0020213          	addi	tp,tp,-1536 # 2a00 <_same_result_table>
     b34:	00320233          	add	tp,tp,gp
     b38:	00024203          	lbu	tp,0(tp) # 0 <_start>
     b3c:	ff812483          	lw	s1,-8(sp)
     b40:	ffc12403          	lw	s0,-4(sp)

00000b44 <slli_264>:
     b44:	00420233          	add	tp,tp,tp
     b48:	00420233          	add	tp,tp,tp
     b4c:	00410233          	add	tp,sp,tp
     b50:	000011b7          	lui	gp,0x1
     b54:	b7018193          	addi	gp,gp,-1168 # b70 <non_taken_255.L46>
     b58:	fe312823          	sw	gp,-16(sp)
     b5c:	000011b7          	lui	gp,0x1
     b60:	b8418193          	addi	gp,gp,-1148 # b84 <non_taken_255.L46+0x14>
     b64:	fe312623          	sw	gp,-20(sp)
     b68:	fec22203          	lw	tp,-20(tp) # ffffffec <_end+0xfff6cfec>
     b6c:	00020067          	jalr	zero,0(tp) # 0 <_start>

00000b70 <non_taken_255.L46>:
     b70:	00058513          	addi	a0,a1,0
     b74:	0bc00213          	addi	tp,zero,188
     b78:	00020067          	jalr	zero,0(tp) # 0 <_start>
     b7c:	0bc00093          	addi	ra,zero,188
     b80:	000080e7          	jalr	ra,0(ra)
     b84:	ff410113          	addi	sp,sp,-12
     b88:	00812223          	sw	s0,4(sp)
     b8c:	00112423          	sw	ra,8(sp)
     b90:	0004b437          	lui	s0,0x4b
     b94:	c0040413          	addi	s0,s0,-1024 # 4ac00 <_logic_shift_table+0x48000>
     b98:	04100513          	addi	a0,zero,65
     b9c:	000010b7          	lui	ra,0x1
     ba0:	da408093          	addi	ra,ra,-604 # da4 <putch>
     ba4:	000080e7          	jalr	ra,0(ra)
     ba8:	00144503          	lbu	a0,1(s0)
     bac:	00140413          	addi	s0,s0,1

00000bb0 <bne_276.L37>:
     bb0:	fea12823          	sw	a0,-16(sp)
     bb4:	fe812e23          	sw	s0,-4(sp)
     bb8:	00003437          	lui	s0,0x3
     bbc:	a0840413          	addi	s0,s0,-1528 # 2a08 <_check_8bit_0_table>
     bc0:	ff014183          	lbu	gp,-16(sp)
     bc4:	003401b3          	add	gp,s0,gp
     bc8:	0001c183          	lbu	gp,0(gp)
     bcc:	ff114203          	lbu	tp,-15(sp)
     bd0:	00440233          	add	tp,s0,tp
     bd4:	00024203          	lbu	tp,0(tp) # 0 <_start>
     bd8:	004181b3          	add	gp,gp,tp
     bdc:	ff214203          	lbu	tp,-14(sp)
     be0:	00440233          	add	tp,s0,tp
     be4:	00024203          	lbu	tp,0(tp) # 0 <_start>
     be8:	004181b3          	add	gp,gp,tp
     bec:	ff314203          	lbu	tp,-13(sp)
     bf0:	00440233          	add	tp,s0,tp
     bf4:	00024203          	lbu	tp,0(tp) # 0 <_start>
     bf8:	004181b3          	add	gp,gp,tp
     bfc:	00003237          	lui	tp,0x3
     c00:	a0020213          	addi	tp,tp,-1536 # 2a00 <_same_result_table>
     c04:	00320233          	add	tp,tp,gp
     c08:	00024203          	lbu	tp,0(tp) # 0 <_start>
     c0c:	ffc12403          	lw	s0,-4(sp)

00000c10 <slli_285>:
     c10:	00420233          	add	tp,tp,tp
     c14:	00420233          	add	tp,tp,tp
     c18:	00410233          	add	tp,sp,tp
     c1c:	000011b7          	lui	gp,0x1
     c20:	c3c18193          	addi	gp,gp,-964 # c3c <non_taken_276.L37>
     c24:	fe312823          	sw	gp,-16(sp)
     c28:	000011b7          	lui	gp,0x1
     c2c:	b9c18193          	addi	gp,gp,-1124 # b9c <non_taken_255.L46+0x2c>
     c30:	fe312623          	sw	gp,-20(sp)
     c34:	fec22203          	lw	tp,-20(tp) # ffffffec <_end+0xfff6cfec>
     c38:	00020067          	jalr	zero,0(tp) # 0 <_start>

00000c3c <non_taken_276.L37>:
     c3c:	0004b437          	lui	s0,0x4b
     c40:	c6440413          	addi	s0,s0,-924 # 4ac64 <_logic_shift_table+0x48064>
     c44:	06900513          	addi	a0,zero,105
     c48:	000010b7          	lui	ra,0x1
     c4c:	da408093          	addi	ra,ra,-604 # da4 <putch>
     c50:	000080e7          	jalr	ra,0(ra)
     c54:	00144503          	lbu	a0,1(s0)
     c58:	00140413          	addi	s0,s0,1

00000c5c <bne_293.L38>:
     c5c:	fea12823          	sw	a0,-16(sp)
     c60:	fe812e23          	sw	s0,-4(sp)
     c64:	00003437          	lui	s0,0x3
     c68:	a0840413          	addi	s0,s0,-1528 # 2a08 <_check_8bit_0_table>
     c6c:	ff014183          	lbu	gp,-16(sp)
     c70:	003401b3          	add	gp,s0,gp
     c74:	0001c183          	lbu	gp,0(gp)
     c78:	ff114203          	lbu	tp,-15(sp)
     c7c:	00440233          	add	tp,s0,tp
     c80:	00024203          	lbu	tp,0(tp) # 0 <_start>
     c84:	004181b3          	add	gp,gp,tp
     c88:	ff214203          	lbu	tp,-14(sp)
     c8c:	00440233          	add	tp,s0,tp
     c90:	00024203          	lbu	tp,0(tp) # 0 <_start>
     c94:	004181b3          	add	gp,gp,tp
     c98:	ff314203          	lbu	tp,-13(sp)
     c9c:	00440233          	add	tp,s0,tp
     ca0:	00024203          	lbu	tp,0(tp) # 0 <_start>
     ca4:	004181b3          	add	gp,gp,tp
     ca8:	00003237          	lui	tp,0x3
     cac:	a0020213          	addi	tp,tp,-1536 # 2a00 <_same_result_table>
     cb0:	00320233          	add	tp,tp,gp
     cb4:	00024203          	lbu	tp,0(tp) # 0 <_start>
     cb8:	ffc12403          	lw	s0,-4(sp)

00000cbc <slli_302>:
     cbc:	00420233          	add	tp,tp,tp
     cc0:	00420233          	add	tp,tp,tp
     cc4:	00410233          	add	tp,sp,tp
     cc8:	000011b7          	lui	gp,0x1
     ccc:	ce818193          	addi	gp,gp,-792 # ce8 <non_taken_293.L38>
     cd0:	fe312823          	sw	gp,-16(sp)
     cd4:	000011b7          	lui	gp,0x1
     cd8:	c4818193          	addi	gp,gp,-952 # c48 <non_taken_276.L37+0xc>
     cdc:	fe312623          	sw	gp,-20(sp)
     ce0:	fec22203          	lw	tp,-20(tp) # ffffffec <_end+0xfff6cfec>
     ce4:	00020067          	jalr	zero,0(tp) # 0 <_start>

00000ce8 <non_taken_293.L38>:
     ce8:	0004b437          	lui	s0,0x4b
     cec:	c7040413          	addi	s0,s0,-912 # 4ac70 <_logic_shift_table+0x48070>
     cf0:	02000513          	addi	a0,zero,32
     cf4:	000010b7          	lui	ra,0x1
     cf8:	da408093          	addi	ra,ra,-604 # da4 <putch>
     cfc:	000080e7          	jalr	ra,0(ra)
     d00:	00144503          	lbu	a0,1(s0)
     d04:	00140413          	addi	s0,s0,1

00000d08 <bne_310.L39>:
     d08:	fea12823          	sw	a0,-16(sp)
     d0c:	fe812e23          	sw	s0,-4(sp)
     d10:	00003437          	lui	s0,0x3
     d14:	a0840413          	addi	s0,s0,-1528 # 2a08 <_check_8bit_0_table>
     d18:	ff014183          	lbu	gp,-16(sp)
     d1c:	003401b3          	add	gp,s0,gp
     d20:	0001c183          	lbu	gp,0(gp)
     d24:	ff114203          	lbu	tp,-15(sp)
     d28:	00440233          	add	tp,s0,tp
     d2c:	00024203          	lbu	tp,0(tp) # 0 <_start>
     d30:	004181b3          	add	gp,gp,tp
     d34:	ff214203          	lbu	tp,-14(sp)
     d38:	00440233          	add	tp,s0,tp
     d3c:	00024203          	lbu	tp,0(tp) # 0 <_start>
     d40:	004181b3          	add	gp,gp,tp
     d44:	ff314203          	lbu	tp,-13(sp)
     d48:	00440233          	add	tp,s0,tp
     d4c:	00024203          	lbu	tp,0(tp) # 0 <_start>
     d50:	004181b3          	add	gp,gp,tp
     d54:	00003237          	lui	tp,0x3
     d58:	a0020213          	addi	tp,tp,-1536 # 2a00 <_same_result_table>
     d5c:	00320233          	add	tp,tp,gp
     d60:	00024203          	lbu	tp,0(tp) # 0 <_start>
     d64:	ffc12403          	lw	s0,-4(sp)

00000d68 <slli_319>:
     d68:	00420233          	add	tp,tp,tp
     d6c:	00420233          	add	tp,tp,tp
     d70:	00410233          	add	tp,sp,tp
     d74:	000011b7          	lui	gp,0x1
     d78:	d9418193          	addi	gp,gp,-620 # d94 <non_taken_310.L39>
     d7c:	fe312823          	sw	gp,-16(sp)
     d80:	000011b7          	lui	gp,0x1
     d84:	cf418193          	addi	gp,gp,-780 # cf4 <non_taken_293.L38+0xc>
     d88:	fe312623          	sw	gp,-20(sp)
     d8c:	fec22203          	lw	tp,-20(tp) # ffffffec <_end+0xfff6cfec>
     d90:	00020067          	jalr	zero,0(tp) # 0 <_start>

00000d94 <non_taken_310.L39>:
     d94:	00100513          	addi	a0,zero,1
     d98:	000010b7          	lui	ra,0x1
     d9c:	db008093          	addi	ra,ra,-592 # db0 <halt>
     da0:	000080e7          	jalr	ra,0(ra)

00000da4 <putch>:
     da4:	100007b7          	lui	a5,0x10000
     da8:	00a78023          	sb	a0,0(a5) # 10000000 <_end+0xff6d000>
     dac:	00008067          	jalr	zero,0(ra)

00000db0 <halt>:
     db0:	00001237          	lui	tp,0x1
     db4:	db020213          	addi	tp,tp,-592 # db0 <halt>
     db8:	00020067          	jalr	zero,0(tp) # 0 <_start>

00000dbc <_trm_init>:
     dbc:	ff410113          	addi	sp,sp,-12
     dc0:	0004b537          	lui	a0,0x4b
     dc4:	c1c50513          	addi	a0,a0,-996 # 4ac1c <_logic_shift_table+0x4801c>
     dc8:	00112423          	sw	ra,8(sp)
     dcc:	08c00093          	addi	ra,zero,140
     dd0:	000080e7          	jalr	ra,0(ra)
     dd4:	000010b7          	lui	ra,0x1
     dd8:	db008093          	addi	ra,ra,-592 # db0 <halt>
     ddc:	000080e7          	jalr	ra,0(ra)

00000de0 <memcpy>:
     de0:	01f00793          	addi	a5,zero,31

00000de4 <bgeu_471.L89>:
     de4:	fe812e23          	sw	s0,-4(sp)
     de8:	fe912c23          	sw	s1,-8(sp)
     dec:	fec12823          	sw	a2,-16(sp)
     df0:	00078413          	addi	s0,a5,0
     df4:	ff012483          	lw	s1,-16(sp)
     df8:	fe812423          	sw	s0,-24(sp)
     dfc:	feb14183          	lbu	gp,-21(sp)

00000e00 <slli_476>:
     e00:	003181b3          	add	gp,gp,gp
     e04:	fe312423          	sw	gp,-24(sp)
     e08:	fe914183          	lbu	gp,-23(sp)

00000e0c <slli_478>:
     e0c:	003181b3          	add	gp,gp,gp
     e10:	fe912423          	sw	s1,-24(sp)
     e14:	feb14203          	lbu	tp,-21(sp)

00000e18 <slli_481>:
     e18:	00420233          	add	tp,tp,tp
     e1c:	fe412423          	sw	tp,-24(sp)
     e20:	fe914203          	lbu	tp,-23(sp)
     e24:	004181b3          	add	gp,gp,tp

00000e28 <slli_483>:
     e28:	003181b3          	add	gp,gp,gp

00000e2c <sub_484>:
     e2c:	fe312a23          	sw	gp,-12(sp)
     e30:	fe912423          	sw	s1,-24(sp)
     e34:	00033237          	lui	tp,0x33
     e38:	b0020213          	addi	tp,tp,-1280 # 32b00 <_logic_shift_table+0x2ff00>
     e3c:	feb14183          	lbu	gp,-21(sp)
     e40:	004181b3          	add	gp,gp,tp
     e44:	0001c183          	lbu	gp,0(gp)
     e48:	fe3103a3          	sb	gp,-25(sp)
     e4c:	fea14183          	lbu	gp,-22(sp)
     e50:	004181b3          	add	gp,gp,tp
     e54:	0001c183          	lbu	gp,0(gp)
     e58:	fe310323          	sb	gp,-26(sp)
     e5c:	fe914183          	lbu	gp,-23(sp)
     e60:	004181b3          	add	gp,gp,tp
     e64:	0001c183          	lbu	gp,0(gp)
     e68:	fe3102a3          	sb	gp,-27(sp)
     e6c:	fe814183          	lbu	gp,-24(sp)
     e70:	004181b3          	add	gp,gp,tp
     e74:	0001c183          	lbu	gp,0(gp)
     e78:	fe310223          	sb	gp,-28(sp)
     e7c:	ff412183          	lw	gp,-12(sp)
     e80:	fe412203          	lw	tp,-28(sp)
     e84:	00440233          	add	tp,s0,tp
     e88:	00120213          	addi	tp,tp,1 # 1 <_start+0x1>
     e8c:	fe412423          	sw	tp,-24(sp)
     e90:	feb14203          	lbu	tp,-21(sp)

00000e94 <slli_489>:
     e94:	00420233          	add	tp,tp,tp
     e98:	fe412423          	sw	tp,-24(sp)
     e9c:	fe914203          	lbu	tp,-23(sp)
     ea0:	004181b3          	add	gp,gp,tp
     ea4:	00003237          	lui	tp,0x3
     ea8:	b1020213          	addi	tp,tp,-1264 # 2b10 <_sltu1_table>
     eac:	00320233          	add	tp,tp,gp
     eb0:	ff812483          	lw	s1,-8(sp)
     eb4:	ffc12403          	lw	s0,-4(sp)
     eb8:	00024203          	lbu	tp,0(tp) # 0 <_start>

00000ebc <slli_493>:
     ebc:	00420233          	add	tp,tp,tp
     ec0:	00420233          	add	tp,tp,tp
     ec4:	00410233          	add	tp,sp,tp
     ec8:	000011b7          	lui	gp,0x1
     ecc:	ee818193          	addi	gp,gp,-280 # ee8 <non_taken_471.L89>
     ed0:	fe312823          	sw	gp,-16(sp)
     ed4:	000031b7          	lui	gp,0x3
     ed8:	83c18193          	addi	gp,gp,-1988 # 283c <non_taken_858.L108+0x4>
     edc:	fe312623          	sw	gp,-20(sp)
     ee0:	fec22203          	lw	tp,-20(tp) # ffffffec <_end+0xfff6cfec>
     ee4:	00020067          	jalr	zero,0(tp) # 0 <_start>

00000ee8 <non_taken_471.L89>:
     ee8:	fe312a23          	sw	gp,-12(sp)
     eec:	feb12423          	sw	a1,-24(sp)
     ef0:	00033237          	lui	tp,0x33
     ef4:	b0020213          	addi	tp,tp,-1280 # 32b00 <_logic_shift_table+0x2ff00>
     ef8:	feb14183          	lbu	gp,-21(sp)
     efc:	004181b3          	add	gp,gp,tp
     f00:	0001c183          	lbu	gp,0(gp)
     f04:	fe3103a3          	sb	gp,-25(sp)
     f08:	fea14183          	lbu	gp,-22(sp)
     f0c:	004181b3          	add	gp,gp,tp
     f10:	0001c183          	lbu	gp,0(gp)
     f14:	fe310323          	sb	gp,-26(sp)
     f18:	fe914183          	lbu	gp,-23(sp)
     f1c:	004181b3          	add	gp,gp,tp
     f20:	0001c183          	lbu	gp,0(gp)
     f24:	fe3102a3          	sb	gp,-27(sp)
     f28:	fe814183          	lbu	gp,-24(sp)
     f2c:	004181b3          	add	gp,gp,tp
     f30:	0001c183          	lbu	gp,0(gp)
     f34:	fe310223          	sb	gp,-28(sp)
     f38:	ff412183          	lw	gp,-12(sp)
     f3c:	fe412203          	lw	tp,-28(sp)
     f40:	004507b3          	add	a5,a0,tp
     f44:	00178793          	addi	a5,a5,1

00000f48 <andi_499>:
     f48:	00700213          	addi	tp,zero,7

00000f4c <and_500>:
     f4c:	fef12823          	sw	a5,-16(sp)
     f50:	fe412623          	sw	tp,-20(sp)
     f54:	00003737          	lui	a4,0x3
     f58:	c0070713          	addi	a4,a4,-1024 # 2c00 <_logic_shift_table>
     f5c:	fe012223          	sw	zero,-28(sp)
     f60:	ff314203          	lbu	tp,-13(sp)
     f64:	fe4102a3          	sb	tp,-27(sp)
     f68:	fef14203          	lbu	tp,-17(sp)
     f6c:	fe410223          	sb	tp,-28(sp)
     f70:	fe412203          	lw	tp,-28(sp)
     f74:	00470233          	add	tp,a4,tp
     f78:	00024203          	lbu	tp,0(tp) # 0 <_start>
     f7c:	fe4105a3          	sb	tp,-21(sp)
     f80:	ff214203          	lbu	tp,-14(sp)
     f84:	fe4102a3          	sb	tp,-27(sp)
     f88:	fee14203          	lbu	tp,-18(sp)
     f8c:	fe410223          	sb	tp,-28(sp)
     f90:	fe412203          	lw	tp,-28(sp)
     f94:	00470233          	add	tp,a4,tp
     f98:	00024203          	lbu	tp,0(tp) # 0 <_start>
     f9c:	fe410523          	sb	tp,-22(sp)
     fa0:	ff114203          	lbu	tp,-15(sp)
     fa4:	fe4102a3          	sb	tp,-27(sp)
     fa8:	fed14203          	lbu	tp,-19(sp)
     fac:	fe410223          	sb	tp,-28(sp)
     fb0:	fe412203          	lw	tp,-28(sp)
     fb4:	00470233          	add	tp,a4,tp
     fb8:	00024203          	lbu	tp,0(tp) # 0 <_start>
     fbc:	fe4104a3          	sb	tp,-23(sp)
     fc0:	ff014203          	lbu	tp,-16(sp)
     fc4:	fe4102a3          	sb	tp,-27(sp)
     fc8:	fec14203          	lbu	tp,-20(sp)
     fcc:	fe410223          	sb	tp,-28(sp)
     fd0:	fe412203          	lw	tp,-28(sp)
     fd4:	00470233          	add	tp,a4,tp
     fd8:	00024203          	lbu	tp,0(tp) # 0 <_start>
     fdc:	fe410423          	sb	tp,-24(sp)
     fe0:	fe812703          	lw	a4,-24(sp)

00000fe4 <bne_507.L111>:
     fe4:	fee12823          	sw	a4,-16(sp)
     fe8:	fe812e23          	sw	s0,-4(sp)
     fec:	00003437          	lui	s0,0x3
     ff0:	a0840413          	addi	s0,s0,-1528 # 2a08 <_check_8bit_0_table>
     ff4:	ff014183          	lbu	gp,-16(sp)
     ff8:	003401b3          	add	gp,s0,gp
     ffc:	0001c183          	lbu	gp,0(gp)
    1000:	ff114203          	lbu	tp,-15(sp)
    1004:	00440233          	add	tp,s0,tp
    1008:	00024203          	lbu	tp,0(tp) # 0 <_start>
    100c:	004181b3          	add	gp,gp,tp
    1010:	ff214203          	lbu	tp,-14(sp)
    1014:	00440233          	add	tp,s0,tp
    1018:	00024203          	lbu	tp,0(tp) # 0 <_start>
    101c:	004181b3          	add	gp,gp,tp
    1020:	ff314203          	lbu	tp,-13(sp)
    1024:	00440233          	add	tp,s0,tp
    1028:	00024203          	lbu	tp,0(tp) # 0 <_start>
    102c:	004181b3          	add	gp,gp,tp
    1030:	00003237          	lui	tp,0x3
    1034:	a0020213          	addi	tp,tp,-1536 # 2a00 <_same_result_table>
    1038:	00320233          	add	tp,tp,gp
    103c:	00024203          	lbu	tp,0(tp) # 0 <_start>
    1040:	ffc12403          	lw	s0,-4(sp)

00001044 <slli_516>:
    1044:	00420233          	add	tp,tp,tp
    1048:	00420233          	add	tp,tp,tp
    104c:	00410233          	add	tp,sp,tp
    1050:	000011b7          	lui	gp,0x1
    1054:	07018193          	addi	gp,gp,112 # 1070 <non_taken_507.L111>
    1058:	fe312823          	sw	gp,-16(sp)
    105c:	000021b7          	lui	gp,0x2
    1060:	c8818193          	addi	gp,gp,-888 # 1c88 <andi_701>
    1064:	fe312623          	sw	gp,-20(sp)
    1068:	fec22203          	lw	tp,-20(tp) # ffffffec <_end+0xfff6cfec>
    106c:	00020067          	jalr	zero,0(tp) # 0 <_start>

00001070 <non_taken_507.L111>:
    1070:	fe312a23          	sw	gp,-12(sp)
    1074:	fea12423          	sw	a0,-24(sp)
    1078:	00033237          	lui	tp,0x33
    107c:	b0020213          	addi	tp,tp,-1280 # 32b00 <_logic_shift_table+0x2ff00>
    1080:	feb14183          	lbu	gp,-21(sp)
    1084:	004181b3          	add	gp,gp,tp
    1088:	0001c183          	lbu	gp,0(gp)
    108c:	fe3103a3          	sb	gp,-25(sp)
    1090:	fea14183          	lbu	gp,-22(sp)
    1094:	004181b3          	add	gp,gp,tp
    1098:	0001c183          	lbu	gp,0(gp)
    109c:	fe310323          	sb	gp,-26(sp)
    10a0:	fe914183          	lbu	gp,-23(sp)
    10a4:	004181b3          	add	gp,gp,tp
    10a8:	0001c183          	lbu	gp,0(gp)
    10ac:	fe3102a3          	sb	gp,-27(sp)
    10b0:	fe814183          	lbu	gp,-24(sp)
    10b4:	004181b3          	add	gp,gp,tp
    10b8:	0001c183          	lbu	gp,0(gp)
    10bc:	fe310223          	sb	gp,-28(sp)
    10c0:	ff412183          	lw	gp,-12(sp)
    10c4:	fe412203          	lw	tp,-28(sp)
    10c8:	004002b3          	add	t0,zero,tp
    10cc:	00128293          	addi	t0,t0,1

000010d0 <andi_523>:
    10d0:	00700213          	addi	tp,zero,7

000010d4 <and_524>:
    10d4:	fe512823          	sw	t0,-16(sp)
    10d8:	fe412623          	sw	tp,-20(sp)
    10dc:	000032b7          	lui	t0,0x3
    10e0:	c0028293          	addi	t0,t0,-1024 # 2c00 <_logic_shift_table>
    10e4:	fe012223          	sw	zero,-28(sp)
    10e8:	ff314203          	lbu	tp,-13(sp)
    10ec:	fe4102a3          	sb	tp,-27(sp)
    10f0:	fef14203          	lbu	tp,-17(sp)
    10f4:	fe410223          	sb	tp,-28(sp)
    10f8:	fe412203          	lw	tp,-28(sp)
    10fc:	00428233          	add	tp,t0,tp
    1100:	00024203          	lbu	tp,0(tp) # 0 <_start>
    1104:	fe4105a3          	sb	tp,-21(sp)
    1108:	ff214203          	lbu	tp,-14(sp)
    110c:	fe4102a3          	sb	tp,-27(sp)
    1110:	fee14203          	lbu	tp,-18(sp)
    1114:	fe410223          	sb	tp,-28(sp)
    1118:	fe412203          	lw	tp,-28(sp)
    111c:	00428233          	add	tp,t0,tp
    1120:	00024203          	lbu	tp,0(tp) # 0 <_start>
    1124:	fe410523          	sb	tp,-22(sp)
    1128:	ff114203          	lbu	tp,-15(sp)
    112c:	fe4102a3          	sb	tp,-27(sp)
    1130:	fed14203          	lbu	tp,-19(sp)
    1134:	fe410223          	sb	tp,-28(sp)
    1138:	fe412203          	lw	tp,-28(sp)
    113c:	00428233          	add	tp,t0,tp
    1140:	00024203          	lbu	tp,0(tp) # 0 <_start>
    1144:	fe4104a3          	sb	tp,-23(sp)
    1148:	ff014203          	lbu	tp,-16(sp)
    114c:	fe4102a3          	sb	tp,-27(sp)
    1150:	fec14203          	lbu	tp,-20(sp)
    1154:	fe410223          	sb	tp,-28(sp)
    1158:	fe412203          	lw	tp,-28(sp)
    115c:	00428233          	add	tp,t0,tp
    1160:	00024203          	lbu	tp,0(tp) # 0 <_start>
    1164:	fe410423          	sb	tp,-24(sp)
    1168:	fe812283          	lw	t0,-24(sp)

0000116c <sub_531>:
    116c:	fe312a23          	sw	gp,-12(sp)
    1170:	fe512423          	sw	t0,-24(sp)
    1174:	00033237          	lui	tp,0x33
    1178:	b0020213          	addi	tp,tp,-1280 # 32b00 <_logic_shift_table+0x2ff00>
    117c:	feb14183          	lbu	gp,-21(sp)
    1180:	004181b3          	add	gp,gp,tp
    1184:	0001c183          	lbu	gp,0(gp)
    1188:	fe3103a3          	sb	gp,-25(sp)
    118c:	fea14183          	lbu	gp,-22(sp)
    1190:	004181b3          	add	gp,gp,tp
    1194:	0001c183          	lbu	gp,0(gp)
    1198:	fe310323          	sb	gp,-26(sp)
    119c:	fe914183          	lbu	gp,-23(sp)
    11a0:	004181b3          	add	gp,gp,tp
    11a4:	0001c183          	lbu	gp,0(gp)
    11a8:	fe3102a3          	sb	gp,-27(sp)
    11ac:	fe814183          	lbu	gp,-24(sp)
    11b0:	004181b3          	add	gp,gp,tp
    11b4:	0001c183          	lbu	gp,0(gp)
    11b8:	fe310223          	sb	gp,-28(sp)
    11bc:	ff412183          	lw	gp,-12(sp)
    11c0:	fe412203          	lw	tp,-28(sp)
    11c4:	00460633          	add	a2,a2,tp
    11c8:	00160613          	addi	a2,a2,1 # 40001 <_logic_shift_table+0x3d401>

000011cc <beq_534.L90>:
    11cc:	fe512823          	sw	t0,-16(sp)
    11d0:	fe812e23          	sw	s0,-4(sp)
    11d4:	00003437          	lui	s0,0x3
    11d8:	a0840413          	addi	s0,s0,-1528 # 2a08 <_check_8bit_0_table>
    11dc:	ff014183          	lbu	gp,-16(sp)
    11e0:	003401b3          	add	gp,s0,gp
    11e4:	0001c183          	lbu	gp,0(gp)
    11e8:	ff114203          	lbu	tp,-15(sp)
    11ec:	00440233          	add	tp,s0,tp
    11f0:	00024203          	lbu	tp,0(tp) # 0 <_start>
    11f4:	004181b3          	add	gp,gp,tp
    11f8:	ff214203          	lbu	tp,-14(sp)
    11fc:	00440233          	add	tp,s0,tp
    1200:	00024203          	lbu	tp,0(tp) # 0 <_start>
    1204:	004181b3          	add	gp,gp,tp
    1208:	ff314203          	lbu	tp,-13(sp)
    120c:	00440233          	add	tp,s0,tp
    1210:	00024203          	lbu	tp,0(tp) # 0 <_start>
    1214:	004181b3          	add	gp,gp,tp
    1218:	00003237          	lui	tp,0x3
    121c:	a0020213          	addi	tp,tp,-1536 # 2a00 <_same_result_table>
    1220:	00320233          	add	tp,tp,gp
    1224:	00024203          	lbu	tp,0(tp) # 0 <_start>
    1228:	ffc12403          	lw	s0,-4(sp)

0000122c <slli_543>:
    122c:	00420233          	add	tp,tp,tp
    1230:	00420233          	add	tp,tp,tp
    1234:	00410233          	add	tp,sp,tp
    1238:	000031b7          	lui	gp,0x3
    123c:	8f818193          	addi	gp,gp,-1800 # 28f8 <non_taken_870.L104+0x2c>
    1240:	fe312823          	sw	gp,-16(sp)
    1244:	000011b7          	lui	gp,0x1
    1248:	25818193          	addi	gp,gp,600 # 1258 <non_taken_534.L90>
    124c:	fe312623          	sw	gp,-20(sp)
    1250:	fec22203          	lw	tp,-20(tp) # ffffffec <_end+0xfff6cfec>
    1254:	00020067          	jalr	zero,0(tp) # 0 <_start>

00001258 <non_taken_534.L90>:
    1258:	00550733          	add	a4,a0,t0
    125c:	00058693          	addi	a3,a1,0
    1260:	00050793          	addi	a5,a0,0
    1264:	0006c303          	lbu	t1,0(a3)
    1268:	00178793          	addi	a5,a5,1
    126c:	00168693          	addi	a3,a3,1
    1270:	fe678fa3          	sb	t1,-1(a5)

00001274 <bne_546.L79>:
    1274:	fef12823          	sw	a5,-16(sp)
    1278:	fee12623          	sw	a4,-20(sp)
    127c:	fe812e23          	sw	s0,-4(sp)
    1280:	fe912c23          	sw	s1,-8(sp)
    1284:	0004b437          	lui	s0,0x4b
    1288:	d0040413          	addi	s0,s0,-768 # 4ad00 <_check_same_array>
    128c:	ff014183          	lbu	gp,-16(sp)
    1290:	00340233          	add	tp,s0,gp
    1294:	00100193          	addi	gp,zero,1
    1298:	00320023          	sb	gp,0(tp) # 0 <_start>
    129c:	fec14183          	lbu	gp,-20(sp)
    12a0:	003401b3          	add	gp,s0,gp
    12a4:	00018023          	sb	zero,0(gp)
    12a8:	00024183          	lbu	gp,0(tp) # 0 <_start>
    12ac:	ff114483          	lbu	s1,-15(sp)
    12b0:	00940233          	add	tp,s0,s1
    12b4:	00100493          	addi	s1,zero,1
    12b8:	00920023          	sb	s1,0(tp) # 0 <_start>
    12bc:	fed14483          	lbu	s1,-19(sp)
    12c0:	009404b3          	add	s1,s0,s1
    12c4:	00048023          	sb	zero,0(s1)
    12c8:	00024483          	lbu	s1,0(tp) # 0 <_start>
    12cc:	009181b3          	add	gp,gp,s1
    12d0:	ff214483          	lbu	s1,-14(sp)
    12d4:	00940233          	add	tp,s0,s1
    12d8:	00100493          	addi	s1,zero,1
    12dc:	00920023          	sb	s1,0(tp) # 0 <_start>
    12e0:	fee14483          	lbu	s1,-18(sp)
    12e4:	009404b3          	add	s1,s0,s1
    12e8:	00048023          	sb	zero,0(s1)
    12ec:	00024483          	lbu	s1,0(tp) # 0 <_start>
    12f0:	009181b3          	add	gp,gp,s1
    12f4:	ff314483          	lbu	s1,-13(sp)
    12f8:	00940233          	add	tp,s0,s1
    12fc:	00100493          	addi	s1,zero,1
    1300:	00920023          	sb	s1,0(tp) # 0 <_start>
    1304:	fef14483          	lbu	s1,-17(sp)
    1308:	009404b3          	add	s1,s0,s1
    130c:	00048023          	sb	zero,0(s1)
    1310:	00024483          	lbu	s1,0(tp) # 0 <_start>
    1314:	009181b3          	add	gp,gp,s1
    1318:	00003237          	lui	tp,0x3
    131c:	a0020213          	addi	tp,tp,-1536 # 2a00 <_same_result_table>
    1320:	00320233          	add	tp,tp,gp
    1324:	00024203          	lbu	tp,0(tp) # 0 <_start>
    1328:	ff812483          	lw	s1,-8(sp)
    132c:	ffc12403          	lw	s0,-4(sp)

00001330 <slli_555>:
    1330:	00420233          	add	tp,tp,tp
    1334:	00420233          	add	tp,tp,tp
    1338:	00410233          	add	tp,sp,tp
    133c:	000011b7          	lui	gp,0x1
    1340:	35c18193          	addi	gp,gp,860 # 135c <non_taken_546.L79>
    1344:	fe312823          	sw	gp,-16(sp)
    1348:	000011b7          	lui	gp,0x1
    134c:	26418193          	addi	gp,gp,612 # 1264 <non_taken_534.L90+0xc>
    1350:	fe312623          	sw	gp,-20(sp)
    1354:	fec22203          	lw	tp,-20(tp) # ffffffec <_end+0xfff6cfec>
    1358:	00020067          	jalr	zero,0(tp) # 0 <_start>

0000135c <non_taken_546.L79>:
    135c:	005585b3          	add	a1,a1,t0
    1360:	01f00793          	addi	a5,zero,31

00001364 <bgeu_559.L91>:
    1364:	fe812e23          	sw	s0,-4(sp)
    1368:	fe912c23          	sw	s1,-8(sp)
    136c:	fec12823          	sw	a2,-16(sp)
    1370:	00078413          	addi	s0,a5,0
    1374:	ff012483          	lw	s1,-16(sp)
    1378:	fe812423          	sw	s0,-24(sp)
    137c:	feb14183          	lbu	gp,-21(sp)

00001380 <slli_564>:
    1380:	003181b3          	add	gp,gp,gp
    1384:	fe312423          	sw	gp,-24(sp)
    1388:	fe914183          	lbu	gp,-23(sp)

0000138c <slli_566>:
    138c:	003181b3          	add	gp,gp,gp
    1390:	fe912423          	sw	s1,-24(sp)
    1394:	feb14203          	lbu	tp,-21(sp)

00001398 <slli_569>:
    1398:	00420233          	add	tp,tp,tp
    139c:	fe412423          	sw	tp,-24(sp)
    13a0:	fe914203          	lbu	tp,-23(sp)
    13a4:	004181b3          	add	gp,gp,tp

000013a8 <slli_571>:
    13a8:	003181b3          	add	gp,gp,gp

000013ac <sub_572>:
    13ac:	fe312a23          	sw	gp,-12(sp)
    13b0:	fe912423          	sw	s1,-24(sp)
    13b4:	00033237          	lui	tp,0x33
    13b8:	b0020213          	addi	tp,tp,-1280 # 32b00 <_logic_shift_table+0x2ff00>
    13bc:	feb14183          	lbu	gp,-21(sp)
    13c0:	004181b3          	add	gp,gp,tp
    13c4:	0001c183          	lbu	gp,0(gp)
    13c8:	fe3103a3          	sb	gp,-25(sp)
    13cc:	fea14183          	lbu	gp,-22(sp)
    13d0:	004181b3          	add	gp,gp,tp
    13d4:	0001c183          	lbu	gp,0(gp)
    13d8:	fe310323          	sb	gp,-26(sp)
    13dc:	fe914183          	lbu	gp,-23(sp)
    13e0:	004181b3          	add	gp,gp,tp
    13e4:	0001c183          	lbu	gp,0(gp)
    13e8:	fe3102a3          	sb	gp,-27(sp)
    13ec:	fe814183          	lbu	gp,-24(sp)
    13f0:	004181b3          	add	gp,gp,tp
    13f4:	0001c183          	lbu	gp,0(gp)
    13f8:	fe310223          	sb	gp,-28(sp)
    13fc:	ff412183          	lw	gp,-12(sp)
    1400:	fe412203          	lw	tp,-28(sp)
    1404:	00440233          	add	tp,s0,tp
    1408:	00120213          	addi	tp,tp,1 # 1 <_start+0x1>
    140c:	fe412423          	sw	tp,-24(sp)
    1410:	feb14203          	lbu	tp,-21(sp)

00001414 <slli_577>:
    1414:	00420233          	add	tp,tp,tp
    1418:	fe412423          	sw	tp,-24(sp)
    141c:	fe914203          	lbu	tp,-23(sp)
    1420:	004181b3          	add	gp,gp,tp
    1424:	00003237          	lui	tp,0x3
    1428:	b1020213          	addi	tp,tp,-1264 # 2b10 <_sltu1_table>
    142c:	00320233          	add	tp,tp,gp
    1430:	ff812483          	lw	s1,-8(sp)
    1434:	ffc12403          	lw	s0,-4(sp)
    1438:	00024203          	lbu	tp,0(tp) # 0 <_start>

0000143c <slli_581>:
    143c:	00420233          	add	tp,tp,tp
    1440:	00420233          	add	tp,tp,tp
    1444:	00410233          	add	tp,sp,tp
    1448:	000011b7          	lui	gp,0x1
    144c:	46818193          	addi	gp,gp,1128 # 1468 <non_taken_559.L91>
    1450:	fe312823          	sw	gp,-16(sp)
    1454:	000031b7          	lui	gp,0x3
    1458:	8e418193          	addi	gp,gp,-1820 # 28e4 <non_taken_870.L104+0x18>
    145c:	fe312623          	sw	gp,-20(sp)
    1460:	fec22203          	lw	tp,-20(tp) # ffffffec <_end+0xfff6cfec>
    1464:	00020067          	jalr	zero,0(tp) # 0 <_start>

00001468 <non_taken_559.L91>:
    1468:	fe060293          	addi	t0,a2,-32

0000146c <andi_584>:
    146c:	fe000213          	addi	tp,zero,-32

00001470 <and_585>:
    1470:	fe512823          	sw	t0,-16(sp)
    1474:	fe412623          	sw	tp,-20(sp)
    1478:	000032b7          	lui	t0,0x3
    147c:	c0028293          	addi	t0,t0,-1024 # 2c00 <_logic_shift_table>
    1480:	fe012223          	sw	zero,-28(sp)
    1484:	ff314203          	lbu	tp,-13(sp)
    1488:	fe4102a3          	sb	tp,-27(sp)
    148c:	fef14203          	lbu	tp,-17(sp)
    1490:	fe410223          	sb	tp,-28(sp)
    1494:	fe412203          	lw	tp,-28(sp)
    1498:	00428233          	add	tp,t0,tp
    149c:	00024203          	lbu	tp,0(tp) # 0 <_start>
    14a0:	fe4105a3          	sb	tp,-21(sp)
    14a4:	ff214203          	lbu	tp,-14(sp)
    14a8:	fe4102a3          	sb	tp,-27(sp)
    14ac:	fee14203          	lbu	tp,-18(sp)
    14b0:	fe410223          	sb	tp,-28(sp)
    14b4:	fe412203          	lw	tp,-28(sp)
    14b8:	00428233          	add	tp,t0,tp
    14bc:	00024203          	lbu	tp,0(tp) # 0 <_start>
    14c0:	fe410523          	sb	tp,-22(sp)
    14c4:	ff114203          	lbu	tp,-15(sp)
    14c8:	fe4102a3          	sb	tp,-27(sp)
    14cc:	fed14203          	lbu	tp,-19(sp)
    14d0:	fe410223          	sb	tp,-28(sp)
    14d4:	fe412203          	lw	tp,-28(sp)
    14d8:	00428233          	add	tp,t0,tp
    14dc:	00024203          	lbu	tp,0(tp) # 0 <_start>
    14e0:	fe4104a3          	sb	tp,-23(sp)
    14e4:	ff014203          	lbu	tp,-16(sp)
    14e8:	fe4102a3          	sb	tp,-27(sp)
    14ec:	fec14203          	lbu	tp,-20(sp)
    14f0:	fe410223          	sb	tp,-28(sp)
    14f4:	fe412203          	lw	tp,-28(sp)
    14f8:	00428233          	add	tp,t0,tp
    14fc:	00024203          	lbu	tp,0(tp) # 0 <_start>
    1500:	fe410423          	sb	tp,-24(sp)
    1504:	fe812283          	lw	t0,-24(sp)
    1508:	02028293          	addi	t0,t0,32
    150c:	005707b3          	add	a5,a4,t0
    1510:	00058693          	addi	a3,a1,0
    1514:	0006a303          	lw	t1,0(a3)
    1518:	0046a383          	lw	t2,4(a3)
    151c:	02068693          	addi	a3,a3,32
    1520:	00672023          	sw	t1,0(a4)
    1524:	00772223          	sw	t2,4(a4)
    1528:	fe86a303          	lw	t1,-24(a3)
    152c:	fec6a383          	lw	t2,-20(a3)
    1530:	02070713          	addi	a4,a4,32
    1534:	fe672423          	sw	t1,-24(a4)
    1538:	fe772623          	sw	t2,-20(a4)
    153c:	ff06a303          	lw	t1,-16(a3)
    1540:	ff46a383          	lw	t2,-12(a3)
    1544:	fe672823          	sw	t1,-16(a4)
    1548:	fe772a23          	sw	t2,-12(a4)
    154c:	ff86a303          	lw	t1,-8(a3)
    1550:	ffc6a383          	lw	t2,-4(a3)
    1554:	fe672c23          	sw	t1,-8(a4)
    1558:	fe772e23          	sw	t2,-4(a4)

0000155c <bne_592.L81>:
    155c:	fee12823          	sw	a4,-16(sp)
    1560:	fef12623          	sw	a5,-20(sp)
    1564:	fe812e23          	sw	s0,-4(sp)
    1568:	fe912c23          	sw	s1,-8(sp)
    156c:	0004b437          	lui	s0,0x4b
    1570:	d0040413          	addi	s0,s0,-768 # 4ad00 <_check_same_array>
    1574:	ff014183          	lbu	gp,-16(sp)
    1578:	00340233          	add	tp,s0,gp
    157c:	00100193          	addi	gp,zero,1
    1580:	00320023          	sb	gp,0(tp) # 0 <_start>
    1584:	fec14183          	lbu	gp,-20(sp)
    1588:	003401b3          	add	gp,s0,gp
    158c:	00018023          	sb	zero,0(gp)
    1590:	00024183          	lbu	gp,0(tp) # 0 <_start>
    1594:	ff114483          	lbu	s1,-15(sp)
    1598:	00940233          	add	tp,s0,s1
    159c:	00100493          	addi	s1,zero,1
    15a0:	00920023          	sb	s1,0(tp) # 0 <_start>
    15a4:	fed14483          	lbu	s1,-19(sp)
    15a8:	009404b3          	add	s1,s0,s1
    15ac:	00048023          	sb	zero,0(s1)
    15b0:	00024483          	lbu	s1,0(tp) # 0 <_start>
    15b4:	009181b3          	add	gp,gp,s1
    15b8:	ff214483          	lbu	s1,-14(sp)
    15bc:	00940233          	add	tp,s0,s1
    15c0:	00100493          	addi	s1,zero,1
    15c4:	00920023          	sb	s1,0(tp) # 0 <_start>
    15c8:	fee14483          	lbu	s1,-18(sp)
    15cc:	009404b3          	add	s1,s0,s1
    15d0:	00048023          	sb	zero,0(s1)
    15d4:	00024483          	lbu	s1,0(tp) # 0 <_start>
    15d8:	009181b3          	add	gp,gp,s1
    15dc:	ff314483          	lbu	s1,-13(sp)
    15e0:	00940233          	add	tp,s0,s1
    15e4:	00100493          	addi	s1,zero,1
    15e8:	00920023          	sb	s1,0(tp) # 0 <_start>
    15ec:	fef14483          	lbu	s1,-17(sp)
    15f0:	009404b3          	add	s1,s0,s1
    15f4:	00048023          	sb	zero,0(s1)
    15f8:	00024483          	lbu	s1,0(tp) # 0 <_start>
    15fc:	009181b3          	add	gp,gp,s1
    1600:	00003237          	lui	tp,0x3
    1604:	a0020213          	addi	tp,tp,-1536 # 2a00 <_same_result_table>
    1608:	00320233          	add	tp,tp,gp
    160c:	00024203          	lbu	tp,0(tp) # 0 <_start>
    1610:	ff812483          	lw	s1,-8(sp)
    1614:	ffc12403          	lw	s0,-4(sp)

00001618 <slli_601>:
    1618:	00420233          	add	tp,tp,tp
    161c:	00420233          	add	tp,tp,tp
    1620:	00410233          	add	tp,sp,tp
    1624:	000011b7          	lui	gp,0x1
    1628:	64418193          	addi	gp,gp,1604 # 1644 <andi_604>
    162c:	fe312823          	sw	gp,-16(sp)
    1630:	000011b7          	lui	gp,0x1
    1634:	51418193          	addi	gp,gp,1300 # 1514 <and_585+0xa4>
    1638:	fe312623          	sw	gp,-20(sp)
    163c:	fec22203          	lw	tp,-20(tp) # ffffffec <_end+0xfff6cfec>
    1640:	00020067          	jalr	zero,0(tp) # 0 <_start>

00001644 <andi_604>:
    1644:	01f00213          	addi	tp,zero,31

00001648 <and_605>:
    1648:	fec12823          	sw	a2,-16(sp)
    164c:	fe412623          	sw	tp,-20(sp)
    1650:	000033b7          	lui	t2,0x3
    1654:	c0038393          	addi	t2,t2,-1024 # 2c00 <_logic_shift_table>
    1658:	fe012223          	sw	zero,-28(sp)
    165c:	ff314203          	lbu	tp,-13(sp)
    1660:	fe4102a3          	sb	tp,-27(sp)
    1664:	fef14203          	lbu	tp,-17(sp)
    1668:	fe410223          	sb	tp,-28(sp)
    166c:	fe412203          	lw	tp,-28(sp)
    1670:	00438233          	add	tp,t2,tp
    1674:	00024203          	lbu	tp,0(tp) # 0 <_start>
    1678:	fe4105a3          	sb	tp,-21(sp)
    167c:	ff214203          	lbu	tp,-14(sp)
    1680:	fe4102a3          	sb	tp,-27(sp)
    1684:	fee14203          	lbu	tp,-18(sp)
    1688:	fe410223          	sb	tp,-28(sp)
    168c:	fe412203          	lw	tp,-28(sp)
    1690:	00438233          	add	tp,t2,tp
    1694:	00024203          	lbu	tp,0(tp) # 0 <_start>
    1698:	fe410523          	sb	tp,-22(sp)
    169c:	ff114203          	lbu	tp,-15(sp)
    16a0:	fe4102a3          	sb	tp,-27(sp)
    16a4:	fed14203          	lbu	tp,-19(sp)
    16a8:	fe410223          	sb	tp,-28(sp)
    16ac:	fe412203          	lw	tp,-28(sp)
    16b0:	00438233          	add	tp,t2,tp
    16b4:	00024203          	lbu	tp,0(tp) # 0 <_start>
    16b8:	fe4104a3          	sb	tp,-23(sp)
    16bc:	ff014203          	lbu	tp,-16(sp)
    16c0:	fe4102a3          	sb	tp,-27(sp)
    16c4:	fec14203          	lbu	tp,-20(sp)
    16c8:	fe410223          	sb	tp,-28(sp)
    16cc:	fe412203          	lw	tp,-28(sp)
    16d0:	00438233          	add	tp,t2,tp
    16d4:	00024203          	lbu	tp,0(tp) # 0 <_start>
    16d8:	fe410423          	sb	tp,-24(sp)
    16dc:	fe812383          	lw	t2,-24(sp)

000016e0 <andi_612>:
    16e0:	01800213          	addi	tp,zero,24

000016e4 <and_613>:
    16e4:	fec12823          	sw	a2,-16(sp)
    16e8:	fe412623          	sw	tp,-20(sp)
    16ec:	00003737          	lui	a4,0x3
    16f0:	c0070713          	addi	a4,a4,-1024 # 2c00 <_logic_shift_table>
    16f4:	fe012223          	sw	zero,-28(sp)
    16f8:	ff314203          	lbu	tp,-13(sp)
    16fc:	fe4102a3          	sb	tp,-27(sp)
    1700:	fef14203          	lbu	tp,-17(sp)
    1704:	fe410223          	sb	tp,-28(sp)
    1708:	fe412203          	lw	tp,-28(sp)
    170c:	00470233          	add	tp,a4,tp
    1710:	00024203          	lbu	tp,0(tp) # 0 <_start>
    1714:	fe4105a3          	sb	tp,-21(sp)
    1718:	ff214203          	lbu	tp,-14(sp)
    171c:	fe4102a3          	sb	tp,-27(sp)
    1720:	fee14203          	lbu	tp,-18(sp)
    1724:	fe410223          	sb	tp,-28(sp)
    1728:	fe412203          	lw	tp,-28(sp)
    172c:	00470233          	add	tp,a4,tp
    1730:	00024203          	lbu	tp,0(tp) # 0 <_start>
    1734:	fe410523          	sb	tp,-22(sp)
    1738:	ff114203          	lbu	tp,-15(sp)
    173c:	fe4102a3          	sb	tp,-27(sp)
    1740:	fed14203          	lbu	tp,-19(sp)
    1744:	fe410223          	sb	tp,-28(sp)
    1748:	fe412203          	lw	tp,-28(sp)
    174c:	00470233          	add	tp,a4,tp
    1750:	00024203          	lbu	tp,0(tp) # 0 <_start>
    1754:	fe4104a3          	sb	tp,-23(sp)
    1758:	ff014203          	lbu	tp,-16(sp)
    175c:	fe4102a3          	sb	tp,-27(sp)
    1760:	fec14203          	lbu	tp,-20(sp)
    1764:	fe410223          	sb	tp,-28(sp)
    1768:	fe412203          	lw	tp,-28(sp)
    176c:	00470233          	add	tp,a4,tp
    1770:	00024203          	lbu	tp,0(tp) # 0 <_start>
    1774:	fe410423          	sb	tp,-24(sp)
    1778:	fe812703          	lw	a4,-24(sp)
    177c:	005585b3          	add	a1,a1,t0
    1780:	00038613          	addi	a2,t2,0

00001784 <beq_620.L105>:
    1784:	fee12823          	sw	a4,-16(sp)
    1788:	fe812e23          	sw	s0,-4(sp)
    178c:	00003437          	lui	s0,0x3
    1790:	a0840413          	addi	s0,s0,-1528 # 2a08 <_check_8bit_0_table>
    1794:	ff014183          	lbu	gp,-16(sp)
    1798:	003401b3          	add	gp,s0,gp
    179c:	0001c183          	lbu	gp,0(gp)
    17a0:	ff114203          	lbu	tp,-15(sp)
    17a4:	00440233          	add	tp,s0,tp
    17a8:	00024203          	lbu	tp,0(tp) # 0 <_start>
    17ac:	004181b3          	add	gp,gp,tp
    17b0:	ff214203          	lbu	tp,-14(sp)
    17b4:	00440233          	add	tp,s0,tp
    17b8:	00024203          	lbu	tp,0(tp) # 0 <_start>
    17bc:	004181b3          	add	gp,gp,tp
    17c0:	ff314203          	lbu	tp,-13(sp)
    17c4:	00440233          	add	tp,s0,tp
    17c8:	00024203          	lbu	tp,0(tp) # 0 <_start>
    17cc:	004181b3          	add	gp,gp,tp
    17d0:	00003237          	lui	tp,0x3
    17d4:	a0020213          	addi	tp,tp,-1536 # 2a00 <_same_result_table>
    17d8:	00320233          	add	tp,tp,gp
    17dc:	00024203          	lbu	tp,0(tp) # 0 <_start>
    17e0:	ffc12403          	lw	s0,-4(sp)

000017e4 <slli_629>:
    17e4:	00420233          	add	tp,tp,tp
    17e8:	00420233          	add	tp,tp,tp
    17ec:	00410233          	add	tp,sp,tp
    17f0:	000021b7          	lui	gp,0x2
    17f4:	6b018193          	addi	gp,gp,1712 # 26b0 <beq_846.L107>
    17f8:	fe312823          	sw	gp,-16(sp)
    17fc:	000021b7          	lui	gp,0x2
    1800:	81018193          	addi	gp,gp,-2032 # 1810 <non_taken_620.L105>
    1804:	fe312623          	sw	gp,-20(sp)
    1808:	fec22203          	lw	tp,-20(tp) # ffffffec <_end+0xfff6cfec>
    180c:	00020067          	jalr	zero,0(tp) # 0 <_start>

00001810 <non_taken_620.L105>:
    1810:	ff810113          	addi	sp,sp,-8
    1814:	00812223          	sw	s0,4(sp)
    1818:	00912023          	sw	s1,0(sp)
    181c:	00058313          	addi	t1,a1,0
    1820:	00078713          	addi	a4,a5,0
    1824:	007784b3          	add	s1,a5,t2
    1828:	00700413          	addi	s0,zero,7
    182c:	00032603          	lw	a2,0(t1)
    1830:	00432683          	lw	a3,4(t1)
    1834:	00870713          	addi	a4,a4,8

00001838 <sub_632>:
    1838:	fe312a23          	sw	gp,-12(sp)
    183c:	fee12423          	sw	a4,-24(sp)
    1840:	00033237          	lui	tp,0x33
    1844:	b0020213          	addi	tp,tp,-1280 # 32b00 <_logic_shift_table+0x2ff00>
    1848:	feb14183          	lbu	gp,-21(sp)
    184c:	004181b3          	add	gp,gp,tp
    1850:	0001c183          	lbu	gp,0(gp)
    1854:	fe3103a3          	sb	gp,-25(sp)
    1858:	fea14183          	lbu	gp,-22(sp)
    185c:	004181b3          	add	gp,gp,tp
    1860:	0001c183          	lbu	gp,0(gp)
    1864:	fe310323          	sb	gp,-26(sp)
    1868:	fe914183          	lbu	gp,-23(sp)
    186c:	004181b3          	add	gp,gp,tp
    1870:	0001c183          	lbu	gp,0(gp)
    1874:	fe3102a3          	sb	gp,-27(sp)
    1878:	fe814183          	lbu	gp,-24(sp)
    187c:	004181b3          	add	gp,gp,tp
    1880:	0001c183          	lbu	gp,0(gp)
    1884:	fe310223          	sb	gp,-28(sp)
    1888:	ff412183          	lw	gp,-12(sp)
    188c:	fe412203          	lw	tp,-28(sp)
    1890:	004482b3          	add	t0,s1,tp
    1894:	00128293          	addi	t0,t0,1
    1898:	fec72c23          	sw	a2,-8(a4)
    189c:	fed72e23          	sw	a3,-4(a4)
    18a0:	00830313          	addi	t1,t1,8

000018a4 <bltu_636.L82>:
    18a4:	fe812e23          	sw	s0,-4(sp)
    18a8:	fe912c23          	sw	s1,-8(sp)
    18ac:	fe512823          	sw	t0,-16(sp)
    18b0:	00040413          	addi	s0,s0,0
    18b4:	ff012483          	lw	s1,-16(sp)
    18b8:	fe812423          	sw	s0,-24(sp)
    18bc:	feb14183          	lbu	gp,-21(sp)

000018c0 <slli_641>:
    18c0:	003181b3          	add	gp,gp,gp
    18c4:	fe312423          	sw	gp,-24(sp)
    18c8:	fe914183          	lbu	gp,-23(sp)

000018cc <slli_643>:
    18cc:	003181b3          	add	gp,gp,gp
    18d0:	fe912423          	sw	s1,-24(sp)
    18d4:	feb14203          	lbu	tp,-21(sp)

000018d8 <slli_646>:
    18d8:	00420233          	add	tp,tp,tp
    18dc:	fe412423          	sw	tp,-24(sp)
    18e0:	fe914203          	lbu	tp,-23(sp)
    18e4:	004181b3          	add	gp,gp,tp

000018e8 <slli_648>:
    18e8:	003181b3          	add	gp,gp,gp

000018ec <sub_649>:
    18ec:	fe312a23          	sw	gp,-12(sp)
    18f0:	fe912423          	sw	s1,-24(sp)
    18f4:	00033237          	lui	tp,0x33
    18f8:	b0020213          	addi	tp,tp,-1280 # 32b00 <_logic_shift_table+0x2ff00>
    18fc:	feb14183          	lbu	gp,-21(sp)
    1900:	004181b3          	add	gp,gp,tp
    1904:	0001c183          	lbu	gp,0(gp)
    1908:	fe3103a3          	sb	gp,-25(sp)
    190c:	fea14183          	lbu	gp,-22(sp)
    1910:	004181b3          	add	gp,gp,tp
    1914:	0001c183          	lbu	gp,0(gp)
    1918:	fe310323          	sb	gp,-26(sp)
    191c:	fe914183          	lbu	gp,-23(sp)
    1920:	004181b3          	add	gp,gp,tp
    1924:	0001c183          	lbu	gp,0(gp)
    1928:	fe3102a3          	sb	gp,-27(sp)
    192c:	fe814183          	lbu	gp,-24(sp)
    1930:	004181b3          	add	gp,gp,tp
    1934:	0001c183          	lbu	gp,0(gp)
    1938:	fe310223          	sb	gp,-28(sp)
    193c:	ff412183          	lw	gp,-12(sp)
    1940:	fe412203          	lw	tp,-28(sp)
    1944:	00440233          	add	tp,s0,tp
    1948:	00120213          	addi	tp,tp,1 # 1 <_start+0x1>
    194c:	fe412423          	sw	tp,-24(sp)
    1950:	feb14203          	lbu	tp,-21(sp)

00001954 <slli_654>:
    1954:	00420233          	add	tp,tp,tp
    1958:	fe412423          	sw	tp,-24(sp)
    195c:	fe914203          	lbu	tp,-23(sp)
    1960:	004181b3          	add	gp,gp,tp
    1964:	00003237          	lui	tp,0x3
    1968:	b1020213          	addi	tp,tp,-1264 # 2b10 <_sltu1_table>
    196c:	00320233          	add	tp,tp,gp
    1970:	ff812483          	lw	s1,-8(sp)
    1974:	ffc12403          	lw	s0,-4(sp)
    1978:	00024203          	lbu	tp,0(tp) # 0 <_start>

0000197c <slli_658>:
    197c:	00420233          	add	tp,tp,tp
    1980:	00420233          	add	tp,tp,tp
    1984:	00410233          	add	tp,sp,tp
    1988:	000021b7          	lui	gp,0x2
    198c:	82c18193          	addi	gp,gp,-2004 # 182c <non_taken_620.L105+0x1c>
    1990:	fe312823          	sw	gp,-16(sp)
    1994:	000021b7          	lui	gp,0x2
    1998:	9a818193          	addi	gp,gp,-1624 # 19a8 <non_taken_636.L82>
    199c:	fe312623          	sw	gp,-20(sp)
    19a0:	fec22203          	lw	tp,-20(tp) # ffffffec <_end+0xfff6cfec>
    19a4:	00020067          	jalr	zero,0(tp) # 0 <_start>

000019a8 <non_taken_636.L82>:
    19a8:	ff838713          	addi	a4,t2,-8

000019ac <andi_661>:
    19ac:	ff800213          	addi	tp,zero,-8

000019b0 <and_662>:
    19b0:	fee12823          	sw	a4,-16(sp)
    19b4:	fe412623          	sw	tp,-20(sp)
    19b8:	00003737          	lui	a4,0x3
    19bc:	c0070713          	addi	a4,a4,-1024 # 2c00 <_logic_shift_table>
    19c0:	fe012223          	sw	zero,-28(sp)
    19c4:	ff314203          	lbu	tp,-13(sp)
    19c8:	fe4102a3          	sb	tp,-27(sp)
    19cc:	fef14203          	lbu	tp,-17(sp)
    19d0:	fe410223          	sb	tp,-28(sp)
    19d4:	fe412203          	lw	tp,-28(sp)
    19d8:	00470233          	add	tp,a4,tp
    19dc:	00024203          	lbu	tp,0(tp) # 0 <_start>
    19e0:	fe4105a3          	sb	tp,-21(sp)
    19e4:	ff214203          	lbu	tp,-14(sp)
    19e8:	fe4102a3          	sb	tp,-27(sp)
    19ec:	fee14203          	lbu	tp,-18(sp)
    19f0:	fe410223          	sb	tp,-28(sp)
    19f4:	fe412203          	lw	tp,-28(sp)
    19f8:	00470233          	add	tp,a4,tp
    19fc:	00024203          	lbu	tp,0(tp) # 0 <_start>
    1a00:	fe410523          	sb	tp,-22(sp)
    1a04:	ff114203          	lbu	tp,-15(sp)
    1a08:	fe4102a3          	sb	tp,-27(sp)
    1a0c:	fed14203          	lbu	tp,-19(sp)
    1a10:	fe410223          	sb	tp,-28(sp)
    1a14:	fe412203          	lw	tp,-28(sp)
    1a18:	00470233          	add	tp,a4,tp
    1a1c:	00024203          	lbu	tp,0(tp) # 0 <_start>
    1a20:	fe4104a3          	sb	tp,-23(sp)
    1a24:	ff014203          	lbu	tp,-16(sp)
    1a28:	fe4102a3          	sb	tp,-27(sp)
    1a2c:	fec14203          	lbu	tp,-20(sp)
    1a30:	fe410223          	sb	tp,-28(sp)
    1a34:	fe412203          	lw	tp,-28(sp)
    1a38:	00470233          	add	tp,a4,tp
    1a3c:	00024203          	lbu	tp,0(tp) # 0 <_start>
    1a40:	fe410423          	sb	tp,-24(sp)
    1a44:	fe812703          	lw	a4,-24(sp)
    1a48:	00870713          	addi	a4,a4,8

00001a4c <andi_669>:
    1a4c:	00700213          	addi	tp,zero,7

00001a50 <and_670>:
    1a50:	fe712823          	sw	t2,-16(sp)
    1a54:	fe412623          	sw	tp,-20(sp)
    1a58:	00003637          	lui	a2,0x3
    1a5c:	c0060613          	addi	a2,a2,-1024 # 2c00 <_logic_shift_table>
    1a60:	fe012223          	sw	zero,-28(sp)
    1a64:	ff314203          	lbu	tp,-13(sp)
    1a68:	fe4102a3          	sb	tp,-27(sp)
    1a6c:	fef14203          	lbu	tp,-17(sp)
    1a70:	fe410223          	sb	tp,-28(sp)
    1a74:	fe412203          	lw	tp,-28(sp)
    1a78:	00460233          	add	tp,a2,tp
    1a7c:	00024203          	lbu	tp,0(tp) # 0 <_start>
    1a80:	fe4105a3          	sb	tp,-21(sp)
    1a84:	ff214203          	lbu	tp,-14(sp)
    1a88:	fe4102a3          	sb	tp,-27(sp)
    1a8c:	fee14203          	lbu	tp,-18(sp)
    1a90:	fe410223          	sb	tp,-28(sp)
    1a94:	fe412203          	lw	tp,-28(sp)
    1a98:	00460233          	add	tp,a2,tp
    1a9c:	00024203          	lbu	tp,0(tp) # 0 <_start>
    1aa0:	fe410523          	sb	tp,-22(sp)
    1aa4:	ff114203          	lbu	tp,-15(sp)
    1aa8:	fe4102a3          	sb	tp,-27(sp)
    1aac:	fed14203          	lbu	tp,-19(sp)
    1ab0:	fe410223          	sb	tp,-28(sp)
    1ab4:	fe412203          	lw	tp,-28(sp)
    1ab8:	00460233          	add	tp,a2,tp
    1abc:	00024203          	lbu	tp,0(tp) # 0 <_start>
    1ac0:	fe4104a3          	sb	tp,-23(sp)
    1ac4:	ff014203          	lbu	tp,-16(sp)
    1ac8:	fe4102a3          	sb	tp,-27(sp)
    1acc:	fec14203          	lbu	tp,-20(sp)
    1ad0:	fe410223          	sb	tp,-28(sp)
    1ad4:	fe412203          	lw	tp,-28(sp)
    1ad8:	00460233          	add	tp,a2,tp
    1adc:	00024203          	lbu	tp,0(tp) # 0 <_start>
    1ae0:	fe410423          	sb	tp,-24(sp)
    1ae4:	fe812603          	lw	a2,-24(sp)
    1ae8:	00e787b3          	add	a5,a5,a4
    1aec:	00e585b3          	add	a1,a1,a4

00001af0 <beq_677.L83>:
    1af0:	fec12823          	sw	a2,-16(sp)
    1af4:	fe812e23          	sw	s0,-4(sp)
    1af8:	00003437          	lui	s0,0x3
    1afc:	a0840413          	addi	s0,s0,-1528 # 2a08 <_check_8bit_0_table>
    1b00:	ff014183          	lbu	gp,-16(sp)
    1b04:	003401b3          	add	gp,s0,gp
    1b08:	0001c183          	lbu	gp,0(gp)
    1b0c:	ff114203          	lbu	tp,-15(sp)
    1b10:	00440233          	add	tp,s0,tp
    1b14:	00024203          	lbu	tp,0(tp) # 0 <_start>
    1b18:	004181b3          	add	gp,gp,tp
    1b1c:	ff214203          	lbu	tp,-14(sp)
    1b20:	00440233          	add	tp,s0,tp
    1b24:	00024203          	lbu	tp,0(tp) # 0 <_start>
    1b28:	004181b3          	add	gp,gp,tp
    1b2c:	ff314203          	lbu	tp,-13(sp)
    1b30:	00440233          	add	tp,s0,tp
    1b34:	00024203          	lbu	tp,0(tp) # 0 <_start>
    1b38:	004181b3          	add	gp,gp,tp
    1b3c:	00003237          	lui	tp,0x3
    1b40:	a0020213          	addi	tp,tp,-1536 # 2a00 <_same_result_table>
    1b44:	00320233          	add	tp,tp,gp
    1b48:	00024203          	lbu	tp,0(tp) # 0 <_start>
    1b4c:	ffc12403          	lw	s0,-4(sp)

00001b50 <slli_686>:
    1b50:	00420233          	add	tp,tp,tp
    1b54:	00420233          	add	tp,tp,tp
    1b58:	00410233          	add	tp,sp,tp
    1b5c:	000021b7          	lui	gp,0x2
    1b60:	c7818193          	addi	gp,gp,-904 # 1c78 <non_taken_689.L88>
    1b64:	fe312823          	sw	gp,-16(sp)
    1b68:	000021b7          	lui	gp,0x2
    1b6c:	b7c18193          	addi	gp,gp,-1156 # 1b7c <non_taken_677.L83>
    1b70:	fe312623          	sw	gp,-20(sp)
    1b74:	fec22203          	lw	tp,-20(tp) # ffffffec <_end+0xfff6cfec>
    1b78:	00020067          	jalr	zero,0(tp) # 0 <_start>

00001b7c <non_taken_677.L83>:
    1b7c:	00c78633          	add	a2,a5,a2
    1b80:	0005c703          	lbu	a4,0(a1)
    1b84:	00178793          	addi	a5,a5,1
    1b88:	00158593          	addi	a1,a1,1
    1b8c:	fee78fa3          	sb	a4,-1(a5)

00001b90 <bne_689.L88>:
    1b90:	fef12823          	sw	a5,-16(sp)
    1b94:	fec12623          	sw	a2,-20(sp)
    1b98:	fe812e23          	sw	s0,-4(sp)
    1b9c:	fe912c23          	sw	s1,-8(sp)
    1ba0:	0004b437          	lui	s0,0x4b
    1ba4:	d0040413          	addi	s0,s0,-768 # 4ad00 <_check_same_array>
    1ba8:	ff014183          	lbu	gp,-16(sp)
    1bac:	00340233          	add	tp,s0,gp
    1bb0:	00100193          	addi	gp,zero,1
    1bb4:	00320023          	sb	gp,0(tp) # 0 <_start>
    1bb8:	fec14183          	lbu	gp,-20(sp)
    1bbc:	003401b3          	add	gp,s0,gp
    1bc0:	00018023          	sb	zero,0(gp)
    1bc4:	00024183          	lbu	gp,0(tp) # 0 <_start>
    1bc8:	ff114483          	lbu	s1,-15(sp)
    1bcc:	00940233          	add	tp,s0,s1
    1bd0:	00100493          	addi	s1,zero,1
    1bd4:	00920023          	sb	s1,0(tp) # 0 <_start>
    1bd8:	fed14483          	lbu	s1,-19(sp)
    1bdc:	009404b3          	add	s1,s0,s1
    1be0:	00048023          	sb	zero,0(s1)
    1be4:	00024483          	lbu	s1,0(tp) # 0 <_start>
    1be8:	009181b3          	add	gp,gp,s1
    1bec:	ff214483          	lbu	s1,-14(sp)
    1bf0:	00940233          	add	tp,s0,s1
    1bf4:	00100493          	addi	s1,zero,1
    1bf8:	00920023          	sb	s1,0(tp) # 0 <_start>
    1bfc:	fee14483          	lbu	s1,-18(sp)
    1c00:	009404b3          	add	s1,s0,s1
    1c04:	00048023          	sb	zero,0(s1)
    1c08:	00024483          	lbu	s1,0(tp) # 0 <_start>
    1c0c:	009181b3          	add	gp,gp,s1
    1c10:	ff314483          	lbu	s1,-13(sp)
    1c14:	00940233          	add	tp,s0,s1
    1c18:	00100493          	addi	s1,zero,1
    1c1c:	00920023          	sb	s1,0(tp) # 0 <_start>
    1c20:	fef14483          	lbu	s1,-17(sp)
    1c24:	009404b3          	add	s1,s0,s1
    1c28:	00048023          	sb	zero,0(s1)
    1c2c:	00024483          	lbu	s1,0(tp) # 0 <_start>
    1c30:	009181b3          	add	gp,gp,s1
    1c34:	00003237          	lui	tp,0x3
    1c38:	a0020213          	addi	tp,tp,-1536 # 2a00 <_same_result_table>
    1c3c:	00320233          	add	tp,tp,gp
    1c40:	00024203          	lbu	tp,0(tp) # 0 <_start>
    1c44:	ff812483          	lw	s1,-8(sp)
    1c48:	ffc12403          	lw	s0,-4(sp)

00001c4c <slli_698>:
    1c4c:	00420233          	add	tp,tp,tp
    1c50:	00420233          	add	tp,tp,tp
    1c54:	00410233          	add	tp,sp,tp
    1c58:	000021b7          	lui	gp,0x2
    1c5c:	c7818193          	addi	gp,gp,-904 # 1c78 <non_taken_689.L88>
    1c60:	fe312823          	sw	gp,-16(sp)
    1c64:	000021b7          	lui	gp,0x2
    1c68:	b8018193          	addi	gp,gp,-1152 # 1b80 <non_taken_677.L83+0x4>
    1c6c:	fe312623          	sw	gp,-20(sp)
    1c70:	fec22203          	lw	tp,-20(tp) # ffffffec <_end+0xfff6cfec>
    1c74:	00020067          	jalr	zero,0(tp) # 0 <_start>

00001c78 <non_taken_689.L88>:
    1c78:	00412403          	lw	s0,4(sp)
    1c7c:	00012483          	lw	s1,0(sp)
    1c80:	00810113          	addi	sp,sp,8
    1c84:	00008067          	jalr	zero,0(ra)

00001c88 <andi_701>:
    1c88:	00300213          	addi	tp,zero,3

00001c8c <and_702>:
    1c8c:	fef12823          	sw	a5,-16(sp)
    1c90:	fe412623          	sw	tp,-20(sp)
    1c94:	000037b7          	lui	a5,0x3
    1c98:	c0078793          	addi	a5,a5,-1024 # 2c00 <_logic_shift_table>
    1c9c:	fe012223          	sw	zero,-28(sp)
    1ca0:	ff314203          	lbu	tp,-13(sp)
    1ca4:	fe4102a3          	sb	tp,-27(sp)
    1ca8:	fef14203          	lbu	tp,-17(sp)
    1cac:	fe410223          	sb	tp,-28(sp)
    1cb0:	fe412203          	lw	tp,-28(sp)
    1cb4:	00478233          	add	tp,a5,tp
    1cb8:	00024203          	lbu	tp,0(tp) # 0 <_start>
    1cbc:	fe4105a3          	sb	tp,-21(sp)
    1cc0:	ff214203          	lbu	tp,-14(sp)
    1cc4:	fe4102a3          	sb	tp,-27(sp)
    1cc8:	fee14203          	lbu	tp,-18(sp)
    1ccc:	fe410223          	sb	tp,-28(sp)
    1cd0:	fe412203          	lw	tp,-28(sp)
    1cd4:	00478233          	add	tp,a5,tp
    1cd8:	00024203          	lbu	tp,0(tp) # 0 <_start>
    1cdc:	fe410523          	sb	tp,-22(sp)
    1ce0:	ff114203          	lbu	tp,-15(sp)
    1ce4:	fe4102a3          	sb	tp,-27(sp)
    1ce8:	fed14203          	lbu	tp,-19(sp)
    1cec:	fe410223          	sb	tp,-28(sp)
    1cf0:	fe412203          	lw	tp,-28(sp)
    1cf4:	00478233          	add	tp,a5,tp
    1cf8:	00024203          	lbu	tp,0(tp) # 0 <_start>
    1cfc:	fe4104a3          	sb	tp,-23(sp)
    1d00:	ff014203          	lbu	tp,-16(sp)
    1d04:	fe4102a3          	sb	tp,-27(sp)
    1d08:	fec14203          	lbu	tp,-20(sp)
    1d0c:	fe410223          	sb	tp,-28(sp)
    1d10:	fe412203          	lw	tp,-28(sp)
    1d14:	00478233          	add	tp,a5,tp
    1d18:	00024203          	lbu	tp,0(tp) # 0 <_start>
    1d1c:	fe410423          	sb	tp,-24(sp)
    1d20:	fe812783          	lw	a5,-24(sp)

00001d24 <bne_709.L112>:
    1d24:	fef12823          	sw	a5,-16(sp)
    1d28:	fe812e23          	sw	s0,-4(sp)
    1d2c:	00003437          	lui	s0,0x3
    1d30:	a0840413          	addi	s0,s0,-1528 # 2a08 <_check_8bit_0_table>
    1d34:	ff014183          	lbu	gp,-16(sp)
    1d38:	003401b3          	add	gp,s0,gp
    1d3c:	0001c183          	lbu	gp,0(gp)
    1d40:	ff114203          	lbu	tp,-15(sp)
    1d44:	00440233          	add	tp,s0,tp
    1d48:	00024203          	lbu	tp,0(tp) # 0 <_start>
    1d4c:	004181b3          	add	gp,gp,tp
    1d50:	ff214203          	lbu	tp,-14(sp)
    1d54:	00440233          	add	tp,s0,tp
    1d58:	00024203          	lbu	tp,0(tp) # 0 <_start>
    1d5c:	004181b3          	add	gp,gp,tp
    1d60:	ff314203          	lbu	tp,-13(sp)
    1d64:	00440233          	add	tp,s0,tp
    1d68:	00024203          	lbu	tp,0(tp) # 0 <_start>
    1d6c:	004181b3          	add	gp,gp,tp
    1d70:	00003237          	lui	tp,0x3
    1d74:	a0020213          	addi	tp,tp,-1536 # 2a00 <_same_result_table>
    1d78:	00320233          	add	tp,tp,gp
    1d7c:	00024203          	lbu	tp,0(tp) # 0 <_start>
    1d80:	ffc12403          	lw	s0,-4(sp)

00001d84 <slli_718>:
    1d84:	00420233          	add	tp,tp,tp
    1d88:	00420233          	add	tp,tp,tp
    1d8c:	00410233          	add	tp,sp,tp
    1d90:	000021b7          	lui	gp,0x2
    1d94:	db018193          	addi	gp,gp,-592 # 1db0 <andi_721>
    1d98:	fe312823          	sw	gp,-16(sp)
    1d9c:	000031b7          	lui	gp,0x3
    1da0:	8d018193          	addi	gp,gp,-1840 # 28d0 <non_taken_870.L104+0x4>
    1da4:	fe312623          	sw	gp,-20(sp)
    1da8:	fec22203          	lw	tp,-20(tp) # ffffffec <_end+0xfff6cfec>
    1dac:	00020067          	jalr	zero,0(tp) # 0 <_start>

00001db0 <andi_721>:
    1db0:	00300213          	addi	tp,zero,3

00001db4 <and_722>:
    1db4:	fea12823          	sw	a0,-16(sp)
    1db8:	fe412623          	sw	tp,-20(sp)
    1dbc:	000037b7          	lui	a5,0x3
    1dc0:	c0078793          	addi	a5,a5,-1024 # 2c00 <_logic_shift_table>
    1dc4:	fe012223          	sw	zero,-28(sp)
    1dc8:	ff314203          	lbu	tp,-13(sp)
    1dcc:	fe4102a3          	sb	tp,-27(sp)
    1dd0:	fef14203          	lbu	tp,-17(sp)
    1dd4:	fe410223          	sb	tp,-28(sp)
    1dd8:	fe412203          	lw	tp,-28(sp)
    1ddc:	00478233          	add	tp,a5,tp
    1de0:	00024203          	lbu	tp,0(tp) # 0 <_start>
    1de4:	fe4105a3          	sb	tp,-21(sp)
    1de8:	ff214203          	lbu	tp,-14(sp)
    1dec:	fe4102a3          	sb	tp,-27(sp)
    1df0:	fee14203          	lbu	tp,-18(sp)
    1df4:	fe410223          	sb	tp,-28(sp)
    1df8:	fe412203          	lw	tp,-28(sp)
    1dfc:	00478233          	add	tp,a5,tp
    1e00:	00024203          	lbu	tp,0(tp) # 0 <_start>
    1e04:	fe410523          	sb	tp,-22(sp)
    1e08:	ff114203          	lbu	tp,-15(sp)
    1e0c:	fe4102a3          	sb	tp,-27(sp)
    1e10:	fed14203          	lbu	tp,-19(sp)
    1e14:	fe410223          	sb	tp,-28(sp)
    1e18:	fe412203          	lw	tp,-28(sp)
    1e1c:	00478233          	add	tp,a5,tp
    1e20:	00024203          	lbu	tp,0(tp) # 0 <_start>
    1e24:	fe4104a3          	sb	tp,-23(sp)
    1e28:	ff014203          	lbu	tp,-16(sp)
    1e2c:	fe4102a3          	sb	tp,-27(sp)
    1e30:	fec14203          	lbu	tp,-20(sp)
    1e34:	fe410223          	sb	tp,-28(sp)
    1e38:	fe412203          	lw	tp,-28(sp)
    1e3c:	00478233          	add	tp,a5,tp
    1e40:	00024203          	lbu	tp,0(tp) # 0 <_start>
    1e44:	fe410423          	sb	tp,-24(sp)
    1e48:	fe812783          	lw	a5,-24(sp)
    1e4c:	00400293          	addi	t0,zero,4
    1e50:	ffc60613          	addi	a2,a2,-4

00001e54 <sub_729>:
    1e54:	fe312a23          	sw	gp,-12(sp)
    1e58:	fef12423          	sw	a5,-24(sp)
    1e5c:	00033237          	lui	tp,0x33
    1e60:	b0020213          	addi	tp,tp,-1280 # 32b00 <_logic_shift_table+0x2ff00>
    1e64:	feb14183          	lbu	gp,-21(sp)
    1e68:	004181b3          	add	gp,gp,tp
    1e6c:	0001c183          	lbu	gp,0(gp)
    1e70:	fe3103a3          	sb	gp,-25(sp)
    1e74:	fea14183          	lbu	gp,-22(sp)
    1e78:	004181b3          	add	gp,gp,tp
    1e7c:	0001c183          	lbu	gp,0(gp)
    1e80:	fe310323          	sb	gp,-26(sp)
    1e84:	fe914183          	lbu	gp,-23(sp)
    1e88:	004181b3          	add	gp,gp,tp
    1e8c:	0001c183          	lbu	gp,0(gp)
    1e90:	fe3102a3          	sb	gp,-27(sp)
    1e94:	fe814183          	lbu	gp,-24(sp)
    1e98:	004181b3          	add	gp,gp,tp
    1e9c:	0001c183          	lbu	gp,0(gp)
    1ea0:	fe310223          	sb	gp,-28(sp)
    1ea4:	ff412183          	lw	gp,-12(sp)
    1ea8:	fe412203          	lw	tp,-28(sp)
    1eac:	004282b3          	add	t0,t0,tp
    1eb0:	00128293          	addi	t0,t0,1
    1eb4:	00f60633          	add	a2,a2,a5
    1eb8:	00058713          	addi	a4,a1,0
    1ebc:	005507b3          	add	a5,a0,t0
    1ec0:	00050693          	addi	a3,a0,0
    1ec4:	00074303          	lbu	t1,0(a4)
    1ec8:	00168693          	addi	a3,a3,1
    1ecc:	00170713          	addi	a4,a4,1
    1ed0:	fe668fa3          	sb	t1,-1(a3)

00001ed4 <bne_732.L84>:
    1ed4:	fed12823          	sw	a3,-16(sp)
    1ed8:	fef12623          	sw	a5,-20(sp)
    1edc:	fe812e23          	sw	s0,-4(sp)
    1ee0:	fe912c23          	sw	s1,-8(sp)
    1ee4:	0004b437          	lui	s0,0x4b
    1ee8:	d0040413          	addi	s0,s0,-768 # 4ad00 <_check_same_array>
    1eec:	ff014183          	lbu	gp,-16(sp)
    1ef0:	00340233          	add	tp,s0,gp
    1ef4:	00100193          	addi	gp,zero,1
    1ef8:	00320023          	sb	gp,0(tp) # 0 <_start>
    1efc:	fec14183          	lbu	gp,-20(sp)
    1f00:	003401b3          	add	gp,s0,gp
    1f04:	00018023          	sb	zero,0(gp)
    1f08:	00024183          	lbu	gp,0(tp) # 0 <_start>
    1f0c:	ff114483          	lbu	s1,-15(sp)
    1f10:	00940233          	add	tp,s0,s1
    1f14:	00100493          	addi	s1,zero,1
    1f18:	00920023          	sb	s1,0(tp) # 0 <_start>
    1f1c:	fed14483          	lbu	s1,-19(sp)
    1f20:	009404b3          	add	s1,s0,s1
    1f24:	00048023          	sb	zero,0(s1)
    1f28:	00024483          	lbu	s1,0(tp) # 0 <_start>
    1f2c:	009181b3          	add	gp,gp,s1
    1f30:	ff214483          	lbu	s1,-14(sp)
    1f34:	00940233          	add	tp,s0,s1
    1f38:	00100493          	addi	s1,zero,1
    1f3c:	00920023          	sb	s1,0(tp) # 0 <_start>
    1f40:	fee14483          	lbu	s1,-18(sp)
    1f44:	009404b3          	add	s1,s0,s1
    1f48:	00048023          	sb	zero,0(s1)
    1f4c:	00024483          	lbu	s1,0(tp) # 0 <_start>
    1f50:	009181b3          	add	gp,gp,s1
    1f54:	ff314483          	lbu	s1,-13(sp)
    1f58:	00940233          	add	tp,s0,s1
    1f5c:	00100493          	addi	s1,zero,1
    1f60:	00920023          	sb	s1,0(tp) # 0 <_start>
    1f64:	fef14483          	lbu	s1,-17(sp)
    1f68:	009404b3          	add	s1,s0,s1
    1f6c:	00048023          	sb	zero,0(s1)
    1f70:	00024483          	lbu	s1,0(tp) # 0 <_start>
    1f74:	009181b3          	add	gp,gp,s1
    1f78:	00003237          	lui	tp,0x3
    1f7c:	a0020213          	addi	tp,tp,-1536 # 2a00 <_same_result_table>
    1f80:	00320233          	add	tp,tp,gp
    1f84:	00024203          	lbu	tp,0(tp) # 0 <_start>
    1f88:	ff812483          	lw	s1,-8(sp)
    1f8c:	ffc12403          	lw	s0,-4(sp)

00001f90 <slli_741>:
    1f90:	00420233          	add	tp,tp,tp
    1f94:	00420233          	add	tp,tp,tp
    1f98:	00410233          	add	tp,sp,tp
    1f9c:	000021b7          	lui	gp,0x2
    1fa0:	fbc18193          	addi	gp,gp,-68 # 1fbc <non_taken_732.L84>
    1fa4:	fe312823          	sw	gp,-16(sp)
    1fa8:	000021b7          	lui	gp,0x2
    1fac:	ec418193          	addi	gp,gp,-316 # 1ec4 <sub_729+0x70>
    1fb0:	fe312623          	sw	gp,-20(sp)
    1fb4:	fec22203          	lw	tp,-20(tp) # ffffffec <_end+0xfff6cfec>
    1fb8:	00020067          	jalr	zero,0(tp) # 0 <_start>

00001fbc <non_taken_732.L84>:
    1fbc:	01f00713          	addi	a4,zero,31
    1fc0:	005585b3          	add	a1,a1,t0

00001fc4 <bgeu_745.L85>:
    1fc4:	fe812e23          	sw	s0,-4(sp)
    1fc8:	fe912c23          	sw	s1,-8(sp)
    1fcc:	fec12823          	sw	a2,-16(sp)
    1fd0:	00070413          	addi	s0,a4,0
    1fd4:	ff012483          	lw	s1,-16(sp)
    1fd8:	fe812423          	sw	s0,-24(sp)
    1fdc:	feb14183          	lbu	gp,-21(sp)

00001fe0 <slli_750>:
    1fe0:	003181b3          	add	gp,gp,gp
    1fe4:	fe312423          	sw	gp,-24(sp)
    1fe8:	fe914183          	lbu	gp,-23(sp)

00001fec <slli_752>:
    1fec:	003181b3          	add	gp,gp,gp
    1ff0:	fe912423          	sw	s1,-24(sp)
    1ff4:	feb14203          	lbu	tp,-21(sp)

00001ff8 <slli_755>:
    1ff8:	00420233          	add	tp,tp,tp
    1ffc:	fe412423          	sw	tp,-24(sp)
    2000:	fe914203          	lbu	tp,-23(sp)
    2004:	004181b3          	add	gp,gp,tp

00002008 <slli_757>:
    2008:	003181b3          	add	gp,gp,gp

0000200c <sub_758>:
    200c:	fe312a23          	sw	gp,-12(sp)
    2010:	fe912423          	sw	s1,-24(sp)
    2014:	00033237          	lui	tp,0x33
    2018:	b0020213          	addi	tp,tp,-1280 # 32b00 <_logic_shift_table+0x2ff00>
    201c:	feb14183          	lbu	gp,-21(sp)
    2020:	004181b3          	add	gp,gp,tp
    2024:	0001c183          	lbu	gp,0(gp)
    2028:	fe3103a3          	sb	gp,-25(sp)
    202c:	fea14183          	lbu	gp,-22(sp)
    2030:	004181b3          	add	gp,gp,tp
    2034:	0001c183          	lbu	gp,0(gp)
    2038:	fe310323          	sb	gp,-26(sp)
    203c:	fe914183          	lbu	gp,-23(sp)
    2040:	004181b3          	add	gp,gp,tp
    2044:	0001c183          	lbu	gp,0(gp)
    2048:	fe3102a3          	sb	gp,-27(sp)
    204c:	fe814183          	lbu	gp,-24(sp)
    2050:	004181b3          	add	gp,gp,tp
    2054:	0001c183          	lbu	gp,0(gp)
    2058:	fe310223          	sb	gp,-28(sp)
    205c:	ff412183          	lw	gp,-12(sp)
    2060:	fe412203          	lw	tp,-28(sp)
    2064:	00440233          	add	tp,s0,tp
    2068:	00120213          	addi	tp,tp,1 # 1 <_start+0x1>
    206c:	fe412423          	sw	tp,-24(sp)
    2070:	feb14203          	lbu	tp,-21(sp)

00002074 <slli_763>:
    2074:	00420233          	add	tp,tp,tp
    2078:	fe412423          	sw	tp,-24(sp)
    207c:	fe914203          	lbu	tp,-23(sp)
    2080:	004181b3          	add	gp,gp,tp
    2084:	00003237          	lui	tp,0x3
    2088:	b1020213          	addi	tp,tp,-1264 # 2b10 <_sltu1_table>
    208c:	00320233          	add	tp,tp,gp
    2090:	ff812483          	lw	s1,-8(sp)
    2094:	ffc12403          	lw	s0,-4(sp)
    2098:	00024203          	lbu	tp,0(tp) # 0 <_start>

0000209c <slli_767>:
    209c:	00420233          	add	tp,tp,tp
    20a0:	00420233          	add	tp,tp,tp
    20a4:	00410233          	add	tp,sp,tp
    20a8:	000021b7          	lui	gp,0x2
    20ac:	0c818193          	addi	gp,gp,200 # 20c8 <non_taken_745.L85>
    20b0:	fe312823          	sw	gp,-16(sp)
    20b4:	000021b7          	lui	gp,0x2
    20b8:	46c18193          	addi	gp,gp,1132 # 246c <non_taken_806.L105>
    20bc:	fe312623          	sw	gp,-20(sp)
    20c0:	fec22203          	lw	tp,-20(tp) # ffffffec <_end+0xfff6cfec>
    20c4:	00020067          	jalr	zero,0(tp) # 0 <_start>

000020c8 <non_taken_745.L85>:
    20c8:	fe060293          	addi	t0,a2,-32

000020cc <andi_770>:
    20cc:	fe000213          	addi	tp,zero,-32

000020d0 <and_771>:
    20d0:	fe512823          	sw	t0,-16(sp)
    20d4:	fe412623          	sw	tp,-20(sp)
    20d8:	000032b7          	lui	t0,0x3
    20dc:	c0028293          	addi	t0,t0,-1024 # 2c00 <_logic_shift_table>
    20e0:	fe012223          	sw	zero,-28(sp)
    20e4:	ff314203          	lbu	tp,-13(sp)
    20e8:	fe4102a3          	sb	tp,-27(sp)
    20ec:	fef14203          	lbu	tp,-17(sp)
    20f0:	fe410223          	sb	tp,-28(sp)
    20f4:	fe412203          	lw	tp,-28(sp)
    20f8:	00428233          	add	tp,t0,tp
    20fc:	00024203          	lbu	tp,0(tp) # 0 <_start>
    2100:	fe4105a3          	sb	tp,-21(sp)
    2104:	ff214203          	lbu	tp,-14(sp)
    2108:	fe4102a3          	sb	tp,-27(sp)
    210c:	fee14203          	lbu	tp,-18(sp)
    2110:	fe410223          	sb	tp,-28(sp)
    2114:	fe412203          	lw	tp,-28(sp)
    2118:	00428233          	add	tp,t0,tp
    211c:	00024203          	lbu	tp,0(tp) # 0 <_start>
    2120:	fe410523          	sb	tp,-22(sp)
    2124:	ff114203          	lbu	tp,-15(sp)
    2128:	fe4102a3          	sb	tp,-27(sp)
    212c:	fed14203          	lbu	tp,-19(sp)
    2130:	fe410223          	sb	tp,-28(sp)
    2134:	fe412203          	lw	tp,-28(sp)
    2138:	00428233          	add	tp,t0,tp
    213c:	00024203          	lbu	tp,0(tp) # 0 <_start>
    2140:	fe4104a3          	sb	tp,-23(sp)
    2144:	ff014203          	lbu	tp,-16(sp)
    2148:	fe4102a3          	sb	tp,-27(sp)
    214c:	fec14203          	lbu	tp,-20(sp)
    2150:	fe410223          	sb	tp,-28(sp)
    2154:	fe412203          	lw	tp,-28(sp)
    2158:	00428233          	add	tp,t0,tp
    215c:	00024203          	lbu	tp,0(tp) # 0 <_start>
    2160:	fe410423          	sb	tp,-24(sp)
    2164:	fe812283          	lw	t0,-24(sp)
    2168:	02028293          	addi	t0,t0,32
    216c:	005786b3          	add	a3,a5,t0
    2170:	00058713          	addi	a4,a1,0
    2174:	00072303          	lw	t1,0(a4)
    2178:	02070713          	addi	a4,a4,32
    217c:	02078793          	addi	a5,a5,32
    2180:	fe67a023          	sw	t1,-32(a5)
    2184:	fe472303          	lw	t1,-28(a4)
    2188:	fe67a223          	sw	t1,-28(a5)
    218c:	fe872303          	lw	t1,-24(a4)
    2190:	fe67a423          	sw	t1,-24(a5)
    2194:	fec72303          	lw	t1,-20(a4)
    2198:	fe67a623          	sw	t1,-20(a5)
    219c:	ff072303          	lw	t1,-16(a4)
    21a0:	fe67a823          	sw	t1,-16(a5)
    21a4:	ff472303          	lw	t1,-12(a4)
    21a8:	fe67aa23          	sw	t1,-12(a5)
    21ac:	ff872303          	lw	t1,-8(a4)
    21b0:	fe67ac23          	sw	t1,-8(a5)
    21b4:	ffc72303          	lw	t1,-4(a4)
    21b8:	fe67ae23          	sw	t1,-4(a5)

000021bc <bne_778.L86>:
    21bc:	fef12823          	sw	a5,-16(sp)
    21c0:	fed12623          	sw	a3,-20(sp)
    21c4:	fe812e23          	sw	s0,-4(sp)
    21c8:	fe912c23          	sw	s1,-8(sp)
    21cc:	0004b437          	lui	s0,0x4b
    21d0:	d0040413          	addi	s0,s0,-768 # 4ad00 <_check_same_array>
    21d4:	ff014183          	lbu	gp,-16(sp)
    21d8:	00340233          	add	tp,s0,gp
    21dc:	00100193          	addi	gp,zero,1
    21e0:	00320023          	sb	gp,0(tp) # 0 <_start>
    21e4:	fec14183          	lbu	gp,-20(sp)
    21e8:	003401b3          	add	gp,s0,gp
    21ec:	00018023          	sb	zero,0(gp)
    21f0:	00024183          	lbu	gp,0(tp) # 0 <_start>
    21f4:	ff114483          	lbu	s1,-15(sp)
    21f8:	00940233          	add	tp,s0,s1
    21fc:	00100493          	addi	s1,zero,1
    2200:	00920023          	sb	s1,0(tp) # 0 <_start>
    2204:	fed14483          	lbu	s1,-19(sp)
    2208:	009404b3          	add	s1,s0,s1
    220c:	00048023          	sb	zero,0(s1)
    2210:	00024483          	lbu	s1,0(tp) # 0 <_start>
    2214:	009181b3          	add	gp,gp,s1
    2218:	ff214483          	lbu	s1,-14(sp)
    221c:	00940233          	add	tp,s0,s1
    2220:	00100493          	addi	s1,zero,1
    2224:	00920023          	sb	s1,0(tp) # 0 <_start>
    2228:	fee14483          	lbu	s1,-18(sp)
    222c:	009404b3          	add	s1,s0,s1
    2230:	00048023          	sb	zero,0(s1)
    2234:	00024483          	lbu	s1,0(tp) # 0 <_start>
    2238:	009181b3          	add	gp,gp,s1
    223c:	ff314483          	lbu	s1,-13(sp)
    2240:	00940233          	add	tp,s0,s1
    2244:	00100493          	addi	s1,zero,1
    2248:	00920023          	sb	s1,0(tp) # 0 <_start>
    224c:	fef14483          	lbu	s1,-17(sp)
    2250:	009404b3          	add	s1,s0,s1
    2254:	00048023          	sb	zero,0(s1)
    2258:	00024483          	lbu	s1,0(tp) # 0 <_start>
    225c:	009181b3          	add	gp,gp,s1
    2260:	00003237          	lui	tp,0x3
    2264:	a0020213          	addi	tp,tp,-1536 # 2a00 <_same_result_table>
    2268:	00320233          	add	tp,tp,gp
    226c:	00024203          	lbu	tp,0(tp) # 0 <_start>
    2270:	ff812483          	lw	s1,-8(sp)
    2274:	ffc12403          	lw	s0,-4(sp)

00002278 <slli_787>:
    2278:	00420233          	add	tp,tp,tp
    227c:	00420233          	add	tp,tp,tp
    2280:	00410233          	add	tp,sp,tp
    2284:	000021b7          	lui	gp,0x2
    2288:	2a418193          	addi	gp,gp,676 # 22a4 <andi_790>
    228c:	fe312823          	sw	gp,-16(sp)
    2290:	000021b7          	lui	gp,0x2
    2294:	17418193          	addi	gp,gp,372 # 2174 <and_771+0xa4>
    2298:	fe312623          	sw	gp,-20(sp)
    229c:	fec22203          	lw	tp,-20(tp) # ffffffec <_end+0xfff6cfec>
    22a0:	00020067          	jalr	zero,0(tp) # 0 <_start>

000022a4 <andi_790>:
    22a4:	01c00213          	addi	tp,zero,28

000022a8 <and_791>:
    22a8:	fec12823          	sw	a2,-16(sp)
    22ac:	fe412623          	sw	tp,-20(sp)
    22b0:	00003737          	lui	a4,0x3
    22b4:	c0070713          	addi	a4,a4,-1024 # 2c00 <_logic_shift_table>
    22b8:	fe012223          	sw	zero,-28(sp)
    22bc:	ff314203          	lbu	tp,-13(sp)
    22c0:	fe4102a3          	sb	tp,-27(sp)
    22c4:	fef14203          	lbu	tp,-17(sp)
    22c8:	fe410223          	sb	tp,-28(sp)
    22cc:	fe412203          	lw	tp,-28(sp)
    22d0:	00470233          	add	tp,a4,tp
    22d4:	00024203          	lbu	tp,0(tp) # 0 <_start>
    22d8:	fe4105a3          	sb	tp,-21(sp)
    22dc:	ff214203          	lbu	tp,-14(sp)
    22e0:	fe4102a3          	sb	tp,-27(sp)
    22e4:	fee14203          	lbu	tp,-18(sp)
    22e8:	fe410223          	sb	tp,-28(sp)
    22ec:	fe412203          	lw	tp,-28(sp)
    22f0:	00470233          	add	tp,a4,tp
    22f4:	00024203          	lbu	tp,0(tp) # 0 <_start>
    22f8:	fe410523          	sb	tp,-22(sp)
    22fc:	ff114203          	lbu	tp,-15(sp)
    2300:	fe4102a3          	sb	tp,-27(sp)
    2304:	fed14203          	lbu	tp,-19(sp)
    2308:	fe410223          	sb	tp,-28(sp)
    230c:	fe412203          	lw	tp,-28(sp)
    2310:	00470233          	add	tp,a4,tp
    2314:	00024203          	lbu	tp,0(tp) # 0 <_start>
    2318:	fe4104a3          	sb	tp,-23(sp)
    231c:	ff014203          	lbu	tp,-16(sp)
    2320:	fe4102a3          	sb	tp,-27(sp)
    2324:	fec14203          	lbu	tp,-20(sp)
    2328:	fe410223          	sb	tp,-28(sp)
    232c:	fe412203          	lw	tp,-28(sp)
    2330:	00470233          	add	tp,a4,tp
    2334:	00024203          	lbu	tp,0(tp) # 0 <_start>
    2338:	fe410423          	sb	tp,-24(sp)
    233c:	fe812703          	lw	a4,-24(sp)
    2340:	005585b3          	add	a1,a1,t0

00002344 <andi_798>:
    2344:	01f00213          	addi	tp,zero,31

00002348 <and_799>:
    2348:	fec12823          	sw	a2,-16(sp)
    234c:	fe412623          	sw	tp,-20(sp)
    2350:	00003637          	lui	a2,0x3
    2354:	c0060613          	addi	a2,a2,-1024 # 2c00 <_logic_shift_table>
    2358:	fe012223          	sw	zero,-28(sp)
    235c:	ff314203          	lbu	tp,-13(sp)
    2360:	fe4102a3          	sb	tp,-27(sp)
    2364:	fef14203          	lbu	tp,-17(sp)
    2368:	fe410223          	sb	tp,-28(sp)
    236c:	fe412203          	lw	tp,-28(sp)
    2370:	00460233          	add	tp,a2,tp
    2374:	00024203          	lbu	tp,0(tp) # 0 <_start>
    2378:	fe4105a3          	sb	tp,-21(sp)
    237c:	ff214203          	lbu	tp,-14(sp)
    2380:	fe4102a3          	sb	tp,-27(sp)
    2384:	fee14203          	lbu	tp,-18(sp)
    2388:	fe410223          	sb	tp,-28(sp)
    238c:	fe412203          	lw	tp,-28(sp)
    2390:	00460233          	add	tp,a2,tp
    2394:	00024203          	lbu	tp,0(tp) # 0 <_start>
    2398:	fe410523          	sb	tp,-22(sp)
    239c:	ff114203          	lbu	tp,-15(sp)
    23a0:	fe4102a3          	sb	tp,-27(sp)
    23a4:	fed14203          	lbu	tp,-19(sp)
    23a8:	fe410223          	sb	tp,-28(sp)
    23ac:	fe412203          	lw	tp,-28(sp)
    23b0:	00460233          	add	tp,a2,tp
    23b4:	00024203          	lbu	tp,0(tp) # 0 <_start>
    23b8:	fe4104a3          	sb	tp,-23(sp)
    23bc:	ff014203          	lbu	tp,-16(sp)
    23c0:	fe4102a3          	sb	tp,-27(sp)
    23c4:	fec14203          	lbu	tp,-20(sp)
    23c8:	fe410223          	sb	tp,-28(sp)
    23cc:	fe412203          	lw	tp,-28(sp)
    23d0:	00460233          	add	tp,a2,tp
    23d4:	00024203          	lbu	tp,0(tp) # 0 <_start>
    23d8:	fe410423          	sb	tp,-24(sp)
    23dc:	fe812603          	lw	a2,-24(sp)

000023e0 <beq_806.L105>:
    23e0:	fee12823          	sw	a4,-16(sp)
    23e4:	fe812e23          	sw	s0,-4(sp)
    23e8:	00003437          	lui	s0,0x3
    23ec:	a0840413          	addi	s0,s0,-1528 # 2a08 <_check_8bit_0_table>
    23f0:	ff014183          	lbu	gp,-16(sp)
    23f4:	003401b3          	add	gp,s0,gp
    23f8:	0001c183          	lbu	gp,0(gp)
    23fc:	ff114203          	lbu	tp,-15(sp)
    2400:	00440233          	add	tp,s0,tp
    2404:	00024203          	lbu	tp,0(tp) # 0 <_start>
    2408:	004181b3          	add	gp,gp,tp
    240c:	ff214203          	lbu	tp,-14(sp)
    2410:	00440233          	add	tp,s0,tp
    2414:	00024203          	lbu	tp,0(tp) # 0 <_start>
    2418:	004181b3          	add	gp,gp,tp
    241c:	ff314203          	lbu	tp,-13(sp)
    2420:	00440233          	add	tp,s0,tp
    2424:	00024203          	lbu	tp,0(tp) # 0 <_start>
    2428:	004181b3          	add	gp,gp,tp
    242c:	00003237          	lui	tp,0x3
    2430:	a0020213          	addi	tp,tp,-1536 # 2a00 <_same_result_table>
    2434:	00320233          	add	tp,tp,gp
    2438:	00024203          	lbu	tp,0(tp) # 0 <_start>
    243c:	ffc12403          	lw	s0,-4(sp)

00002440 <slli_815>:
    2440:	00420233          	add	tp,tp,tp
    2444:	00420233          	add	tp,tp,tp
    2448:	00410233          	add	tp,sp,tp
    244c:	000021b7          	lui	gp,0x2
    2450:	6b018193          	addi	gp,gp,1712 # 26b0 <beq_846.L107>
    2454:	fe312823          	sw	gp,-16(sp)
    2458:	000021b7          	lui	gp,0x2
    245c:	46c18193          	addi	gp,gp,1132 # 246c <non_taken_806.L105>
    2460:	fe312623          	sw	gp,-20(sp)
    2464:	fec22203          	lw	tp,-20(tp) # ffffffec <_end+0xfff6cfec>
    2468:	00020067          	jalr	zero,0(tp) # 0 <_start>

0000246c <non_taken_806.L105>:
    246c:	ffc60293          	addi	t0,a2,-4

00002470 <andi_818>:
    2470:	ffc00213          	addi	tp,zero,-4

00002474 <and_819>:
    2474:	fe512823          	sw	t0,-16(sp)
    2478:	fe412623          	sw	tp,-20(sp)
    247c:	000032b7          	lui	t0,0x3
    2480:	c0028293          	addi	t0,t0,-1024 # 2c00 <_logic_shift_table>
    2484:	fe012223          	sw	zero,-28(sp)
    2488:	ff314203          	lbu	tp,-13(sp)
    248c:	fe4102a3          	sb	tp,-27(sp)
    2490:	fef14203          	lbu	tp,-17(sp)
    2494:	fe410223          	sb	tp,-28(sp)
    2498:	fe412203          	lw	tp,-28(sp)
    249c:	00428233          	add	tp,t0,tp
    24a0:	00024203          	lbu	tp,0(tp) # 0 <_start>
    24a4:	fe4105a3          	sb	tp,-21(sp)
    24a8:	ff214203          	lbu	tp,-14(sp)
    24ac:	fe4102a3          	sb	tp,-27(sp)
    24b0:	fee14203          	lbu	tp,-18(sp)
    24b4:	fe410223          	sb	tp,-28(sp)
    24b8:	fe412203          	lw	tp,-28(sp)
    24bc:	00428233          	add	tp,t0,tp
    24c0:	00024203          	lbu	tp,0(tp) # 0 <_start>
    24c4:	fe410523          	sb	tp,-22(sp)
    24c8:	ff114203          	lbu	tp,-15(sp)
    24cc:	fe4102a3          	sb	tp,-27(sp)
    24d0:	fed14203          	lbu	tp,-19(sp)
    24d4:	fe410223          	sb	tp,-28(sp)
    24d8:	fe412203          	lw	tp,-28(sp)
    24dc:	00428233          	add	tp,t0,tp
    24e0:	00024203          	lbu	tp,0(tp) # 0 <_start>
    24e4:	fe4104a3          	sb	tp,-23(sp)
    24e8:	ff014203          	lbu	tp,-16(sp)
    24ec:	fe4102a3          	sb	tp,-27(sp)
    24f0:	fec14203          	lbu	tp,-20(sp)
    24f4:	fe410223          	sb	tp,-28(sp)
    24f8:	fe412203          	lw	tp,-28(sp)
    24fc:	00428233          	add	tp,t0,tp
    2500:	00024203          	lbu	tp,0(tp) # 0 <_start>
    2504:	fe410423          	sb	tp,-24(sp)
    2508:	fe812283          	lw	t0,-24(sp)
    250c:	00428293          	addi	t0,t0,4
    2510:	005687b3          	add	a5,a3,t0
    2514:	00058713          	addi	a4,a1,0
    2518:	00072303          	lw	t1,0(a4)
    251c:	00468693          	addi	a3,a3,4
    2520:	00470713          	addi	a4,a4,4
    2524:	fe66ae23          	sw	t1,-4(a3)

00002528 <bne_826.L87>:
    2528:	fed12823          	sw	a3,-16(sp)
    252c:	fef12623          	sw	a5,-20(sp)
    2530:	fe812e23          	sw	s0,-4(sp)
    2534:	fe912c23          	sw	s1,-8(sp)
    2538:	0004b437          	lui	s0,0x4b
    253c:	d0040413          	addi	s0,s0,-768 # 4ad00 <_check_same_array>
    2540:	ff014183          	lbu	gp,-16(sp)
    2544:	00340233          	add	tp,s0,gp
    2548:	00100193          	addi	gp,zero,1
    254c:	00320023          	sb	gp,0(tp) # 0 <_start>
    2550:	fec14183          	lbu	gp,-20(sp)
    2554:	003401b3          	add	gp,s0,gp
    2558:	00018023          	sb	zero,0(gp)
    255c:	00024183          	lbu	gp,0(tp) # 0 <_start>
    2560:	ff114483          	lbu	s1,-15(sp)
    2564:	00940233          	add	tp,s0,s1
    2568:	00100493          	addi	s1,zero,1
    256c:	00920023          	sb	s1,0(tp) # 0 <_start>
    2570:	fed14483          	lbu	s1,-19(sp)
    2574:	009404b3          	add	s1,s0,s1
    2578:	00048023          	sb	zero,0(s1)
    257c:	00024483          	lbu	s1,0(tp) # 0 <_start>
    2580:	009181b3          	add	gp,gp,s1
    2584:	ff214483          	lbu	s1,-14(sp)
    2588:	00940233          	add	tp,s0,s1
    258c:	00100493          	addi	s1,zero,1
    2590:	00920023          	sb	s1,0(tp) # 0 <_start>
    2594:	fee14483          	lbu	s1,-18(sp)
    2598:	009404b3          	add	s1,s0,s1
    259c:	00048023          	sb	zero,0(s1)
    25a0:	00024483          	lbu	s1,0(tp) # 0 <_start>
    25a4:	009181b3          	add	gp,gp,s1
    25a8:	ff314483          	lbu	s1,-13(sp)
    25ac:	00940233          	add	tp,s0,s1
    25b0:	00100493          	addi	s1,zero,1
    25b4:	00920023          	sb	s1,0(tp) # 0 <_start>
    25b8:	fef14483          	lbu	s1,-17(sp)
    25bc:	009404b3          	add	s1,s0,s1
    25c0:	00048023          	sb	zero,0(s1)
    25c4:	00024483          	lbu	s1,0(tp) # 0 <_start>
    25c8:	009181b3          	add	gp,gp,s1
    25cc:	00003237          	lui	tp,0x3
    25d0:	a0020213          	addi	tp,tp,-1536 # 2a00 <_same_result_table>
    25d4:	00320233          	add	tp,tp,gp
    25d8:	00024203          	lbu	tp,0(tp) # 0 <_start>
    25dc:	ff812483          	lw	s1,-8(sp)
    25e0:	ffc12403          	lw	s0,-4(sp)

000025e4 <slli_835>:
    25e4:	00420233          	add	tp,tp,tp
    25e8:	00420233          	add	tp,tp,tp
    25ec:	00410233          	add	tp,sp,tp
    25f0:	000021b7          	lui	gp,0x2
    25f4:	61018193          	addi	gp,gp,1552 # 2610 <andi_838>
    25f8:	fe312823          	sw	gp,-16(sp)
    25fc:	000021b7          	lui	gp,0x2
    2600:	51818193          	addi	gp,gp,1304 # 2518 <and_819+0xa4>
    2604:	fe312623          	sw	gp,-20(sp)
    2608:	fec22203          	lw	tp,-20(tp) # ffffffec <_end+0xfff6cfec>
    260c:	00020067          	jalr	zero,0(tp) # 0 <_start>

00002610 <andi_838>:
    2610:	00300213          	addi	tp,zero,3

00002614 <and_839>:
    2614:	fec12823          	sw	a2,-16(sp)
    2618:	fe412623          	sw	tp,-20(sp)
    261c:	00003637          	lui	a2,0x3
    2620:	c0060613          	addi	a2,a2,-1024 # 2c00 <_logic_shift_table>
    2624:	fe012223          	sw	zero,-28(sp)
    2628:	ff314203          	lbu	tp,-13(sp)
    262c:	fe4102a3          	sb	tp,-27(sp)
    2630:	fef14203          	lbu	tp,-17(sp)
    2634:	fe410223          	sb	tp,-28(sp)
    2638:	fe412203          	lw	tp,-28(sp)
    263c:	00460233          	add	tp,a2,tp
    2640:	00024203          	lbu	tp,0(tp) # 0 <_start>
    2644:	fe4105a3          	sb	tp,-21(sp)
    2648:	ff214203          	lbu	tp,-14(sp)
    264c:	fe4102a3          	sb	tp,-27(sp)
    2650:	fee14203          	lbu	tp,-18(sp)
    2654:	fe410223          	sb	tp,-28(sp)
    2658:	fe412203          	lw	tp,-28(sp)
    265c:	00460233          	add	tp,a2,tp
    2660:	00024203          	lbu	tp,0(tp) # 0 <_start>
    2664:	fe410523          	sb	tp,-22(sp)
    2668:	ff114203          	lbu	tp,-15(sp)
    266c:	fe4102a3          	sb	tp,-27(sp)
    2670:	fed14203          	lbu	tp,-19(sp)
    2674:	fe410223          	sb	tp,-28(sp)
    2678:	fe412203          	lw	tp,-28(sp)
    267c:	00460233          	add	tp,a2,tp
    2680:	00024203          	lbu	tp,0(tp) # 0 <_start>
    2684:	fe4104a3          	sb	tp,-23(sp)
    2688:	ff014203          	lbu	tp,-16(sp)
    268c:	fe4102a3          	sb	tp,-27(sp)
    2690:	fec14203          	lbu	tp,-20(sp)
    2694:	fe410223          	sb	tp,-28(sp)
    2698:	fe412203          	lw	tp,-28(sp)
    269c:	00460233          	add	tp,a2,tp
    26a0:	00024203          	lbu	tp,0(tp) # 0 <_start>
    26a4:	fe410423          	sb	tp,-24(sp)
    26a8:	fe812603          	lw	a2,-24(sp)
    26ac:	005585b3          	add	a1,a1,t0

000026b0 <beq_846.L107>:
    26b0:	fec12823          	sw	a2,-16(sp)
    26b4:	fe812e23          	sw	s0,-4(sp)
    26b8:	00003437          	lui	s0,0x3
    26bc:	a0840413          	addi	s0,s0,-1528 # 2a08 <_check_8bit_0_table>
    26c0:	ff014183          	lbu	gp,-16(sp)
    26c4:	003401b3          	add	gp,s0,gp
    26c8:	0001c183          	lbu	gp,0(gp)
    26cc:	ff114203          	lbu	tp,-15(sp)
    26d0:	00440233          	add	tp,s0,tp
    26d4:	00024203          	lbu	tp,0(tp) # 0 <_start>
    26d8:	004181b3          	add	gp,gp,tp
    26dc:	ff214203          	lbu	tp,-14(sp)
    26e0:	00440233          	add	tp,s0,tp
    26e4:	00024203          	lbu	tp,0(tp) # 0 <_start>
    26e8:	004181b3          	add	gp,gp,tp
    26ec:	ff314203          	lbu	tp,-13(sp)
    26f0:	00440233          	add	tp,s0,tp
    26f4:	00024203          	lbu	tp,0(tp) # 0 <_start>
    26f8:	004181b3          	add	gp,gp,tp
    26fc:	00003237          	lui	tp,0x3
    2700:	a0020213          	addi	tp,tp,-1536 # 2a00 <_same_result_table>
    2704:	00320233          	add	tp,tp,gp
    2708:	00024203          	lbu	tp,0(tp) # 0 <_start>
    270c:	ffc12403          	lw	s0,-4(sp)

00002710 <slli_855>:
    2710:	00420233          	add	tp,tp,tp
    2714:	00420233          	add	tp,tp,tp
    2718:	00410233          	add	tp,sp,tp
    271c:	000031b7          	lui	gp,0x3
    2720:	8e018193          	addi	gp,gp,-1824 # 28e0 <non_taken_870.L104+0x14>
    2724:	fe312823          	sw	gp,-16(sp)
    2728:	000021b7          	lui	gp,0x2
    272c:	73c18193          	addi	gp,gp,1852 # 273c <non_taken_846.L107>
    2730:	fe312623          	sw	gp,-20(sp)
    2734:	fec22203          	lw	tp,-20(tp) # ffffffec <_end+0xfff6cfec>
    2738:	00020067          	jalr	zero,0(tp) # 0 <_start>

0000273c <non_taken_846.L107>:
    273c:	00c78633          	add	a2,a5,a2
    2740:	0005c703          	lbu	a4,0(a1)
    2744:	00178793          	addi	a5,a5,1
    2748:	00158593          	addi	a1,a1,1
    274c:	fee78fa3          	sb	a4,-1(a5)

00002750 <bne_858.L108>:
    2750:	fef12823          	sw	a5,-16(sp)
    2754:	fec12623          	sw	a2,-20(sp)
    2758:	fe812e23          	sw	s0,-4(sp)
    275c:	fe912c23          	sw	s1,-8(sp)
    2760:	0004b437          	lui	s0,0x4b
    2764:	d0040413          	addi	s0,s0,-768 # 4ad00 <_check_same_array>
    2768:	ff014183          	lbu	gp,-16(sp)
    276c:	00340233          	add	tp,s0,gp
    2770:	00100193          	addi	gp,zero,1
    2774:	00320023          	sb	gp,0(tp) # 0 <_start>
    2778:	fec14183          	lbu	gp,-20(sp)
    277c:	003401b3          	add	gp,s0,gp
    2780:	00018023          	sb	zero,0(gp)
    2784:	00024183          	lbu	gp,0(tp) # 0 <_start>
    2788:	ff114483          	lbu	s1,-15(sp)
    278c:	00940233          	add	tp,s0,s1
    2790:	00100493          	addi	s1,zero,1
    2794:	00920023          	sb	s1,0(tp) # 0 <_start>
    2798:	fed14483          	lbu	s1,-19(sp)
    279c:	009404b3          	add	s1,s0,s1
    27a0:	00048023          	sb	zero,0(s1)
    27a4:	00024483          	lbu	s1,0(tp) # 0 <_start>
    27a8:	009181b3          	add	gp,gp,s1
    27ac:	ff214483          	lbu	s1,-14(sp)
    27b0:	00940233          	add	tp,s0,s1
    27b4:	00100493          	addi	s1,zero,1
    27b8:	00920023          	sb	s1,0(tp) # 0 <_start>
    27bc:	fee14483          	lbu	s1,-18(sp)
    27c0:	009404b3          	add	s1,s0,s1
    27c4:	00048023          	sb	zero,0(s1)
    27c8:	00024483          	lbu	s1,0(tp) # 0 <_start>
    27cc:	009181b3          	add	gp,gp,s1
    27d0:	ff314483          	lbu	s1,-13(sp)
    27d4:	00940233          	add	tp,s0,s1
    27d8:	00100493          	addi	s1,zero,1
    27dc:	00920023          	sb	s1,0(tp) # 0 <_start>
    27e0:	fef14483          	lbu	s1,-17(sp)
    27e4:	009404b3          	add	s1,s0,s1
    27e8:	00048023          	sb	zero,0(s1)
    27ec:	00024483          	lbu	s1,0(tp) # 0 <_start>
    27f0:	009181b3          	add	gp,gp,s1
    27f4:	00003237          	lui	tp,0x3
    27f8:	a0020213          	addi	tp,tp,-1536 # 2a00 <_same_result_table>
    27fc:	00320233          	add	tp,tp,gp
    2800:	00024203          	lbu	tp,0(tp) # 0 <_start>
    2804:	ff812483          	lw	s1,-8(sp)
    2808:	ffc12403          	lw	s0,-4(sp)

0000280c <slli_867>:
    280c:	00420233          	add	tp,tp,tp
    2810:	00420233          	add	tp,tp,tp
    2814:	00410233          	add	tp,sp,tp
    2818:	000031b7          	lui	gp,0x3
    281c:	83818193          	addi	gp,gp,-1992 # 2838 <non_taken_858.L108>
    2820:	fe312823          	sw	gp,-16(sp)
    2824:	000021b7          	lui	gp,0x2
    2828:	74018193          	addi	gp,gp,1856 # 2740 <non_taken_846.L107+0x4>
    282c:	fe312623          	sw	gp,-20(sp)
    2830:	fec22203          	lw	tp,-20(tp) # ffffffec <_end+0xfff6cfec>
    2834:	00020067          	jalr	zero,0(tp) # 0 <_start>

00002838 <non_taken_858.L108>:
    2838:	00008067          	jalr	zero,0(ra)
    283c:	00050793          	addi	a5,a0,0

00002840 <bne_870.L104>:
    2840:	fec12823          	sw	a2,-16(sp)
    2844:	fe812e23          	sw	s0,-4(sp)
    2848:	00003437          	lui	s0,0x3
    284c:	a0840413          	addi	s0,s0,-1528 # 2a08 <_check_8bit_0_table>
    2850:	ff014183          	lbu	gp,-16(sp)
    2854:	003401b3          	add	gp,s0,gp
    2858:	0001c183          	lbu	gp,0(gp)
    285c:	ff114203          	lbu	tp,-15(sp)
    2860:	00440233          	add	tp,s0,tp
    2864:	00024203          	lbu	tp,0(tp) # 0 <_start>
    2868:	004181b3          	add	gp,gp,tp
    286c:	ff214203          	lbu	tp,-14(sp)
    2870:	00440233          	add	tp,s0,tp
    2874:	00024203          	lbu	tp,0(tp) # 0 <_start>
    2878:	004181b3          	add	gp,gp,tp
    287c:	ff314203          	lbu	tp,-13(sp)
    2880:	00440233          	add	tp,s0,tp
    2884:	00024203          	lbu	tp,0(tp) # 0 <_start>
    2888:	004181b3          	add	gp,gp,tp
    288c:	00003237          	lui	tp,0x3
    2890:	a0020213          	addi	tp,tp,-1536 # 2a00 <_same_result_table>
    2894:	00320233          	add	tp,tp,gp
    2898:	00024203          	lbu	tp,0(tp) # 0 <_start>
    289c:	ffc12403          	lw	s0,-4(sp)

000028a0 <slli_879>:
    28a0:	00420233          	add	tp,tp,tp
    28a4:	00420233          	add	tp,tp,tp
    28a8:	00410233          	add	tp,sp,tp
    28ac:	000031b7          	lui	gp,0x3
    28b0:	8cc18193          	addi	gp,gp,-1844 # 28cc <non_taken_870.L104>
    28b4:	fe312823          	sw	gp,-16(sp)
    28b8:	000021b7          	lui	gp,0x2
    28bc:	73c18193          	addi	gp,gp,1852 # 273c <non_taken_846.L107>
    28c0:	fe312623          	sw	gp,-20(sp)
    28c4:	fec22203          	lw	tp,-20(tp) # ffffffec <_end+0xfff6cfec>
    28c8:	00020067          	jalr	zero,0(tp) # 0 <_start>

000028cc <non_taken_870.L104>:
    28cc:	00008067          	jalr	zero,0(ra)
    28d0:	00050793          	addi	a5,a0,0
    28d4:	00002237          	lui	tp,0x2
    28d8:	73c20213          	addi	tp,tp,1852 # 273c <non_taken_846.L107>
    28dc:	00020067          	jalr	zero,0(tp) # 0 <_start>
    28e0:	00008067          	jalr	zero,0(ra)
    28e4:	00070793          	addi	a5,a4,0
    28e8:	00060393          	addi	t2,a2,0
    28ec:	00002237          	lui	tp,0x2
    28f0:	81020213          	addi	tp,tp,-2032 # 1810 <non_taken_620.L105>
    28f4:	00020067          	jalr	zero,0(tp) # 0 <_start>
    28f8:	00050713          	addi	a4,a0,0
    28fc:	00001237          	lui	tp,0x1
    2900:	36020213          	addi	tp,tp,864 # 1360 <non_taken_546.L79+0x4>
    2904:	00020067          	jalr	zero,0(tp) # 0 <_start>
