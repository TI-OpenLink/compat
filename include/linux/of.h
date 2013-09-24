#ifndef _COMPAT_LINUX_OF_H
#define _COMPAT_LINUX_OF_H 1

#include <linux/version.h>

#if (LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,34))
#include_next <linux/of.h>
#else

#ifdef CONFIG_OF
#include_next <linux/of.h>
#endif /* CONFIG_OF */

#endif /* (LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,34)) */

#if (LINUX_VERSION_CODE < KERNEL_VERSION(3,3,0))
/**
 * of_property_read_bool - Findfrom a property
 * @np:		device node from which the property value is to be read.
 * @propname:	name of the property to be searched.
 *
 * Search for a property in a device node.
 * Returns true if the property exist false otherwise.
 */
static inline bool of_property_read_bool(const struct device_node *np,
					 const char *propname)
{
	struct property *prop = of_find_property(np, propname, NULL);

	return prop ? true : false;
}
#endif

#endif	/* _COMPAT_LINUX_OF_H */
