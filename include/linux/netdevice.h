#include_next <linux/netdevice.h>

#ifndef COMPAT_NETDEVICE_H
#define COMPAT_NETDEVICE_H

#if (LINUX_VERSION_CODE < KERNEL_VERSION(3,10,0))
struct netdev_notifier_info {
	struct net_device *dev;
};

static inline struct net_device *
netdev_notifier_info_to_dev(const struct netdev_notifier_info *info)
{
	/* this is just a workaround, as older kernels pass different param */
	return (struct net_device *)info;
}
#endif /* LINUX_VERSION_CODE < KERNEL_VERSION(3,10,0) */

#endif // COMPAT_NETDEVICE_H
