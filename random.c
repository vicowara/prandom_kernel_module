#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/jiffies.h>
#include <linux/random.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("vicowara");
MODULE_DESCRIPTION("pseudo-random number generation test");

int __init random_init(void) {
	struct rnd_state state;
	prandom_seed_state(&state, jiffies);
	pr_info("[%lu] random number: %u\n", jiffies/HZ, prandom_u32_state(&state));
	return 0;
}

void __exit random_exit(void){
}

module_init(random_init);
module_exit(random_exit);
