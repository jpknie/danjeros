#ifndef X86_64_CONTROL_REGISTERS
#define X86_64_CONTROL_REGISTERS

static inline unsigned read_cr0() {
	unsigned ret;
	__asm__ volatile( "mov %%cr0, %0"
                  : "=r"(ret) );
	return ret;
}

static inline unsigned read_cr4() {
	unsigned ret;
	__asm__ volatile( "mov %%cr4, %0"
                  : "=r"(ret) );
	return ret;
}

#endif
