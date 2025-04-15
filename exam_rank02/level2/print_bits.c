/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 14:12:41 by mariaber          #+#    #+#             */
/*   Updated: 2025/04/05 14:12:43 by mariaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void    print_bits(unsigned char octet)
{
    int i = 8;         //partiamo dal bit piu significativo (i = 7) 
                       //fino al meno significativo (i = 0)

    unsigned char bit; //dove salvare il bit

    while (i--)
    {
        bit = (octet >> i & 1) + '0'; //il bit che ci interessa salvare, si trova
                                      //nella posizione piu a destra. Dopo lo convertiamo 
                                      //in ascii
        write(1, &bit,1);
    }
}

int main(void)
{
    unsigned char num = 48;

    print_bits(num);
    printf(" -> %u\n", num);
    return(0);
}

