/*
 * Sylpheed -- a GTK+ based, lightweight, and fast e-mail client
 * Copyright (C) 1999-2003 Hiroyuki Yamamoto & the Sylpheed-Claws team
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 */

#ifndef SGPGME_H
#define SGPGME_H 1

#include <gpgme.h>

#include "privacy.h"

void sgpgme_init(void);
void sgpgme_done(void);

gpgme_verify_result_t sgpgme_verify_signature	(gpgme_ctx_t ctx,
				    	 gpgme_data_t sig,
				    	 gpgme_data_t plain,
					 gpgme_data_t dummy);
SignatureStatus sgpgme_sigstat_gpgme_to_privacy
					(gpgme_ctx_t ctx,
					 gpgme_verify_result_t status);
gchar *sgpgme_sigstat_info_short	(gpgme_ctx_t ctx,
					 gpgme_verify_result_t status);
gchar *sgpgme_sigstat_info_full		(gpgme_ctx_t ctx,
					 gpgme_verify_result_t status);
gpgme_data_t sgpgme_data_from_mimeinfo	(MimeInfo *mimeinfo);
gpgme_data_t sgpgme_decrypt_verify	(gpgme_data_t cipher, 
					 gpgme_verify_result_t *status,
					 gpgme_ctx_t ctx);
gchar *sgpgme_get_encrypt_data		(GSList *recp_names);
gboolean sgpgme_setup_signers(gpgme_ctx_t ctx, PrefsAccount *account);

#endif /* SGPGME_H */