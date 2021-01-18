glabel func_80A3402C
/* 0145C 80A3402C 27BDFFC8 */  addiu   $sp, $sp, 0xFFC8           ## $sp = FFFFFFC8
/* 01460 80A34030 AFB10020 */  sw      $s1, 0x0020($sp)           
/* 01464 80A34034 AFB0001C */  sw      $s0, 0x001C($sp)           
/* 01468 80A34038 00808025 */  or      $s0, $a0, $zero            ## $s0 = 00000000
/* 0146C 80A3403C 00A08825 */  or      $s1, $a1, $zero            ## $s1 = 00000000
/* 01470 80A34040 AFBF0024 */  sw      $ra, 0x0024($sp)           
/* 01474 80A34044 2605014C */  addiu   $a1, $s0, 0x014C           ## $a1 = 0000014C
/* 01478 80A34048 0C0189B7 */  jal     Collider_UpdateCylinder
              
/* 0147C 80A3404C AFA5002C */  sw      $a1, 0x002C($sp)           
/* 01480 80A34050 3C010001 */  lui     $at, 0x0001                ## $at = 00010000
/* 01484 80A34054 34211E60 */  ori     $at, $at, 0x1E60           ## $at = 00011E60
/* 01488 80A34058 02212821 */  addu    $a1, $s1, $at              
/* 0148C 80A3405C AFA50028 */  sw      $a1, 0x0028($sp)           
/* 01490 80A34060 02202025 */  or      $a0, $s1, $zero            ## $a0 = 00000000
/* 01494 80A34064 0C017713 */  jal     CollisionCheck_SetOC
              ## CollisionCheck_setOC
/* 01498 80A34068 8FA6002C */  lw      $a2, 0x002C($sp)           
/* 0149C 80A3406C 3C014220 */  lui     $at, 0x4220                ## $at = 42200000
/* 014A0 80A34070 44810000 */  mtc1    $at, $f0                   ## $f0 = 40.00
/* 014A4 80A34074 240E0005 */  addiu   $t6, $zero, 0x0005         ## $t6 = 00000005
/* 014A8 80A34078 AFAE0014 */  sw      $t6, 0x0014($sp)           
/* 014AC 80A3407C 44060000 */  mfc1    $a2, $f0                   
/* 014B0 80A34080 02202025 */  or      $a0, $s1, $zero            ## $a0 = 00000000
/* 014B4 80A34084 02002825 */  or      $a1, $s0, $zero            ## $a1 = 00000000
/* 014B8 80A34088 3C0741C8 */  lui     $a3, 0x41C8                ## $a3 = 41C80000
/* 014BC 80A3408C 0C00B92D */  jal     func_8002E4B4              
/* 014C0 80A34090 E7A00010 */  swc1    $f0, 0x0010($sp)           
/* 014C4 80A34094 920F015D */  lbu     $t7, 0x015D($s0)           ## 0000015D
/* 014C8 80A34098 31F80002 */  andi    $t8, $t7, 0x0002           ## $t8 = 00000000
/* 014CC 80A3409C 53000017 */  beql    $t8, $zero, .L80A340FC     
/* 014D0 80A340A0 02202025 */  or      $a0, $s1, $zero            ## $a0 = 00000000
/* 014D4 80A340A4 8E020188 */  lw      $v0, 0x0188($s0)           ## 00000188
/* 014D8 80A340A8 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 014DC 80A340AC 24050003 */  addiu   $a1, $zero, 0x0003         ## $a1 = 00000003
/* 014E0 80A340B0 10400005 */  beq     $v0, $zero, .L80A340C8     
/* 014E4 80A340B4 00000000 */  nop
/* 014E8 80A340B8 8C590000 */  lw      $t9, 0x0000($v0)           ## 00000000
/* 014EC 80A340BC 33280080 */  andi    $t0, $t9, 0x0080           ## $t0 = 00000000
/* 014F0 80A340C0 5500000E */  bnel    $t0, $zero, .L80A340FC     
/* 014F4 80A340C4 02202025 */  or      $a0, $s1, $zero            ## $a0 = 00000000
.L80A340C8:
/* 014F8 80A340C8 0C28CAF4 */  jal     func_80A32BD0              
/* 014FC 80A340CC A2000114 */  sb      $zero, 0x0114($s0)         ## 00000114
/* 01500 80A340D0 960A02F4 */  lhu     $t2, 0x02F4($s0)           ## 000002F4
/* 01504 80A340D4 44802000 */  mtc1    $zero, $f4                 ## $f4 = 0.00
/* 01508 80A340D8 24090064 */  addiu   $t1, $zero, 0x0064         ## $t1 = 00000064
/* 0150C 80A340DC 354B0004 */  ori     $t3, $t2, 0x0004           ## $t3 = 00000004
/* 01510 80A340E0 A2090305 */  sb      $t1, 0x0305($s0)           ## 00000305
/* 01514 80A340E4 A60B02F4 */  sh      $t3, 0x02F4($s0)           ## 000002F4
/* 01518 80A340E8 02002025 */  or      $a0, $s0, $zero            ## $a0 = 00000000
/* 0151C 80A340EC 24056872 */  addiu   $a1, $zero, 0x6872         ## $a1 = 00006872
/* 01520 80A340F0 0C00BE0A */  jal     Audio_PlayActorSound2
              
/* 01524 80A340F4 E6040068 */  swc1    $f4, 0x0068($s0)           ## 00000068
/* 01528 80A340F8 02202025 */  or      $a0, $s1, $zero            ## $a0 = 00000000
.L80A340FC:
/* 0152C 80A340FC 8FA50028 */  lw      $a1, 0x0028($sp)           
/* 01530 80A34100 0C01767D */  jal     CollisionCheck_SetAC
              ## CollisionCheck_setAC
/* 01534 80A34104 8FA6002C */  lw      $a2, 0x002C($sp)           
/* 01538 80A34108 0C28CC28 */  jal     func_80A330A0              
/* 0153C 80A3410C 00000000 */  nop
/* 01540 80A34110 10400007 */  beq     $v0, $zero, .L80A34130     
/* 01544 80A34114 3C0C80A3 */  lui     $t4, %hi(func_80A33D10)    ## $t4 = 80A30000
/* 01548 80A34118 258C3D10 */  addiu   $t4, $t4, %lo(func_80A33D10) ## $t4 = 80A33D10
/* 0154C 80A3411C 240D0006 */  addiu   $t5, $zero, 0x0006         ## $t5 = 00000006
/* 01550 80A34120 AE0C0130 */  sw      $t4, 0x0130($s0)           ## 00000130
/* 01554 80A34124 A20D001F */  sb      $t5, 0x001F($s0)           ## 0000001F
/* 01558 80A34128 10000007 */  beq     $zero, $zero, .L80A34148   
/* 0155C 80A3412C A2000114 */  sb      $zero, 0x0114($s0)         ## 00000114
.L80A34130:
/* 01560 80A34130 920E0114 */  lbu     $t6, 0x0114($s0)           ## 00000114
/* 01564 80A34134 3C0F80A3 */  lui     $t7, %hi(EnGe2_Update)    ## $t7 = 80A30000
/* 01568 80A34138 25EF3E34 */  addiu   $t7, $t7, %lo(EnGe2_Update) ## $t7 = 80A33E34
/* 0156C 80A3413C 55C00003 */  bnel    $t6, $zero, .L80A3414C     
/* 01570 80A34140 8FBF0024 */  lw      $ra, 0x0024($sp)           
/* 01574 80A34144 AE0F0130 */  sw      $t7, 0x0130($s0)           ## 00000130
.L80A34148:
/* 01578 80A34148 8FBF0024 */  lw      $ra, 0x0024($sp)           
.L80A3414C:
/* 0157C 80A3414C 8FB0001C */  lw      $s0, 0x001C($sp)           
/* 01580 80A34150 8FB10020 */  lw      $s1, 0x0020($sp)           
/* 01584 80A34154 03E00008 */  jr      $ra                        
/* 01588 80A34158 27BD0038 */  addiu   $sp, $sp, 0x0038           ## $sp = 00000000
