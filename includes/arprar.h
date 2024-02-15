/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arprar.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-clee <mde-clee@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 22:54:02 by mde-clee          #+#    #+#             */
/*   Updated: 2023/12/30 08:28:13 by mde-clee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARPRAR_H
# define ARPRAR_H

# include <stddef.h>
# include "../dep/libft/libft.h"

char	*bn_div(char *a, char *b, char **c, int prec);
char	*bn_shft_ins(char *a, size_t off, int n);
char	*bn_rnd(char **a, int prec, int sign);
char	*bn_mult(char *a, char *b, char **c);
char	*bn_subt(char *a, char *b, char *c);
char	*bn_add(char *a, char *b, char *c);
char	*bn_insrad(char *a, size_t decs);
char	*bn_shft_rt(char *a, size_t off);
char	*bn_norad(char *a, size_t decs);
char	*bn_new(int len, char *in);
char	*bn_pad(char *a, size_t n);
char	*bn_cln(char **a);
char	*bn_strt(char *a);
char	*bn_trim(char *a);
size_t	bn_decs(char *a);
size_t	bn_len(char *a);
void	bn_clr(char *a);
void	bn_nclr(char *a, size_t n);
int		bn_put(char *a, int pos, char dig);
int		bn_tke(char *a, int pos, char dig);
int		bn_pow(char *a, char *b, char *c);
int		bn_smlr(char *a, char *b);
int		bn_eql(char *a, char *b);
int		bn_set(char *a, char *b);
int		bn_iszro(char *a);

#endif
