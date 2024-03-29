/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/06 13:16:12 by agouby            #+#    #+#             */
/*   Updated: 2017/09/20 00:10:43 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "msg.h"

typedef struct	s_parser
{
	char			*slh;
	unsigned char	got_ant : 1;
	unsigned char	got_room : 1;
	unsigned char	got_tube : 1;
	unsigned char	got_start;
	unsigned char	got_end;
	unsigned char	err : 1;
	size_t			ln;
	size_t			command_cnt;
}				t_parser;

#endif
