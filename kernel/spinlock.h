#define NSEM	100
struct spinlock {
  uint locked;      
 
  char *name;  
  struct cpu *cpu;
};
struct semaphore {
	struct spinlock lock;
	// semaphore lock
	int count;
	// semaphore value
	int valid;
	// 1 if this entry is in use
};
// OS semaphore table type
struct semtab {
	struct spinlock lock;
	struct semaphore sem[NSEM];
};
extern struct semtab semtable;
