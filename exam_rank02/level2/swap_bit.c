/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 14:13:01 by mariaber          #+#    #+#             */
/*   Updated: 2025/04/05 14:13:03 by mariaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

unsigned char swap_bits(unsigned char octet)
{
    return ((octet >> 4) | (octet << 4));
}

int main (void)
{
    unsigned char num = 48;

    printf("numero -> %u\n", num);
    num = swap_bits(num);
    printf("binario con swap -> %u\n", num);
    return(0);
}
