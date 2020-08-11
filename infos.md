# <center>Corewar</center>

## <center>ASM</center>

### 1) ByteCode

| Name  | Opcode | Cycles | Param 1           | Param 2           | Param 3    | Modify Carry | Description Byte | Direct Bytes |
|:-----:|:------:|:------:|:-----------------:|:-----------------:|:----------:|:------------:|:----------------:|:------------:|
| live  | 0x01   | 10     | DIR               | none              | none       | no           | no               | 4            |
| ld    | 0x02   | 5      | DIR or IND        | REG               | none       | yes          | yes              | 4            |
| st    | 0x03   | 5      | REG               | IND or REG        | none       | no           | yes              | 0            |
| add   | 0x04   | 10     | REG               | REG               | REG        | yes          | yes              | 0            |
| sub   | 0x05   | 10     | REG               | REG               | REG        | yes          | yes              | 0            |
| and   | 0x06   | 6      | REG or DIR or IND | REG or DIR or IND | REG        | yes          | yes              | 4            |
| or    | 0x07   | 6      | REG or DIR or IND | REG or DIR or IND | REG        | yes          | yes              | 4            |
| xor   | 0x08   | 6      | REG or DIR or IND | REG or DIR or IND | REG        | yes          | yes              | 4            |
| zjmp  | 0x09   | 20     | DIR               | none              | none       | no           | no               | 2            |
| ldi   | 0x0a   | 25     | RED or DIR or IND | REG or DIR        | REG        | yes          | yes              | 2            |
| sti   | 0x0b   | 25     | REG               | REG or DIR or IND | REG or DIR | no           | yes              | 2            |
| fork  | 0x0c   | 800    | DIR               | none              | none       | no           | no               | 2            |
| lld   | 0x0d   | 10     | DIR or IND        | REG               | none       | yes          | yes              | 4            |
| lldi  | 0x0e   | 50     | REG or DIR or IND | REG or DIR        | REG        | yes          | yes              | 2            |
| lfork | 0x0f   | 1000   | DIR               | none              | none       | no           | no               | 2            |
| aff   | 0x10   | 2      | REG               | none              | none       | no           | yes              | 0            |

* When compiling an instruction you have to write:
    * Opcode of the instruction (in hexadecimal).
    * Description of the parameters (in hexadecimal).
    * Parameters (in hexadecimal).

## <center>Virtual Machine</center>

### 1) Instructions Effects

`live`: takes 1 parameter: 4 bytes that represent the player’s number. It indicates that the player is alive.

`ld`: takes 2 parameters. It loads the value of the first parameter into the second parameter, which must be a register (not the PC). This operation modifies the carry.<br />&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;`ld 34,r3` loads the REG_SIZE bytes starting at the address PC + 34 % IDX_MOD into r3.

`st`: takes 2 parameters. It stores the first parameter’s value (which is a register) into the second (whether a register or a number).<br />&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;`st r4,34` stores the content of r4 at the address PC + 34 % IDX_MOD.<br />&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;`st r3,r8` copies the content of r3 into r8.

`add`: takes 3 registers as parameters. It adds the content of the first two and puts the sum into the third one (which must be a register). This operation modifies the carry.<br />&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;`add r2,r3,r5` adds the content of r2 and r3 and puts the result into r5.

`sub`: Similar to add, but performing a subtraction.

`and`: takes 3 parameters. It performs a binary AND between the first two parameters ans stores the result into the third one (which must be a register). This operation modifies the carry.<br />&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;`and r2, %0,r3` puts r2 & 0 into r3.

`or`: Similar to and, but performing a binary OR.

`xor`: Similar to and, but performing a binary XOR (exclusive OR).

`zjmp`: takes 1 parameter, which must be an index. It jumps to this index if the carry is worth 1. Otherwise, it does nothing but consumes the same time.<br />&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;`zjmp %23` puts, if carry equals 1, PC + 23 % IDX_MOD into the PC.

`ldi`: takes 3 parameters. The first two must be indexes, the third one must be a register. This operation modifies the carry and functions as follows:<br />&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;`ldi 3,%4,r1` reads IND_SIZ bytes from the address PC + 3 % IDX_MOD, adds 4 to this value. The sum is named S. REG_SIZE bytes are read from the address PC + S % IDX_MOD and copied into r1.

`sti`: takes 3 parameters. The first one must be a register. The other two can be indexes or registers. It functions as follows:<br />&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;`sti r2,%4,%5` copies the content of r2 into the address PC + (4+5) % IDX_MOD.

`fork`: takes 1 parameter, which must be an index. It creates a new program that inherits different states from the parent. This program is executed at the address PC + first parameter % IDX_MOD.

`lld`: Similar to ld without the %IDX_MOD. This operation modifies the carry.

`lldi`: Similar to ldi without the %IDX_MOD. This operation modifies the carry.

`lfork`: Similar to fork without the %IDX_MOD.

`aff`: takes 1 register, which must be a register. It displays on the standard output the character whose ASCII code is the content of the register (in base 10). A 256 modulo is applied to this ASCII code.<br />&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;`aff r3` displays '*' if r3 contains 42.
