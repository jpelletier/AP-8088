#ifndef _TARGET_BITS_H_
#define _TARGET_BITS_H_

#define BIT_RESET	1
#define BIT_NMI		2
#define BIT_INTR	3
#define BIT_READY	4
#define BIT_CLK		5
#define BIT_TEST	6
#define BIT_MN_MX	7
#define BIT_RQGT0	8
#define BIT_RQGT1	9

#define BIT_RD		8
#define BIT_S2		9
#define BIT_S1		10
#define BIT_S0	 	11
#define BIT_LOCK	12
#define BIT_INTA	13
#define BIT_SSO		4

#define MASK_RESET	(1<<BIT_RESET)
#define MASK_NMI	(1<<BIT_NMI)
#define MASK_INTR	(1<<BIT_INTR)
#define MASK_READY	(1<<BIT_READY)
#define MASK_CLK	(1<<BIT_CLK)
#define MASK_TEST	(1<<BIT_TEST)
#define MASK_MN_MX	(1<<BIT_MN_MX)
#define MASK_RQGT0	(1<<BIT_RQGT0)
#define MASK_RQGT1	(1<<BIT_RQGT1)

#define MASK_RD		(1<<BIT_RD)
#define MASK_S2		(1<<BIT_S2)
#define MASK_S1		(1<<BIT_S1)
#define MASK_S0		(1<<BIT_S0)
#define MASK_LOCK	(1<<BIT_LOCK)
#define MASK_INTA	(1<<BIT_INTA)
#define MASK_SSO	(1<<BIT_SSO)

typedef enum {
		IntAck = 0,
		IoRead = 1,
		IoWrite = 2,
		Halt = 3,
		Fetch = 4,
		MemRead = 5,
		MemWrite = 6,
		Passive = 7
} bus_transaction_t;

#endif /* _TARGET_BITS_H_ */
