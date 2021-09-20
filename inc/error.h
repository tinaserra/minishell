/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 12:11:16 by vserra            #+#    #+#             */
/*   Updated: 2021/09/16 14:41:55 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

static char g_str_error[NUMBER][256] =
{
	[SYNTXT] = "syntax error unexpected token\n",
	[HOME] = "HOME not set\n",
	[EXPORT] = "not a valid identifier\n",
	[CMD] = "command not found\n",
	[FORKING] = "error forking\n",
	[PIPING] = "error piping\n",
};

#endif
