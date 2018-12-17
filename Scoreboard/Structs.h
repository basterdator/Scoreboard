#pragma once

#ifndef __STRUCTS_H__
#define __STRUCTS_H__


#define LD 	0
#define ST 	1
#define ADD	2
#define SUB	3
#define MULT 4
#define DIV	5
#define HALT 6

typedef int bool;
enum { false, true };

typedef struct Inst {
	int		pc;
	int		imm;
	int		src_reg_0;					// from parsing
	int		src_reg_1;					// from parsing
	int		dst_erg;					// from parsing
	int		opcode;						// from parsing
	int		cycle_issue;				// at parsing set to - 1
	int		cycle_read_operands;		// at parsing set to - 1
	int		cycle_execute_end;			// at parsing set to - 1
	int		cycle_write_result;			// at parsing set to - 1
} Inst;


typedef struct FuncUnit {
	char*	unit[10];						// e.g: SUB0 SUB1 SUB2
	int		type;						// SUB(macro).Given at parsing.
	int		delay;						//Given at parsing
	int		state;						//(WAIT_FOR_OPERANDS, EXECUTING, WAIT_FOR_WRITE_RESULT)
	int		remaining_time;				//reset_func_unit changes back to delay
	bool	busy;
	int		dst_reg;					//(Fi)
	int		src_reg_1;					//(Fj)
	int		src_reg_2;					//(Fk)
	char*	producing_unit_src_reg_1;	//(Qj)
	char*	producing_unit_src_reg_2;	//(Qk)
	bool	src_reg_1_ready;			//(Rj)
	bool	src_reg_2_ready;			//(Rk)
	Inst	current_inst;
} FuncUnit;


typedef struct FuncUnitStatusTable {
	int			num_of_units;
	FuncUnit	*func_unit_list;
} FuncUnitStatusTable;

#endif // __STRUCTS_H__