/*
 * Copyright 2010-2016 Intel Corporation.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License, version 2,
 * as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License for more details.
 *
 * Disclaimer: The codes contained in these modules may be specific to
 * the Intel Software Development Platform codenamed Knights Ferry,
 * and the Intel product codenamed Knights Corner, and are not backward
 * compatible with other Intel products. Additionally, Intel will NOT
 * support the codes or instruction set in future products.
 *
 * Intel offers no warranty of any kind regarding the code. This code is
 * licensed on an "AS IS" basis and Intel is not obligated to provide
 * any support, assistance, installation, training, or other services
 * of any kind. Intel is also not obligated to provide any updates,
 * enhancements or extensions. Intel specifically disclaims any warranty
 * of merchantability, non-infringement, fitness for any particular
 * purpose, and any other warranty.
 *
 * Further, Intel disclaims all liability of any kind, including but
 * not limited to liability for infringement of any proprietary rights,
 * relating to the use of the code, even if Intel is notified of the
 * possibility of such liability. Except as expressly stated in an Intel
 * license agreement provided with this code and agreed upon with Intel,
 * no license, express or implied, by estoppel or otherwise, to any
 * intellectual property rights is granted herein.
 */

/*
  Structures which are passed from host to MIC card through
  uOS kernel command line option, virtio_addr.

  (C) Copyright 2012 Intel Corporation
  Author: Caz Yokoyama <Caz.Yokoyama@intel.com>
 */
#ifndef MIC_VIRTIO_H
#define MIC_VIRTIO_H

struct vb_shared {
	struct virtio_blk_config blk_config;
	uint32_t host_features;
	uint32_t client_features;
	bool update;
	struct vring vring;
};

struct mic_virtblk {
#ifdef HOST
	struct vb_shared vb_shared;
	void *vblk;  /* keep vblk in vhost for virtblk */
#else
	struct vb_shared *vb_shared;
	void *vdev;  /* keep vdev in virtio for virtblk */
#endif
};

uint64_t mic_vhost_pm_disconnect_node(uint64_t node_bitmask, enum disconn_type type);
void mic_vhost_blk_stop(bd_info_t *bd_info);

#endif // MIC_VIRTIO_H
